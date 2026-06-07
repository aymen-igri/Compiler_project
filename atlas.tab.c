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

int ajouter_var(const char *nom, int type, int data_type, int valeur);
int chercher_var(const char *nom);


#line 153 "atlas.tab.c"

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
  YYSYMBOL_optional_point = 61,            /* optional_point  */
  YYSYMBOL_declarations = 62,              /* declarations  */
  YYSYMBOL_declaration = 63,               /* declaration  */
  YYSYMBOL_const_declaration = 64,         /* const_declaration  */
  YYSYMBOL_const_items = 65,               /* const_items  */
  YYSYMBOL_const_item = 66,                /* const_item  */
  YYSYMBOL_const_expr = 67,                /* const_expr  */
  YYSYMBOL_var_declaration = 68,           /* var_declaration  */
  YYSYMBOL_var_items = 69,                 /* var_items  */
  YYSYMBOL_var_item = 70,                  /* var_item  */
  YYSYMBOL_type = 71,                      /* type  */
  YYSYMBOL_var_list = 72,                  /* var_list  */
  YYSYMBOL_instructions = 73,              /* instructions  */
  YYSYMBOL_instruction = 74,               /* instruction  */
  YYSYMBOL_instr_io = 75,                  /* instr_io  */
  YYSYMBOL_instr_affectation = 76,         /* instr_affectation  */
  YYSYMBOL_77_1 = 77,                      /* @1  */
  YYSYMBOL_instr_si = 78,                  /* instr_si  */
  YYSYMBOL_cond_si = 79,                   /* cond_si  */
  YYSYMBOL_else_marker = 80,               /* else_marker  */
  YYSYMBOL_instr_pour = 81,                /* instr_pour  */
  YYSYMBOL_82_2 = 82,                      /* @2  */
  YYSYMBOL_83_3 = 83,                      /* $@3  */
  YYSYMBOL_84_4 = 84,                      /* @4  */
  YYSYMBOL_85_5 = 85,                      /* @5  */
  YYSYMBOL_86_6 = 86,                      /* @6  */
  YYSYMBOL_87_7 = 87,                      /* @7  */
  YYSYMBOL_88_8 = 88,                      /* @8  */
  YYSYMBOL_pour_opt_step = 89,             /* pour_opt_step  */
  YYSYMBOL_90_9 = 90,                      /* @9  */
  YYSYMBOL_instr_tantque = 91,             /* instr_tantque  */
  YYSYMBOL_loop_start = 92,                /* loop_start  */
  YYSYMBOL_cond_tantque = 93,              /* cond_tantque  */
  YYSYMBOL_instr_passer = 94,              /* instr_passer  */
  YYSYMBOL_expr = 95                       /* expr  */
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
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

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
       0,   152,   152,   161,   163,   167,   169,   173,   174,   178,
     182,   183,   187,   191,   198,   199,   200,   201,   202,   203,
     204,   208,   212,   213,   217,   221,   222,   226,   230,   238,
     239,   242,   243,   244,   245,   246,   247,   251,   263,   274,
     278,   282,   288,   298,   297,   325,   329,   336,   346,   359,
     369,   373,   380,   385,   393,   398,   401,   368,   437,   447,
     446,   464,   474,   481,   490,   502,   509,   516,   523,   548,
     557,   566,   575,   584,   593,   602,   611,   620,   625,   630,
     635,   640,   645,   650,   659,   668,   677
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
  "programme", "optional_point", "declarations", "declaration",
  "const_declaration", "const_items", "const_item", "const_expr",
  "var_declaration", "var_items", "var_item", "type", "var_list",
  "instructions", "instruction", "instr_io", "instr_affectation", "@1",
  "instr_si", "cond_si", "else_marker", "instr_pour", "@2", "$@3", "@4",
  "@5", "@6", "@7", "@8", "pour_opt_step", "@9", "instr_tantque",
  "loop_start", "cond_tantque", "instr_passer", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -36,     7,   -14,   -39,   -39,    84,    22,    39,   166,
     -39,   -39,   -39,   -39,   -39,    22,   -39,   -28,    -3,     4,
      39,   -39,    13,    31,     3,     3,    15,    32,   -39,    66,
      44,   -39,    63,     8,   -39,    46,    48,   -39,   166,   -39,
     -39,   305,    49,   -39,   -39,    42,   -26,    57,   -39,   -39,
     -39,     3,     3,    51,   -39,   -39,   -39,     3,   319,   319,
     -39,   -39,     3,   167,   -39,   -39,    50,   -39,   -39,   -39,
      67,     3,   166,   286,   -39,   -39,    68,   -38,    79,   -39,
     -39,     3,   194,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   216,   -39,   107,
       3,   -39,   -39,   -39,   -39,   166,   238,   100,   -39,   -39,
     -39,   -38,   121,    81,   260,   -39,   357,   340,    16,    16,
      92,    92,    92,   -39,   374,   374,   374,   374,   374,   374,
     113,   -39,   319,   132,   108,   -39,   -24,   -38,   -38,   -38,
     -38,   -38,   -39,   -39,   -39,   -39,     3,   -39,   -39,   -39,
      88,    88,   -39,   -39,   -39,   319,   112,   -39,     3,   319,
     116,   -39,   -39,     3,   -39,   319,   126,   166,   149,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     0,     0,
       6,     7,     8,    25,    26,    21,    22,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    65,     0,
       0,    62,     0,     0,    29,     0,     0,    33,     0,    34,
      35,     0,     0,    23,    27,     0,     0,     0,    11,    37,
      38,     0,     0,     0,    66,    67,    68,     0,    39,    40,
      41,    42,     0,     0,    50,    43,     3,    30,    31,    32,
       0,     0,     0,     0,    36,    24,     0,     0,     0,    85,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     4,     2,    45,    49,     0,     0,     0,    64,    28,
      14,     0,     0,     0,     0,    86,    83,    84,    69,    70,
      71,    72,    73,    74,    77,    79,    80,    81,    82,    78,
      86,    51,    44,     0,    86,    61,     0,     0,     0,     0,
       0,     0,    12,    13,    75,    47,     0,    46,    63,    20,
      15,    16,    17,    18,    19,    52,     0,    53,     0,    54,
      58,    59,    55,     0,    56,    60,     0,     0,     0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   120,    80,   -39,
     -39,   152,   -39,   -39,   -32,   -31,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,   102,     6,    10,    11,    20,    21,   112,    12,
      15,    16,    17,    45,    33,    34,    35,    36,   100,    37,
      38,   105,    39,    99,   146,   156,   158,   160,   164,   166,
     162,   163,    40,    41,    72,    42,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,   110,    67,     1,    63,     3,    70,     4,   137,   138,
     139,   140,   141,    44,   111,    66,    73,    77,    22,    23,
      24,    25,    26,    27,    28,    29,    79,    80,    30,   149,
      13,    14,    82,    51,    31,     5,    52,    97,    46,    67,
     107,    53,    54,    55,    56,    47,   106,    18,    19,    32,
      87,    88,    89,    90,    49,    57,   114,    60,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    50,   133,    61,   132,    67,    22,    23,    24,
      25,    26,    27,    28,    29,    64,   103,    30,     7,     8,
       9,    75,    76,    31,    65,    68,    51,    69,    74,    52,
      78,   101,    67,    81,    53,    54,    55,    56,    32,   109,
      22,    23,    24,    25,    26,    27,    28,    29,    62,   113,
      30,   155,   139,   140,   141,   104,    31,   135,   131,    90,
     143,   145,   148,   159,   157,   168,     0,    67,   165,   161,
      48,    32,    22,    23,    24,    25,    26,    27,    28,    29,
     167,   147,    30,   137,   138,   139,   140,   141,    31,    22,
      23,    24,    25,    26,    27,    28,    29,    43,     0,    30,
     142,     0,     0,    32,   169,    31,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    98,    30,     0,     0,     0,
      32,   136,    31,     0,     0,    83,    84,     0,     0,    85,
      86,    87,    88,    89,    90,     0,     0,    32,     0,     0,
      91,    92,    93,    94,    95,    96,     0,   150,   151,   152,
     153,   154,    83,    84,     0,     0,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,     0,    83,    84,     0,   115,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,     0,    83,    84,     0,   130,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,     0,    83,    84,
       0,   134,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     0,
     108,     0,     0,   144,    83,    84,     0,     0,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    51,     0,     0,    52,     0,
       0,     0,     0,    53,    54,    55,    56,    83,    84,     0,
       0,    85,    86,    87,    88,    89,    90,    71,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    83,     0,
       0,     0,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    85,
      86,    87,    88,    89,    90,     0,     0,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    85,    86,    87,    88,
      89,    90
};

