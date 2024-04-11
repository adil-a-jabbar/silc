/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20230521

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yaccfile.y"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"
    #include "symbolTable.h"
    #include "functionChecks.h"
    #include "exprtree.h"

    int yylex(void);
    extern FILE *yyin;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 14 "yaccfile.y"
typedef union YYSTYPE{
    struct tnode* no;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   13,   13,   16,   16,   25,   18,   18,
   19,   19,   19,   14,   14,   21,   17,   17,   28,   28,
   29,   20,   20,   22,   23,   27,   27,   27,   30,   26,
   26,   26,   31,   15,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    7,    7,    8,    4,    5,    5,    6,
    6,    9,   10,   12,   12,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,   24,   24,   11,   11,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    2,    1,    3,    3,    1,
    1,    4,    4,    2,    1,    9,    3,    2,    2,    1,
    3,    3,    1,    4,    3,    3,    1,    0,    2,    3,
    1,    0,    2,    8,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    8,    6,    6,    3,    3,    3,    4,
    4,    2,    2,    3,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    4,    3,    4,    3,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   77,   78,    0,    0,    0,    3,    5,    0,    0,
    7,    0,    0,    0,    2,   15,    0,    0,   10,    4,
    6,    0,    0,    1,   14,    0,    0,    8,    0,    0,
    0,    0,    0,    0,   31,    9,    0,    0,    0,   27,
   12,   33,    0,   13,    0,    0,   29,    0,    0,   30,
   18,    0,    0,   20,    0,    0,   26,    0,   23,    0,
   17,   19,   70,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   36,   37,   38,   39,   40,   41,   42,
   43,   34,    0,   21,    0,    0,    0,    0,   55,    0,
    0,    0,    0,    0,   52,   53,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   35,    0,    0,   22,    0,   73,    0,    0,
   47,    0,   48,   49,    0,    0,   61,    0,    0,   59,
   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   24,   16,   72,    0,   74,   54,    0,
    0,   50,   51,   25,    0,    0,    0,    0,    0,   45,
   46,    0,   44,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  290,  292,  293,  298,  309,  311,  313,  291,  309,  314,
  323,  295,  309,  312,  313,  319,  259,  316,  317,  291,
  323,   40,  259,  313,  319,   91,   40,  272,  294,   41,
   40,  257,  309,  324,  329,  317,  123,  309,  325,  328,
   93,  259,  294,   41,  290,  315,  259,  294,   41,  329,
  291,  309,  326,  327,  271,  320,  328,  123,  259,  318,
  291,  327,  257,  259,  269,  270,  281,  285,  288,  289,
   40,  299,  300,  301,  302,  303,  304,  305,  306,  307,
  308,  125,  315,  272,  294,   91,   40,  299,  260,   40,
  299,  310,  299,  299,  272,  272,  299,  261,  262,  263,
  264,  265,  268,  273,  274,  275,  276,  277,  278,  279,
  280,  296,  301,  321,  320,  259,  299,   41,  299,  322,
  272,  260,  272,  272,  282,  287,   41,  299,  299,  299,
  299,  299,  299,  310,  299,  299,  299,  299,  299,  299,
  299,  299,  299,  258,  125,   93,  294,   41,   41,  300,
  300,  272,  272,  272,  299,  283,  284,  286,  300,  272,
  272,  284,  272,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          4,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
    9,   92,    6,   14,    7,   10,   46,   18,   19,   60,
   16,   56,  114,  120,   11,   34,   39,   53,   54,   40,
   35,
};
static const YYINT yysindex[] = {                      -256,
 -251,    0,    0,    0, -282, -234,    0,    0, -232, -237,
    0,   -7, -247, -234,    0,    0,  -31, -255,    0,    0,
    0,  -12,   -2,    0,    0, -212, -234,    0, -232,  -80,
 -234,  -42, -166,  -39,    0,    0, -229, -159,  -36,    0,
    0,    0, -234,    0, -223, -179,    0, -234,  -21,    0,
    0, -158, -214,    0,  345,  -10,    0, -229,    0, -250,
    0,    0,    0,  -29,  -17,  -32,  -17,  -17, -169, -168,
  -17, -115,  -40,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -179,    0, -145,  -17,  -20,  -69,    0,  -26,
  344, -156, -138, -167,    0,    0,  374,  -17,  -17,  -17,
  -17,  -17,  -32,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
  -17,  -17,    0, -141,   -6,    0,  -92,    0,  471,  -35,
    0,   77,    0,    0,  345,  345,    0, -173, -173,    0,
    0, -173,  427, -151, -198, -198, -198, -198, -198, -198,
 -190, -190,  451,    0,    0,    0,  -17,    0,    0,  261,
  299,    0,    0,    0,  471,  345, -143, -142,  308,    0,
    0, -140,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -244,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -34,    0,    0,    0,
  -22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -11,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -16,    0,
    0,    0,    0,    0,    0,    0,    0,   12,   35,    0,
    0,   58,    0,    0,   81,  104,  127,  150,  177,  205,
  234,  254,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -15,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  575, -110,  -70,    0,    0,    0,    0,    0,    0,    0,
    4,   28,    0,    0,   18,    0,   75,    0,  105,    0,
  129,   69,    0,    0,  144,    0,    0,    0,  102,  108,
  114,
};
#define YYTABLESIZE 751
static const YYINT yytable[] = {                         71,
  146,   44,  113,    5,   49,  148,   32,   90,   27,   13,
   87,   23,   12,   71,  150,  151,   28,   13,   28,   71,
  118,   84,   71,   15,   76,   75,   17,   11,   30,   71,
   33,   24,   22,    1,   38,    2,    3,   31,   29,    8,
    2,    3,   37,   85,   32,  159,   33,   12,   52,   11,
   41,   38,   56,   20,    2,    3,   52,    2,    3,   26,
   45,   86,   98,   99,  100,  101,  102,   51,    2,    3,
   98,   99,  100,  101,  102,   57,   61,    2,    3,  113,
  113,   71,  104,  105,  106,  107,  108,  109,  113,  100,
  101,   55,   42,   98,   99,  100,  101,  102,   60,   47,
   59,   58,   95,   96,   56,  104,  105,  106,  107,  108,
  109,  110,  111,  116,   82,  124,  144,  149,  145,  126,
  153,   62,   98,   99,  100,  101,  102,   57,  160,  161,
  134,  163,   83,   36,  104,  105,  106,  107,  108,  109,
  110,  111,   25,  125,   63,   98,   99,  100,  101,  102,
   60,  115,  103,   21,   62,   57,   50,  104,  105,  106,
  107,  108,  109,  110,  111,    0,    0,   64,   98,   99,
  100,  101,  102,   62,    0,    0,    0,    0,    0,    0,
  104,  105,  106,  107,  108,  109,  110,  111,    0,    0,
   65,   98,   99,  100,  101,  102,   63,    0,    0,    0,
    0,    0,  121,  104,  105,  106,  107,  108,  109,  110,
  111,    0,    0,    0,    0,    0,   63,   66,   64,   64,
    0,    0,    0,    0,   63,    0,   64,   89,   65,   66,
   63,    0,   64,  122,    0,    0,   63,    0,   64,   63,
   67,   64,   65,    0,   68,   67,    0,   69,   70,   71,
   71,   71,   71,   71,   43,  112,   71,   48,  147,   32,
   71,   71,   71,   71,   71,   71,   71,   71,   71,   66,
   71,   28,   56,   56,   68,   71,   56,   76,   75,   56,
    0,    0,   71,   56,   56,   56,   56,   56,   56,   56,
   56,   56,    0,   56,   69,   57,   57,   67,   56,   57,
   71,    0,   57,    0,    0,   56,   57,   57,   57,   57,
   57,   57,   57,   57,   57,    0,   57,    0,   60,   60,
    0,   57,   60,    0,    0,   60,   68,    0,   57,   60,
   60,   60,   60,   60,   60,   60,   60,   60,   71,   60,
    0,    0,    0,    0,   60,    0,   69,   71,   62,    0,
    0,   60,   62,   62,   62,   62,   62,   62,   62,   62,
   62,    0,   62,    0,    0,    0,    0,   62,    0,    0,
    0,   63,    0,    0,   62,   63,   63,   63,   63,   63,
   63,   63,   63,   63,   71,   63,    0,    0,    0,    0,
   63,    0,    0,    0,   64,    0,    0,   63,   64,   64,
   64,   64,   64,   64,   64,   64,   64,    0,   64,    0,
    0,    0,    0,   64,  127,    0,    0,   65,    0,    0,
   64,   65,   65,   65,   65,   65,   65,   65,   65,   65,
    0,   65,    0,    0,    0,    0,   65,    0,    0,    0,
    0,    0,    0,   65,   66,    0,    0,    0,   66,   66,
   66,   66,   66,   66,   66,   66,   66,    0,   66,    0,
    0,    0,    0,   66,    0,    0,    0,    0,    0,    0,
   66,    0,   67,    0,    0,    0,   67,   67,   67,   67,
   67,   67,   67,   67,   67,    0,   67,    0,    0,    0,
    0,   67,    0,    0,    0,    0,    0,    0,   67,    0,
    0,   68,    0,    0,    0,   68,    0,    0,    0,    0,
    0,    0,   68,   68,    0,   68,    0,   63,    0,   64,
   68,   69,    0,    0,    0,   69,    0,   68,    0,   65,
   66,    0,   69,   69,    0,   69,    0,    0,    0,    0,
   69,   67,    0,  156,  157,   68,    0,   69,   69,   70,
    0,    0,    0,    0,    0,   63,    0,   64,    0,    0,
    0,    0,    0,    0,   63,    0,   64,   65,   66,    0,
    0,    0,    0,    0,    0,    0,   65,   66,    0,   67,
    0,    0,    0,   68,  158,    0,   69,   70,   67,    0,
    0,  162,   68,    0,    0,   69,   70,    0,    0,    0,
    0,   63,    0,   64,   98,   99,  100,  101,  102,    0,
    0,    0,    0,   65,   66,  123,  104,  105,  106,  107,
  108,  109,  110,  111,    0,   67,    0,    0,    0,   68,
    0,    0,   69,   70,   98,   99,  100,  101,  102,   88,
   91,   93,   94,    0,    0,   97,  104,  105,  106,  107,
  108,  109,  110,  111,    0,    0,    0,    0,    0,    0,
  117,  119,    0,    0,   97,    0,    0,    0,    0,    0,
    0,    0,  128,  129,  130,  131,  132,  133,  135,  136,
  137,  138,  139,  140,  141,  142,  143,   98,   99,  100,
  101,  102,    0,    0,    0,    0,    0,    0,  152,  104,
  105,  106,  107,  108,  109,  110,  111,    0,    0,    0,
    0,   98,   99,  100,  101,  102,    0,    0,    0,    0,
    0,  155,  154,  104,  105,  106,  107,  108,  109,  110,
  111,   98,   99,  100,  101,  102,    0,    0,    0,    0,
    0,    0,    0,  104,  105,  106,  107,  108,  109,  110,
  111,
};
static const YYINT yycheck[] = {                         40,
   93,   41,   73,    0,   41,   41,   41,   40,   40,    6,
   40,  259,  295,   40,  125,  126,  272,   14,   41,   40,
   41,  272,   40,    6,   41,   41,  259,  272,   41,   41,
   27,   14,   40,  290,   31,  292,  293,   40,  294,  291,
  292,  293,  123,  294,  257,  156,   43,  295,   45,  294,
   93,   48,   41,  291,  292,  293,   53,  292,  293,   91,
  290,   91,  261,  262,  263,  264,  265,  291,  292,  293,
  261,  262,  263,  264,  265,   41,  291,  292,  293,  150,
  151,   93,  273,  274,  275,  276,  277,  278,  159,  263,
  264,  271,  259,  261,  262,  263,  264,  265,   41,  259,
  259,  123,  272,  272,   93,  273,  274,  275,  276,  277,
  278,  279,  280,  259,  125,  272,  258,   41,  125,  287,
  272,   41,  261,  262,  263,  264,  265,   93,  272,  272,
  103,  272,   58,   29,  273,  274,  275,  276,  277,  278,
  279,  280,   14,  282,   41,  261,  262,  263,  264,  265,
   93,   83,  268,   10,   53,   48,   43,  273,  274,  275,
  276,  277,  278,  279,  280,   -1,   -1,   41,  261,  262,
  263,  264,  265,   93,   -1,   -1,   -1,   -1,   -1,   -1,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,   -1,
   41,  261,  262,  263,  264,  265,   93,   -1,   -1,   -1,
   -1,   -1,  272,  273,  274,  275,  276,  277,  278,  279,
  280,   -1,   -1,   -1,   -1,   -1,  257,   41,  259,   93,
   -1,   -1,   -1,   -1,  257,   -1,  259,  260,  269,  270,
  257,   -1,  259,  260,   -1,   -1,  257,   -1,  259,  257,
  281,  259,   93,   -1,  285,   41,   -1,  288,  289,  261,
  262,  263,  264,  265,  294,  296,  268,  294,  294,  294,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   93,
  282,  294,  261,  262,   41,  287,  265,  294,  294,  268,
   -1,   -1,  294,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,  282,   41,  261,  262,   93,  287,  265,
   40,   -1,  268,   -1,   -1,  294,  272,  273,  274,  275,
  276,  277,  278,  279,  280,   -1,  282,   -1,  261,  262,
   -1,  287,  265,   -1,   -1,  268,   93,   -1,  294,  272,
  273,  274,  275,  276,  277,  278,  279,  280,   40,  282,
   -1,   -1,   -1,   -1,  287,   -1,   93,   40,  268,   -1,
   -1,  294,  272,  273,  274,  275,  276,  277,  278,  279,
  280,   -1,  282,   -1,   -1,   -1,   -1,  287,   -1,   -1,
   -1,  268,   -1,   -1,  294,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   40,  282,   -1,   -1,   -1,   -1,
  287,   -1,   -1,   -1,  268,   -1,   -1,  294,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,   -1,
   -1,   -1,   -1,  287,   41,   -1,   -1,  268,   -1,   -1,
  294,  272,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,  282,   -1,   -1,   -1,   -1,  287,   -1,   -1,   -1,
   -1,   -1,   -1,  294,  268,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,   -1,
   -1,   -1,   -1,  287,   -1,   -1,   -1,   -1,   -1,   -1,
  294,   -1,  268,   -1,   -1,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,   -1,  282,   -1,   -1,   -1,
   -1,  287,   -1,   -1,   -1,   -1,   -1,   -1,  294,   -1,
   -1,  268,   -1,   -1,   -1,  272,   -1,   -1,   -1,   -1,
   -1,   -1,  279,  280,   -1,  282,   -1,  257,   -1,  259,
  287,  268,   -1,   -1,   -1,  272,   -1,  294,   -1,  269,
  270,   -1,  279,  280,   -1,  282,   -1,   -1,   -1,   -1,
  287,  281,   -1,  283,  284,  285,   -1,  294,  288,  289,
   -1,   -1,   -1,   -1,   -1,  257,   -1,  259,   -1,   -1,
   -1,   -1,   -1,   -1,  257,   -1,  259,  269,  270,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,   -1,  281,
   -1,   -1,   -1,  285,  286,   -1,  288,  289,  281,   -1,
   -1,  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,
   -1,  257,   -1,  259,  261,  262,  263,  264,  265,   -1,
   -1,   -1,   -1,  269,  270,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,  281,   -1,   -1,   -1,  285,
   -1,   -1,  288,  289,  261,  262,  263,  264,  265,   65,
   66,   67,   68,   -1,   -1,   71,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,
   86,   87,   -1,   -1,   90,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   98,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,  147,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  273,  274,  275,  276,  277,  278,  279,
  280,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#define YYUNDFTOKEN 330
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NUM",
"END","ID","STRING_TYPE","PLUS","MINUS","MUL","DIV","MOD","SPACE","NEWLINE",
"ASSG","READ","WRITE","START","COLON","LT","LE","GT","GE","EQ","NE","OR","AND",
"IF","THEN","ELSE","ENDIF","WHILE","ENDWHILE","DO","BREAK","CONT","DECL",
"ENDDECL","INT","STR","COMMA","MAIN","RETURN","$accept","program","expr",
"Slist","Stmt","InputStmt","OutputStmt","AsgStmt","IfStmt","WhileStmt",
"BreakStmt","ContinueStmt","Type","String","GdeclBlock","FdefBlock","MainBlock",
"GdeclList","LdeclBlock","GidList","Gid","IdList","Fdef","Body","Retstmt",
"ArgList","GDecl","GParamList","ParamList","LDeclList","LDecl","Param","GParam",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : GdeclBlock FdefBlock MainBlock",
"program : GdeclBlock MainBlock",
"program : MainBlock",
"GdeclBlock : DECL GdeclList ENDDECL",
"GdeclBlock : DECL ENDDECL",
"GdeclList : GdeclList GDecl",
"GdeclList : GDecl",
"GDecl : Type GidList COLON",
"GidList : GidList COMMA Gid",
"GidList : Gid",
"Gid : ID",
"Gid : ID '[' NUM ']'",
"Gid : ID '(' GParamList ')'",
"FdefBlock : FdefBlock Fdef",
"FdefBlock : Fdef",
"Fdef : Type ID '(' ParamList ')' '{' LdeclBlock Body '}'",
"LdeclBlock : DECL LDeclList ENDDECL",
"LdeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : Type IdList COLON",
"IdList : IdList COMMA ID",
"IdList : ID",
"Body : START Slist Retstmt END",
"Retstmt : RETURN expr COLON",
"ParamList : ParamList COMMA Param",
"ParamList : Param",
"ParamList :",
"Param : Type ID",
"GParamList : GParamList COMMA GParam",
"GParamList : GParam",
"GParamList :",
"GParam : Type ID",
"MainBlock : Type MAIN '(' ')' '{' LdeclBlock Body '}'",
"Slist : Slist Stmt",
"Slist : Stmt",
"Stmt : InputStmt",
"Stmt : OutputStmt",
"Stmt : AsgStmt",
"Stmt : IfStmt",
"Stmt : WhileStmt",
"Stmt : BreakStmt",
"Stmt : ContinueStmt",
"IfStmt : IF expr THEN Slist ELSE Slist ENDIF COLON",
"IfStmt : IF expr THEN Slist ENDIF COLON",
"WhileStmt : WHILE expr DO Slist ENDWHILE COLON",
"InputStmt : READ expr COLON",
"OutputStmt : WRITE expr COLON",
"OutputStmt : WRITE String COLON",
"AsgStmt : expr ASSG expr COLON",
"AsgStmt : expr ASSG String COLON",
"BreakStmt : BREAK COLON",
"ContinueStmt : CONT COLON",
"String : '(' STRING_TYPE ')'",
"String : STRING_TYPE",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr DIV expr",
"expr : expr MUL expr",
"expr : expr MOD expr",
"expr : '(' expr ')'",
"expr : expr LT expr",
"expr : expr LE expr",
"expr : expr GT expr",
"expr : expr GE expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr OR expr",
"expr : expr AND expr",
"expr : NUM",
"expr : ID",
"expr : ID '[' expr ']'",
"expr : ID '(' ')'",
"expr : ID '(' ArgList ')'",
"ArgList : ArgList COMMA expr",
"ArgList : expr",
"Type : INT",
"Type : STR",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 152 "yaccfile.y"

void yyerror(char * msg){
    printf ("%s\n", msg);
    exit (1);
}

int main (){
    yyin = fopen ("input.txt", "r");
    filePointer = fopen ("executable.xsm", "w");
    headerGen (filePointer);
    fclose (filePointer);
    printf ("tokens:\n-------------\n");
    yyparse();
    filePointer = fopen ("executable.xsm", "a");
    exitGen (filePointer);
    return 0;
}
#line 748 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 28 "yaccfile.y"
	{printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
    printSymbolTable();}
#line 1422 "y.tab.c"
break;
case 2:
#line 30 "yaccfile.y"
	{printf ("\n----------------------------------------------------------------\n                          symbol table:           \n----------------------------------------------------------------\n");
    printSymbolTable();}
#line 1428 "y.tab.c"
break;
case 3:
#line 32 "yaccfile.y"
	{
    /* $$ = $3;*/
    /* FILE* filePointer = fopen ("executable.xsm", "w");*/
    printf ("\n-------------\nsymbol table:\n-------------\n");
    printSymbolTable();
    /* codeGen ($$, filePointer);*/
    /* exitGen (filePointer);*/
    /* fclose (filePointer);*/
    /* exit (1);*/
}
#line 1442 "y.tab.c"
break;
case 4:
#line 43 "yaccfile.y"
	{}
#line 1447 "y.tab.c"
break;
case 5:
#line 44 "yaccfile.y"
	{}
#line 1452 "y.tab.c"
break;
case 6:
#line 46 "yaccfile.y"
	{}
#line 1457 "y.tab.c"
break;
case 7:
#line 47 "yaccfile.y"
	{}
#line 1462 "y.tab.c"
break;
case 8:
#line 49 "yaccfile.y"
	{}
#line 1467 "y.tab.c"
break;
case 9:
#line 51 "yaccfile.y"
	{}
#line 1472 "y.tab.c"
break;
case 10:
#line 52 "yaccfile.y"
	{}
#line 1477 "y.tab.c"
break;
case 11:
#line 54 "yaccfile.y"
	{Ginstall (yystack.l_mark[0].no->varName, type, 1, NULL); yyval.no->type = type; yyval.no=yystack.l_mark[0].no;}
#line 1482 "y.tab.c"
break;
case 12:
#line 55 "yaccfile.y"
	{Ginstall (yystack.l_mark[-3].no->varName, type, yystack.l_mark[-1].no->val, NULL); yyval.no->type = type; yyval.no=yystack.l_mark[-3].no;}
#line 1487 "y.tab.c"
break;
case 13:
#line 56 "yaccfile.y"
	{Ginstall (yystack.l_mark[-3].no->varName, type, -1, paramList); yyval.no->type = type; yyval.no=yystack.l_mark[-3].no; paramList=NULL; paramListTail=NULL;}
#line 1492 "y.tab.c"
break;
case 14:
#line 59 "yaccfile.y"
	{}
#line 1497 "y.tab.c"
break;
case 15:
#line 60 "yaccfile.y"
	{}
#line 1502 "y.tab.c"
break;
case 16:
#line 62 "yaccfile.y"
	{currGSymbol = setGentry(yystack.l_mark[-7].no->varName); if (type != currGSymbol->type) {yyerror ("invalid type for function\n");} yystack.l_mark[-1].no->nodeType = FUN_DEF; checkNameEquivalence (yystack.l_mark[-7].no->varName); filePointer = fopen ("executable.xsm", "a"); codeGen (yystack.l_mark[-1].no, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
#line 1507 "y.tab.c"
break;
case 17:
#line 64 "yaccfile.y"
	{}
#line 1512 "y.tab.c"
break;
case 18:
#line 65 "yaccfile.y"
	{}
#line 1517 "y.tab.c"
break;
case 20:
#line 67 "yaccfile.y"
	{}
#line 1522 "y.tab.c"
break;
case 21:
#line 69 "yaccfile.y"
	{}
#line 1527 "y.tab.c"
break;
case 22:
#line 71 "yaccfile.y"
	{Linstall (yystack.l_mark[0].no->varName, type, currPBinding++);}
#line 1532 "y.tab.c"
break;
case 23:
#line 72 "yaccfile.y"
	{Linstall (yystack.l_mark[0].no->varName, type, currPBinding++);}
#line 1537 "y.tab.c"
break;
case 24:
#line 74 "yaccfile.y"
	{yyval.no = makeConnectorNode (FUN_DEF, yystack.l_mark[-2].no, yystack.l_mark[-1].no);}
#line 1542 "y.tab.c"
break;
case 25:
#line 76 "yaccfile.y"
	{yyval.no = makeStmtNode (RET_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1547 "y.tab.c"
break;
case 26:
#line 78 "yaccfile.y"
	{}
#line 1552 "y.tab.c"
break;
case 27:
#line 79 "yaccfile.y"
	{}
#line 1557 "y.tab.c"
break;
case 28:
#line 80 "yaccfile.y"
	{}
#line 1562 "y.tab.c"
break;
case 29:
#line 82 "yaccfile.y"
	{Linstall (yystack.l_mark[0].no->varName, type, currNBinding--); insertParamList (yystack.l_mark[0].no->varName, type);}
#line 1567 "y.tab.c"
break;
case 30:
#line 84 "yaccfile.y"
	{}
#line 1572 "y.tab.c"
break;
case 31:
#line 85 "yaccfile.y"
	{}
#line 1577 "y.tab.c"
break;
case 32:
#line 86 "yaccfile.y"
	{}
#line 1582 "y.tab.c"
break;
case 33:
#line 88 "yaccfile.y"
	{insertParamList (yystack.l_mark[0].no->varName, type);}
#line 1587 "y.tab.c"
break;
case 34:
#line 90 "yaccfile.y"
	{yystack.l_mark[-1].no->nodeType = MAIN_FUN; filePointer = fopen ("executable.xsm", "a"); codeGen (yystack.l_mark[-1].no, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
#line 1592 "y.tab.c"
break;
case 35:
#line 92 "yaccfile.y"
	{yyval.no=makeConnectorNode (CONNECTOR, yystack.l_mark[-1].no, yystack.l_mark[0].no);}
#line 1597 "y.tab.c"
break;
case 36:
#line 93 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1602 "y.tab.c"
break;
case 37:
#line 95 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1607 "y.tab.c"
break;
case 38:
#line 96 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1612 "y.tab.c"
break;
case 39:
#line 97 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1617 "y.tab.c"
break;
case 40:
#line 98 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1622 "y.tab.c"
break;
case 41:
#line 99 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1627 "y.tab.c"
break;
case 42:
#line 100 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1632 "y.tab.c"
break;
case 43:
#line 101 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1637 "y.tab.c"
break;
case 44:
#line 103 "yaccfile.y"
	{yyval.no=makeStmtNode (IFELSE, yystack.l_mark[-6].no, yystack.l_mark[-2].no, yystack.l_mark[-4].no);}
#line 1642 "y.tab.c"
break;
case 45:
#line 104 "yaccfile.y"
	{yyval.no=makeStmtNode (IFNODE, yystack.l_mark[-4].no, yystack.l_mark[-2].no, NULL);}
#line 1647 "y.tab.c"
break;
case 46:
#line 106 "yaccfile.y"
	{yyval.no=makeStmtNode (WH, yystack.l_mark[-4].no, yystack.l_mark[-2].no, NULL);}
#line 1652 "y.tab.c"
break;
case 47:
#line 108 "yaccfile.y"
	{yyval.no=makeStmtNode (INPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1657 "y.tab.c"
break;
case 48:
#line 110 "yaccfile.y"
	{yyval.no=makeStmtNode (OUTPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1662 "y.tab.c"
break;
case 49:
#line 111 "yaccfile.y"
	{yyval.no=makeStmtNode (OUTPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1667 "y.tab.c"
break;
case 50:
#line 113 "yaccfile.y"
	{yyval.no=makeStmtNode (ASG_STMT, yystack.l_mark[-3].no, yystack.l_mark[-1].no, NULL);}
#line 1672 "y.tab.c"
break;
case 51:
#line 114 "yaccfile.y"
	{yyval.no=makeStmtNode (ASG_STMT, yystack.l_mark[-3].no, yystack.l_mark[-1].no, NULL);}
#line 1677 "y.tab.c"
break;
case 52:
#line 116 "yaccfile.y"
	{yyval.no=makeStmtNode (BRK_STMT, NULL, NULL, NULL);}
#line 1682 "y.tab.c"
break;
case 53:
#line 118 "yaccfile.y"
	{yyval.no=makeStmtNode (CONT_STMT, NULL, NULL, NULL);}
#line 1687 "y.tab.c"
break;
case 54:
#line 120 "yaccfile.y"
	{yyval.no=yystack.l_mark[-1].no; yyval.no->type=strType;}
#line 1692 "y.tab.c"
break;
case 55:
#line 121 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; yyval.no->type=strType;}
#line 1697 "y.tab.c"
break;
case 56:
#line 123 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '+', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1702 "y.tab.c"
break;
case 57:
#line 124 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '-', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1707 "y.tab.c"
break;
case 58:
#line 125 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '/', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1712 "y.tab.c"
break;
case 59:
#line 126 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '*', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1717 "y.tab.c"
break;
case 60:
#line 127 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '%', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1722 "y.tab.c"
break;
case 61:
#line 128 "yaccfile.y"
	{yyval.no=yystack.l_mark[-1].no;  yyval.no->type = yystack.l_mark[-1].no->type;}
#line 1727 "y.tab.c"
break;
case 62:
#line 129 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '<', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1732 "y.tab.c"
break;
case 63:
#line 130 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'l', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1737 "y.tab.c"
break;
case 64:
#line 131 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '>', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1742 "y.tab.c"
break;
case 65:
#line 132 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'g', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1747 "y.tab.c"
break;
case 66:
#line 133 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '=', yystack.l_mark[-2].no, yystack.l_mark[0].no); printf ("expr->expr eq expr\n");}
#line 1752 "y.tab.c"
break;
case 67:
#line 134 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'n', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1757 "y.tab.c"
break;
case 68:
#line 135 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '|', yystack.l_mark[-2].no, yystack.l_mark[0].no); printf ("expr->expr or expr\n");}
#line 1762 "y.tab.c"
break;
case 69:
#line 136 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '&', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1767 "y.tab.c"
break;
case 70:
#line 137 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1772 "y.tab.c"
break;
case 71:
#line 138 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; if (LSymbolLookup (yystack.l_mark[0].no->varName) == NULL) {yystack.l_mark[0].no->Gentry = setGentry (yystack.l_mark[0].no->varName); yystack.l_mark[0].no->type = yystack.l_mark[0].no->Gentry->type;} else {yystack.l_mark[0].no->type = (LSymbolLookup (yystack.l_mark[0].no->varName))->type;}}
#line 1777 "y.tab.c"
break;
case 72:
#line 139 "yaccfile.y"
	{if (yystack.l_mark[-1].no->type != intType) yyerror("\ntype error !\n"); yystack.l_mark[-3].no->Gentry = setGentry (yystack.l_mark[-3].no->varName); yystack.l_mark[-3].no->type = yystack.l_mark[-3].no->Gentry->type; yystack.l_mark[-3].no->left = yystack.l_mark[-1].no; yyval.no=yystack.l_mark[-3].no;}
#line 1782 "y.tab.c"
break;
case 73:
#line 140 "yaccfile.y"
	{yystack.l_mark[-2].no->Gentry = setGentry (yystack.l_mark[-2].no->varName); funArgsCheck(yystack.l_mark[-2].no->Gentry, argsHead); yystack.l_mark[-2].no->type = yystack.l_mark[-2].no->Gentry->type; yystack.l_mark[-2].no->mid = NULL; yyval.no=yystack.l_mark[-2].no; yyval.no->nodeType=FUN_CALL;}
#line 1787 "y.tab.c"
break;
case 74:
#line 141 "yaccfile.y"
	{yystack.l_mark[-3].no->Gentry = setGentry (yystack.l_mark[-3].no->varName); funArgsCheck(yystack.l_mark[-3].no->Gentry, argsHead); yystack.l_mark[-3].no->type = yystack.l_mark[-3].no->Gentry->type; yystack.l_mark[-3].no->mid = argsHead; yyval.no=yystack.l_mark[-3].no; argsHead = NULL; argsTail = NULL; yyval.no->nodeType=FUN_CALL;}
#line 1792 "y.tab.c"
break;
case 75:
#line 143 "yaccfile.y"
	{argsTail->mid=yystack.l_mark[0].no; argsTail=argsTail->mid; argsTail->mid = NULL;}
#line 1797 "y.tab.c"
break;
case 76:
#line 144 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; argsHead = yyval.no; argsTail = yyval.no; argsTail->mid = NULL;}
#line 1802 "y.tab.c"
break;
case 77:
#line 147 "yaccfile.y"
	{type = intType;}
#line 1807 "y.tab.c"
break;
case 78:
#line 148 "yaccfile.y"
	{type = strType;}
#line 1812 "y.tab.c"
break;
#line 1814 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
