%option noyywrap
%{
 #include<stdio.h>
%}

%%

\/\/.* {printf ("%s\n", yytext);}
\/\*(.|\n)*?(\*\/) {printf ("%s\n", yytext);}
.|\n    {}

%%

int main()
{
   FILE * in_file = fopen ("input_file", "r");
   yyin = in_file;
   yylex();
   return 1;

}
