%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int currLabel = 0;
    int currReg = 0;
    int currAddress = 4096;
    int label_stack [50];
    int top = -1;
    int type;
    struct Gsymbol *head=NULL, *tail=NULL;
    FILE * filePointer;
    #include "exprtree.h"
    #include "symbolTable.h"
    #include "exprtree.c"
    #include "symbolTable.c"

    int yylex(void);
    void yyerror();
    extern FILE *yyin;
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BreakStmt ContinueStmt ID Type VarList Decl DecList Declarations String STRING_TYPE
%token NUM PLUS MINUS MUL DIV MOD END SPACE NEWLINE ID ASSG READ WRITE START COLON LT LE GT GE EQ NE IF THEN ELSE ENDIF WHILE ENDWHILE DO BREAK CONT DECL ENDDECL INT STR COMMA STRING_TYPE
%left LT LE GT GE EQ NE 
%left PLUS MINUS MOD
%left MUL DIV
%left READ WRITE

%%

program: Declarations START Slist END COLON {
    $$ = $3;
    FILE* filePointer = fopen ("executable.xsm", "w");
    printf ("\n-------------\nsymbol table:\n-------------\n");
    printSymbolTable();
    headerGen (filePointer);
    codeGen ($$, filePointer);
    exitGen (filePointer);
    fclose (filePointer);
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

OutputStmt: WRITE expr COLON {$$=makeStmtNode (OUTPUT_STMT, $2, NULL, NULL);}
        |   WRITE String COLON {$$=makeStmtNode (OUTPUT_STMT, $2, NULL, NULL);};

AsgStmt: expr ASSG expr COLON {$$=makeStmtNode (ASG_STMT, $1, $3, NULL);}
    |    expr ASSG String COLON {$$=makeStmtNode (ASG_STMT, $1, $3, NULL);};

BreakStmt: BREAK COLON {$$=makeStmtNode (BRK_STMT, NULL, NULL, NULL);};

ContinueStmt: CONT COLON {$$=makeStmtNode (CONT_STMT, NULL, NULL, NULL);};

String: '(' STRING_TYPE ')' {$$=$2;}
    |   STRING_TYPE {$$=$1;};

expr: expr PLUS expr {$$=makeOperatorNode (OP, '+', $1, $3);}
| expr MINUS expr {$$=makeOperatorNode (OP, '-', $1, $3);}
| expr DIV expr {$$=makeOperatorNode (OP, '/', $1, $3);}
| expr MUL expr {$$=makeOperatorNode (OP, '*', $1, $3);}
| expr MOD expr {$$=makeOperatorNode (OP, '%', $1, $3);}
| '(' expr ')' {$$=$2;  $$->type = $2->type;}
| expr LT expr {$$=makeOperatorNode (BOOL, '<', $1, $3);}
| expr LE expr {$$=makeOperatorNode (BOOL, 'l', $1, $3);}
| expr GT expr {$$=makeOperatorNode (BOOL, '>', $1, $3);}
| expr GE expr {$$=makeOperatorNode (BOOL, 'g', $1, $3);}
| expr EQ expr {$$=makeOperatorNode (BOOL, '=', $1, $3);}
| expr NE expr {$$=makeOperatorNode (BOOL, 'n', $1, $3);}
| NUM {$$=$1;}
| ID {$$=$1; $1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; }
| ID '[' expr ']' {if ($3->type != intType) yyerror("\ntype error !\n"); $1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; $1->left = $3;}
| ID '[' expr ']' '[' expr ']' {$$=$1; $1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type;};

Declarations:   DECL DecList ENDDECL {};
            |   DECL ENDDECL {};

DecList:    DecList Decl {}
        |   Decl {};

Decl: Type VarList COLON {};

Type:   INT {type = intType;}
    |   STR {type = strType;};

VarList:    VarList COMMA ID {install ($3->varName, type, 1, 1); $$->type = type;}
        |   VarList COMMA ID '[' NUM ']' {install ($3->varName, type, 1, $5->val); $$->type = type;}
        |   VarList COMMA ID '[' NUM ']''[' NUM ']'  {install ($3->varName, type, $5->val, $8->val); $$->type = type;}
        |   VarList COMMA MUL ID {printf ("varlist->pointer\n"); install ($4->varName, (type==intType?intPointer:strPointer), 1, 1); $$->type = (type==intType?intPointer:strPointer);}
        |   ID {install ($1->varName, type, 1, 1); $$->type = type;}
        |   ID '[' NUM ']' {install ($1->varName, type, 1, $3->val); $$->type = type;}
        |   ID '[' NUM ']''[' NUM ']' {install ($1->varName, type, $3->val, $6->val); $$->type = type;} 
        |   MUL ID {printf ("varlist->pointer\n"); install ($2->varName, (type==intType?intPointer:strPointer), 1, 1); $$->type = (type==intType?intPointer:strPointer);};

%%

void yyerror(char * msg){
    printf ("%s\n", msg);
    exit (0);
}

int main (void){
    yyin = fopen ("input.txt", "r");
    yyparse();
    return 0;
}