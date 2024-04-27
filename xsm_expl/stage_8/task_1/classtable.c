#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"globals.h"
#include"exprtree.h"
#include"typetable.h"
#include "symbolTable.h"
#include "classtable.h"

struct Classtable * CInstall (char *name, char *pname) {
    printf ("installing class %s\n", name);
    //duplicate check
    if (CLookup (name) != NULL){
        char msg[40];
        sprintf(msg, "\n%s: class already exists\n", name);
        yyerror(msg);
    }

    struct Classtable * temp = (struct Classtable *) malloc (sizeof(struct Classtable));
    temp->name = (char*)malloc(strlen(name)+1);
    strcpy (temp->name, name);
    temp->Class_index = currClassIndex++;
    temp->Fieldcount = 0;
    temp->Methodcount = 0;
    temp->Memberfield = NULL;
    temp->Vfuncptr = NULL;
    if (pname == NULL)
        temp->Parentptr = NULL;
    else{
        temp->Parentptr = CLookup (pname);
        temp->Fieldcount = temp->Parentptr->Fieldcount;
        temp->Methodcount = temp->Parentptr->Methodcount;
        classInherit (temp, temp->Parentptr);   //copy memberfunctions and fields from parent class
    }
    if (Chead == NULL){
        Chead = temp;
        Ctail = temp;
        Ctail->next = NULL;
    }
    else {
        Ctail->next = temp;
        Ctail = Ctail->next;
        Ctail->next = NULL;
    }
    
    return temp;
}

