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

int varIndex (char a){
    return a-97;
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
        printf ("input %c\n", t->left->op);
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

    return -1;
}