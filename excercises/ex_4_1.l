%option noyywrap
%{
 #include<stdio.h>
   int words_count = 0;
   int char_count = 0;
   int lines_count = 0;
%}

%%

. {char_count ++;}
[a-zA-Z]+ {char_count += yyleng; words_count++;}
\n {lines_count ++; char_count ++;}

%%

int main()
{
   yylex();
   printf ("words: %d   lines: %d   characters: %d\n", words_count, lines_count, char_count);
   return 1;

}