static const yytype_int16 yycheck[] =
{
      25,    39,    33,     3,    29,    41,    38,     0,    32,    33,
      34,    35,    36,    41,    52,     7,    41,    43,    10,    11,
      12,    13,    14,    15,    16,    17,    51,    52,    20,    53,
       8,     9,    57,    30,    26,    49,    33,    62,    41,    70,
      72,    38,    39,    40,    41,    41,    71,     8,     9,    41,
      34,    35,    36,    37,    41,    52,    81,    42,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    41,   105,    42,   100,   107,    10,    11,    12,
      13,    14,    15,    16,    17,    41,    19,    20,     4,     5,
       6,    49,    50,    26,    31,    49,    30,    49,    49,    33,
      43,    51,   133,    52,    38,    39,    40,    41,    41,    41,
      10,    11,    12,    13,    14,    15,    16,    17,    52,    40,
      20,   146,    34,    35,    36,    58,    26,    27,    21,    37,
      49,    18,    24,   158,    22,   167,    -1,   168,   163,    23,
      20,    41,    10,    11,    12,    13,    14,    15,    16,    17,
      24,    19,    20,    32,    33,    34,    35,    36,    26,    10,
      11,    12,    13,    14,    15,    16,    17,    15,    -1,    20,
      49,    -1,    -1,    41,    25,    26,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    18,    20,    -1,    -1,    -1,
      41,   111,    26,    -1,    -1,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    41,    -1,    -1,
      43,    44,    45,    46,    47,    48,    -1,   137,   138,   139,
     140,   141,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    -1,    28,    29,    -1,    53,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    -1,    28,    29,    -1,    53,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    28,    29,
      -1,    53,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    -1,
      24,    -1,    -1,    53,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    30,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    52,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    28,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    32,    33,    34,    35,
      36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    60,    41,     0,    49,    62,     4,     5,     6,
      63,    64,    68,     8,     9,    69,    70,    71,     8,     9,
      65,    66,    10,    11,    12,    13,    14,    15,    16,    17,
      20,    26,    41,    73,    74,    75,    76,    78,    79,    81,
      91,    92,    94,    70,    41,    72,    41,    41,    66,    41,
      41,    30,    33,    38,    39,    40,    41,    52,    95,    95,
      42,    42,    52,    95,    41,    31,     7,    74,    49,    49,
      73,    52,    93,    95,    49,    49,    50,    43,    43,    95,
      95,    52,    95,    28,    29,    32,    33,    34,    35,    36,
      37,    43,    44,    45,    46,    47,    48,    95,    18,    82,
      77,    51,    61,    19,    58,    80,    95,    73,    24,    41,
      39,    52,    67,    40,    95,    53,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      53,    21,    95,    73,    53,    27,    67,    32,    33,    34,
      35,    36,    49,    49,    53,    18,    83,    19,    24,    53,
      67,    67,    67,    67,    67,    95,    84,    22,    85,    95,
      86,    23,    89,    90,    87,    95,    88,    24,    73,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    77,    76,    78,    78,    79,    79,    80,
      82,    83,    84,    85,    86,    87,    88,    81,    89,    90,
      89,    91,    92,    93,    93,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     0,     1,     0,     2,     1,     1,     2,
       1,     2,     5,     5,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     2,     3,     1,     1,     1,     3,     1,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     0,     4,     3,     5,     5,     3,     1,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       3,     4,     1,     4,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3
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
  case 2: /* programme: TOK_PROGRAMME TOK_IDENTIFIANT TOK_POINT_VIRGULE declarations TOK_DEBUT instructions TOK_FIN optional_point  */
#line 157 "atlas.y"
    {
    }
#line 1405 "atlas.tab.c"
    break;

  case 12: /* const_item: TOK_ENT TOK_IDENTIFIANT TOK_EGAL const_expr TOK_POINT_VIRGULE  */
#line 188 "atlas.y"
     {
         ajouter_var((yyvsp[-3].sval), 1, (yyvsp[-1].ival), 1);
     }
#line 1413 "atlas.tab.c"
    break;

  case 13: /* const_item: TOK_BOOL TOK_IDENTIFIANT TOK_EGAL TOK_BOOLEEN TOK_POINT_VIRGULE  */
#line 192 "atlas.y"
     {
         ajouter_var((yyvsp[-3].sval), 1, (yyvsp[-1].ival), 2);
     }
#line 1421 "atlas.tab.c"
    break;

  case 14: /* const_expr: TOK_ENTIER  */
#line 198 "atlas.y"
                { (yyval.ival) = (yyvsp[0].ival); }
#line 1427 "atlas.tab.c"
    break;

  case 15: /* const_expr: const_expr TOK_PLUS const_expr  */
#line 199 "atlas.y"
                                      { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1433 "atlas.tab.c"
    break;

  case 16: /* const_expr: const_expr TOK_MOINS const_expr  */
#line 200 "atlas.y"
                                       { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1439 "atlas.tab.c"
    break;

  case 17: /* const_expr: const_expr TOK_MULT const_expr  */
#line 201 "atlas.y"
                                      { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1445 "atlas.tab.c"
    break;

  case 18: /* const_expr: const_expr TOK_DIV const_expr  */
#line 202 "atlas.y"
                                     { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
#line 1451 "atlas.tab.c"
    break;

  case 19: /* const_expr: const_expr TOK_MOD const_expr  */
#line 203 "atlas.y"
                                     { (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); }
#line 1457 "atlas.tab.c"
    break;

  case 20: /* const_expr: TOK_PAREN_OUV const_expr TOK_PAREN_FERM  */
#line 204 "atlas.y"
                                               { (yyval.ival) = (yyvsp[-1].ival); }
#line 1463 "atlas.tab.c"
    break;

  case 25: /* type: TOK_ENT  */
#line 221 "atlas.y"
              { (yyval.ival) = 1; current_dec_type = 1; }
#line 1469 "atlas.tab.c"
    break;

  case 26: /* type: TOK_BOOL  */
#line 222 "atlas.y"
                { (yyval.ival) = 2; current_dec_type = 2; }
#line 1475 "atlas.tab.c"
    break;

  case 27: /* var_list: TOK_IDENTIFIANT  */
#line 227 "atlas.y"
     {
         ajouter_var((yyvsp[0].sval), 0, 0, current_dec_type);
     }
#line 1483 "atlas.tab.c"
    break;

  case 28: /* var_list: var_list TOK_VIRGULE TOK_IDENTIFIANT  */
#line 231 "atlas.y"
     {
         ajouter_var((yyvsp[0].sval), 0, 0, current_dec_type);
     }
#line 1491 "atlas.tab.c"
    break;

  case 37: /* instr_io: TOK_LIRE TOK_IDENTIFIANT  */
#line 252 "atlas.y"
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
#line 1507 "atlas.tab.c"
    break;

  case 38: /* instr_io: TOK_LIRERC TOK_IDENTIFIANT  */
#line 264 "atlas.y"
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
#line 1522 "atlas.tab.c"
    break;

  case 39: /* instr_io: TOK_ECRIRE expr  */
#line 275 "atlas.y"
     {
         generer("ecrire");
     }
#line 1530 "atlas.tab.c"
    break;

  case 40: /* instr_io: TOK_ECRIRERC expr  */
#line 279 "atlas.y"
     {
         generer("ecrireRC");
     }
#line 1538 "atlas.tab.c"
    break;

  case 41: /* instr_io: TOK_IMPRIMER TOK_CHAINE  */
#line 283 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "imprimer %s", (yyvsp[0].sval));
         generer(buf);
     }
#line 1548 "atlas.tab.c"
    break;

  case 42: /* instr_io: TOK_IMPRIMERRC TOK_CHAINE  */
#line 289 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "imprimerRC %s", (yyvsp[0].sval));
         generer(buf);
     }
#line 1558 "atlas.tab.c"
    break;

  case 43: /* @1: %empty  */
#line 298 "atlas.y"
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
#line 1577 "atlas.tab.c"
    break;

  case 44: /* instr_affectation: TOK_IDENTIFIANT TOK_AFFECT @1 expr  */
#line 313 "atlas.y"
     {
         int expected_type = (yyval.ival);
         if ((yyvsp[0].ival) != expected_type && expected_type != -1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: type incompatible dans l'affectation (attendu: %s, trouve: %s)\n",
                                 yylineno, type_name(expected_type), type_name((yyvsp[0].ival)));
            exit(1);
         }
         generer("affect");
     }
#line 1591 "atlas.tab.c"
    break;

  case 45: /* instr_si: cond_si instructions TOK_FSI  */
#line 326 "atlas.y"
     {
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1599 "atlas.tab.c"
    break;

  case 46: /* instr_si: cond_si instructions else_marker instructions TOK_FSI  */
#line 330 "atlas.y"
     {
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1607 "atlas.tab.c"
    break;

  case 47: /* cond_si: TOK_SI TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_ALORS  */
#line 337 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'si' doit etre un booleen\n", yylineno);
            exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
         current_bsf_index = (yyval.ival);
     }
#line 1621 "atlas.tab.c"
    break;

  case 48: /* cond_si: TOK_SI expr TOK_ALORS  */
#line 347 "atlas.y"
     {
         if ((yyvsp[-1].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'si' doit etre un booleen\n", yylineno);
            exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
         current_bsf_index = (yyval.ival);
     }
#line 1635 "atlas.tab.c"
    break;

  case 49: /* else_marker: TOK_SINON  */
#line 360 "atlas.y"
     {
         (yyval.ival) = code_idx;
         generer("bra 0");
         patcher(current_bsf_index, code_idx); // patch the bsf from cond_si
     }
#line 1645 "atlas.tab.c"
    break;

  case 50: /* @2: %empty  */
#line 369 "atlas.y"
    {
        (yyval.ival) = chercher_var((yyvsp[0].sval));
    }
#line 1653 "atlas.tab.c"
    break;

  case 51: /* $@3: %empty  */
#line 373 "atlas.y"
    {
        char buf[256];
        sprintf(buf, "empiler-adr %d", (yyvsp[-1].ival)); 
        generer(buf);
        
    }
#line 1664 "atlas.tab.c"
    break;

  case 52: /* @4: %empty  */
#line 380 "atlas.y"
    {
        generer("affect");
        (yyval.ival) = (yyvsp[-3].ival); // $5: loop var address
    }
#line 1673 "atlas.tab.c"
    break;

  case 53: /* @5: %empty  */
#line 385 "atlas.y"
    {
        int slot = adresse_var++;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot); 
        generer(buf);
        (yyval.ival) = slot;
    }
#line 1685 "atlas.tab.c"
    break;

  case 54: /* @6: %empty  */
#line 393 "atlas.y"
    {
        generer("affect");
        (yyval.ival) = (yyvsp[-8].ival); // $7: limit slot
    }
#line 1694 "atlas.tab.c"
    break;

  case 55: /* @7: %empty  */
#line 398 "atlas.y"
    {
        (yyval.ival) = code_idx; // $9: START OF LOOP LABEL
    }
#line 1702 "atlas.tab.c"
    break;

  case 56: /* @8: %empty  */
#line 401 "atlas.y"
    {
        char buf[256];
        sprintf(buf, "empiler-adr %d", (yyvsp[-10].ival)); 
        generer(buf);
        generer("valeur-pile");
        
        sprintf(buf, "empiler-adr %d", (yyvsp[-4].ival)); 
        generer(buf);
        generer("valeur-pile");
        generer("pp-egal");
        (yyval.ival) = code_idx; // $10: BSF index
        generer("bsf 0");
    }
#line 1720 "atlas.tab.c"
    break;

  case 57: /* instr_pour: TOK_POUR TOK_IDENTIFIANT @2 TOK_DEPUIS $@3 expr @4 TOK_JUSQUA @5 expr @6 pour_opt_step @7 @8 TOK_FAIRE instructions TOK_FPOUR  */
#line 415 "atlas.y"
    {
        char buf[256];
        // Increment: var = var + step
        sprintf(buf, "empiler-adr %d", (yyvsp[-14].ival)); 
        generer(buf);
        sprintf(buf, "empiler-adr %d", (yyvsp[-10].ival)); 
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
#line 1743 "atlas.tab.c"
    break;

  case 58: /* pour_opt_step: %empty  */
#line 437 "atlas.y"
    {
        int slot = adresse_var++;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot);
        generer(buf);
        generer("empiler-val 1");
        generer("affect");
        (yyval.ival) = slot;
    }
#line 1757 "atlas.tab.c"
    break;

  case 59: /* @9: %empty  */
#line 447 "atlas.y"
    {
        int slot = adresse_var++;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot);
        generer(buf);
        (yyval.ival) = slot;
    }
#line 1769 "atlas.tab.c"
    break;

  case 60: /* pour_opt_step: TOK_PARPAS @9 expr  */
#line 455 "atlas.y"
    {
        generer("affect");
        (yyval.ival) = (yyvsp[-1].ival);
    }
#line 1778 "atlas.tab.c"
    break;

  case 61: /* instr_tantque: loop_start cond_tantque instructions TOK_FTQ  */
#line 465 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "bra %d", (yyvsp[-3].ival));
         generer(buf);
         patcher((yyvsp[-2].ival), code_idx);
     }
#line 1789 "atlas.tab.c"
    break;

  case 62: /* loop_start: TOK_TANTQUE  */
#line 475 "atlas.y"
     {
         (yyval.ival) = code_idx;
     }
#line 1797 "atlas.tab.c"
    break;

  case 63: /* cond_tantque: TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_FAIRE  */
#line 482 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'tantque' doit etre un booleen\n", yylineno);
             exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
     }
#line 1810 "atlas.tab.c"
    break;

  case 64: /* cond_tantque: expr TOK_FAIRE  */
#line 491 "atlas.y"
     {
         if ((yyvsp[-1].ival) != 2) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'tantque' doit etre un booleen\n", yylineno);
             exit(1);
         }
         (yyval.ival) = code_idx;
         generer("bsf 0");
     }
