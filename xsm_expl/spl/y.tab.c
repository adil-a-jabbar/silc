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

#line 2 "splparser.y"
#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "spl.h"
#include "file.h"
#include "node.h"


int label_add();
int yyerror();
int yylex();
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 14 "splparser.y"
typedef union YYSTYPE
{
    struct tree *n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 48 "y.tab.c"

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

#define ALIAS 257
#define DEFINE 258
#define DO 259
#define ELSE 260
#define ENDIF 261
#define ENDWHILE 262
#define IF 263
#define RETURN 264
#define IRETURN 265
#define LOAD 266
#define STORE 267
#define THEN 268
#define WHILE 269
#define HALT 270
#define REG 271
#define NUM 272
#define ASSIGNOP 273
#define ARITHOP1 274
#define ARITHOP2 275
#define RELOP 276
#define LOGOP 277
#define NOTOP 278
#define ID 279
#define BREAK 280
#define CONTINUE 281
#define CHKPT 282
#define READ 283
#define READI 284
#define PRINT 285
#define STRING 286
#define INLINE 287
#define BACKUP 288
#define RESTORE 289
#define LOADI 290
#define GOTO 291
#define CALL 292
#define ENCRYPT 293
#define PORT 294
#define UMIN 295
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    7,    8,    8,    9,    9,    1,    1,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    5,   10,    6,    4,    4,
};
static const YYINT yylen[] = {                            2,
    2,    1,    2,    0,    4,    5,    2,    1,    4,    4,
    6,    8,    6,    4,    7,    7,    7,    2,    2,    2,
    2,    2,    3,    2,    2,    3,    3,    2,    2,    3,
    3,    3,    2,    3,    3,    3,    3,    2,    2,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         4,
    0,    0,    0,    0,   45,    0,    0,    0,    0,   47,
    0,   49,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   44,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    8,    0,   43,    0,    0,    0,    3,
    0,   18,   19,    0,    0,   22,   38,   48,   39,   33,
   20,   21,   24,   25,    0,    0,    0,   28,   29,    0,
    0,    0,    0,    0,    0,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   26,   27,   23,
    0,   31,   32,   30,   41,   40,    0,    0,    0,   35,
    0,    0,    0,    0,    0,    0,   14,    0,    0,    0,
   10,    9,    0,    0,    5,    0,    0,    0,    0,   46,
    0,    0,    0,    6,    0,    0,    0,   11,    0,   13,
   15,   16,   17,    0,   12,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  297,  304,  305,  257,  263,  264,  265,  266,  267,  269,
  270,  271,  272,  274,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  293,
   40,   91,  298,  299,  300,  301,  302,  303,  258,  306,
  279,   59,   59,   40,   40,   59,  272,  279,  300,   58,
   59,   59,   59,   59,  301,  300,  286,   59,   59,   40,
  279,  279,  301,  300,  300,  299,  273,  274,  275,  276,
  277,  300,  300,  279,  271,  300,  300,   59,   59,   59,
  300,   59,   59,   59,   41,   93,  294,  300,  300,  300,
  300,  300,  268,  259,  272,  274,   59,   44,   44,   44,
   59,   59,  298,  298,   59,  272,  300,  300,  300,  260,
  261,  307,  262,   59,   41,   41,   41,   59,  298,   59,
   59,   59,   59,  261,   59,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
   33,   34,   35,   36,   37,   38,    2,    3,   40,  112,
};
static const YYINT yysindex[] = {                         0,
    0,  103, -248, -266,    0,  -39,  -35,  -10,   -7,    0,
  -19,    0,    0, -211,  169,    4,   11,   14,   15,   16,
 -265,  169,    0, -223,   17,   18,   38, -200, -199, -265,
  169,  169,  103,    0, -230,    0,  169,  169, -198,    0,
 -189,    0,    0,  169,  169,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   25,  -56,   26,    0,    0,  169,
   27,   30,   31,   87,  -91,    0,  -40,  169,  169,  169,
  169, -259, -238, -247,   32,  183,  192,    0,    0,    0,
  198,    0,    0,    0,    0,    0,   33,  -52, -187,    0,
 -216, -226,  103,  103,   34, -178,    0,  169,  169,  169,
    0,    0,   -8,   29,    0,   39,  127,  162,  176,    0,
   40,  103,   41,    0,   42,   43,   44,    0,   66,    0,
    0,    0,    0,   45,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  142,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -221,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  105,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -33,    0,
  246,  356,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  -89,  -32,   -3,    1,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 633
static const YYINT yytable[] = {                         31,
   66,   86,   79,  103,  104,   12,  102,   34,   93,   39,
   34,   49,   41,   48,   68,   69,   70,   71,   56,   42,
   94,   55,  119,   43,   95,   34,   96,   64,   65,   44,
   63,   31,   45,   72,   73,   68,   69,   70,   71,   46,
   76,   77,   67,   68,   69,   70,   71,   68,   69,   70,
   32,   48,   48,   48,   48,   48,   81,   68,   69,   34,
   47,   50,   57,   88,   89,   90,   91,   92,   31,   51,
   66,   66,   52,   53,   54,   58,   59,   60,   61,   62,
   74,   75,   32,   78,   80,   82,   66,   69,   83,   84,
   97,  101,  105,  106,  107,  108,  109,  114,  118,  120,
  121,  122,  123,  125,    1,   31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   32,
    0,    0,    0,    0,    0,    0,    0,   85,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  115,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,   68,   69,   70,   71,    0,    0,    0,    0,
    0,    0,    0,   32,    0,    0,    0,    0,    0,    0,
    0,    0,  116,    0,    0,    0,    0,    0,   31,    0,
    0,    0,    0,    0,    0,    0,  117,   68,   69,   70,
   71,   68,   69,   70,   71,   34,   98,    0,    0,    0,
   12,   13,    2,   14,   34,   99,    0,   15,   48,   34,
   34,  100,   34,   34,    0,   23,    0,    0,    4,    0,
    0,  110,  111,   87,    5,    6,    7,    8,    9,   32,
   10,   11,   12,   13,    0,   14,    0,    0,    0,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,    4,   36,    0,    0,   36,
  113,    5,    6,    7,    8,    9,    0,   10,   11,   12,
   13,    0,   14,    0,   36,    0,   15,   16,   17,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
   29,   30,    4,    0,    0,    0,  124,    0,    5,    6,
    7,    8,    9,    0,   10,   11,   12,   13,   36,   14,
    0,    0,    0,   15,   16,   17,   18,   19,   20,   21,
   22,   23,   24,   25,   26,   27,   28,   29,   30,    4,
   68,   69,   70,   71,    0,    5,    6,    7,    8,    9,
    0,   10,   11,   12,   13,    0,   14,    0,    0,    0,
   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
   25,   26,   27,   28,   29,   30,   37,    0,    2,   37,
   68,   69,   70,   71,    2,    2,    2,    2,    2,    0,
    2,    2,    2,    2,   37,    2,    0,    0,    0,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,   68,   69,   70,   71,   12,
   13,    0,   14,    0,    0,    0,   15,   48,   37,   68,
   69,   70,   71,    0,   23,    0,   68,   69,   70,   71,
    0,    0,    0,    0,    0,   68,   69,   70,   71,    0,
    0,   68,   69,   70,   71,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,   36,    0,    0,    0,    0,   36,    0,
    0,   36,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   37,    0,    0,    0,    0,    0,
    0,    0,    0,   37,    0,    0,    0,    0,   37,    0,
    0,    0,   37,
};
static const YYINT yycheck[] = {                         40,
   33,   93,   59,   93,   94,  271,   59,   41,  268,  258,
   44,   15,  279,  279,  274,  275,  276,  277,   22,   59,
  259,   21,  112,   59,  272,   59,  274,   31,   32,   40,
   30,   40,   40,   37,   38,  274,  275,  276,  277,   59,
   44,   45,  273,  274,  275,  276,  277,  274,  275,  276,
   91,  273,  274,  275,  276,  277,   60,  274,  275,   93,
  272,   58,  286,   67,   68,   69,   70,   71,   40,   59,
  103,  104,   59,   59,   59,   59,   59,   40,  279,  279,
  279,  271,   91,   59,   59,   59,  119,  275,   59,   59,
   59,   59,   59,  272,   98,   99,  100,   59,   59,   59,
   59,   59,   59,   59,    0,   40,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   91,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,  274,  275,  276,  277,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   91,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   41,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   41,  274,  275,  276,
  277,  274,  275,  276,  277,  259,   44,   -1,   -1,   -1,
  271,  272,   91,  274,  268,   44,   -1,  278,  279,  273,
  274,   44,  276,  277,   -1,  286,   -1,   -1,  257,   -1,
   -1,  260,  261,  294,  263,  264,  265,  266,  267,   91,
  269,  270,  271,  272,   -1,  274,   -1,   -1,   -1,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  257,   41,   -1,   -1,   44,
  262,  263,  264,  265,  266,  267,   -1,  269,  270,  271,
  272,   -1,  274,   -1,   59,   -1,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,  293,  257,   -1,   -1,   -1,  261,   -1,  263,  264,
  265,  266,  267,   -1,  269,  270,  271,  272,   93,  274,
   -1,   -1,   -1,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  257,
  274,  275,  276,  277,   -1,  263,  264,  265,  266,  267,
   -1,  269,  270,  271,  272,   -1,  274,   -1,   -1,   -1,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  293,   41,   -1,  257,   44,
  274,  275,  276,  277,  263,  264,  265,  266,  267,   -1,
  269,  270,  271,  272,   59,  274,   -1,   -1,   -1,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  274,  275,  276,  277,  271,
  272,   -1,  274,   -1,   -1,   -1,  278,  279,   93,  274,
  275,  276,  277,   -1,  286,   -1,  274,  275,  276,  277,
   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,   -1,
   -1,  274,  275,  276,  277,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  259,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,   -1,   -1,   -1,  273,   -1,
   -1,  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  259,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,   -1,   -1,   -1,  273,   -1,
   -1,   -1,  277,
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
   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 295
#define YYUNDFTOKEN 308
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error",
"ALIAS","DEFINE","DO","ELSE","ENDIF","ENDWHILE","IF","RETURN","IRETURN","LOAD",
"STORE","THEN","WHILE","HALT","REG","NUM","ASSIGNOP","ARITHOP1","ARITHOP2",
"RELOP","LOGOP","NOTOP","ID","BREAK","CONTINUE","CHKPT","READ","READI","PRINT",
"STRING","INLINE","BACKUP","RESTORE","LOADI","GOTO","CALL","ENCRYPT","PORT",
"UMIN","$accept","body","stmtlist","stmt","expr","ids","ifpad","whilepad",
"definelistpad","definelist","definestmt","elsepad","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : body",
"body : definelistpad stmtlist",
"definelistpad : definelist",
"definelist : definelist definestmt",
"definelist :",
"definestmt : DEFINE ID NUM ';'",
"definestmt : DEFINE ID ARITHOP1 NUM ';'",
"stmtlist : stmtlist stmt",
"stmtlist : stmt",
"stmt : expr ASSIGNOP expr ';'",
"stmt : expr ASSIGNOP PORT ';'",
"stmt : ifpad expr THEN stmtlist ENDIF ';'",
"stmt : ifpad expr THEN stmtlist elsepad stmtlist ENDIF ';'",
"stmt : whilepad expr DO stmtlist ENDWHILE ';'",
"stmt : ALIAS ID REG ';'",
"stmt : LOAD '(' expr ',' expr ')' ';'",
"stmt : STORE '(' expr ',' expr ')' ';'",
"stmt : LOADI '(' expr ',' expr ')' ';'",
"stmt : RETURN ';'",
"stmt : IRETURN ';'",
"stmt : BREAK ';'",
"stmt : CONTINUE ';'",
"stmt : HALT ';'",
"stmt : INLINE STRING ';'",
"stmt : CHKPT ';'",
"stmt : READ ';'",
"stmt : READI ids ';'",
"stmt : PRINT expr ';'",
"stmt : BACKUP ';'",
"stmt : RESTORE ';'",
"stmt : ENCRYPT ids ';'",
"stmt : GOTO ID ';'",
"stmt : CALL ID ';'",
"stmt : ID ':'",
"expr : expr ARITHOP1 expr",
"expr : expr ARITHOP2 expr",
"expr : expr RELOP expr",
"expr : expr LOGOP expr",
"expr : ARITHOP1 NUM",
"expr : NOTOP expr",
"expr : '[' expr ']'",
"expr : '(' expr ')'",
"expr : NUM",
"expr : ids",
"expr : STRING",
"ifpad : IF",
"elsepad : ELSE",
"whilepad : WHILE",
"ids : ID",
"ids : REG",

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
#line 270 "splparser.y"

int yyerror (char *msg) 
{
    return fprintf (stderr, "%d: %s\n",linecount,msg);
}
#line 638 "y.tab.c"

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
#line 28 "splparser.y"
	{
                                    codegen(yystack.l_mark[0].n);
                                    out_linecount++;
                                    fprintf(fp,"HALT");
                                }
#line 1315 "y.tab.c"
break;
case 2:
#line 35 "splparser.y"
	{
                                    add_predefined_constants();
                                }
#line 1322 "y.tab.c"
break;
case 5:
#line 44 "splparser.y"
	{
                                                    insert_constant(yystack.l_mark[-2].n->name,yystack.l_mark[-1].n->value);
                                                }
#line 1329 "y.tab.c"
break;
case 6:
#line 47 "splparser.y"
	{
                                                    if(node_getType(yystack.l_mark[-2].n)==NODE_SUB)
                                                        insert_constant(yystack.l_mark[-3].n->name,-1*yystack.l_mark[-1].n->value);
                                                    else
                                                        insert_constant(yystack.l_mark[-3].n->name,yystack.l_mark[-1].n->value);
                                                }
#line 1339 "y.tab.c"
break;
case 7:
#line 55 "splparser.y"
	{
                                                    yyval.n=create_nontermNode(NODE_STMTLIST,yystack.l_mark[-1].n,yystack.l_mark[0].n);
                                                }
#line 1346 "y.tab.c"
break;
case 8:
#line 58 "splparser.y"
	{
                                                    yyval.n=yystack.l_mark[0].n;
                                                }
#line 1353 "y.tab.c"
break;
case 9:
#line 63 "splparser.y"
	{
                                                    if(node_getType(yystack.l_mark[-3].n)==NODE_REG || node_getType(yystack.l_mark[-3].n)==NODE_ADDR_EXPR)
                                                    {
                                                        yystack.l_mark[-2].n->value=2;
                                                        yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-3].n,yystack.l_mark[-1].n,NULL);
                                                    }
                                                    else
                                                    {
                                                        printf("\n%d:Invalid operands in assignment!!\n",linecount);
                                                        exit(0);
                                                    }
                                                }
