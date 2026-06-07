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
        sprintf(code[label].instruction, "bsf %d", target);
    } else if (strncmp(code[label].instruction, "bra", 3) == 0) {
        sprintf(code[label].instruction, "bra %d", target);
    }
}

// struct for variables management
typedef struct {
    char nom[64];
    int type;
    int data_type;
    int adresse;
    int valeur;
} Variable;

Variable variables[100];
int nb_vars = 0;
int adresse_var = 0;
int max_adresse_var = 0;
int current_dec_type = 0;
int current_bsf_index = 0;

int get_data_type(const char *nom) {
    for (int i = 0; i < nb_vars; i++) {
        if (strcmp(variables[i].nom, nom) == 0)
            return variables[i].data_type;
    }
    return -1;
}

int is_const(const char *nom) {
    for (int i = 0; i < nb_vars; i++) {
        if (strcmp(variables[i].nom, nom) == 0)
            return variables[i].type == 1;
    }
    return 0;
}

const char* type_name(int t) {
    return t == 1 ? "ent" : (t == 2 ? "bool" : "inconnu");
}

int etiq = 0;

void yyerror(const char *msg);
int yylex();

int ajouter_var(const char *nom, int is_const, int valeur, int data_type);
int chercher_var(const char *nom);
int chercher_var_silence(const char *nom);


