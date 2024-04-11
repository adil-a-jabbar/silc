typedef struct tnode{
    int nodeType;
    int val;
    char op;
    struct tnode *left, *right;
}tnode;

struct tnode * makeLeafNode (int nodeType, int n);
struct tnode * makeIdNode (int nodeType, char id);
struct tnode * makeStmtNode (int nodeType, struct tnode * left, struct tnode * right);
struct tnode * makeConnectorNode (int nodeType, struct tnode * left, struct tnode * right);
struct tnode * makeOperatorNode (int nodeType, char op, struct tnode * left, struct tnode * right);

int evaluate (struct tnode * t);
int varIndex (char a);

enum NodeType{
    CONNECTOR,
    ASG_STMT,
    IDENT,
    CONST,
    OP,
    INPUT_STMT,
    OUTPUT_STMT,
};
