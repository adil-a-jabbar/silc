struct tnode * makeLeafNode (int n){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode * makeOperatorNode (char op, struct tnode * left, struct tnode * right){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->op = op;
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
    if (t->op == NULL){
        printf ("%d ", t->val);
    }

    else{
        printf ("%c ", t->op);
    }
    if (t->left != NULL)
    prefix (t->left);

    if (t->right != NULL)
    prefix (t->right);
}

void postfix (struct tnode * t){
    if (t->left != NULL)
    postfix (t->left);

    if (t->right != NULL)
    postfix (t->right);

    if (t->op == NULL){
        printf ("%d ", t->val);
    }

    else{
        printf ("%c ", t->op);
    }
}

int getReg (){
    currReg ++;
    return currReg-1;
}

void freeReg(){
    currReg --;
}

int codeGen (struct tnode *t, FILE * filePointer){
    if (t->op == NULL){
        int resultReg = getReg();
        fprintf (filePointer, "MOV R%d, %d\n", resultReg, t->val);
        return resultReg;
    }

    else{
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
}
