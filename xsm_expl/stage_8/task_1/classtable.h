#ifndef CLASSTABLE_H
#define CLASSTABLE_H

typedef struct Classtable
{
    char *name;                      // name of the class
    struct CFieldlist *Memberfield;  // pointer to Fieldlist
    struct Memberfunclist *Vfuncptr; // pointer to Memberfunclist
    struct Classtable *Parentptr;    // pointer to the parent's class table
    int Class_index;                 // position of the class in the virtual function table
    int Fieldcount;                  // count of fields
    int Methodcount;                 // count of methods
    struct Classtable *next;         // pointer to next class table entry
} Classtable;

typedef struct CFieldlist
{
    char *name;               // name of the field
    int Fieldindex;           // position of the field
    struct Typetable *type;   // pointer to typetable
    struct Classtable *Ctype; // pointer to the class containing the field
    struct CFieldlist *next;   // pointer to next fieldlist entry
} CFieldlist;

typedef struct Memberfunclist
{
    char *name;                    // name of the member function in the class
    struct Typetable *type;        // pointer to typetable
    struct Classtable *Ctype;      // pointer to classtable
    struct Paramstruct *paramlist; // pointer to the head of the formal parameter list
    int Funcposition;              // position of the function in the class table
    int Flabel;                    // A label for identifying the starting address of the function's code in the memory
    struct Memberfunclist *next;   // pointer to next Memberfunclist entry
} Memberfunclist;

struct Classtable * CInstall (char *name, char *pname);
struct Classtable * CLookup (char *name);
void CFieldInstall (struct Classtable * cptr, char * typename, char *name);
void CMethodInstall (struct Classtable * cptr, char * typename, char *name);
void CParamInstall (char * typename, char *name);
void printClassTable();
void printMemberFields (struct Classtable * cptr);
void printMethods (struct Classtable * cptr);
struct CFieldlist * Class_FLookup (struct Classtable * cptr, char * name);
struct Memberfunclist * Class_MLookup (struct Classtable * cptr, char * name);
void classInherit (struct Classtable * child, struct Classtable * parent);
void CMethodCopy (struct Classtable * cptr, struct Memberfunclist * method);

#endif /* CLASSTABLE_H */
