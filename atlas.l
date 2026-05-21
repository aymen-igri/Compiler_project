/*
 * ============================================================
 *  Analyseur lexical du langage Atlas
 *  Fichier : atlas.l  (Flex)
 * ============================================================
 *
 *  Compilation Windows :
 *    flex atlas.l
 *    gcc -o atlas_lex lex.yy.c -lfl      (avec libfl)
 *    OU sans libfl :
 *    gcc -o atlas_lex lex.yy.c           (main() dans ce fichier)
 *
 *  Utilisation avec Bison (partie 2) :
 *    flex atlas.l
 *    bison -d atlas.y
 *    gcc -o atlas atlas.tab.c lex.yy.c -lm
 * ============================================================
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ─────────────────────────────────────────────────────────
   Quand ce fichier est utilisé SEUL (test lexical),
   on inclut les définitions des tokens ici.
   Quand il est couplé à Bison, on inclut atlas.tab.h
   ───────────────────────────────────────────────────────── */
#ifdef AVEC_BISON
  #include "atlas.tab.h"
#else
  /* Codes tokens pour test autonome */
  typedef enum {
    /* Mots-clés structure */
    TOK_PROGRAMME = 1, TOK_VAR,      TOK_CONST,
    TOK_DEBUT,         TOK_FIN,
    /* Types */
    TOK_ENT,           TOK_BOOL,
    /* Instructions */
    TOK_LIRE,          TOK_LIRERC,
    TOK_ECRIRE,        TOK_ECRIRERC,
    TOK_IMPRIMER,      TOK_IMPRIMERRC,
    TOK_PASSER,
    /* Structures de contrôle */
    TOK_SI,    TOK_ALORS,  TOK_SINON,   TOK_FSI,
    TOK_POUR,  TOK_DEPUIS, TOK_JUSQUA,  TOK_PARPAS,
    TOK_FAIRE, TOK_FPOUR,
    TOK_TANTQUE, TOK_FTQ,
    /* Opérateurs logiques */
    TOK_ET,  TOK_OU,  TOK_NON,
    /* Littéraux et identificateurs */
    TOK_ENTIER,        /* nombre entier              */
    TOK_BOOLEEN,       /* 0 (faux) ou 1 (vrai)       */
    TOK_IDENTIFIANT,   /* nom de variable/constante  */
    TOK_CHAINE,        /* texte entre apostrophes    */
    /* Opérateurs */
    TOK_AFFECT,        /* :=  */
    TOK_PLUS,  TOK_MOINS, TOK_MULT, TOK_DIV, TOK_MOD,
    TOK_PUISS, TOK_VALABS,
    /* Comparaisons */
    TOK_EGAL,  TOK_INF,  TOK_SUP,
    TOK_INF_EG, TOK_SUP_EG, TOK_DIFF,
    /* Ponctuation */
    TOK_POINT_VIRGULE, /* ;  */
    TOK_VIRGULE,       /* ,  */
    TOK_POINT,         /* .  */
    TOK_PAREN_OUV,     /* (  */
    TOK_PAREN_FERM,    /* )  */
    TOK_ERREUR
  } TypeToken;

  /* Valeurs sémantiques (utilisées aussi en mode autonome) */
  int    yylval_int;
  char   yylval_str[256];
#endif

/* Compteur de lignes pour les messages d'erreur */
int num_ligne = 1;

/* Prototypes internes */
void erreur_lex(const char *msg);

%}

/* ─────────────────────────────────────────────────────────
   OPTIONS FLEX
   ───────────────────────────────────────────────────────── */
%option noyywrap
%option nounput
%option noinput
%option yylineno
%option case-insensitive

/* ─────────────────────────────────────────────────────────
   DÉFINITIONS (abréviations pour les règles)
   ───────────────────────────────────────────────────────── */

LETTRE      [a-zA-Z_]
CHIFFRE     [0-9]
IDENT       {LETTRE}({LETTRE}|{CHIFFRE})*
ENTIER      {CHIFFRE}+
ESPACE      [ \t\r]+
NEWLINE     \n
COMMENTAIRE "//"[^\n]*

%%

 /* ═══════════════════════════════════════════════════════
    1. COMMENTAIRES et ESPACES  (ignorés)
    ═══════════════════════════════════════════════════════ */

{COMMENTAIRE}   { /* commentaire de fin de ligne → ignorer */ }
{ESPACE}        { /* espaces / tabulations → ignorer       */ }
{NEWLINE}       { num_ligne++; }


 /* ═══════════════════════════════════════════════════════
    2. MOTS-CLÉS DE STRUCTURE
    ═══════════════════════════════════════════════════════ */

"programme"     { return TOK_PROGRAMME;  }
"var"           { return TOK_VAR;        }
"const"         { return TOK_CONST;      }
"debut"         { return TOK_DEBUT;      }
"fin"           { return TOK_FIN;        }


 /* ═══════════════════════════════════════════════════════
    3. TYPES DE DONNÉES
    ═══════════════════════════════════════════════════════ */

