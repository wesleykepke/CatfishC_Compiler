/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 22 "../parser/cParser.y" /* yacc.c:339  */

	// # includes 
	#include <climits>
	#include <fstream>
	#include <iostream>
	#include <string>
	#include "../classes/symbolTableEntry.h"
	#include "../classes/symbolTable.h"
	#include "../lexer/Escape_Sequences_Colors.h"
	#include "../parser/nodes/nodeClassList.h"

	// extern variables and forward declarations 
	extern int yylineno;
	extern int colPosition;  
	extern bool YFLAG; 
	extern std::ofstream outY;
	extern std::ofstream outG;
	extern std::ofstream outA;
	extern bool inInsertMode;
	extern symbolTable table;
	std::string intTC();
	std::string labelTC();
	int yylex(void);
	void yyerror(const char* errorMsg);
	void registerNode(std::ofstream &out, astNode* ptr);
	void outputNode(std::ofstream &out, astNode* ptr);
	void outputTerminal(std::ofstream &out, std::string name, int id);

	// global variables 
	std::vector< std::vector<int> > funcParams;
	std::vector<symbolTableEntry*> funcCallingParams; 
	int unaryOperatorChosen = -1;
	symbolTableEntry* currentFunc;
	int intTicket = 0;
	int labelCount = 0; 

	// root of the ast
	astNode* astRoot = NULL; 
	int unique = 0;

#line 107 "cParser.tab.c" /* yacc.c:339  */

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
   by #include "cParser.tab.h".  */
#ifndef YY_YY_CPARSER_TAB_H_INCLUDED
# define YY_YY_CPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 67 "../parser/cParser.y" /* yacc.c:355  */

	typedef union {
		char _char;
		long long _num;
		long double _dec; // decimal
		char _str[256];
		class symbolTableEntry* _ste;   
	} vals;

	typedef struct {
		int valType; 
		vals val;
		class astNode* astPtr;
	} node;

#line 153 "cParser.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INTEGER_CONSTANT = 259,
    FLOATING_CONSTANT = 260,
    ENUMERATION_CONSTANT = 261,
    CHARACTER_CONSTANT = 262,
    STRING_LITERAL = 263,
    SIZEOF = 264,
    PTR_OP = 265,
    INC_OP = 266,
    DEC_OP = 267,
    LEFT_OP = 268,
    RIGHT_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    AND_OP = 274,
    OR_OP = 275,
    MUL_ASSIGN = 276,
    DIV_ASSIGN = 277,
    MOD_ASSIGN = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    LEFT_ASSIGN = 281,
    RIGHT_ASSIGN = 282,
    AND_ASSIGN = 283,
    XOR_ASSIGN = 284,
    OR_ASSIGN = 285,
    TYPEDEF_NAME = 286,
    PLUS = 287,
    MINUS = 288,
    MULT = 289,
    DIV = 290,
    MOD = 291,
    SEMI = 292,
    COLON = 293,
    COMMA = 294,
    AMP = 295,
    ASSIGN = 296,
    TILDE = 297,
    PIPE = 298,
    CARROT = 299,
    DOT = 300,
    BANG = 301,
    QUESTION = 302,
    LPAREN = 303,
    LBRACK = 304,
    LCURL = 305,
    RPAREN = 306,
    RBRACK = 307,
    RCURL = 308,
    LTHAN = 309,
    GTHAN = 310,
    TYPEDEF = 311,
    EXTERN = 312,
    STATIC = 313,
    AUTO = 314,
    REGISTER = 315,
    CHAR = 316,
    SHORT = 317,
    INT = 318,
    LONG = 319,
    SIGNED = 320,
    UNSIGNED = 321,
    FLOAT = 322,
    DOUBLE = 323,
    CONST = 324,
    VOLATILE = 325,
    VOID = 326,
    STRUCT = 327,
    UNION = 328,
    ENUM = 329,
    ELIPSIS = 330,
    RANGE = 331,
    CASE = 332,
    DEFAULT = 333,
    IF = 334,
    ELSE = 335,
    SWITCH = 336,
    WHILE = 337,
    DO = 338,
    FOR = 339,
    GOTO = 340,
    CONTINUE = 341,
    BREAK = 342,
    RETURN = 343
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 87 "../parser/cParser.y" /* yacc.c:355  */

	node* n;

#line 258 "cParser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 273 "cParser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1443

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  394

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   174,   174,   184,   205,   233,   241,   255,   281,   310,
     341,   378,   404,   436,   458,   486,   507,   532,   553,   578,
     599,   627,   644,   661,   678,   695,   715,   732,   749,   766,
     783,   800,   817,   835,   852,   869,   877,   885,   896,   913,
     932,   940,   948,   959,   967,   978,   986,   997,  1005,  1016,
    1037,  1090,  1101,  1109,  1117,  1125,  1136,  1144,  1155,  1163,
    1171,  1182,  1190,  1198,  1209,  1217,  1228,  1236,  1247,  1269,
    1297,  1319,  1348,  1377,  1426,  1456,  1497,  1534,  1556,  1581,
    1606,  1638,  1659,  1687,  1695,  1706,  1714,  1725,  1757,  1778,
    1789,  1797,  1808,  1829,  1858,  1894,  1902,  1913,  1921,  1932,
    1940,  1948,  1959,  1968,  1976,  1984,  1992,  2000,  2008,  2016,
    2024,  2035,  2043,  2051,  2059,  2067,  2076,  2087,  2095,  2103,
    2114,  2122,  2141,  2165,  2194,  2223,  2257,  2265,  2273,  2280,
    2287,  2293,  2299,  2320,  2348,  2385,  2430,  2471,  2507,  2552,
    2593,  2637,  2680,  2728,  2771,  2818,  2865,  2921,  2929,  2937,
    2945,  2953,  2964,  2985,  3017,  3038,  3070,  3084,  3096,  3108,
    3121,  3136,  3151,  3159,  3167,  3175,  3183,  3194,  3202,  3213,
    3224,  3232,  3243,  3251,  3263,  3271,  3282,  3290,  3301,  3309,
    3320,  3342,  3371,  3403,  3424,  3453,  3482,  3511,  3543,  3551,
    3559,  3570,  3591,  3623,  3656,  3678,  3718,  3782,  3818,  3826,
    3837,  3859,  3886,  3911,  3938,  3946,  3957,  3973,  3989,  4005,
    4021,  4037,  4056,  4083,  4120,  4128,  4170,  4178,  4186,  4240,
    4293,  4304,  4315,  4323,  4337,  4351,  4365,  4382,  4399,  4416,
    4430,  4450
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_CONSTANT",
  "FLOATING_CONSTANT", "ENUMERATION_CONSTANT", "CHARACTER_CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPEDEF_NAME", "PLUS", "MINUS", "MULT", "DIV", "MOD", "SEMI", "COLON",
  "COMMA", "AMP", "ASSIGN", "TILDE", "PIPE", "CARROT", "DOT", "BANG",
  "QUESTION", "LPAREN", "LBRACK", "LCURL", "RPAREN", "RBRACK", "RCURL",
  "LTHAN", "GTHAN", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE",
  "CONST", "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELIPSIS",
  "RANGE", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR",
  "GOTO", "CONTINUE", "BREAK", "RETURN", "$accept", "start_unit",
  "translation_unit", "external_declaration", "function_definition",
  "declaration", "declaration_list", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "init_declarator_list", "init_declarator",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "set_insert_push",
  "set_lookup_pop", "set_lookup", "set_insert", "open_curl", "close_curl",
  "statement_list", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "constant_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "unary_operator", "postfix_expression",
  "primary_expression", "argument_expression_list", "constant", "string",
  "identifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