#line 1369 "y.tab.c"
break;
case 10:
#line 75 "splparser.y"
	{
                                                    if(node_getType(yystack.l_mark[-3].n)==NODE_REG || node_getType(yystack.l_mark[-3].n)==NODE_ADDR_EXPR)
                                                    {
                                                        yystack.l_mark[-2].n->value=2;
                                                        yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-3].n,yystack.l_mark[-1].n,NULL);
                                                    }
                                                    else
                                                    {
                                                        printf("\n%d:Invalid operands in assignment!!\n",linecount);
                                                        exit(0);
                                                    }
                                                }
#line 1385 "y.tab.c"
break;
case 11:
#line 87 "splparser.y"
	{                                
                                                            yyval.n=create_tree(yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,NULL);
                                                            pop_alias();
                                                            depth--;
                                                        }
#line 1394 "y.tab.c"
break;
case 12:
#line 93 "splparser.y"
	{    
                                                            yyval.n=create_tree(yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n);
                                                            pop_alias();
                                                            depth--;
                                                        }
#line 1403 "y.tab.c"
break;
case 13:
#line 98 "splparser.y"
	{
                                                            yyval.n=create_tree(yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,NULL);
                                                            pop_alias();
                                                            depth--;
                                                            flag_break--;
                                                        }
