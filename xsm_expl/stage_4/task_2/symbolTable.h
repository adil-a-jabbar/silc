typedef struct Gsymbol{
    char *name;
    int type;
    int size;
    int binding;
    struct Gsymbol * next;
}Gsymbol;

struct Gsymbol * symbolLookup (char *name);
struct Gsymbol * install (char * name, int type, int size);
void printSymbolTable();
int getAddress (int size);
char * typeToString (int type);

