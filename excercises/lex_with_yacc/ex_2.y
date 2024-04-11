%{
#include<stdio.h>
int yyerror();
%}

%union{
char* word;
}

%token <word> WORD NEWLINE

%left '+' '-'
%left '*' '/'

%%
start:	expr NEWLINE {printf ("\n"); exit (1);}

expr:	expr '+' expr {printf ("+ ");}
	| expr '*' expr {printf ("* ");}
	| expr '-' expr {printf ("- ");}
	| expr '/' expr {printf ("/ ");}
	| WORD {printf ("%s ", $<word>1);}
	;

%%
int yyerror(){
printf ("Error\n");
}

int main(){
yyparse();
return 1;
}