#line 1413 "y.tab.c"
break;
case 14:
#line 104 "splparser.y"
	{    
                                                            push_alias(yystack.l_mark[-2].n->name,yystack.l_mark[-1].n->value);
                                                            yyval.n=NULL;
                                                        }
#line 1421 "y.tab.c"
break;
case 15:
#line 108 "splparser.y"
	{
                                                            yyval.n=create_tree(yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,NULL);
                                                        }
#line 1428 "y.tab.c"
break;
case 16:
#line 111 "splparser.y"
	{
                                                            yyval.n=create_tree(yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,NULL);
                                                        }
#line 1435 "y.tab.c"
break;
case 17:
#line 114 "splparser.y"
	{
                                                            yyval.n=create_tree(yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,NULL);
                                                        }
#line 1442 "y.tab.c"
break;
case 18:
#line 117 "splparser.y"
	{
                                                            yyval.n=yystack.l_mark[-1].n;
                                                        }
#line 1449 "y.tab.c"
break;
case 19:
#line 120 "splparser.y"
	{
                                                            yyval.n=yystack.l_mark[-1].n;
                                                        }
#line 1456 "y.tab.c"
break;
case 20:
#line 123 "splparser.y"
	{
                                                            if(flag_break==0)
                                                            {
                                                                printf("\n%d: break or continue should be used inside while!!\n",linecount);
                                                                exit(0);                                
                                                            }
                                                            yyval.n=yystack.l_mark[-1].n;
                                                        }