#line 155 "atlas.tab.c"

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
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_optional_point = 62,            /* optional_point  */
  YYSYMBOL_declarations = 63,              /* declarations  */
  YYSYMBOL_declaration = 64,               /* declaration  */
  YYSYMBOL_const_declaration = 65,         /* const_declaration  */
  YYSYMBOL_const_items = 66,               /* const_items  */
  YYSYMBOL_const_item = 67,                /* const_item  */
  YYSYMBOL_const_expr = 68,                /* const_expr  */
  YYSYMBOL_var_declaration = 69,           /* var_declaration  */
  YYSYMBOL_var_items = 70,                 /* var_items  */
  YYSYMBOL_var_item = 71,                  /* var_item  */
  YYSYMBOL_type = 72,                      /* type  */
  YYSYMBOL_var_list = 73,                  /* var_list  */
  YYSYMBOL_instructions = 74,              /* instructions  */
  YYSYMBOL_instruction = 75,               /* instruction  */
  YYSYMBOL_instr_io = 76,                  /* instr_io  */
  YYSYMBOL_instr_affectation = 77,         /* instr_affectation  */
  YYSYMBOL_78_2 = 78,                      /* @2  */
  YYSYMBOL_instr_si = 79,                  /* instr_si  */
  YYSYMBOL_80_3 = 80,                      /* @3  */
  YYSYMBOL_cond_si = 81,                   /* cond_si  */
  YYSYMBOL_instr_pour = 82,                /* instr_pour  */
  YYSYMBOL_83_4 = 83,                      /* @4  */
  YYSYMBOL_84_5 = 84,                      /* $@5  */
  YYSYMBOL_85_6 = 85,                      /* @6  */
  YYSYMBOL_86_7 = 86,                      /* @7  */
  YYSYMBOL_87_8 = 87,                      /* @8  */
  YYSYMBOL_88_9 = 88,                      /* @9  */
  YYSYMBOL_89_10 = 89,                     /* @10  */
  YYSYMBOL_pour_opt_step = 90,             /* pour_opt_step  */
  YYSYMBOL_91_11 = 91,                     /* @11  */
  YYSYMBOL_instr_tantque = 92,             /* instr_tantque  */
  YYSYMBOL_loop_start = 93,                /* loop_start  */
  YYSYMBOL_cond_tantque = 94,              /* cond_tantque  */
  YYSYMBOL_instr_passer = 95,              /* instr_passer  */
  YYSYMBOL_expr = 96                       /* expr  */
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
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

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
       0,   156,   156,   153,   169,   171,   175,   177,   181,   182,
     186,   190,   191,   195,   199,   206,   207,   208,   209,   210,
     211,   212,   216,   220,   221,   225,   229,   230,   234,   238,
     246,   247,   250,   251,   252,   253,   254,   255,   259,   271,
     282,   286,   290,   296,   306,   305,   333,   338,   337,   350,
     359,   372,   376,   382,   387,   396,   401,   404,   371,   446,
     457,   456,   475,   485,   492,   501,   513,   520,   527,   534,
     559,   568,   577,   586,   595,   604,   613,   622,   631,   636,
     641,   646,   651,   656,   661,   670,   679,   688
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
  "programme", "$@1", "optional_point", "declarations", "declaration",
  "const_declaration", "const_items", "const_item", "const_expr",
  "var_declaration", "var_items", "var_item", "type", "var_list",
  "instructions", "instruction", "instr_io", "instr_affectation", "@2",
  "instr_si", "@3", "cond_si", "instr_pour", "@4", "$@5", "@6", "@7", "@8",
  "@9", "@10", "pour_opt_step", "@11", "instr_tantque", "loop_start",
  "cond_tantque", "instr_passer", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    -9,    33,   -12,   -78,   -78,     9,    -2,     2,   -78,
     -78,   -78,   -78,   -78,   -78,    -2,   -78,     7,     8,    15,
       2,   -78,   193,   -78,   -78,   -27,    29,    40,   -78,    46,
      47,   -21,   -21,     1,    48,   -78,    56,    51,   -78,    62,
     124,   -78,    50,    52,   -78,   193,   -78,   -78,    72,    54,
     -78,    59,   -31,    64,   -78,   -78,   -21,   -21,    55,   -78,
     -78,   -78,   -21,   328,   328,   -78,   -78,   -21,   194,   -78,
     -78,    58,   -78,   -78,   -78,    65,   -21,   193,   307,   -78,
     -78,   -78,   -31,   113,    66,   -78,   -78,   -21,   215,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   237,   -78,    95,   -21,   -78,   -78,   -78,
     -78,   259,   141,   -78,    18,   -31,   -31,   -31,   -31,   -31,
     -78,   -78,   281,   -78,   366,   349,    -8,    -8,    80,    80,
      80,   -78,   383,   383,   383,   383,   383,   383,   100,   -78,
     328,   193,    97,   -78,   -78,    11,    11,   -78,   -78,   -78,
     -78,   -78,   -21,   159,   -78,   328,   -78,   104,   -78,   -21,
     328,    96,   -78,   -78,   -21,   -78,   328,    98,   193,   176,
     -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,     0,     0,     0,     2,
       7,     8,     9,    26,    27,    22,    23,     0,     0,     0,
      10,    11,     0,    24,    28,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,    66,     0,     0,    63,     0,
       0,    30,     0,     0,    34,     0,    35,    36,     0,     0,
      25,     0,     0,     0,    38,    39,     0,     0,     0,    67,
      68,    69,     0,    40,    41,    42,    43,     0,     0,    51,
      44,     4,    31,    32,    33,     0,     0,     0,     0,    37,
      29,    15,     0,     0,     0,    86,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     5,     3,    46,
      47,     0,     0,    65,     0,     0,     0,     0,     0,     0,
      13,    14,     0,    87,    84,    85,    70,    71,    72,    73,
      74,    75,    78,    80,    81,    82,    83,    79,    87,    52,
      45,     0,    87,    62,    21,    16,    17,    18,    19,    20,
      76,    49,     0,     0,    64,    53,    48,     0,    54,     0,
      55,    59,    60,    56,     0,    57,    61,     0,     0,     0,
      58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   108,   -77,
     -78,   -78,   114,   -78,   -78,   -43,   -39,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    22,   108,     6,    10,    11,    20,    21,    83,
      12,    15,    16,    17,    25,    40,    41,    42,    43,   106,
      44,   141,    45,    46,   105,   152,   157,   159,   161,   165,
     167,   163,   164,    47,    48,    77,    49,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    72,    75,     1,    68,   114,    13,    14,    81,    56,
      18,    19,    57,     7,     8,     9,    78,    58,    59,    60,
      61,    82,    50,    51,    85,    86,    93,    94,    95,    96,
      88,    62,     3,     4,   112,   103,    72,     5,   145,   146,
     147,   148,   149,    65,   111,   117,   118,   119,    24,    26,
     115,   116,   117,   118,   119,   122,    27,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   144,    52,    72,   140,    29,    30,    31,    32,    33,
      34,    35,    36,    53,   109,    37,    56,    54,    55,    57,
      66,    38,    69,    70,    58,    59,    60,    61,   153,    73,
      80,    74,    56,    79,    84,    57,    39,    87,    67,   107,
      58,    59,    60,    61,    72,   121,   139,    96,   151,   162,
     155,   154,   168,   110,    76,   169,   158,   160,    28,    23,
      72,    71,   166,     0,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,    37,   115,   116,   117,   118,   119,
      38,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,    37,   120,     0,     0,    39,     0,    38,   143,    29,
      30,    31,    32,    33,    34,    35,    36,     0,   156,    37,
       0,     0,    39,     0,     0,    38,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,    37,     0,     0,     0,
      39,   170,    38,    29,    30,    31,    32,    33,    34,    35,
      36,     0,   104,    37,     0,     0,     0,    39,     0,    38,
       0,     0,    89,    90,     0,     0,    91,    92,    93,    94,
      95,    96,     0,     0,    39,     0,     0,    97,    98,    99,
     100,   101,   102,    89,    90,     0,     0,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,     0,    89,    90,     0,   123,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,     0,    89,    90,     0,
     138,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,     0,    89,
      90,     0,   142,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
       0,   113,     0,     0,   150,    89,    90,     0,     0,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,    89,    90,     0,     0,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,    89,     0,     0,
       0,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,    91,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,    91,    92,    93,    94,    95,
      96
};

