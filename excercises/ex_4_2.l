%option noyywrap
%{
 #include<stdio.h>
   int int_count = 0;
   int float_count = 0;
%}

%%

[0-9]+ {int_count ++;}
[0-9]+"."[0-9]* {float_count++ ;}

%%

int main()
{
   yylex();
   printf ("integers: %d   floating point nums: %d\n", int_count, float_count);
   return 1;

}
