%{
#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"
#include "globals.h"
#include "typetable.h"
#include "classtable.h"
#include "y.tab.h"

void yyerror();
int number;
extern FILE *yyin;

%}
digit [0-9]
letter [a-zA-Z]
underscr [_] 
identifier {letter}({letter}|{digit}|{underscr})* 
minus [-]
%%

"begin"     {printf ("BEGIN "); return START;}
"end"       {printf ("END "); return END;}
"main"      {printf ("MAIN "); return MAIN;}
"return"    {printf ("RETURN "); return RETURN;}
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
"decl"      {printf ("DECL "); return DECL;}
"enddecl"   {printf ("ENDDECL "); return ENDDECL;}
"type"      {printf ("TYPE "); return TYPE;}
"endtype"   {printf ("ENDTYPE "); return ENDTYPE;}
"alloc"     {printf ("ALLOC "); return ALLOC;}
"initialize" {printf ("INITIALIZE "); return INITIALIZE;}
"free"      {printf ("FREE "); return FREE;}
"class"     {printf ("CLASS "); return CLASS;}
"endclass"     {printf ("ENDCLASS "); return ENDCLASS;}
"new"     {printf ("NEW "); return NEW;}
"delete"     {printf ("DELETE "); return DELETE;}
"extends"     {printf ("EXTENDS "); return EXTENDS;}
"self"      {yylval.no = makeIdNode (IDENT, yytext); printf ("SELF "); return SELF;}
"null"      {yylval.no = makeLeafNode (CONST, "-999999", nullType); printf ("NULL "); return NULLVAL;}
"int"       {yylval.no = makeIdNode(INT_TYPE_NODE, yytext); printf ("INT "); return INT;}
"str"       {yylval.no = makeIdNode(STR_TYPE_NODE, yytext); printf ("STR "); return STR;}
{digit}+    {yylval.no = makeLeafNode (CONST, yytext, intType); printf ("NUM "); 
        return NUM;}
\"[^"]*\"  {printf ("STRING "); yylval.no = makeLeafNode (CONST, yytext, strType); return STRING_TYPE;}
{identifier} {printf ("ID "); yylval.no = makeIdNode(IDENT, yytext); return ID;}
"+" {printf ("PLUS "); return PLUS;}
"-" {printf ("MINUS "); return MINUS;}
"*" {printf ("MUL "); return MUL;}
"/" {printf ("DIV "); return DIV;}
"%" {printf ("MOD "); return MOD;}
"," {printf ("COMMA "); return COMMA;}
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
"." {printf ("DOT "); return *yytext;}
"(" {printf ("LBRACE "); return *yytext;}
")" {printf ("RBRACE "); return *yytext;}
"{" {printf ("LCBRACE "); return *yytext;}
"}" {printf ("RCBRACE "); return *yytext;}
"||" {printf ("OR "); return OR;}
"&&" {printf ("AND "); return AND;}
[\n]* {yylineno++;}
[\[\]] {return *yytext;}

%%

int yywrap(){
    return 1;
}