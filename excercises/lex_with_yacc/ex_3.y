%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int yyerror();
char output[50][50];
int curr_index=0;
int flag=0;
%}

%union{
char* word;
}

%token <word> WORD NEWLINE

%left '+' '-'
%left '*' '/'

%%
start:	expr NEWLINE {
	printf ("%s ", $<word>$);
	printf ("\n");
	 exit (1);
	}

expr:	expr '+' expr {$<word>$ = mknod('+', $<word>1, $<word>3);}

		| expr '-' expr {$<word>$ = mknod('-', $<word>1, $<word>3);}

		| expr '/' expr {$<word>$ = mknod('/', $<word>1, $<word>3);}
		
		| expr '*' expr {$<word>$ = mknod('*', $<word>1, $<word>3);}
	| WORD
	;

%%
char* mknod(char op, char* str1, char* str2){
	int newlen = strlen (str1) + strlen (str2) + 4;
	char* newstr = malloc ((newlen+4)*sizeof(char));
	newstr[0]=op;
	newstr[1]=' ';
	strcpy (newstr+2, str1);
	newstr[strlen(str1)+2]=' ';
	strcpy (newstr+3+strlen(str1), str2);
	newstr[newlen] = ' ';
	return newstr;
}

int yyerror(){
printf ("Error\n");
}

int main(){
yyparse();
return 1;
}
