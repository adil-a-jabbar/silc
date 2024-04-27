%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"
    #include "symbolTable.h"
    #include "exprtree.h"
    #include "typetable.h"
    #include "classtable.h"
    #include "functionChecks.h"

    int yylex(void);
    extern FILE *yyin;
    extern int yylineno;
%}

%union{
    struct tnode* no;
}

%type <no> expr NUM program END Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BreakStmt ContinueStmt FreeStmt ID TypeName String STRING_TYPE TypeDefBlock ClassdefBlock GdeclBlock FdefBlock MainBlock FieldDeclList FieldDecl TypeDefList GdeclList LdeclBlock GidList Gid IdList Fdef Body Retstmt ArgList INT STR Field ALLOC INITIALIZE FREE NULLVAL Type ClassDefList ClassDef Cname Fieldlists Fld MethodDecl MDecl MethodDefns FieldFunction SELF MDeclParam MDeclParamList NEW
%token NUM PLUS MINUS MUL DIV MOD END SPACE NEWLINE ID ASSG READ WRITE START COLON LT LE GT GE EQ NE OR AND IF THEN ELSE ENDIF WHILE ENDWHILE DO BREAK CONT DECL ENDDECL INT STR COMMA STRING_TYPE MAIN RETURN TYPE ENDTYPE ALLOC INITIALIZE FREE NULLVAL SELF DELETE NEW CLASS ENDCLASS EXTENDS
%left AND OR 
%left LT LE GT GE EQ NE 
%left PLUS MINUS MOD
%left MUL DIV
%left READ WRITE

%%

program: TypeDefBlock ClassdefBlock GdeclBlock FdefBlock MainBlock {
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable(); printClassTable();
                        }
        | TypeDefBlock ClassdefBlock GdeclBlock MainBlock {
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable(); printClassTable();
                        };

TypeDefBlock: TYPE TypeDefList ENDTYPE {} | {};

TypeDefList: TypeDefList TypeDef {}
        | TypeDef {};

TypeDef: ID '{' FieldDeclList '}' {Tinstall ($1->varName, $3, -1); Flisthead = NULL; currFieldIndex = 0;};

FieldDeclList: FieldDeclList FieldDecl {$$ = makeConnectorNode (CONNECTOR, $1, $2);}
        | FieldDecl {$$ = $1;};

FieldDecl: TypeName ID COLON {$$ = makeTreeNode(FIELD_DECL, NULL, -1, NULL, '0', NULL, NULL, $1, $2, NULL);};

ClassdefBlock: CLASS ClassDefList ENDCLASS {filePointer = fopen ("executable.xsm", "a"); VFTGen (filePointer); fclose (filePointer);}
                | {};

ClassDefList: ClassDefList ClassDef 
        | ClassDef;

ClassDef: Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' {currFuncposition = 0; currFieldIndex = 0;}
ClassDef: Cname '{' DECL MethodDecl ENDDECL MethodDefns '}' {currFuncposition = 0; currFieldIndex = 0;}
        | Cname '{' DECL Fieldlists ENDDECL '}' {currFuncposition = 0; currFieldIndex = 0;};

Cname: ID {strcpy (currClass, $1->varName); CInstall ($1->varName, NULL);}
        | ID EXTENDS ID {strcpy (currClass, $1->varName); CInstall ($1->varName, $3->varName);};

Fieldlists: Fieldlists Fld {printf ("Fieldlists -> Fieldlists Fld\n");};
        | Fld {printf ("Fieldlists -> Fld\n");};

Fld: INT ID COLON {CFieldInstall (CLookup (currClass), $1->varName, $2->varName);}
    | STR ID COLON {CFieldInstall (CLookup (currClass), $1->varName, $2->varName);}
    | ID ID COLON {CFieldInstall (CLookup (currClass), $1->varName, $2->varName);};

MethodDecl: MethodDecl MDecl 
        | MDecl;