static const yytype_int16 yycheck[] =
{
      32,    40,    45,     3,    36,    82,     8,     9,    39,    30,
       8,     9,    33,     4,     5,     6,    48,    38,    39,    40,
      41,    52,    49,    50,    56,    57,    34,    35,    36,    37,
      62,    52,    41,     0,    77,    67,    75,    49,   115,   116,
     117,   118,   119,    42,    76,    34,    35,    36,    41,    41,
      32,    33,    34,    35,    36,    87,    41,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    53,    43,   112,   106,    10,    11,    12,    13,    14,
      15,    16,    17,    43,    19,    20,    30,    41,    41,    33,
      42,    26,    41,    31,    38,    39,    40,    41,   141,    49,
      41,    49,    30,    49,    40,    33,    41,    52,    52,    51,
      38,    39,    40,    41,   153,    49,    21,    37,    18,    23,
     152,    24,    24,    58,    52,   168,    22,   159,    20,    15,
     169,     7,   164,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    20,    32,    33,    34,    35,    36,
      26,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    49,    -1,    -1,    41,    -1,    26,    27,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      -1,    -1,    41,    -1,    -1,    26,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      41,    25,    26,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    18,    20,    -1,    -1,    -1,    41,    -1,    26,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    41,    -1,    -1,    43,    44,    45,
      46,    47,    48,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    28,    29,    -1,    53,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    -1,    28,    29,    -1,
      53,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    28,
      29,    -1,    53,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      -1,    24,    -1,    -1,    53,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    28,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    32,    33,    34,    35,    36,
      37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    60,    41,     0,    49,    63,     4,     5,     6,
      64,    65,    69,     8,     9,    70,    71,    72,     8,     9,
      66,    67,    61,    71,    41,    73,    41,    41,    67,    10,
      11,    12,    13,    14,    15,    16,    17,    20,    26,    41,
      74,    75,    76,    77,    79,    81,    82,    92,    93,    95,
      49,    50,    43,    43,    41,    41,    30,    33,    38,    39,
      40,    41,    52,    96,    96,    42,    42,    52,    96,    41,
      31,     7,    75,    49,    49,    74,    52,    94,    96,    49,
      41,    39,    52,    68,    40,    96,    96,    52,    96,    28,
      29,    32,    33,    34,    35,    36,    37,    43,    44,    45,
      46,    47,    48,    96,    18,    83,    78,    51,    62,    19,
      58,    96,    74,    24,    68,    32,    33,    34,    35,    36,
      49,    49,    96,    53,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    53,    21,
      96,    80,    53,    27,    53,    68,    68,    68,    68,    68,
      53,    18,    84,    74,    24,    96,    19,    85,    22,    86,
      96,    87,    23,    90,    91,    88,    96,    89,    24,    74,
      25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    61,    60,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    69,    70,    70,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    76,    78,    77,    79,    80,    79,    81,
      81,    83,    84,    85,    86,    87,    88,    89,    82,    90,
      91,    90,    92,    93,    94,    94,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     1,     0,     2,     1,     1,
       2,     1,     2,     5,     5,     1,     3,     3,     3,     3,
       3,     3,     2,     1,     2,     3,     1,     1,     1,     3,
       1,     2,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     0,     4,     3,     0,     6,     5,
       3,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     3,     4,     1,     4,     2,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3
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
  case 2: /* $@1: %empty  */
#line 156 "atlas.y"
    {
        generer("ouverture-bloc");
        char buf[256];
        sprintf(buf, "reserver-var %d", adresse_var);
        generer(buf);
    }
#line 1417 "atlas.tab.c"
    break;

  case 3: /* programme: TOK_PROGRAMME TOK_IDENTIFIANT TOK_POINT_VIRGULE declarations TOK_DEBUT $@1 instructions TOK_FIN optional_point  */
#line 164 "atlas.y"
    {
        generer("fermeture-bloc");
    }
#line 1425 "atlas.tab.c"
    break;

  case 13: /* const_item: TOK_ENT TOK_IDENTIFIANT TOK_EGAL const_expr TOK_POINT_VIRGULE  */
#line 196 "atlas.y"
     {
         ajouter_var((yyvsp[-3].sval), 1, (yyvsp[-1].ival), 1);
     }
#line 1433 "atlas.tab.c"
    break;

  case 14: /* const_item: TOK_BOOL TOK_IDENTIFIANT TOK_EGAL TOK_BOOLEEN TOK_POINT_VIRGULE  */
#line 200 "atlas.y"
     {
         ajouter_var((yyvsp[-3].sval), 1, (yyvsp[-1].ival), 2);
     }
#line 1441 "atlas.tab.c"
    break;

  case 15: /* const_expr: TOK_ENTIER  */
#line 206 "atlas.y"
                { (yyval.ival) = (yyvsp[0].ival); }
#line 1447 "atlas.tab.c"
    break;

  case 16: /* const_expr: const_expr TOK_PLUS const_expr  */
#line 207 "atlas.y"
                                      { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1453 "atlas.tab.c"
    break;

  case 17: /* const_expr: const_expr TOK_MOINS const_expr  */
#line 208 "atlas.y"
                                       { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1459 "atlas.tab.c"
    break;

  case 18: /* const_expr: const_expr TOK_MULT const_expr  */
#line 209 "atlas.y"
                                      { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1465 "atlas.tab.c"
    break;

  case 19: /* const_expr: const_expr TOK_DIV const_expr  */
#line 210 "atlas.y"
                                     { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
#line 1471 "atlas.tab.c"
    break;

  case 20: /* const_expr: const_expr TOK_MOD const_expr  */
#line 211 "atlas.y"
                                     { (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); }
#line 1477 "atlas.tab.c"
    break;

  case 21: /* const_expr: TOK_PAREN_OUV const_expr TOK_PAREN_FERM  */
#line 212 "atlas.y"
                                               { (yyval.ival) = (yyvsp[-1].ival); }
#line 1483 "atlas.tab.c"
    break;

  case 26: /* type: TOK_ENT  */
#line 229 "atlas.y"
              { (yyval.ival) = 1; current_dec_type = 1; }
#line 1489 "atlas.tab.c"
    break;

  case 27: /* type: TOK_BOOL  */
#line 230 "atlas.y"
                { (yyval.ival) = 2; current_dec_type = 2; }
#line 1495 "atlas.tab.c"
    break;

  case 28: /* var_list: TOK_IDENTIFIANT  */
#line 235 "atlas.y"
     {
         ajouter_var((yyvsp[0].sval), 0, 0, current_dec_type);
     }
#line 1503 "atlas.tab.c"
    break;

  case 29: /* var_list: var_list TOK_VIRGULE TOK_IDENTIFIANT  */
#line 239 "atlas.y"
     {
         ajouter_var((yyvsp[0].sval), 0, 0, current_dec_type);
     }
#line 1511 "atlas.tab.c"
    break;

  case 38: /* instr_io: TOK_LIRE TOK_IDENTIFIANT  */
#line 260 "atlas.y"
     {
         if (is_const((yyvsp[0].sval))) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: 'lire' ne peut pas modifier une constante '%s'\n", yylineno, (yyvsp[0].sval));
             exit(1);
         }
         char buf[256];
         sprintf(buf, "empiler-adr %d", chercher_var((yyvsp[0].sval)));
         
         generer(buf);
         generer("lire");
     }
#line 1527 "atlas.tab.c"
    break;

  case 39: /* instr_io: TOK_LIRERC TOK_IDENTIFIANT  */
#line 272 "atlas.y"
     {
         if (is_const((yyvsp[0].sval))) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: 'lireRC' ne peut pas modifier une constante '%s'\n", yylineno, (yyvsp[0].sval));
             exit(1);
         }
         char buf[256];
         sprintf(buf, "empiler-adr %d", chercher_var((yyvsp[0].sval)));
         generer(buf);
         generer("lireRC");
     }
#line 1542 "atlas.tab.c"
    break;

  case 40: /* instr_io: TOK_ECRIRE expr  */
#line 283 "atlas.y"
     {
         generer("ecrire");
     }
#line 1550 "atlas.tab.c"
    break;

  case 41: /* instr_io: TOK_ECRIRERC expr  */
#line 287 "atlas.y"
     {
         generer("ecrireRC");
     }
#line 1558 "atlas.tab.c"
    break;

  case 42: /* instr_io: TOK_IMPRIMER TOK_CHAINE  */
#line 291 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "imprimer %s", (yyvsp[0].sval));
         generer(buf);
     }
#line 1568 "atlas.tab.c"
    break;

  case 43: /* instr_io: TOK_IMPRIMERRC TOK_CHAINE  */
#line 297 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "imprimerRC %s", (yyvsp[0].sval));
         generer(buf);
     }
#line 1578 "atlas.tab.c"
    break;

  case 44: /* @2: %empty  */
#line 306 "atlas.y"
     {
         int idx = chercher_var((yyvsp[-1].sval));
         if (idx == -1) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: variable '%s' non declarée\n", yylineno, (yyvsp[-1].sval));
            exit(1);
         } else if (is_const((yyvsp[-1].sval))) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: tentative d'affectation a une constante '%s'\n", yylineno, (yyvsp[-1].sval));
            exit(1);
         }
         char buf[256];
         sprintf(buf, "empiler-adr %d", idx);
         generer(buf);
         (yyval.ival) = get_data_type((yyvsp[-1].sval));
     }
