struct tnode * makeLeafNode (int nodeType, int n){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode * makeIdNode (int nodeType, char id){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->op = id;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode * makeOperatorNode (int nodeType, char op, struct tnode * left, struct tnode * right){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->op = op;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode * makeStmtNode (int nodeType, struct tnode * left, struct tnode * right){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    if (nodeType == ASG_STMT){
        temp->op = '=';
    }
    return temp;
}

struct tnode * makeConnectorNode (int nodeType, struct tnode * left, struct tnode * right){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    return temp;
}

int getReg (FILE * filePointer){
    if (currReg != 21)
    currReg ++;
    return currReg-1;
}

void freeReg(FILE * filePointer){
    if (currReg != 0)
    currReg --;
}

int address (char a){
    return a-97+4096;
}

void headerGen (FILE * filePointer){
    fprintf (filePointer, "0\n2056\n0\n0\n0\n0\n0\n0\nPUSH SP, 4122\n");
}

void exitGen (FILE * filePointer){
    int currReg = getReg (filePointer);
    fprintf (filePointer, "MOV R%d, \"Exit\"\nPUSH R%d\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, currReg);
}

int codeGen (struct tnode *t, FILE * filePointer){
    if (t->nodeType == CONNECTOR){
        codeGen (t->left, filePointer);
        codeGen (t->right, filePointer);
        return -1;
    }

    else if (t->nodeType == OP){
        if (t->op == '+'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '-'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "SUB R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '*'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "MUL R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '/'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "DIV R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }
    }

    else if (t->nodeType == INPUT_STMT){
        int currReg = getReg(filePointer);
        fprintf (filePointer, "MOV R%d, \"Read\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, \"-1\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, %d\nPUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, address(t->left->op), currReg);
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg(filePointer);
        return 0;
    }
    else if (t->nodeType == OUTPUT_STMT){
        int resultReg;
        resultReg = codeGen (t->left, filePointer);
        int currReg = getReg(filePointer);
        fprintf (filePointer, "MOV R%d, \"Write\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, \"-2\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", resultReg, currReg);
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg(filePointer);
        return 0;
    }

    else if (t->nodeType == ASG_STMT){
        int resultReg = codeGen (t->right, filePointer);
        fprintf (filePointer, "MOV [%d], R%d\n", address(t->left->op), resultReg);
        freeReg (filePointer);
        freeReg (filePointer);
    }

    else if (t->nodeType == CONST){
        int resultReg = getReg(filePointer);
        fprintf (filePointer, "MOV R%d, %d\n", resultReg, t->val);
        return resultReg;
    }

    else if (t->nodeType == IDENT){
        int resultReg = getReg(filePointer);
        fprintf (filePointer, "MOV R%d, [%d]\n", resultReg, address (t->op));
        return resultReg;
    }
}
