int getAddress (int size) { //for static allocation
    int returnVal = currAddress;
    currAddress += size;
    return returnVal;
}

struct Gsymbol * install (char * name, int type, int size){
    if (symbolLookup(name) != NULL){ //check if symbol already exist
        char * msg;
        sprintf (msg, "\nerror! variable '%s' re-declared", name);
        yyerror (msg);
    }
    struct Gsymbol * temp;
    temp = (struct Gsymbol *) malloc (sizeof(struct Gsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy (temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->binding = getAddress (size);

    if (head == NULL) { 
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
    return temp;
}

struct Gsymbol * symbolLookup (char *name){
    struct Gsymbol * temp = head;
    while (temp != NULL) {
        if (strcmp (name, temp->name) == 0){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void printSymbolTable(){
    struct Gsymbol * temp = head;
    while (temp != NULL){
        printf ("%s : %d : %s\n", temp->name, temp->binding, typeToString(temp->type));
        temp = temp->next;
    }
}

char * typeToString (int type){
    if (type==intType){
        return ("INT");
    }
    else if (type==strType){
        return ("STR");
    }
}