#line 1597 "atlas.tab.c"
    break;

  case 45: /* instr_affectation: TOK_IDENTIFIANT TOK_AFFECT @2 expr  */
#line 321 "atlas.y"
     {
         int expected_type = (yyvsp[-1].ival);
         if ((yyvsp[0].ival) != expected_type && expected_type != -1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: type incompatible dans l'affectation (attendu: %s, trouve: %s)\n",
                                 yylineno, type_name(expected_type), type_name((yyvsp[0].ival)));
            exit(1);
         }
         generer("affect");
     }
#line 1611 "atlas.tab.c"
    break;

  case 46: /* instr_si: cond_si instructions TOK_FSI  */
#line 334 "atlas.y"
     {
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1619 "atlas.tab.c"
    break;

  case 47: /* @3: %empty  */
#line 338 "atlas.y"
       {
           (yyval.ival) = code_idx;
           generer("bra 0");
           patcher((yyvsp[-2].ival), code_idx);
       }
#line 1629 "atlas.tab.c"
    break;

  case 48: /* instr_si: cond_si instructions TOK_SINON @3 instructions TOK_FSI  */
#line 344 "atlas.y"
     {
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1637 "atlas.tab.c"
    break;

  case 49: /* cond_si: TOK_SI TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_ALORS  */
#line 351 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'si' doit etre un booleen\n", yylineno);
            exit(1);
         }
         generer("bsf 0");
         (yyval.ival) = code_idx -1;
     }
