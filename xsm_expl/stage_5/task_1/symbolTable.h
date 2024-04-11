typedef struct Gsymbol{
    char *name;
    int type;
    int size;
    int binding;
    struct Paramstruct *paramlist;
    int flabel;
    struct Gsymbol * next;
}Gsymbol;

typedef struct Paramstruct{
    char * paramName;
    int type;
    struct Paramstruct * next;
}Paramstruct;

typedef struct Lsymbol {
    char * name;
    int type;
    int binding;
    struct Lsymbol * next;
}Lsymbol;

struct Gsymbol * GSymbolLookup (char *name);
struct Lsymbol * LSymbolLookup (char *name);
struct Gsymbol * install (char * name, int type, int size);
void printSymbolTable();
int getAddress (int size);
char * typeToString (int type);

