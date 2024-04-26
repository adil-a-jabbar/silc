#ifndef EXPRTREE_H
#define EXPRTREE_H
#include<stdio.h>

typedef struct tnode {
    int nodeType;
    struct Typetable * type;
    struct Classtable * Ctype;
    int val;
    char *strVal;
    char op;
    char *varName;
    struct Gsymbol *Gentry;
    struct tnode *left, *right, *mid;
} tnode;

tnode *makeLeafNode(int nodeType, char *val, struct Typetable * type);
tnode *makeIdNode(int nodeType, char *id);
tnode *makeStmtNode(int nodeType, struct tnode *left, struct tnode *right, struct tnode *mid);
tnode *makeConnectorNode(int nodeType, struct tnode *left, struct tnode *right);
tnode *makeOperatorNode(int nodeType, char op, struct tnode *left, struct tnode *right);
tnode *makeDeclNode(int nodeType, struct Typetable * type, int size);
tnode *makeTreeNode (int nodeType, struct Typetable * type, int val, char *strVal, char op, char *varName, struct Gsymbol *Gentry, struct tnode *left,struct tnode *right,struct tnode *mid);
struct tnode * makeCFunCallNode (int nodeType, struct tnode *left, struct tnode *mid, struct tnode *right);
struct tnode * makeSelfNode (int nodeType, char *varName);
struct tnode * makeAllocNode (int nodeType, struct Classtable * class);
struct tnode * makeFieldNode (int nodeType, struct tnode * left, struct tnode * right);

int evaluate(struct tnode *t);

int getReg();
void freeReg();
int getFlabel ();
int codeGen(struct tnode *t, FILE *filePointer);
void headerGen (FILE * filePointer);
void exitGen (FILE * filePointer);
void Initialize (FILE * filePointer);
void VFTGen (FILE * filePointer);

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
    FREE_STMT,
    DECL_NODE,
    FUN_DEF,
    MAIN_FUN,
    FUN_CALL,
    FIELD_DECL,
    TYPE_NODE,
    INT_TYPE_NODE,
    STR_TYPE_NODE,
    FIELD_NODE,
    ALLOC_NODE,
    INITIALIZE_NODE,
    SELF_NODE,
    C_FUN_CALL,
    C_FUN_DEF,
};


#endif /* EXPRTREE_H */