#line 1650 "atlas.tab.c"
    break;

  case 50: /* cond_si: TOK_SI expr TOK_ALORS  */
#line 360 "atlas.y"
     {
         if ((yyvsp[-1].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'si' doit etre un booleen\n", yylineno);
            exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
     }
#line 1663 "atlas.tab.c"
    break;

  case 51: /* @4: %empty  */
#line 372 "atlas.y"
    {
        (yyval.ival) = chercher_var((yyvsp[0].sval));
    }
#line 1671 "atlas.tab.c"
    break;

  case 52: /* $@5: %empty  */
#line 376 "atlas.y"
    {
        char buf[256];
        sprintf(buf, "empiler-adr %d", (yyvsp[-1].ival)); 
        generer(buf);
    }
#line 1681 "atlas.tab.c"
    break;

  case 53: /* @6: %empty  */
#line 382 "atlas.y"
    {
        generer("affect");
        (yyval.ival) = (yyvsp[-3].ival); // $7: loop var address
    }
#line 1690 "atlas.tab.c"
    break;

  case 54: /* @7: %empty  */
#line 387 "atlas.y"
    {
        int slot = adresse_var++;
        if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot); 
        generer(buf);
        (yyval.ival) = slot;
    }
#line 1703 "atlas.tab.c"
    break;

  case 55: /* @8: %empty  */
#line 396 "atlas.y"
    {
        generer("affect");
        (yyval.ival) = (yyvsp[-1].ival); // $11: limit slot address
    }
#line 1712 "atlas.tab.c"
    break;

  case 56: /* @9: %empty  */
#line 401 "atlas.y"
    {
        (yyval.ival) = code_idx; // $13: START OF LOOP LABEL
    }
#line 1720 "atlas.tab.c"
    break;

  case 57: /* @10: %empty  */
#line 404 "atlas.y"
    {
        char buf[256];
        sprintf(buf, "empiler-adr %d", (yyvsp[-10].ival)); 
        generer(buf);
        generer("valeur-pile");
        
        sprintf(buf, "empiler-adr %d", (yyvsp[-2].ival)); 
        generer(buf);
        generer("valeur-pile");
        generer("pp-egal");
        (yyval.ival) = code_idx; // $14: BSF index
        generer("bsf 0");
    }
#line 1738 "atlas.tab.c"
    break;

  case 58: /* instr_pour: TOK_POUR TOK_IDENTIFIANT @4 TOK_DEPUIS $@5 expr @6 TOK_JUSQUA @7 expr @8 pour_opt_step @9 @10 TOK_FAIRE instructions TOK_FPOUR  */
#line 418 "atlas.y"
    {
        char buf[256];
        // Increment: var = var + step
        sprintf(buf, "empiler-adr %d", (yyvsp[-14].ival)); 
        generer(buf); // Address for assignment
        
        sprintf(buf, "empiler-adr %d", (yyvsp[-14].ival)); 
        generer(buf);
        generer("valeur-pile");
        
        sprintf(buf, "empiler-adr %d", (yyvsp[-5].ival)); 
        generer(buf);
        generer("valeur-pile");
        
        generer("plus");
        generer("affect");
        
        // Jump back
        sprintf(buf, "bra %d", (yyvsp[-4].ival)); 
        generer(buf);
        
        // Patch exit
        patcher((yyvsp[-3].ival), code_idx);
    }
#line 1767 "atlas.tab.c"
    break;

  case 59: /* pour_opt_step: %empty  */
#line 446 "atlas.y"
    {
        int slot = adresse_var++;
        if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot);
        generer(buf);
        generer("empiler-val 1");
        generer("affect");
        (yyval.ival) = slot;
    }
