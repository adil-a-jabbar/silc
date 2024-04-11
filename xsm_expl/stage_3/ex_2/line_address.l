%option noyywrap
%{
#include <stdlib.h>
#include <stdio.h>
void yyerror();

extern FILE *yyin;
FILE * filePointer;
int lineNo=0;
%}

%%
.*\n  {
            if (lineNo < 8){
                fprintf (filePointer, "%d: ", 2048+lineNo);
            }
            else {
                fprintf (filePointer, "%d: ", 2056+(lineNo-8)*2);
            }
            fprintf (filePointer, yytext);
            lineNo++;
        }

.       {}

%%

int main (){
    filePointer = fopen ("line_address.txt", "w");
    yyin = fopen ("translated.xsm", "r");
    yylex();
    return 1;
}