# Compiler
CC = gcc
# Flags
CFLAGS = -Wall -g

# Targets
all: compiler address_translate

# Compile Lex and Yacc files for the compiler
compiler: lex.yy.c y.tab.c exprtree.c exprtree.h functionChecks.c functionChecks.h symbolTable.c symbolTable.h
	$(CC) $(CFLAGS) lex.yy.c y.tab.c exprtree.c functionChecks.c symbolTable.c -o compiler

# Compile Lex file for address translator
address_translate: address.yy.c
	$(CC) $(CFLAGS) address.yy.c -o address_translate

# Generate Lex file
lex.yy.c: lexfile.l
	lex lexfile.l

# Generate Yacc files
y.tab.c: yaccfile.y
	yacc -d yaccfile.y

# Generate Lex file for address translator
address.yy.c: address_translate.l
	lex address_translate.l

# Clean generated files
clean:
	rm -f lex.yy.c y.tab.c address.yy.c compiler address_translate

