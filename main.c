#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atlas.h"

/* The interpreter logic is included via map_interpreter_logic.c or similar */
/* To keep it simple, we'll re-implement a minimal runner or call the interpreter */

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

void display_map() {
    printf("\n--- Generated MAP Code ---\n");
    for (int i = 0; i < code_idx; i++) {
        printf("%d\t%s\n", i + 1, code[i].instruction);
    }
    printf("--------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier.atlas>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Impossible d'ouvrir : %s\n", argv[1]);
        return 1;
    }
    yyin = f;
    
    int result = yyparse();
    fclose(f);

    if (result == 0) {
        // Patch reserver-var with max_adresse_var
        if (code_idx > 1 && strncmp(code[1].instruction, "reserver-var", 12) == 0) {
            sprintf(code[1].instruction, "reserver-var %d", max_adresse_var);
        }

        char map_fileName[256];
        strcpy(map_fileName, argv[1]);
        char *dot = strrchr(map_fileName, '.');
        if (dot) strcpy(dot, ".map");
        else strcat(map_fileName, ".map");

        save_map(map_fileName);
        display_map();

        printf("\nExecuting MAP code...\n");
        char command[512];
        sprintf(command, "./map_interpreter %s", map_fileName);
        system(command);
    }

    return result;
}
