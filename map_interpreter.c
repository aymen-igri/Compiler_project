#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulator.c"

#define MAX_INSTRUCTIONS 10000

typedef struct {
    char instruction[256];
    int has_arg;
    int arg;
    char text[256];
} MapInstruction;

MapInstruction map_code[MAX_INSTRUCTIONS];
int map_size = 0;

void load_map(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Impossible d'ouvrir : %s\n", filename);
        exit(1);
    }
    
    char line[512];
    while (fgets(line, sizeof(line), f)) {
        int line_num;
        char instr[256];
        
        // Parse line: "NUM\tINSTRUCTION [ARG]"
        if (sscanf(line, "%d\t%255s", &line_num, instr) == 2) {
            strcpy(map_code[map_size].instruction, instr);
            
            // Check if instruction has argument
            char *arg_str = strchr(line, '\t');
            if (arg_str) {
                arg_str = strchr(arg_str + 1, ' ');
                if (arg_str) {
                    // Try to parse as integer
                    if (sscanf(arg_str, "%d", &map_code[map_size].arg) == 1) {
                        map_code[map_size].has_arg = 1;
                    } else {
                        // It's a string argument (for imprimer)
                        sscanf(arg_str, "%255s", map_code[map_size].text);
                        map_code[map_size].has_arg = 1;
                    }
                }
            }
            
            map_size++;
        }
    }
    
    fclose(f);
}

void execute_map() {
    ouverture_bloc();
    
    while (CO < map_size) {
        MapInstruction *current = &map_code[CO];
        
        if (strcmp(current->instruction, "ouverture-bloc") == 0) {
            // Already called above
            CO++;
        }
        else if (strcmp(current->instruction, "fermeture-bloc") == 0) {
            fermeture_bloc();
        }
        else if (strcmp(current->instruction, "reserver-var") == 0) {
            reserver_var(current->arg);
            CO++;
        }
        else if (strcmp(current->instruction, "reserver-kst") == 0) {
            // Not implemented in current simulator
            CO++;
        }
        else if (strcmp(current->instruction, "empiler-val") == 0) {
            empiler_val(current->arg);
            CO++;
        }
        else if (strcmp(current->instruction, "empiler-adr") == 0) {
            empiler_adr(current->arg);
            CO++;
        }
        else if (strcmp(current->instruction, "valeur-pile") == 0) {
            valeur_pile();
            CO++;
        }
        else if (strcmp(current->instruction, "affect") == 0) {
            affect();
            CO++;
        }
        else if (strcmp(current->instruction, "lire") == 0) {
            lire();
            CO++;
        }
        else if (strcmp(current->instruction, "lireRC") == 0) {
            lireRC();
            CO++;
        }
        else if (strcmp(current->instruction, "ecrire") == 0) {
            ecrire();
            CO++;
        }
        else if (strcmp(current->instruction, "ecrireRC") == 0) {
            ecrireRC();
            CO++;
        }
        else if (strcmp(current->instruction, "imprimer") == 0) {
            imprimer(current->text);
            CO++;
        }
        else if (strcmp(current->instruction, "imprimerRC") == 0) {
            imprimerRC(current->text);
            CO++;
        }
        else if (strcmp(current->instruction, "plus") == 0) {
            plus();
            CO++;
        }
        else if (strcmp(current->instruction, "moins") == 0) {
            moins();
            CO++;
        }
        else if (strcmp(current->instruction, "mult") == 0) {
            mult();
            CO++;
        }
        else if (strcmp(current->instruction, "div") == 0) {
            division();
            CO++;
        }
        else if (strcmp(current->instruction, "mod") == 0) {
            mod();
            CO++;
        }
        else if (strcmp(current->instruction, "puiss") == 0) {
            puiss();
            CO++;
        }
        else if (strcmp(current->instruction, "valabs") == 0) {
            valabs();
            CO++;
        }
        else if (strcmp(current->instruction, "neg") == 0) {
            neg();
            CO++;
        }
        else if (strcmp(current->instruction, "egal") == 0) {
            egal();
            CO++;
        }
        else if (strcmp(current->instruction, "dif") == 0) {
            dif();
            CO++;
        }
        else if (strcmp(current->instruction, "pps") == 0) {
            pps();
            CO++;
        }
        else if (strcmp(current->instruction, "pgs") == 0) {
            pgs();
            CO++;
        }
        else if (strcmp(current->instruction, "pp-egal") == 0) {
            pp_egal();
            CO++;
        }
        else if (strcmp(current->instruction, "pg-egal") == 0) {
            pg_egal();
            CO++;
        }
        else if (strcmp(current->instruction, "et") == 0) {
            et();
            CO++;
        }
        else if (strcmp(current->instruction, "ou") == 0) {
            ou();
            CO++;
        }
        else if (strcmp(current->instruction, "non") == 0) {
            non();
            CO++;
        }
        else if (strcmp(current->instruction, "bsf") == 0) {
            bsf(current->arg);
        }
        else if (strcmp(current->instruction, "bsv") == 0) {
            bsv(current->arg);
        }
        else if (strcmp(current->instruction, "bra") == 0) {
            bra(current->arg);
        }
        else if (strcmp(current->instruction, "passer") == 0) {
            // No-op
            CO++;
        }
        else {
            fprintf(stderr, "Instruction inconnue: %s\n", current->instruction);
            CO++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier.map>\n", argv[0]);
        return 1;
    }
    
    load_map(argv[1]);
    execute_map();
    
    return 0;
}