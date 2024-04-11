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
#define SPACE 265
#define NEWLINE 266
#define ASSG 267
#define READ 268
#define WRITE 269
#define START 270
#define COLON 271
#define LT 272
#define LE 273
#define GT 274
#define GE 275
#define EQ 276
#define NE 277
#define IF 278
#define THEN 279
#define ELSE 280
#define ENDIF 281
#define WHILE 282
#define ENDWHILE 283
#define DO 284
#define BREAK 285
#define CONT 286
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290
#define COMMA 291
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
