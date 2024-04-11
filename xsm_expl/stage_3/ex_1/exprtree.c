void yyerror();
int varIndex (char a){
    return a-97;
}

struct tnode * makeLeafNode (int nodeType, int n){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    temp->type = intType;
    return temp;
}

struct tnode * makeIdNode (int nodeType, char id){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->op = id;
    temp->left = NULL;
    temp->right = NULL;
    temp->type = intType;
    return temp;
}

struct tnode * makeOperatorNode (int nodeType, char op, struct tnode * left, struct tnode * right){
    //typechecking
    if (nodeType == OP && (left->type != intType | right->type != intType)) {
        printf ("type error !\n");
        yyerror();
    }
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->op = op;
    temp->left = left;
    temp->right = right;
    if (nodeType == BOOL) {
        temp->type = boolType;
    }
    return temp;
}

struct tnode * makeStmtNode (int nodeType, struct tnode * left, struct tnode * right, struct tnode * mid){
    //typechecking
    if ((nodeType == ASG_STMT && (left->type != intType | right->type != intType)) | ((nodeType == IFNODE | nodeType == IFELSE | nodeType == WH) && (left->type != boolType))){
        printf ("type error !\n");
        yyerror();
    }
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    if (nodeType == IFELSE){
        temp->mid = mid;
    }
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
    fprintf (filePointer, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, 4122\n");
}

void exitGen (FILE * filePointer){
    int currReg = getReg (filePointer);
    fprintf (filePointer, "MOV R%d, \"Exit\"\nPUSH R%d\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, currReg);
}

int getLabel (){
    currLabel ++;
    return currLabel-1;
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

    else if (t->nodeType == WH){
        int label1 = getLabel();
        int label2 = getLabel();
        fprintf (filePointer, "L%d:\n", label1);
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "JZ R%d, L%d\n", resultReg, label2);
        codeGen (t->right, filePointer);
        fprintf (filePointer, "JMP L%d\nL%d:\n", label1, label2);
        return -1;
    }

    else if (t->nodeType == IFNODE){
        int label1 = getLabel();
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "JZ R%d, L%d\n", resultReg, label1);
        codeGen (t->right, filePointer);
        fprintf (filePointer, "L%d:\n", label1);
        return -1;
    }

    else if (t->nodeType == IFELSE){
        int label1 = getLabel();
        int label2 = getLabel();
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "JZ R%d, L%d\n", resultReg, label1);
        codeGen (t->mid, filePointer);
        fprintf (filePointer, "JMP L%d\n", label2);
        fprintf (filePointer, "L%d:\n", label1);
        codeGen (t->right, filePointer);
        fprintf (filePointer, "L%d:\n", label2);
        return -1;
    }

    else if (t->nodeType == BOOL){
        int resultReg = codeGen (t->left, filePointer);
        if (t->op == '<'){
            fprintf (filePointer, "LT R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == 'l'){
            fprintf (filePointer, "LE R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == '>'){
            fprintf (filePointer, "GT R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == 'g'){
            fprintf (filePointer, "GE R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == '='){
            fprintf (filePointer, "EQ R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == 'n'){
            fprintf (filePointer, "NE R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }
        return resultReg;
    }
}

int evaluate(struct tnode * t) {
    if (t->nodeType == CONNECTOR){
        evaluate (t->left);
        evaluate (t->right);
    }

    else if (t->nodeType == CONST){
        return (t->val);
    }

    else if (t->nodeType == IDENT){
        return (variable_arr [varIndex(t->op)]);
    }

    else if (t->nodeType == INPUT_STMT){
        printf ("input %c:\n", t->left->op);
        scanf ("%d", &variable_arr[varIndex(t->left->op)]);
    }

    else if (t->nodeType == OUTPUT_STMT){
        printf ("%d\n", evaluate (t->left));
    }

    else if (t->nodeType == OP){
        switch (t->op){
            case '+' : return (evaluate (t->left) + evaluate (t->right)); break;
            case '-' : return (evaluate (t->left) - evaluate (t->right)); break;
            case '*' : return (evaluate (t->left) * evaluate (t->right)); break;
            case '/' : return (evaluate (t->left) / evaluate (t->right)); break;
            default : printf ("error\n");
        }
    }

    else if (t->nodeType == ASG_STMT){
        variable_arr[varIndex(t->left->op)] = evaluate (t->right);
    }

    else if (t->nodeType == IFNODE){
        if (evaluate (t->left)){
            evaluate (t->right);
        }
        return -1;
    }

    else if (t->nodeType == IFELSE){
        if (evaluate (t->left)){
            evaluate (t->mid);
        }
        else {
            evaluate (t->right);
        }
        return -1;
    }

    else if (t->nodeType == BOOL){
        if (t->op == '<'){
            if (evaluate (t->left) < evaluate (t->right)) {
                return 1;
            }
            else return 0;
        }

        else if (t->op == 'l'){
            if (evaluate (t->left) <= evaluate (t->right)) return 1;
            else return 0;
        }

        else if (t->op == '>'){
            if (evaluate (t->left) > evaluate (t->right)) return 1;
            else return 0;
        }
        
        else if (t->op == 'g'){
            if (evaluate (t->left) >= evaluate (t->right)) return 1;
            else return 0;
        }

        else if (t->op == '='){
            if (evaluate (t->left) == evaluate (t->right)) return 1;
            else return 0;
        }

        else if (t->op == 'n'){
            if (evaluate (t->left) != evaluate (t->right)) return 1;
            else return 0;
        }
    }

    else if (t->nodeType == WH){
        while (evaluate (t->left)){
            evaluate (t->right);
        }
        return -1;
    }

    return -1;
}