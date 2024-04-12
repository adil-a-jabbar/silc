%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"
    #include "symbolTable.h"
    #include "functionChecks.h"
    #include "exprtree.h"
    #include "typetable.h"
    #include "classtable.h"

    int yylex(void);
    extern FILE *yyin;
    extern int yylineno;
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BreakStmt ContinueStmt FreeStmt ID TypeName String STRING_TYPE TypeDefBlock ClassdefBlock GdeclBlock FdefBlock MainBlock FieldDeclList FieldDecl TypeDefList GdeclList LdeclBlock GidList Gid IdList Fdef Body Retstmt ArgList INT STR Field ALLOC INITIALIZE FREE NULLVAL Type ClassDefList ClassDef Cname Fieldlists Fld MethodDecl MDecl MethodDefns FieldFunction
%token NUM PLUS MINUS MUL DIV MOD END SPACE NEWLINE ID ASSG READ WRITE START COLON LT LE GT GE EQ NE OR AND IF THEN ELSE ENDIF WHILE ENDWHILE DO BREAK CONT DECL ENDDECL INT STR COMMA STRING_TYPE MAIN RETURN TYPE ENDTYPE ALLOC INITIALIZE FREE NULLVAL SELF DELETE NEW CLASS ENDCLASS
%left AND OR 
%left LT LE GT GE EQ NE 
%left PLUS MINUS MOD
%left MUL DIV
%left READ WRITE

%%

program: TypeDefBlock ClassdefBlock GdeclBlock FdefBlock MainBlock {
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        }
        | TypeDefBlock ClassdefBlock GdeclBlock MainBlock {
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        };

TypeDefBlock: TYPE TypeDefList ENDTYPE {} | {};

TypeDefList: TypeDefList TypeDef {}
        | TypeDef {};

TypeDef: ID '{' FieldDeclList '}' {Tinstall ($1->varName, $3, -1); Flisthead = NULL; currFieldIndex = 0;};

FieldDeclList: FieldDeclList FieldDecl {$$ = makeConnectorNode (CONNECTOR, $1, $2);}
        | FieldDecl {$$ = $1;};

FieldDecl: TypeName ID COLON {$$ = makeTreeNode(FIELD_DECL, NULL, -1, NULL, '0', NULL, NULL, $1, $2, NULL);};

ClassdefBlock: CLASS ClassDefList ENDCLASS {}
                | {};

ClassDefList: ClassDefList ClassDef 
        | ClassDef {};

ClassDef: Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' {};

Cname: ID {CInstall ($1->varName, NULL);};

Fieldlists: Fieldlists Fld {};
        | Fld {};

Fld: INT ID COLON {}
    | STR ID COLON {}
    | ID ID COLON {};

MethodDecl: MethodDecl MDecl {};
        | MDecl {};

MDecl: ID ID '(' ParamList ')' COLON {}
        | INT ID '(' ParamList ')' COLON
        | STR ID '(' ParamList ')' COLON;

MethodDefns: MethodDefns Fdef {}
        | Fdef {};

FieldFunction: SELF '.' ID '(' ArgList ')' {}
            | ID '.' ID '(' ArgList ')' {}
            | Field '.' ID '(' ArgList ')' {};

GdeclBlock: DECL GdeclList ENDDECL {printf ("GdeclDone\n"); printSymbolTable();} 
            | DECL ENDDECL {} | {};

GdeclList: GdeclList GDecl {} 
        | GDecl {};

GDecl: Type GidList COLON {doesTypeExist($1->varName); };

Type:   INT {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, $1->varName); printf ("type set to %s\n", type);}
    |   STR {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, $1->varName); printf ("type set to %s\n", type);}
    |   ID  {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, $1->varName); printf ("type set to %s\n", type);};

GidList: GidList COMMA Gid {}
        | Gid {};

Gid: ID {Ginstall ($1->varName, TLookup(Gtype), 1, NULL); $$->type = TLookup(type); $$=$1;}
    | ID '[' NUM ']' {Ginstall ($1->varName, TLookup(Gtype), $3->val, NULL); $$->type = TLookup(type); $$=$1;}
    | ID '(' GParamList ')' {Ginstall ($1->varName, TLookup(Gtype), -1, paramList); $$->type = TLookup(type); $$=$1; paramList=NULL; paramListTail=NULL;};


FdefBlock: FdefBlock Fdef {}
        | Fdef {};