"ent"           { return TOK_ENT;  }
"bool"          { return TOK_BOOL; }


 /* ═══════════════════════════════════════════════════════
    4. INSTRUCTIONS D'ENTRÉE / SORTIE
    ═══════════════════════════════════════════════════════ */

"lirerc"        { return TOK_LIRERC;      }   /* lireRC avant lire ! */
"lire"          { return TOK_LIRE;        }
"ecrirerc"      { return TOK_ECRIRERC;    }   /* ecrireRC avant ecrire ! */
"ecrire"        { return TOK_ECRIRE;      }
"imprimerrc"    { return TOK_IMPRIMERRC;  }   /* imprimerRC avant imprimer ! */
"imprimer"      { return TOK_IMPRIMER;    }
"passer"        { return TOK_PASSER;      }


 /* ═══════════════════════════════════════════════════════
    5. STRUCTURES DE CONTRÔLE
    ═══════════════════════════════════════════════════════ */

"si"            { return TOK_SI;     }
"alors"         { return TOK_ALORS;  }
"sinon"         { return TOK_SINON;  }
"fsi"           { return TOK_FSI;    }

"pour"          { return TOK_POUR;   }
"depuis"        { return TOK_DEPUIS; }
"jusqua"        { return TOK_JUSQUA; }
"parpas"        { return TOK_PARPAS; }
"faire"         { return TOK_FAIRE;  }
"fpour"         { return TOK_FPOUR;  }

"tantque"       { return TOK_TANTQUE; }
"ftq"           { return TOK_FTQ;     }


 /* ═══════════════════════════════════════════════════════
    6. OPÉRATEURS LOGIQUES (mots-clés)
    ═══════════════════════════════════════════════════════ */

"et"            { return TOK_ET;  }
"ou"            { return TOK_OU;  }
"non"           { return TOK_NON; }


 /* ═══════════════════════════════════════════════════════
    7. OPÉRATEURS ARITHMÉTIQUES (mots-clés)
    ═══════════════════════════════════════════════════════ */

"puiss"         { return TOK_PUISS;  }
"valabs"        { return TOK_VALABS; }


 /* ═══════════════════════════════════════════════════════
    8. BOOLÉENS LITTÉRAUX
    ═══════════════════════════════════════════════════════ */

"vrai"          {
#ifdef AVEC_BISON
                  yylval.ival = 1;
#else
                  yylval_int = 1;
#endif
                  return TOK_BOOLEEN;
                }

"faux"          {
#ifdef AVEC_BISON
                  yylval.ival = 0;
#else
                  yylval_int = 0;
#endif
                  return TOK_BOOLEEN;
                }


 /* ═══════════════════════════════════════════════════════
    9. ENTIERS LITTÉRAUX
    ═══════════════════════════════════════════════════════ */

{ENTIER}        {
#ifdef AVEC_BISON
                  yylval.ival = atoi(yytext);
#else
                  yylval_int = atoi(yytext);
#endif
                  return TOK_ENTIER;
                }


 /* ═══════════════════════════════════════════════════════
    10. CHAÎNES DE CARACTÈRES  'texte'
        (pour imprimer / imprimerRC)
    ═══════════════════════════════════════════════════════ */

\'[^\']*\'      {
                  /* Extraire le contenu sans les apostrophes */
                  int len = strlen(yytext) - 2;
#ifdef AVEC_BISON
                  strncpy(yylval.sval, yytext + 1, len);
                  yylval.sval[len] = '\0';
#else
                  strncpy(yylval_str, yytext + 1, len);
                  yylval_str[len] = '\0';
#endif
                  return TOK_CHAINE;
                }


 /* ═══════════════════════════════════════════════════════
    11. IDENTIFICATEURS
        (après tous les mots-clés pour ne pas les masquer)
    ═══════════════════════════════════════════════════════ */

{IDENT}         {
#ifdef AVEC_BISON
                  strncpy(yylval.sval, yytext, 63);
                  yylval.sval[63] = '\0';
#else
                  strncpy(yylval_str, yytext, 63);
                  yylval_str[63] = '\0';
#endif
                  return TOK_IDENTIFIANT;
                }


 /* ═══════════════════════════════════════════════════════
    12. OPÉRATEURS ET PONCTUATION
    ═══════════════════════════════════════════════════════ */

":="            { return TOK_AFFECT;        }
"+"             { return TOK_PLUS;          }
"-"             { return TOK_MOINS;         }
"*"             { return TOK_MULT;          }
"/"             { return TOK_DIV;           }
"%"             { return TOK_MOD;           }

 /* Opérateurs de comparaison (ordre important : <> avant < et >) */
"<>"            { return TOK_DIFF;   }
"<="            { return TOK_INF_EG; }
">="            { return TOK_SUP_EG; }
"<"             { return TOK_INF;    }
">"             { return TOK_SUP;    }
"="             { return TOK_EGAL;   }

 /* Ponctuation */
