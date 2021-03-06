/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y" /* yacc.c:339  */

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>

#define YYSTYPE atributos

using namespace std;
int q = 0;

struct atributos
{
	string label;
	string tipo;
	string traducao;
	string valor;
};

typedef struct atributos Atributos;
typedef map<string, Atributos> MAPA;
list<MAPA*> pilhaDeMapas;
string variaveis;

int yylex(void);
string gerarVarTemp();
//string geradora();
MAPA* buscaMapa (string label);
string declaracoes();
bool verificarDeclaracao(string label);
string gerarBloco();
string gerarfimbloco();
string valorBoolean(string a);
void yyerror(string MSG);
int tipoToIndice(string tipo);
string intToString(int label);
string op[6][6];
bool loopFor = false;
bool loopForWhile = false;
list<string> labelOpen;
list<string> labelClose;
list<string> labelAdd;


#line 112 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIN = 258,
    TK_TIPO_BOOLEAN = 259,
    TK_TIPO_FLOAT = 260,
    TK_TIPO_CHAR = 261,
    TK_TIPO_INT = 262,
    TK_TIPO_STRING = 263,
    TK_BOOLEAN = 264,
    TK_FLOAT = 265,
    TK_CHAR = 266,
    TK_INT = 267,
    TK_ID = 268,
    TK_STRING = 269,
    TK_MAIOR = 270,
    TK_MAIOR_IGUAL = 271,
    TK_MENOR = 272,
    TK_MENOR_IGUAL = 273,
    TK_IGUAL = 274,
    TK_DIFERENTE = 275,
    TK_OU = 276,
    TK_E = 277,
    TK_NEGACAO = 278,
    TK_FIM = 279,
    TK_ERROR = 280,
    TK_IF = 281,
    TK_ELSE = 282,
    TK_WHILE = 283,
    TK_SWITCH = 284,
    TK_CASE = 285,
    TK_DO = 286,
    TK_FOR = 287,
    TK_COUT = 288,
    TK_INC = 289,
    TK_INC_ABREV = 290,
    TK_CAST = 291
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_TIPO_BOOLEAN 259
#define TK_TIPO_FLOAT 260
#define TK_TIPO_CHAR 261
#define TK_TIPO_INT 262
#define TK_TIPO_STRING 263
#define TK_BOOLEAN 264
#define TK_FLOAT 265
#define TK_CHAR 266
#define TK_INT 267
#define TK_ID 268
#define TK_STRING 269
#define TK_MAIOR 270
#define TK_MAIOR_IGUAL 271
#define TK_MENOR 272
#define TK_MENOR_IGUAL 273
#define TK_IGUAL 274
#define TK_DIFERENTE 275
#define TK_OU 276
#define TK_E 277
#define TK_NEGACAO 278
#define TK_FIM 279
#define TK_ERROR 280
#define TK_IF 281
#define TK_ELSE 282
#define TK_WHILE 283
#define TK_SWITCH 284
#define TK_CASE 285
#define TK_DO 286
#define TK_FOR 287
#define TK_COUT 288
#define TK_INC 289
#define TK_INC_ABREV 290
#define TK_CAST 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    38,    36,    46,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    78,    85,    91,    99,   108,   114,   119,
     124,   125,   126,   127,   128,   129,   130,   131,   134,   139,
     144,   149,   155,   163,   178,   193,   233,   269,   312,   329,
     368,   407,   446,   485,   493,   504,   515,   524,   532,   541,
     549,   591,   633,   644,   685,   726,   767,   808,   849,   890,
     902,   907,   918,   921,   948,   976
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_TIPO_BOOLEAN",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_INT", "TK_TIPO_STRING",
  "TK_BOOLEAN", "TK_FLOAT", "TK_CHAR", "TK_INT", "TK_ID", "TK_STRING",
  "TK_MAIOR", "TK_MAIOR_IGUAL", "TK_MENOR", "TK_MENOR_IGUAL", "TK_IGUAL",
  "TK_DIFERENTE", "TK_OU", "TK_E", "TK_NEGACAO", "TK_FIM", "TK_ERROR",
  "TK_IF", "TK_ELSE", "TK_WHILE", "TK_SWITCH", "TK_CASE", "TK_DO",
  "TK_FOR", "TK_COUT", "TK_INC", "TK_INC_ABREV", "'+'", "'-'", "'*'",
  "'/'", "TK_CAST", "'('", "')'", "'{'", "'}'", "';'", "','", "'='",
  "$accept", "START", "MAIN", "ESCOPO_GLOBAL", "INICIO_ESCOPO",
  "FIM_ESCOPO", "BLOCO", "COMANDOS", "COMANDO", "TIPO", "DECLARACAO",
  "ATRIBUICAO", "E", "IF", "COUT", "WHILE", "DO", "FOR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    43,    45,    42,    47,
     291,    40,    41,   123,   125,    59,    44,    61
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -48,     3,    11,   -48,    16,   -48,   -21,   -20,   -17,   -48,
      85,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -30,   -48,    43,   -18,   -14,   -17,   -12,    -7,    43,
      43,    -9,    85,    24,   -40,     5,   112,   -48,     6,   -48,
     -48,   -48,   -48,    43,   -48,    86,    43,    43,    30,    46,
      43,   -48,    -6,   -48,   -48,   -48,    14,   -48,    49,   -48,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,   -48,   -48,   225,   153,   161,    23,   -30,    20,
     189,   -48,    43,    21,   -48,   -48,   -48,   -48,   -48,   -48,
      86,    86,   233,   233,   233,   233,   -17,   -17,    43,    43,
     -48,   225,    43,    40,   -48,   197,   122,   225,   -17,    27,
      46,   -48,   -48,    31,   -17,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     2,     0,     0,     0,     5,
       9,     3,    20,    19,    21,    18,    22,    35,    38,    36,
      34,    37,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    13,     0,    14,
      16,    15,    28,     0,    37,    42,     0,     0,     0,     0,
       0,    49,     0,     6,     7,     8,    23,    11,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    17,    27,     0,     0,     0,     0,     0,
       0,    33,     0,    24,    43,    44,    45,    46,    47,    48,
      41,    40,    29,    30,    31,    32,     0,     0,     0,     0,
      52,    26,     0,    50,    53,     0,     0,    25,     0,     0,
       0,    51,    54,     0,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -48,   -26,    37,   -48,   -48,
     -48,   -47,   -22,   -48,   -48,   -48,   -48,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     2,    10,    54,    11,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    45,    79,     3,    42,    57,    58,    51,    52,    60,
      61,    62,    63,    64,    65,    66,    67,    43,     4,     6,
       7,    74,     8,    46,    75,    76,     9,    47,    80,    49,
      68,    69,    70,    71,    50,    53,    81,    56,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      59,    73,    17,    18,    19,    20,    44,    22,    77,    78,
     101,    82,    83,   113,    98,    99,    23,   108,   102,    55,
     103,   104,   112,   114,     0,     0,   105,   106,     0,     0,
     107,     0,   111,    29,    30,     0,     0,     0,   115,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,    60,    61,    62,    63,    64,    65,     0,    23,     0,
       0,    24,     0,    25,     0,     0,    26,    27,    28,     0,
       0,     0,     0,     0,     0,    29,    30,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,    68,    69,
      70,    71,     0,     0,     0,     0,     0,    72,    68,    69,
      70,    71,     0,     0,     0,     0,     0,   110,    60,    61,
      62,    63,    64,    65,    66,    67,    60,    61,    62,    63,
      64,    65,    66,    67,     0,     0,     0,     0,     0,    68,
      69,    70,    71,     0,     0,    96,     0,    68,    69,    70,
      71,     0,     0,    97,    60,    61,    62,    63,    64,    65,
      66,    67,    60,    61,    62,    63,    64,    65,    66,    67,
       0,     0,     0,     0,     0,    68,    69,    70,    71,     0,
       0,   100,     0,    68,    69,    70,    71,     0,     0,   109,
      60,    61,    62,    63,    64,    65,    66,    67,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,    68,    69,    70,    71
};

