#ifndef GLOBALS_H
#define GLOBALS_H

#include "exprtree.h" // Include any other necessary headers here
#define ANSI_COLOR_RED     "\x1b[91m"
#define ANSI_COLOR_RESET      "\x1b[0m"
#define HB_SIZE 8

extern int currLabel;
extern int currFlabel;
extern int currReg;
extern int currPBinding;
extern int currNBinding;
extern int currAddress;
extern int currTypeSize;
extern int currFieldIndex;
extern int label_stack[50];
extern int top;
extern int regUseStack[50];
extern int regUseStackTop;
extern char type[20];
extern char Gtype[20];
extern struct Gsymbol *Ghead, *Gtail;
extern struct Lsymbol *Lhead, *Ltail;
extern struct Typetable *Thead, *Ttail;
extern struct Typetable *intType, *strType, *boolType, *nullType;
extern struct Fieldlist *Flisthead, *Flisttail;
extern struct Gsymbol *currGSymbol;
extern struct Paramstruct *paramList;
extern struct Paramstruct *paramListTail;
extern struct tnode *argsHead, *argsTail;
extern FILE *filePointer;
extern void yyerror(char *msg);

#endif /* GLOBALS_H */