MDecl: ID ID '(' MDeclParamList ')' COLON {CMethodInstall (CLookup(currClass), $1->varName, $2->varName); $$->varName = $2->varName; CParamlisthead = NULL, CParamlisttail = NULL;}
        | INT ID '(' MDeclParamList ')' COLON {CMethodInstall (CLookup(currClass), $1->varName, $2->varName); $$->varName = $2->varName; CParamlisthead = NULL, CParamlisttail = NULL;}
        | STR ID '(' MDeclParamList ')' COLON {CMethodInstall (CLookup(currClass), $1->varName, $2->varName); $$->varName = $2->varName; CParamlisthead = NULL, CParamlisttail = NULL;};

CParamList: CParamList COMMA CParam  {}
    | CParam {}
    |  {Linstall (selfStr, currClass, currNBinding--);};

MDeclParamList: MDeclParamList COMMA MDeclParam  {}
    | MDeclParam {}
    |  {};
    
CParam: INT ID {CParamInstall ($1->varName, $2->varName); if (firstParamFlag == 0) Linstall (selfStr, currClass, currNBinding--); firstParamFlag = 1; Linstall ($2->varName, $1->varName, currNBinding--);}
        | STR ID {CParamInstall ($1->varName, $2->varName); if (firstParamFlag == 0) Linstall (selfStr, currClass, currNBinding--); firstParamFlag = 1; Linstall ($2->varName, $1->varName, currNBinding--);}
        | ID ID {CParamInstall ($1->varName, $2->varName); if (firstParamFlag == 0) Linstall (selfStr, currClass, currNBinding--); firstParamFlag = 1; Linstall ($2->varName, $1->varName, currNBinding--);};

MDeclParam: INT ID {CParamInstall ($1->varName, $2->varName);}
        | STR ID {CParamInstall ($1->varName, $2->varName);}
        | ID ID {CParamInstall ($1->varName, $2->varName);};

MethodDefns: MethodDefns CFdef {printf ("MethodDefns -> MethodDefns CFdef\n"); firstParamFlag = 0; paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
        | CFdef {printf ("MethodDefns -> CFdef\n"); firstParamFlag = 0; paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;};

CFdef: INT ID '(' CParamList ')' '{' LdeclBlock Body '}' {strcpy (currMethod, $2->varName); $8->nodeType = C_FUN_DEF; filePointer = fopen ("executable.xsm", "a"); codeGen ($8, filePointer); fclose (filePointer); Lhead = NULL;}
        | INT ID '(' CParamList ')' '{' Body '}' {strcpy (currMethod, $2->varName); $7->nodeType = C_FUN_DEF; filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); Lhead = NULL;};
        | STR ID '(' CParamList ')' '{' LdeclBlock Body '}' {strcpy (currMethod, $2->varName); $8->nodeType = C_FUN_DEF; filePointer = fopen ("executable.xsm", "a"); codeGen ($8, filePointer); fclose (filePointer); Lhead = NULL;}
        | STR ID '(' CParamList ')' '{' Body '}' {strcpy (currMethod, $2->varName); $7->nodeType = C_FUN_DEF; filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); Lhead = NULL;}
        | ID ID '(' CParamList ')' '{' LdeclBlock Body '}' {strcpy (currMethod, $2->varName); $8->nodeType = C_FUN_DEF; filePointer = fopen ("executable.xsm", "a"); codeGen ($8, filePointer); fclose (filePointer); Lhead = NULL;}
        | ID ID '(' CParamList ')' '{' Body '}' {strcpy (currMethod, $2->varName); $7->nodeType = C_FUN_DEF; filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); Lhead = NULL;};

FieldFunction: Field '.' ID '(' ArgList ')' {$$ = makeCFunCallNode (C_FUN_CALL, $1, $5, $3); strcpy (currClass, $1->Ctype->name);}
            | Field '.' ID '(' ')' {$$ = makeCFunCallNode (C_FUN_CALL, $1, NULL, $3); strcpy (currClass, $1->Ctype->name);}
            | ID '.' ID '(' ArgList ')' {$1->Gentry =  setGentry($1->varName); $1->Ctype = $1->Gentry->Ctype; $$ = makeCFunCallNode (C_FUN_CALL, $1, $5, $3); strcpy (currClass, $1->Ctype->name);}
            | ID '.' ID '(' ')' {$1->Gentry =  setGentry($1->varName); $1->Ctype = $1->Gentry->Ctype; $$ = makeCFunCallNode (C_FUN_CALL, $1, NULL, $3); strcpy (currClass, $1->Ctype->name);}
            | SELF '.' ID '(' ArgList ')' {doesLSymbolExist ($1->varName); $1->Ctype = CLookup(currClass); $$ = makeCFunCallNode (C_FUN_CALL, $1, $5, $3);}
            | SELF '.' ID '(' ')' {doesLSymbolExist ($1->varName); $1->Ctype = CLookup(currClass); $$ = makeCFunCallNode (C_FUN_CALL, $1, NULL, $3);};

