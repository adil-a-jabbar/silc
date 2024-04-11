#ifndef GLOBALS_H
#define GLOBALS_H

#include "exprtree.h" // Include any other necessary headers here

extern int currLabel;
extern int currFlabel;
extern int currReg;
extern int currPBinding;
extern int currNBinding;
extern int currAddress;
extern int label_stack[50];
extern int top;
extern int regUseStack[50];
extern int regUseStackTop;
extern int type;
extern struct Gsymbol *Ghead, *Gtail;
extern struct Lsymbol *Lhead, *Ltail;
extern struct Gsymbol *currGSymbol;
extern struct Paramstruct *paramList;
extern struct Paramstruct *paramListTail;
extern struct tnode *argsHead, *argsTail;
extern FILE *filePointer;
extern void yyerror(char *msg);

#endif /* GLOBALS_H */
