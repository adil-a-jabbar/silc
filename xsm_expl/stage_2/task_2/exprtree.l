%{
#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"
#include "y.tab.h"

void yyerror();
int number;
extern FILE *yyin;

%}

%%

[0-9]+ {number = atoi(yytext); yylval.no = makeLeafNode (CONST, number); printf ("NUM "); return NUM;}
[a-z] {yylval.no = makeIdNode(IDENT, *yytext); printf ("ID "); return ID;}
"+" {printf ("PLUS "); return PLUS;}
"-" {printf ("MINUS "); return MINUS;}
"*" {printf ("MUL "); return MUL;}
"/" {printf ("DIV "); return DIV;}
" " {}
"=" {printf ("ASSG "); return ASSG;}
";" {return COLON;}
[\t] {}
[()] {return *yytext;}
[\n] {}
"begin" {printf ("BEGIN "); return START;}
"end" {printf ("END "); return END;}
"read" {printf ("READ "); return READ;}
"write" {printf ("WRITE "); return WRITE;}

%%

int yywrap(){
    return 1;
}