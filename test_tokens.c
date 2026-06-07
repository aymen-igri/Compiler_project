#include <stdio.h>
#include "atlas.tab.h"
extern int yylex();
extern char *yytext;
extern FILE *yyin;

const char* token_name(int tok) {
    switch(tok) {
        case TOK_PROGRAMME: return "TOK_PROGRAMME";
        case TOK_IDENTIFIANT: return "TOK_IDENTIFIANT";
        case TOK_POINT_VIRGULE: return "TOK_POINT_VIRGULE";
        case TOK_DEBUT: return "TOK_DEBUT";
        case TOK_FIN: return "TOK_FIN";
        case TOK_VAR: return "TOK_VAR";
        case TOK_ENT: return "TOK_ENT";
        case 0: return "EOF";
        default: return "OTHER";
    }
}

int main() {
    FILE *f = fopen("/tmp/test_minimal.atlas", "r");
    if (!f) { printf("Cannot open file\n"); return 1; }
    yyin = f;
    int tok;
    while ((tok = yylex()) != 0) {
        printf("Token: %s, Text: '%s'\n", token_name(tok), yytext);
    }
    printf("EOF reached\n");
    return 0;
}