#define YYPACT_NINF -199

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-199)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     651,  -199,  -199,   117,    90,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,    11,    22,   651,  -199,  -199,  -199,    21,
     950,   950,   950,  -199,    16,  -199,   -22,   136,    60,  -199,
    -199,  -199,   117,     5,    56,    42,  -199,  -199,  -199,    -6,
    -199,   202,  -199,  -199,  -199,   256,    75,   348,   -22,  -199,
     950,  1300,   774,   136,  -199,  -199,  -199,   -18,  -199,    69,
      56,  -199,    90,  -199,   -22,  -199,   256,   256,  1346,  -199,
      78,   256,  -199,  -199,  -199,  -199,   950,  -199,    21,  -199,
      65,    83,   107,  -199,    56,  -199,  -199,  -199,  -199,  -199,
    1181,  1227,  1227,  -199,  -199,  -199,  -199,  -199,  -199,   563,
    -199,  -199,   102,     6,   137,   145,   147,   140,    47,   163,
     234,   264,   249,  -199,  -199,  1238,    95,  -199,  -199,  -199,
    -199,    56,  -199,  1238,     1,  -199,   179,  1042,  -199,  -199,
    -199,  -199,  -199,  1238,    63,  -199,   185,  1369,   901,   505,
    -199,  -199,   607,   785,  -199,    93,  -199,   254,  -199,  1231,
     -12,  -199,   563,  -199,  1238,  -199,  -199,     3,   200,    79,
    -199,  -199,   535,  -199,  1238,  1238,  1238,  1238,  1238,  1238,
    1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,
    1238,  1238,  1238,  -199,    56,  -199,  -199,    56,   611,   206,
    -199,  -199,  -199,  1042,  -199,  -199,  -199,  -199,    78,  1238,
    -199,  -199,   505,  -199,  1238,   226,   220,   224,   227,   505,
     240,    56,   262,   267,  1061,  -199,  -199,  -199,  -199,   391,
    -199,  -199,  -199,   167,   275,  -199,  -199,   242,   288,  -199,
     263,   254,  1324,   835,  -199,  -199,    56,  -199,   290,  1276,
     257,  -199,  1238,  1238,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  1238,   137,   297,   145,
     147,   140,    47,   163,   163,   234,   234,   234,   234,   264,
     264,   249,   249,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
     151,  1238,  -199,    76,  -199,  -199,  -199,  -199,   448,   305,
     505,  1238,  1238,  1238,   270,  1107,   309,  -199,  -199,  -199,
     187,  -199,  -199,  -199,   505,  -199,  -199,  -199,  -199,   303,
    -199,   306,  -199,  -199,  -199,  -199,  -199,  1238,  1238,  -199,
      96,   723,  -199,  -199,   505,  -199,   174,   189,   194,   311,
    1124,   232,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,   505,   505,   505,  1238,   846,
     252,  1170,   281,  -199,  -199,   203,   505,   210,   895,   944,
     255,   505,   327,  -199,   505,   505,   211,   505,   214,   993,
    -199,  -199,  -199,  -199,   505,  -199,   505,   505,   219,  -199,
    -199,  -199,   505,  -199
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   231,    37,    77,     0,    25,    24,    23,    21,    22,
      27,    28,    29,    30,    33,    34,    31,    32,    38,    39,
      26,    43,    44,     0,     0,     2,     3,     5,     6,     0,
      15,    17,    19,    35,     0,    36,   129,    68,     0,    70,
      81,    79,    78,     0,     0,    63,     1,     4,    11,     0,
      47,   129,    16,    18,    20,     0,    42,   130,   129,     7,
       0,   128,     0,    69,    82,    80,    71,     0,    64,    66,
       0,    12,     0,   128,   129,     9,    52,    54,     0,    45,
       0,     0,   122,   129,   128,     8,     0,   128,     0,    74,
      88,     0,    83,    85,     0,   226,   228,   229,   227,   230,
       0,     0,     0,   208,   209,   207,   206,   210,   211,     0,
      72,   169,     0,   167,   170,   172,   174,   176,   178,   180,
     183,   188,   191,   194,   198,     0,   200,   212,   221,   222,
     220,     0,    61,     0,     0,    48,    49,     0,    10,    53,
      55,    41,    46,     0,     0,    56,    58,     0,   128,     0,
     128,    13,     0,     0,    87,    99,    89,   100,    75,     0,
       0,    90,     0,   204,     0,   201,   202,    97,     0,     0,
     152,   154,   198,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,     0,   218,   219,     0,     0,     0,
      65,    67,    62,     0,   129,    92,    59,    51,     0,     0,
      40,   127,     0,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   111,   113,   112,     0,
     114,   115,   116,     0,   220,    14,   107,     0,     0,   103,
       0,   101,     0,     0,    84,    86,     0,    76,     0,     0,
      99,    98,     0,     0,   223,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   156,     0,   171,     0,   173,
     175,   177,   179,   181,   182,   186,   187,   184,   185,   189,
     190,   192,   193,   195,   196,   197,   217,   216,   214,   224,
       0,     0,    95,     0,    50,    57,    60,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   149,   150,
       0,   131,   133,   121,     0,   108,   102,   104,   109,     0,
     105,     0,    91,   205,   199,   153,   155,     0,     0,   215,
       0,     0,    93,   127,     0,   119,     0,     0,     0,     0,
       0,     0,   147,   151,   123,   117,   110,   106,   168,   225,
     213,    94,    96,   125,   118,     0,     0,     0,     0,     0,
       0,     0,   134,   136,   137,     0,     0,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
     135,   138,   140,   141,     0,   143,     0,     0,     0,   142,
     144,   145,     0,   146
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,  -199,  -199,   340,  -199,   -45,   -41,    18,  -199,   154,
     231,  -199,  -199,   286,  -199,   298,   -58,   -64,  -199,   161,
    -199,   302,   245,     7,   -35,    29,  -199,   -59,  -199,   221,
    -199,  -198,  -199,   223,   -84,  -147,   -24,  -199,  -199,   186,
    -199,    40,    66,   -57,  -199,  -199,   169,  -199,  -199,  -199,
    -102,  -121,  -199,   -32,   -86,  -199,   208,   207,   212,   213,
     209,   157,    97,   158,   160,  -116,   -16,  -199,  -199,  -199,
    -199,  -199,  -199,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    58,    90,    30,    31,
      32,    33,    34,    78,    49,    50,    79,    80,   144,   145,
      35,    67,    68,    36,    37,    38,    42,   237,    92,    93,
     160,   204,   293,   168,   238,   157,   225,   226,   227,   228,
      83,   297,    94,    60,    84,   344,   229,   230,   231,   232,
     233,   170,   266,   171,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   172,   125,   126,   127,
     290,   128,   129,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    86,    91,    63,    39,   292,   156,   169,   241,   193,
      74,    43,   139,   140,     1,    87,   205,    86,    29,     1,
     142,   131,    46,    45,     1,    39,   174,   246,    57,    39,
     111,    71,    41,    72,    56,   132,    51,     3,    39,   247,
     131,   150,   148,    29,    69,   167,   124,   201,    52,    53,
      54,   249,   153,   175,   202,     3,    66,   206,    48,     1,
     169,    44,   169,     1,   180,   181,    55,   240,     1,     4,
      69,    65,    39,   268,   283,   284,   285,   289,    88,   136,
      39,     1,   205,   251,   163,   165,   166,   146,    39,   142,
      39,    86,    70,     1,   161,   136,     1,   154,   167,     3,
     207,   111,   208,   241,    88,   194,   195,   196,     4,   124,
     133,   111,     3,   152,   153,   331,   143,   124,   253,   155,
      63,   111,   310,   296,     3,    81,     4,   124,   299,   332,
     254,    69,   325,   352,   158,   253,   324,   124,     4,   137,
     197,   152,   153,   198,  -128,   326,   159,   294,   350,   234,
     149,     3,    39,   151,   173,    39,   176,   321,   124,    43,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   111,   182,   183,
     179,   155,   111,   319,    61,    62,    18,    19,   177,   330,
     328,   178,   199,   124,   286,   304,   250,   287,   124,   336,
     337,   338,   329,   341,   313,   312,   253,   349,    39,    76,
     205,   111,   234,   253,   212,   146,   235,   184,   185,   234,
      73,   306,    59,   209,   343,   355,   253,   124,   253,   234,
      76,    76,    76,   253,    40,    76,   124,    75,   360,   -49,
     356,   -49,   253,    73,    85,   357,   322,   186,   187,   253,
     253,   252,    57,   253,   372,   291,   365,   367,   253,   370,
     138,   374,   384,    76,   300,   386,   376,   378,   301,   361,
     392,   253,   302,    64,   312,   303,   335,   388,   250,   275,
     276,   277,   278,   190,   191,   192,    77,     2,   305,   368,
     345,   253,   379,   315,   253,   348,   188,   189,   234,   307,
     234,    76,   242,   243,   308,   249,   153,    77,    77,    77,
     354,   124,    77,   314,   234,   317,    76,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   362,   363,   364,   234,   327,   253,   273,   274,   316,
      77,   323,   373,   334,   279,   280,   342,   380,   281,   282,
     382,   383,   339,   385,   346,   234,   234,   234,   347,   358,
     389,   371,   390,   391,   381,    47,   234,   147,   393,   295,
     135,   234,   134,   353,   234,   234,   200,   234,    77,  -126,
     245,   298,   267,   269,   234,   248,   234,   234,   272,   270,
       0,   271,   234,    77,     1,    95,    96,    97,    98,    99,
     100,    82,   101,   102,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   103,   104,   105,     0,     0,   213,     0,
       0,   106,     0,   107,     0,     0,     0,   108,     0,   109,
       0,    57,     0,     0,   311,     0,     0,     0,     0,     0,
       0,     1,    95,    96,    97,    98,    99,   100,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,   214,   215,
     216,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     103,   104,   105,     0,     0,   213,     0,     0,   106,     0,
     107,     0,     0,     0,   108,     0,   109,     0,    57,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     1,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,   214,   215,   216,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   103,   104,   105,
       0,     0,   213,     0,     0,   106,     0,   107,     0,     0,
       0,   108,     0,   109,     0,    57,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     1,    95,    96,    97,
      98,    99,   100,     0,   101,   102,   265,     0,     0,     0,
       0,     0,   214,   215,   216,     0,   217,   218,   219,   220,
     221,   222,   223,   224,     2,   103,   104,   105,     0,     0,
       0,     0,     0,   106,     0,   107,     0,     0,     0,   108,
       1,   109,     0,     0,     1,    95,    96,    97,    98,    99,
     100,     0,   101,   102,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     2,     0,
       0,     3,     0,   103,   104,   105,     0,     0,     0,     0,
       0,   106,     0,   107,     1,   152,   153,   108,   236,   109,
       0,     0,   288,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     2,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     1,    95,    96,    97,
      98,    99,   100,     0,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,     0,     0,   106,     0,   107,     0,     0,     0,   108,
       0,   109,     0,   203,     0,     0,   351,     1,    95,    96,
      97,    98,    99,   100,     0,   101,   102,     0,     1,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,   106,     0,   107,   103,   104,   105,
     108,     0,   109,     0,     0,   106,   110,   107,     0,     0,
       0,   108,     0,   109,     0,     0,     0,   239,     1,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,     1,
      95,    96,    97,    98,    99,   100,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,     0,     0,   106,     0,   107,   103,   104,
     105,   108,     0,   109,     0,     0,   106,   320,   107,     0,
       0,     0,   108,     0,   109,     0,     0,   366,     1,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,     0,  -129,     0,     0,   106,     0,   107,     0,     0,
       0,   108,     0,   109,     0,     0,   375,     1,    95,    96,
      97,    98,    99,   100,   211,   101,   102,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,   103,   104,   105,     0,
       0,     2,     0,     0,   106,     0,   107,     0,     0,     0,
     108,     0,   109,     0,     0,   377,     1,    95,    96,    97,
      98,    99,   100,     0,   101,   102,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   103,   104,   105,     0,     0,
       0,     0,     0,   106,     0,   107,     0,     0,     0,   108,
       0,   109,     0,     0,   387,     1,    95,    96,    97,    98,
      99,   100,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,    95,    96,    97,    98,    99,
     100,     0,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     0,   106,     0,   107,     0,     0,     0,   108,     0,
     109,     0,   203,   103,   104,   105,     0,     0,   309,     0,
       0,   106,     0,   107,     0,     0,     0,   108,     0,   109,
       1,    95,    96,    97,    98,    99,   100,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     1,    95,    96,
      97,    98,    99,   100,     0,   101,   102,     0,     0,   103,
     104,   105,     0,     0,   340,     0,     0,   106,     0,   107,
       0,     0,     0,   108,     0,   109,   103,   104,   105,     0,
       0,   359,     0,     0,   106,     0,   107,     0,     0,     0,
     108,     0,   109,     1,    95,    96,    97,    98,    99,   100,
       0,   101,   102,     0,     1,    95,    96,    97,    98,    99,
     100,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,     0,   369,     0,     0,
     106,     0,   107,   103,   104,   105,   108,     0,   109,     0,
       0,   106,     0,   107,     0,     0,     0,   108,     0,   162,
       1,    95,    96,    97,    98,    99,   100,     0,   101,   102,
       0,     1,    95,    96,    97,    98,    99,   100,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     2,     0,     0,     0,     0,   106,     0,   107,
     103,   104,   105,   108,     0,   164,     0,     0,   106,     0,
     107,     0,     0,     0,   108,     0,   109,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   244,     2,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   249,   153,     0,   236,     0,     0,
       0,     2,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    89,     0,     0,     0,     2,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   318,     0,     2,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   141,
       2,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,   210,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23
};

