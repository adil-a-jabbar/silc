%{
#include<stdio.h>
#include "y.tab.h"
%}

%option noyywrap

%%

[a-zA-Z] {yylval.character = *yytext; return LETTER;}
"*" {return *yytext;}
"+" {return *yytext;}
"-" {return *yytext;}
"/" {return *yytext;}
[\n] {return NEWLINE;}

%%







