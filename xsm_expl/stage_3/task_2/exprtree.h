typedef struct tnode{
    int nodeType;
    int type;
    int val;
    char op;
    struct tnode *left, *right, *mid;
}tnode;

struct tnode * makeLeafNode (int nodeType, int n);
struct tnode * makeIdNode (int nodeType, char id);
struct tnode * makeStmtNode (int nodeType, struct tnode * left, struct tnode * right, struct tnode * mid);
struct tnode * makeConnectorNode (int nodeType, struct tnode * left, struct tnode * right);
struct tnode * makeOperatorNode (int nodeType, char op, struct tnode * left, struct tnode * right);

int varIndex (char a);
int evaluate (struct tnode * t);

void prefix (struct tnode * t);
void postfix (struct tnode * t);
void infix (struct tnode * t);
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
};

enum type {
    intType,
    boolType,
    strType,
};