";"             { return TOK_POINT_VIRGULE; }
","             { return TOK_VIRGULE;       }
"."             { return TOK_POINT;         }
"("             { return TOK_PAREN_OUV;     }
")"             { return TOK_PAREN_FERM;    }


 /* ═══════════════════════════════════════════════════════
    13. CARACTÈRES NON RECONNUS → ERREUR LEXICALE
    ═══════════════════════════════════════════════════════ */

.               {
                  fprintf(stderr,
                    "[ERREUR LEXICALE] ligne %d : caractere illegal '%s'\n",
                    num_ligne, yytext);
                  return TOK_ERREUR;
                }

%%

/* ─────────────────────────────────────────────────────────
   PROGRAMME PRINCIPAL (mode test autonome uniquement)
   Quand couplé à Bison, ce main() est désactivé.
   ───────────────────────────────────────────────────────── */
#ifndef AVEC_BISON

/* Noms des tokens pour l'affichage */
const char *nom_token(int tok) {
    switch (tok) {
        case TOK_PROGRAMME:    return "PROGRAMME";
        case TOK_VAR:          return "VAR";
        case TOK_CONST:        return "CONST";
        case TOK_DEBUT:        return "DEBUT";
        case TOK_FIN:          return "FIN";
        case TOK_ENT:          return "ENT";
        case TOK_BOOL:         return "BOOL";
        case TOK_LIRE:         return "LIRE";
        case TOK_LIRERC:       return "LIRERC";
        case TOK_ECRIRE:       return "ECRIRE";
        case TOK_ECRIRERC:     return "ECRIRERC";
        case TOK_IMPRIMER:     return "IMPRIMER";
        case TOK_IMPRIMERRC:   return "IMPRIMERRC";
        case TOK_PASSER:       return "PASSER";
        case TOK_SI:           return "SI";
        case TOK_ALORS:        return "ALORS";
        case TOK_SINON:        return "SINON";
        case TOK_FSI:          return "FSI";
        case TOK_POUR:         return "POUR";
        case TOK_DEPUIS:       return "DEPUIS";
        case TOK_JUSQUA:       return "JUSQUA";
        case TOK_PARPAS:       return "PARPAS";
        case TOK_FAIRE:        return "FAIRE";
        case TOK_FPOUR:        return "FPOUR";
        case TOK_TANTQUE:      return "TANTQUE";
        case TOK_FTQ:          return "FTQ";
        case TOK_ET:           return "ET";
        case TOK_OU:           return "OU";
        case TOK_NON:          return "NON";
        case TOK_PUISS:        return "PUISS";
        case TOK_VALABS:       return "VALABS";
        case TOK_ENTIER:       return "ENTIER";
        case TOK_BOOLEEN:      return "BOOLEEN";
        case TOK_IDENTIFIANT:  return "IDENTIFIANT";
        case TOK_CHAINE:       return "CHAINE";
        case TOK_AFFECT:       return "AFFECT(:=)";
        case TOK_PLUS:         return "PLUS(+)";
        case TOK_MOINS:        return "MOINS(-)";
        case TOK_MULT:         return "MULT(*)";
        case TOK_DIV:          return "DIV(/)";
        case TOK_MOD:          return "MOD(%)";
        case TOK_EGAL:         return "EGAL(=)";
        case TOK_INF:          return "INF(<)";
        case TOK_SUP:          return "SUP(>)";
        case TOK_INF_EG:       return "INF_EG(<=)";
        case TOK_SUP_EG:       return "SUP_EG(>=)";
        case TOK_DIFF:         return "DIFF(<>)";
        case TOK_POINT_VIRGULE: return "POINT_VIRGULE(;)";
        case TOK_VIRGULE:      return "VIRGULE(,)";
        case TOK_POINT:        return "POINT(.)";
        case TOK_PAREN_OUV:    return "PAREN_OUV(()";
        case TOK_PAREN_FERM:   return "PAREN_FERM())";
        case TOK_ERREUR:       return "ERREUR";
        default:               return "INCONNU";
    }
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
    } else {
        printf("Lecture depuis stdin (Ctrl+Z sur Windows pour terminer)\n");
        yyin = stdin;
    }

    printf("%-6s %-20s %s\n", "LIGNE", "TOKEN", "VALEUR");
    printf("%-6s %-20s %s\n", "-----", "-----", "------");

    int tok;
    while ((tok = yylex()) != 0) {
        if (tok == TOK_ERREUR) continue;

        printf("%-6d %-20s", num_ligne, nom_token(tok));

        switch (tok) {
            case TOK_ENTIER:
            case TOK_BOOLEEN:
                printf(" %d", yylval_int);
                break;
            case TOK_IDENTIFIANT:
            case TOK_CHAINE:
                printf(" %s", yylval_str);
                break;
            default:
                printf(" %s", yytext);
                break;
        }
        printf("\n");
    }

    if (f) fclose(f);
    printf("\nAnalyse lexicale terminee.\n");
    return 0;
}

#endif /* ifndef AVEC_BISON */
