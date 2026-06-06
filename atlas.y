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
%type <ival> else_marker
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
    instructions
    TOK_FIN optional_point
    {
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
         ajouter_var($2, 1, $4);
     }
     | TOK_BOOL TOK_IDENTIFIANT TOK_EGAL TOK_BOOLEEN TOK_POINT_VIRGULE
     {
         ajouter_var($2, 1, $4);
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
     TOK_ENT  { $$ = 1; }
     | TOK_BOOL { $$ = 2; }
     ;
 
 var_list:
     TOK_IDENTIFIANT
     {
         ajouter_var($1, 0, 0);
     }
     | var_list TOK_VIRGULE TOK_IDENTIFIANT
     {
         ajouter_var($3, 0, 0);
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
         char buf[256];
         sprintf(buf, "empiler_adr(%d);", chercher_var($2));
         generer(buf);
         generer("lire();");
     }
     | TOK_LIRERC TOK_IDENTIFIANT
     {
         char buf[256];
         sprintf(buf, "empiler_adr(%d);", chercher_var($2));
         generer(buf);
         generer("lireRC();");
     }
     | TOK_ECRIRE expr
     {
         generer("ecrire();");
     }
     | TOK_ECRIRERC expr
     {
         generer("ecrireRC();");
     }
     | TOK_IMPRIMER TOK_CHAINE
     {
         char buf[256];
         sprintf(buf, "imprimer(\"%s\");", $2);
         generer(buf);
     }
     | TOK_IMPRIMERRC TOK_CHAINE
     {
         char buf[256];
         sprintf(buf, "imprimerRC(\"%s\");", $2);
         generer(buf);
     }
     ;

instr_affectation:
     TOK_IDENTIFIANT TOK_AFFECT 
     {
         int idx = chercher_var($1);
         char buf[256];
         sprintf(buf, "empiler_adr(%d);", idx);
         generer(buf);
     }
     expr
     {
         generer("affect();");
     }
     ;

instr_si:
     cond_si instructions TOK_FSI
     {
         patcher($1, code_idx);
     }
     | cond_si instructions else_marker instructions TOK_FSI
     {
         patcher($3, code_idx);
     }
     ;

cond_si:
     TOK_SI TOK_PAREN_OUV expr TOK_PAREN_FERM TOK_ALORS
     {
         $$ = code_idx;
         generer("bsf(0000);");
     }
     | TOK_SI expr TOK_ALORS
     {
         $$ = code_idx;
         generer("bsf(0000);");
     }
     ;

else_marker:
     TOK_SINON
     {
         $$ = code_idx;
         generer("bra(0000);");
         patcher($<ival>-1, code_idx); // patch the bsf from cond_si
     }
     ;

instr_pour:
    TOK_POUR TOK_IDENTIFIANT TOK_DEPUIS expr
    {
        int adr = chercher_var($2);
        char buf[256];
        sprintf(buf, "empiler_adr(%d);", adr); generer(buf);
        generer("affect();");
        $<ival>$ = adr; // $5: loop var address
    }
    TOK_JUSQUA expr
    {
        int adr = chercher_var($2);
        char buf[256];
        sprintf(buf, "empiler_adr(%d);", adr); generer(buf);
        generer("affect();");
        $<ival>$ = adr; // $7: limit slot
    }
    pour_opt_step
    {
        $<ival>$ = code_idx; // $9: START OF LOOP LABEL
    }
    {
        char buf[256];
        sprintf(buf, "empiler_adr(%d); valeur_pile();", $<ival>5); generer(buf);
        sprintf(buf, "empiler_adr(%d); valeur_pile();", $<ival>7); generer(buf);
        generer("pp_egal();");
        $<ival>$ = code_idx; // $10: BSF index
        generer("bsf(0000);");
    }
    TOK_FAIRE instructions TOK_FPOUR
    {
        char buf[256];
        // Increment: var = var + step
        sprintf(buf, "empiler_adr(%d); empiler_adr(%d); valeur_pile();", $<ival>5, $<ival>5); generer(buf);
        sprintf(buf, "empiler_adr(%d); valeur_pile();", $<ival>8); generer(buf);
        generer("plus(); affect();");
        
        // Jump back
        sprintf(buf, "goto L%d;", $<ival>9); generer(buf);
        
        // Patch exit
        patcher($<ival>10, code_idx);
    }
    ;

pour_opt_step:
    /* vide */
    {
        int slot = adresse_var++;
        char buf[256];
        sprintf(buf, "empiler_adr(%d); empiler_val(1); affect();", slot);
        generer(buf);
        $$ = slot;
    }
    | TOK_PARPAS expr
    {
        int slot = adresse_var++;
        char buf[256];
        sprintf(buf, "empiler_adr(%d);", slot);
        generer(buf);
        // Step expr is already on stack
        generer("affect();");
        $$ = slot;
    }
    ;



instr_tantque:
     loop_start cond_tantque instructions TOK_FTQ
     {
         char buf[256];
         sprintf(buf, "goto L%d;", $1);
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
         $$ = code_idx;
         generer("bsf(0000);");
     }
     | expr TOK_FAIRE
     {
         $$ = code_idx;
         generer("bsf(0000);");
     }
     ;

instr_passer:
     TOK_PASSER
     {
         generer("/* passer */");
     }
     ;

expr:
     TOK_ENTIER
     {
         char buf[256];
         sprintf(buf, "empiler_val(%d);", $1);
         generer(buf);
         $$ = $1;
     }
     | TOK_BOOLEEN
     {
         char buf[256];
         sprintf(buf, "empiler_val(%d);", $1);
         generer(buf);
         $$ = $1;
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
             sprintf(buf, "empiler_val(%d);", variables[idx].valeur);
             generer(buf);
             $$ = variables[idx].valeur;
         } else { /* variable */
             char buf[256];
             sprintf(buf, "empiler_adr(%d);", variables[idx].adresse);
             generer(buf);
             generer("valeur_pile();");
             $$ = 0;
         }
     }
     | expr TOK_PLUS expr
     {
         generer("plus();");
         $$ = 0;
     }
     | expr TOK_MOINS expr
     {
         generer("moins();");
         $$ = 0;
     }
     | expr TOK_MULT expr
     {
         generer("mult();");
         $$ = 0;
     }
     | expr TOK_DIV expr
     {
         generer("division();");
         $$ = 0;
     }
     | expr TOK_MOD expr
     {
         generer("mod();");
         $$ = 0;
     }
     | expr TOK_PUISS expr
     {
         generer("puiss();");
         $$ = 0;
     }
     | TOK_VALABS TOK_PAREN_OUV expr TOK_PAREN_FERM
     {
         generer("valabs();");
         $$ = 0;
     }
     | TOK_MOINS expr %prec UMINUS
     {
         generer("neg();");
         $$ = 0;
     }
     | expr TOK_EGAL expr
     {
         generer("egal();");
         $$ = 0;
     }
     | expr TOK_DIFF expr
     {
         generer("dif();");
         $$ = 0;
     }
     | expr TOK_INF expr
     {
         generer("pps();");
         $$ = 0;
     }
     | expr TOK_SUP expr
     {
         generer("pgs();");
         $$ = 0;
     }
     | expr TOK_INF_EG expr
     {
         generer("pp_egal();");
         $$ = 0;
     }
     | expr TOK_SUP_EG expr
     {
         generer("pg_egal();");
         $$ = 0;
     }
     | expr TOK_ET expr
     {
         generer("et();");
         $$ = 0;
     }
     | expr TOK_OU expr
     {
         generer("ou();");
         $$ = 0;
     }
     | TOK_NON expr %prec UNOT
     {
         generer("non();");
         $$ = 0;
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