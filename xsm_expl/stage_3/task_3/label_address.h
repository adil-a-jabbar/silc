typedef struct listNode{
    char label[4];
    int address;
    struct listNode * next;
}listNode;

void insert (char *label, int lineNo);
int lookup (char *label);

