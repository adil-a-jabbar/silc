#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "exprtree.h"
#include "symbolTable.h"

void yyerror();

void funArgsCheck(struct Gsymbol *Gentry, struct tnode *argsHead){
    struct tnode *temp = argsHead;
    struct Paramstruct *paramTemp = Gentry->paramlist;

    while (paramTemp != NULL){
        printf ("%s ", paramTemp->paramName);
        paramTemp = paramTemp->next;
    }
    paramTemp = Gentry->paramlist;

    while (temp != NULL)
    {
        if (paramTemp == NULL)
        {
            char msg[40];
            sprintf(msg, "\n%s(): too many arguments\n", Gentry->name);
            yyerror(msg);
        }
        else if (paramTemp->type != temp->type)
        {
            char msg[40];
            sprintf(msg, "\n%s(): invalid type for arg: %s\n", Gentry->name, paramTemp->paramName);
            yyerror(msg);
        }
        temp = temp->mid;
        paramTemp = paramTemp->next;
    }
    if (paramTemp != NULL)
    {
        char msg[40];
        sprintf(msg, "\n%s(): missing arguments\n", Gentry->name);
        yyerror(msg);
    }
}
