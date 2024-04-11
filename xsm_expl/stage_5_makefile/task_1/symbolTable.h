#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

typedef struct Gsymbol {
    char *name;
    int type;
    int size;
    int binding;
    struct Paramstruct *paramlist;
    int flabel;
    struct Gsymbol *next;
} Gsymbol;

typedef struct Paramstruct {
    char *paramName;
    int type;
    struct Paramstruct *next;
} Paramstruct;

typedef struct Lsymbol {
    char *name;
    int type;
    int binding;
    struct Lsymbol *next;
} Lsymbol;

struct Gsymbol *GSymbolLookup(char *name);
struct Lsymbol *LSymbolLookup(char *name);
struct Gsymbol *install(char *name, int type, int size);
void printSymbolTable();
int getAddress(int size);
char *typeToString(int type);
struct Gsymbol *setGentry(char *varName);
struct Gsymbol *Ginstall(char *name, int type, int size, struct Paramstruct *paramlist);
struct Lsymbol *Linstall(char *name, int type, int binding);
void checkNameEquivalence(char *name);
void insertParamList(char *varName, int type);

#endif /* SYMBOLTABLE_H */
