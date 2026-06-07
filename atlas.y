%{

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

%}

%union {
 int ival;
 char sval[256];
}

// Structure tokens
%token TOK_PROGRAMME TOK_VAR TOK_CONST TOK_DEBUT TOK_FIN

// Type tokens
%token TOK_ENT TOK_BOOL

// Instructions tokens
%token TOK_LIRE TOK_LIRERC TOK_ECRIRE TOK_ECRIRERC
%token TOK_IMPRIMER TOK_IMPRIMERRC TOK_PASSER

// Controle flow tokens
%token TOK_SI TOK_ALORS TOK_FSI TOK_POUR
%token TOK_DEPUIS TOK_JUSQUA TOK_PARPAS
%token TOK_FAIRE TOK_FPOUR TOK_TANTQUE TOK_FTQ

// Operators tokens
%token TOK_ET TOK_OU TOK_NON
%token TOK_AFFECT
%token TOK_PLUS TOK_MOINS TOK_MULT TOK_DIV TOK_MOD
%token TOK_PUISS TOK_VALABS

// Types tokens
%token <ival> TOK_ENTIER TOK_BOOLEEN
%token <sval> TOK_IDENTIFIANT TOK_CHAINE

// Comparaison tokens
%token TOK_EGAL TOK_INF TOK_SUP
%token TOK_INF_EG TOK_SUP_EG TOK_DIFF

// Ponctuation tokens
%token TOK_POINT_VIRGULE TOK_VIRGULE TOK_POINT
%token TOK_PAREN_OUV TOK_PAREN_FERM TOK_ERREUR

%left TOK_OU
%left TOK_ET
%left TOK_NON
%left TOK_EGAL TOK_DIFF TOK_INF TOK_SUP TOK_INF_EG TOK_SUP_EG
%left TOK_PLUS TOK_MOINS
%left TOK_MULT TOK_DIV TOK_MOD
%left TOK_PUISS TOK_VALABS
%nonassoc UMINUS
%nonassoc UNOT

%nonassoc IF_PREC
%nonassoc TOK_SINON

%type <ival> expr
%type <ival> type

%type <ival> const_expr

%type <ival> cond_si
%type <ival> loop_start
%type <ival> cond_tantque
%type <ival> pour_opt_step

%%
/* =======================================================
   Regles de grammaire
   ======================================================= */

// Globale program
programme:
    TOK_PROGRAMME TOK_IDENTIFIANT TOK_POINT_VIRGULE
    declarations
    TOK_DEBUT
    {
        generer("ouverture-bloc");
        char buf[256];
        sprintf(buf, "reserver-var %d", adresse_var);
        generer(buf);
    }
    instructions
    TOK_FIN optional_point
    {
        generer("fermeture-bloc");
    }
    ;

optional_point:
    /* vide */
    | TOK_POINT
    ;

// Declaration section
declarations:
     /* vide */
     | declarations declaration
     ;
 
 declaration:
     const_declaration
     | var_declaration
     ;
 
 const_declaration:
     TOK_CONST const_items
     ;
 
 const_items:
     const_item
     | const_items const_item
     ;
 
const_item:
     TOK_ENT TOK_IDENTIFIANT TOK_EGAL const_expr TOK_POINT_VIRGULE
     {
         ajouter_var($2, 1, $4, 1);
     }
     | TOK_BOOL TOK_IDENTIFIANT TOK_EGAL TOK_BOOLEEN TOK_POINT_VIRGULE
     {
         ajouter_var($2, 1, $4, 2);
     }
     ;
     
const_expr:
     TOK_ENTIER { $$ = $1; }
     | const_expr TOK_PLUS const_expr { $$ = $1 + $3; }
     | const_expr TOK_MOINS const_expr { $$ = $1 - $3; }
     | const_expr TOK_MULT const_expr { $$ = $1 * $3; }
     | const_expr TOK_DIV const_expr { $$ = $1 / $3; }
     | const_expr TOK_MOD const_expr { $$ = $1 % $3; }
     | TOK_PAREN_OUV const_expr TOK_PAREN_FERM { $$ = $2; }
     ;
 
 var_declaration:
     TOK_VAR var_items
     ;
 
 var_items:
     var_item
     | var_items var_item
     ;
 
 var_item:
     type var_list TOK_POINT_VIRGULE
     ;
 
 type:
     TOK_ENT  { $$ = 1; current_dec_type = 1; }
     | TOK_BOOL { $$ = 2; current_dec_type = 2; }
     ;
 
 var_list:
     TOK_IDENTIFIANT
     {
         ajouter_var($1, 0, 0, current_dec_type);
     }
     | var_list TOK_VIRGULE TOK_IDENTIFIANT
     {
         ajouter_var($3, 0, 0, current_dec_type);
     }
     ;

// Instruction section
instructions:
     instruction
     | instructions instruction
     ;
instruction:
     instr_io TOK_POINT_VIRGULE
     | instr_affectation TOK_POINT_VIRGULE
     | instr_si
     | instr_pour
     | instr_tantque
     | instr_passer TOK_POINT_VIRGULE
     ;

