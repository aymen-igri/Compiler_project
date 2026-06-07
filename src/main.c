#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atlas.h"

/* Simple execution engine using the code already in memory */
extern int pile[10000];
extern int ip;
extern int CO;

/* Prototypes from simulator.c logic */
void ouverture_bloc();
void fermeture_bloc();
void reserver_var(int n);
void empiler_val(int k);
void empiler_adr(int a);
void valeur_pile();
void affect();
void lire();
void lireRC();
void ecrire();
void ecrireRC();
void imprimer(char *text);
void imprimerRC(char *text);
void plus();
void moins();
void mult();
void division();
void mod();
void puiss();
void valabs();
void neg();
void egal();
void dif();
void pgs();
void pps();
void pg_egal();
void pp_egal();
void ou();
void et();
void non();
void bra(int etiq);
void bsv(int etiq);
void bsf(int etiq);

void save_map(const char *filename) {
    FILE *map_file = fopen(filename, "w");
    if (!map_file) {
        fprintf(stderr, "Impossible de creer : %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < code_idx; i++) {
        fprintf(map_file, "%d\t%s\n", i + 1, code[i].instruction);
    }
    fclose(map_file);
    printf("MAP code generated: %s\n", filename);
}

void execute_internal() {
    ouverture_bloc();
    while (CO < code_idx) {
        char instr[256];
        int arg = 0;
        char text[256] = "";
        
        sscanf(code[CO].instruction, "%s", instr);
        
        if (strcmp(instr, "ouverture-bloc") == 0) CO++;
        else if (strcmp(instr, "fermeture-bloc") == 0) fermeture_bloc();
        else if (strcmp(instr, "reserver-var") == 0) { sscanf(code[CO].instruction, "%*s %d", &arg); reserver_var(arg); CO++; }
        else if (strcmp(instr, "empiler-val") == 0) { sscanf(code[CO].instruction, "%*s %d", &arg); empiler_val(arg); CO++; }
        else if (strcmp(instr, "empiler-adr") == 0) { sscanf(code[CO].instruction, "%*s %d", &arg); empiler_adr(arg); CO++; }
        else if (strcmp(instr, "valeur-pile") == 0) { valeur_pile(); CO++; }
        else if (strcmp(instr, "affect") == 0) { affect(); CO++; }
        else if (strcmp(instr, "lire") == 0) { lire(); CO++; }
        else if (strcmp(instr, "lireRC") == 0) { lireRC(); CO++; }
        else if (strcmp(instr, "ecrire") == 0) { ecrire(); CO++; }
        else if (strcmp(instr, "ecrireRC") == 0) { ecrireRC(); CO++; }
        else if (strcmp(instr, "imprimer") == 0) { sscanf(code[CO].instruction, "imprimer %[^\n]", text); imprimer(text); CO++; }
        else if (strcmp(instr, "imprimerRC") == 0) { sscanf(code[CO].instruction, "imprimerRC %[^\n]", text); imprimerRC(text); CO++; }
        else if (strcmp(instr, "plus") == 0) { plus(); CO++; }
        else if (strcmp(instr, "moins") == 0) { moins(); CO++; }
        else if (strcmp(instr, "mult") == 0) { mult(); CO++; }
        else if (strcmp(instr, "div") == 0) { division(); CO++; }
        else if (strcmp(instr, "mod") == 0) { mod(); CO++; }
        else if (strcmp(instr, "puiss") == 0) { puiss(); CO++; }
        else if (strcmp(instr, "valabs") == 0) { valabs(); CO++; }
        else if (strcmp(instr, "neg") == 0) { neg(); CO++; }
        else if (strcmp(instr, "egal") == 0) { egal(); CO++; }
        else if (strcmp(instr, "dif") == 0) { dif(); CO++; }
        else if (strcmp(instr, "pps") == 0) { pps(); CO++; }
        else if (strcmp(instr, "pgs") == 0) { pgs(); CO++; }
        else if (strcmp(instr, "pp-egal") == 0) { pp_egal(); CO++; }
        else if (strcmp(instr, "pg-egal") == 0) { pg_egal(); CO++; }
        else if (strcmp(instr, "et") == 0) { et(); CO++; }
        else if (strcmp(instr, "ou") == 0) { ou(); CO++; }
        else if (strcmp(instr, "non") == 0) { non(); CO++; }
        else if (strcmp(instr, "bsf") == 0) { sscanf(code[CO].instruction, "%*s %d", &arg); bsf(arg - 1); }
        else if (strcmp(instr, "bsv") == 0) { sscanf(code[CO].instruction, "%*s %d", &arg); bsv(arg - 1); }
        else if (strcmp(instr, "bra") == 0) { sscanf(code[CO].instruction, "%*s %d", &arg); bra(arg - 1); }
        else { CO++; }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier.atlas>\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) { fprintf(stderr, "Impossible d'ouvrir : %s\n", argv[1]); return 1; }
    yyin = f;
    int result = yyparse();
    fclose(f);
    if (result == 0) {
        if (code_idx > 1 && strncmp(code[1].instruction, "reserver-var", 12) == 0) {
            sprintf(code[1].instruction, "reserver-var %d", max_adresse_var);
        }
        char map_fileName[256];
        strcpy(map_fileName, argv[1]);
        char *dot = strrchr(map_fileName, '.');
        if (dot) strcpy(dot, ".map"); else strcat(map_fileName, ".map");
        save_map(map_fileName);
        printf("\nExecuting MAP code...\n");
        execute_internal();
    }
    return result;
}