static const yytype_int16 yycheck[] =
{
       0,    58,    61,    38,     4,   203,    90,   109,   155,   125,
      51,     4,    76,    77,     3,    60,   137,    74,     0,     3,
      78,    39,     0,    23,     3,    25,    20,    39,    50,    29,
      62,    37,     3,    39,    34,    53,    29,    34,    38,    51,
      39,    86,    83,    25,    44,   109,    62,   133,    30,    31,
      32,    48,    49,    47,    53,    34,    51,   143,    37,     3,
     162,    50,   164,     3,    17,    18,    50,   153,     3,    48,
      70,    42,    72,   175,   190,   191,   192,   198,    60,    72,
      80,     3,   203,   167,   100,   101,   102,    80,    88,   147,
      90,   148,    50,     3,    94,    88,     3,    90,   162,    34,
      37,   133,    39,   250,    86,    10,    11,    12,    48,   125,
      41,   143,    34,    48,    49,    39,    38,   133,    39,    90,
     155,   153,   224,   209,    34,    50,    48,   143,   214,    53,
      51,   131,   253,   331,    51,    39,   252,   153,    48,    73,
      45,    48,    49,    48,    49,   266,    39,   204,    52,   149,
      84,    34,   152,    87,    52,   155,    19,   243,   174,   152,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   209,    15,    16,
      40,   152,   214,   242,    48,    49,    69,    70,    43,   291,
      39,    44,   126,   209,   194,   219,   167,   197,   214,   301,
     302,   303,    51,   305,    37,   229,    39,   328,   208,    55,
     331,   243,   212,    39,   148,   208,   150,    54,    55,   219,
      41,   221,    36,    38,    37,    51,    39,   243,    39,   229,
      76,    77,    78,    39,     3,    81,   252,    51,   340,    37,
      51,    39,    39,    41,    58,    51,   246,    13,    14,    39,
      39,    51,    50,    39,    51,    49,   358,   359,    39,   361,
      74,    51,    51,   109,    38,    51,   368,   369,    48,    37,
      51,    39,    48,    42,   298,    48,   300,   379,   249,   182,
     183,   184,   185,    34,    35,    36,    55,    31,    48,    37,
     314,    39,    37,    51,    39,   327,    32,    33,   298,    37,
     300,   147,    48,    49,    37,    48,    49,    76,    77,    78,
     334,   327,    81,    38,   314,    52,   162,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   355,   356,   357,   334,    38,    39,   180,   181,    51,
     109,    51,   366,    38,   186,   187,    37,   371,   188,   189,
     374,   375,    82,   377,    51,   355,   356,   357,    52,    48,
     384,    80,   386,   387,    37,    25,   366,    81,   392,   208,
      72,   371,    70,   333,   374,   375,   131,   377,   147,    31,
     159,   212,   174,   176,   384,   162,   386,   387,   179,   177,
      -1,   178,   392,   162,     3,     4,     5,     6,     7,     8,
       9,    53,    11,    12,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    32,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    -1,    50,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    41,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
       3,    48,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    31,    -1,
      -1,    34,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    42,     3,    48,    49,    46,    51,    48,
      -1,    -1,    51,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    -1,    50,    -1,    -1,    53,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    32,    33,    34,
      46,    -1,    48,    -1,    -1,    40,    52,    42,    -1,    -1,
      -1,    46,    -1,    48,    -1,    -1,    -1,    52,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    42,    32,    33,
      34,    46,    -1,    48,    -1,    -1,    40,    52,    42,    -1,
      -1,    -1,    46,    -1,    48,    -1,    -1,    51,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      -1,    -1,    31,    -1,    -1,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    -1,    -1,    51,     3,     4,     5,
       6,     7,     8,     9,    53,    11,    12,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    32,    33,    34,    -1,
      -1,    31,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    -1,    -1,    51,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    -1,    -1,    51,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,
      48,    -1,    50,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    42,    32,    33,    34,    46,    -1,    48,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    31,    -1,    -1,    -1,    -1,    40,    -1,    42,
      32,    33,    34,    46,    -1,    48,    -1,    -1,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    31,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    51,    -1,    -1,    -1,    31,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    51,    -1,    31,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    53,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    34,    48,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    90,    91,    92,    93,    94,    96,
      97,    98,    99,   100,   101,   109,   112,   113,   114,   162,
      99,   114,   115,   112,    50,   162,     0,    92,    37,   103,
     104,   112,    96,    96,    96,    50,   162,    50,    95,   128,
     132,    48,    49,   113,    99,   114,    51,   110,   111,   162,
      50,    37,    39,    41,    95,   128,    98,    99,   102,   105,
     106,    50,    53,   129,   133,   128,   132,    94,    96,    51,
      96,   116,   117,   118,   131,     4,     5,     6,     7,     8,
       9,    11,    12,    32,    33,    34,    40,    42,    46,    48,
      52,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   160,   161,
     162,    39,    53,    41,   110,   104,   112,   131,   128,   106,
     106,    53,   105,    38,   107,   108,   112,   102,    95,   131,
      94,   131,    48,    49,   112,   114,   123,   124,    51,    39,
     119,   162,    48,   155,    48,   155,   155,   106,   122,   139,
     140,   142,   155,    52,    20,    47,    19,    43,    44,    40,
      17,    18,    15,    16,    54,    55,    13,    14,    32,    33,
      34,    35,    36,   154,    10,    11,    12,    45,    48,   131,
     111,   143,    53,    50,   120,   140,   143,    37,    39,    38,
      53,    53,   131,    37,    77,    78,    79,    81,    82,    83,
      84,    85,    86,    87,    88,   125,   126,   127,   128,   135,
     136,   137,   138,   139,   162,   131,    51,   116,   123,    52,
     143,   124,    48,    49,    75,   118,    39,    51,   122,    48,
     114,   123,    51,    39,    51,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    41,   141,   145,   139,   146,
     147,   148,   149,   150,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   162,   162,    51,   140,
     159,    49,   120,   121,   132,   108,   143,   130,   135,   143,
      38,    48,    48,    48,   125,    48,   162,    37,    37,    37,
     139,    53,   125,    37,    38,    51,    51,    52,    51,   116,
      52,   143,   162,    51,   154,   140,   140,    38,    39,    51,
     139,    39,    53,    53,    38,   125,   139,   139,   139,    82,
      37,   139,    37,    37,   134,   125,    51,    52,   142,   140,
      52,    53,   120,   130,   125,    51,    51,    51,    48,    37,
     139,    37,   125,   125,   125,   139,    51,   139,    37,    37,
     139,    80,    51,   125,    51,    51,   139,    51,   139,    37,
     125,    37,   125,   125,    51,   125,    51,    51,   139,   125,
     125,   125,    51,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   106,   106,   106,   106,   107,   107,   108,   108,
     108,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     127,   127,   128,   128,   128,   128,   129,   130,   131,   132,
     133,   134,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   138,   138,   138,
     138,   138,   139,   139,   140,   140,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   142,   142,   143,
     144,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   150,   150,   150,   150,   150,   151,   151,
     151,   152,   152,   152,   153,   153,   153,   153,   154,   154,
     155,   155,   155,   155,   155,   155,   156,   156,   156,   156,
     156,   156,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   158,   158,   159,   159,   160,   160,   160,   160,
     161,   162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     3,
       4,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     1,     3,     1,
       5,     3,     1,     2,     1,     2,     1,     3,     1,     2,
       3,     4,     5,     2,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     4,     3,     4,     5,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     1,     2,
       1,     3,     1,     3,     4,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       1,     2,     2,     6,     5,     7,     0,     0,     0,     0,
       0,     0,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     7,     8,     7,     8,     8,     9,     3,     2,     2,
       2,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     4,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     4,     3,     3,     2,     2,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1
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
#line 175 "../parser/cParser.y" /* yacc.c:1646  */
    {
			table.popLevelOff();
			outG << "start_unit -> translation_unit;" << std::endl;
			astRoot = (yyvsp[0].n)->astPtr;
			astRoot->gen3AC(); 
		}
#line 1884 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 185 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new translationUnit_Node((yyvsp[0].n)->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "translation_unit : external_declaration;" << std::endl;
				outG << "translation_unit -> external_declaration;" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 1909 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 206 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new translationUnit_Node((yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "translation_unit : translation_unit external_declaration;" << std::endl;
				outG << "translation_unit -> {translation_unit external_declaration};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 1938 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 234 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "external_declaration : function_definition;" << std::endl;
				outG << "external_declaration -> function_definition;" << std::endl;
			}
		}
#line 1950 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 242 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "external_declaration : declaration;" << std::endl;
				outG << "external_declaration -> declaration;" << std::endl;
			}
		}
#line 1962 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 256 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new funcDef_Node(NULL, (yyvsp[-1].n)->astPtr, NULL, (yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "function_definition : declarator compound_statement;" << std::endl;
				outG << "function_definition -> {declarator compound_statement};" << std::endl;
			}
			

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 1992 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 282 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new funcDef_Node(NULL, (yyvsp[-2].n)->astPtr, (yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "function_definition : declarator declaration_list compound_statement;" << std::endl;
				outG << "function_definition -> {declarator declaration_list compound_statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2025 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 311 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "function_definition : declaration_specifiers declarator compound_statement;" << std::endl;
				outG << "function_definition -> {declaration_specifiers declarator compound_statement};" << std::endl;
			}

			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new funcDef_Node((yyvsp[-2].n)->astPtr, (yyvsp[-1].n)->astPtr, NULL, (yyvsp[0].n)->astPtr);



			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2060 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 342 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "function_definition : declaration_specifiers declarator declaration_list compound_statement;" << std::endl;
				outG << "function_definition -> {declaration_specifiers declarator declaration_list compound_statement};" << std::endl;
			}

			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-3].n)->val;
			(yyval.n)->valType = (yyvsp[-3].n)->valType;
			(yyval.n)->astPtr = new funcDef_Node((yyvsp[-3].n)->astPtr, (yyvsp[-2].n)->astPtr, (yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);



			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2095 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 379 "../parser/cParser.y" /* yacc.c:1646  */
    {	
			// output data
			if(YFLAG){
				outY << "declaration : declaration_specifiers SEMI;" << std::endl;
				outG << "declaration -> {declaration_specifiers SEMI};" << std::endl;
			}		
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new declaration_Node((yyvsp[-1].n)->astPtr, NULL);

	

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
		}
#line 2125 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 405 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration : declaration_specifiers init_declarator_list SEMI;" << std::endl;
				outG << "declaration -> {declaration_specifiers init_declarator_list SEMI};" << std::endl;
			}

			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new declaration_Node((yyvsp[-2].n)->astPtr, (yyvsp[-1].n)->astPtr);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
		}
#line 2158 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 437 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node(); 
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new declList_Node((yyvsp[-1].n)->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "declaration_list : declaration;" << std::endl;
				outG << "declaration_list -> declaration;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";

		}
#line 2184 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 459 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create new ast node 
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-3].n)->val;
			(yyval.n)->valType = (yyvsp[-3].n)->valType;
			(yyval.n)->astPtr = new declList_Node((yyvsp[-3].n)->astPtr, (yyvsp[-1].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "declaration_list : declaration_list declaration;" << std::endl;
				outG << "declaration_list -> {declaration_list declaration};" << std::endl;
			}
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
		}
#line 2213 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 487 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : storage_class_specifier;" << std::endl;
				outG << "declaration_specifiers -> storage_class_specifier;" << std::endl; 
			}

			// create AST node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new declSpec_Node(NULL, (yyvsp[0].n)->val._num);
			
			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2238 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 508 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : storage_class_specifier declaration_specifiers;" << std::endl;
				outG << "declaration_specifiers -> {storage_class_specifier declaration_specifiers};" << std::endl;
			}

			// create AST node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new declSpec_Node((yyvsp[0].n)->astPtr, (yyvsp[-1].n)->val._num);
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2267 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 533 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_specifier;" << std::endl;
				outG << "declaration_specifiers -> type_specifier;" << std::endl;
			}

			// create AST node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new declSpec_Node(NULL, (yyvsp[0].n)->val._num);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2292 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 554 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_specifier declaration_specifiers;" << std::endl;
				outG << "declaration_specifiers -> {type_specifier declaration_specifiers};" << std::endl;
			}

			// create AST node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new declSpec_Node((yyvsp[0].n)->astPtr, (yyvsp[-1].n)->val._num);
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2321 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 579 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_qualifier;" << std::endl;
				outG << "declaration_specifiers -> type_qualifier;" << std::endl;
			}

			// create AST node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new declSpec_Node(NULL, (yyvsp[0].n)->val._num);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2346 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 600 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_qualifier declaration_specifiers;" << std::endl;
				outG << "declaration_specifiers -> {type_qualifier declaration_specifiers};" << std::endl;
			}

			// create AST node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new declSpec_Node((yyvsp[0].n)->astPtr, (yyvsp[-1].n)->val._num);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 2375 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 628 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = AUTO; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "auto");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : AUTO;" << std::endl;
				outG << "storage_class_specifier -> AUTO;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2396 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 645 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = REGISTER; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "register");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : REGISTER;" << std::endl;
				outG << "storage_class_specifier -> REGISTER;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2417 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 662 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = STATIC; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "static");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : STATIC;" << std::endl;
				outG << "storage_class_specifier -> STATIC;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2438 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 679 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = EXTERN; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "extern");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : EXTERN;" << std::endl;
				outG << "storage_class_specifier -> EXTERN;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2459 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 696 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node 
			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = TYPEDEF; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "typedef");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : TYPEDEF;" << std::endl;
				outG << "storage_class_specifier -> TYPEDEF;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2480 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 716 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = VOID; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "VOID");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : VOID;" << std::endl;
				outG << "type_specifier -> VOID;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2501 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 733 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = CHAR; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "CHAR");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : CHAR;" << std::endl;
				outG << "type_specifier -> CHAR;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2522 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 750 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = SHORT; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "SHORT");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : SHORT;" << std::endl;
				outG << "type_specifier -> SHORT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2543 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 767 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = INT; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "INT");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : INT;" << std::endl;
				outG << "type_specifier -> INT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2564 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 784 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = LONG; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "LONG");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : LONG;" << std::endl;
				outG << "type_specifier -> LONG;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2585 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 801 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = FLOAT; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "FLOAT");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : FLOAT;" << std::endl;
				outG << "type_specifier -> FLOAT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2606 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 818 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = DOUBLE; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "DOUBLE");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : DOUBLE;" << std::endl;
				outG << "type_specifier -> DOUBLE;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);

		}
#line 2628 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 836 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = SIGNED; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "SIGNED");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : SIGNED;" << std::endl;
				outG << "type_specifier -> SIGNED;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2649 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 853 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = UNSIGNED; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "UNSIGNED");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : UNSIGNED;" << std::endl;
				outG << "type_specifier -> UNSIGNED;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2670 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 870 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			/* not implementing */
			if(YFLAG){
				outY << "type_specifier : struct_or_union_specifier;" << std::endl;
				outG << "type_specifier -> struct_or_union_specifier;" << std::endl;
			}
		}
