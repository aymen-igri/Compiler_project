/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_ATLAS_TAB_H_INCLUDED
# define YY_YY_SRC_ATLAS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_PROGRAMME = 258,           /* TOK_PROGRAMME  */
    TOK_VAR = 259,                 /* TOK_VAR  */
    TOK_CONST = 260,               /* TOK_CONST  */
    TOK_DEBUT = 261,               /* TOK_DEBUT  */
    TOK_FIN = 262,                 /* TOK_FIN  */
    TOK_ENT = 263,                 /* TOK_ENT  */
    TOK_BOOL = 264,                /* TOK_BOOL  */
    TOK_LIRE = 265,                /* TOK_LIRE  */
    TOK_LIRERC = 266,              /* TOK_LIRERC  */
    TOK_ECRIRE = 267,              /* TOK_ECRIRE  */
    TOK_ECRIRERC = 268,            /* TOK_ECRIRERC  */
    TOK_IMPRIMER = 269,            /* TOK_IMPRIMER  */
    TOK_IMPRIMERRC = 270,          /* TOK_IMPRIMERRC  */
    TOK_PASSER = 271,              /* TOK_PASSER  */
    TOK_SI = 272,                  /* TOK_SI  */
    TOK_ALORS = 273,               /* TOK_ALORS  */
    TOK_FSI = 274,                 /* TOK_FSI  */
    TOK_POUR = 275,                /* TOK_POUR  */
    TOK_DEPUIS = 276,              /* TOK_DEPUIS  */
    TOK_JUSQUA = 277,              /* TOK_JUSQUA  */
    TOK_PARPAS = 278,              /* TOK_PARPAS  */
    TOK_FAIRE = 279,               /* TOK_FAIRE  */
    TOK_FPOUR = 280,               /* TOK_FPOUR  */
    TOK_TANTQUE = 281,             /* TOK_TANTQUE  */
    TOK_FTQ = 282,                 /* TOK_FTQ  */
    TOK_ET = 283,                  /* TOK_ET  */
    TOK_OU = 284,                  /* TOK_OU  */
    TOK_NON = 285,                 /* TOK_NON  */
    TOK_AFFECT = 286,              /* TOK_AFFECT  */
    TOK_PLUS = 287,                /* TOK_PLUS  */
    TOK_MOINS = 288,               /* TOK_MOINS  */
    TOK_MULT = 289,                /* TOK_MULT  */
    TOK_DIV = 290,                 /* TOK_DIV  */
    TOK_MOD = 291,                 /* TOK_MOD  */
    TOK_PUISS = 292,               /* TOK_PUISS  */
    TOK_VALABS = 293,              /* TOK_VALABS  */
    TOK_ENTIER = 294,              /* TOK_ENTIER  */
    TOK_BOOLEEN = 295,             /* TOK_BOOLEEN  */
    TOK_IDENTIFIANT = 296,         /* TOK_IDENTIFIANT  */
    TOK_CHAINE = 297,              /* TOK_CHAINE  */
    TOK_EGAL = 298,                /* TOK_EGAL  */
    TOK_INF = 299,                 /* TOK_INF  */
    TOK_SUP = 300,                 /* TOK_SUP  */
    TOK_INF_EG = 301,              /* TOK_INF_EG  */
    TOK_SUP_EG = 302,              /* TOK_SUP_EG  */
    TOK_DIFF = 303,                /* TOK_DIFF  */
    TOK_POINT_VIRGULE = 304,       /* TOK_POINT_VIRGULE  */
    TOK_VIRGULE = 305,             /* TOK_VIRGULE  */
    TOK_POINT = 306,               /* TOK_POINT  */
    TOK_PAREN_OUV = 307,           /* TOK_PAREN_OUV  */
    TOK_PAREN_FERM = 308,          /* TOK_PAREN_FERM  */
    TOK_ERREUR = 309,              /* TOK_ERREUR  */
    UMINUS = 310,                  /* UMINUS  */
    UNOT = 311,                    /* UNOT  */
    IF_PREC = 312,                 /* IF_PREC  */
    TOK_SINON = 313                /* TOK_SINON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "src/atlas.y"

 int ival;
 char sval[256];

#line 127 "src/atlas.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_ATLAS_TAB_H_INCLUDED  */