#line 1782 "atlas.tab.c"
    break;

  case 60: /* @11: %empty  */
#line 457 "atlas.y"
    {
        int slot = adresse_var++;
        if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot);
        generer(buf);
        (yyval.ival) = slot;
    }
#line 1795 "atlas.tab.c"
    break;

  case 61: /* pour_opt_step: TOK_PARPAS @11 expr  */
#line 466 "atlas.y"
    {
        generer("affect");
        (yyval.ival) = (yyvsp[-1].ival);
    }
#line 1804 "atlas.tab.c"
    break;

  case 62: /* instr_tantque: loop_start cond_tantque instructions TOK_FTQ  */
#line 476 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "bra %d", (yyvsp[-3].ival));
         generer(buf);
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1815 "atlas.tab.c"
    break;

  case 63: /* loop_start: TOK_TANTQUE  */
#line 486 "atlas.y"
     {
         (yyval.ival) = code_idx;
     }
#line 1823 "atlas.tab.c"
    break;

  case 64: /* cond_tantque: TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_FAIRE  */
#line 493 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'tantque' doit etre un booleen\n", yylineno);
             exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
     }
#line 1836 "atlas.tab.c"
    break;

  case 65: /* cond_tantque: expr TOK_FAIRE  */
#line 502 "atlas.y"
     {
         if ((yyvsp[-1].ival) != 2) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'tantque' doit etre un booleen\n", yylineno);
             exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
     }