#line 2682 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 878 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			/* not implementing */
			if(YFLAG){
				outY << "type_specifier : enum_specifier;" << std::endl;
				outG << "type_specifier -> enum_specifier;" << std::endl;
			}
		}
#line 2694 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 886 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			/* not implementing */
			if(YFLAG){
				outY << "type_specifier : TYPEDEF_NAME;" << std::endl;
				outG << "type_specifier -> TYPEDEF_NAME;" << std::endl;
			}
		}
#line 2706 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 897 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = CONST; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "CONST");
			
			// output data
			if(YFLAG){
				outY << "type_qualifier : CONST;" << std::endl;
				outG << "translation_unit -> CONST;" << std::endl;
			}

			registerNode(outA, (yyval.n)->astPtr);

		}
#line 2727 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 914 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
 			(yyval.n) = new node();
			(yyval.n)->valType = LONG_LONG_T;
			(yyval.n)->val._num = VOLATILE; 
			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "VOLATILE");
			
			// output data
			if(YFLAG){
				outY << "type_qualifier : VOLATILE;" << std::endl;
				outG << "translation_unit -> VOLATILE;" << std::endl;
			}

			registerNode(outA, (yyval.n)->astPtr);
		}
#line 2747 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 933 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_or_union_specifier : struct_or_union identifier LCURL struct_declaration_list RCURL;" << std::endl;
				outG << "struct_or_union_specifier -> {struct_or_union identifier LCURL struct_declaration_list RCURL};" << std::endl;
			}
		}
#line 2759 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 941 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_or_union_specifier : struct_or_union LCURL struct_declaration_list RCURL;" << std::endl;
				outG << "struct_or_union_specifier -> {struct_or_union LCURL struct_declaration_list RCURL};" << std::endl;
			}
		}
#line 2771 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 949 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_or_union_specifier : struct_or_union identifier;" << std::endl;
				outG << "struct_or_union_specifier -> {struct_or_union identifier};" << std::endl;
			}
		}
#line 2783 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 960 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_or_union : STRUCT;" << std::endl;
				outG << "struct_or_union -> STRUCT;" << std::endl;
			}
		}
#line 2795 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 968 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_or_union : UNION;" << std::endl;
				outG << "struct_or_union -> UNION;" << std::endl;
			}
		}
#line 2807 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 979 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declaration_list : struct_declaration;" << std::endl;
				outG << "struct_declaration_list -> struct_declaration;" << std::endl;
			}
		}
#line 2819 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 987 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declaration_list : struct_declaration_list struct_declaration;" << std::endl;
				outG << "struct_declaration_list -> {struct_declaration_list struct_declaration};" << std::endl;
			}
		}
#line 2831 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 998 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "init_declarator_list : init_declarator;" << std::endl;
			outG << "init_declarator_list -> init_declarator;" << std::endl;
			}
		}
#line 2843 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1006 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "init_declarator_list : init_declarator_list COMMA init_declarator;" << std::endl;
				outG << "init_declarator_list -> {init_declarator_list COMMA init_declarator};" << std::endl;
			}
		}
#line 2855 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1017 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data
			if(YFLAG){
				outY << "init_declarator : declarator;" << std::endl;
				outG << "init_declarator -> declarator;" << std::endl; 
			}

 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new initDecl_Node((yyvsp[0].n)->astPtr, NULL); 

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n"; 
		}
#line 2880 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1038 "../parser/cParser.y" /* yacc.c:1646  */
    { 
 			// create ast node
			(yyval.n) = new node();
			
			//std::cout << "$1 datatype: " << $1->val._ste->getIdentifierType_String() << std::endl; 
 			//std::cout << "$4 datatype: " << $4->valType << std::endl; 

			// perform checking for assignment mismatching 
 			bool warningFlag = false;
 			std::string message = ""; 
 			bool fatalAssignment = (yyvsp[-4].n)->val._ste->setIdentifierValue((*(yyvsp[-1].n)), warningFlag, message); 			
 			if (warningFlag) {
 				std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "WARNING: " << COLOR_NORMAL << message << std::endl; 
 			}

 			else if (fatalAssignment) {
 				std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << " Invalid assignment." << std::endl;
 				yyerror("");
 			}


 			// assign ast node attributes
			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->valType = (yyvsp[-4].n)->valType;
			(yyval.n)->astPtr = new initDecl_Node((yyvsp[-4].n)->astPtr, (yyvsp[-1].n)->astPtr);
			//$$->astPtr->gen3AC(); 
			 
			// output data
 			if(YFLAG){
				outY << "init_declarator : declarator ASSIGN initializer;" << std::endl;
				outG << "init_declarator -> {declarator ASSIGN initializer};" << std::endl; 
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "ASSIGN", unique);
 			unique++;
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";

 		}
#line 2934 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1091 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declaration : specifier_qualifier_list struct_declarator_list SEMI;" << std::endl;
				outG << "struct_declaration -> {specifier_qualifier_list struct_declarator_list SEMI};" << std::endl;
			}
		}
#line 2946 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1102 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_specifier;" << std::endl;
				outG << "specifier_qualifier_list -> type_specifier;" << std::endl;
			}
		}
#line 2958 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1110 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_specifier specifier_qualifier_list;" << std::endl;
				outG << "specifier_qualifier_list -> {type_specifier specifier_qualifier_list};" << std::endl;
			}
		}
#line 2970 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1118 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_qualifier;" << std::endl;
				outG << "specifier_qualifier_list -> type_qualifier;" << std::endl;
			}
		}
#line 2982 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1126 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_qualifier specifier_qualifier_list;" << std::endl;
				outG << "specifier_qualifier_list -> {type_qualifier specifier_qualifier_list};" << std::endl;
			}
		}
#line 2994 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1137 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declarator_list : struct_declarator;" << std::endl;
				outG << "struct_declarator_list -> struct_declarator;" << std::endl;
			}
		}
#line 3006 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1145 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declarator_list : struct_declarator_list COMMA struct_declarator;" << std::endl;
				outG << "struct_declarator_list -> {struct_declarator_list COMMA struct_declarator};" << std::endl;
			}
		}
#line 3018 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1156 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declarator : declarator;" << std::endl;
				outG << "struct_declarator -> declarator;" << std::endl;
			}
		}
#line 3030 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1164 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declarator : COLON constant_expression;" << std::endl;
				outG << "struct_declarator -> COLON constant_expression;" << std::endl;
			}
		}
#line 3042 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1172 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "struct_declarator : declarator COLON constant_expression;" << std::endl;
				outG << "struct_declarator -> {declarator COLON constant_expression};" << std::endl;
			}
		}
#line 3054 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1183 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enum_specifier : ENUM LCURL enumerator_list RCURL;" << std::endl;
				outG << "enum_specifier -> {ENUM LCURL enumerator_list RCURL};" << std::endl;
			}
		}
#line 3066 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1191 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enum_specifier : ENUM identifier LCURL enumerator_list RCURL;" << std::endl;
				outG << "enum_specifier -> {ENUM identifier LCURL enumerator_list RCURL};" << std::endl;
			}
		}
#line 3078 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1199 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enum_specifier : ENUM identifier;" << std::endl;
				outG << "enum_specifier -> {ENUM identifier};" << std::endl;
			}
		}
#line 3090 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1210 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enumerator_list : enumerator;" << std::endl;
				outG << "enumerator_list -> enumerator;" << std::endl;
			}
		}
#line 3102 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1218 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enumerator_list : enumerator_list COMMA enumerator;" << std::endl;
				outG << "enumerator_list -> {enumerator_list COMMA enumerator};" << std::endl;
			}
		}
#line 3114 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1229 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enumerator : identifier;" << std::endl;
				outG << "enumerator -> identifier;" << std::endl;
			}
		}
#line 3126 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1237 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "enumerator : identifier ASSIGN constant_expression;" << std::endl;
				outG << "enumerator -> {identifier ASSIGN constant_expression};" << std::endl;
			}
		}
#line 3138 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1248 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "declarator : direct_declarator;" << std::endl;
				outG << "declarator -> direct_declarator;" << std::endl;
			}			

			// create ast node
			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[0].n)->valType;
 			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->astPtr = new declarator_Node((yyvsp[0].n)->astPtr);
			//$1->astPtr->gen3AC();

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3164 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1270 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new declarator_Node((yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "declarator : pointer direct_declarator;" << std::endl;
				outG << "declarator -> {pointer direct_declarator};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3193 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1298 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
 			if(YFLAG){
				outY << "direct_declarator : identifier;" << std::endl;
				outG << "direct_declarator -> identifier;" << std::endl;
			}

			// create ast node
			/*
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType; */
			(yyval.n) = (yyvsp[0].n);
/*
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";*/
		}
#line 3219 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1320 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "direct_declarator : LPAREN declarator RPAREN;" << std::endl;
				outG << "direct_declarator -> {LPAREN declarator RPAREN};" << std::endl;
			}

			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new directDecl_Node((yyvsp[-1].n)->astPtr, NULL);
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
		}
#line 3252 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1349 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_declarator : direct_declarator LBRACK RBRACK;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LBRACK RBRACK};" << std::endl;
			}	

			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new directDecl_Node((yyvsp[-2].n)->astPtr, NULL);

			// register data for graphviz 
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LBRACK", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RBRACK", unique);
 			unique++;
		}
#line 3285 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1378 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_declarator : direct_declarator LBRACK constant_expression RBRACK;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LBRACK constant_expression RBRACK};" << std::endl;
			}

 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-3].n)->val;
			(yyval.n)->valType = (yyvsp[-3].n)->valType;
			(yyval.n)->astPtr = new directDecl_Node((yyvsp[-3].n)->astPtr, (yyvsp[-1].n)->astPtr);

			// assign array attributes
 			(yyvsp[-3].n)->val._ste->setArray();
 			(yyvsp[-3].n)->val._ste->addArrayDimension((yyvsp[-1].n)->val._num); 
 			std::vector<int> arrayDims = (yyvsp[-3].n)->val._ste->getArrayDimensions();
 			if(arrayDims.size()==1) {
 				table.incrementOffset(arrayDims[0]-1);
 			}
 			else if(arrayDims.size() == 2) {
 				table.decrementOffset(arrayDims[0]-1);
 				table.incrementOffset(arrayDims[0]*arrayDims[1]-1);
			}
			else if(arrayDims.size() == 3) {
 				table.decrementOffset(arrayDims[0]*arrayDims[1]-1);
 				table.incrementOffset(arrayDims[0]*arrayDims[1]*arrayDims[2]-1);
			}
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LBRACK", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RBRACK", unique);
 			unique++;
		}
#line 3338 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1427 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "direct_declarator : direct_declarator LPAREN RPAREN;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LPAREN RPAREN};" << std::endl;
			}	

			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new directDecl_Node((yyvsp[-2].n)->astPtr, NULL);		
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;

		}
#line 3372 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1457 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
 			if(YFLAG){
				outY << "direct_declarator : direct_declarator LPAREN parameter_type_list RPAREN;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LPAREN parameter_type_list RPAREN};" << std::endl;
			}

 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-3].n)->val;
			(yyval.n)->valType = (yyvsp[-3].n)->valType;
			(yyval.n)->astPtr = new directDecl_Node((yyvsp[-3].n)->astPtr, (yyvsp[-1].n)->astPtr);

			// assign function attributes 
			(yyvsp[-3].n)->val._ste->setFunction(); 
			for (unsigned int i = 0; i < funcParams.size(); i++) {
				(yyvsp[-3].n)->val._ste->addParameter(funcParams[i]);
			}
			funcParams.clear();
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;

		}
