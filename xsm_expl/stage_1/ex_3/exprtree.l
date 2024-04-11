%{
#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"
#include "y.tab.h"

void yyerror();
int number;

%}

%%

[0-9]+ {number = atoi(yytext); yylval.no = makeLeafNode (number); return NUM;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
" " {return SPACE;}
[\t] {}
[()] {return *yytext;}
[\n] {return END;}
. {yyerror(); exit(1);}

%%

int yywrap(){
    return 1;
}