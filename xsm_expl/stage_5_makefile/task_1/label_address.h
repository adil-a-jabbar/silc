#ifndef LABEL_ADDRESS_H
#define LABEL_ADDRESS_H
typedef struct listNode{
    char label[5];
    int address;
    struct listNode * next;
} listNode;

extern listNode *head, *tail;
extern void yyerror();
void insert(char *label, int lineNo);
int lookup(char *label);

#endif /* LABEL_ADDRESS_H */