#line 3417 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1498 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
 			if(YFLAG){
				outY << "direct_declarator : direct_declarator LPAREN identifier_list RPAREN;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LPAREN identifier_list RPAREN};" << std::endl;
			}	

			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->valType = (yyvsp[-4].n)->valType;
			(yyval.n)->astPtr = new directDecl_Node((yyvsp[-4].n)->astPtr, (yyvsp[-1].n)->astPtr);		
	 		
			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;

		}
#line 3455 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1535 "../parser/cParser.y" /* yacc.c:1646  */
    {		
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new pointer_Node((yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT;" << std::endl;
				outG << "pointer -> MULT;" << std::endl;
			}
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;

		}
#line 3481 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1557 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new pointer_Node((yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT type_qualifier_list;" << std::endl;
				outG << "pointer -> {MULT type_qualifier_list};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3510 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1582 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new pointer_Node((yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT pointer;" << std::endl;
				outG << "pointer -> {MULT pointer};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3539 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1607 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new pointer_Node((yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT type_qualifier_list pointer;" << std::endl;
				outG << "pointer -> {MULT type_qualifier_list pointer};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3572 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1639 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new typeQualifierList_Node((yyvsp[0].n)->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "type_qualifier_list : type_qualifier;" << std::endl;
				outG << "type_qualifier_list -> type_qualifier;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3597 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1660 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new typeQualifierList_Node((yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);

 			// output data
			if(YFLAG){
				outY << "type_qualifier_list : type_qualifier_list type_qualifier;" << std::endl;
				outG << "type_qualifier_list -> {type_qualifier_list type_qualifier};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3626 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1688 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "parameter_type_list : parameter_list;" << std::endl;
				outG << "parameter_type_list -> parameter_list;" << std::endl;
			}
		}
#line 3638 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1696 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "parameter_type_list : parameter_list COMMA ELIPSIS;" << std::endl;
				outG << "parameter_type_list -> {parameter_list COMMA ELIPSIS};" << std::endl;
			}
		}
#line 3650 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1707 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
 			if(YFLAG){
				outY << "parameter_list : parameter_declaration;" << std::endl;
				outG << "parameter_list -> parameter_declaration;" << std::endl;
			}
		}
#line 3662 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1715 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "parameter_list : parameter_list COMMA parameter_declaration;" << std::endl;
				outG << "parameter_list -> {parameter_list COMMA parameter_declaration};" << std::endl;
			}
		}
#line 3674 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1726 "../parser/cParser.y" /* yacc.c:1646  */
    {	
 			// output data
			if(YFLAG){
				outY << "parameter_declaration : declaration_specifiers declarator;" << std::endl;
				outG << "parameter_declaration -> {declaration_specifiers declarator};" << std::endl;
			}

 			// store integer data types of parameters 
 			std::vector<int> formalParamType;
 			formalParamType = (yyvsp[0].n)->val._ste->getIdentifierType_Vector();
			funcParams.push_back(formalParamType);

			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new paramDecl_Node((yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);



			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3710 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1758 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			 			// output data
			if(YFLAG){
				outY << "parameter_declaration : declaration_specifiers;" << std::endl;
				outG << "parameter_declaration -> declaration_specifiers;" << std::endl;
			}
 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new paramDecl_Node((yyvsp[0].n)->astPtr, NULL);



			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3735 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1779 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "parameter_declaration : declaration_specifiers abstract_declarator;" << std::endl;
				outG << "parameter_declaration -> {declaration_specifiers abstract_declarator};" << std::endl;
			}
		}
#line 3747 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1790 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "identifier_list : identifier;" << std::endl;
				outG << "identifier_list -> identifier;" << std::endl;
			}
		}
#line 3759 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1798 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "identifier_list : identifier_list COMMA identifier;" << std::endl;
				outG << "identifier_list -> {identifier_list COMMA identifier};" << std::endl;
			}
		}
#line 3771 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1809 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new initializer_Node((yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "initializer : assignment_expression;" << std::endl;
				outG << "initializer -> assignment_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 3796 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1830 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new initializer_Node((yyvsp[-1].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "initializer : LCURL initializer_list RCURL;" << std::endl;
				outG << "initializer -> {LCURL initializer_list RCURL};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
#line 3829 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1859 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new initializer_Node((yyvsp[-2].n)->astPtr);

 			// output data 
			if(YFLAG){
				outY << "initializer : LCURL initializer_list COMMA RCURL;" << std::endl;
				outG << "initializer -> {LCURL initializer_list COMMA RCURL};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "COMMA", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
#line 3866 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1895 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "initializer_list : initializer;" << std::endl;
				outG << "initializer_list -> initializer;" << std::endl;
			}
		}
#line 3878 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1903 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "initializer_list : initializer_list COMMA initializer;" << std::endl;
				outG << "initializer_list -> {initializer_list COMMA initializer};" << std::endl;
			}
		}
#line 3890 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1914 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "type_name : specifier_qualifier_list;" << std::endl;
				outG << "type_name -> specifier_qualifier_list;" << std::endl;
			}
		}
#line 3902 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1922 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "type_name : specifier_qualifier_list abstract_declarator;" << std::endl;
				outG << "type_name -> {specifier_qualifier_list abstract_declarator};" << std::endl;
			}
		}
#line 3914 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1933 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "abstract_declarator : pointer;" << std::endl;
				outG << "abstract_declarator -> pointer;" << std::endl;
			}
		}
#line 3926 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1941 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "abstract_declarator : direct_abstract_declarator;" << std::endl;
				outG << "abstract_declarator -> direct_abstract_declarator;" << std::endl;
			}
		}
#line 3938 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1949 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "abstract_declarator : pointer direct_abstract_declarator;" << std::endl;
				outG << "abstract_declarator -> {pointer direct_abstract_declarator};" << std::endl;
			}
		}
#line 3950 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1960 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LPAREN abstract_declarator RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {LPAREN abstract_declarator RPAREN};" << std::endl;
			}
		}
#line 3962 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1969 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LBRACK RBRACK;" << std::endl;
				outG << "direct_abstract_declarator -> {LBRACK RBRACK};" << std::endl;
			}
		}
#line 3974 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1977 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LBRACK constant_expression RBRACK;" << std::endl;
				outG << "direct_abstract_declarator -> {LBRACK constant_expression RBRACK};" << std::endl;
			}
		}
#line 3986 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1985 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LBRACK RBRACK;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LBRACK RBRACK};" << std::endl;
			}
		}
#line 3998 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1993 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LBRACK constant_expression;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LBRACK constant_expression};" << std::endl;
			}
		}
#line 4010 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 2001 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LPAREN RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {LPAREN RPAREN};" << std::endl;
			}
		}
#line 4022 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 2009 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LPAREN parameter_type_list RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {LPAREN parameter_type_list RPAREN};" << std::endl;
			}
		}
#line 4034 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 2017 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LPAREN RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LPAREN RPAREN};" << std::endl;
			}
		}
#line 4046 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 2025 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LPAREN parameter_type_list RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LPAREN parameter_type_list RPAREN};" << std::endl;
			}
		}
#line 4058 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2036 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "statement : labeled_statement;" << std::endl;
				outG << "statement -> labeled_statement;" << std::endl;
			}
		}
#line 4070 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2044 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "statement : compound_statement;" << std::endl;
				outG << "statement -> compound_statement;" << std::endl;
			}
		}
#line 4082 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2052 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "statement : expression_statement;" << std::endl;
				outG << "statement -> expression_statement;" << std::endl;
			}
		}
#line 4094 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2060 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "statement : selection_statement;" << std::endl;
				outG << "statement -> selection_statement;" << std::endl;
			}
		}
#line 4106 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2068 "../parser/cParser.y" /* yacc.c:1646  */
    {
 
 			// output data 
			if(YFLAG){
				outY << "statement : iteration_statement;" << std::endl;
				outG << "statement -> iteration_statement;" << std::endl;
			}
		}
#line 4119 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2077 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "statement : jump_statement;" << std::endl;
				outG << "statement -> jump_statement;" << std::endl;
			}
		}
#line 4131 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2088 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "labeled_statement : identifier COLON statement;" << std::endl;
				outG << "labeled_statement -> {identifier COLON statement};" << std::endl;
			}
		}
#line 4143 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2096 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "labeled_statement : CASE constant_expression COLON statement;" << std::endl;
				outG << "labeled_statement -> {CASE constant_expression COLON statement};" << std::endl;
			}
		}
#line 4155 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2104 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "labeled_statement : DEFAULT COLON statement;" << std::endl;
				outG << "labeled_statement -> {DEFAULT COLON statement};" << std::endl;
			}
		}
#line 4167 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2115 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "expression_statement : SEMI;" << std::endl;
				outG << "expression_statement -> SEMI;" << std::endl;
			}
		}
#line 4179 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2123 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes	
			(yyval.n) = (yyvsp[-1].n); 

			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;

 			// output data 
			if(YFLAG){
				outY << "expression_statement : expression SEMI;" << std::endl;
				outG << "expression_statement -> {expression SEMI};" << std::endl;
			}
		}
#line 4199 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2142 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "compound_statement : LCURL RCURL;" << std::endl;
				outG << "compound_statement -> {LCURL RCURL};" << std::endl;
			}
 			
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->astPtr = new compoundStat_Node(NULL, NULL);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
#line 4227 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2166 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
 			if(YFLAG){
				outY << "compound_statement : LCURL statement_list RCURL;" << std::endl;
				outG << "compound_statement -> {LCURL statement_list RCURL};" << std::endl;
			}

 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-5].n)->val;
			(yyval.n)->valType = (yyvsp[-5].n)->valType;
			(yyval.n)->astPtr = new compoundStat_Node(NULL, (yyvsp[-2].n)->astPtr);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
#line 4260 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2195 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->valType = (yyvsp[-4].n)->valType;
			(yyval.n)->astPtr = new compoundStat_Node((yyvsp[-2].n)->astPtr, NULL);

			// output data
 			if(YFLAG){
				outY << "compound_statement : LCURL declaration_list RCURL;" << std::endl;
				outG << "compound_statement -> {LCURL declaration_list RCURL};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
#line 4293 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2224 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->astPtr = new compoundStat_Node((yyvsp[-4].n)->astPtr, (yyvsp[-2].n)->astPtr);

			// output data 
			if(YFLAG){
				outG << "compound_statement -> {LCURL declaration_list statement_list RCURL};" << std::endl;
				outY << "compound_statement : LCURL declaration_list statement_list RCURL;" << std::endl;
		    }     
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
	    }
#line 4328 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2257 "../parser/cParser.y" /* yacc.c:1646  */
    {
		table.pushLevelOn();
		inInsertMode = true;
		outY << "set_insert_push : inInsertMode = true" << std::endl;
		}
#line 4338 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2265 "../parser/cParser.y" /* yacc.c:1646  */
    {
		table.popLevelOff(); 
		inInsertMode = false;  
		outY << "set_lookup_pop : inInsertMode = false" << std::endl;
		}
#line 4348 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2273 "../parser/cParser.y" /* yacc.c:1646  */
    {
		outY << "set_lookup : inInsertMode = false" << std::endl; 
		inInsertMode = false; 
		}
#line 4357 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2280 "../parser/cParser.y" /* yacc.c:1646  */
    {
		outY << "set_insert : inInsertMode = true" << std::endl; 
		inInsertMode = true; 
		}
#line 4366 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2287 "../parser/cParser.y" /* yacc.c:1646  */
    {
		table.pushLevelOn();
	   }
#line 4374 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2293 "../parser/cParser.y" /* yacc.c:1646  */
    {
		table.popLevelOff();  
		}
