/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cafezinho.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

extern char * yytext;
extern int yylex();
extern FILE* yyin;
extern int lineNum;
extern int tipoErro;
void yyerror(const char *s);

TOperador* CriaNo(TypeOperators typeOperator,  int line, TOperador* t1, TOperador* t2, char* Tlexema);
TOperador* CriaNoTernario(TypeOperators typeOperator,  int line, TOperador* t1, TOperador* t2,TOperador* t3, char* Tlexema);
void walkTree(TOperador* raiz);
void printOperator(TOperador* no, char* nomeOperador);

TOperador* raiz;
char nomeOperador[200];


#line 93 "cafezinho.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CAFEZINHO_TAB_H_INCLUDED
# define YY_YY_CAFEZINHO_TAB_H_INCLUDED
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
    ABRECOLCHETES = 258,
    FECHACOLCHETES = 259,
    ABREPARENTESES = 260,
    FECHAPARENTESES = 261,
    IGUAL = 262,
    DIFERENTE = 263,
    RECEBE = 264,
    MENORIGUAL = 265,
    MAIORIGUAL = 266,
    MENOR = 267,
    MAIOR = 268,
    VIRGULA = 269,
    ABRECHAVE = 270,
    FECHACHAVE = 271,
    EXCLAMACAO = 272,
    INTERROGACAO = 273,
    DOISPONTOS = 274,
    VEZES = 275,
    RESTO = 276,
    DIVIDIDO = 277,
    MENOS = 278,
    MAIS = 279,
    PONTOVIRGULA = 280,
    PROGRAMA = 281,
    CAR = 282,
    INT = 283,
    RETORNE = 284,
    LEIA = 285,
    ESCREVA = 286,
    NOVALINHA = 287,
    SE = 288,
    ENTAO = 289,
    SENAO = 290,
    ENQUANTO = 291,
    EXECUTE = 292,
    E = 293,
    OU = 294,
    ID = 295,
    CONSTCAR = 296,
    CONSTINT = 297,
    CADEIACARACTERES = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "cafezinho.y"

    int line;
    char* Tlexema;
    TOperador* Tpont;