instr_io:
     TOK_LIRE TOK_IDENTIFIANT
     {
         if (is_const($2)) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: 'lire' ne peut pas modifier une constante '%s'\n", yylineno, $2);
             exit(1);
         }
         char buf[256];
         sprintf(buf, "empiler-adr %d", chercher_var($2));
         
         generer(buf);
         generer("lire");
     }
     | TOK_LIRERC TOK_IDENTIFIANT
     {
         if (is_const($2)) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: 'lireRC' ne peut pas modifier une constante '%s'\n", yylineno, $2);
             exit(1);
         }
         char buf[256];
         sprintf(buf, "empiler-adr %d", chercher_var($2));
         generer(buf);
         generer("lireRC");
     }
     | TOK_ECRIRE expr
     {
         generer("ecrire");
     }
     | TOK_ECRIRERC expr
     {
         generer("ecrireRC");
     }
     | TOK_IMPRIMER TOK_CHAINE
     {
         char buf[256];
         sprintf(buf, "imprimer %s", $2);
         generer(buf);
     }
     | TOK_IMPRIMERRC TOK_CHAINE
     {
         char buf[256];
         sprintf(buf, "imprimerRC %s", $2);
         generer(buf);
     }
     ;

instr_affectation:
     TOK_IDENTIFIANT TOK_AFFECT 
     {
         int idx = chercher_var($1);
         if (idx == -1) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: variable '%s' non declarée\n", yylineno, $1);
            exit(1);
         } else if (is_const($1)) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: tentative d'affectation a une constante '%s'\n", yylineno, $1);
            exit(1);
         }
         char buf[256];
         sprintf(buf, "empiler-adr %d", idx);
         generer(buf);
         $<ival>$ = get_data_type($1);
     }
     expr
     {
         int expected_type = $<ival>3;
         if ($<ival>4 != expected_type && expected_type != -1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: type incompatible dans l'affectation (attendu: %s, trouve: %s)\n",
                                 yylineno, type_name(expected_type), type_name($4));
            exit(1);
         }
         generer("affect");
     }
     ;

instr_si:
     cond_si instructions TOK_FSI
     {
         patcher($1, code_idx);
     }
     | cond_si instructions TOK_SINON 
       {
           $<ival>$ = code_idx;
           generer("bra 0");
           patcher($1, code_idx);
       }
       instructions TOK_FSI
     {
         patcher($<ival>4, code_idx);
     }
     ;

cond_si:
     TOK_SI TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_ALORS
     {
         if ($3 != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'si' doit etre un booleen\n", yylineno);
            exit(1);
         }
         generer("bsf 0");
         $$ = code_idx -1;
     }
     | TOK_SI expr TOK_ALORS
     {
         if ($2 != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'si' doit etre un booleen\n", yylineno);
            exit(1);
         }
         $$ = code_idx;
         generer("bsf 0");
     }
     ;

instr_pour:
    TOK_POUR TOK_IDENTIFIANT
    {
        $<ival>$ = chercher_var($2);
    }
    TOK_DEPUIS 
    {
        char buf[256];
        sprintf(buf, "empiler-adr %d", $<ival>3); 
        generer(buf);
    }
    expr
    {
        generer("affect");
        $<ival>$ = $<ival>3; // $7: loop var address
    }
    TOK_JUSQUA 
    {
        int slot = adresse_var++;
        if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot); 
        generer(buf);
        $<ival>$ = slot;
    }
    expr
    {
        generer("affect");
        $<ival>$ = $<ival>9; // $11: limit slot address
    }
    pour_opt_step
    {
        $<ival>$ = code_idx; // $13: START OF LOOP LABEL
    }
    {
        char buf[256];
        sprintf(buf, "empiler-adr %d", $<ival>3); 
        generer(buf);
        generer("valeur-pile");
        
        sprintf(buf, "empiler-adr %d", $<ival>11); 
        generer(buf);
        generer("valeur-pile");
        generer("pp-egal");
        $<ival>$ = code_idx; // $14: BSF index
        generer("bsf 0");
    }
    TOK_FAIRE instructions TOK_FPOUR
    {
        char buf[256];
        // Increment: var = var + step
        sprintf(buf, "empiler-adr %d", $<ival>3); 
        generer(buf); // Address for assignment
        
        sprintf(buf, "empiler-adr %d", $<ival>3); 
        generer(buf);
        generer("valeur-pile");
        
        sprintf(buf, "empiler-adr %d", $<ival>12); 
        generer(buf);
        generer("valeur-pile");
        
        generer("plus");
        generer("affect");
        
        // Jump back
        sprintf(buf, "bra %d", $<ival>13); 
        generer(buf);
        
        // Patch exit
        patcher($<ival>14, code_idx);
    }
    ;

