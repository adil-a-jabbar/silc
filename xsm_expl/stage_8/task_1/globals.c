#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "typetable.h"
#include "classtable.h"

int currLabel = 0;
int currFlabel = 0;
int currReg = 0;
int currAddress = 4096;
int currPBinding = 1;
int currNBinding = -1;
int currClassIndex = 0;
int currFieldIndex = 0;
int currFuncposition = 0;
int currTypeSize = 0;
int firstParamFlag = 0;
int argsTop = 0;
int label_stack[50];
int top = -1;
int regUseStack[50];
int regUseStackTop = -1;
char type[20] = "";
char Gtype[20] = "";
char selfStr[20] = "self";
char currMethod[20] = "";
char currClass[20] = "";
struct Gsymbol *Ghead = NULL, *Gtail = NULL;
struct Lsymbol *Lhead = NULL, *Ltail = NULL;
struct Typetable *Thead = NULL, *Ttail = NULL;
struct Classtable *Chead = NULL, *Ctail = NULL;
struct Typetable *intType = NULL, *strType = NULL, *boolType = NULL, *nullType = NULL;
struct Fieldlist *Flisthead = NULL, *Flisttail = NULL;
struct Gsymbol *currGSymbol = NULL;
struct Paramstruct *paramList = NULL;
struct Paramstruct *paramListTail = NULL;
struct Paramstruct *CParamlisthead = NULL;
struct Paramstruct *CParamlisttail = NULL;
struct tnode *argsHead[10] = {NULL};
struct tnode *argsTail[10] = {NULL};

FILE *filePointer = NULL;