#line 195 "cafezinho.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    47,    48,    49,    50,    54,    58,    59,
      60,    64,    68,    69,    73,    74,    75,    76,    80,    81,
      85,    86,    87,    91,    92,    96,    97,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   115,   119,
     120,   124,   125,   129,   130,   134,   135,   139,   140,   141,
     145,   146,   147,   148,   149,   152,   153,   154,   158,   159,
     160,   161,   165,   166,   167,   171,   172,   176,   177,   178,
     179,   180,   181,   182,   186,   187
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABRECOLCHETES", "FECHACOLCHETES",
  "ABREPARENTESES", "FECHAPARENTESES", "IGUAL", "DIFERENTE", "RECEBE",
  "MENORIGUAL", "MAIORIGUAL", "MENOR", "MAIOR", "VIRGULA", "ABRECHAVE",
  "FECHACHAVE", "EXCLAMACAO", "INTERROGACAO", "DOISPONTOS", "VEZES",
  "RESTO", "DIVIDIDO", "MENOS", "MAIS", "PONTOVIRGULA", "PROGRAMA", "CAR",
  "INT", "RETORNE", "LEIA", "ESCREVA", "NOVALINHA", "SE", "ENTAO", "SENAO",
  "ENQUANTO", "EXECUTE", "E", "OU", "ID", "CONSTCAR", "CONSTINT",
  "CADEIACARACTERES", "$accept", "Programa", "DeclFuncVar", "DeclProg",
  "DeclVar", "DeclFunc", "ListaParametros", "ListaParametrosCont", "Bloco",
  "ListaDeclVar", "Tipo", "ListaComando", "Comando", "Expr", "AssignExpr",
  "CondExpr", "OrExpr", "AndExpr", "EqExpr", "DesigExpr", "AddExpr",
  "MulExpr", "UnExpr", "LValueExpr", "PrimExpr", "ListExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,  -111,  -111,     8,    -3,   -28,  -111,    16,  -111,    13,
      41,  -111,    24,    41,    36,    32,    41,    62,    59,   107,
      99,  -111,    75,    21,    41,  -111,    23,  -111,    31,    31,
    -111,    23,    79,     2,    98,   120,   122,    83,  -111,  -111,
    -111,   113,   101,   115,  -111,  -111,    -1,    97,    72,   139,
      73,    40,  -111,   137,  -111,    27,   143,    16,    44,   116,
    -111,  -111,   153,    34,  -111,  -111,   135,   158,   138,   140,
     141,  -111,    23,    23,    23,     9,  -111,  -111,  -111,    23,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,    23,   125,   144,   145,  -111,   160,    41,
     164,  -111,    23,  -111,    23,  -111,  -111,  -111,   156,   165,
     168,  -111,  -111,    15,   154,    97,    72,   139,   139,    73,
      73,    73,    73,    40,    40,  -111,  -111,  -111,  -111,   170,
      41,    41,   161,  -111,   143,   172,   173,   146,   142,   171,
    -111,    23,   105,   143,  -111,  -111,    41,  -111,  -111,  -111,
     101,   101,  -111,  -111,   157,  -111,   148,  -111,    41,   101,
    -111,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,    24,    23,     0,     0,     0,     1,     0,     2,    10,
      20,     7,     0,    12,     0,     0,     6,     0,     0,     0,
       0,    13,     0,    10,     6,     5,     0,    19,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      37,     0,    25,     0,    38,    39,    41,    44,    46,    49,
      54,    57,    61,     0,    64,    10,    10,     0,    14,     0,
       8,     3,     0,    70,    63,    62,     0,    66,     0,     0,
       0,    33,     0,     0,     0,     0,    18,    26,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,    73,     0,    29,     0,    30,    32,    31,     0,     0,
       0,    68,    74,     0,     0,    43,    45,    48,    47,    53,
      52,    50,    51,    56,    55,    58,    60,    59,    40,     0,
      20,     6,    15,    16,    10,     0,     0,     0,     0,    69,
      67,     0,     0,    10,    21,     4,     0,     9,    69,    65,
       0,     0,    75,    42,     0,    17,    34,    36,    20,     0,
      22,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,   -14,  -111,   -22,  -111,  -111,   -90,    -2,  -110,
     -10,   147,   -76,   -20,   -71,    39,  -111,   104,   106,    18,
      69,    25,    17,   159,   110,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     8,    15,    16,    20,    21,    40,    17,
       5,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    60,    25,    22,   112,    11,    62,    26,     6,   133,
      61,    66,     9,    70,    26,   111,    12,    79,    13,    28,
     144,   140,   128,     7,    59,    29,    28,    14,    26,   141,
      94,    10,    29,    95,    96,    14,    26,   102,    80,    75,
      28,    14,    37,    38,    39,    69,    29,    98,   160,    37,
      38,    39,   108,   109,   110,    97,   155,    24,    99,   114,
      90,    91,    92,    37,    38,    39,    19,    26,     1,     2,
     152,    63,    38,    39,   156,   157,    23,    10,    27,    28,
      82,    83,   135,   161,   136,    29,    74,    30,    75,    22,
     -66,    31,    32,    33,    34,    35,    88,    89,    36,    55,
     117,   118,    37,    38,    39,    57,    26,   125,   126,   127,
      26,    56,   147,   123,   124,    58,    10,   145,    28,    67,
      18,   154,    28,    71,    29,    72,    30,    73,    29,    76,
      31,    32,    33,    34,    35,    81,    22,    36,    64,    65,
      78,    37,    38,    39,    93,    63,    38,    39,    18,    84,
      85,    86,    87,   119,   120,   121,   122,    14,   100,   101,
     103,   104,   137,   105,   132,   106,   107,   129,   134,   130,
     131,   138,   139,   142,   143,   146,   148,   149,   -65,   151,
     150,   153,   158,   159,   115,     0,     0,   116,     0,    77,
       0,    68
};