#line 1468 "y.tab.c"
break;
case 21:
#line 131 "splparser.y"
	{
                                                if(flag_break==0)
                                                {
                                                    printf("\n%d: break or continue should be used inside while!!\n",linecount);
                                                    exit(0);                                
                                                }
                                                yyval.n=yystack.l_mark[-1].n;
                                            }
#line 1480 "y.tab.c"
break;
case 22:
#line 139 "splparser.y"
	{    
                                                yyval.n=yystack.l_mark[-1].n;
                                            }
#line 1487 "y.tab.c"
break;
case 23:
#line 142 "splparser.y"
	{
                                                yystack.l_mark[-1].n->name++;
                                                int temp=strlen(yystack.l_mark[-1].n->name);
                                                yystack.l_mark[-1].n->name[temp-1]='\0';
                                                yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-1].n,NULL,NULL);
                                            }
#line 1497 "y.tab.c"
break;
case 24:
#line 148 "splparser.y"
	{    
                                                yyval.n=yystack.l_mark[-1].n;
                                            }
#line 1504 "y.tab.c"
break;
case 25:
#line 151 "splparser.y"
	{
                                                yyval.n=yystack.l_mark[-1].n;
                                            }
#line 1511 "y.tab.c"
break;
case 26:
#line 154 "splparser.y"
	{    
                                                if(node_getType(yystack.l_mark[-1].n)!=NODE_REG||!isAllowedRegister(yystack.l_mark[-1].n->value))
                                                {
                                                    printf("\n%d:Invalid operand in read!!\n",linecount);
                                                    exit(0);
                                                }                            
                                                yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-1].n,NULL,NULL);
                                            }
