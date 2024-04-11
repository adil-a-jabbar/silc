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
    #include "typetable.h"

    int yylex(void);
    extern FILE *yyin;
    extern int yylineno;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 16 "yaccfile.y"
typedef union YYSTYPE{
    struct tnode* no;
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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,   14,   20,   20,   32,
   18,   18,   19,   15,   15,   21,   21,   33,   31,   31,
   31,   23,   23,   24,   24,   24,   16,   16,   26,   26,
   22,   22,   36,   36,   37,   25,   25,   27,   35,   35,
   35,   38,   34,   34,   34,   39,   17,   17,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    7,
    7,    8,    4,    5,    5,    6,    6,    9,   10,   11,
   28,   13,   13,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,   30,   30,   29,   29,
   12,   12,   12,
};
static const YYINT yylen[] = {                            2,
    4,    2,    3,    3,    2,    1,    3,    2,    1,    4,
    2,    1,    3,    3,    2,    2,    1,    3,    1,    1,
    1,    3,    1,    1,    4,    4,    2,    1,    9,    8,
    3,    2,    2,    1,    3,    3,    1,    3,    3,    1,
    0,    2,    3,    1,    0,    2,    8,    7,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    8,
    6,    6,    3,    3,    3,    4,    4,    2,    2,    3,
    3,    3,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    1,    1,    1,
    4,    3,    4,    1,    3,    3,    3,    3,    3,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    6,    0,   21,   19,
   20,   15,    0,    0,   17,    0,    0,    9,    0,    5,
    0,    0,    2,   28,    0,    0,   14,   16,    0,    0,
   23,    0,    7,    8,    0,    4,    3,   27,    0,    0,
    0,    0,   18,    0,  103,  101,  102,    0,    0,   12,
    1,    0,    0,    0,    0,    0,   44,   22,    0,   10,
   11,    0,    0,   40,    0,    0,    0,    0,   25,   46,
    0,   26,   13,   42,    0,    0,   88,    0,    0,    0,
    0,   89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   50,   51,   52,   53,   54,   55,   56,   57,
   59,   58,    0,   32,    0,    0,   34,    0,   48,   43,
   39,    0,    0,    0,    0,    0,    0,    0,    0,   73,
    0,    0,    0,    0,    0,   68,   69,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   38,   49,    0,   37,    0,   31,   33,
   47,    0,    0,    0,   92,    0,    0,   98,   95,   96,
   70,   63,    0,   64,   65,    0,    0,   71,   79,    0,
    0,   77,   76,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   97,   35,    0,    0,   30,   91,
    0,   93,   72,    0,    0,   66,   67,   36,   29,    0,
    0,    0,    0,    0,   61,   62,    0,   60,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  261,  296,  301,  304,  318,  319,  321,  299,  259,  261,
  262,  297,  325,  335,  337,  259,  324,  336,  319,  321,
  261,  320,  321,  330,  335,   40,  297,  337,  259,  327,
  328,  123,  302,  336,  320,  321,  321,  330,  259,   41,
   91,   40,  278,  298,  259,  261,  262,  316,  322,  323,
  321,   40,  123,  257,  316,  338,  343,  328,  259,  125,
  323,  316,  339,  342,  277,  296,  326,  331,   93,  259,
  298,   41,  278,  259,  298,   41,  257,  259,  263,  264,
  265,  266,  275,  276,  287,  291,  294,  295,  300,   40,
  305,  306,  307,  308,  309,  310,  311,  312,  313,  314,
  315,  332,  334,  297,  316,  340,  341,  331,  125,  343,
  342,  123,   91,   40,   46,   40,   40,  305,  305,  260,
   40,  305,  317,  305,  305,  278,  278,  305,  305,  267,
  268,  269,  270,  271,  274,  279,  280,  281,  282,  283,
  284,  285,  286,  258,  307,   46,  259,  329,  297,  341,
  125,  326,  331,  305,   41,  305,  333,  259,   41,   41,
  278,  278,  260,  278,  278,  288,  293,  278,   41,  305,
  305,  305,  305,  305,  305,  317,  305,  305,  305,  305,
  305,  305,  305,  305,  259,  278,  298,  331,  125,   93,
  298,   41,   41,  306,  306,  278,  278,  259,  125,  305,
  289,  290,  292,  306,  278,  278,  290,  278,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          4,
   91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
  101,   48,  123,    5,    6,   22,    7,   49,   50,   17,
   13,   67,   30,   31,  148,   24,   68,  102,  157,  103,
   25,   18,   15,   56,   63,  106,  107,   64,   57,
};
static const YYINT yysindex[] = {                      -240,
 -292, -217, -228,    0, -179, -225,    0,   -2,    0,    0,
    0,    0, -202, -218,    0, -110, -251,    0, -225,    0,
 -292, -225,    0,    0, -216,   55,    0,    0,  -12, -268,
    0, -159,    0,    0, -225,    0,    0,    0,   61,  -10,
 -147, -159,    0, -218,    0,    0,    0, -148, -122,    0,
    0, -159, -191,   23, -139,  -39,    0,    0, -157,    0,
    0, -137,  -37,    0,   91, -178, -153,    1,    0,    0,
 -159,    0,    0,    0, -159,    4,    0,  -13,   89,   90,
  106,    0,  106,  -18,  106,  106, -140, -131,  106,  106,
  474,   -1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  102,    0, -109, -174,    0,   24,    0,    0,
    0, -191,  106,   66, -108,  111,  120,  494,  514,    0,
   74,  534, -116,  -72, -126,    0,    0,  554,  454,  106,
  106,  106,  106,  106,  -18,  106,  106,  106,  106,  106,
  106,  106,  106,    0,    0,  -96,    0, -252,    0,    0,
    0, -153,   39,  -92,    0,  594,  -32,    0,    0,    0,
    0,    0,  124,    0,    0,   91,   91,    0,    0, -176,
 -176,    0,    0, -176,  574, -105, -135, -135, -135, -135,
 -135, -135,  -99,  -99,    0,    0,  -85,   76,    0,    0,
  106,    0,    0,  -40,   13,    0,    0,    0,    0,  594,
   91,  -76,  -75,   52,    0,    0,  -74,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -73,    0,    0,    0,    0,    0,    0,    0, -246,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -30,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -29,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  125,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  159,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -27,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  187,
  226,    0,    0,  260,    0,    0,  281,  304,  327,  357,
  383,  405,  203,  422,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -25,
    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  -66, -104,  -86,    0,    0,    0,    0,    0,    0,    0,
    0,  -17,   70,    0,  201,  196,   93,    0,  171,    0,
    0,  109,    0,  178,    0,   69,  -62,    0,    0,    0,
   27,  210,  216,    0,    0,    0,  126,  155,  160,
};
#define YYTABLESIZE 880
static const YYINT yytable[] = {                         90,
  190,   72,   60,   76,  108,  145,    8,   16,  192,   43,
   45,   41,   32,  100,  118,   99,  119,  122,  124,  125,
    1,  121,  128,  129,   55,  186,  114,   42,   14,   44,
   16,   24,  115,    9,   62,   21,   11,   26,   90,   14,
   29,    9,   39,   10,   11,  187,  154,  156,  105,  153,
   33,   24,   90,   55,  129,    2,    9,   62,   10,   11,
    3,  194,  195,  170,  171,  172,  173,  174,  175,  177,
  178,  179,  180,  181,  182,  183,  184,  113,   41,   12,
   45,    1,   46,   47,   45,   65,   46,   47,  105,  188,
   38,   90,  132,  133,   27,   40,  204,   20,   23,   45,
   52,   46,   47,   38,   66,   90,  155,  145,  145,   54,
   59,   36,   53,   90,   37,   69,    2,  145,  104,   70,
   73,   74,  149,   65,  200,  109,  112,   51,  116,  117,
   90,  130,  131,  132,  133,  134,   45,  126,   46,   47,
  130,  131,  132,  133,  134,   90,  127,  146,  151,  147,
  158,  159,  136,  137,  138,  139,  140,  141,  142,  143,
  160,  165,  185,  189,  193,   90,  167,  130,  131,  132,
  133,  134,  197,  198,  130,  131,  132,  133,  134,  136,
  137,  138,  139,  140,  141,   19,  136,  137,  138,  139,
  140,  141,  142,  143,  130,  131,  132,  133,  134,   94,
  199,  205,  206,  208,  176,   19,  136,  137,  138,  139,
  140,  141,  142,  143,   35,  166,   77,   90,   78,   61,
  152,   58,   79,   80,   81,   82,   34,   74,   28,  111,
  110,  150,    0,    0,   83,   84,    0,    0,   77,    0,
   78,  120,    0,   86,   79,   80,   85,   82,  201,  202,
   86,   94,    0,   87,   88,   77,  144,   78,   71,   89,
   75,   79,   80,   81,   82,  191,   75,   45,   41,   77,
  100,   78,   99,   83,   84,   79,   80,   81,   82,   74,
    0,    0,    0,    0,    0,   85,    0,   83,   84,   86,
    0,    0,   87,   88,    0,   86,    0,    0,   89,   85,
   78,    0,    0,   86,  203,    0,   87,   88,   77,    0,
   78,    0,   89,    0,   79,   80,   81,   82,   75,    0,
    0,   80,   77,    0,   78,    0,   83,   84,   79,   80,
   77,   82,   78,  163,    0,    0,   79,   80,   85,   82,
    0,  207,   86,    0,   81,   87,   88,   77,    0,   78,
    0,   89,   78,   79,   80,   81,   82,    0,    0,    0,
    0,    0,   77,    0,   78,   83,   84,   82,   79,   80,
    0,   82,    0,   80,    0,    0,    0,   85,    0,    0,
    0,   86,    0,    0,   87,   88,    0,    0,    0,    0,
   89,   90,   90,   90,   90,   90,   81,   83,   90,    0,
    0,    0,   90,   90,   90,   90,   90,   90,   90,   90,
   90,    0,   90,    0,    0,    0,    0,   90,    0,   82,
    0,    0,   90,   84,    0,   94,   94,   94,   94,   94,
    0,    0,   94,    0,    0,    0,   94,   94,   94,   94,
   94,   94,   94,   94,   94,   85,   94,    0,    0,   83,
    0,   94,    0,   74,   74,    0,   94,   74,    0,    0,
   74,    0,   87,    0,   74,   74,   74,   74,   74,   74,
   74,   74,   74,    0,   74,   84,   86,    0,    0,   74,
   86,    0,    0,    0,   74,    0,    0,   86,   86,    0,
   86,    0,   75,   75,  169,   86,   75,   85,    0,   75,
   86,    0,    0,   75,   75,   75,   75,   75,   75,   75,
   75,   75,    0,   75,   87,    0,    0,    0,   75,    0,
    0,    0,    0,   75,    0,    0,   78,   78,    0,    0,
   78,    0,    0,   78,    0,    0,    0,   78,   78,   78,
   78,   78,   78,   78,   78,   78,    0,   78,    0,    0,
    0,    0,   78,    0,   80,    0,    0,   78,   80,   80,
   80,   80,   80,   80,   80,   80,   80,    0,   80,    0,
    0,    0,    0,   80,    0,    0,    0,   81,   80,    0,
    0,   81,   81,   81,   81,   81,   81,   81,   81,   81,
    0,   81,    0,    0,    0,    0,   81,    0,    0,    0,
   82,   81,    0,    0,   82,   82,   82,   82,   82,   82,
   82,   82,   82,    0,   82,    0,    0,    0,    0,   82,
    0,    0,    0,    0,   82,    0,    0,    0,    0,    0,
   83,    0,    0,    0,   83,   83,   83,   83,   83,   83,
   83,   83,   83,    0,   83,    0,    0,    0,    0,   83,
    0,    0,    0,    0,   83,    0,   84,    0,    0,    0,
   84,   84,   84,   84,   84,   84,   84,   84,   84,    0,
   84,    0,    0,    0,    0,   84,    0,    0,   85,    0,
   84,    0,   85,   85,   85,   85,   85,   85,   85,   85,
   85,    0,   85,    0,    0,   87,    0,   85,    0,   87,
    0,    0,   85,    0,    0,    0,   87,   87,    0,   87,
    0,    0,    0,    0,   87,    0,    0,    0,    0,   87,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,    0,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,  135,    0,    0,
    0,    0,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,  161,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,  162,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,  164,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,  168,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,  196,  136,  137,  138,  139,  140,  141,  142,  143,
  130,  131,  132,  133,  134,    0,    0,    0,    0,    0,
    0,    0,  136,  137,  138,  139,  140,  141,  142,  143,
};
static const YYINT yycheck[] = {                         40,
   93,   41,  125,   41,   67,   92,  299,  259,   41,  278,
   41,   41,  123,   41,   81,   41,   83,   84,   85,   86,
  261,   40,   89,   90,   42,  278,   40,   40,    2,  298,
  259,  278,   46,  259,   52,  261,  262,   40,   40,   13,
  259,  259,  259,  261,  262,  298,  113,  114,   66,  112,
  302,  298,   40,   71,  121,  296,  259,   75,  261,  262,
  301,  166,  167,  130,  131,  132,  133,  134,  135,  136,
  137,  138,  139,  140,  141,  142,  143,   91,   91,  297,
  259,  261,  261,  262,  259,  277,  261,  262,  106,  152,
   22,   40,  269,  270,  297,   41,  201,    5,    6,  259,
   40,  261,  262,   35,  296,   40,   41,  194,  195,  257,
  259,   19,  123,   40,   22,   93,  296,  204,  297,  259,
  278,  259,  297,  277,  191,  125,  123,   35,   40,   40,
   40,  267,  268,  269,  270,  271,  259,  278,  261,  262,
  267,  268,  269,  270,  271,   40,  278,   46,  125,  259,
  259,   41,  279,  280,  281,  282,  283,  284,  285,  286,
   41,  278,  259,  125,   41,   41,  293,  267,  268,  269,
  270,  271,  278,  259,  267,  268,  269,  270,  271,  279,
  280,  281,  282,  283,  284,  259,  279,  280,  281,  282,
  283,  284,  285,  286,  267,  268,  269,  270,  271,   41,
  125,  278,  278,  278,  135,    5,  279,  280,  281,  282,
  283,  284,  285,  286,   19,  288,  257,   93,  259,   49,
  112,   44,  263,  264,  265,  266,   17,   41,   13,   75,
   71,  106,   -1,   -1,  275,  276,   -1,   -1,  257,   -1,
  259,  260,   -1,   41,  263,  264,  287,  266,  289,  290,
  291,   93,   -1,  294,  295,  257,  258,  259,  298,  300,
  298,  263,  264,  265,  266,  298,   41,  298,  298,  257,
  298,  259,  298,  275,  276,  263,  264,  265,  266,   93,
   -1,   -1,   -1,   -1,   -1,  287,   -1,  275,  276,  291,
   -1,   -1,  294,  295,   -1,   93,   -1,   -1,  300,  287,
   41,   -1,   -1,  291,  292,   -1,  294,  295,  257,   -1,
  259,   -1,  300,   -1,  263,  264,  265,  266,   93,   -1,
   -1,   41,  257,   -1,  259,   -1,  275,  276,  263,  264,
  257,  266,  259,  260,   -1,   -1,  263,  264,  287,  266,
   -1,  290,  291,   -1,   41,  294,  295,  257,   -1,  259,
   -1,  300,   93,  263,  264,  265,  266,   -1,   -1,   -1,
   -1,   -1,  257,   -1,  259,  275,  276,   41,  263,  264,
   -1,  266,   -1,   93,   -1,   -1,   -1,  287,   -1,   -1,
   -1,  291,   -1,   -1,  294,  295,   -1,   -1,   -1,   -1,
  300,  267,  268,  269,  270,  271,   93,   41,  274,   -1,
   -1,   -1,  278,  279,  280,  281,  282,  283,  284,  285,
  286,   -1,  288,   -1,   -1,   -1,   -1,  293,   -1,   93,
   -1,   -1,  298,   41,   -1,  267,  268,  269,  270,  271,
   -1,   -1,  274,   -1,   -1,   -1,  278,  279,  280,  281,
  282,  283,  284,  285,  286,   41,  288,   -1,   -1,   93,
   -1,  293,   -1,  267,  268,   -1,  298,  271,   -1,   -1,
  274,   -1,   41,   -1,  278,  279,  280,  281,  282,  283,
  284,  285,  286,   -1,  288,   93,  274,   -1,   -1,  293,
  278,   -1,   -1,   -1,  298,   -1,   -1,  285,  286,   -1,
  288,   -1,  267,  268,   41,  293,  271,   93,   -1,  274,
  298,   -1,   -1,  278,  279,  280,  281,  282,  283,  284,
  285,  286,   -1,  288,   93,   -1,   -1,   -1,  293,   -1,
   -1,   -1,   -1,  298,   -1,   -1,  267,  268,   -1,   -1,
  271,   -1,   -1,  274,   -1,   -1,   -1,  278,  279,  280,
  281,  282,  283,  284,  285,  286,   -1,  288,   -1,   -1,
   -1,   -1,  293,   -1,  274,   -1,   -1,  298,  278,  279,
  280,  281,  282,  283,  284,  285,  286,   -1,  288,   -1,
   -1,   -1,   -1,  293,   -1,   -1,   -1,  274,  298,   -1,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
   -1,  288,   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,
  274,  298,   -1,   -1,  278,  279,  280,  281,  282,  283,
  284,  285,  286,   -1,  288,   -1,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,  298,   -1,   -1,   -1,   -1,   -1,
  274,   -1,   -1,   -1,  278,  279,  280,  281,  282,  283,
  284,  285,  286,   -1,  288,   -1,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,  298,   -1,  274,   -1,   -1,   -1,
  278,  279,  280,  281,  282,  283,  284,  285,  286,   -1,
  288,   -1,   -1,   -1,   -1,  293,   -1,   -1,  274,   -1,
  298,   -1,  278,  279,  280,  281,  282,  283,  284,  285,
  286,   -1,  288,   -1,   -1,  274,   -1,  293,   -1,  278,
   -1,   -1,  298,   -1,   -1,   -1,  285,  286,   -1,  288,
   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,  274,   -1,   -1,
   -1,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 302
#define YYUNDFTOKEN 344
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,0,0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NUM",
"END","ID","STRING_TYPE","INT","STR","ALLOC","INITIALIZE","FREE","NULLVAL",
"PLUS","MINUS","MUL","DIV","MOD","SPACE","NEWLINE","ASSG","READ","WRITE",
"START","COLON","LT","LE","GT","GE","EQ","NE","OR","AND","IF","THEN","ELSE",
"ENDIF","WHILE","ENDWHILE","DO","BREAK","CONT","DECL","ENDDECL","COMMA","MAIN",
"RETURN","TYPE","ENDTYPE","$accept","program","expr","Slist","Stmt","InputStmt",
"OutputStmt","AsgStmt","IfStmt","WhileStmt","BreakStmt","ContinueStmt",
"FreeStmt","TypeName","String","TypeDefBlock","GdeclBlock","FdefBlock",
"MainBlock","FieldDeclList","FieldDecl","TypeDefList","GdeclList","LdeclBlock",
"GidList","Gid","IdList","Fdef","Body","Retstmt","ArgList","Field","Type",
"TypeDef","GDecl","GParamList","ParamList","LDeclList","LDecl","Param","GParam",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : TypeDefBlock GdeclBlock FdefBlock MainBlock",
"program : GdeclBlock MainBlock",
"program : GdeclBlock FdefBlock MainBlock",
"program : TypeDefBlock GdeclBlock MainBlock",
"program : TypeDefBlock MainBlock",
"program : MainBlock",
"TypeDefBlock : TYPE TypeDefList ENDTYPE",
"TypeDefList : TypeDefList TypeDef",
"TypeDefList : TypeDef",
"TypeDef : ID '{' FieldDeclList '}'",
"FieldDeclList : FieldDeclList FieldDecl",
"FieldDeclList : FieldDecl",
"FieldDecl : TypeName ID COLON",
"GdeclBlock : DECL GdeclList ENDDECL",
"GdeclBlock : DECL ENDDECL",
"GdeclList : GdeclList GDecl",
"GdeclList : GDecl",
"GDecl : Type GidList COLON",
"Type : INT",
"Type : STR",
"Type : ID",
"GidList : GidList COMMA Gid",
"GidList : Gid",
"Gid : ID",
"Gid : ID '[' NUM ']'",
"Gid : ID '(' GParamList ')'",
"FdefBlock : FdefBlock Fdef",
"FdefBlock : Fdef",
"Fdef : Type ID '(' ParamList ')' '{' LdeclBlock Body '}'",
"Fdef : Type ID '(' ParamList ')' '{' Body '}'",
"LdeclBlock : DECL LDeclList ENDDECL",
"LdeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : TypeName IdList COLON",
"IdList : IdList COMMA ID",
"IdList : ID",
"Body : START Slist END",
"ParamList : ParamList COMMA Param",
"ParamList : Param",
"ParamList :",
"Param : TypeName ID",
"GParamList : GParamList COMMA GParam",
"GParamList : GParam",
"GParamList :",
"GParam : TypeName ID",
"MainBlock : INT MAIN '(' ')' '{' LdeclBlock Body '}'",
"MainBlock : INT MAIN '(' ')' '{' Body '}'",
"Slist : Slist Stmt",
"Slist : Stmt",
"Stmt : InputStmt",
"Stmt : OutputStmt",
"Stmt : AsgStmt",
"Stmt : IfStmt",
"Stmt : WhileStmt",
"Stmt : BreakStmt",
"Stmt : ContinueStmt",
"Stmt : Retstmt",
"Stmt : FreeStmt",
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
"FreeStmt : FREE expr COLON",
"Retstmt : RETURN expr COLON",
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
"expr : NULLVAL",
"expr : ID",
"expr : ID '[' expr ']'",
"expr : ID '(' ')'",
"expr : ID '(' ArgList ')'",
"expr : Field",
"expr : ALLOC '(' ')'",
"expr : INITIALIZE '(' ')'",
"Field : Field '.' ID",
"Field : ID '.' ID",
"ArgList : ArgList COMMA expr",
"ArgList : expr",
"TypeName : INT",
"TypeName : STR",
"TypeName : ID",

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
#line 214 "yaccfile.y"

void yyerror(char * msg){
    printf (ANSI_COLOR_RED "\nerror in line %d: %s\n" ANSI_COLOR_RESET, yylineno, msg);
    exit (1);
}

int main (){
    yyin = fopen ("input.txt", "r");
    filePointer = fopen ("executable.xsm", "w");
    headerGen (filePointer);
    fclose (filePointer);
    TypeTableCreate();
    printf ("tokens:\n-------------\n");
    yyparse();
    filePointer = fopen ("executable.xsm", "a");
    exitGen (filePointer);
    return 0;
}
#line 847 "y.tab.c"

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
#line 30 "yaccfile.y"
	{
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        }
#line 1523 "y.tab.c"
break;
case 2:
#line 34 "yaccfile.y"
	{
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        }
#line 1531 "y.tab.c"
break;
case 3:
#line 38 "yaccfile.y"
	{
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        }
#line 1539 "y.tab.c"
break;
case 4:
#line 42 "yaccfile.y"
	{
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        }
#line 1547 "y.tab.c"
break;
case 5:
#line 46 "yaccfile.y"
	{
                            printf ("\n----------------------------------------------------------------\n                         symbol table:           \n----------------------------------------------------------------\n");
                            printSymbolTable(); printTypeTable();
                        }
#line 1555 "y.tab.c"
break;
case 6:
#line 50 "yaccfile.y"
	{
                            printf ("\n-------------\nsymbol table:\n-------------\n");
                            printSymbolTable(); printTypeTable();
                        }
#line 1563 "y.tab.c"
break;
case 7:
#line 55 "yaccfile.y"
	{}
#line 1568 "y.tab.c"
break;
case 8:
#line 57 "yaccfile.y"
	{}
#line 1573 "y.tab.c"
break;
case 9:
#line 58 "yaccfile.y"
	{}
#line 1578 "y.tab.c"
break;
case 10:
#line 60 "yaccfile.y"
	{Tinstall (yystack.l_mark[-3].no->varName, yystack.l_mark[-1].no, -1); Flisthead = NULL; currFieldIndex = 0;}
#line 1583 "y.tab.c"
break;
case 11:
#line 62 "yaccfile.y"
	{yyval.no = makeConnectorNode (CONNECTOR, yystack.l_mark[-1].no, yystack.l_mark[0].no);}
#line 1588 "y.tab.c"
break;
case 12:
#line 63 "yaccfile.y"
	{yyval.no = yystack.l_mark[0].no;}
#line 1593 "y.tab.c"
break;
case 13:
#line 65 "yaccfile.y"
	{yyval.no = makeTreeNode(FIELD_DECL, NULL, -1, NULL, '0', NULL, NULL, yystack.l_mark[-2].no, yystack.l_mark[-1].no, NULL);}
#line 1598 "y.tab.c"
break;
case 14:
#line 67 "yaccfile.y"
	{printf ("GdeclDone\n"); printSymbolTable();}
#line 1603 "y.tab.c"
break;
case 15:
#line 68 "yaccfile.y"
	{}
#line 1608 "y.tab.c"
break;
case 16:
#line 70 "yaccfile.y"
	{}
#line 1613 "y.tab.c"
break;
case 17:
#line 71 "yaccfile.y"
	{}
#line 1618 "y.tab.c"
break;
case 18:
#line 73 "yaccfile.y"
	{doesTypeExist(yystack.l_mark[-2].no->varName); }
#line 1623 "y.tab.c"
break;
case 19:
#line 75 "yaccfile.y"
	{yyval.no = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', yystack.l_mark[0].no->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, yystack.l_mark[0].no->varName); printf ("type set to %s\n", type);}
#line 1628 "y.tab.c"
break;
case 20:
#line 76 "yaccfile.y"
	{yyval.no = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', yystack.l_mark[0].no->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, yystack.l_mark[0].no->varName); printf ("type set to %s\n", type);}
#line 1633 "y.tab.c"
break;
case 21:
#line 77 "yaccfile.y"
	{yyval.no = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', yystack.l_mark[0].no->varName, NULL, NULL, NULL, NULL); strcpy (Gtype, yystack.l_mark[0].no->varName); printf ("type set to %s\n", type);}
#line 1638 "y.tab.c"
break;
case 22:
#line 79 "yaccfile.y"
	{}
#line 1643 "y.tab.c"
break;
case 23:
#line 80 "yaccfile.y"
	{}
#line 1648 "y.tab.c"
break;
case 24:
#line 82 "yaccfile.y"
	{Ginstall (yystack.l_mark[0].no->varName, TLookup(Gtype), 1, NULL); yyval.no->type = TLookup(type); yyval.no=yystack.l_mark[0].no;}
#line 1653 "y.tab.c"
break;
case 25:
#line 83 "yaccfile.y"
	{Ginstall (yystack.l_mark[-3].no->varName, TLookup(Gtype), yystack.l_mark[-1].no->val, NULL); yyval.no->type = TLookup(type); yyval.no=yystack.l_mark[-3].no;}
#line 1658 "y.tab.c"
break;
case 26:
#line 84 "yaccfile.y"
	{Ginstall (yystack.l_mark[-3].no->varName, TLookup(Gtype), -1, paramList); yyval.no->type = TLookup(type); yyval.no=yystack.l_mark[-3].no; paramList=NULL; paramListTail=NULL;}
#line 1663 "y.tab.c"
break;
case 27:
#line 87 "yaccfile.y"
	{}
#line 1668 "y.tab.c"
break;
case 28:
#line 88 "yaccfile.y"
	{}
#line 1673 "y.tab.c"
break;
case 29:
#line 90 "yaccfile.y"
	{doesTypeExist(yystack.l_mark[-8].no->varName); currGSymbol = setGentry(yystack.l_mark[-7].no->varName); if (TLookup(Gtype) != currGSymbol->type) {yyerror ("invalid type for function\n");} yystack.l_mark[-1].no->nodeType = FUN_DEF; checkNameEquivalence (yystack.l_mark[-7].no->varName); filePointer = fopen ("executable.xsm", "a"); codeGen (yystack.l_mark[-1].no, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
#line 1678 "y.tab.c"
break;
case 30:
#line 91 "yaccfile.y"
	{doesTypeExist(yystack.l_mark[-7].no->varName); currGSymbol = setGentry(yystack.l_mark[-6].no->varName); if (TLookup(Gtype) != currGSymbol->type) {yyerror ("invalid type for function\n");} yystack.l_mark[-1].no->nodeType = FUN_DEF; checkNameEquivalence (yystack.l_mark[-6].no->varName); filePointer = fopen ("executable.xsm", "a"); codeGen (yystack.l_mark[-1].no, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
#line 1683 "y.tab.c"
break;
case 31:
#line 93 "yaccfile.y"
	{printf ("LdeclBlockDone\n");}
#line 1688 "y.tab.c"
break;
case 32:
#line 94 "yaccfile.y"
	{printf ("LdeclBlockDone\n");}
#line 1693 "y.tab.c"
break;
case 34:
#line 96 "yaccfile.y"
	{}
#line 1698 "y.tab.c"
break;
case 35:
#line 98 "yaccfile.y"
	{doesTypeExist(yystack.l_mark[-2].no->varName); }
#line 1703 "y.tab.c"
break;
case 36:
#line 100 "yaccfile.y"
	{Linstall (yystack.l_mark[0].no->varName, TLookup(type), currPBinding++);}
#line 1708 "y.tab.c"
break;
case 37:
#line 101 "yaccfile.y"
	{Linstall (yystack.l_mark[0].no->varName, TLookup(type), currPBinding++);}
#line 1713 "y.tab.c"
break;
case 38:
#line 103 "yaccfile.y"
	{yyval.no = makeConnectorNode (FUN_DEF, yystack.l_mark[-1].no, yystack.l_mark[0].no); printf ("Body Done\n");}
#line 1718 "y.tab.c"
break;
case 39:
#line 105 "yaccfile.y"
	{}
#line 1723 "y.tab.c"
break;
case 40:
#line 106 "yaccfile.y"
	{}
#line 1728 "y.tab.c"
break;
case 41:
#line 107 "yaccfile.y"
	{}
#line 1733 "y.tab.c"
break;
case 42:
#line 109 "yaccfile.y"
	{doesTypeExist(yystack.l_mark[-1].no->varName); Linstall (yystack.l_mark[0].no->varName, TLookup(type), currNBinding--); insertParamList (yystack.l_mark[0].no->varName, TLookup(type));}
#line 1738 "y.tab.c"
break;
case 43:
#line 111 "yaccfile.y"
	{}
#line 1743 "y.tab.c"
break;
case 44:
#line 112 "yaccfile.y"
	{}
#line 1748 "y.tab.c"
break;
case 45:
#line 113 "yaccfile.y"
	{}
#line 1753 "y.tab.c"
break;
case 46:
#line 115 "yaccfile.y"
	{doesTypeExist(yystack.l_mark[-1].no->varName); insertParamList (yystack.l_mark[0].no->varName, TLookup(type));}
#line 1758 "y.tab.c"
break;
case 47:
#line 117 "yaccfile.y"
	{yystack.l_mark[-1].no->nodeType = MAIN_FUN; filePointer = fopen ("executable.xsm", "a"); codeGen (yystack.l_mark[-1].no, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
#line 1763 "y.tab.c"
break;
case 48:
#line 118 "yaccfile.y"
	{yystack.l_mark[-1].no->nodeType = MAIN_FUN; filePointer = fopen ("executable.xsm", "a"); codeGen (yystack.l_mark[-1].no, filePointer); fclose (filePointer); paramList=NULL; paramListTail=NULL; Lhead=NULL; Ltail=NULL; currPBinding=1; currNBinding=-1;}
#line 1768 "y.tab.c"
break;
case 49:
#line 120 "yaccfile.y"
	{yyval.no=makeConnectorNode (CONNECTOR, yystack.l_mark[-1].no, yystack.l_mark[0].no);}
#line 1773 "y.tab.c"
break;
case 50:
#line 121 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1778 "y.tab.c"
break;
case 51:
#line 123 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1783 "y.tab.c"
break;
case 52:
#line 124 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1788 "y.tab.c"
break;
case 53:
#line 125 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1793 "y.tab.c"
break;
case 54:
#line 126 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1798 "y.tab.c"
break;
case 55:
#line 127 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1803 "y.tab.c"
break;
case 56:
#line 128 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1808 "y.tab.c"
break;
case 57:
#line 129 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1813 "y.tab.c"
break;
case 58:
#line 130 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1818 "y.tab.c"
break;
case 59:
#line 131 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1823 "y.tab.c"
break;
case 60:
#line 133 "yaccfile.y"
	{yyval.no=makeStmtNode (IFELSE, yystack.l_mark[-6].no, yystack.l_mark[-2].no, yystack.l_mark[-4].no);}
#line 1828 "y.tab.c"
break;
case 61:
#line 134 "yaccfile.y"
	{yyval.no=makeStmtNode (IFNODE, yystack.l_mark[-4].no, yystack.l_mark[-2].no, NULL);}
#line 1833 "y.tab.c"
break;
case 62:
#line 136 "yaccfile.y"
	{yyval.no=makeStmtNode (WH, yystack.l_mark[-4].no, yystack.l_mark[-2].no, NULL);}
#line 1838 "y.tab.c"
break;
case 63:
#line 138 "yaccfile.y"
	{yyval.no=makeStmtNode (INPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1843 "y.tab.c"
break;
case 64:
#line 140 "yaccfile.y"
	{yyval.no=makeStmtNode (OUTPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1848 "y.tab.c"
break;
case 65:
#line 141 "yaccfile.y"
	{yyval.no=makeStmtNode (OUTPUT_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1853 "y.tab.c"
break;
case 66:
#line 143 "yaccfile.y"
	{yyval.no=makeStmtNode (ASG_STMT, yystack.l_mark[-3].no, yystack.l_mark[-1].no, NULL);}
#line 1858 "y.tab.c"
break;
case 67:
#line 144 "yaccfile.y"
	{yyval.no=makeStmtNode (ASG_STMT, yystack.l_mark[-3].no, yystack.l_mark[-1].no, NULL);}
#line 1863 "y.tab.c"
break;
case 68:
#line 146 "yaccfile.y"
	{yyval.no=makeStmtNode (BRK_STMT, NULL, NULL, NULL);}
#line 1868 "y.tab.c"
break;
case 69:
#line 148 "yaccfile.y"
	{yyval.no=makeStmtNode (CONT_STMT, NULL, NULL, NULL);}
#line 1873 "y.tab.c"
break;
case 70:
#line 150 "yaccfile.y"
	{yyval.no=makeStmtNode (FREE_STMT, NULL, yystack.l_mark[-1].no, NULL);}
#line 1878 "y.tab.c"
break;
case 71:
#line 152 "yaccfile.y"
	{yyval.no = makeStmtNode (RET_STMT, yystack.l_mark[-1].no, NULL, NULL);}
#line 1883 "y.tab.c"
break;
case 72:
#line 154 "yaccfile.y"
	{yyval.no=yystack.l_mark[-1].no; yyval.no->type = strType;}
#line 1888 "y.tab.c"
break;
case 73:
#line 155 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; yyval.no->type = strType;}
#line 1893 "y.tab.c"
break;
case 74:
#line 157 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '+', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1898 "y.tab.c"
break;
case 75:
#line 158 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '-', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1903 "y.tab.c"
break;
case 76:
#line 159 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '/', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1908 "y.tab.c"
break;
case 77:
#line 160 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '*', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1913 "y.tab.c"
break;
case 78:
#line 161 "yaccfile.y"
	{yyval.no=makeOperatorNode (OP, '%', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1918 "y.tab.c"
break;
case 79:
#line 162 "yaccfile.y"
	{yyval.no=yystack.l_mark[-1].no;  yyval.no->type = yystack.l_mark[-1].no->type;}
#line 1923 "y.tab.c"
break;
case 80:
#line 163 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '<', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1928 "y.tab.c"
break;
case 81:
#line 164 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'l', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1933 "y.tab.c"
break;
case 82:
#line 165 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '>', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1938 "y.tab.c"
break;
case 83:
#line 166 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'g', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1943 "y.tab.c"
break;
case 84:
#line 167 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '=', yystack.l_mark[-2].no, yystack.l_mark[0].no); printf ("expr->expr eq expr\n");}
#line 1948 "y.tab.c"
break;
case 85:
#line 168 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, 'n', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1953 "y.tab.c"
break;
case 86:
#line 169 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '|', yystack.l_mark[-2].no, yystack.l_mark[0].no); printf ("expr->expr or expr\n");}
#line 1958 "y.tab.c"
break;
case 87:
#line 170 "yaccfile.y"
	{yyval.no=makeOperatorNode (BOOL, '&', yystack.l_mark[-2].no, yystack.l_mark[0].no);}
#line 1963 "y.tab.c"
break;
case 88:
#line 171 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1968 "y.tab.c"
break;
case 89:
#line 172 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1973 "y.tab.c"
break;
case 90:
#line 173 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; if (LSymbolLookup (yystack.l_mark[0].no->varName) == NULL) {yystack.l_mark[0].no->Gentry = setGentry (yystack.l_mark[0].no->varName); yystack.l_mark[0].no->type = yystack.l_mark[0].no->Gentry->type;} else {yystack.l_mark[0].no->type = (LSymbolLookup (yystack.l_mark[0].no->varName))->type;}}
#line 1978 "y.tab.c"
break;
case 91:
#line 174 "yaccfile.y"
	{if (yystack.l_mark[-1].no->type != intType) yyerror("\ntype error !\n"); yystack.l_mark[-3].no->Gentry = setGentry (yystack.l_mark[-3].no->varName); yystack.l_mark[-3].no->type = yystack.l_mark[-3].no->Gentry->type; yystack.l_mark[-3].no->left = yystack.l_mark[-1].no; yyval.no=yystack.l_mark[-3].no;}
#line 1983 "y.tab.c"
break;
case 92:
#line 175 "yaccfile.y"
	{yystack.l_mark[-2].no->Gentry = setGentry (yystack.l_mark[-2].no->varName); funArgsCheck(yystack.l_mark[-2].no->Gentry, argsHead); yystack.l_mark[-2].no->type = yystack.l_mark[-2].no->Gentry->type; yystack.l_mark[-2].no->mid = NULL; yyval.no=yystack.l_mark[-2].no; yyval.no->nodeType=FUN_CALL;}
#line 1988 "y.tab.c"
break;
case 93:
#line 176 "yaccfile.y"
	{yystack.l_mark[-3].no->Gentry = setGentry (yystack.l_mark[-3].no->varName); funArgsCheck(yystack.l_mark[-3].no->Gentry, argsHead); yystack.l_mark[-3].no->type = yystack.l_mark[-3].no->Gentry->type; yystack.l_mark[-3].no->mid = argsHead; yyval.no=yystack.l_mark[-3].no; argsHead = NULL; argsTail = NULL; yyval.no->nodeType=FUN_CALL;}
#line 1993 "y.tab.c"
break;
case 94:
#line 177 "yaccfile.y"
	{yyval.no = yystack.l_mark[0].no;}
#line 1998 "y.tab.c"
break;
case 95:
#line 178 "yaccfile.y"
	{yystack.l_mark[-2].no = makeAllocNode (ALLOC_NODE); yyval.no = yystack.l_mark[-2].no;}
#line 2003 "y.tab.c"
break;
case 96:
#line 179 "yaccfile.y"
	{yystack.l_mark[-2].no = makeAllocNode (INITIALIZE_NODE); yyval.no = yystack.l_mark[-2].no;}
#line 2008 "y.tab.c"
break;
case 97:
#line 181 "yaccfile.y"
	{
                        yyval.no = makeFieldNode (FIELD_NODE, yystack.l_mark[-2].no, yystack.l_mark[0].no);
                        if ((FLookup (yystack.l_mark[-2].no->type, yystack.l_mark[0].no->varName)) == NULL){
                            char msg[100];
                            sprintf (msg, "'%s' does not have a member named '%s'\n", yystack.l_mark[-2].no->type->name, yystack.l_mark[0].no->varName);
                            yyerror (msg);
                        }
                        else
                        yystack.l_mark[0].no->type = (FLookup (yystack.l_mark[-2].no->type, yystack.l_mark[0].no->varName))->type;
                        yyval.no->type = yystack.l_mark[0].no->type;
                    }
#line 2023 "y.tab.c"
break;
case 98:
#line 192 "yaccfile.y"
	{if (LSymbolLookup (yystack.l_mark[-2].no->varName) == NULL) {yystack.l_mark[-2].no->Gentry = setGentry (yystack.l_mark[-2].no->varName); yystack.l_mark[-2].no->type = yystack.l_mark[-2].no->Gentry->type;} else {yystack.l_mark[-2].no->type = (LSymbolLookup (yystack.l_mark[-2].no->varName))->type;}
                    if ((FLookup (yystack.l_mark[-2].no->type, yystack.l_mark[0].no->varName)) == NULL){
                        char msg[100];
                        sprintf (msg, "'%s' does not have a member named '%s'\n", yystack.l_mark[-2].no->type->name, yystack.l_mark[0].no->varName);
                        yyerror (msg);
                    }
                    else
                    yystack.l_mark[0].no->type = (FLookup (yystack.l_mark[-2].no->type, yystack.l_mark[0].no->varName))->type;
                    yyval.no = makeFieldNode (FIELD_NODE, yystack.l_mark[-2].no, yystack.l_mark[0].no);
                    yyval.no->type = yystack.l_mark[0].no->type;
                }
#line 2038 "y.tab.c"
break;
case 99:
#line 204 "yaccfile.y"
	{argsTail->mid=yystack.l_mark[0].no; argsTail=argsTail->mid; argsTail->mid = NULL;}
#line 2043 "y.tab.c"
break;
case 100:
#line 205 "yaccfile.y"
	{yyval.no=yystack.l_mark[0].no; argsHead = yyval.no; argsTail = yyval.no; argsTail->mid = NULL;}
#line 2048 "y.tab.c"
break;
case 101:
#line 208 "yaccfile.y"
	{yyval.no = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', yystack.l_mark[0].no->varName, NULL, NULL, NULL, NULL); strcpy (type, yystack.l_mark[0].no->varName); printf ("type set to %s\n", type);}
#line 2053 "y.tab.c"
break;
case 102:
#line 209 "yaccfile.y"
	{yyval.no = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', yystack.l_mark[0].no->varName, NULL, NULL, NULL, NULL); strcpy (type, yystack.l_mark[0].no->varName); printf ("type set to %s\n", type);}
#line 2058 "y.tab.c"
break;
case 103:
#line 210 "yaccfile.y"
	{yyval.no = makeTreeNode (TYPE_NODE, NULL, -1, NULL, '0', yystack.l_mark[0].no->varName, NULL, NULL, NULL, NULL); strcpy (type, yystack.l_mark[0].no->varName); printf ("type set to %s\n", type);}
#line 2063 "y.tab.c"
break;
#line 2065 "y.tab.c"
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
