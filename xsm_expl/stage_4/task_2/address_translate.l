%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "label_address.h"
void yyerror();
listNode *head, *tail = NULL;
#include "label_address.c"

extern FILE *yyin;
FILE * filePointer;
int pass=0;
int lineNo=0;
%}

label_decl [a-zA-QST-Z][0-9]+:\n
label [a-zA-QST-Z][0-9]\n
%%

{label_decl} {
            insert (yytext, lineNo);}
.       { 
            fprintf (filePointer,yytext);
        }
\n      {
            fprintf (filePointer,yytext);
            lineNo++;
        }

{label} {
            lineNo++;
            if (pass==0) fprintf (filePointer, yytext);
            
            else{   //second pass
                fprintf (filePointer, "%d\n", lookup (yytext));
            }
        }
%%
void yyerror(){
    printf ("error missing label declaration!\n");
    exit (1);
}

int yywrap (){
    if (pass == 1) return 1;
    pass++;
    yyin = fopen ("label_removed.xsm", "r");
    fclose (filePointer);
    filePointer = fopen ("translated.xsm", "w");
    return 0;
}

int main (){
    filePointer = fopen ("label_removed.xsm", "w");
    yyin = fopen ("executable.xsm", "r");
    yylex();
    return 1;
}