#line 1823 "atlas.tab.c"
    break;

  case 65: /* instr_passer: TOK_PASSER  */
#line 503 "atlas.y"
     {
         generer("/* passer */");
     }
#line 1831 "atlas.tab.c"
    break;

  case 66: /* expr: TOK_ENTIER  */
#line 510 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler-val %d", (yyvsp[0].ival));
         generer(buf);
         (yyval.ival) = 1;
     }
#line 1842 "atlas.tab.c"
    break;

  case 67: /* expr: TOK_BOOLEEN  */
#line 517 "atlas.y"
     {
         char buf[256];
         sprintf(buf, "empiler-val %d", (yyvsp[0].ival));
         generer(buf);
         (yyval.ival) = 2;
     }
#line 1853 "atlas.tab.c"
    break;

  case 68: /* expr: TOK_IDENTIFIANT  */
#line 524 "atlas.y"
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
#line 1882 "atlas.tab.c"
    break;

  case 69: /* expr: expr TOK_PLUS expr  */
#line 549 "atlas.y"
     {
        if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '+' requiert des entiers\n", yylineno);
            exit(1);
        }
        generer("plus");
        (yyval.ival) = 1;  // result is entier
     }
#line 1895 "atlas.tab.c"
    break;

  case 70: /* expr: expr TOK_MOINS expr  */
