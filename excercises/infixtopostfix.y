%{
#include<stdio.h>
#include<stdlib.h>

void print_operator (char op);
int yylex();
int yyerror();
int pos = 0;
int isdigit();

%}

%token DIGIT NEWLINE
%left '+' '-'
%left '*'

%%

start:  expr NEWLINE    {printf ("\n"); exit(1);}
expr:   expr '+' expr   {printf ("+ ");}
    |   expr '*' expr   {printf ("* ");}
    |   expr '-' expr   {printf ("- ");}
    |   DIGIT           {printf ("%d ", $1);}
    |   '(' expr ')'
    ;

%%

void print_operator(char c){
    switch(c){
        case '+'  : printf("PLUS ");
                    break;
        case '*'  : printf("MUL ");
                    break;
    }
    return;
}

int yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main()
{
 yyparse();
 return 1;
}

