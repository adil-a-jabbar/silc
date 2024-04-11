#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

int currLabel = 0;
int currFlabel = 0;
int currReg = 0;
int currPBinding = 1;
int currNBinding = -1;
int currAddress = 4096;
int label_stack[50];
int top = -1;
int regUseStack[50];
int regUseStackTop = -1;
int type;
struct Gsymbol *Ghead = NULL, *Gtail = NULL;
struct Lsymbol *Lhead = NULL, *Ltail = NULL;
struct Gsymbol *currGSymbol = NULL;
struct Paramstruct *paramList = NULL;
struct Paramstruct *paramListTail = NULL;
struct tnode *argsHead = NULL, *argsTail = NULL;
FILE *filePointer = NULL;