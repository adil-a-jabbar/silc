#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NUM 257
#define END 258
#define ID 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define SPACE 264
#define NEWLINE 265
#define ASSG 266
#define READ 267
#define WRITE 268
#define START 269
#define COLON 270
#define LT 271
#define LE 272
#define GT 273
#define GE 274
#define EQ 275
#define NE 276
#define IF 277
#define THEN 278
#define ELSE 279
#define ENDIF 280
#define WHILE 281
#define ENDWHILE 282
#define DO 283
#define BREAK 284
#define CONT 285
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
