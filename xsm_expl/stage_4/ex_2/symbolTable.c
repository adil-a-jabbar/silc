int getAddress (int size) {
    if (currAddress > 4196) {
        char * msg;
        msg = "out of space\n";
        yyerror (msg);
    }
    int returnVal = currAddress;
    currAddress += size;
    return returnVal;
}

struct Gsymbol * install (char * name, int type, int row_size, int column_size){
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
    temp->row_size = row_size;
    temp->column_size = column_size;
    temp->size = row_size*column_size;
    temp->binding = getAddress (temp->size);

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
        printf ("%s : %d : %s  (size: %d)\n", temp->name, temp->binding, typeToString(temp->type), temp->size);
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
    else if (type==intPointer){
        return ("INT_PTR");
    }
    else if (type==strPointer){
        return ("STR_PTR");
    }
}

struct Gsymbol * setGentry (char * varName){
    struct Gsymbol * Gentry = symbolLookup (varName);
    if (Gentry == NULL){
        char msg[100];
        sprintf (msg, "error: undeclared variable -> '%s'\n", varName);
        yyerror (msg);
    }
    return Gentry;
}