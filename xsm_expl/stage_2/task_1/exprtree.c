struct tnode * makeLeafNode (int nodeType, int n){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->op = NULL;
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

int evaluate (struct tnode * t){
    if (t->op == NULL){
        return t->val;
    }
    else {
        switch (t->op){
            case '+' : return (evaluate(t->left) + evaluate(t->right));
            break;

            case '-' : return (evaluate(t->left) - evaluate(t->right));
            break;
            
            case '*' : return (evaluate(t->left) * evaluate(t->right));
            break;

            case '/' : return (evaluate(t->left) / evaluate(t->right));
            break;
        }
    }
}

void prefix (struct tnode * t){
    if (t->nodeType == CONST){
        printf ("%d ", t->val);
    }

    else if (t->nodeType == IDENT){
        printf ("%c ", t->op);
    }

    else if (t->nodeType == INPUT_STMT){
        printf ("READ ");
    }

    else if (t->nodeType == OUTPUT_STMT){
        printf ("WRITE ");
    }

    else if (t->nodeType == ASG_STMT){
        printf ("%c ", t->op);
    }

    else if (t->nodeType == OP){
        printf ("%c ", t->op);
    }

    if (t->left != NULL)
    prefix (t->left);

    if (t->right != NULL)
    prefix (t->right);
}

void infix (struct tnode * t){
    if (t->left != NULL){
        infix (t->left);
    }

    if (t->nodeType == CONST){
        printf ("%d ", t->val);
    }

    else if (t->nodeType == IDENT){
        printf ("%c ", t->op);
    }

    else if (t->nodeType == INPUT_STMT){
        printf ("READ ");
    }

    else if (t->nodeType == OUTPUT_STMT){
        printf ("WRITE ");
    }

    else if (t->nodeType == ASG_STMT){
        printf ("%c ", t->op);
    }

    else if (t->nodeType == OP){
        printf ("%c ", t->op);
    }

    if (t->right != NULL){
        infix (t->right);
    }
}

void postfix (struct tnode * t){
    if (t->left != NULL)
    postfix (t->left);

    if (t->right != NULL)
    postfix (t->right);

    printf ("%d ", t->nodeType);
}

int getReg (){
    currReg ++;
    return currReg-1;
}

void freeReg(){
    currReg --;
}

int address (char a){
    return a-97+4096;
}

int codeGen (struct tnode *t, FILE * filePointer){
    if (t->nodeType == CONNECTOR){
        codeGen (t->left, filePointer);
        codeGen (t->right, filePointer);
        return -1;
    }

    else if (t->nodeType == OP){
        if (t->op == '+'){
            int resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            return resultReg;
        }

        else if (t->op == '-'){
            int resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "SUB R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            return resultReg;
        }

        else if (t->op == '*'){
            int resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "MUL R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            return resultReg;
        }

        else if (t->op == '/'){
            int resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "DIV R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            return resultReg;
        }
    }

    else if (t->nodeType == INPUT_STMT){
        int currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"Read\"\nPUSH R%d\n", currReg, currReg);
        freeReg();
        currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"-1\"\nPUSH R%d\n", currReg, currReg);
        freeReg();
        currReg = getReg();
        fprintf (filePointer, "MOV R%d, %d\nPUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, address(t->left->op), currReg);
        freeReg();
        currReg = getReg();
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg();
        return 0;
    }
    else if (t->nodeType == OUTPUT_STMT){
        int resultReg = getReg();
        resultReg = codeGen (t->left, filePointer);
        int currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"Write\"\nPUSH R%d\n", currReg, currReg);
        freeReg();
        currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"-2\"\nPUSH R%d\n", currReg, currReg);
        freeReg();
        currReg = getReg();
        fprintf (filePointer, "MOV R%d, R%d\nPUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, resultReg, currReg);
        freeReg();
        currReg = getReg();
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg();
        freeReg();
        return 0;
    }

    else if (t->nodeType == ASG_STMT){
        int resultReg = codeGen (t->right, filePointer);
        fprintf (filePointer, "MOV [%d], R%d\n", address(t->left->op), resultReg);
    }

    else if (t->nodeType == CONST){
        int resultReg = getReg();
        fprintf (filePointer, "MOV R%d, %d\n", resultReg, t->val);
        return resultReg;
    }

    else if (t->nodeType == IDENT){
        return 0;
    }
}
