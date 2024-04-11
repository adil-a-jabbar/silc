void insert (char *label, int lineNo) {
    //remove ':' from label declaration
    int i=0;
    while (label[i]!=':') i++;
    label [i] = '\n'; label [i+1] = '\0';
    //
    struct listNode * temp = (struct listNode*) malloc (sizeof(struct listNode));
    strcpy (temp->label, label);
    temp->address = 2056+((lineNo-8)*2);

    if (head==NULL) {
        head = temp;
        tail = temp;
    }

    else{
        tail->next = temp;
        tail = temp;
    }
}

int lookup (char *label){
    if (head==NULL) yyerror();
    struct listNode * curr = head;
    while (curr != NULL){
        if (strcmp (label, curr->label) == 0){
            return curr->address;
        }
        curr = curr->next;
    }
    yyerror();
}