%{
 #include<stdio.h>
 char *file1;
%}

%%

[0-9]+  printf("number");

%%

int count = 0;

int yywrap()
{
   if(count < 2){
        count ++;
        return 0;
   }
   else
    return 1;
}

int main()
{
   yylex();
   return 1;
}
