%{
 #include<stdio.h>
 char *file1;
%}

%%

[0-9]+  printf("number");

%%

int yywrap()
{
   if(yyin != stdin)
   {
      yyin = stdin;
      return 0;
   }
   else
    return 1;
}

int main()
{
   FILE *newfile_pointer = fopen("input_file","r");
   yyin = newfile_pointer;
   yylex();
   return 1;
}