#line 1523 "y.tab.c"
break;
case 27:
#line 162 "splparser.y"
	{
                                                yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-1].n,NULL,NULL);
                                            }
#line 1530 "y.tab.c"
break;
case 28:
#line 165 "splparser.y"
	{
                                                yyval.n = create_tree(yystack.l_mark[-1].n, NULL, NULL, NULL);
                                            }
#line 1537 "y.tab.c"
break;
case 29:
#line 168 "splparser.y"
	{
                                                yyval.n = create_tree(yystack.l_mark[-1].n, NULL, NULL, NULL);
                                            }
#line 1544 "y.tab.c"
break;
case 30:
#line 171 "splparser.y"
	{    
                                                if(node_getType(yystack.l_mark[-1].n)!=NODE_REG||!isAllowedRegister(yystack.l_mark[-1].n->value))
                                                {
                                                    printf("\n%d:Invalid operand in encrypt!!\n",linecount);
                                                    exit(0);
                                                }                            
                                                yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-1].n,NULL,NULL);
                                            }
#line 1556 "y.tab.c"
break;
case 31:
#line 179 "splparser.y"
	{
                                                if(lookup_constant(node_getName(yystack.l_mark[-1].n))!=NULL)/*if the address to jump to is a predefined value in constants file*/
                                                {
                                                    yyval.n=create_tree(yystack.l_mark[-2].n,substitute_id(yystack.l_mark[-1].n),NULL,NULL);
                                                }
                                                else
                                                {
                                                    yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-1].n,NULL,NULL);
                                                }
                                                yyval.n->value=linecount;/*Hack to show line numbers in case of syntax errors*/
                                            }
