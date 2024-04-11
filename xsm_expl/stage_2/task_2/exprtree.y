%{
    #include <stdio.h>
    #include <stdlib.h>
    int currReg = 0;
    #include "exprtree.h"
    #include "exprtree.c"

    int yylex(void);
    void yyerror();
    extern FILE *yyin;
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END Slist Stmt InputStmt OutputStmt AsgStmt ID
%token NUM PLUS MINUS MUL DIV END SPACE NEWLINE ID ASSG READ WRITE START COLON
%left ASSG 
%left PLUS MINUS
%left MUL DIV
%left READ WRITE

%%

program: START Slist END COLON {
    $$ = $2;
    FILE* filePointer = fopen ("executable.xsm", "w");
    headerGen (filePointer);
    codeGen ($2, filePointer);
    exitGen (filePointer);
    exit (1);
};

Slist:  Slist Stmt {$$=makeConnectorNode (CONNECTOR, $1, $2);}
        | Stmt {$$=$1;};

Stmt:   InputStmt {$$=$1;}
        | OutputStmt {$$=$1;}
        | AsgStmt {$$=$1;};

InputStmt: READ expr COLON {$$=makeStmtNode (INPUT_STMT, $2, NULL);};

OutputStmt: WRITE expr COLON {$$=makeStmtNode (OUTPUT_STMT, $2, NULL);};

AsgStmt: expr ASSG expr COLON {$$=makeStmtNode (ASG_STMT, $1, $3);};

expr: expr PLUS expr {$$=makeOperatorNode (OP, '+', $1, $3);}
| expr MINUS expr {$$=makeOperatorNode (OP, '-', $1, $3);}
| expr DIV expr {$$=makeOperatorNode (OP, '/', $1, $3);}
| expr MUL expr {$$=makeOperatorNode (OP, '*', $1, $3);}
| '(' expr ')' {$$=$2;}
| NUM {$$=$1;}
| ID {$$=$1;};

%%

void yyerror(){
    printf ("error\n");
}

int main (void){
    FILE* tempFile = fopen("executable.xsm", "w");
    fclose (tempFile);
    yyin = fopen ("input.txt", "r");
    yyparse();
    return 0;
}