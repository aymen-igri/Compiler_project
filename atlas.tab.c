/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "atlas.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylineno;

/* Code generation */
typedef struct {
    char instruction[256];
} Instruction;

Instruction code[10000];
int code_idx = 0;

 /* Generate instruction */
void generer(const char *instr) {
    strcpy(code[code_idx].instruction, instr);
    code_idx++;
}

/* Generate label */
int generer_label() {
    return code_idx;
}

 /* Patch branch instruction */
void patcher(int label, int target) {
    if (strncmp(code[label].instruction, "bsf", 3) == 0) {
        sprintf(code[label].instruction, "if (pile[ip--] == 0) goto L%d;", target);
    } else if (strncmp(code[label].instruction, "bra", 3) == 0) {
        sprintf(code[label].instruction, "goto L%d;", target);
    }
}

// struct for variables management
typedef struct {
    char nom[64];
    int type;
    int adresse;
    int valeur;
} Variable;

Variable variables[100];
int nb_vars = 0;
int adresse_var = 0;

int etiq = 0;

void yyerror(const char *msg);
int yylex();

int ajouter_var(const char *nom, int type, int valeur);
int chercher_var(const char *nom);


#line 130 "atlas.tab.c"

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

#include "atlas.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_PROGRAMME = 3,              /* TOK_PROGRAMME  */
  YYSYMBOL_TOK_VAR = 4,                    /* TOK_VAR  */
  YYSYMBOL_TOK_CONST = 5,                  /* TOK_CONST  */
  YYSYMBOL_TOK_DEBUT = 6,                  /* TOK_DEBUT  */
  YYSYMBOL_TOK_FIN = 7,                    /* TOK_FIN  */
  YYSYMBOL_TOK_ENT = 8,                    /* TOK_ENT  */
  YYSYMBOL_TOK_BOOL = 9,                   /* TOK_BOOL  */
  YYSYMBOL_TOK_LIRE = 10,                  /* TOK_LIRE  */
  YYSYMBOL_TOK_LIRERC = 11,                /* TOK_LIRERC  */
  YYSYMBOL_TOK_ECRIRE = 12,                /* TOK_ECRIRE  */
  YYSYMBOL_TOK_ECRIRERC = 13,              /* TOK_ECRIRERC  */
  YYSYMBOL_TOK_IMPRIMER = 14,              /* TOK_IMPRIMER  */
  YYSYMBOL_TOK_IMPRIMERRC = 15,            /* TOK_IMPRIMERRC  */
  YYSYMBOL_TOK_PASSER = 16,                /* TOK_PASSER  */
  YYSYMBOL_TOK_SI = 17,                    /* TOK_SI  */
  YYSYMBOL_TOK_ALORS = 18,                 /* TOK_ALORS  */
  YYSYMBOL_TOK_FSI = 19,                   /* TOK_FSI  */
  YYSYMBOL_TOK_POUR = 20,                  /* TOK_POUR  */
  YYSYMBOL_TOK_DEPUIS = 21,                /* TOK_DEPUIS  */
  YYSYMBOL_TOK_JUSQUA = 22,                /* TOK_JUSQUA  */
  YYSYMBOL_TOK_PARPAS = 23,                /* TOK_PARPAS  */
  YYSYMBOL_TOK_FAIRE = 24,                 /* TOK_FAIRE  */
  YYSYMBOL_TOK_FPOUR = 25,                 /* TOK_FPOUR  */
  YYSYMBOL_TOK_TANTQUE = 26,               /* TOK_TANTQUE  */
  YYSYMBOL_TOK_FTQ = 27,                   /* TOK_FTQ  */
  YYSYMBOL_TOK_ET = 28,                    /* TOK_ET  */
  YYSYMBOL_TOK_OU = 29,                    /* TOK_OU  */
  YYSYMBOL_TOK_NON = 30,                   /* TOK_NON  */
  YYSYMBOL_TOK_AFFECT = 31,                /* TOK_AFFECT  */
  YYSYMBOL_TOK_PLUS = 32,                  /* TOK_PLUS  */
  YYSYMBOL_TOK_MOINS = 33,                 /* TOK_MOINS  */
  YYSYMBOL_TOK_MULT = 34,                  /* TOK_MULT  */
  YYSYMBOL_TOK_DIV = 35,                   /* TOK_DIV  */
  YYSYMBOL_TOK_MOD = 36,                   /* TOK_MOD  */
  YYSYMBOL_TOK_PUISS = 37,                 /* TOK_PUISS  */
  YYSYMBOL_TOK_VALABS = 38,                /* TOK_VALABS  */
  YYSYMBOL_TOK_ENTIER = 39,                /* TOK_ENTIER  */
  YYSYMBOL_TOK_BOOLEEN = 40,               /* TOK_BOOLEEN  */
  YYSYMBOL_TOK_IDENTIFIANT = 41,           /* TOK_IDENTIFIANT  */
  YYSYMBOL_TOK_CHAINE = 42,                /* TOK_CHAINE  */
  YYSYMBOL_TOK_EGAL = 43,                  /* TOK_EGAL  */
  YYSYMBOL_TOK_INF = 44,                   /* TOK_INF  */
  YYSYMBOL_TOK_SUP = 45,                   /* TOK_SUP  */
  YYSYMBOL_TOK_INF_EG = 46,                /* TOK_INF_EG  */
  YYSYMBOL_TOK_SUP_EG = 47,                /* TOK_SUP_EG  */
  YYSYMBOL_TOK_DIFF = 48,                  /* TOK_DIFF  */
  YYSYMBOL_TOK_POINT_VIRGULE = 49,         /* TOK_POINT_VIRGULE  */
  YYSYMBOL_TOK_VIRGULE = 50,               /* TOK_VIRGULE  */
  YYSYMBOL_TOK_POINT = 51,                 /* TOK_POINT  */
  YYSYMBOL_TOK_PAREN_OUV = 52,             /* TOK_PAREN_OUV  */
  YYSYMBOL_TOK_PAREN_FERM = 53,            /* TOK_PAREN_FERM  */
  YYSYMBOL_TOK_ERREUR = 54,                /* TOK_ERREUR  */
  YYSYMBOL_UMINUS = 55,                    /* UMINUS  */
  YYSYMBOL_UNOT = 56,                      /* UNOT  */
  YYSYMBOL_IF_PREC = 57,                   /* IF_PREC  */
  YYSYMBOL_TOK_SINON = 58,                 /* TOK_SINON  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_programme = 60,                 /* programme  */
  YYSYMBOL_declarations = 61,              /* declarations  */
  YYSYMBOL_declaration = 62,               /* declaration  */
  YYSYMBOL_const_declaration = 63,         /* const_declaration  */
  YYSYMBOL_const_items = 64,               /* const_items  */
  YYSYMBOL_const_item = 65,                /* const_item  */
  YYSYMBOL_const_expr = 66,                /* const_expr  */
  YYSYMBOL_var_declaration = 67,           /* var_declaration  */
  YYSYMBOL_var_items = 68,                 /* var_items  */
  YYSYMBOL_var_item = 69,                  /* var_item  */
  YYSYMBOL_type = 70,                      /* type  */
  YYSYMBOL_var_list = 71,                  /* var_list  */
  YYSYMBOL_instructions = 72,              /* instructions  */
  YYSYMBOL_instruction = 73,               /* instruction  */
  YYSYMBOL_instr_io = 74,                  /* instr_io  */
  YYSYMBOL_instr_affectation = 75,         /* instr_affectation  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_instr_si = 77,                  /* instr_si  */
  YYSYMBOL_cond_si = 78,                   /* cond_si  */
  YYSYMBOL_else_marker = 79,               /* else_marker  */
  YYSYMBOL_instr_pour = 80,                /* instr_pour  */
  YYSYMBOL_instr_tantque = 81,             /* instr_tantque  */
  YYSYMBOL_loop_start = 82,                /* loop_start  */
  YYSYMBOL_cond_tantque = 83,              /* cond_tantque  */
  YYSYMBOL_instr_passer = 84,              /* instr_passer  */
  YYSYMBOL_expr = 85                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   138,   140,   144,   145,   149,   153,   154,
     158,   162,   169,   170,   171,   172,   173,   174,   175,   179,
     183,   184,   188,   192,   193,   197,   201,   209,   210,   213,
     214,   215,   216,   217,   218,   222,   229,   236,   240,   244,
     250,   260,   259,   273,   277,   284,   292,   301,   306,   314,
     324,   331,   339,   346,   353,   360,   385,   390,   395,   400,
     405,   410,   415,   420,   425,   430,   435,   440,   445,   450,
     455,   460,   465,   470
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_PROGRAMME",
  "TOK_VAR", "TOK_CONST", "TOK_DEBUT", "TOK_FIN", "TOK_ENT", "TOK_BOOL",
  "TOK_LIRE", "TOK_LIRERC", "TOK_ECRIRE", "TOK_ECRIRERC", "TOK_IMPRIMER",
  "TOK_IMPRIMERRC", "TOK_PASSER", "TOK_SI", "TOK_ALORS", "TOK_FSI",
  "TOK_POUR", "TOK_DEPUIS", "TOK_JUSQUA", "TOK_PARPAS", "TOK_FAIRE",
  "TOK_FPOUR", "TOK_TANTQUE", "TOK_FTQ", "TOK_ET", "TOK_OU", "TOK_NON",
  "TOK_AFFECT", "TOK_PLUS", "TOK_MOINS", "TOK_MULT", "TOK_DIV", "TOK_MOD",
  "TOK_PUISS", "TOK_VALABS", "TOK_ENTIER", "TOK_BOOLEEN",
  "TOK_IDENTIFIANT", "TOK_CHAINE", "TOK_EGAL", "TOK_INF", "TOK_SUP",
  "TOK_INF_EG", "TOK_SUP_EG", "TOK_DIFF", "TOK_POINT_VIRGULE",
  "TOK_VIRGULE", "TOK_POINT", "TOK_PAREN_OUV", "TOK_PAREN_FERM",
  "TOK_ERREUR", "UMINUS", "UNOT", "IF_PREC", "TOK_SINON", "$accept",
  "programme", "declarations", "declaration", "const_declaration",
  "const_items", "const_item", "const_expr", "var_declaration",
  "var_items", "var_item", "type", "var_list", "instructions",
  "instruction", "instr_io", "instr_affectation", "$@1", "instr_si",
  "cond_si", "else_marker", "instr_pour", "instr_tantque", "loop_start",
  "cond_tantque", "instr_passer", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -17,    38,     4,   -87,   -87,    25,    -7,    43,   188,
     -87,   -87,   -87,   -87,   -87,    -7,   -87,    14,    29,    42,
      43,   -87,    47,    49,   319,   319,    50,    51,   -87,    45,
      53,   -87,    74,     2,   -87,    58,    59,   -87,   188,   -87,
     -87,    57,    88,   -87,   -87,    37,    95,    97,   -87,   -87,
     -87,   319,   319,    89,   -87,   -87,   -87,   319,   333,   333,
     -87,   -87,   319,   121,   -87,    92,   -87,   -87,   -87,    65,
     319,   188,   -87,   -87,   103,   -29,   115,   -87,   -87,   319,
     208,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   230,   319,   319,   -87,   -87,
     -87,   188,   252,   119,   -87,   -87,   -29,   306,   109,   274,
     -87,   371,   354,    -1,    -1,   122,   122,   122,   -87,    85,
      85,    85,    85,    85,    85,   143,    67,   333,   137,   138,
     -87,   -28,   -29,   -29,   -29,   -29,   -29,   -87,   -87,   -87,
     -87,   319,   -87,   -87,   -87,     6,     6,   -87,   -87,   -87,
     187,   319,   188,   300,   154,   188,   -87,   171,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       4,     5,     6,    23,    24,    19,    20,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,    52,     0,
       0,    50,     0,     0,    27,     0,     0,    31,     0,    32,
      33,     0,     0,    21,    25,     0,     0,     0,     9,    35,
      36,     0,     0,     0,    53,    54,    55,     0,    37,    38,
      39,    40,     0,     0,    41,     0,    28,    29,    30,     0,
       0,     0,    34,    22,     0,     0,     0,    72,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,    43,
      46,     0,     0,     0,    26,    12,     0,     0,     0,     0,
      73,    70,    71,    56,    57,    58,    59,    60,    61,    64,
      66,    67,    68,    69,    65,     0,     0,    42,     0,     0,
      49,     0,     0,     0,     0,     0,     0,    10,    11,    62,
      45,     0,    44,    51,    18,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,    47,     0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   152,   -86,   -87,   -87,
     158,   -87,   -87,   -27,   -30,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    10,    11,    20,    21,   107,    12,    15,
      16,    17,    45,    33,    34,    35,    36,    97,    37,    38,
     101,    39,    40,    41,    71,    42,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    13,    14,    66,   132,   133,   134,   135,   136,    65,
     105,    69,    22,    23,    24,    25,    26,    27,    28,    29,
     131,     1,    30,   106,     3,   144,    77,    78,    31,     7,
       8,     9,    80,    85,    86,    87,    88,    95,     4,    66,
     134,   135,   136,    32,   103,   102,   145,   146,   147,   148,
     149,    18,    19,     5,   109,    44,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      46,   126,   127,    66,   128,    22,    23,    24,    25,    26,
      27,    28,    29,    47,    99,    30,    73,    74,    49,   141,
      50,    31,    60,    61,    63,    81,    82,    62,    66,    83,
      84,    85,    86,    87,    88,    64,    32,    67,    68,    70,
      89,    90,    91,    92,    93,    94,   150,    83,    84,    85,
      86,    87,    88,   100,    66,   154,   153,    66,   157,    22,
      23,    24,    25,    26,    27,    28,    29,    72,    75,    30,
      76,    79,    96,    98,   104,    31,   130,    22,    23,    24,
      25,    26,    27,    28,    29,   108,   142,    30,   138,    88,
      32,   140,   143,    31,    22,    23,    24,    25,    26,    27,
      28,    29,    48,    43,    30,     0,     0,     0,    32,   156,
      31,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,    30,     0,     0,     0,    32,   158,    31,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,    30,     0,
     151,   152,    32,     0,    31,    81,    82,     0,     0,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,    32,
      89,    90,    91,    92,    93,    94,    81,    82,     0,     0,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,     0,    81,    82,
       0,   110,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,     0,
      81,    82,     0,   125,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,     0,    81,    82,     0,   129,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,     0,   155,     0,     0,   139,    81,    82,
       0,     0,    83,    84,    85,    86,    87,    88,   132,   133,
     134,   135,   136,    89,    90,    91,    92,    93,    94,    51,
       0,     0,    52,     0,     0,   137,     0,    53,    54,    55,
      56,    81,    82,     0,     0,    83,    84,    85,    86,    87,
      88,    57,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    81,     0,     0,     0,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,    90,    91,    92,    93,    94
};

