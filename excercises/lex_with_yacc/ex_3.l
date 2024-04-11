%{
#include<stdio.h>
#include "y.tab.h"
%}

%option noyywrap

%%

[a-zA-Z]+ {yylval.word = strdup(yytext); return WORD;}
"*" {return *yytext;}
"+" {return *yytext;}
"-" {return *yytext;}
"/" {return *yytext;}
[\n] {return NEWLINE;}

%%
