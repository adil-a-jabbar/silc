%{
#include<stdio.h>
int yyerror();
%}

%union{
char character;
}

%token <character> LETTER NEWLINE

%left '+' '-'
%left '*' '/'

%%
start:	expr NEWLINE {printf ("\n"); exit (1);}

expr:	expr '+' expr {printf ("+ ");}
	| expr '*' expr {printf ("* ");}
	| expr '-' expr {printf ("- ");}
	| expr '/' expr {printf ("/ ");}
	| LETTER {printf ("%c ", $<character>1);}
	;

%%
int yyerror(){
printf ("Error\n");
}

int main(){
yyparse();
return 1;
}
