%{
#include <stdio.h>
extern int yylex();
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }
%}
%token TOK_PROGRAMME TOK_IDENTIFIANT TOK_POINT_VIRGULE
%%
programme:
    TOK_PROGRAMME TOK_IDENTIFIANT TOK_POINT_VIRGULE
    { printf("Parsed successfully!\n"); }
    ;
%%
int main() { return yyparse(); }