#line 1849 "atlas.tab.c"
    break;

  case 66: /* instr_passer: TOK_PASSER  */
#line 514 "atlas.y"
     {
         generer("passer");
     }
#line 1857 "atlas.tab.c"
    break;

  case 67: /* expr: TOK_ENTIER  */
#line 521 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler-val %d", (yyvsp[0].ival));
         generer(buf);
         (yyval.ival) = 1;
     }
#line 1868 "atlas.tab.c"
    break;

  case 68: /* expr: TOK_BOOLEEN  */
#line 528 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler-val %d", (yyvsp[0].ival));
         generer(buf);
         (yyval.ival) = 2;
     }
#line 1879 "atlas.tab.c"
    break;

  case 69: /* expr: TOK_IDENTIFIANT  */
#line 535 "atlas.y"
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
             sprintf(buf, "empiler-val %d", variables[idx].valeur);
             generer(buf);
             (yyval.ival) = variables[idx].data_type;
         } else { /* variable */
             char buf[256];
             sprintf(buf, "empiler-adr %d", variables[idx].adresse);
             generer(buf);
             generer("valeur-pile");
             (yyval.ival) = variables[idx].data_type;
         }
     }
#line 1908 "atlas.tab.c"
    break;

  case 70: /* expr: expr TOK_PLUS expr  */
#line 560 "atlas.y"
     {
        if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '+' requiert des entiers\n", yylineno);
            exit(1);
        }
        generer("plus");
        (yyval.ival) = 1;  // result is entier
     }
#line 1921 "atlas.tab.c"
    break;

  case 71: /* expr: expr TOK_MOINS expr  */
#line 569 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '-' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("moins");
         (yyval.ival) = 1;
     }
#line 1934 "atlas.tab.c"
    break;

  case 72: /* expr: expr TOK_MULT expr  */
#line 578 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '*' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("mult");
         (yyval.ival) = 1;
     }
#line 1947 "atlas.tab.c"
    break;

  case 73: /* expr: expr TOK_DIV expr  */
#line 587 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '/' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("div");
         (yyval.ival) = 1;
     }
#line 1960 "atlas.tab.c"
    break;

  case 74: /* expr: expr TOK_MOD expr  */
#line 596 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '%%' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("mod");
         (yyval.ival) = 1;
     }
#line 1973 "atlas.tab.c"
    break;

  case 75: /* expr: expr TOK_PUISS expr  */
#line 605 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'puiss' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("puiss");
         (yyval.ival) = 1;
     }
#line 1986 "atlas.tab.c"
    break;

  case 76: /* expr: TOK_VALABS TOK_PAREN_OUV expr TOK_PAREN_FERM  */
