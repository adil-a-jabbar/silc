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
#define SELF 267
#define NEW 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define MOD 273
#define SPACE 274
#define NEWLINE 275
#define ASSG 276
#define READ 277
#define WRITE 278
#define START 279
#define COLON 280
#define LT 281
#define LE 282
#define GT 283
#define GE 284
#define EQ 285
#define NE 286
#define OR 287
#define AND 288
#define IF 289
#define THEN 290
#define ELSE 291
#define ENDIF 292
#define WHILE 293
#define ENDWHILE 294
#define DO 295
#define BREAK 296
#define CONT 297
#define DECL 298
#define ENDDECL 299
#define COMMA 300
#define MAIN 301
#define RETURN 302
#define TYPE 303
#define ENDTYPE 304
#define DELETE 305
#define CLASS 306
#define ENDCLASS 307
#define EXTENDS 308
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
