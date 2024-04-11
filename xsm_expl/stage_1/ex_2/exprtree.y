%{
    #include <stdio.h>
    #include <stdlib.h>
    int currReg = 0;
    #include "exprtree.h"
    #include "exprtree.c"

    int yylex(void);
    void yyerror();
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program: expr END {
    FILE* filePointer;
    filePointer = fopen ("executable.xsm", "w");
    $$ = $2;
    fprintf (filePointer, "PUSH R%d\n", codeGen ($1, filePointer));
    exit (1);
};

expr: expr PLUS expr {$$=makeOperatorNode ('+', $1, $3);}
| expr MINUS expr {$$=makeOperatorNode ('-', $1, $3);}
| expr DIV expr {$$=makeOperatorNode ('/', $1, $3);}
| expr MUL expr {$$=makeOperatorNode ('*', $1, $3);}
| '(' expr ')' {$$=$2;}
| NUM {
    $$=$1;
};

%%

void yyerror(){
    printf ("error\n");
}

int main (void){
    yyparse();
    return 0;
}