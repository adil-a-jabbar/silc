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
#define OR 279
#define AND 280
#define IF 281
#define THEN 282
#define ELSE 283
#define ENDIF 284
#define WHILE 285
#define ENDWHILE 286
#define DO 287
#define BREAK 288
#define CONT 289
#define DECL 290
#define ENDDECL 291
#define INT 292
#define STR 293
#define COMMA 294
#define MAIN 295
#define RETURN 296
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