static const yytype_int16 yycheck[] =
{
      10,    23,    16,    13,    75,     7,    26,     5,     0,    99,
      24,    31,    40,    33,     5,     6,     3,    18,     5,    17,
     130,     6,    93,    26,     3,    23,    17,    14,     5,    14,
       3,    15,    23,    55,    56,    14,     5,     3,    39,     5,
      17,    14,    40,    41,    42,    43,    23,     3,   158,    40,
      41,    42,    72,    73,    74,    57,   146,    25,    14,    79,
      20,    21,    22,    40,    41,    42,    42,     5,    27,    28,
     141,    40,    41,    42,   150,   151,    40,    15,    16,    17,
       8,     9,   102,   159,   104,    23,     3,    25,     5,    99,
       7,    29,    30,    31,    32,    33,    23,    24,    36,    40,
      82,    83,    40,    41,    42,     6,     5,    90,    91,    92,
       5,     4,   134,    88,    89,    40,    15,   131,    17,    40,
     130,   143,    17,    25,    23,     5,    25,     5,    23,    16,
      29,    30,    31,    32,    33,    38,   146,    36,    28,    29,
      25,    40,    41,    42,     7,    40,    41,    42,   158,    10,
      11,    12,    13,    84,    85,    86,    87,    14,    42,     6,
      25,     3,     6,    25,     4,    25,    25,    42,     4,    25,
      25,     6,     4,    19,     4,    14,     4,     4,     7,    37,
      34,   142,    25,    35,    80,    -1,    -1,    81,    -1,    42,
      -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,    45,    46,    54,     0,    26,    47,    40,
      15,    52,     3,     5,    14,    48,    49,    53,    54,    42,
      50,    51,    54,    40,    25,    46,     5,    16,    17,    23,
      25,    29,    30,    31,    32,    33,    36,    40,    41,    42,
      52,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    40,     4,     6,    40,     3,
      48,    46,    57,    40,    68,    68,    57,    40,    67,    43,
      57,    25,     5,     5,     3,     5,    16,    55,    25,    18,
      39,    38,     8,     9,    10,    11,    12,    13,    23,    24,
      20,    21,    22,     7,     3,    48,    48,    52,     3,    14,
      42,     6,     3,    25,     3,    25,    25,    25,    57,    57,
      57,     6,    58,    69,    57,    61,    62,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    58,    42,
      25,    25,     4,    51,     4,    57,    57,     6,     6,     4,
       6,    14,    19,     4,    53,    46,    14,    48,     4,     4,
      34,    37,    58,    59,    48,    51,    56,    56,    25,    35,
      53,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    47,    48,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     5,     8,     4,     0,     2,     3,     6,
       0,     4,     0,     1,     2,     4,     4,     6,     4,     3,
       0,     5,     8,     1,     1,     1,     2,     1,     2,     3,
       3,     3,     3,     2,     6,     8,     6,     1,     1,     1,
       3,     1,     5,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     4,     1,     4,     3,     4,
       1,     1,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 43 "cafezinho.y"
                           { raiz = CriaNo(Programa, lineNum, (yyvsp[-1].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1486 "cafezinho.tab.c"
    break;

  case 3:
#line 47 "cafezinho.y"
                                               { (yyval.Tpont) = CriaNoTernario(DeclFuncVar1, lineNum, (yyvsp[-4].Tpont), (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1492 "cafezinho.tab.c"
    break;

  case 4:
#line 48 "cafezinho.y"
                                                                                     { (yyval.Tpont) = CriaNoTernario(DeclFuncVar1, lineNum, (yyvsp[-7].Tpont), (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1498 "cafezinho.tab.c"
    break;

  case 5:
#line 49 "cafezinho.y"
                                   { (yyval.Tpont) = CriaNoTernario(DeclFuncVar2, lineNum, (yyvsp[-3].Tpont), (yyvsp[-1].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1504 "cafezinho.tab.c"
    break;

  case 6:
#line 50 "cafezinho.y"
        {(yyval.Tpont)=NULL;}
#line 1510 "cafezinho.tab.c"
    break;

  case 7:
#line 54 "cafezinho.y"
                     { (yyval.Tpont) = (yyvsp[0].Tpont); }
#line 1516 "cafezinho.tab.c"
    break;

  case 8:
#line 58 "cafezinho.y"
                            { (yyval.Tpont) = (yyvsp[0].Tpont); }
#line 1522 "cafezinho.tab.c"
    break;

  case 9:
#line 59 "cafezinho.y"
                                                                { (yyval.Tpont) = (yyvsp[0].Tpont); }
#line 1528 "cafezinho.tab.c"
    break;

  case 10:
#line 60 "cafezinho.y"
        { (yyval.Tpont)=NULL; }
#line 1534 "cafezinho.tab.c"
    break;

  case 11:
#line 64 "cafezinho.y"
                                                            { (yyval.Tpont) = CriaNo(DeclFunc , lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1540 "cafezinho.tab.c"
    break;

  case 12:
#line 68 "cafezinho.y"
      { (yyval.Tpont)=NULL; }
#line 1546 "cafezinho.tab.c"
    break;

  case 13:
#line 69 "cafezinho.y"
                          { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1552 "cafezinho.tab.c"
    break;

  case 14:
#line 73 "cafezinho.y"
              { (yyval.Tpont)=(yyvsp[-1].Tpont); }
#line 1558 "cafezinho.tab.c"
    break;

  case 15:
#line 74 "cafezinho.y"
                                           { (yyval.Tpont)=(yyvsp[-3].Tpont); }
#line 1564 "cafezinho.tab.c"
    break;

  case 16:
#line 75 "cafezinho.y"
                                          { (yyval.Tpont) = CriaNo(ListaParametrosCont2, lineNum, (yyvsp[-3].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1570 "cafezinho.tab.c"
    break;

  case 17:
#line 76 "cafezinho.y"
                                                                       { (yyval.Tpont) = CriaNo(ListaParametrosCont3, lineNum, (yyvsp[-5].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1576 "cafezinho.tab.c"
    break;

  case 18:
#line 80 "cafezinho.y"
                                                     { (yyval.Tpont) = CriaNo(Bloco, lineNum, (yyvsp[-2].Tpont), (yyvsp[-1].Tpont), NULL); }
#line 1582 "cafezinho.tab.c"
    break;

  case 19:
#line 81 "cafezinho.y"
                                        { (yyval.Tpont)=(yyvsp[-1].Tpont); }
#line 1588 "cafezinho.tab.c"
    break;

  case 20:
#line 85 "cafezinho.y"
        { (yyval.Tpont)=NULL; }
#line 1594 "cafezinho.tab.c"
    break;

  case 21:
#line 86 "cafezinho.y"
                                                { (yyval.Tpont) = CriaNoTernario(ListaDeclVar, lineNum, (yyvsp[-4].Tpont), (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1600 "cafezinho.tab.c"
    break;

  case 22:
#line 87 "cafezinho.y"
                                                                                      { (yyval.Tpont) = CriaNoTernario(VetorDeclVar, lineNum, (yyvsp[-7].Tpont), (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1606 "cafezinho.tab.c"
    break;

  case 23:
#line 91 "cafezinho.y"
          { (yyval.Tpont) = CriaNo(Tipo, lineNum, NULL, NULL, "int"); }
#line 1612 "cafezinho.tab.c"
    break;

  case 24:
#line 92 "cafezinho.y"
          { (yyval.Tpont) = CriaNo(Tipo, lineNum, NULL, NULL, "car"); }
#line 1618 "cafezinho.tab.c"
    break;

  case 25:
#line 96 "cafezinho.y"
              { (yyval.Tpont) = (yyvsp[0].Tpont); }
#line 1624 "cafezinho.tab.c"
    break;

  case 26:
#line 97 "cafezinho.y"
                           { (yyval.Tpont) = CriaNo(ListaComando, lineNum, (yyvsp[-1].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1630 "cafezinho.tab.c"
    break;

  case 27:
#line 101 "cafezinho.y"
                   { (yyval.Tpont)=NULL; }
#line 1636 "cafezinho.tab.c"
    break;

  case 28:
#line 102 "cafezinho.y"
                        { (yyval.Tpont)=(yyvsp[-1].Tpont); }
#line 1642 "cafezinho.tab.c"
    break;

  case 29:
#line 103 "cafezinho.y"
                                { (yyval.Tpont) = CriaNo(Retorne, lineNum, (yyvsp[-1].Tpont), NULL, NULL); }
#line 1648 "cafezinho.tab.c"
    break;

  case 30:
#line 104 "cafezinho.y"
                                   { (yyval.Tpont) = CriaNo(Leia, lineNum, (yyvsp[-1].Tpont), NULL, NULL); }
#line 1654 "cafezinho.tab.c"
    break;

  case 31:
#line 105 "cafezinho.y"
                                { (yyval.Tpont) = CriaNo(Escreva, lineNum, (yyvsp[-1].Tpont), NULL, NULL); }
#line 1660 "cafezinho.tab.c"
    break;

  case 32:
#line 106 "cafezinho.y"
                                            { (yyval.Tpont) = CriaNo(EscrevaC, lineNum, NULL, NULL, NULL); }
#line 1666 "cafezinho.tab.c"
    break;

  case 33:
#line 107 "cafezinho.y"
                             { (yyval.Tpont) = CriaNo(NovaLinha, lineNum, NULL, NULL, NULL); }
#line 1672 "cafezinho.tab.c"
    break;

  case 34:
#line 108 "cafezinho.y"
                                                           {{ (yyval.Tpont) = CriaNo(Se, lineNum, (yyvsp[-3].Tpont), (yyvsp[0].Tpont), NULL); }}
#line 1678 "cafezinho.tab.c"
    break;

  case 35:
#line 109 "cafezinho.y"
                                                                         { (yyval.Tpont) = CriaNoTernario(SeSenao, lineNum, (yyvsp[-5].Tpont), (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1684 "cafezinho.tab.c"
    break;

  case 36:
#line 110 "cafezinho.y"
                                                                   { (yyval.Tpont) = CriaNo(Enquanto, lineNum, (yyvsp[-3].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1690 "cafezinho.tab.c"
    break;

  case 37:
#line 111 "cafezinho.y"
            { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1696 "cafezinho.tab.c"
    break;

  case 38:
#line 115 "cafezinho.y"
                 { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1702 "cafezinho.tab.c"
    break;

  case 39:
#line 119 "cafezinho.y"
               { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1708 "cafezinho.tab.c"
    break;

  case 40:
#line 120 "cafezinho.y"
                                  { (yyval.Tpont) = CriaNo(Atribuir, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1714 "cafezinho.tab.c"
    break;

  case 41:
#line 124 "cafezinho.y"
             { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1720 "cafezinho.tab.c"
    break;

  case 42:
#line 125 "cafezinho.y"
                                                   { (yyval.Tpont) = CriaNoTernario(SeTernario, lineNum, (yyvsp[-4].Tpont), (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1726 "cafezinho.tab.c"
    break;

  case 43:
#line 129 "cafezinho.y"
                        { (yyval.Tpont) = CriaNo(Ou, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1732 "cafezinho.tab.c"
    break;

  case 44:
#line 130 "cafezinho.y"
              { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1738 "cafezinho.tab.c"
    break;

  case 45:
#line 134 "cafezinho.y"
                       { (yyval.Tpont) = CriaNo(And, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1744 "cafezinho.tab.c"
    break;

  case 46:
#line 135 "cafezinho.y"
             { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1750 "cafezinho.tab.c"
    break;

  case 47:
#line 139 "cafezinho.y"
                              { (yyval.Tpont) = CriaNo(IgualIgual, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1756 "cafezinho.tab.c"
    break;

  case 48:
#line 140 "cafezinho.y"
                                 { (yyval.Tpont) = CriaNo(Diferente, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1762 "cafezinho.tab.c"
    break;

  case 49:
#line 141 "cafezinho.y"
                {   (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1768 "cafezinho.tab.c"
    break;

  case 50:
#line 145 "cafezinho.y"
                              { (yyval.Tpont) = CriaNo(Menor, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1774 "cafezinho.tab.c"
    break;

  case 51:
#line 146 "cafezinho.y"
                              { (yyval.Tpont) = CriaNo(Maior, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1780 "cafezinho.tab.c"
    break;

  case 52:
#line 147 "cafezinho.y"
                                   { (yyval.Tpont) = CriaNo(MaiorIgual, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1786 "cafezinho.tab.c"
    break;

  case 53:
#line 148 "cafezinho.y"
                                   { (yyval.Tpont) = CriaNo(MenorIgual, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1792 "cafezinho.tab.c"
    break;

  case 54:
#line 149 "cafezinho.y"
              { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1798 "cafezinho.tab.c"
    break;

  case 55:
#line 152 "cafezinho.y"
                           { (yyval.Tpont) = CriaNo(Mais, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1804 "cafezinho.tab.c"
    break;

  case 56:
#line 153 "cafezinho.y"
                            { (yyval.Tpont) = CriaNo(Menos, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1810 "cafezinho.tab.c"
    break;

  case 57:
#line 154 "cafezinho.y"
              { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1816 "cafezinho.tab.c"
    break;

  case 58:
#line 158 "cafezinho.y"
                           { (yyval.Tpont) = CriaNo(Mult, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1822 "cafezinho.tab.c"
    break;

  case 59:
#line 159 "cafezinho.y"
                              { (yyval.Tpont) = CriaNo(Divisao, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1828 "cafezinho.tab.c"
    break;

  case 60:
#line 160 "cafezinho.y"
                           { (yyval.Tpont) = CriaNo(Resto, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), NULL); }
#line 1834 "cafezinho.tab.c"
    break;

  case 61:
#line 161 "cafezinho.y"
             { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1840 "cafezinho.tab.c"
    break;

  case 62:
#line 165 "cafezinho.y"
                     { (yyval.Tpont) = CriaNo(Oposto, lineNum, (yyvsp[0].Tpont), NULL, NULL); }
#line 1846 "cafezinho.tab.c"
    break;

  case 63:
#line 166 "cafezinho.y"
                          { (yyval.Tpont) = CriaNo(Negacao, lineNum, (yyvsp[0].Tpont), NULL, NULL); }
#line 1852 "cafezinho.tab.c"
    break;

  case 64:
#line 167 "cafezinho.y"
               { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1858 "cafezinho.tab.c"
    break;

  case 65:
#line 171 "cafezinho.y"
                                           { (yyval.Tpont) = CriaNo(IdentificadorCEC, lineNum, (yyvsp[-1].Tpont), NULL, NULL); }
#line 1864 "cafezinho.tab.c"
    break;

  case 66:
#line 172 "cafezinho.y"
         { (yyval.Tpont) = CriaNo(Identificador, lineNum, NULL, NULL, NULL); }
#line 1870 "cafezinho.tab.c"
    break;

  case 67:
#line 176 "cafezinho.y"
                                                 { (yyval.Tpont) = CriaNo(IdentificadorL, lineNum, (yyvsp[-1].Tpont), NULL, NULL); }
#line 1876 "cafezinho.tab.c"
    break;

  case 68:
#line 177 "cafezinho.y"
                                        { (yyval.Tpont) = CriaNo(Identificador, lineNum, NULL, NULL, NULL); }
#line 1882 "cafezinho.tab.c"
    break;

  case 69:
#line 178 "cafezinho.y"
                                           { (yyval.Tpont) = CriaNo(IdentificadorCEC, lineNum, (yyvsp[-1].Tpont), NULL, NULL); }
#line 1888 "cafezinho.tab.c"
    break;

  case 70:
#line 179 "cafezinho.y"
         { (yyval.Tpont) = CriaNo(Identificador, lineNum, NULL, NULL, yytext); }
#line 1894 "cafezinho.tab.c"
    break;

  case 71:
#line 180 "cafezinho.y"
               { (yyval.Tpont) = CriaNo(ConstCar, lineNum, NULL, NULL, yytext); }
#line 1900 "cafezinho.tab.c"
    break;

  case 72:
#line 181 "cafezinho.y"
               { (yyval.Tpont) = CriaNo(ConstInt, lineNum, NULL, NULL, yytext); }
#line 1906 "cafezinho.tab.c"
    break;

  case 73:
#line 182 "cafezinho.y"
                                          { (yyval.Tpont)=(yyvsp[-1].Tpont); }
#line 1912 "cafezinho.tab.c"
    break;

  case 74:
#line 186 "cafezinho.y"
                 { (yyval.Tpont)=(yyvsp[0].Tpont); }
#line 1918 "cafezinho.tab.c"
    break;

  case 75:
#line 187 "cafezinho.y"
                                  { (yyval.Tpont) = CriaNo(Virgula, lineNum, (yyvsp[-2].Tpont), (yyvsp[0].Tpont), yytext); }
#line 1924 "cafezinho.tab.c"
    break;


#line 1928 "cafezinho.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 190 "cafezinho.y"


int main(int argc, char** argv){
   if(argc!=2)
        yyerror("Uso correto: ./cafezinho nome_arq_entrada.txt");
   yyin=fopen(argv[1], "r");
   if(!yyin)
        yyerror("arquivo não pode ser aberto\n");
    if (yyparse() == 0) {
        printf("Análise sintática concluída com sucesso.\n");
    }

}

void yyerror(char const * s) {
        if(tipoErro==0)
    {
        printf("%s NA LINHA %d - token: %s\n", s, lineNum, yytext);
    }
    else
    {
        printf("Erro sintatico proximo a %s ", yytext);
        printf(" - linha: %d \n", lineNum);
        tipoErro=1;
    }
    exit(1);

}

void walkTree(TOperador* raiz){
    if(raiz){
        printOperator(raiz, nomeOperador);
        printf("%s", nomeOperador);
            printf("filho 1\n");
        walkTree(raiz->t1);
            printf("end filho 1 \nfilho 2\n");
        walkTree(raiz->t2);
            printf("end filho 2\n");
        walkTree(raiz->t3);
        }
}
TOperador* CriaNo(TypeOperators typeOperator, int line, TOperador* t1, TOperador* t2, char* Tlexema){
    
    TOperador* aux = (TOperador*) malloc(sizeof(TOperador));
    if (aux){
        //printf("entrei aqui\n");
        aux->typeOperator=typeOperator;
        aux->line=line;
        aux->t1=t1;
        aux->t2=t2;
        aux->t3=NULL;
        if(Tlexema){
            aux->Tlexema= (char*)malloc(strlen(Tlexema)+1);
            strcpy(aux->Tlexema, Tlexema);
        }
        return(aux);
    }
    return(NULL);
}
TOperador* CriaNoTernario(TypeOperators typeOperator, int line, TOperador* t1, TOperador* t2,TOperador* t3, char* Tlexema){
    
    TOperador* aux = (TOperador*) malloc(sizeof(TOperador));
    if (aux){
        //printf("entrei aqui\n");
        aux->typeOperator=typeOperator;
        aux->line=line;
        aux->t1=t1;
        aux->t2=t2;
        aux->t3=t3;
        if(Tlexema){
            aux->Tlexema= (char*)malloc(strlen(Tlexema)+1);
            strcpy(aux->Tlexema, Tlexema);
        }
        return(aux);
    }
    return(NULL);
}
void printOperator(TOperador* no, char* nomeOperador){
    switch(no->typeOperator){
        case Programa:
        strcpy(nomeOperador,"programa\n");
        break;
        case Se:
        sprintf(nomeOperador, "Se - LINHA: %d\n", no->line);
        break;
        case Enquanto :
        sprintf(nomeOperador, "Enquanto - LINHA: %d\n", no->line);
        break;
        case Do:
        sprintf(nomeOperador, "Do - LINHA: %d\n", no->line);
        break;
        case ConstCar:
        sprintf(nomeOperador, "%s ConstCar- LINHA: %d\n", no->Tlexema,no->line);
        break;
        case ConstInt:
        sprintf(nomeOperador, "%s ConstInt- LINHA: %d\n", no->Tlexema,no->line);
        break;
        case Num:
        sprintf(nomeOperador, "%s NUM- LINHA: %d\n", no->Tlexema,no->line);
        break;
        case Mais:
        sprintf(nomeOperador, "+ - LINHA: %d\n", no->line);
        break;
        case Menos:
        sprintf(nomeOperador, "- - LINHA: %d\n", no->line);
        break;
        case Mult:
        sprintf(nomeOperador, "* - LINHA: %d\n", no->line);
        break;
        case Divisao:
        sprintf(nomeOperador, "/ - LINHA: %d\n", no->line);
        break;
        case Resto:
        sprintf(nomeOperador, "%% - LINHA: %d\n", no->line);
        break;
        case Menor:
        sprintf(nomeOperador, "< - LINHA: %d\n", no->line);
        break;
        case Maior:
        sprintf(nomeOperador, "> - LINHA: %d\n", no->line);
        break;
        case Igual:
        sprintf(nomeOperador, "== - LINHA: %d\n", no->line);
        break;
        case MenorIgual:
        sprintf(nomeOperador, "<= - LINHA: %d\n", no->line);
        break;
        case MaiorIgual:
        sprintf(nomeOperador, ">= - LINHA: %d\n", no->line);
        break;
        case Identificador:
        sprintf(nomeOperador, "ID - LINHA: %d\n", no->line);
        break;
        case Atribuir:
        sprintf(nomeOperador, "= - LINHA: %d\n", no->line);
        break;
        case DeclFuncVar:
        sprintf(nomeOperador, "DeclFuncVar - LINHA: %d\n", no->line);
        break;
        case Escreva:
        sprintf(nomeOperador, "Escreva Expr - LINHA: %d\n", no->line);
        break;
        case EscrevaC:
        sprintf(nomeOperador, "Escreva Cadeia - LINHA: %d\n", no->line);
        break;
        case Bloco:
        sprintf(nomeOperador, "Bloco - LINHA: %d\n", no->line);
        break;
        case ListaComando:
        sprintf(nomeOperador, "ListaComando - LINHA: %d\n", no->line);
        break;
        case lstStmt:
        sprintf(nomeOperador, "Faze de Teste - LINHA: %d\n", no->line);
        break;
        case IdentificadorCEC:
        sprintf(nomeOperador, "ID[Expr] - LINHA: %d\n", no->line);
        break;
        case IdentificadorL:
        sprintf(nomeOperador, "ID(ListExpr) - LINHA: %d\n", no->line);
        break;
        case Negacao:
        sprintf(nomeOperador, "! - LINHA: %d\n", no->line);
        break;
        case Oposto:
        sprintf(nomeOperador, "- Unario - LINHA: %d\n", no->line);
        break;
        case IgualIgual:
        sprintf(nomeOperador, "== - LINHA: %d\n", no->line);
        break;
        case Diferente:
        sprintf(nomeOperador, "!= - LINHA: %d\n", no->line);
        break;
        case And:
        sprintf(nomeOperador, "E - LINHA: %d\n", no->line);
        break;
        case Ou:
        sprintf(nomeOperador, "Ou - LINHA: %d\n", no->line);
        break;
        case SeTernario:
        sprintf(nomeOperador, "E ? E : E - LINHA: %d\n", no->line);
        break;
        case SeSenao:
        sprintf(nomeOperador, "SeSenao - LINHA: %d\n", no->line);
        break;
        case NovaLinha:
        sprintf(nomeOperador, "NovaLinha  - LINHA: %d\n", no->line);
        break;
        case Leia:
        sprintf(nomeOperador, "Leia  - LINHA: %d\n", no->line);
        break;
        case Retorne:
        sprintf(nomeOperador, "Retorne  - LINHA: %d\n", no->line);
        break;
        case Tipo:
        sprintf(nomeOperador, "Tipo %s  - LINHA: %d\n",no->Tlexema, no->line);
        break;
        case VetorDeclVar:
        sprintf(nomeOperador, "VetorDeclVar - LINHA: %d\n",no->line);
        break;
        case ListaDeclVar:
        sprintf(nomeOperador, "ListaDeclVar - LINHA: %d\n",no->line);
        break;
        case ListaParametrosCont2:
        sprintf(nomeOperador, "Tipo ID VIRGULA  ListaParametrosCont - LINHA: %d\n",no->line);
        break;
        case ListaParametrosCont3:
        sprintf(nomeOperador, "Tipo ID COLCH_E  COLCH_D VIRGULA ListaParametrosCont - LINHA: %d\n",no->line);
        break;
        case DeclFunc:
        sprintf(nomeOperador, "DeclFunc - LINHA: %d\n",no->line);
        break;
        case DeclFuncVar1:
        sprintf(nomeOperador, "DeclFuncVar1 - LINHA: %d\n",no->line);
        break;
        case DeclFuncVar2:
        sprintf(nomeOperador, "DeclFuncVar2 - LINHA: %d\n",no->line);
        break;
        case DeclFuncVar3:
        sprintf(nomeOperador, "DeclFuncVar3 - LINHA: %d\n",no->line);
        break;
        case Virgula:
        sprintf(nomeOperador, ", - LINHA: %d\n",no->line);
        break;
    }
}
