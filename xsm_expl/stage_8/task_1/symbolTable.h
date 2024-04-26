#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

typedef struct Gsymbol {
    char *name;
    struct Typetable * type;
    struct Classtable * Ctype;
    int size;
    int binding;
    struct Paramstruct *paramlist;
    int flabel;
    struct Gsymbol *next;
} Gsymbol;

typedef struct Paramstruct {
    char *paramName;
    struct Typetable * type;
    struct Classtable * Ctype;
    struct Paramstruct *next;
} Paramstruct;

typedef struct Lsymbol {
    char *name;
    struct Typetable * type;
    struct Classtable * Ctype;
    int binding;
    struct Lsymbol *next;
} Lsymbol;

struct Gsymbol *GSymbolLookup(char *name);
struct Lsymbol *LSymbolLookup(char *name);
struct Gsymbol *install(char *name, struct Typetable * type, int size);
void printSymbolTable();
int getAddress(int size);
char *typeToString(struct Typetable * type);
struct Gsymbol *setGentry(char *varName);
struct Gsymbol *Ginstall(char *name, struct Typetable * type, struct Classtable * Ctype, int size, struct Paramstruct *paramlist);
struct Lsymbol *Linstall(char *name, char * typename, int binding);
void checkNameEquivalence(char *name);
void insertParamList(char *varName, struct Typetable * type);

#endif /* SYMBOLTABLE_H */
