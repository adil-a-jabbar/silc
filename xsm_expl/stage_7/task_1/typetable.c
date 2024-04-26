#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"globals.h"
#include"exprtree.h"
#include"typetable.h"
#include "symbolTable.h"

void TypeTableCreate() {
    char * name = (char*) malloc (5*sizeof(char));
    
    //install int
    strcpy (name, "int");
    intType = Tinstall (name, NULL, 1);

    //install str
    strcpy (name, "str");
    strType = Tinstall (name, NULL, 1);

    //install void
    strcpy (name, "void");
    nullType = Tinstall (name, NULL, 0);

    //install bool
    strcpy (name, "bool");
    boolType = Tinstall (name, NULL, 0);
}

struct Typetable * Tinstall (char * name, struct tnode * fields, int size) {
    printf ("installing %s\n", name);
    //duplicate check
    if (TLookup (name) != NULL){
        char msg[40];
        sprintf(msg, "\n%s: type already exists\n", name);
        yyerror(msg);
    }

    struct Typetable * temp = (struct Typetable *) malloc (sizeof(struct Typetable));
    temp->name = (char*)malloc(strlen(name)+1);
    strcpy (temp->name, name);
    temp->size = size;
    if (Thead == NULL){
        Thead = temp;
        Ttail = temp;
        Ttail->next = NULL;
    }
    else {
        Ttail->next = temp;
        Ttail = Ttail->next;
        Ttail->next = NULL;
    }
    temp->fields = Finstall (temp, fields);
    printf ("instaleld field list:\n");
    printFieldList (temp->fields);
    if (temp->size != 1){
        temp->size = currTypeSize;
        currTypeSize = 0;
    }
    return temp;
}

struct Fieldlist * Finstall (struct Typetable * type, struct tnode * t){
    if (t == NULL){
        return NULL;
    }

    if (t->nodeType == CONNECTOR){
        Finstall (type, t->left);
        Finstall (type, t->right);
    }

    else if (t->nodeType == FIELD_DECL){
        if (currTypeSize > 8){
            char msg[40];
            sprintf(msg, "\nfor type '%s': too many member fields\n", type->name);
            yyerror(msg);
        }
        //add duplicate fields check
        doesTypeExist(t->left->varName);
        currTypeSize++;
        struct Fieldlist * temp = (struct Fieldlist *) malloc (sizeof(struct Fieldlist));
        temp->name = (char *) malloc (sizeof(t->right->varName));
        strcpy (temp->name, t->right->varName);
        temp->fieldIndex = currFieldIndex++;
        temp->type = TLookup (t->left->varName);
        

        if (Flisthead == NULL){
            Flisthead = temp;
            Flisttail = temp;
            Flisttail->next=NULL;
        }

        else {
            Flisttail->next = temp;
            Flisttail = Flisttail->next;
            Flisttail->next=NULL;
        }
    }
    return Flisthead;
}

struct Typetable * TLookup (char * name) {
    struct Typetable * temp = Thead;
    while (temp != NULL){
        if (strcmp(name, temp->name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct Fieldlist* FLookup(struct Typetable *type, char *name){
    struct Fieldlist * temp = type->fields;
    while (temp != NULL){
        if (strcmp (temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printTypeTable () {
    printf ("\n---------------------------\n|        Typetable        |\n---------------------------\n");
    printf ("|  typeName  |  typeSize  |\n---------------------------\n");
    struct Typetable * temp = Thead;
    while (temp != NULL) {
        printf ("|    ");
        printf ("%s", temp->name);
        for (int i=0; i<8-strlen(temp->name); i++){
            printf (" ");
        }
        printf ("|      ");
        printf ("%d", temp->size);
        printf ("     | ");
        if (temp->fields != NULL){
            printFieldList (temp->fields);
        }
        printf ("\n");
        temp = temp->next;
    }
    printf ("---------------------------\n");
    printf ("\n");
}

void printFieldList (struct Fieldlist * fields) {
    printf ("  --> member fields: ");
    struct Fieldlist * temp = fields;
    while (temp != NULL){
        printf ("%s (type: %s, index: %d)    ", temp->name, typeToString(temp->type), temp->fieldIndex);
        temp = temp->next;
    }
}

void doesTypeExist (char typeName[20]){
    if (TLookup(typeName) == NULL){
        char msg[40];
        sprintf(msg, "\n%s: unknown type '%s'\n", typeName, typeName);
        yyerror(msg);
    }
}