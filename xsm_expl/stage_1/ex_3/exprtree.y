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
%token NUM PLUS MINUS MUL DIV END SPACE
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

expr: PLUS expr expr {$$=makeOperatorNode ('+', $2, $3);}
| MINUS expr expr {$$=makeOperatorNode ('-', $2, $3);}
| DIV expr expr {$$=makeOperatorNode ('/', $2, $3);}
| MUL expr expr {$$=makeOperatorNode ('*', $2, $3);}
| SPACE PLUS expr expr {$$=makeOperatorNode ('+', $3, $4);}
| SPACE MINUS expr expr {$$=makeOperatorNode ('-', $3, $4);}
| SPACE DIV expr expr {$$=makeOperatorNode ('/', $3, $4);}
| SPACE MUL expr expr {$$=makeOperatorNode ('*', $3, $4);}
| SPACE NUM {
    $$=$2;
};

%%

void yyerror(){
    printf ("error\n");
}

int main (void){
    yyparse();
    return 0;
}