struct Classtable * CLookup (char *name) {
    struct Classtable * temp = Chead;
    while (temp != NULL){
        if (strcmp (name, temp->name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void CFieldInstall (struct Classtable * cptr, char * typename, char *name) {
    struct CFieldlist * temp = (struct CFieldlist *) malloc (sizeof (struct CFieldlist));
    temp->name = (char*)malloc(strlen(name)+1);
    strcpy (temp->name, name);
    if (TLookup(typename) != NULL){
        temp->type = TLookup(typename);
        temp->Ctype = NULL;
    }
    else if (CLookup (typename) != NULL) {
        temp->Ctype = CLookup(typename);
        temp->type = NULL;
    }
    if (currFieldIndex == 8){
        char msg[40];
        sprintf(msg, "\n%s: too many fields\n", currClass);
        yyerror(msg);
    }
    temp->Fieldindex = currFieldIndex++;
    if (cptr->Memberfield == NULL) {    //first member field
        cptr->Memberfield = temp;
    }

    else{           //attach new member at the end
        struct CFieldlist * temp2 = cptr->Memberfield;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    temp->next = NULL;
    printf ("installed %s in member fields list of %s\n", name, cptr->name);
}

void CMethodInstall (struct Classtable * cptr, char * typename, char *name) {
    //no more than 8 functions
    if (currFuncposition == 8){
        char msg[40];
        sprintf(msg, "\n%s: too many methods\n", cptr->name);
        yyerror(msg);
    }
    //check if method already exists
    struct Memberfunclist * temp3 = cptr->Vfuncptr;
        while (temp3 != NULL){
            if (strcmp (temp3->name, name) == 0) {  //already exists
                if (cptr->Parentptr != NULL){
                    temp3->Flabel = getFlabel();    //override
                    return;
                }
                else{
                    char msg[40];
                    sprintf(msg, "\nmultiple decl of method '%s'\n", name);
                    yyerror(msg);
                }
            }
            temp3 = temp3->next;
        }

    struct Memberfunclist * temp = (Memberfunclist*) malloc (sizeof(Memberfunclist));
    if (TLookup(typename) != NULL){
        temp->type = TLookup(typename);
        temp->Ctype = NULL;
    }

    else if (CLookup(typename) != NULL){
        temp->Ctype = CLookup(typename);
        temp->type = NULL;
    }

    temp->name = (char*)malloc(strlen(name)+1);
    strcpy (temp->name, name);
    temp->paramlist = CParamlisthead;
    temp->Funcposition = currFuncposition++;
    temp->Flabel = getFlabel();
    temp->next = NULL;

    if (cptr->Vfuncptr == NULL) {
        cptr->Vfuncptr = temp;
    }
    else{
        struct Memberfunclist * temp2 = cptr->Vfuncptr;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    printf ("installed method %s in methodlist of class %s\n", name, cptr->name);
}

void CParamInstall (char * typename, char *name) {
    struct Paramstruct * temp = (struct Paramstruct *) malloc (sizeof (struct Paramstruct));
    temp->paramName = (char*)malloc(strlen(name)+1);
    strcpy (temp->paramName, name);

    if (TLookup(typename) != NULL){
        temp->type = TLookup(typename);
        temp->Ctype = NULL;
    }

    else if (CLookup (typename) != NULL) {
        temp->Ctype = CLookup(typename);
        temp->type = NULL;
    }

    temp->next = NULL;
    if (CParamlisthead == NULL) {
        CParamlisthead = temp;
        CParamlisttail = temp;
    }

    else {
        CParamlisttail->next = temp;
        CParamlisttail = CParamlisttail->next;
    }
    printf ("%s added to cparamlist\n", name);
}

void printClassTable(){
    struct Classtable * temp;
    temp = Chead;
    printf ("\n----------------------------\n|        Class Table       |\n----------------------------\n");
    printf ("| Class Name | Class Index |\n");
    printf ("----------------------------\n");
    while (temp != NULL) {
        printf ("|   %s", temp->name);
        for (int i=0; i<(9-strlen(temp->name)); i++)
            printf (" ");

        printf ("|      %d      |\n", temp->Class_index);
        printMemberFields (temp);
        printMethods (temp);
        temp = temp->next;
    }
}

void printMemberFields (struct Classtable * cptr) {
    struct CFieldlist * temp = cptr->Memberfield;
    printf ("Member fields:\n");
    printf ("| field name  |  field type  |  field index  |\n");
    printf ("----------------------------------------------\n");
    while (temp != NULL){
        printf ("|  %s", temp->name);
        for (int i=0; i<(11-strlen(temp->name)); i++)
            printf (" ");
        printf ("|");
        if (temp->type != NULL){
            printf ("  %s", typeToString(temp->type));
            for (int i=0; i<(12-strlen(typeToString(temp->type))); i++)
                printf (" ");
            printf ("|");
        }

        else if (temp->Ctype != NULL) {
            printf ("  %s  |", temp->Ctype->name);
        }
        printf ("       %d       |\n", temp->Fieldindex);
        temp = temp->next;
    }
}

void printMethods (struct Classtable * cptr) {
    struct Memberfunclist * temp = cptr->Vfuncptr;
    printf ("Methods:\n");
    printf ("|     Method Name     |   retType   | Fun Index | Flabel |\n");
    printf ("----------------------------------------------------------\n");
    
    while (temp != NULL) {
        printf ("|  %s", temp->name);
        for (int i=0; i<(19-strlen(temp->name)); i++)
            printf (" ");
        printf ("|");
        if (temp->type != NULL){
            printf ("  %s", typeToString(temp->type));
            for (int i=0; i<(11-strlen(typeToString(temp->type))); i++)
                printf (" ");
            printf ("|");
        }

        else if (temp->Ctype != NULL) {
            printf ("  %s  |", temp->Ctype->name);
        }
        printf ("     %d     |", temp->Funcposition);
        printf ("   F%d   |\n", temp->Flabel);
        temp = temp->next;
    }
    printf ("\n");
}

struct CFieldlist * Class_FLookup (struct Classtable * cptr, char * name) {
    struct CFieldlist * temp = cptr->Memberfield;
    while (temp != NULL){
        if (strcmp (temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct Memberfunclist * Class_MLookup (struct Classtable * cptr, char * name) {
    if (cptr == NULL) {
        return NULL;
    }
    struct Memberfunclist * temp = cptr->Vfuncptr;
    while (temp != NULL){
        if (strcmp (temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void classInherit (struct Classtable * child, struct Classtable * parent) {
    struct Memberfunclist * tempFunc = parent->Vfuncptr;
    //copy methods from parent
    while (tempFunc != NULL) {
        CMethodCopy (child, tempFunc);
        tempFunc = tempFunc->next;
    }

    //copy fields from parent
    struct CFieldlist * tempField = parent->Memberfield;
    while (tempField != NULL){
        struct Classtable * Ctype = tempField->Ctype;
        struct Typetable * type = tempField->type;               
        if (type != NULL){
            CFieldInstall (child, type->name, tempField->name);
        }
        else if (Ctype != NULL) {
            CFieldInstall (child, Ctype->name, tempField->name);
        }
        tempField = tempField->next;
    }
}

void CMethodCopy (struct Classtable * cptr, struct Memberfunclist * method) {
    struct Memberfunclist * temp = (Memberfunclist*) malloc (sizeof(Memberfunclist));

    temp->name = (char*)malloc(strlen(method->name)+1);
    strcpy (temp->name, method->name);
    temp->paramlist = method->paramlist;
    temp->Funcposition = currFuncposition++;
    temp->Flabel = method->Flabel;
    temp->type = method->type;
    temp->Ctype = method->Ctype;
    printf ("%s->flabel = %d, %s->flabel = %d\n", temp->name, temp->Flabel, method->name, method->Flabel);
    temp->next = NULL;

    if (cptr->Vfuncptr == NULL) {
        cptr->Vfuncptr = temp;
    }
    else{
        struct Memberfunclist * temp2 = cptr->Vfuncptr;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    printf ("copied method %s in methodlist of class %s\n", temp->name, cptr->name);
}

int checkInheritance (Classtable *left, Classtable * right) {
     if (right != left && (isNotChild (right, left))){
        return 1;
     }

     else return 0;
}

int isNotChild (Classtable * child, Classtable * parent) {
    if (child->Parentptr == NULL) {
        return 1;
    }

    while (child->Parentptr != NULL)  {
        if (child->Parentptr == parent){
            return 0;
        }
        child = child->Parentptr;
    }
    return 1;
}