%option noyywrap
%{
 #include<stdio.h>
%}

%%

[A][a-zA-Z][a-zA-Z][ \t\n] {printf ("%s\n", yytext);}
.|\n                            {}


%%

int main()
{
   yylex();
   return 1;

}
