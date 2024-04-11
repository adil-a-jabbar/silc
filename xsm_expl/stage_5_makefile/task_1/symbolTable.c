#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "exprtree.h"
#include "symbolTable.h"

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

struct Gsymbol * Ginstall (char * name, int type, int size, struct Paramstruct * paramlist){
    if (GSymbolLookup(name) != NULL){ //check if symbol already exist
        char msg[100]; 
        sprintf (msg, "\nerror! '%s' re-declared", name);
        yyerror (msg);
    }
    struct Gsymbol * temp;
    temp = (struct Gsymbol *) malloc (sizeof(struct Gsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy (temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->paramlist = paramlist;

    if (size != -1) //variable
        temp->binding = getAddress (temp->size);

    else{   //function
        temp->binding = -1;
        temp->flabel = getFlabel();
        temp->paramlist = paramList;
    }

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
        printf (" %s %s (binding: %d) |", typeToString(temp->type), temp->name, temp->binding);
        temp = temp->next;
    }
    printf ("\n");
}

struct Lsymbol * Linstall (char * name, int type, int binding){
    if (LSymbolLookup(name) != NULL){ //check if symbol already exist
        char msg[100]; 
        sprintf (msg, "\nerror! '%s' re-declared", name);
        yyerror (msg);
    }
    struct Lsymbol * temp;
    temp = (struct Lsymbol *) malloc (sizeof(struct Lsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy (temp->name, name);
    temp->type = type;
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

void printParamList(struct Paramstruct * paramlist){
    struct Paramstruct * temp = paramlist;
    printf ("       paramList:   ");
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
            printf ("| retType: %s  | flabel: %d |\n",  typeToString(temp->type), temp->flabel);
            // printLSymbolTable(temp);
            printParamList(temp->paramlist);
        }
        else{
            printf ("| variable | %s", temp->name);
            for (int i=0; i<(11-strlen(temp->name)); i++) printf (" ");
            printf ("| binding: %d | type: %s | size: %d |\n", temp->binding, typeToString(temp->type), temp->size);
        }
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
    return ("INVALID");
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

void insertParamList (char* varName, int type) {
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
        Linstall (temp->paramName, temp->type, --currNBinding);
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
    printf ("\n");
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
