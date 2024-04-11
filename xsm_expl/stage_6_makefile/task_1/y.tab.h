#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NUM 257
#define END 258
#define ID 259
#define STRING_TYPE 260
#define INT 261
#define STR 262
#define ALLOC 263
#define INITIALIZE 264
#define FREE 265
#define NULLVAL 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define MOD 271
#define SPACE 272
#define NEWLINE 273
#define ASSG 274
#define READ 275
#define WRITE 276
#define START 277
#define COLON 278
#define LT 279
#define LE 280
#define GT 281
#define GE 282
#define EQ 283
#define NE 284
#define OR 285
#define AND 286
#define IF 287
#define THEN 288
#define ELSE 289
#define ENDIF 290
#define WHILE 291
#define ENDWHILE 292
#define DO 293
#define BREAK 294
#define CONT 295
#define DECL 296
#define ENDDECL 297
#define COMMA 298
#define MAIN 299
#define RETURN 300
#define TYPE 301
#define ENDTYPE 302
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
