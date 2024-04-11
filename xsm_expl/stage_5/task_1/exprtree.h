typedef struct tnode{
    int nodeType;
    int type;
    int val;
    char * strVal;
    char op;
    char * varName;
    struct Gsymbol * Gentry;
    struct tnode *left, *right, *mid;
}tnode;

struct tnode * makeLeafNode (int nodeType, char *val, int type);
struct tnode * makeIdNode (int nodeType, char* id);
struct tnode * makeStmtNode (int nodeType, struct tnode * left, struct tnode * right, struct tnode * mid);
struct tnode * makeConnectorNode (int nodeType, struct tnode * left, struct tnode * right);
struct tnode * makeOperatorNode (int nodeType, char op, struct tnode * left, struct tnode * right);
struct tnode * makeDeclNode (int nodeType, int type, int size);

int evaluate (struct tnode * t);

int getReg();
void freeReg();
int codeGen(struct tnode *t, FILE * filePointer);

enum NodeType{
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

enum type {
    intType,
    boolType,
    strType,
    intPointer,
    strPointer,
};
