%option noyywrap
%{
 #include <stdlib.h>
 #include <stdio.h>
%}

number [0-9]+

%%

{number}*[0|2|4|6|8] {printf("Even\n");}
{number}*[1|3|5|7|9] {printf("Odd\n");}

%%

int main()
{
 yylex();
 return 1;
}
