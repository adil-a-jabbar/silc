%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"
    #include "symbolTable.h"
    #include "functionChecks.h"
    #include "exprtree.h"

    int yylex(void);
    extern FILE *yyin;
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BreakStmt ContinueStmt ID Type String STRING_TYPE GdeclBlock FdefBlock MainBlock GdeclList LdeclBlock GidList Gid IdList Fdef Body Retstmt ArgList
%token NUM PLUS MINUS MUL DIV MOD END SPACE NEWLINE ID ASSG READ WRITE START COLON LT LE GT GE EQ NE OR AND IF THEN ELSE ENDIF WHILE ENDWHILE DO BREAK CONT DECL ENDDECL INT STR COMMA STRING_TYPE MAIN RETURN
%left AND OR 
%left LT LE GT GE EQ NE 
%left PLUS MINUS MOD
%left MUL DIV
%left READ WRITE

%%

program: GdeclBlock FdefBlock MainBlock {printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
    printSymbolTable();}
        | GdeclBlock MainBlock {printf ("\n----------------------------------------------------------------\n                          symbol table:           \n----------------------------------------------------------------\n");
    printSymbolTable();}
        | MainBlock {
    // $$ = $3;
    // FILE* filePointer = fopen ("executable.xsm", "w");
    printf ("\n-------------\nsymbol table:\n-------------\n");
    printSymbolTable();
    // codeGen ($$, filePointer);
    // exitGen (filePointer);
    // fclose (filePointer);
    // exit (1);
};

GdeclBlock: DECL GdeclList ENDDECL {} 
            | DECL ENDDECL {};

GdeclList: GdeclList GDecl {} 
        | GDecl {};

GDecl: Type GidList COLON {};

GidList: GidList COMMA Gid {}
        | Gid {};

Gid: ID {Ginstall ($1->varName, type, 1, NULL); $$->type = type; $$=$1;}
    | ID '[' NUM ']' {Ginstall ($1->varName, type, $3->val, NULL); $$->type = type; $$=$1;}
    | ID '(' GParamList ')' {Ginstall ($1->varName, type, -1, paramList); $$->type = type; $$=$1; paramList=NULL; paramListTail=NULL;};


FdefBlock: FdefBlock Fdef {};
        | Fdef {};

Fdef: Type ID '(' ParamList ')' '{' LdeclBlock Body '}' {currGSymbol = setGentry($2->varName); if (type != currGSymbol->type) {yyerror ("invalid type for function\n");} $8->nodeType = FUN_DEF; checkNameEquivalence ($2->varName); filePointer = fopen ("executable.xsm", "a"); codeGen ($8, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;};

LdeclBlock: DECL LDeclList ENDDECL {}
        | DECL ENDDECL {};

LDeclList: LDeclList LDecl | LDecl {};

LDecl: Type IdList COLON {};

IdList: IdList COMMA ID {Linstall ($3->varName, type, currPBinding++);}
        | ID {Linstall ($1->varName, type, currPBinding++);};

Body: START Slist Retstmt END {$$ = makeConnectorNode (FUN_DEF, $2, $3);};

Retstmt: RETURN expr COLON {$$ = makeStmtNode (RET_STMT, $2, NULL, NULL);};

ParamList: ParamList COMMA Param  {}
    | Param {}
    |  {};

Param: Type ID {Linstall ($2->varName, type, currNBinding--); insertParamList ($2->varName, type);};

GParamList: GParamList COMMA GParam  {}
    | GParam {}
    |  {};

GParam: Type ID {insertParamList ($2->varName, type);};

MainBlock: Type MAIN '(' ')' '{' LdeclBlock Body '}' {$7->nodeType = MAIN_FUN; filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;};

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

String: '(' STRING_TYPE ')' {$$=$2; $$->type=strType;}
    |   STRING_TYPE {$$=$1; $$->type=strType;};

expr: expr PLUS expr {$$=makeOperatorNode (OP, '+', $1, $3);}
| expr MINUS expr    {$$=makeOperatorNode (OP, '-', $1, $3);}
| expr DIV expr {$$=makeOperatorNode (OP, '/', $1, $3);}
| expr MUL expr {$$=makeOperatorNode (OP, '*', $1, $3);}
| expr MOD expr {$$=makeOperatorNode (OP, '%', $1, $3);}
| '(' expr ')' {$$=$2;  $$->type = $2->type;}
| expr LT expr {$$=makeOperatorNode (BOOL, '<', $1, $3);}
| expr LE expr {$$=makeOperatorNode (BOOL, 'l', $1, $3);}
| expr GT expr {$$=makeOperatorNode (BOOL, '>', $1, $3);}
| expr GE expr {$$=makeOperatorNode (BOOL, 'g', $1, $3);}
| expr EQ expr {$$=makeOperatorNode (BOOL, '=', $1, $3); printf ("expr->expr eq expr\n");}
| expr NE expr {$$=makeOperatorNode (BOOL, 'n', $1, $3);}
| expr OR expr {$$=makeOperatorNode (BOOL, '|', $1, $3); printf ("expr->expr or expr\n");}
| expr AND expr {$$=makeOperatorNode (BOOL, '&', $1, $3);}
| NUM {$$=$1;}
| ID                {$$=$1; if (LSymbolLookup ($1->varName) == NULL) {$1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type;} else {$1->type = (LSymbolLookup ($1->varName))->type;}}  //add lsymbollookup for array too
| ID '[' expr ']'   {if ($3->type != intType) yyerror("\ntype error !\n"); $1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; $1->left = $3; $$=$1;}
| ID '(' ')'        {$1->Gentry = setGentry ($1->varName); funArgsCheck($1->Gentry, argsHead); $1->type = $1->Gentry->type; $1->mid = NULL; $$=$1; $$->nodeType=FUN_CALL;}
| ID '(' ArgList ')'{$1->Gentry = setGentry ($1->varName); funArgsCheck($1->Gentry, argsHead); $1->type = $1->Gentry->type; $1->mid = argsHead; $$=$1; argsHead = NULL; argsTail = NULL; $$->nodeType=FUN_CALL;};

ArgList: ArgList COMMA expr {argsTail->mid=$3; argsTail=argsTail->mid; argsTail->mid = NULL;}
        | expr {$$=$1; argsHead = $$; argsTail = $$; argsTail->mid = NULL;} 


Type:   INT {type = intType;}
    |   STR {type = strType;};


%%

void yyerror(char * msg){
    printf ("%s\n", msg);
    exit (1);
}

int main (){
    yyin = fopen ("input.txt", "r");
    filePointer = fopen ("executable.xsm", "w");
    headerGen (filePointer);
    fclose (filePointer);
    printf ("tokens:\n-------------\n");
    yyparse();
    filePointer = fopen ("executable.xsm", "a");
    exitGen (filePointer);
    return 0;
}