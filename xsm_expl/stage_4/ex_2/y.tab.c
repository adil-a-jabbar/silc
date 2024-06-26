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
    int currLabel = 0;
    int currReg = 0;
    int currAddress = 4096;
    int label_stack [50];
    int top = -1;
    int type;
    struct Gsymbol *head=NULL, *tail=NULL;
    FILE * filePointer;
    #include "exprtree.h"
    #include "symbolTable.h"
    #include "exprtree.c"
    #include "symbolTable.c"

    int yylex(void);
    void yyerror();
    extern FILE *yyin;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 23 "yaccfile.y"
typedef union YYSTYPE{
    struct tnode* no;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "y.tab.c"

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    7,    7,    8,    4,    5,    5,    6,    6,    9,   10,
   16,   16,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,   15,   15,
   14,   14,   13,   11,   11,   12,   12,   12,   12,   12,
   12,   12,   12,
};
static const YYINT yylen[] = {                            2,
    5,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    8,    6,    6,    3,    3,    3,    4,    4,    2,    2,
    3,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    1,    1,    4,    7,    3,    2,
    2,    1,    3,    1,    1,    3,    6,    9,    4,    1,
    4,    7,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   40,   44,   45,    0,   42,    0,    0,
    0,    0,    0,   39,   41,   35,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    4,    5,    6,
    7,    8,    9,   10,    0,   53,   43,    0,    0,    0,
   22,    0,    0,    0,    0,    0,   19,   20,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    2,    0,    0,    0,    0,   14,    0,   15,
   16,    0,    0,   28,    0,    0,   26,   25,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
   49,    0,   21,    0,    0,   17,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,   13,   52,
    0,   38,    0,    0,   11,   48,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  288,  294,  309,  289,  290,  291,  305,  307,  308,  271,
  259,  263,  306,  289,  307,  257,  259,  269,  270,  279,
  283,  286,  287,   40,  295,  296,  297,  298,  299,  300,
  301,  302,  303,  304,   91,  259,  272,  292,   91,  295,
  260,   40,  295,  310,  295,  295,  272,  272,  295,  261,
  262,  263,  264,  265,  268,  273,  274,  275,  276,  277,
  278,  258,  297,  257,  259,  263,  295,  272,  260,  272,
  272,  280,  285,   41,  295,  295,  295,  295,  295,  295,
  310,  295,  295,  295,  295,  295,  295,  272,   93,   91,
  259,   93,   41,  296,  296,  272,  272,   91,  257,   91,
  281,  282,  284,  257,   93,  295,  296,  272,  272,   93,
   91,   93,  282,  257,  272,   93,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
    7,   13,    8,    9,    3,   44,
};
static const YYINT yysindex[] = {                      -271,
 -224,    0, -241,    0,    0,    0, -251,    0, -211,   17,
  -56, -220, -266,    0,    0,    0,  -50,  -31,  -39,  -31,
  -31, -228, -204,  -31, -150,  -35,    0,    0,    0,    0,
    0,    0,    0,    0, -188,    0,    0, -230,  -31, -129,
    0,    3, -108, -191, -175, -201,    0,    0,  257,  -31,
  -31,  -31,  -31,  -31,  -39,  -31,  -31,  -31,  -31,  -31,
  -31, -190,    0,   -2,    1, -166,  -83,    0,   53,    0,
    0,   17,   17,    0, -205, -205,    0,    0, -205,  264,
 -176, -240, -240, -240, -240, -240, -240,    0,    6, -153,
    0,   15,    0,  -40,   -4,    0,    0, -149,   14,  -31,
   17, -163, -156,   24,   28,  -65,    2,    0,    0,    0,
 -137,    0, -151,   29,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -265,    0,    0,    0,    0,    0,   44,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -261,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   90,  111,    0,    0,  132,    0,
    0,  147,  161,  175,  197,  217,  232,    0, -254,    0,
    0,   69,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -252,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   -5,  -69,  -24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  120,    0,    0,   75,
};
#define YYTABLESIZE 542
static const YYINT yytable[] = {                         24,
   42,   63,   94,   95,   24,   37,   50,   11,   24,   92,
   46,   12,   40,   43,   45,   46,    1,   51,   49,   47,
   50,   51,   52,   53,   54,   38,   50,  112,   65,   10,
   46,  107,   66,   67,   35,   24,   49,   51,   36,   47,
   39,   24,   24,   47,   75,   76,   77,   78,   79,   80,
   82,   83,   84,   85,   86,   87,   24,   52,   53,   50,
   51,   52,   53,   54,    4,    5,    6,   48,   64,   63,
   63,   56,   57,   58,   59,   60,   61,   14,    5,    6,
   71,   88,   63,   73,   36,   50,   51,   52,   53,   54,
   89,   90,   91,   93,  106,   97,   98,   56,   57,   58,
   59,   60,   61,   99,   72,  100,  105,  104,  108,   37,
   50,   51,   52,   53,   54,  109,  110,   55,  111,  114,
  115,  116,   56,   57,   58,   59,   60,   61,   15,   81,
   23,   50,   51,   52,   53,   54,   36,    0,    0,    0,
    0,    0,   68,   56,   57,   58,   59,   60,   61,    0,
    0,   24,   50,   51,   52,   53,   54,    0,    0,    0,
    0,   37,    0,   70,   56,   57,   58,   59,   60,   61,
    0,    0,   27,    0,    0,    0,    0,   50,   51,   52,
   53,   54,   23,    0,    0,    0,    0,   29,    0,   56,
   57,   58,   59,   60,   61,   50,   51,   52,   53,   54,
    0,   30,    0,   24,    0,    0,    0,   56,   57,   58,
   59,   60,   61,    0,    0,   31,   16,   16,   17,   17,
   41,   16,   62,   17,   27,   16,    0,   17,   18,   19,
    0,    0,    0,   18,   19,    0,    0,   32,   20,   29,
  101,  102,   21,   20,    0,   22,   23,   21,    0,    0,
   22,   23,   16,   30,   17,    0,    0,   33,   16,   16,
   17,   17,   69,    0,   18,   19,    0,   31,    0,    0,
   18,   19,   34,   16,   20,   17,    0,    0,   21,  103,
   20,   22,   23,  113,   21,   18,   19,   22,   23,   32,
    0,    0,    0,    0,    0,   20,    0,   74,    0,   21,
    0,    0,   22,   23,   36,   36,   36,   36,   36,   33,
    0,   36,    0,    0,    0,   36,   36,   36,   36,   36,
   36,   36,    0,   36,   34,    0,    0,    0,   36,   37,
   37,   37,   37,   37,    0,    0,   37,    0,    0,    0,
   37,   37,   37,   37,   37,   37,   37,    0,   37,    0,
   23,   23,    0,   37,   23,    0,    0,   23,    0,    0,
    0,   23,   23,   23,   23,   23,   23,   23,    0,   23,
    0,   24,   24,    0,   23,   24,    0,    0,   24,    0,
    0,    0,   24,   24,   24,   24,   24,   24,   24,    0,
   24,    0,   27,   27,    0,   24,   27,    0,    0,   27,
    0,    0,    0,   27,   27,   27,   27,   27,   27,   27,
    0,   27,    0,    0,   29,    0,   27,    0,   29,   29,
   29,   29,   29,   29,   29,    0,   29,    0,   30,    0,
    0,   29,   30,   30,   30,   30,   30,   30,   30,    0,
   30,    0,   31,    0,    0,   30,   31,   31,   31,   31,
   31,   31,   31,    0,   31,    0,    0,    0,    0,   31,
    0,    0,    0,    0,   32,    0,    0,    0,   32,   32,
   32,   32,   32,   32,   32,    0,   32,    0,    0,    0,
    0,   32,    0,    0,   33,    0,    0,    0,   33,   33,
   33,   33,   33,   33,   33,    0,   33,    0,    0,   34,
    0,   33,    0,   34,   34,   34,   34,   34,   34,   34,
    0,   34,    0,    0,    0,    0,   34,   50,   51,   52,
   53,   54,    0,    0,   50,   51,   52,   53,   54,   56,
   57,   58,   59,   60,   61,   96,   56,   57,   58,   59,
   60,   61,
};
static const YYINT yycheck[] = {                         40,
   40,   26,   72,   73,   40,  272,  272,  259,   40,   93,
  272,  263,   18,   19,   20,   21,  288,  272,   24,  272,
  261,  262,  263,  264,  265,  292,  292,   93,  259,  271,
  292,  101,  263,   39,   91,   40,   42,  292,  259,  292,
   91,   40,   40,  272,   50,   51,   52,   53,   54,   55,
   56,   57,   58,   59,   60,   61,   40,  263,  264,  261,
  262,  263,  264,  265,  289,  290,  291,  272,  257,   94,
   95,  273,  274,  275,  276,  277,  278,  289,  290,  291,
  272,  272,  107,  285,   41,  261,  262,  263,  264,  265,
   93,   91,  259,   41,  100,  272,   91,  273,  274,  275,
  276,  277,  278,  257,  280,   91,   93,  257,  272,   41,
  261,  262,  263,  264,  265,  272,   93,  268,   91,  257,
  272,   93,  273,  274,  275,  276,  277,  278,    9,   55,
   41,  261,  262,  263,  264,  265,   93,   -1,   -1,   -1,
   -1,   -1,  272,  273,  274,  275,  276,  277,  278,   -1,
   -1,   41,  261,  262,  263,  264,  265,   -1,   -1,   -1,
   -1,   93,   -1,  272,  273,  274,  275,  276,  277,  278,
   -1,   -1,   41,   -1,   -1,   -1,   -1,  261,  262,  263,
  264,  265,   93,   -1,   -1,   -1,   -1,   41,   -1,  273,
  274,  275,  276,  277,  278,  261,  262,  263,  264,  265,
   -1,   41,   -1,   93,   -1,   -1,   -1,  273,  274,  275,
  276,  277,  278,   -1,   -1,   41,  257,  257,  259,  259,
  260,  257,  258,  259,   93,  257,   -1,  259,  269,  270,
   -1,   -1,   -1,  269,  270,   -1,   -1,   41,  279,   93,
  281,  282,  283,  279,   -1,  286,  287,  283,   -1,   -1,
  286,  287,  257,   93,  259,   -1,   -1,   41,  257,  257,
  259,  259,  260,   -1,  269,  270,   -1,   93,   -1,   -1,
  269,  270,   41,  257,  279,  259,   -1,   -1,  283,  284,
  279,  286,  287,  282,  283,  269,  270,  286,  287,   93,
   -1,   -1,   -1,   -1,   -1,  279,   -1,   41,   -1,  283,
   -1,   -1,  286,  287,  261,  262,  263,  264,  265,   93,
   -1,  268,   -1,   -1,   -1,  272,  273,  274,  275,  276,
  277,  278,   -1,  280,   93,   -1,   -1,   -1,  285,  261,
  262,  263,  264,  265,   -1,   -1,  268,   -1,   -1,   -1,
  272,  273,  274,  275,  276,  277,  278,   -1,  280,   -1,
  261,  262,   -1,  285,  265,   -1,   -1,  268,   -1,   -1,
   -1,  272,  273,  274,  275,  276,  277,  278,   -1,  280,
   -1,  261,  262,   -1,  285,  265,   -1,   -1,  268,   -1,
   -1,   -1,  272,  273,  274,  275,  276,  277,  278,   -1,
  280,   -1,  261,  262,   -1,  285,  265,   -1,   -1,  268,
   -1,   -1,   -1,  272,  273,  274,  275,  276,  277,  278,
   -1,  280,   -1,   -1,  268,   -1,  285,   -1,  272,  273,
  274,  275,  276,  277,  278,   -1,  280,   -1,  268,   -1,
   -1,  285,  272,  273,  274,  275,  276,  277,  278,   -1,
  280,   -1,  268,   -1,   -1,  285,  272,  273,  274,  275,
  276,  277,  278,   -1,  280,   -1,   -1,   -1,   -1,  285,
   -1,   -1,   -1,   -1,  268,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,   -1,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,  268,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,   -1,  280,   -1,   -1,  268,
   -1,  285,   -1,  272,  273,  274,  275,  276,  277,  278,
   -1,  280,   -1,   -1,   -1,   -1,  285,  261,  262,  263,
  264,  265,   -1,   -1,  261,  262,  263,  264,  265,  273,
  274,  275,  276,  277,  278,  272,  273,  274,  275,  276,
  277,  278,
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
   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NUM","END","ID",
"STRING_TYPE","PLUS","MINUS","MUL","DIV","MOD","SPACE","NEWLINE","ASSG","READ",
"WRITE","START","COLON","LT","LE","GT","GE","EQ","NE","IF","THEN","ELSE",
"ENDIF","WHILE","ENDWHILE","DO","BREAK","CONT","DECL","ENDDECL","INT","STR",
"COMMA","$accept","program","expr","Slist","Stmt","InputStmt","OutputStmt",
"AsgStmt","IfStmt","WhileStmt","BreakStmt","ContinueStmt","Type","VarList",
"Decl","DecList","Declarations","String","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : Declarations START Slist END COLON",
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
"expr : NUM",
"expr : ID",
"expr : ID '[' expr ']'",
"expr : ID '[' expr ']' '[' expr ']'",
"Declarations : DECL DecList ENDDECL",
"Declarations : DECL ENDDECL",
"DecList : DecList Decl",
"DecList : Decl",
"Decl : Type VarList COLON",
"Type : INT",
"Type : STR",
"VarList : VarList COMMA ID",
"VarList : VarList COMMA ID '[' NUM ']'",
"VarList : VarList COMMA ID '[' NUM ']' '[' NUM ']'",
"VarList : VarList COMMA MUL ID",
"VarList : ID",
"VarList : ID '[' NUM ']'",
"VarList : ID '[' NUM ']' '[' NUM ']'",
"VarList : MUL ID",

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
#line 117 "yaccfile.y"

void yyerror(char * msg){
    printf ("%s\n", msg);
    exit (0);
}

int main (void){
    yyin = fopen ("input.txt", "r");
    yyparse();
    return 0;
}
#line 624 "y.tab.c"

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
#line 36 "yaccfile.y"
	{
    yyval.no = yystack.l_mark[-2].no;
    FILE* filePointer = fopen ("executable.xsm", "w");
    printf ("\n-------------\nsymbol table:\n-------------\n");
    printSymbolTable();
    headerGen (filePointer);
    codeGen (yyval.no, filePointer);
    exitGen (filePointer);
    fclose (filePointer);
    exit (1);
}
#line 1307 "y.tab.c"
break;
case 2:
#line 48 "yaccfile.y"
	{yyval.no=makeConnectorNode (CONNECTOR, yystack.l_mark[-1].no, yystack.l_mark[0].no);}
#line 1312 "y.tab.c"
break;
case 3:
#line 49 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1317 "y.tab.c"
break;
case 4:
#line 51 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1322 "y.tab.c"
break;
case 5:
#line 52 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1327 "y.tab.c"
break;
case 6:
#line 53 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1332 "y.tab.c"
break;
case 7:
#line 54 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1337 "y.tab.c"
break;
case 8:
#line 55 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1342 "y.tab.c"
break;
case 9:
#line 56 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1347 "y.tab.c"
break;
case 10:
#line 57 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1352 "y.tab.c"
break;
case 11:
#line 59 "yaccfile.y"
	{yyval.no=makeStmtNode (IFELSE, yystack.l_mark[-6].no, yystack.l_mark[-2].no, yystack.l_mark[-4].no);}
#line 1357 "y.tab.c"
break;
case 12:
#line 60 "yaccfile.y"
	{yyval.no=makeStmtNode (IFNODE, yystack.l_mark[-4].no, yystack.l_mark[-2].no, NULL);}
#line 1362 "y.tab.c"
break;
case 13:
#line 62 "yaccfile.y"
	{yyval.no=makeStmtNode (WH, yystack.l_mark[-4].no, yystack.l_mark[-2].no, NULL);}
#line 1367 "y.tab.c"
break;
case 14:
#line 64 "yaccfile.y"
	{yyval.no=makeStmtNode (INPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1372 "y.tab.c"
break;
case 15:
#line 66 "yaccfile.y"
	{yyval.no=makeStmtNode (OUTPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1377 "y.tab.c"
break;
case 16:
#line 67 "yaccfile.y"
	{yyval.no=makeStmtNode (OUTPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1382 "y.tab.c"
break;
case 17:
#line 69 "yaccfile.y"
	{yyval.no=makeStmtNode (ASG_STMT, yystack.l_mark[-3].no, yystack.l_mark[-1].no, NULL);}
#line 1387 "y.tab.c"
break;
case 18:
#line 70 "yaccfile.y"
	{yyval.no=makeStmtNode (ASG_STMT, yystack.l_mark[-3].no, yystack.l_mark[-1].no, NULL);}
#line 1392 "y.tab.c"
break;
case 19:
#line 72 "yaccfile.y"
	{yyval.no=makeStmtNode (BRK_STMT, NULL, NULL, NULL);}
#line 1397 "y.tab.c"
break;
case 20:
#line 74 "yaccfile.y"
	{yyval.no=makeStmtNode (CONT_STMT, NULL, NULL, NULL);}
#line 1402 "y.tab.c"
break;
case 21:
#line 76 "yaccfile.y"
	{yyval.no=yystack.l_mark[-1].no;}
#line 1407 "y.tab.c"
break;
case 22:
#line 77 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1412 "y.tab.c"
break;
case 23:
#line 79 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '+', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1417 "y.tab.c"
break;
case 24:
#line 80 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '-', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1422 "y.tab.c"
break;
case 25:
#line 81 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '/', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1427 "y.tab.c"
break;
case 26:
#line 82 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '*', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1432 "y.tab.c"
break;
case 27:
#line 83 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '%', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1437 "y.tab.c"
break;
case 28:
#line 84 "yaccfile.y"
	{yyval.no=yystack.l_mark[-1].no;  yyval.no->type = yystack.l_mark[-1].no->type;}
#line 1442 "y.tab.c"
break;
case 29:
#line 85 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '<', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1447 "y.tab.c"
break;
case 30:
#line 86 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'l', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1452 "y.tab.c"
break;
case 31:
#line 87 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '>', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1457 "y.tab.c"
break;
case 32:
#line 88 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'g', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1462 "y.tab.c"
break;
case 33:
#line 89 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '=', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1467 "y.tab.c"
break;
case 34:
#line 90 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'n', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1472 "y.tab.c"
break;
case 35:
#line 91 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1477 "y.tab.c"
break;
case 36:
#line 92 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; yystack.l_mark[0].no->Gentry = setGentry (yystack.l_mark[0].no->varName); yystack.l_mark[0].no->type = yystack.l_mark[0].no->Gentry->type; }
#line 1482 "y.tab.c"
break;
case 37:
#line 93 "yaccfile.y"
	{if (yystack.l_mark[-1].no->type != intType) yyerror("\ntype error !\n"); yystack.l_mark[-3].no->Gentry = setGentry (yystack.l_mark[-3].no->varName); yystack.l_mark[-3].no->type = yystack.l_mark[-3].no->Gentry->type; yystack.l_mark[-3].no->left = yystack.l_mark[-1].no;}
#line 1487 "y.tab.c"
break;
case 38:
#line 94 "yaccfile.y"
	{yyval.no=yystack.l_mark[-6].no; yystack.l_mark[-6].no->Gentry = setGentry (yystack.l_mark[-6].no->varName); yystack.l_mark[-6].no->type = yystack.l_mark[-6].no->Gentry->type;}
#line 1492 "y.tab.c"
break;
case 39:
#line 96 "yaccfile.y"
	{}
#line 1497 "y.tab.c"
break;
case 40:
#line 97 "yaccfile.y"
	{}
#line 1502 "y.tab.c"
break;
case 41:
#line 99 "yaccfile.y"
	{}
#line 1507 "y.tab.c"
break;
case 42:
#line 100 "yaccfile.y"
	{}
#line 1512 "y.tab.c"
break;
case 43:
#line 102 "yaccfile.y"
	{}
#line 1517 "y.tab.c"
break;
case 44:
#line 104 "yaccfile.y"
	{type = intType;}
#line 1522 "y.tab.c"
break;
case 45:
#line 105 "yaccfile.y"
	{type = strType;}
#line 1527 "y.tab.c"
break;
case 46:
#line 107 "yaccfile.y"
	{install (yystack.l_mark[0].no->varName, type, 1, 1); yyval.no->type = type;}
#line 1532 "y.tab.c"
break;
case 47:
#line 108 "yaccfile.y"
	{install (yystack.l_mark[-3].no->varName, type, 1, yystack.l_mark[-1].no->val); yyval.no->type = type;}
#line 1537 "y.tab.c"
break;
case 48:
#line 109 "yaccfile.y"
	{install (yystack.l_mark[-6].no->varName, type, yystack.l_mark[-4].no->val, yystack.l_mark[-1].no->val); yyval.no->type = type;}
#line 1542 "y.tab.c"
break;
case 49:
#line 110 "yaccfile.y"
	{printf ("varlist->pointer\n"); install (yystack.l_mark[0].no->varName, (type==intType?intPointer:strPointer), 1, 1); yyval.no->type = (type==intType?intPointer:strPointer);}
#line 1547 "y.tab.c"
break;
case 50:
#line 111 "yaccfile.y"
	{install (yystack.l_mark[0].no->varName, type, 1, 1); yyval.no->type = type;}
#line 1552 "y.tab.c"
break;
case 51:
#line 112 "yaccfile.y"
	{install (yystack.l_mark[-3].no->varName, type, 1, yystack.l_mark[-1].no->val); yyval.no->type = type;}
#line 1557 "y.tab.c"
break;
case 52:
#line 113 "yaccfile.y"
	{install (yystack.l_mark[-6].no->varName, type, yystack.l_mark[-4].no->val, yystack.l_mark[-1].no->val); yyval.no->type = type;}
#line 1562 "y.tab.c"
break;
case 53:
#line 114 "yaccfile.y"
	{printf ("varlist->pointer\n"); install (yystack.l_mark[0].no->varName, (type==intType?intPointer:strPointer), 1, 1); yyval.no->type = (type==intType?intPointer:strPointer);}
#line 1567 "y.tab.c"
break;
#line 1569 "y.tab.c"
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