#line 558 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '-' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("moins");
         (yyval.ival) = 1;
     }
#line 1908 "atlas.tab.c"
    break;

  case 71: /* expr: expr TOK_MULT expr  */
#line 567 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '*' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("mult");
         (yyval.ival) = 1;
     }
#line 1921 "atlas.tab.c"
    break;

  case 72: /* expr: expr TOK_DIV expr  */
#line 576 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '/' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("division");
         (yyval.ival) = 1;
     }
#line 1934 "atlas.tab.c"
    break;

  case 73: /* expr: expr TOK_MOD expr  */
#line 585 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '%%' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("mod");
         (yyval.ival) = 1;
     }
#line 1947 "atlas.tab.c"
    break;

  case 74: /* expr: expr TOK_PUISS expr  */
#line 594 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'puiss' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("puiss");
         (yyval.ival) = 1;
     }
#line 1960 "atlas.tab.c"
    break;

  case 75: /* expr: TOK_VALABS TOK_PAREN_OUV expr TOK_PAREN_FERM  */
#line 603 "atlas.y"
     {
         if ((yyvsp[-1].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'valabs' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("valabs");
         (yyval.ival) = 1;
     }
#line 1973 "atlas.tab.c"
    break;

  case 76: /* expr: TOK_MOINS expr  */
#line 612 "atlas.y"
     {
         if ((yyvsp[0].ival) != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '-' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("neg");
         (yyval.ival) = 1;
     }
#line 1986 "atlas.tab.c"
    break;

  case 77: /* expr: expr TOK_EGAL expr  */
#line 621 "atlas.y"
     {
         generer("egal");
         (yyval.ival) = 2;
     }
#line 1995 "atlas.tab.c"
    break;

  case 78: /* expr: expr TOK_DIFF expr  */
#line 626 "atlas.y"
     {
         generer("dif");
         (yyval.ival) = 2;
     }
#line 2004 "atlas.tab.c"
    break;

  case 79: /* expr: expr TOK_INF expr  */
#line 631 "atlas.y"
     {
         generer("pps");
         (yyval.ival) = 2;
     }
#line 2013 "atlas.tab.c"
    break;

  case 80: /* expr: expr TOK_SUP expr  */
#line 636 "atlas.y"
     {
         generer("pgs");
         (yyval.ival) = 2;
     }
#line 2022 "atlas.tab.c"
    break;

  case 81: /* expr: expr TOK_INF_EG expr  */
#line 641 "atlas.y"
     {
         generer("pp-egal");
         (yyval.ival) = 2;
     }
#line 2031 "atlas.tab.c"
    break;

  case 82: /* expr: expr TOK_SUP_EG expr  */
#line 646 "atlas.y"
     {
         generer("pg-egal");
         (yyval.ival) = 2;
     }
#line 2040 "atlas.tab.c"
    break;

  case 83: /* expr: expr TOK_ET expr  */
#line 651 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2 || (yyvsp[0].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'et' requiert des booleens\n", yylineno);
            exit(1);
         }
         generer("et");
         (yyval.ival) = 2;
     }
#line 2053 "atlas.tab.c"
    break;

  case 84: /* expr: expr TOK_OU expr  */
#line 660 "atlas.y"
     {
         if ((yyvsp[-2].ival) != 2 || (yyvsp[0].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'ou' requiert des booleens\n", yylineno);
            exit(1);
         }
         generer("ou");
         (yyval.ival) = 2;
     }
#line 2066 "atlas.tab.c"
    break;

  case 85: /* expr: TOK_NON expr  */
#line 669 "atlas.y"
     {
         if ((yyvsp[0].ival) != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'non' requiert un booleen\n", yylineno);
            exit(1);
         }
         generer("non");
         (yyval.ival) = 2;
     }
#line 2079 "atlas.tab.c"
    break;

  case 86: /* expr: TOK_PAREN_OUV expr TOK_PAREN_FERM  */
#line 678 "atlas.y"
     {
         (yyval.ival) = (yyvsp[-1].ival);
     }
#line 2087 "atlas.tab.c"
    break;


#line 2091 "atlas.tab.c"

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

#line 682 "atlas.y"


/*  ═════════════════════════════════════════════════════════
    FONCTIONS UTILITAIRES
    ════════════════════════════════════════════════════════ */

int ajouter_var(const char *nom, int is_const, int valeur, int data_type) {
     if (nb_vars >= 100) {
         fprintf(stderr, "Erreur : trop de variables\n");
         return -1;
     }

     if (chercher_var(nom) != -1) {
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
