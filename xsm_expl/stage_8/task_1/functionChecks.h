#ifndef FUNCTIONCHECKS_H
#define FUNCTIONCHECKS_H

void yyerror();
void funArgsCheck(struct Gsymbol * Gentry, struct tnode * argsHead);
void methodArgsCheck(struct Memberfunclist * method, struct tnode *argsHead);

#endif /* FUNCTIONCHECKS_H */