#line 614 "atlas.y"
     {
         if ((yyvsp[-1].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'valabs' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("valabs");
         (yyval.ival) = 1;
     }
#line 1999 "atlas.tab.c"
    break;

  case 77: /* expr: TOK_MOINS expr  */
#line 623 "atlas.y"
     {
         if ((yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '-' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("neg");
         (yyval.ival) = 1;
     }
#line 2012 "atlas.tab.c"
    break;

  case 78: /* expr: expr TOK_EGAL expr  */
#line 632 "atlas.y"
     {
         generer("egal");
         (yyval.ival) = 2;
     }
#line 2021 "atlas.tab.c"
    break;

  case 79: /* expr: expr TOK_DIFF expr  */
#line 637 "atlas.y"
     {
         generer("dif");
         (yyval.ival) = 2;
     }
#line 2030 "atlas.tab.c"
    break;

  case 80: /* expr: expr TOK_INF expr  */
#line 642 "atlas.y"
     {
         generer("pps");
         (yyval.ival) = 2;
     }
#line 2039 "atlas.tab.c"
    break;

  case 81: /* expr: expr TOK_SUP expr  */
#line 647 "atlas.y"
     {
         generer("pgs");
         (yyval.ival) = 2;
     }
#line 2048 "atlas.tab.c"
    break;

  case 82: /* expr: expr TOK_INF_EG expr  */
#line 652 "atlas.y"
     {
         generer("pp-egal");
         (yyval.ival) = 2;
     }
#line 2057 "atlas.tab.c"
    break;

  case 83: /* expr: expr TOK_SUP_EG expr  */
#line 657 "atlas.y"
     {
         generer("pg-egal");
         (yyval.ival) = 2;
     }
#line 2066 "atlas.tab.c"
    break;

  case 84: /* expr: expr TOK_ET expr  */
#line 662 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2 || (yyvsp[0].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'et' requiert des booleens\n", yylineno);
            exit(1);
         }
         generer("et");
         (yyval.ival) = 2;
     }
#line 2079 "atlas.tab.c"
    break;

  case 85: /* expr: expr TOK_OU expr  */
#line 671 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2 || (yyvsp[0].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'ou' requiert des booleens\n", yylineno);
            exit(1);
         }
         generer("ou");
         (yyval.ival) = 2;
     }
#line 2092 "atlas.tab.c"
    break;

  case 86: /* expr: TOK_NON expr  */
#line 680 "atlas.y"
     {
         if ((yyvsp[0].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'non' requiert un booleen\n", yylineno);
            exit(1);
         }
         generer("non");
         (yyval.ival) = 2;
     }
#line 2105 "atlas.tab.c"
    break;

  case 87: /* expr: TOK_PAREN_OUV expr TOK_PAREN_FERM  */
#line 689 "atlas.y"
     {
         (yyval.ival) = (yyvsp[-1].ival);
     }
#line 2113 "atlas.tab.c"
    break;


#line 2117 "atlas.tab.c"

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

#line 693 "atlas.y"


/*  ═════════════════════════════════════════════════════════
    FONCTIONS UTILITAIRES
    ════════════════════════════════════════════════════════ */

int ajouter_var(const char *nom, int is_const, int valeur, int data_type) {
     if (nb_vars >= 100) {
         fprintf(stderr, "Erreur : trop de variables\n");
         return -1;
     }

     if (chercher_var_silence(nom) != -1) {
         fprintf(stderr, "Erreur : variable '%s' deja declaree\n", nom);
         return -1;
     }

     strcpy(variables[nb_vars].nom, nom);
     variables[nb_vars].type = is_const;
     variables[nb_vars].data_type = data_type;
     variables[nb_vars].adresse = adresse_var;
     variables[nb_vars].valeur = valeur;

     if (!is_const) {
          adresse_var++;
          if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
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

int chercher_var_silence(const char *nom) {
    for (int i = 0; i < nb_vars; i++) {
        if (strcmp(variables[i].nom, nom) == 0)
            return variables[i].adresse;
    }
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
        // Patch reserver-var with max_adresse_var
        if (code_idx > 1 && strncmp(code[1].instruction, "reserver-var", 12) == 0) {
            sprintf(code[1].instruction, "reserver-var %d", max_adresse_var);
        }
        
        char map_fileName[256];
        if (argc >= 2) {
            strcpy(map_fileName, argv[1]);
            char *dot = strrchr(map_fileName, '.');
            if (dot) strcpy(dot, ".map");
            else strcat(map_fileName, ".map");
        } else {
            strcpy(map_fileName, "output.map");
        }
        FILE *map_file = fopen(map_fileName, "w");
        if (!map_file) {
            fprintf(stderr, "Impossible de creer : %s\n", map_fileName);
            return 1;
        }
        
        for (int i = 0; i < code_idx; i++) {
            fprintf(map_file, "%d\t%s\n", i + 1, code[i].instruction);
        }
        fclose(map_file);
        printf("MAP code generated: %s\n", map_fileName);
    }

    if (f) fclose(f);
    return result;
}