#line 4382 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2300 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "statement_list : statement;" << std::endl;
				outG << "statement_list -> statement;" << std::endl;
			}	

 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new statList_Node((yyvsp[0].n)->astPtr, NULL);
			
			// register data for graphviz			
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4407 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2321 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "statement_list : statement_list statement;" << std::endl;
				outG << "statement_list -> {statement_list statement};" << std::endl;
			}

			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
			(yyval.n)->astPtr = new statList_Node((yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4436 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 2349 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new selectionStat_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, NULL);

			// output pasta
			if(YFLAG){
				outY << "selection_statement : IF LPAREN expression RPAREN statement;" << std::endl;
				outG << "selection_statement -> {IF LPAREN expression RPAREN statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "IF", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4477 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 2386 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->valType = (yyvsp[-4].n)->valType;
			(yyval.n)->astPtr = new selectionStat_Node((yyvsp[-4].n)->astPtr, (yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "selection_statement : IF LPAREN expression RPAREN statement ELSE statement;" << std::endl;
				outG << "selection_statement -> {IF LPAREN expression RPAREN statement ELSE statement};" << std::endl;
			}
		
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "IF", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "ELSE", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4526 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 2431 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new selectionStat_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "selection_statement : SWITCH LPAREN expression RPAREN statement;" << std::endl;
				outG << "selection_statement -> {SWITCH LPAREN expression RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SWITCH", unique);
 			unique++;

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4568 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 2472 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->astPtr = new iterStat_Node(NULL, (yyvsp[-2].n)->astPtr, NULL, (yyvsp[0].n)->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : WHILE LPAREN expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {WHILE LPAREN expression RPAREN statement};" << std::endl; 
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "WHILE", unique);
 			unique++;

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4608 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2508 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-5].n)->val;
			(yyval.n)->valType = (yyvsp[-5].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node(NULL, (yyvsp[-2].n)->astPtr, NULL, (yyvsp[-5].n)->astPtr, true);

			// output data
			if(YFLAG){
				outY << "iteration_statement : DO statement WHILE LPAREN expression RPAREN SEMI;" << std::endl;
				outG << "iteration_statement -> {DO statement WHILE LPAREN expression RPAREN SEMI};" << std::endl; 
			}

			// register data for graphviz and assign attributes
			registerNode(outA, (yyval.n)->astPtr);
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "DO", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-5].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr); 
 						outA << " -> ";
 			outputTerminal(outA, "WHILE", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr); 
 						outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
		}
#line 4657 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2553 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node(NULL, NULL, NULL, (yyvsp[0].n)->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI SEMI RPAREN statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";	
		}
#line 4702 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2594 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node(NULL, NULL, (yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI SEMI expression RPAREN statement};" << std::endl;
			}
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";	
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";		
		}
#line 4750 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2638 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-3].n)->val;
			(yyval.n)->valType = (yyvsp[-3].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node(NULL, (yyvsp[-3].n)->astPtr, NULL, (yyvsp[0].n)->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI expression SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI expression SEMI RPAREN statement};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 4797 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2681 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->valType = (yyvsp[-4].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node(NULL, (yyvsp[-4].n)->astPtr, (yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI expression SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI expression SEMI expression RPAREN statement};" << std::endl;
			
			}		
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 4849 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 2729 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->valType = (yyvsp[-4].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node((yyvsp[-4].n)->astPtr, NULL, NULL, (yyvsp[0].n)->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI SEMI RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 4896 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2772 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-5].n)->val;
			(yyval.n)->valType = (yyvsp[-5].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node((yyvsp[-5].n)->astPtr, NULL, (yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI SEMI expression RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-5].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 4947 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2819 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-5].n)->val;
			(yyval.n)->valType = (yyvsp[-5].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node((yyvsp[-5].n)->astPtr, (yyvsp[-3].n)->astPtr, NULL, (yyvsp[0].n)->astPtr, false);

			// output data S
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI expression SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI expression SEMI RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-5].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 4998 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2866 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-6].n)->val;
			(yyval.n)->valType = (yyvsp[-6].n)->valType;
			(yyval.n)->astPtr = new iterStat_Node((yyvsp[-6].n)->astPtr, (yyvsp[-4].n)->astPtr, (yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI expression SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI expression SEMI expression RPAREN statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-6].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5055 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2922 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "jump_statement : GOTO identifier SEMI;" << std::endl;
				outG << "jump_statement -> {GOTO identifier SEMI};" << std::endl;
			}
		}
#line 5067 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2930 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "jump_statement : CONTINUE SEMI;" << std::endl;
				outG << "jump_statement -> {CONTINUE SEMI};" << std::endl;
			}
		}
#line 5079 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2938 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "jump_statement : BREAK SEMI;" << std::endl;
				outG << "jump_statement -> {BREAK SEMI};" << std::endl;
			}
		}
#line 5091 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2946 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "jump_statement : RETURN SEMI;" << std::endl;
				outG << "jump_statement -> {RETURN SEMI};" << std::endl;
			}
		}
#line 5103 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 2954 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "jump_statement : RETURN expression SEMI;" << std::endl;
				outG << "jump_statement -> {RETURN expression SEMI};" << std::endl;
			}
		}
#line 5115 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 2965 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new expr_Node((yyvsp[0].n)->astPtr, NULL);	

			// output data 
			if(YFLAG){
				outY << "expression : assignment_expression;" << std::endl;
				outG << "expression -> assignment_expression;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5140 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2986 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new expr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr);

			// output data 
			if(YFLAG){
				outY << "expression : expression COMMA assignment_expression;" << std::endl;
				outG << "expression -> {expression COMMA assignment_expression};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "COMMA", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5173 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 3018 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->astPtr = new assignmentExpr_Node((yyvsp[0].n)->astPtr, NULL, -1);

			// output data 
			if(YFLAG){
				outY << "assignment_expression : conditional_expression;" << std::endl;
				outG << "assignment_expression -> conditional_expression;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5198 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 3039 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->astPtr = new assignmentExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, (yyvsp[-1].n)->val._num);

			// output data 
			if(YFLAG){
				outY << "assignment_expression : unary_expression assignment_operator assignment_expression;" << std::endl;
				outG << "assignment_expression -> {unary_expression assignment_operator assignment_expression};" << std::endl;
			}

			// register data for graphviz			
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5231 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 3071 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->valType = LONG_LONG_T;
 			(yyval.n)->val._num = ASSIGN;
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "ASSIGN"); 
 			registerNode(outA, (yyval.n)->astPtr);
 			// output data  
			if(YFLAG){
				outY << "assignment_operator : ASSIGN;" << std::endl;
				outG << "assignment_operator -> ASSIGN;" << std::endl;
			}
		}
#line 5249 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 3085 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			(yyval.n) = new node(); 
 			(yyval.n)->valType = LONG_LONG_T;
 			(yyval.n)->val._num = MUL_ASSIGN; 
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "MUL_ASSIGN"); 
 			registerNode(outA, (yyval.n)->astPtr);
			if(YFLAG){
				outY << "assignment_operator : MUL_ASSIGN;" << std::endl;
			outG << "assignment_operator -> MUL_ASSIGN;" << std::endl;
			}
		}
#line 5265 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 3097 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			(yyval.n) = new node(); 
 			(yyval.n)->valType = LONG_LONG_T;
 			(yyval.n)->val._num = DIV_ASSIGN; 
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "DIV_ASSIGN"); 
 			registerNode(outA, (yyval.n)->astPtr);
			if(YFLAG){
				outY << "assignment_operator : DIV_ASSIGN;" << std::endl;
			outG << "assignment_operator -> DIV_ASSIGN;" << std::endl;
			}
		}
#line 5281 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 3109 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			(yyval.n) = new node(); 
 			(yyval.n)->valType = LONG_LONG_T;
 			(yyval.n)->val._num = MOD_ASSIGN; 
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "MOD_ASSIGN"); 
 			registerNode(outA, (yyval.n)->astPtr);
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : MOD_ASSIGN;" << std::endl;
				outG << "assignment_operator -> MOD_ASSIGN;" << std::endl;
			}
		}
#line 5298 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 3122 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->valType = LONG_LONG_T;
 			(yyval.n)->val._num = ADD_ASSIGN;
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "ADD_ASSIGN"); 
 			registerNode(outA, (yyval.n)->astPtr);

 			// output data 
			if(YFLAG){
				outY << "assignment_operator : ADD_ASSIGN;" << std::endl;
				outG << "assignment_operator -> ADD_ASSIGN;" << std::endl;
			}
		}
#line 5317 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 3137 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->valType = LONG_LONG_T;
 			(yyval.n)->val._num = SUB_ASSIGN;
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "SUB_ASSIGN"); 
 			registerNode(outA, (yyval.n)->astPtr);

 			// output data 
			if(YFLAG){
				outY << "assignment_operator : SUB_ASSIGN;" << std::endl;
				outG << "assignment_operator -> SUB_ASSIGN;" << std::endl;
			}
		}
#line 5336 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 3152 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : LEFT_ASSIGN;" << std::endl;
				outG << "assignment_operator -> LEFT_ASSIGN;" << std::endl;
			}
		}
#line 5348 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 3160 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : RIGHT_ASSIGN;" << std::endl;
				outG << "assignment_operator -> RIGHT_ASSIGN;" << std::endl;
			}
		}
#line 5360 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 3168 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : AND_ASSIGN;" << std::endl;
				outG << "assignment_operator -> AND_ASSIGN;" << std::endl;
			}
		}
#line 5372 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 3176 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : XOR_ASSIGN;" << std::endl;
				outG << "assignment_operator -> XOR_ASSIGN;" << std::endl;
			}
		}
#line 5384 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 3184 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : OR_ASSIGN;" << std::endl;
				outG << "assignment_operator -> OR_ASSIGN;" << std::endl;
			}
		}
#line 5396 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 3195 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "conditional_expression : logical_or_expression;" << std::endl;
				outG << "conditional_expression -> logical_or_expression;" << std::endl;
			}
		}
#line 5408 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 3203 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "conditional_expression : logical_or_expression QUESTION expression COLON conditional_expression;" << std::endl;
				outG << "conditional_expression -> {logical_or_expression QUESTION expression COLON conditional_expression;" << std::endl;
			}
		}
#line 5420 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 3214 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "constant_expression : conditional_expression;" << std::endl;
				outG << "constant_expression -> conditional_expression;" << std::endl;
			}
		}
#line 5432 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 3225 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "logical_or_expression : logical_and_expression;" << std::endl;
				outG << "logical_or_expression -> logical_and_expression;" << std::endl;
			}
		}
#line 5444 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 3233 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "logical_or_expression : logical_or_expression OR_OP logical_and_expression;" << std::endl;
				outG << "logical_or_expression -> {logical_or_expression OR_OP logical_and_expression};" << std::endl;
			}
		}
#line 5456 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 3244 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "logical_and_expression : inclusive_or_expression;" << std::endl;
				outG << "logical_and_expression -> inclusive_or_expression;" << std::endl;
			}
		}
#line 5468 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 3252 "../parser/cParser.y" /* yacc.c:1646  */
    {
			if(YFLAG){
				// output data 
				outY << "logical_and_expression : logical_and_expression AND_OP inclusive_or_expression;" << std::endl;
				outG << "logical_and_expression -> {logical_and_expression AND_OP inclusive_or_expression};" << std::endl;
			}

		}
#line 5481 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 3264 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "inclusive_or_expression : exclusive_or_expression;" << std::endl;
				outG << "inclusive_or_expression -> exclusive_or_expression;" << std::endl;
			}
		}
#line 5493 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 3272 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "inclusive_or_expression : inclusive_or_expression PIPE exclusive_or_expression;" << std::endl;
				outG << "inclusive_or_expression -> {inclusive_or_expression PIPE exclusive_or_expression};" << std::endl;
			}
		}
#line 5505 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 3283 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "exclusive_or_expression : and_expression;" << std::endl;
				outG << "exclusive_or_expression -> and_expression;" << std::endl;
			}
		}
#line 5517 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 3291 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "exclusive_or_expression : exclusive_or_expression CARROT and_expression;" << std::endl;
				outG << "exclusive_or_expression -> {exclusive_or_expression CARROT and_expression};" << std::endl;
			}
		}
#line 5529 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 3302 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data 
			if(YFLAG){
				outY << "and_expression : equality_expression;" << std::endl;
				outG << "and_expression -> equality_expression;" << std::endl;
			}
		}
#line 5541 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 3310 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "and_expression : and_expression AMP equality_expression;" << std::endl;
				outG << "and_expression -> {and_expression AMP equality_expression};" << std::endl;
			}
		}
