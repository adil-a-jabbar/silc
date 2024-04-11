#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NUM 257
#define END 258
#define ID 259
#define STRING_TYPE 260
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define MOD 265
#define SPACE 266
#define NEWLINE 267
#define ASSG 268
#define READ 269
#define WRITE 270
#define START 271
#define COLON 272
#define LT 273
#define LE 274
#define GT 275
#define GE 276
#define EQ 277
#define NE 278
#define IF 279
#define THEN 280
#define ELSE 281
#define ENDIF 282
#define WHILE 283
#define ENDWHILE 284
#define DO 285
#define BREAK 286
#define CONT 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define COMMA 292
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
    struct tnode* no;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