static const yytype_int8 yycheck[] =
{
      26,    23,    49,     0,    34,    45,    46,    29,    30,    15,
      16,    17,    18,    19,    20,    21,    22,    47,     7,     3,
      41,    43,    42,    41,    46,    47,    43,    41,    50,    41,
      36,    37,    38,    39,    41,    44,    42,    13,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      45,    45,     9,    10,    11,    12,    13,    14,    28,    13,
      82,    47,    13,   110,    41,    45,    23,    27,    47,    32,
      96,    97,    45,    42,    -1,    -1,    98,    99,    -1,    -1,
     102,    -1,   108,    40,    41,    -1,    -1,    -1,   114,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    15,    16,    17,    18,    19,    20,    -1,    23,    -1,
      -1,    26,    -1,    28,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    15,    16,
      17,    18,    19,    20,    21,    22,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    36,    37,    38,
      39,    -1,    -1,    42,    15,    16,    17,    18,    19,    20,
      21,    22,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    36,    37,    38,    39,    -1,    -1,    42,
      15,    16,    17,    18,    19,    20,    21,    22,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    51,     0,     7,    50,     3,    41,    42,    43,
      52,    54,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    23,    26,    28,    31,    32,    33,    40,
      41,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    34,    47,    13,    60,    41,    41,    54,    41,
      41,    60,    60,    44,    53,    55,    13,    45,    46,    45,
      15,    16,    17,    18,    19,    20,    21,    22,    36,    37,
      38,    39,    45,    45,    60,    60,    60,    28,    13,    59,
      60,    42,    47,    13,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    42,    42,    41,    45,
      42,    60,    47,    54,    54,    60,    60,    60,    27,    42,
      45,    54,    45,    59,    42,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    52,    53,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    63,    64,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     0,     1,     1,     3,     2,     0,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     3,     5,     4,     3,     2,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     2,
       5,     7,     4,     5,     7,     9
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 70 "sintatica.y" /* yacc.c:1646  */
    { 
					cout << "\n*Compilador DOIT* \n#include<string.h>\n#include<iostream>\n#include<stdio.h>\n" << endl;
					cout << variaveis << endl;
					declaracoes();			
					cout << (yyvsp[0]).traducao << endl;
				}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = "int main(void)\n{\n" + (yyvsp[0]).traducao + "\treturn 0;\n}\n\n"; 
				}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = new MAPA();
					pilhaDeMapas.push_front(mapa);
				}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 92 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = new MAPA();
					pilhaDeMapas.push_front(mapa);
					(yyval).traducao = "";
				}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "sintatica.y" /* yacc.c:1646  */
    {	
					declaracoes();				
					pilhaDeMapas.pop_front();
					(yyval).traducao = "";

				}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = (yyvsp[-1]).traducao;
				}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "sintatica.y" /* yacc.c:1646  */
    { 
					(yyval).traducao = (yyvsp[-1]).traducao +  "\n" + (yyvsp[0]).traducao;
				}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = "";
				}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = "int";
					(yyval).tipo = "int";
				}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = "float";
					(yyval).tipo = "float";
				}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = "boolean";
					(yyval).tipo = "boolean";
				}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 150 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = "char";
					(yyval).tipo = "char";
				}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 156 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = "string";
					(yyval).tipo = "string";
				}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao((yyvsp[0]).label))
					{
						(*mapa)[(yyvsp[0]).label].label = gerarVarTemp();
						(*mapa)[(yyvsp[0]).label].tipo = (yyvsp[-1]).tipo;
					}
					(yyval).tipo = (*mapa)[(yyvsp[0]).label].tipo;
					(yyvsp[0]).label = (*mapa)[(yyvsp[0]).label].label;

					(yyval).traducao = (yyvsp[0]).traducao + (yyval).tipo + " " + (yyvsp[0]).label;
					(yyval).traducao = "";
				}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 179 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao((yyvsp[0]).label))
					{
						(*mapa)[(yyvsp[0]).label].label = gerarVarTemp();
						(*mapa)[(yyvsp[0]).label].tipo = (yyvsp[-2]).tipo;
					}

					(yyval).tipo = (*mapa)[(yyvsp[0]).label].tipo;
					(yyvsp[0]).label = (*mapa)[(yyvsp[0]).label].label;
					(yyval).traducao = "";
					
				}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 206 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao((yyvsp[-2]).label))
					{
						(*mapa)[(yyvsp[-2]).label].label = gerarVarTemp();
						(*mapa)[(yyvsp[-2]).label].tipo = (yyvsp[-4]).tipo;
					}
					(yyval).tipo = (*mapa)[(yyvsp[-2]).label].tipo;
					(yyvsp[-2]).label = (*mapa)[(yyvsp[-2]).label].label;

					if ((yyval).tipo == (yyvsp[0]).tipo)
					{
						(yyval).traducao = (yyvsp[-4]).traducao + "\n" + (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + (yyvsp[0]).label + ";\n";
					}
					else
					{
						if ((yyval).tipo!=(yyvsp[0]).tipo)
						{	
							yyerror("ERRO: ATRIBUICAO ILEGAL!");
						}
						else
						{
							(yyval).traducao = (yyvsp[-4]).traducao + "\n" + (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + (yyvsp[0]).label + ";\n";
						}
					}
				}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao((yyvsp[-2]).label))
					{	
						(*mapa)[(yyvsp[-2]).label].label = gerarVarTemp();
						(*mapa)[(yyvsp[-2]).label].tipo = (yyvsp[-3]).tipo;
					}

					(yyval).tipo = (*mapa)[(yyvsp[-2]).label].tipo;
    				(yyvsp[-2]).label = (*mapa)[(yyvsp[-2]).label].label;

					if ((yyval).tipo!=(yyvsp[0]).tipo) 
					{
						yyerror("ERRO: ATRIBUICAO ILEGAL!");
					}
					else
					{
						(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + (yyvsp[0]).label + ";\n";						
					}
				}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 292 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = buscaMapa((yyvsp[-2]).label);
					if(mapa == NULL)
						yyerror("ERRO: VARIAVEL NAO DECLARADA.");

					(yyval).tipo = (*mapa)[(yyvsp[-2]).label].tipo;	

					if ((yyval).tipo!=(yyvsp[0]).tipo) 
					{
						yyerror("ERRO: ATRIBUICAO ILEGAL!");
					}
					else
					{
						(yyval).label = (*mapa)[(yyvsp[-2]).label].label;
						(yyval).tipo = (*mapa)[(yyvsp[-2]).label].tipo;
						(yyvsp[-2]).label = (yyval).label;
						(yyval).traducao = (yyvsp[0]).traducao + '\t' + (yyvsp[-2]).label + " = " + (yyvsp[0]).label + ";\n" ;
					}
					
				}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 313 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = buscaMapa((yyvsp[-1]).label);
					(yyvsp[-1]).label = (*mapa)[(yyvsp[-1]).label].label;
				
					if(mapa == NULL)
					{
						yyerror("ERRO: VARIAVEL NAO DECLARADA!");
					}
					
					else
					{
						(yyval).traducao = "\t" + (yyvsp[-1]).label + " = " + (yyvsp[-1]).label + " " + (yyvsp[0]).traducao[0] + "1;\n";
					}
				}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 330 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(yyval).tipo = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";

					if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{	
						if ((yyval).tipo == "ilegal") 
						{
								yyerror("ERRO: SOMA ILEGAL!");
						}
						else if ((yyval).tipo == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label +";\n";
						}
						else if ((yyval).tipo == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{ 	
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label + ";\n";
					}
				}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 369 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(yyval).tipo = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";

					if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{	
						if ((yyval).tipo == "ilegal") 
						{
								yyerror("ERRO: SUBTRACAO ILEGAL!");
						}
						else if ((yyval).tipo == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " - " + (yyvsp[0]).label +";\n";
						}
						else if ((yyval).tipo == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " - " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{ 	
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " - " + (yyvsp[0]).label + ";\n";
					}
				}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 408 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(yyval).tipo = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";

					if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{	
						if ((yyval).tipo == "ilegal") 
						{
								yyerror("ERRO: MULTIPLICACAO ILEGAL!");
						}
						else if ((yyval).tipo == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " * " + (yyvsp[0]).label +";\n";
						}
						else if ((yyval).tipo == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " * " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{ 	
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " * " + (yyvsp[0]).label + ";\n";
					}
				}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 447 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(yyval).tipo = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";

					if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{	
						if ((yyval).tipo == "ilegal") 
						{
								yyerror("ERRO: DIVISAO ILEGAL!");
						}
						else if ((yyval).tipo == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " / " + (yyvsp[0]).label +";\n";
						}
						else if ((yyval).tipo == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+(yyval).tipo+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = (yyval).tipo;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " / " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{ 	
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " / " + (yyvsp[0]).label + ";\n";
					}
				}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 486 "sintatica.y" /* yacc.c:1646  */
    {	
					(yyval).label = gerarVarTemp();
					(yyval).traducao = (yyvsp[-1]).traducao;	
					(yyval).tipo = (yyvsp[-1]).tipo;
					(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-1]).label + ";\n";
		
				}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 494 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();

					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].traducao = (yyvsp[0]).traducao;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label+ ";\n";
				}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 505 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].traducao = (yyvsp[0]).traducao;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label+ ";\n";
				}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 516 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].traducao = (yyvsp[0]).traducao;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label+ ";\n";
				}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 525 "sintatica.y" /* yacc.c:1646  */
    {	
					MAPA* mapa = buscaMapa((yyvsp[0]).label);
					mapa = pilhaDeMapas.front();		
					(yyval).label = (*mapa)[(yyvsp[0]).label].label;
					(yyval).tipo = (*mapa)[(yyvsp[0]).label].tipo;
					(yyval).traducao = "";
				}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 533 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].traducao = (yyvsp[0]).traducao;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label+ ";\n";
				}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 542 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].valor = (yyvsp[0]).traducao;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;					
				}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 550 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
 					//pra verificar se eh ilegal
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: AND ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " && " + (yyvsp[0]).label + ";\n";
					}
				}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 592 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: OR ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " || " + (yyvsp[0]).label + ";\n";
					}
    					
				}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 634 "sintatica.y" /* yacc.c:1646  */
    {
				
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(yyval).tipo = "boolean";
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao =  (yyvsp[-1]).traducao + (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + "!" + (yyvsp[0]).label +";\n";	

				}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 645 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MAIOR QUE ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " > " + (yyvsp[0]).label + ";\n";
					}
    			}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 686 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MAIOR/IGUAL ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " >= " + (yyvsp[0]).label + ";\n";
					}
    			}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 727 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MENOR QUE ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " < " + (yyvsp[0]).label + ";\n";
					}
    			}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 768 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MENOR/IGUAL ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " <= " + (yyvsp[0]).label + ";\n";
					}
    			}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 809 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: IGUAL QUE ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " == " + (yyvsp[0]).label + ";\n";
					}
    			}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 850 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
 					(yyval).label = (yyval).label;
 					(yyval).tipo = "boolean";
    				string tipo1 = op[tipoToIndice((yyvsp[-2]).tipo)][tipoToIndice((yyvsp[0]).tipo)];
    				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t";
    				(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;

    				if ((yyvsp[-2]).tipo != (yyvsp[0]).tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: DIFERENTE ILEGAL!");
						}
						else if (tipo1 == (yyvsp[-2]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[0]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label +";\n";
						}
						else if (tipo1 == (yyvsp[0]).tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + (yyvsp[-2]).label + ";\n";
			            	(yyvsp[-2]).label = tempCast;
			            	(*mapa)[(yyvsp[-2]).label].label = (yyvsp[-2]).label;
							(*mapa)[(yyvsp[-2]).label].tipo = tipo1;
          					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + traducaoCast + "\t" + (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label +";\n";
						}
					}
					else
					{
						(yyval).traducao += (yyval).label + " = " + (yyvsp[-2]).label + " != " + (yyvsp[0]).label + ";\n";
					}
    			}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 891 "sintatica.y" /* yacc.c:1646  */
    {
					MAPA* mapa = pilhaDeMapas.front();
					(yyval).label = gerarVarTemp();
					(yyval).tipo = (yyvsp[-1]).tipo;
					(*mapa)[(yyval).label].label = (yyval).label;
					(*mapa)[(yyval).label].tipo = (yyval).tipo;
					(yyval).traducao = (yyvsp[0]).traducao + '\t' + (yyval).label + " = (" + (yyvsp[-1]).tipo + ") " + (yyvsp[0]).label + ";\n";
				}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 903 "sintatica.y" /* yacc.c:1646  */
    {	string blocoEnd = gerarBloco();
					(yyval).traducao = (yyvsp[-2]).traducao + "\n\tif (" + (yyvsp[-2]).label +") goto " + blocoEnd + ";\n\n" + (yyvsp[0]).traducao + "\t" + blocoEnd + ":\n";		
				}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 908 "sintatica.y" /* yacc.c:1646  */
    {
					string blocoIf = gerarBloco();
					string blocoElse = gerarBloco();
					string blocoEnd = gerarBloco();

					(yyval).traducao = (yyvsp[-4]).traducao + "\n\tif (" + (yyvsp[-4]).label +") goto " + blocoElse + ";\n\n" + (yyvsp[-2]).traducao  + "\tgoto " + blocoEnd  + ";\n\n\t" + blocoElse + ":\n"+(yyvsp[0]).traducao + "\t" + blocoEnd + ":\n";
				}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 918 "sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = "\tcout << " + (yyvsp[-1]).label + " << endl;";}
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 922 "sintatica.y" /* yacc.c:1646  */
    {
					if(loopFor)
					{
						loopFor = false;
						loopForWhile = true;
					}

					string blocoIf = gerarBloco();
					labelOpen.push_front(blocoIf);

					string blocoElse = gerarBloco();
					labelClose.push_front(blocoElse);

					(yyval).traducao = (yyvsp[-2]).traducao + "\n\t" + labelOpen.front() + ":" + "\n\tif (" + (yyvsp[-2]).label +") goto " + labelClose.front() + ";\n\n" + (yyvsp[0]).traducao + "\tgoto " +labelOpen.front() + ";\n\n\t" + labelClose.front() + ":\n";
					labelOpen.pop_front();
					labelClose.pop_front();

					if(loopForWhile)
					{
						loopFor = true;
						loopForWhile = false;

					}
				}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 949 "sintatica.y" /* yacc.c:1646  */
    {
					{
						string blocoIf = gerarBloco();
						labelOpen.push_front(blocoIf);
			    			string blocoElse = gerarBloco();
			    			labelOpen.push_front(blocoElse);

			   		 if(loopFor)
					{
						loopFor = false;
						loopForWhile = true;
					}

				}
			
				(yyval).traducao = (yyvsp[-2]).traducao + "\n\t" + labelOpen.front() + ":\n" + (yyvsp[-5]).traducao + "\tif (" + (yyvsp[-2]).label + ") goto " + labelOpen.front() + ";\n\tgoto " + labelOpen.front() + ";\n\n\t" + labelClose.front() + ":\n";
				labelOpen.pop_front();
				labelClose.pop_front();

				if(loopForWhile)
				{
					loopFor = true;
					loopForWhile = false;
				}
			}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 977 "sintatica.y" /* yacc.c:1646  */
    {	
				{
					loopFor = true;
	
					string blocoIf = gerarBloco();
					labelOpen.push_front(blocoIf);
	
					string blocoAdd = gerarBloco();
					labelAdd.push_front(blocoAdd);
	
					string blocoElse = gerarBloco();
					labelClose.push_front(blocoElse);
				}
		
				(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + labelOpen.front() + ":\n" +  (yyvsp[-4]).traducao + "\n\tif (" + (yyvsp[-4]).label +") goto " + labelClose.front() + ";\n\n" + (yyvsp[0]).traducao + "\n\t" + labelAdd.front() + ":\n" + (yyvsp[-2]).traducao + "\tgoto " + labelOpen.front() + ";\n\n\t" + labelClose.front() + ":\n";

				labelOpen.pop_front();
				labelAdd.pop_front();
				labelClose.pop_front();
				loopFor = false;
			}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2436 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1001 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{	
	op[1][1] = "int";
	op[1][2] = "float";
	op[1][3] = "ilegal";
	op[1][4] = "string";
	op[1][5] = "ilegal";
	op[2][1] = "float";
	op[2][2] = "float";
	op[2][3] = "ilegal";
	op[2][4] = "string";
	op[2][5] = "ilegal";
	op[3][1] = "ilegal";
	op[3][2] = "ilegal";
	op[3][3] = "string";
	op[3][4] = "string";
	op[3][5] = "ilegal";
	op[4][1] = "string";
	op[4][2] = "string";
	op[4][3] = "string";
	op[4][4] = "string";
	op[4][5] = "ilegal";
	op[5][1] = "ilegal";
	op[5][2] = "ilegal";
	op[5][3] = "ilegal";
	op[5][4] = "ilegal";
	op[5][5] = "boolean";	
	yyparse();
	return 0;
}

string gerarVarTemp()
{	   
	stringstream ss;
	ss << q;
	string str = ss.str();
	q++;
	return "TEMP" +str; 
}

/*string geradora(){
	
	char buffer[50];
	string temp;
	numero++;
	sprintf(buffer,"temp %d",numero);
	temp = buffer;
	return temp;
}*/

void yyerror(string MSG )
{
	cout << MSG << endl;
	exit (0);
}		

MAPA* buscaMapa(string label)
{
	list<MAPA*>::iterator i;
	for(i = pilhaDeMapas.begin(); i != pilhaDeMapas.end(); i++)
	{
		MAPA* mapa = *i;
		if(mapa->find(label) != mapa->end()) {return mapa;}
	}
	return NULL;
}

string gerarBloco()
{	
	static int bloco = 1;
	stringstream label;
	label << " bloco " << bloco++;
	return label.str();
}
string gerarfimbloco()
{	
	static int bloco = 0;
	stringstream label;
	label << " fim_if " << bloco++;
	return label.str();
}
	
bool verificarDeclaracao(string label)
{
	MAPA* mapa = pilhaDeMapas.front();
	if(mapa->find(label) == mapa->end())
	return false;
	else return true;	
}

string declaracoes()
{
	MAPA mapa = *pilhaDeMapas.front();
	MAPA::iterator i;
	stringstream s;
	for(i = mapa.begin(); i != mapa.end(); i++){
		if(i->second.tipo == "boolean"){
			continue;
		}else{
			s << i->second.tipo << " " << i->second.label << ";\n";
		}
	}
	variaveis += s.str() + "\n";
	return variaveis;
}


/*string valorBoolean (string a) {
	if (a == "true") return "1";
	else if (a == "false") return "0";
}*/

int tipoToIndice(string tipo)
{
	if(tipo == "int") 
		return 1;
	else if(tipo == "float") 
		return 2;
	else if(tipo == "string") 
		return 3;
	else if(tipo == "char") 
		return 4;
	else if(tipo == "boolean") 
		return 5;
}

string intToString(int label)
{
	stringstream out;
	out << label;
	return out.str();
}
