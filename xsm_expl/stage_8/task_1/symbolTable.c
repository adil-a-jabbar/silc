#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "exprtree.h"
#include "symbolTable.h"
#include "typetable.h"
#include "classtable.h"

int getAddress (int size) {
    if (currAddress > 4196) {
        char msg[100]; 
        strcpy (msg, "out of space\n");
        yyerror (msg);
    }
    int returnVal = currAddress;
    currAddress += size;
    return returnVal;
}

struct Gsymbol * Ginstall (char * name, struct Typetable * type, struct Classtable *Ctype, int size, struct Paramstruct * paramlist){
    if (GSymbolLookup(name) != NULL){ //check if symbol already exist
        char msg[100]; 
        sprintf (msg, "\nerror! '%s' re-declared", name);
        yyerror (msg);
    }
    struct Gsymbol * temp;
    temp = (struct Gsymbol *) malloc (sizeof(struct Gsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy (temp->name, name);
    if (type != NULL){
        temp->type = type;
        temp->Ctype = NULL;
        printf ("installing %s with type: %s\n", name, typeToString (type));
    }
    else{
        temp->Ctype = Ctype;
        temp->type = NULL;
        printf ("installing %s with type: %s\n", name, temp->Ctype->name);
    }
    if (Ctype != NULL)
        temp->size = 2;
    else
        temp->size = size;
    temp->paramlist = paramlist;

    if (size != -1) //variable
        temp->binding = getAddress (temp->size);

    else{   //function
        temp->binding = -1;
        temp->flabel = getFlabel();
        temp->paramlist = paramList;
    }

    temp->next = NULL;

    if (Ghead == NULL) { 
        Ghead = temp;
        Gtail = temp;
    }
    else {
        Gtail->next = temp;
        Gtail = Gtail->next;
    }
    return temp;
}

void printLSymbolTable(){
    struct Lsymbol * temp = Lhead;
    printf ("       Local symbols now: ");
    if (temp == NULL) printf ("none");
    while (temp != NULL){
        if (temp->Ctype == NULL)
        printf (" %s %s (binding: %d) |", typeToString(temp->type), temp->name, temp->binding);
        else
        printf (" %s %s (binding: %d) |", temp->Ctype->name, temp->name, temp->binding);
        temp = temp->next;
    }
    printf ("\n");
}

struct Lsymbol * Linstall (char * name, char *typename, int binding){
    if (LSymbolLookup(name) != NULL){ //check if symbol already exist
        char msg[100]; 
        sprintf (msg, "\nerror! '%s' re-declared", name);
        yyerror (msg);
    }
    struct Lsymbol * temp;
    temp = (struct Lsymbol *) malloc (sizeof(struct Lsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy (temp->name, name);
    if (TLookup(typename) != NULL){
        temp->type = TLookup(typename);
        temp->Ctype = NULL;
    }
    else if (CLookup(typename) != NULL){
        temp->Ctype = CLookup (typename);
        temp->type = NULL;
    }
    temp->binding = binding;
    
    if (Lhead == NULL) { 
        Lhead = temp;
        Ltail = temp;
    }
    else {
        Ltail->next = temp;
        Ltail = Ltail->next;
    }
    Ltail->next = NULL;
    printLSymbolTable ();
    return temp;
}

struct Gsymbol * GSymbolLookup (char *name){
    struct Gsymbol * temp = Ghead;
    while (temp != NULL) {
        if (strcmp (name, temp->name) == 0){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

struct Lsymbol * LSymbolLookup (char *name){
    struct Lsymbol * temp = Lhead;
    while (temp != NULL) {
        if (strcmp (name, temp->name) == 0){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void doesLSymbolExist (char *name) {
    struct Lsymbol * temp = Lhead;
    while (temp != NULL) {
        if (strcmp (name, temp->name) == 0){
            return;
        }
        temp=temp->next;
    }
    char msg[100];
    sprintf (msg, "\nerror: '%s' unknown\n", name);
    yyerror (msg);
}

void printParamList(struct Paramstruct * paramlist){
    struct Paramstruct * temp = paramlist;
    printf (" paramList: ");
    while (temp != NULL){
        printf (" %s %s |", typeToString (temp->type), temp->paramName);
        temp = temp->next;
    }
    printf ("\n");
}

void printSymbolTable(){
    struct Gsymbol * temp = Ghead;
    while (temp != NULL){
        if (temp->size == -1){
            printf ("| function | %s", temp->name);
            for (int i=0; i<(11-strlen(temp->name)); i++) printf (" ");
            if (temp->type != NULL)
            printf ("| retType: %s  | flabel: %d |",  typeToString(temp->type), temp->flabel);
            else if (temp->Ctype != NULL)
            printf ("| retType: %s  | flabel: %d |",  temp->Ctype->name, temp->flabel);
            // printLSymbolTable(temp);
            printParamList(temp->paramlist);
        }
        else{
            printf ("| variable | %s", temp->name);
            for (int i=0; i<(11-strlen(temp->name)); i++) printf (" ");
            if (temp->type != NULL)
            printf ("| binding: %d | type: %s | size: %d |\n", temp->binding, typeToString(temp->type), temp->size);
            else if (temp->Ctype != NULL)
            printf ("| binding: %d | type: %s | size: %d |\n", temp->binding, temp->Ctype->name, temp->size);
        }
        temp = temp->next;
    }
}


char * typeToString (struct Typetable * type){
    char * typeString = (char *) malloc (10*sizeof(char));
    if (type != NULL){
        strcpy (typeString, type->name);
        return typeString;
    }
    return NULL;
}

struct Gsymbol * setGentry (char * varName){
    struct Gsymbol * Gentry = GSymbolLookup (varName);
    if (Gentry == NULL){
        char msg[100];
        sprintf (msg, "\nerror: '%s' undeclared\n", varName);
        yyerror (msg);
    }
    return Gentry;
}

void insertParamList (char* varName, struct Typetable * type) {
    struct Paramstruct * temp = (struct Paramstruct*) malloc (sizeof(Paramstruct));
    temp->paramName = (char*) malloc (sizeof(varName));
    strcpy (temp->paramName, varName);
    temp->type = type;
    if (paramList == NULL){
        paramList = temp;
        paramListTail = paramList;
        paramListTail->next = NULL;
    }

    else{
        paramListTail->next = temp;
        paramListTail = paramListTail->next;
        paramListTail->next = NULL;
    }
}


void paramListToLsymbol (){
    struct Paramstruct * temp = paramList;
    while (temp != NULL){
        Linstall (temp->paramName, typeToString(temp->type), --currNBinding);
        temp = temp->next;
    }
}

void checkNameEquivalence (char * name){
    struct Gsymbol * Gentryptr = setGentry (name);
    struct Paramstruct * paramlist = Gentryptr->paramlist;
    struct Paramstruct * temp = paramList;
    printf ("orgiginal paramList:\n");
    while (paramlist != NULL){
        printf ("%s, %s  ", typeToString(paramlist->type), paramlist->paramName);
        paramlist = paramlist->next;
    }
    printf ("new paramList:\n");
    while (temp != NULL){
        printf ("%s, %s  ", typeToString(temp->type), temp->paramName);
        temp = temp->next;
    }
    printf ("\n");
    paramlist = Gentryptr->paramlist;
    temp = paramList;
    while (paramlist != NULL) {
        if (temp == NULL){
            char msg[50];
            sprintf (msg, "\nerror: in defn of %s(): missing parameters\n", name);
            yyerror (msg);
        }
        if ((strcmp (temp->paramName, paramlist->paramName)) | (temp->type != paramlist->type)){
            char msg[70];
            sprintf (msg, "\nerror: in defn of %s(): invalid parameters   (expected: %s %s  found: %s %s)\n", name, typeToString(paramlist->type), paramlist->paramName, typeToString(temp->type), temp->paramName);
            yyerror (msg);
        }
        paramlist = paramlist->next;
        temp = temp->next;
    }
    if (temp != NULL) {
        char msg[50];
        sprintf (msg, "\nerror: in defn of %s(): too many parameters\n", name);
        yyerror (msg);
    }
}
