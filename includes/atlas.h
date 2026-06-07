#ifndef ATLAS_H
#define ATLAS_H

#include <stdio.h>

/* Code generation structures */
typedef struct {
    char instruction[256];
} Instruction;

extern Instruction code[10000];
extern int code_idx;
extern int max_adresse_var;
extern int adresse_var;

/* Parser functions and variables */
extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char *msg);

#endif
