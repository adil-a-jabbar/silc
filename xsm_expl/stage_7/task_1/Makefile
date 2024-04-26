CC = gcc
CFLAGS = -g -Wall -Wno-unused-function

all: compiler address_translate

compiler: lex.yy.c y.tab.c exprtree.c functionChecks.c symbolTable.c globals.c typetable.c
	$(CC) $(CFLAGS) lex.yy.c y.tab.c exprtree.c functionChecks.c symbolTable.c globals.c typetable.c -o compiler -ll

address_translate: address_translate.c label_address.c
	$(CC) $(CFLAGS) address_translate.c label_address.c -o address_translate

lex.yy.c: lexfile.l
	lex lexfile.l

y.tab.c: yaccfile.y
	yacc -d yaccfile.y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h compiler address_translate