#line 5553 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 3321 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
	 		(yyval.n)->astPtr = new equalityExpr_Node((yyvsp[0].n)->astPtr, NULL, -1);

	 		// output data 
			if(YFLAG){
				outY << "equality_expression : relational_expression;" << std::endl;
	 			outG << "equality_expression -> relational_expression;" << std::endl;
			}
			
			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";

		}
#line 5579 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 3343 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
	 		(yyval.n)->astPtr = new equalityExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, EQ_OP);

	 		// output data 
			if(YFLAG){
				outY << "equality_expression : equality_expression EQ_OP relational_expression;" << std::endl;
				outG << "equality_expression -> {equality_expression EQ_OP relational_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "EQ_OP", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5612 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 3372 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
	 		(yyval.n)->astPtr = new equalityExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, NE_OP);

 			// output data 
			if(YFLAG){
				outY << "equality_expression : equality_expression NE_OP relational_expression;" << std::endl;
	 			outG << "equality_expression -> {equality_expression LTHAN relational_expression};" << std::endl;
			}

			// register data for graphviz			
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "NE_OP", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5645 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 3404 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
	 		(yyval.n)->astPtr = new relationalExpr_Node((yyvsp[0].n)->astPtr, NULL, -1);

	 		// output data
			if(YFLAG){
				outY << "relational_expression : shift_expression;" << std::endl;
	 			outG << "relational_expression -> shift_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5670 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 3425 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
	 		(yyval.n)->astPtr = new relationalExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, LTHAN);

	 		// output data
			if(YFLAG){
				outY << "relational_expression : relational_expression LTHAN shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression LTHAN shift_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LTHAN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5703 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 3454 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
	 		(yyval.n)->astPtr = new relationalExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, GTHAN);

	 		// output data 
			if(YFLAG){
				outY << "relational_expression : relational_expression GTHAN shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression GTHAN shift_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "GTHAN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5736 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 3483 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
	 		(yyval.n)->astPtr = new relationalExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, LE_OP);

	 		// output data 
			if(YFLAG){
				outY << "relational_expression : relational_expression LE_OP shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression LE_OP shift_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LE_OP", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5769 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 3512 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[-2].n)->val;
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
	 		(yyval.n)->astPtr = new relationalExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, GE_OP);

	 		// output data 
			if(YFLAG){
				outY << "relational_expression : relational_expression GE_OP shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression GE_OP shift_expression};" << std::endl;
			}

			// create ast node
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "GE_OP", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5802 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 3544 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "shift_expression : additive_expression;" << std::endl;
				outG << "shift_expression -> additive_expression;" << std::endl;
			}
		}
#line 5814 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 3552 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "shift_expression : shift_expression LEFT_OP additive_expression;" << std::endl;
				outG << "shift_expression -> {shift_expression LEFT_OP additive_expression};" << std::endl;
			}
		}
#line 5826 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 3560 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "shift_expression : shift_expression RIGHT_OP additive_expression;" << std::endl;
				outG << "shift_expression -> {shift_expression RIGHT_OP additive_expression};" << std::endl;
			}
		}
#line 5838 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 3571 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;
	 		(yyval.n)->astPtr = new multExpr_Node((yyvsp[0].n)->astPtr, NULL, -1);

	 		// output data 
			if(YFLAG){
				outY << "additive_expression : multiplicative_expression;" << std::endl;
	 			outG << "additive_expression -> multiplicative_expression;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5863 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 3592 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->val = (yyvsp[-2].n)->val; 
 			(yyval.n)->astPtr = new additiveExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, PLUS);
 			//$$->astPtr->gen3AC();

 			// output data 
 			if(YFLAG){
				outY << "additive_expression : additive_expression PLUS multiplicative_expression;" << std::endl;
	 			outG << "additive_expression -> {additive_expression PLUS cast_expression};" << std::endl;
			}
			
 			// performArithmeticOp($$, $1, $3, PLUS);

			// register data for graphviz		
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "PLUS", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5899 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 3624 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->valType = (yyvsp[-2].n)->valType;
			(yyval.n)->val = (yyvsp[-2].n)->val; 
			(yyval.n)->astPtr = new additiveExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, MINUS);
			//$$->astPtr->gen3AC();

			// output data 
 			if(YFLAG){
				outY << "additive_expression : additive_expression MINUS multiplicative_expression;" << std::endl;
	 			outG << "additive_expression -> {additive_expression MINUS cast_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
	 		outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "MINUS", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5933 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 3657 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node
			(yyval.n) = new node();
			(yyval.n)->val = (yyvsp[0].n)->val; 
			(yyval.n)->valType = (yyvsp[0].n)->valType; 
	 		(yyval.n)->astPtr = new multExpr_Node((yyvsp[0].n)->astPtr, NULL, -1);
			//$$->astPtr->gen3AC();

 			// output data 
			if(YFLAG){
				outY << "multiplicative_expression : cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> cast_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 5959 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 3679 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-2].n)->valType;
 			(yyval.n)->val = (yyvsp[-2].n)->val; 
			(yyval.n)->astPtr = new multExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, MULT);
			//$$->astPtr->gen3AC();

			// output data
			if(YFLAG){
				outY << "multiplicative_expression : multiplicative_expression MULT cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> {multiplicative_expression MULT cast_expression};" << std::endl;
			}

			/*
 			if ($1->valType != STE_T && $3->valType == STE_T) {
 				performArithmeticOp_OneSTE($$, $1, $3, MULT, false);
 			}
 			else if ($1->valType == STE_T && $3->valType != STE_T) {
 				std::cout << "left is an STE and right is not" << std::endl; 
 				performArithmeticOp_OneSTE($$, $1, $3, MULT, true);
 			}
			*/

 			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "MULT", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 6003 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 3719 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-2].n)->valType;
 			(yyval.n)->val = (yyvsp[-2].n)->val; 
			(yyval.n)->astPtr = new multExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, DIV);
			//$$->astPtr->gen3AC();

			// prevent division by 0
			switch ((yyvsp[0].n)->valType) {
				case LONG_LONG_T:
				case LONG_T:
				case INT_T:
				case SHORT_T:
					if ((yyvsp[0].n)->val._num == 0) {
						std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL;
						std::cout << "Unable to divide by 0." << std::endl; 
 						yyerror("");
					}
				break;

				case FLOAT_T:
				case DOUBLE_T:
				case LONG_DOUBLE_T:
					if ((yyvsp[0].n)->val._dec == 0.0) {
						std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL;
						std::cout << "Unable to divide by 0.0." << std::endl; 
 						yyerror("");
					}
				break;  
			}

			// output data
 			if(YFLAG){
				outY << "multiplicative_expression : multiplicative_expression DIV cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> {multiplicative_expression DIV cast_expression};" << std::endl;
			}

			/*
			if ($1->valType != STE_T && $3->valType == STE_T) {
 				performArithmeticOp_OneSTE($$, $1, $3, DIV, false);
 			}
 			else if ($1->valType == STE_T && $3->valType != STE_T) {
 				std::cout << "left is an STE and right is not" << std::endl; 
 				performArithmeticOp_OneSTE($$, $1, $3, DIV, true);
 			}
 			*/

 			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "DIV", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 6071 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 3783 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-2].n)->valType;
 			(yyval.n)->val = (yyvsp[-2].n)->val; 
			(yyval.n)->astPtr = new multExpr_Node((yyvsp[-2].n)->astPtr, (yyvsp[0].n)->astPtr, MOD);

			// output data
 			if(YFLAG){
				outY << "multiplicative_expression : multiplicative_expression MOD cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> {multiplicative_expression MOD cast_expression};" << std::endl;
			}
 			
			/*
 			performArithmeticOp($$, $1, $3, MOD);
 			*/
	 		
 			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-2].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "MOD", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 6108 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 3819 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "cast_expression : unary_expression;" << std::endl;
				outG << "cast_expression -> unary_expression;" << std::endl;
			}
		}
#line 6120 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 3827 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "cast_expression : LPAREN type_name RPAREN cast_expression;" << std::endl;
				outG << "cast_expression -> {LPAREN type_name RPAREN cast_expression};" << std::endl;
			}
		}
#line 6132 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 3838 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
			(yyval.n) = new node();
			(yyval.n)->valType = (yyvsp[0].n)->valType;
			(yyval.n)->val = (yyvsp[0].n)->val;
	 		(yyval.n)->astPtr = new unaryExpr_Node((yyvsp[0].n)->astPtr, NULL, false, false);
			//$$->astPtr->gen3AC();

	 		// output data 
			if(YFLAG){
				outY << "unary_expression : postfix_expression;" << std::endl;
	 			outG << "unary_expression -> postfix_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 6158 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 3860 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[0].n)->valType;
 			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->astPtr = new unaryExpr_Node(NULL, (yyvsp[0].n)->astPtr, true, false);
			//$$->astPtr->gen3AC();

 			// output data 
 			if(YFLAG){
				outY << "unary_expression : INC_OP unary_expression;" << std::endl;
	 			outG << "unary_expression -> {INC_OP cast_expression};" << std::endl;
			}

			// register data for graphviz	 		
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "INC_OP", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";

		}
#line 6189 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 3887 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
	 		(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[0].n)->valType;
 			(yyval.n)->val = (yyvsp[0].n)->val;
 			(yyval.n)->astPtr = new unaryExpr_Node(NULL, (yyvsp[0].n)->astPtr, false, true);
			//$$->astPtr->gen3AC();

 			if(YFLAG){
				outY << "unary_expression : DEC_OP unary_expression;" << std::endl;
	 		outG << "unary_expression -> {DEC_OP cast_expression};" << std::endl;
			}		

 			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "DEC_OP", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";
		}
#line 6218 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 3912 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
			(yyval.n) = new node();
			(yyval.n)->valType = (yyvsp[-1].n)->valType;
 			(yyval.n)->val = (yyvsp[-1].n)->val;
			(yyval.n)->astPtr = new unaryExpr_Node((yyvsp[-1].n)->astPtr, (yyvsp[0].n)->astPtr);
			//$$->astPtr->gen3AC();

			// output data 
			if(YFLAG){
				outY << "unary_expression : unary_operator cast_expression;" << std::endl;
	 			outG << "unary_expression -> {unary_operator cast_expression}" << std::endl;
			}		

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n";

		}
#line 6249 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 3939 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "unary_expression : SIZEOF unary_expression;" << std::endl;
				outG << "unary_expression -> {SIZEOF unary_expression};" << std::endl;
			}
		}
#line 6261 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 3947 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "unary_expression : SIZEOF LPAREN type_name RPAREN;" << std::endl;
				outG << "unary_expression -> {SIZEOF LPAREN type_name RPAREN};" << std::endl;
			}
		}
#line 6273 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 3958 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
 			(yyval.n) = new node();
			(yyval.n)->astPtr = new unaryOp_Node(AMP);
 			unaryOperatorChosen = AMP;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : AMP;" << std::endl;
 				outG << "unary_operator -> AMP;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6293 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 3974 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
 			(yyval.n) = new node();
			(yyval.n)->astPtr = new unaryOp_Node(MULT);
 			unaryOperatorChosen = MULT;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : MULT;" << std::endl;
 				outG << "unary_operator -> MULT;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6313 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 3990 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
 			(yyval.n) = new node();
			(yyval.n)->astPtr = new unaryOp_Node(PLUS);
 			unaryOperatorChosen = PLUS;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : PLUS;" << std::endl;
 				outG << "unary_operator -> PLUS;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6333 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 4006 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
 			(yyval.n) = new node();
			(yyval.n)->astPtr = new unaryOp_Node(MINUS);
 			unaryOperatorChosen = MINUS;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : MINUS;" << std::endl;
 				outG << "unary_operator -> MINUS;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6353 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 4022 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
 			(yyval.n) = new node();
			(yyval.n)->astPtr = new unaryOp_Node(TILDE);
 			unaryOperatorChosen = TILDE;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : TILDE;" << std::endl;
 				outG << "unary_operator -> TILDE;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6373 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 4038 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes 
 			(yyval.n) = new node();
			(yyval.n)->astPtr = new unaryOp_Node(BANG);
 			unaryOperatorChosen = BANG;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : BANG;" << std::endl;
 				outG << "unary_operator -> BANG;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6393 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 4057 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[0].n)->valType;
 			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->astPtr = new postfixExpr_Node((yyvsp[0].n)->astPtr, NULL, false, false);
			//$$->astPtr->gen3AC();

			// output data 
 			if(YFLAG){
				outY << "postfix_expression : primary_expression;" << std::endl;
 				outG << "postfix_expression -> primary_expression;" << std::endl;
			}

			// check to see if the current identifier is a function 
 			if((yyvsp[0].n)->valType == STE_T && (yyvsp[0].n)->val._ste->isFunction()){
 				currentFunc = (yyvsp[0].n)->val._ste;
 			} 
 			
 			// register data for graphviz
 			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[0].n)->astPtr);
 			outA << ";\n"; 
 		}
