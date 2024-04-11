%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int currLabel = 0;
    int currReg = 0;
    int variable_arr [26];
    int currAddress = 4096;
    int label_stack [50];
    int top = -1;
    int type;
    struct Gsymbol *head=NULL, *tail=NULL;
    #include "exprtree.h"
    #include "exprtree.c"
    #include "symbolTable.h"
    #include "symbolTable.c"

    int yylex(void);
    void yyerror();
    extern FILE *yyin;
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BreakStmt ContinueStmt ID Type VarList Decl DecList Declarations
%token NUM PLUS MINUS MUL DIV END SPACE NEWLINE ID ASSG READ WRITE START COLON LT LE GT GE EQ NE IF THEN ELSE ENDIF WHILE ENDWHILE DO BREAK CONT DECL ENDDECL INT STR COMMA
%left LT LE GT GE EQ NE 
%left PLUS MINUS
%left MUL DIV
%left READ WRITE

%%

program: Declarations START Slist END COLON {
    $$ = $3;
    // FILE* filePointer = fopen ("executable.xsm", "w");
    printf ("\nsymbol table:\n");
    printSymbolTable();
    // headerGen (filePointer);
    // codeGen ($$, filePointer);
    // exitGen (filePointer);
    exit (1);
};

Slist:  Slist Stmt {$$=makeConnectorNode (CONNECTOR, $1, $2);}
        | Stmt {$$=$1;};

Stmt:   InputStmt {$$=$1;}
        | OutputStmt {$$=$1;}
        | AsgStmt {$$=$1;}
        | IfStmt {$$=$1;}
        | WhileStmt {$$=$1;}
        | BreakStmt {$$=$1;}
        | ContinueStmt {$$=$1;};

IfStmt: IF expr THEN Slist ELSE Slist ENDIF COLON {$$=makeStmtNode (IFELSE, $2, $6, $4);}
        | IF expr THEN Slist ENDIF COLON {$$=makeStmtNode (IFNODE, $2, $4, NULL);};

WhileStmt: WHILE expr DO Slist ENDWHILE COLON {$$=makeStmtNode (WH, $2, $4, NULL);};

InputStmt: READ expr COLON {$$=makeStmtNode (INPUT_STMT, $2, NULL, NULL);};

OutputStmt: WRITE expr COLON {$$=makeStmtNode (OUTPUT_STMT, $2, NULL, NULL);};

AsgStmt: expr ASSG expr COLON {$$=makeStmtNode (ASG_STMT, $1, $3, NULL);};

BreakStmt: BREAK COLON {$$=makeStmtNode (BRK_STMT, NULL, NULL, NULL);};

ContinueStmt: CONT COLON {$$=makeStmtNode (CONT_STMT, NULL, NULL, NULL);};

expr: expr PLUS expr {$$=makeOperatorNode (OP, '+', $1, $3); $$->type = intType;}
| expr MINUS expr {$$=makeOperatorNode (OP, '-', $1, $3); $$->type = intType;}
| expr DIV expr {$$=makeOperatorNode (OP, '/', $1, $3); $$->type = intType;}
| expr MUL expr {$$=makeOperatorNode (OP, '*', $1, $3); $$->type = intType;}
| '(' expr ')' {$$=$2;  $$->type = $2->type;}
| expr LT expr {$$=makeOperatorNode (BOOL, '<', $1, $3); $$->type = boolType;}
| expr LE expr {$$=makeOperatorNode (BOOL, 'l', $1, $3); $$->type = boolType;}
| expr GT expr {$$=makeOperatorNode (BOOL, '>', $1, $3); $$->type = boolType;}
| expr GE expr {$$=makeOperatorNode (BOOL, 'g', $1, $3); $$->type = boolType;}
| expr EQ expr {$$=makeOperatorNode (BOOL, '=', $1, $3); $$->type = boolType;}
| expr NE expr {$$=makeOperatorNode (BOOL, 'n', $1, $3); $$->type = boolType;}
| NUM {$$=$1;}
| ID {$$=$1;};

Declarations:   DECL DecList ENDDECL {};
            |   DECL ENDDECL {};

DecList:    DecList Decl {}
        |   Decl {};

Decl: Type VarList COLON {};

Type:   INT {type = intType;}
    |   STR {type = strType;};

VarList:    VarList COMMA ID {$$->Gentry = install ($3->varName, type, 1); $$->type = type;}
        |   ID {$$->Gentry = install ($1->varName, type, 1); $$->type = type;};

%%

void yyerror(char * msg){
    printf ("%s\n", msg);
    exit (0);
}

int main (void){
    FILE* tempFile = fopen("executable.xsm", "w");
    fclose (tempFile);
    yyin = fopen ("input.txt", "r");
    yyparse();
    return 0;
}