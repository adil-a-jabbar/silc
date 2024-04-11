#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

struct Typetable {
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};

struct Fieldlist {
    char *name;              //name of the field
    int fieldIndex;          //the position of the field in the field list
    struct Typetable *type;  //pointer to type table entry of the field's type
    struct Fieldlist *next;  //pointer to the next field
};

void TypeTableCreate();
struct Typetable * Tinstall (char * name, struct tnode * fields, int size);
struct Fieldlist * Finstall (struct Typetable * type, struct tnode * t);
struct Typetable * TLookup (char * name);
struct Fieldlist* FLookup(struct Typetable *type, char *name);
void printTypeTable () ;
void printFieldList (struct Fieldlist * fields);
void duplFieldCheck (struct tnode * t, char *name, int *count);
void doesTypeExist (char typeName[20]);

#endif /* TYPE_TABLE_H */
