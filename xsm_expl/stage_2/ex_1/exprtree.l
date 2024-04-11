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

[0-9]+ {number = atoi(yytext); yylval.no = makeLeafNode (CONST, number); return NUM;}
[a-z] {yylval.no = makeIdNode(IDENT, *yytext); return ID;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
" " {}
"=" {return ASSG;}
";" {return COLON;}
[\t] {}
[()] {return *yytext;}
[\n] {}
"begin" {return START;}
"end" {return END;}
"read" {return READ;}
"write" {return WRITE;}

%%

int yywrap(){
    return 1;
}