Fdef: Type ID '(' ParamList ')' '{' LdeclBlock Body '}' {doesTypeExist($1->varName); currGSymbol = setGentry($2->varName); if (TLookup(Gtype) != currGSymbol->type) {yyerror ("invalid type for function\n");} $8->nodeType = FUN_DEF; checkNameEquivalence ($2->varName); filePointer = fopen ("executable.xsm", "a"); codeGen ($8, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
        | Type ID '(' ParamList ')' '{' Body '}' {doesTypeExist($1->varName); currGSymbol = setGentry($2->varName); if (TLookup(Gtype) != currGSymbol->type) {yyerror ("invalid type for function\n");} $7->nodeType = FUN_DEF; checkNameEquivalence ($2->varName); filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;};

LdeclBlock: DECL LDeclList ENDDECL {printf ("LdeclBlockDone\n");}
        | DECL ENDDECL {printf ("LdeclBlockDone\n");};

LDeclList: LDeclList LDecl | LDecl {};

LDecl: TypeName IdList COLON {doesTypeExist($1->varName); };

IdList: IdList COMMA ID {Linstall ($3->varName, TLookup(type), currPBinding++);}
        | ID {Linstall ($1->varName, TLookup(type), currPBinding++);};

Body: START Slist END {$$ = makeConnectorNode (FUN_DEF, $2, $3); printf ("Body Done\n");};

ParamList: ParamList COMMA Param  {}
    | Param {}
    |  {};

Param: TypeName ID {doesTypeExist($1->varName); Linstall ($2->varName, TLookup(type), currNBinding--); insertParamList ($2->varName, TLookup(type));};

GParamList: GParamList COMMA GParam  {}
    | GParam {}
    |  {};

GParam: TypeName ID {doesTypeExist($1->varName); insertParamList ($2->varName, TLookup(type));};

MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}' {$7->nodeType = MAIN_FUN; filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
        | INT MAIN '(' ')' '{' Body '}' {$6->nodeType = MAIN_FUN; filePointer = fopen ("executable.xsm", "a"); codeGen ($6, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}; 

Slist:  Slist Stmt {$$=makeConnectorNode (CONNECTOR, $1, $2);}
        | Stmt {$$=$1;};

Stmt:   InputStmt {$$=$1;}
        | OutputStmt {$$=$1;}
        | AsgStmt {$$=$1;}
        | IfStmt {$$=$1;}
        | WhileStmt {$$=$1;}
        | BreakStmt {$$=$1;}
        | ContinueStmt {$$=$1;}
        | Retstmt {$$=$1;}
        | FreeStmt {$$=$1;};

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

FreeStmt: FREE expr COLON {$$=makeStmtNode (FREE_STMT, NULL, $2, NULL);};

Retstmt: RETURN expr COLON {$$ = makeStmtNode (RET_STMT, $2, NULL, NULL);};

String: '(' STRING_TYPE ')' {$$=$2; $$->type = strType;}
    |   STRING_TYPE {$$=$1; $$->type = strType;};

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
| NULLVAL           {$$=$1;}  //add lsymbollookup for array too
| ID                {$$=$1; if (LSymbolLookup ($1->varName) == NULL) {$1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type;} else {$1->type = (LSymbolLookup ($1->varName))->type;}}  //add lsymbollookup for array too
| ID '[' expr ']'   {if ($3->type != intType) yyerror("\ntype error !\n"); $1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; $1->left = $3; $$=$1;}
| ID '(' ')'        {$1->Gentry = setGentry ($1->varName); funArgsCheck($1->Gentry, argsHead); $1->type = $1->Gentry->type; $1->mid = NULL; $$=$1; $$->nodeType=FUN_CALL;}
| ID '(' ArgList ')'{$1->Gentry = setGentry ($1->varName); funArgsCheck($1->Gentry, argsHead); $1->type = $1->Gentry->type; $1->mid = argsHead; $$=$1; argsHead = NULL; argsTail = NULL; $$->nodeType=FUN_CALL;}
| Field {$$ = $1;}
| ALLOC '(' ')' {$1 = makeAllocNode (ALLOC_NODE); $$ = $1;}
| INITIALIZE '(' ')' {$1 = makeAllocNode (INITIALIZE_NODE); $$ = $1;}
| FieldFunction {}
| NEW '(' ID ')' {}
| DELETE '(' Field ')' {};

Field: Field '.' ID {
                        $$ = makeFieldNode (FIELD_NODE, $1, $3);
                        if ((FLookup ($1->type, $3->varName)) == NULL){
                            char msg[100];
                            sprintf (msg, "'%s' does not have a member named '%s'\n", $1->type->name, $3->varName);
                            yyerror (msg);
                        }
                        else
                        $3->type = (FLookup ($1->type, $3->varName))->type;
                        $$->type = $3->type;
                    }
    | ID '.' ID {if (LSymbolLookup ($1->varName) == NULL) {$1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type;} else {$1->type = (LSymbolLookup ($1->varName))->type;}
                    if ((FLookup ($1->type, $3->varName)) == NULL){
                        char msg[100];
                        sprintf (msg, "'%s' does not have a member named '%s'\n", $1->type->name, $3->varName);
                        yyerror (msg);
                    }
                    else
                    $3->type = (FLookup ($1->type, $3->varName))->type;
                    $$ = makeFieldNode (FIELD_NODE, $1, $3);
                    $$->type = $3->type;
                };

ArgList: ArgList COMMA expr {argsTail->mid=$3; argsTail=argsTail->mid; argsTail->mid = NULL;}
        | expr {$$=$1; argsHead = $$; argsTail = $$; argsTail->mid = NULL;} 


TypeName:   INT {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (type, $1->varName); printf ("type set to %s\n", type);}
    |   STR {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (type, $1->varName); printf ("type set to %s\n", type);}
    |   ID  {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (type, $1->varName); printf ("type set to %s\n", type);};


%%

void yyerror(char * msg){
    printf (ANSI_COLOR_RED "\nerror in line %d: %s\n" ANSI_COLOR_RESET, yylineno, msg);
    exit (1);
}

int main (){
    yyin = fopen ("input.txt", "r");
    filePointer = fopen ("executable.xsm", "w");
    headerGen (filePointer);
    fclose (filePointer);
    TypeTableCreate();
    printf ("tokens:\n-------------\n");
    yyparse();
    filePointer = fopen ("executable.xsm", "a");
    exitGen (filePointer);
    return 0;
}