pour_opt_step:
    /* vide */
    {
        int slot = adresse_var++;
        if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot);
        generer(buf);
        generer("empiler-val 1");
        generer("affect");
        $$ = slot;
    }
    | TOK_PARPAS 
    {
        int slot = adresse_var++;
        if (adresse_var > max_adresse_var) max_adresse_var = adresse_var;
        char buf[256];
        sprintf(buf, "empiler-adr %d", slot);
        generer(buf);
        $<ival>$ = slot;
    }
    expr
    {
        generer("affect");
        $$ = $<ival>2;
    }
    ;



instr_tantque:
     loop_start cond_tantque instructions TOK_FTQ
     {
         char buf[256];
         sprintf(buf, "bra %d", $1);
         generer(buf);
         patcher($2, code_idx);
     }
     ;

loop_start:
     TOK_TANTQUE
     {
         $$ = code_idx;
     }
     ;

cond_tantque:
     TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_FAIRE
     {
         if ($2 != 2) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'tantque' doit etre un booleen\n", yylineno);
             exit(1);
         }
         $$ = code_idx;
         generer("bsf 0");
     }
     | expr TOK_FAIRE
     {
         if ($1 != 2) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: la condition du 'tantque' doit etre un booleen\n", yylineno);
             exit(1);
         }
         $$ = code_idx;
         generer("bsf 0");
     }
     ;

instr_passer:
     TOK_PASSER
     {
         generer("passer");
     }
     ;

expr:
     TOK_ENTIER
     {
         char buf[256];
         sprintf(buf, "empiler-val %d", $1);
         generer(buf);
         $$ = 1;
     }
     | TOK_BOOLEEN
     {
         char buf[256];
         sprintf(buf, "empiler-val %d", $1);
         generer(buf);
         $$ = 2;
     }
     | TOK_IDENTIFIANT
     {
         int idx = -1;
         for (int i = 0; i < nb_vars; i++) {
             if (strcmp(variables[i].nom, $1) == 0) {
                 idx = i;
                 break;
             }
         }
         if (idx == -1) {
             fprintf(stderr, "Erreur: variable '%s' non declaree\n", $1);
             $$ = 0;
         } else if (variables[idx].type == 1) { /* constante */
             char buf[256];
             sprintf(buf, "empiler-val %d", variables[idx].valeur);
             generer(buf);
             $$ = variables[idx].data_type;
         } else { /* variable */
             char buf[256];
             sprintf(buf, "empiler-adr %d", variables[idx].adresse);
             generer(buf);
             generer("valeur-pile");
             $$ = variables[idx].data_type;
         }
     }
     | expr TOK_PLUS expr
     {
        if ($1 != 1 || $3 != 1) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '+' requiert des entiers\n", yylineno);
            exit(1);
        }
        generer("plus");
        $$ = 1;  // result is entier
     }
     | expr TOK_MOINS expr
     {
         if ($1 != 1 || $3 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '-' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("moins");
         $$ = 1;
     }
     | expr TOK_MULT expr
     {
         if ($1 != 1 || $3 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '*' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("mult");
         $$ = 1;
     }
     | expr TOK_DIV expr
     {
         if ($1 != 1 || $3 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '/' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("div");
         $$ = 1;
     }
     | expr TOK_MOD expr
     {
         if ($1 != 1 || $3 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '%%' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("mod");
         $$ = 1;
     }
     | expr TOK_PUISS expr
     {
         if ($1 != 1 || $3 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'puiss' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("puiss");
         $$ = 1;
     }
     | TOK_VALABS TOK_PAREN_OUV expr TOK_PAREN_FERM
     {
         if ($3 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'valabs' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("valabs");
         $$ = 1;
     }
     | TOK_MOINS expr %prec UMINUS
     {
         if ($2 != 1) {
             fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur '-' requiert des entiers\n", yylineno);
             exit(1);
         }
         generer("neg");
         $$ = 1;
     }
     | expr TOK_EGAL expr
     {
         generer("egal");
         $$ = 2;
     }
     | expr TOK_DIFF expr
     {
         generer("dif");
         $$ = 2;
     }
     | expr TOK_INF expr
     {
         generer("pps");
         $$ = 2;
     }
     | expr TOK_SUP expr
     {
         generer("pgs");
         $$ = 2;
     }
     | expr TOK_INF_EG expr
     {
         generer("pp-egal");
         $$ = 2;
     }
     | expr TOK_SUP_EG expr
     {
         generer("pg-egal");
         $$ = 2;
     }
     | expr TOK_ET expr
     {
         if ($1 != 2 || $3 != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'et' requiert des booleens\n", yylineno);
            exit(1);
         }
         generer("et");
         $$ = 2;
     }
     | expr TOK_OU expr
     {
         if ($1 != 2 || $3 != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'ou' requiert des booleens\n", yylineno);
            exit(1);
         }
         generer("ou");
         $$ = 2;
     }
     | TOK_NON expr %prec UNOT
     {
         if ($2 != 2) {
            fprintf(stderr, "[ERREUR SEMANTIQUE] ligne %d: operateur 'non' requiert un booleen\n", yylineno);
            exit(1);
         }
         generer("non");
         $$ = 2;
     }
     | TOK_PAREN_OUV expr TOK_PAREN_FERM
     {
         $$ = $2;
     }
     ;
%%

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