#line 6424 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 4084 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-4].n)->valType;
 			(yyval.n)->val = (yyvsp[-4].n)->val;
			(yyval.n)->astPtr = new postfixExpr_Node((yyvsp[-4].n)->astPtr, (yyvsp[-1].n)->astPtr, false, false);
			//$$->astPtr->gen3AC();

 			// output data 
 			if(YFLAG){
				outY << "postfix_expression : postfix_expression LBRACK expression RBRACK;" << std::endl;
				outG << "postfix_expression -> {postfix_expression LBRACK expression RBRACK};" << std::endl;
			}

			// register data for graphviz
 			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-4].n)->astPtr);
 			outA << ";\n"; 

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LBRACK", unique);
 			unique++;

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n"; 

 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RBRACK", unique);
 			unique++;
		}
#line 6465 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 4121 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "postfix_expression : postfix_expression LPAREN RPAREN;" << std::endl;
				outG << "postfix_expression -> {postfix_expression LPAREN RPAREN};" << std::endl;
			}
		}
#line 6477 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 4129 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-3].n)->valType;
 			(yyval.n)->val = (yyvsp[-3].n)->val;
 			(yyval.n)->astPtr = new postfixExpr_Node((yyvsp[-3].n)->astPtr, (yyvsp[-1].n)->astPtr, false, false);

 			// output data 
  			if(YFLAG){
				outY << "postfix_expression : postfix_expression LPAREN argument_expression_list RPAREN;" << std::endl;
 				outG << "postfix_expression -> {postfix_expression LPAREN argument_expression_list RPAREN;};" << std::endl;
			}

			// check to see if the function parameters are valid 
 			(yyvsp[-3].n)->val._ste = currentFunc; 
 			std::string errorMsg = "";
 			if (!(yyvsp[-3].n)->val._ste->checkParams(funcCallingParams, errorMsg)) {
 				std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL << errorMsg << std::endl;
 				yyerror("");
 			}
 			funcCallingParams.clear();

			// register data for graphviz
 			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-3].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
		}
#line 6523 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 4171 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "postfix_expression : postfix_expression DOT identifier;" << std::endl;
				outG << "postfix_expression -> {postfix_expression DOT identifier};" << std::endl;
			}
		}
#line 6535 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 4179 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data
			if(YFLAG){
				outY << "postfix_expression : postfix_expression PTR_OP identifier;" << std::endl;
				outG << "postfix_expression -> {postfix_expression PTR_OP identifier};" << std::endl;
			}
		}
#line 6547 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 4187 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-1].n)->valType;
 			(yyval.n)->val = (yyvsp[-1].n)->val;
 			(yyval.n)->astPtr = new postfixExpr_Node((yyvsp[-1].n)->astPtr, NULL, true, false);
 			//$$->astPtr->gen3AC();

 			// output data 
			if(YFLAG){
				outY << "postfix_expression : postfix_expression INC_OP;" << std::endl;
 				outG << "postfix_expression -> {postfix_expression INC_OP};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "INC_OP", unique);
 			unique++;

 			// do we need this? Seems like run-time stuff
 			/*
 			node* n = $1->val._ste->getIdentifierValue();
 			switch(n->valType) {
 				case LONG_LONG_T:
				case LONG_T:
				case INT_T:
				case SHORT_T:
 					n->val._num++;
 					break; 

 				case FLOAT_T:
				case DOUBLE_T:
				case LONG_DOUBLE_T:
 					n->val._dec++;
 					break;

 				case CHAR_T:
 					n->val._char++;
 					break;

 				default:
 					yyerror("Unable to increment.");
 					break;
 			}
 			$1->val._ste->setIdentifierValue(*n);
			*/	
		}
#line 6605 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 4241 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node();
 			(yyval.n)->valType = (yyvsp[-1].n)->valType;
 			(yyval.n)->val = (yyvsp[-1].n)->val;
 			(yyval.n)->astPtr = new postfixExpr_Node((yyvsp[-1].n)->astPtr, NULL, false, true);
 			//$$->astPtr->gen3AC(); 

 			// output data 
 			if(YFLAG){
				outY << "postfix_expression : postfix_expression DEC_OP;" << std::endl;
 				outG << "postfix_expression -> {postfix_expression DEC_OP};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
 			outputNode(outA, (yyval.n)->astPtr);
 			outA << " -> ";
 			outputNode(outA, (yyvsp[-1].n)->astPtr);
 			outA << ";\n";

 			// perform decrement - do we need this? Seems like run-time stuff
 			/*
 			node* n = $1->val._ste->getIdentifierValue();
 			switch(n->valType) {
 				case LONG_LONG_T:
				case LONG_T:
				case INT_T:
				case SHORT_T:
 					n->val._num--;
 					break; 

 				case FLOAT_T:
				case DOUBLE_T:
				case LONG_DOUBLE_T:
 					n->val._dec--;
 					break;

 				case CHAR_T:
 					n->val._char--;
 					break;

 				default:
 					yyerror("Unable to decrement.");
 					break;
 			}
 			$1->val._ste->setIdentifierValue(*n);
			*/
		}
#line 6659 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 4294 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "primary_expression : identifier;" << std::endl;
				outG << "primary_expression -> identifier;" << std::endl;
			}

			// pass pointer up tree 
 			(yyval.n) = (yyvsp[0].n);
		}
#line 6674 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 4305 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
 			if(YFLAG){
				outY << "primary_expression : constant;" << std::endl;
				outG << "primary_expression -> constant;" << std::endl;
			}

			// pass pointer up tree
 			(yyval.n) = (yyvsp[0].n);
		}
#line 6689 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 4316 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// output data 
			if(YFLAG){
				outY << "primary_expression : string;" << std::endl;
				outG << "primary_expression -> string;" << std::endl;
			}
		}
#line 6701 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 4324 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// assign appropriate node
 			(yyval.n) = (yyvsp[-1].n);

 			// output data 
			if(YFLAG){
				outY << "primary_expression : LPAREN expression RPAREN;" << std::endl;
				outG << "primary_expression -> {LPAREN expression RPAREN};" << std::endl;
			}
		}
#line 6716 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 4338 "../parser/cParser.y" /* yacc.c:1646  */
    { 
			// push back the symbol table entry of the actual parameter
 			funcCallingParams.push_back((yyvsp[0].n)->val._ste);

 			// output data 
 			if(YFLAG){
				outY << "argument_expression_list : assignment_expression;" << std::endl;
				outG << "argument_expression_list -> assignment_expression;" << std::endl;
			}

 			
 			// create ast node ?
		}
#line 6734 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 4352 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			if(YFLAG){
				outY << "argument_expression_list : argument_expression_list COMMA assignment_expression;" << std::endl;
				outG << "argument_expression_list -> {argument_expression_list COMMA assignment_expression};" << std::endl;
			}
 			// push back the symbol table entry of the actual parameter
 			funcCallingParams.push_back((yyvsp[0].n)->val._ste);

			// create ast node ?
		}
#line 6749 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 4366 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->val = (yyvsp[0].n)->val; 
 			(yyval.n)->valType = INT_T; 
 			(yyval.n)->astPtr = new leaf_Node((yyval.n)->val, (yyval.n)->valType, "INTEGER_CONSTANT");

 			// output data
 			if(YFLAG){
				outY << "constant : INTEGER_CONSTANT;" << std::endl;
				outG << "constant -> INTEGER_CONSTANT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6770 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 4383 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->astPtr = new leaf_Node((yyvsp[0].n)->val, (yyvsp[0].n)->valType, "CHARACTER_CONSTANT");
 			(yyval.n)->val = (yyvsp[0].n)->val; 
 			(yyval.n)->valType = CHAR_T; 

 			// output data
 			if(YFLAG){
				outY << "constant : CHARACTER_CONSTANT;" << std::endl;
				outG << "constant -> CHARACTER_CONSTANT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6791 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 4400 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->astPtr = new leaf_Node((yyvsp[0].n)->val, (yyvsp[0].n)->valType, "FLOATING_CONSTANT");
 			(yyval.n)->val = (yyvsp[0].n)->val; 
 			(yyval.n)->valType = FLOAT_T;

 			// output data
 			if(YFLAG){
				outY << "constant : FLOATING_CONSTANT;" << std::endl;
				outG << "constant -> FLOATING_CONSTANT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6812 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 4417 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			/* not sure what to do about this */
			if(YFLAG){
				outY << "constant : ENUMERATION_CONSTANT;" << std::endl;
				outG << "constant -> ENUMERATION_CONSTANT;" << std::endl;
			}

			// displaying error message 
			yyerror("catfishC cannot handle enumeration constants.");
		}
#line 6827 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 4431 "../parser/cParser.y" /* yacc.c:1646  */
    {
 			// create ast node and assign attributes
 			(yyval.n) = new node(); 
 			(yyval.n)->astPtr = new leaf_Node((yyvsp[0].n)->val, (yyvsp[0].n)->valType, "STRING_LITERAL");
 			strcpy((yyval.n)->val._str, (yyvsp[0].n)->val._str);
 			(yyval.n)->valType = STR_T; 

 			// output data 
			if(YFLAG){
				outY << "string : STRING_LITERAL;" << std::endl;
				outG << "string -> STRING_LITERAL;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6848 "cParser.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 4451 "../parser/cParser.y" /* yacc.c:1646  */
    {
			// output data
			if(YFLAG){
				outY << "identifier : IDENTIFIER;" << std::endl;
				outG << "identifier -> IDENTIFIER;" << std::endl;
			}

			// create ast node and assign attributes
			(yyval.n) = new node(); 
			(yyval.n)->astPtr = new leaf_Node((yyvsp[0].n)->val, (yyvsp[0].n)->valType, (yyvsp[0].n)->val._ste->getIdentifierName());
			(yyval.n)->val = (yyvsp[0].n)->val;
			(yyval.n)->valType = (yyvsp[0].n)->valType;

			// register data for graphviz
			registerNode(outA, (yyval.n)->astPtr);
		}
#line 6869 "cParser.tab.c" /* yacc.c:1646  */
    break;


#line 6873 "cParser.tab.c" /* yacc.c:1646  */
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
#line 4468 "../parser/cParser.y" /* yacc.c:1906  */
 /* end of ANSI C grammar and actions */

/* user code */

/*
Function: yyerror(const char* s)

Description: Used for error messages in both the Flex and Bison files. 
*/
void yyerror(const char* s) {

	std::cout << s << std::endl;
	exit(-1);
}

/*
Function: integerTicketCounter()

Description: Returns a unique string for each integer encountered while 
parsing.
*/
std::string intTC() {
	return "IT_" + std::to_string(intTicket++);
}

std::string labelTC() {
	return "Label_" + std::to_string(labelCount++);
}

void registerNode(std::ofstream &out, astNode* ptr){

	out << ptr->getName() << '_' << ptr->getID() << ' ';
	out << "[label = \"" << ptr->getName() << "\"" << "]";
	out << ';' << std::endl;
}

void outputNode(std::ofstream &out, astNode* ptr){

	out << ptr->getName() << '_' << ptr->getID();
}

void outputTerminal(std::ofstream &out, std::string name, int id){
	out << name << id << ";\n";
	out << name << id << "[label=" << name << "];\n";
}