#line 1571 "y.tab.c"
break;
case 32:
#line 190 "splparser.y"
	{
                                                if(lookup_constant(node_getName(yystack.l_mark[-1].n))!=NULL)/*if the address to jump to is a predefined value in constants file*/
                                                {
                                                    yyval.n=create_tree(yystack.l_mark[-2].n,substitute_id(yystack.l_mark[-1].n),NULL,NULL);
                                                }
                                                else
                                                {
                                                    yyval.n=create_tree(yystack.l_mark[-2].n,yystack.l_mark[-1].n,NULL,NULL);
                                                }
                                                yyval.n->value=linecount;/*Hack to show line numbers in case of syntax errors*/
                                            }
#line 1586 "y.tab.c"
break;
case 33:
#line 201 "splparser.y"
	{
                                                label_add(node_getName(yystack.l_mark[-1].n));
                                                yyval.n=create_nontermNode(NODE_LABEL_DEF,yystack.l_mark[-1].n,NULL);
                                            }
#line 1594 "y.tab.c"
break;
case 34:
#line 208 "splparser.y"
	{
                                                yyval.n=create_tree(yystack.l_mark[-1].n,yystack.l_mark[-2].n,yystack.l_mark[0].n,NULL);
                                            }
#line 1601 "y.tab.c"
break;
case 35:
#line 211 "splparser.y"
	{
                                                yyval.n=create_tree(yystack.l_mark[-1].n,yystack.l_mark[-2].n,yystack.l_mark[0].n,NULL);
                                            }
#line 1608 "y.tab.c"
break;
case 36:
#line 214 "splparser.y"
	{
                                                yyval.n=create_tree(yystack.l_mark[-1].n,yystack.l_mark[-2].n,yystack.l_mark[0].n,NULL);
                                            }
#line 1615 "y.tab.c"
break;
case 37:
#line 217 "splparser.y"
	{
                                                yyval.n=create_tree(yystack.l_mark[-1].n,yystack.l_mark[-2].n,yystack.l_mark[0].n,NULL);
                                            }
#line 1622 "y.tab.c"
break;
case 38:
#line 220 "splparser.y"
	{
                                                if(node_getType(yystack.l_mark[-1].n)==NODE_SUB)
                                                    yystack.l_mark[0].n->value=yystack.l_mark[0].n->value*-1;
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1631 "y.tab.c"
break;
case 39:
#line 225 "splparser.y"
	{
                                                yyval.n=create_tree(yystack.l_mark[-1].n,yystack.l_mark[0].n,NULL,NULL);
                                            }
#line 1638 "y.tab.c"
break;
case 40:
#line 228 "splparser.y"
	{
                                                yyval.n=create_nontermNode(NODE_ADDR_EXPR,yystack.l_mark[-1].n,NULL);
                                            }
#line 1645 "y.tab.c"
break;
case 41:
#line 231 "splparser.y"
	{
                                                yyval.n=yystack.l_mark[-1].n;
                                            }
#line 1652 "y.tab.c"
break;
case 42:
#line 234 "splparser.y"
	{    
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1659 "y.tab.c"
break;
case 43:
#line 237 "splparser.y"
	{
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1666 "y.tab.c"
break;
case 44:
#line 240 "splparser.y"
	{
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1673 "y.tab.c"
break;
case 45:
#line 245 "splparser.y"
	{
                                                depth++;
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1681 "y.tab.c"
break;
case 46:
#line 250 "splparser.y"
	{
                                                pop_alias();
                                            }
#line 1688 "y.tab.c"
break;
case 47:
#line 255 "splparser.y"
	{
                                                depth++;
                                                flag_break++;
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1697 "y.tab.c"
break;
case 48:
#line 262 "splparser.y"
	{                            
                                                yyval.n=substitute_id(yystack.l_mark[0].n);
                                            }
#line 1704 "y.tab.c"
break;
case 49:
#line 265 "splparser.y"
	{
                                                yyval.n=yystack.l_mark[0].n;
                                            }
#line 1711 "y.tab.c"
break;
#line 1713 "y.tab.c"
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