static const yytype_int16 yycheck[] =
{
      25,     8,     9,    33,    32,    33,    34,    35,    36,     7,
      39,    38,    10,    11,    12,    13,    14,    15,    16,    17,
     106,     3,    20,    52,    41,    53,    51,    52,    26,     4,
       5,     6,    57,    34,    35,    36,    37,    62,     0,    69,
      34,    35,    36,    41,    71,    70,   132,   133,   134,   135,
     136,     8,     9,    49,    79,    41,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      41,    96,    97,   103,   101,    10,    11,    12,    13,    14,
      15,    16,    17,    41,    19,    20,    49,    50,    41,    22,
      41,    26,    42,    42,    41,    28,    29,    52,   128,    32,
      33,    34,    35,    36,    37,    31,    41,    49,    49,    52,
      43,    44,    45,    46,    47,    48,   141,    32,    33,    34,
      35,    36,    37,    58,   154,   152,   151,   157,   155,    10,
      11,    12,    13,    14,    15,    16,    17,    49,    43,    20,
      43,    52,    21,    51,    41,    26,    27,    10,    11,    12,
      13,    14,    15,    16,    17,    40,    19,    20,    49,    37,
      41,    18,    24,    26,    10,    11,    12,    13,    14,    15,
      16,    17,    20,    15,    20,    -1,    -1,    -1,    41,    25,
      26,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    -1,    -1,    -1,    41,    25,    26,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    -1,
      23,    24,    41,    -1,    26,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    41,
      43,    44,    45,    46,    47,    48,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    28,    29,
      -1,    53,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    -1,
      28,    29,    -1,    53,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    -1,    28,    29,    -1,    53,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    -1,    24,    -1,    -1,    53,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    32,    33,
      34,    35,    36,    43,    44,    45,    46,    47,    48,    30,
      -1,    -1,    33,    -1,    -1,    49,    -1,    38,    39,    40,
      41,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    52,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    28,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    60,    41,     0,    49,    61,     4,     5,     6,
      62,    63,    67,     8,     9,    68,    69,    70,     8,     9,
      64,    65,    10,    11,    12,    13,    14,    15,    16,    17,
      20,    26,    41,    72,    73,    74,    75,    77,    78,    80,
      81,    82,    84,    69,    41,    71,    41,    41,    65,    41,
      41,    30,    33,    38,    39,    40,    41,    52,    85,    85,
      42,    42,    52,    41,    31,     7,    73,    49,    49,    72,
      52,    83,    49,    49,    50,    43,    43,    85,    85,    52,
      85,    28,    29,    32,    33,    34,    35,    36,    37,    43,
      44,    45,    46,    47,    48,    85,    21,    76,    51,    19,
      58,    79,    85,    72,    41,    39,    52,    66,    40,    85,
      53,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    53,    85,    85,    72,    53,
      27,    66,    32,    33,    34,    35,    36,    49,    49,    53,
      18,    22,    19,    24,    53,    66,    66,    66,    66,    66,
      85,    23,    24,    85,    72,    24,    25,    72,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    76,    75,    77,    77,    78,    79,    80,    80,    81,
      82,    83,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     0,     2,     1,     1,     2,     1,     2,
       5,     5,     1,     3,     3,     3,     3,     3,     3,     2,
       1,     2,     3,     1,     1,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     0,     4,     3,     5,     5,     1,     9,    11,     4,
       1,     4,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programme: TOK_PROGRAMME TOK_IDENTIFIANT TOK_POINT_VIRGULE declarations TOK_DEBUT instructions TOK_FIN TOK_POINT  */
#line 133 "atlas.y"
    {
    }
#line 1363 "atlas.tab.c"
    break;

  case 10: /* const_item: TOK_ENT TOK_IDENTIFIANT TOK_EGAL const_expr TOK_POINT_VIRGULE  */
#line 159 "atlas.y"
     {
         ajouter_var((yyvsp[-3].sval), 1, (yyvsp[-1].ival));
     }
#line 1371 "atlas.tab.c"
    break;

  case 11: /* const_item: TOK_BOOL TOK_IDENTIFIANT TOK_EGAL TOK_BOOLEEN TOK_POINT_VIRGULE  */
#line 163 "atlas.y"
     {
         ajouter_var((yyvsp[-3].sval), 1, (yyvsp[-1].ival));
     }
#line 1379 "atlas.tab.c"
    break;

  case 12: /* const_expr: TOK_ENTIER  */
#line 169 "atlas.y"
                { (yyval.ival) = (yyvsp[0].ival); }
#line 1385 "atlas.tab.c"
    break;

  case 13: /* const_expr: const_expr TOK_PLUS const_expr  */
#line 170 "atlas.y"
                                      { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1391 "atlas.tab.c"
    break;

  case 14: /* const_expr: const_expr TOK_MOINS const_expr  */
#line 171 "atlas.y"
                                       { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1397 "atlas.tab.c"
    break;

  case 15: /* const_expr: const_expr TOK_MULT const_expr  */
#line 172 "atlas.y"
                                      { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1403 "atlas.tab.c"
    break;

  case 16: /* const_expr: const_expr TOK_DIV const_expr  */
#line 173 "atlas.y"
                                     { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
#line 1409 "atlas.tab.c"
    break;

  case 17: /* const_expr: const_expr TOK_MOD const_expr  */
#line 174 "atlas.y"
                                     { (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); }
#line 1415 "atlas.tab.c"
    break;

  case 18: /* const_expr: TOK_PAREN_OUV const_expr TOK_PAREN_FERM  */
#line 175 "atlas.y"
                                               { (yyval.ival) = (yyvsp[-1].ival); }
#line 1421 "atlas.tab.c"
    break;

  case 23: /* type: TOK_ENT  */
#line 192 "atlas.y"
              { (yyval.ival) = 1; }
#line 1427 "atlas.tab.c"
    break;

  case 24: /* type: TOK_BOOL  */
#line 193 "atlas.y"
                { (yyval.ival) = 2; }
#line 1433 "atlas.tab.c"
    break;

  case 25: /* var_list: TOK_IDENTIFIANT  */
#line 198 "atlas.y"
     {
         ajouter_var((yyvsp[0].sval), 0, 0);
     }
#line 1441 "atlas.tab.c"
    break;

  case 26: /* var_list: var_list TOK_VIRGULE TOK_IDENTIFIANT  */
#line 202 "atlas.y"
     {
         ajouter_var((yyvsp[0].sval), 0, 0);
     }
#line 1449 "atlas.tab.c"
    break;

  case 35: /* instr_io: TOK_LIRE TOK_IDENTIFIANT  */
#line 223 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler_adr(%d);", chercher_var((yyvsp[0].sval)));
         generer(buf);
         generer("lire();");
     }
#line 1460 "atlas.tab.c"
    break;

  case 36: /* instr_io: TOK_LIRERC TOK_IDENTIFIANT  */
#line 230 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler_adr(%d);", chercher_var((yyvsp[0].sval)));
         generer(buf);
         generer("lireRC();");
     }
#line 1471 "atlas.tab.c"
    break;

  case 37: /* instr_io: TOK_ECRIRE expr  */
#line 237 "atlas.y"
     {
         generer("ecrire();");
     }
#line 1479 "atlas.tab.c"
    break;

  case 38: /* instr_io: TOK_ECRIRERC expr  */
#line 241 "atlas.y"
     {
         generer("ecrireRC();");
     }
#line 1487 "atlas.tab.c"
    break;

  case 39: /* instr_io: TOK_IMPRIMER TOK_CHAINE  */
#line 245 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "imprimer(\"%s\");", (yyvsp[0].sval));
         generer(buf);
     }
#line 1497 "atlas.tab.c"
    break;

  case 40: /* instr_io: TOK_IMPRIMERRC TOK_CHAINE  */
#line 251 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "imprimerRC(\"%s\");", (yyvsp[0].sval));
         generer(buf);
     }
#line 1507 "atlas.tab.c"
    break;

  case 41: /* $@1: %empty  */
#line 260 "atlas.y"
     {
         int idx = chercher_var((yyvsp[-1].sval));
         char buf[256];
         sprintf(buf, "empiler_adr(%d);", idx);
         generer(buf);
     }
#line 1518 "atlas.tab.c"
    break;

  case 42: /* instr_affectation: TOK_IDENTIFIANT TOK_AFFECT $@1 expr  */
#line 267 "atlas.y"
     {
         generer("affect();");
     }
#line 1526 "atlas.tab.c"
    break;

  case 43: /* instr_si: cond_si instructions TOK_FSI  */
#line 274 "atlas.y"
     {
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1534 "atlas.tab.c"
    break;

  case 44: /* instr_si: cond_si instructions else_marker instructions TOK_FSI  */
#line 278 "atlas.y"
     {
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1542 "atlas.tab.c"
    break;

  case 45: /* cond_si: TOK_SI TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_ALORS  */
#line 285 "atlas.y"
     {
         (yyval.ival) = code_idx;
         generer("bsf(0000);");
     }
#line 1551 "atlas.tab.c"
    break;

  case 46: /* else_marker: TOK_SINON  */
#line 293 "atlas.y"
     {
         (yyval.ival) = code_idx;
         generer("bra(0000);");
         patcher((yyvsp[(-1) - (1)].ival), code_idx); // patch the bsf from cond_si
     }
#line 1561 "atlas.tab.c"
    break;

  case 47: /* instr_pour: TOK_POUR TOK_IDENTIFIANT TOK_DEPUIS expr TOK_JUSQUA expr TOK_FAIRE instructions TOK_FPOUR  */
#line 304 "atlas.y"
     {
     }
#line 1568 "atlas.tab.c"
    break;

  case 48: /* instr_pour: TOK_POUR TOK_IDENTIFIANT TOK_DEPUIS expr TOK_JUSQUA expr TOK_PARPAS expr TOK_FAIRE instructions TOK_FPOUR  */
#line 309 "atlas.y"
     {
     }
#line 1575 "atlas.tab.c"
    break;

  case 49: /* instr_tantque: loop_start cond_tantque instructions TOK_FTQ  */
#line 315 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "goto L%d;", (yyvsp[-3].ival));
         generer(buf);
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1586 "atlas.tab.c"
    break;

  case 50: /* loop_start: TOK_TANTQUE  */
#line 325 "atlas.y"
     {
         (yyval.ival) = code_idx;
     }
#line 1594 "atlas.tab.c"
    break;

  case 51: /* cond_tantque: TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_FAIRE  */
#line 332 "atlas.y"
     {
         (yyval.ival) = code_idx;
         generer("bsf(0000);");
     }
#line 1603 "atlas.tab.c"
    break;

  case 52: /* instr_passer: TOK_PASSER  */
#line 340 "atlas.y"
     {
         generer("/* passer */");
     }
#line 1611 "atlas.tab.c"
    break;

  case 53: /* expr: TOK_ENTIER  */
#line 347 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler_val(%d);", (yyvsp[0].ival));
         generer(buf);
         (yyval.ival) = (yyvsp[0].ival);
     }
#line 1622 "atlas.tab.c"
    break;

  case 54: /* expr: TOK_BOOLEEN  */
#line 354 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler_val(%d);", (yyvsp[0].ival));
         generer(buf);
         (yyval.ival) = (yyvsp[0].ival);
     }
#line 1633 "atlas.tab.c"
    break;

  case 55: /* expr: TOK_IDENTIFIANT  */
#line 361 "atlas.y"
     {
         int idx = -1;
         for (int i = 0; i < nb_vars; i++) {
             if (strcmp(variables[i].nom, (yyvsp[0].sval)) == 0) {
                 idx = i;
                 break;
             }
         }
         if (idx == -1) {
             fprintf(stderr, "Erreur: variable '%s' non declaree\n", (yyvsp[0].sval));
             (yyval.ival) = 0;
         } else if (variables[idx].type == 1) { /* constante */
             char buf[256];
             sprintf(buf, "empiler_val(%d);", variables[idx].valeur);
             generer(buf);
             (yyval.ival) = variables[idx].valeur;
         } else { /* variable */
             char buf[256];
             sprintf(buf, "empiler_adr(%d);", variables[idx].adresse);
             generer(buf);
             generer("valeur_pile();");
             (yyval.ival) = 0;
         }
     }
#line 1662 "atlas.tab.c"
    break;

  case 56: /* expr: expr TOK_PLUS expr  */
#line 386 "atlas.y"
     {
         generer("plus();");
         (yyval.ival) = 0;
     }
#line 1671 "atlas.tab.c"
    break;

  case 57: /* expr: expr TOK_MOINS expr  */
#line 391 "atlas.y"
     {
         generer("moins();");
         (yyval.ival) = 0;
     }
#line 1680 "atlas.tab.c"
    break;

  case 58: /* expr: expr TOK_MULT expr  */
#line 396 "atlas.y"
     {
         generer("mult();");
         (yyval.ival) = 0;
     }
#line 1689 "atlas.tab.c"
    break;

  case 59: /* expr: expr TOK_DIV expr  */
#line 401 "atlas.y"
     {
         generer("division();");
         (yyval.ival) = 0;
     }
#line 1698 "atlas.tab.c"
    break;

  case 60: /* expr: expr TOK_MOD expr  */
#line 406 "atlas.y"
     {
         generer("mod();");
         (yyval.ival) = 0;
     }
#line 1707 "atlas.tab.c"
    break;

  case 61: /* expr: expr TOK_PUISS expr  */
#line 411 "atlas.y"
     {
         generer("puiss();");
         (yyval.ival) = 0;
     }
#line 1716 "atlas.tab.c"
    break;

  case 62: /* expr: TOK_VALABS TOK_PAREN_OUV expr TOK_PAREN_FERM  */
#line 416 "atlas.y"
     {
         generer("valabs();");
         (yyval.ival) = 0;
     }
#line 1725 "atlas.tab.c"
    break;

  case 63: /* expr: TOK_MOINS expr  */
#line 421 "atlas.y"
     {
         generer("neg();");
         (yyval.ival) = 0;
     }
#line 1734 "atlas.tab.c"
    break;

  case 64: /* expr: expr TOK_EGAL expr  */
#line 426 "atlas.y"
     {
         generer("egal();");
         (yyval.ival) = 0;
     }
#line 1743 "atlas.tab.c"
    break;

  case 65: /* expr: expr TOK_DIFF expr  */
#line 431 "atlas.y"
     {
         generer("dif();");
         (yyval.ival) = 0;
     }
#line 1752 "atlas.tab.c"
    break;

  case 66: /* expr: expr TOK_INF expr  */
#line 436 "atlas.y"
     {
         generer("pps();");
         (yyval.ival) = 0;
     }
#line 1761 "atlas.tab.c"
    break;

  case 67: /* expr: expr TOK_SUP expr  */
#line 441 "atlas.y"
     {
         generer("pgs();");
         (yyval.ival) = 0;
     }
#line 1770 "atlas.tab.c"
    break;

  case 68: /* expr: expr TOK_INF_EG expr  */
#line 446 "atlas.y"
     {
         generer("pp_egal();");
         (yyval.ival) = 0;
     }
#line 1779 "atlas.tab.c"
    break;

  case 69: /* expr: expr TOK_SUP_EG expr  */
#line 451 "atlas.y"
     {
         generer("pg_egal();");
         (yyval.ival) = 0;
     }
#line 1788 "atlas.tab.c"
    break;

  case 70: /* expr: expr TOK_ET expr  */
#line 456 "atlas.y"
     {
         generer("et();");
         (yyval.ival) = 0;
     }
#line 1797 "atlas.tab.c"
    break;

  case 71: /* expr: expr TOK_OU expr  */
#line 461 "atlas.y"
     {
         generer("ou();");
         (yyval.ival) = 0;
     }
#line 1806 "atlas.tab.c"
    break;

  case 72: /* expr: TOK_NON expr  */
#line 466 "atlas.y"
     {
         generer("non();");
         (yyval.ival) = 0;
     }
#line 1815 "atlas.tab.c"
    break;

  case 73: /* expr: TOK_PAREN_OUV expr TOK_PAREN_FERM  */
#line 471 "atlas.y"
     {
         (yyval.ival) = (yyvsp[-1].ival);
     }
#line 1823 "atlas.tab.c"
    break;


#line 1827 "atlas.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 475 "atlas.y"


/*  ═════════════════════════════════════════════════════════
    FONCTIONS UTILITAIRES
    ════════════════════════════════════════════════════════ */

int ajouter_var(const char *nom, int is_const, int valeur) {
     if (nb_vars >= 100) {
         fprintf(stderr, "Erreur : trop de variables\n");
         return -1;
     }
     strcpy(variables[nb_vars].nom, nom);
     variables[nb_vars].type = is_const;
     variables[nb_vars].adresse = adresse_var;
     variables[nb_vars].valeur = valeur;

     if (!is_const) {  /* Only reserve space for variables, not constants */
         adresse_var++;
     }

     nb_vars++;
     return variables[nb_vars - 1].adresse;
}

int chercher_var(const char *nom) {
    for (int i = 0; i < nb_vars; i++) {
        if (strcmp(variables[i].nom, nom) == 0)
            return variables[i].adresse;
    }
    fprintf(stderr, "Erreur : variable '%s' non declaree\n", nom);
    return -1;
}

void yyerror(const char *msg) {
     extern int yylineno;
     fprintf(stderr, "[ERREUR SYNTAXIQUE] ligne %d : %s\n", yylineno, msg);
}

int main(int argc, char *argv[]) {
    FILE *f = NULL;

    if (argc >= 2) {
        f = fopen(argv[1], "r");
        if (!f) {
            fprintf(stderr, "Impossible d'ouvrir : %s\n", argv[1]);
            return 1;
        }
        yyin = f;
    }
    
    int result = yyparse();

    if (result == 0) {
        printf("#include \"simulator.c\"\n\n");
        printf("int main() {\n");
        printf("    ouverture_bloc();\n");
        printf("    reserver_var(%d);\n", adresse_var);
        
        /* Output generated instructions with labels */
        for (int i = 0; i < code_idx; i++) {
            printf("L%d: %s\n", i, code[i].instruction);
        }
        
        printf("L%d: fermeture_bloc();\n", code_idx);
        printf("    return 0;\n");
        printf("}\n");
    }

    if (f) fclose(f);
    return result;
}
