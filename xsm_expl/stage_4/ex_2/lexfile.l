%{
#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"
#include "y.tab.h"

void yyerror();
int number;
extern FILE *yyin;

%}
digit [0-9]
letter [a-zA-Z]
underscr [_] 
identifier {letter}({letter}|{digit}|{underscr})* 
%%

"begin"     {printf ("BEGIN "); return START;}
"end"       {printf ("END "); return END;}
"read"      {printf ("READ "); return READ;}
"write"     {printf ("WRITE "); return WRITE;}
"if"        {printf ("IF "); return IF;}
"endif"     {printf ("ENDIF "); return ENDIF;}
"else"      {printf ("ELSE "); return ELSE;}
"then"      {printf ("THEN "); return THEN;}
"while"     {printf ("WHILE "); return WHILE;}
"endwhile"  {printf ("ENDWHILE "); return ENDWHILE;}
"do"        {printf ("DO "); return DO;}
"break"     {printf ("BREAK "); return BREAK;}
"continue"  {printf ("CONT "); return CONT;}
"decl"      {printf ("tokens:\n---------\nDECL "); return DECL;}
"enddecl"   {printf ("ENDDECL "); return ENDDECL;}
"int"       {printf ("INT "); return INT;}
"str"       {printf ("STR "); return STR;}
{digit}+    {yylval.no = makeLeafNode (CONST, yytext, intType); printf ("NUM "); 
        return NUM;}
[\"].*[\"]  {printf ("STRING "); yylval.no = makeLeafNode (CONST, yytext, strType); return STRING_TYPE;}
{identifier} {printf ("ID "); yylval.no = makeIdNode(IDENT, yytext); return ID;}
"+" {printf ("PLUS "); return PLUS;}
"-" {printf ("MINUS "); return MINUS;}
"*" {printf ("MUL "); return MUL;}
"/" {printf ("DIV "); return DIV;}
"%" {printf ("MOD "); return MOD;}
"," {printf (", "); return COMMA;}
" " {}
"=" {printf ("ASSG "); return ASSG;}
";" {printf ("COLON "); return COLON;}
"<" {printf ("LT "); return LT;}
"<=" {printf ("LE "); return LE;}
">"  {printf ("GT "); return GT;}
">=" {printf ("GE "); return GE;}
"==" {printf ("EQ "); return EQ;}
"!=" {printf ("NE "); return NE;}
[\t] {}
[()] {return *yytext;}
[\n] {}
[\[\]] {return *yytext;}

%%

int yywrap(){
    return 1;
}