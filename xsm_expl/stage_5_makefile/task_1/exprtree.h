#ifndef EXPRTREE_H
#define EXPRTREE_H

typedef struct tnode {
    int nodeType;
    int type;
    int val;
    char *strVal;
    char op;
    char *varName;
    struct Gsymbol *Gentry;
    struct tnode *left, *right, *mid;
} tnode;

tnode *makeLeafNode(int nodeType, char *val, int type);
tnode *makeIdNode(int nodeType, char *id);
tnode *makeStmtNode(int nodeType, struct tnode *left, struct tnode *right, struct tnode *mid);
tnode *makeConnectorNode(int nodeType, struct tnode *left, struct tnode *right);
tnode *makeOperatorNode(int nodeType, char op, struct tnode *left, struct tnode *right);
tnode *makeDeclNode(int nodeType, int type, int size);

int evaluate(struct tnode *t);

int getReg();
void freeReg();
int getFlabel ();
int codeGen(struct tnode *t, FILE *filePointer);
void headerGen (FILE * filePointer);
void exitGen (FILE * filePointer);

enum NodeType {
    CONNECTOR,
    ASG_STMT,
    IDENT,
    CONST,
    OP,
    INPUT_STMT,
    OUTPUT_STMT,
    BOOL,
    IFNODE,
    IFELSE,
    WH,
    BRK_STMT,
    CONT_STMT,
    RET_STMT,
    DECL_NODE,
    FUN_DEF,
    MAIN_FUN,
    FUN_CALL,
};

enum Type {
    intType,
    boolType,
    strType,
    intPointer,
    strPointer,
};

#endif /* EXPRTREE_H */
