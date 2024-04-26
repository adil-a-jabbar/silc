#include "globals.h"
#include "exprtree.h"

struct Classtable
{
    char *name;                      // name of the class
    struct CFieldlist *Memberfield;  // pointer to Fieldlist
    struct Memberfunclist *Vfuncptr; // pointer to Memberfunclist
    struct Classtable *Parentptr;    // pointer to the parent's class table
    int Class_index;                 // position of the class in the virtual function table
    int Fieldcount;                  // count of fields
    int Methodcount;                 // count of methods
    struct Classtable *Next;         // pointer to next class table entry
};

struct CFieldlist
{
    char *name;               // name of the field
    int Fieldindex;           // position of the field
    struct Typetable *type;   // pointer to typetable
    struct Classtable *Ctype; // pointer to the class containing the field
    struct Fieldlist *Next;   // pointer to next fieldlist entry
};

struct Memberfunclist
{
    char *name;                    // name of the member function in the class
    struct Typetable *type;        // pointer to typetable
    struct Paramstruct *paramlist; // pointer to the head of the formal parameter list
    int Funcposition;              // position of the function in the class table
    int Flabel;                    // A label for identifying the starting address of the function's code in the memory
    struct Memberfunclist *Next;   // pointer to next Memberfunclist entry
};

struct Classtable * CInstall (char *name, char *pname);