GdeclBlock: DECL GdeclList ENDDECL {printf ("GdeclDone\n");} 
            | DECL ENDDECL {} | {};

GdeclList: GdeclList GDecl {} 
        | GDecl {};

GDecl: Type GidList COLON {doesTypeExist($1->varName);};

Type:   INT {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, $1->varName); printf ("type set to %s\n", type);}
    |   STR {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, $1->varName); printf ("type set to %s\n", type);}
    |   ID  {$$ = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', $1->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, $1->varName); printf ("type set to %s\n", type);};

GidList: GidList COMMA Gid {}
        | Gid {};

Gid: ID {Ginstall ($1->varName, TLookup(Gtype), CLookup(Gtype), 1, NULL); $$->type = TLookup(type); $$=$1;}
    | ID '[' NUM ']' {Ginstall ($1->varName, TLookup(Gtype), NULL, $3->val, NULL); $$->type = TLookup(type); $$=$1;}
    | ID '(' GParamList ')' {Ginstall ($1->varName, TLookup(Gtype), CLookup(Gtype), -1, paramList); $$->type = TLookup(type); $$=$1; paramList=NULL; paramListTail=NULL;};


FdefBlock: FdefBlock Fdef {}
        | Fdef {};

Fdef: Type ID '(' ParamList ')' '{' LdeclBlock Body '}' {doesTypeExist($1->varName); currGSymbol = setGentry($2->varName); if (TLookup(Gtype) != currGSymbol->type) {yyerror ("invalid type for function\n");} $8->nodeType = FUN_DEF; checkNameEquivalence ($2->varName); filePointer = fopen ("executable.xsm", "a"); codeGen ($8, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
        | Type ID '(' ParamList ')' '{' Body '}' {doesTypeExist($1->varName); currGSymbol = setGentry($2->varName); if (TLookup(Gtype) != currGSymbol->type) {yyerror ("invalid type for function\n");} $7->nodeType = FUN_DEF; checkNameEquivalence ($2->varName); filePointer = fopen ("executable.xsm", "a"); codeGen ($7, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;};

LdeclBlock: DECL LDeclList ENDDECL {printf ("LdeclBlockDone\n");}
        | DECL ENDDECL {printf ("LdeclBlockDone\n");};

LDeclList: LDeclList LDecl | LDecl {};

LDecl: TypeName IdList COLON {doesTypeExist($1->varName); };

IdList: IdList COMMA ID {Linstall ($3->varName, typeToString(TLookup(type)), currPBinding++);}
        | ID {Linstall ($1->varName, typeToString(TLookup(type)), currPBinding++);};

Body: START Slist END {$$ = makeConnectorNode (FUN_DEF, $2, $3); printf ("Body Done\n");};

ParamList: ParamList COMMA Param  {}
    | Param {}
    |  {};

Param: TypeName ID {doesTypeExist($1->varName); Linstall ($2->varName, typeToString(TLookup(type)), currNBinding--); insertParamList ($2->varName, TLookup(type));};

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

OutputStmt: WRITE expr COLON {$$=makeStmtNode (OUTPUT_STMT, $2, NULL, NULL);};

AsgStmt: expr ASSG expr COLON {$$=makeStmtNode (ASG_STMT, $1, $3, NULL);};

BreakStmt: BREAK COLON {$$=makeStmtNode (BRK_STMT, NULL, NULL, NULL);};

ContinueStmt: CONT COLON {$$=makeStmtNode (CONT_STMT, NULL, NULL, NULL);};

FreeStmt: FREE expr COLON {$$=makeStmtNode (FREE_STMT, NULL, $2, NULL);};

Retstmt: RETURN expr COLON {$$ = makeStmtNode (RET_STMT, $2, NULL, NULL);};

String: STRING_TYPE {$$=$1; $$->type = strType;};

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
| ID                {$$=$1; if (LSymbolLookup ($1->varName) == NULL) {$1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; $1->Ctype = $1->Gentry->Ctype;} else {$1->type = (LSymbolLookup ($1->varName))->type;}}  //add lsymbollookup for array too
| ID '[' expr ']'   {if ($3->type != intType) yyerror("\ntype error !\n"); $1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; $1->left = $3; $$=$1;}
| ID '(' ')'        {doesTypeExist($1->varName); $1->Gentry = setGentry ($1->varName); funArgsCheck($1->Gentry, argsHead[argsTop]); argsTop--; $1->type = $1->Gentry->type; $1->mid = NULL; $$=$1; $$->nodeType=FUN_CALL;}
| ID '(' ArgList ')'{doesTypeExist($1->varName); $1->Gentry = setGentry ($1->varName); funArgsCheck($1->Gentry, argsHead[argsTop]); $1->type = $1->Gentry->type; $1->mid = argsHead[argsTop]; $$=$1; argsHead[argsTop] = NULL; argsTail[argsTop] = NULL; argsTop--; $$->nodeType=FUN_CALL;}
| Field {$$ = $1;}
| ALLOC '(' ')' {$1 = makeAllocNode (ALLOC_NODE, NULL); $$ = $1;}
| INITIALIZE '(' ')' {$1 = makeAllocNode (INITIALIZE_NODE, NULL); $$ = $1;}
| FieldFunction {}
| NEW '(' ID ')' {$1 = makeAllocNode (ALLOC_NODE, CLookup($3->varName)); $$ = $1;}
| DELETE '(' Field ')' {}
| String {$$ = $1;};

Field: Field '.' ID {
                        $$ = makeFieldNode (FIELD_NODE, $1, $3);
                        if ($1->type != NULL){
                                $3->type = (FLookup ($1->type, $3->varName))->type;
                                $3->Ctype = (FLookup ($1->type, $3->varName))->Ctype;
                        }
                        else{
                                $3->type = (Class_FLookup($1->Ctype, $3->varName))->type;
                                $3->Ctype = (Class_FLookup($1->Ctype, $3->varName))->Ctype;
                        }
                        $$->type = $3->type;
                        $$->Ctype = $3->Ctype;
                    }
    | ID '.' ID {if (LSymbolLookup ($1->varName) == NULL) {$1->Gentry = setGentry ($1->varName); $1->type = $1->Gentry->type; $1->Ctype = $1->Gentry->Ctype;} else {$1->type = (LSymbolLookup ($1->varName))->type; $1->Ctype = (LSymbolLookup ($1->varName))->Ctype;}
                    $$ = makeFieldNode (FIELD_NODE, $1, $3);
                    if ($1->type != NULL){
                        $3->type = (FLookup ($1->type, $3->varName))->type;
                        $3->Ctype = (FLookup ($1->type, $3->varName))->Ctype;
                    }
                    else{
                        $3->type = (Class_FLookup($1->Ctype, $3->varName))->type;
                        $3->Ctype = (Class_FLookup($1->Ctype, $3->varName))->Ctype;
                    }
                    $$->type = $3->type;
                    $$->Ctype = $3->Ctype;
                }
    | SELF '.' ID {
                        doesLSymbolExist ($1->varName);
                        $1->Ctype = CLookup (currClass);
                        $1->type = NULL;
                        $$ = makeFieldNode (FIELD_NODE, $1, $3);
                        $3->type = (Class_FLookup($1->Ctype, $3->varName))->type;
                        $3->Ctype = (Class_FLookup($1->Ctype, $3->varName))->Ctype;
                        $$->type = $3->type;
                        $$->Ctype = $3->Ctype;
                };

ArgList: ArgList COMMA expr {argsTail[argsTop]->mid=$3; argsTail[argsTop]=argsTail[argsTop]->mid; argsTail[argsTop]->mid = NULL;}
        | expr {argsTop++; $$=$1; argsHead[argsTop] = $$; argsTail[argsTop] = $$; argsTail[argsTop]->mid = NULL;} ;


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