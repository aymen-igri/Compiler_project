#include <stdio.h>
#include "atlas.tab.h"
extern int yylex();
extern char *yytext;
extern FILE *yyin;

int main() {
    int tok;
    yyin = fopen("TestProgram/somme.atlas", "r");
    while ((tok = yylex()) != 0) {
        printf("Token: %d, Text: '%s'\n", tok, yytext);
    }
    return 0;
}
