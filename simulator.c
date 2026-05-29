#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pile[10000];
int ip = 0;
int CO = 0;

void ouverture_bloc()
{
    ip = 0;
}
void fermeture_bloc()
{
    exit(0);
}
void empiler_val(int k)
{
    ip++;
    pile[ip] = k;
}
void empiler_adr(int a)
{
    ip++;
    pile[ip] = a;
}
void reserver_var(int n)
{
    for (int i = ip; i < ip + n; i++)
    {
        pile[i] = 0;
    }
    ip += n;
}
void valeur_pile()
{
    pile[ip] = pile[pile[ip]];
}
void affect()
{
    pile[pile[ip - 1]] = pile[ip];
    ip -= 2;
}
void ecrire()
{
    printf("%d", pile[ip]);
    ip--;
}
void ecrireRC()
{
    printf("%d\n", pile[ip]);
    ip--;
}
void lire()
{
    scanf("%d", &pile[pile[ip]]);
    ip--;
}
void lireRC()
{
    scanf("%d", &pile[pile[ip]]);
    printf("\n");
    ip--;
}
void valabs()
{
    pile[ip] = pile[ip] >= 0 ? pile[ip] : -pile[ip];
}
void neg()
{
    pile[ip] = -pile[ip];
}
void non()
{
    pile[ip] = ~pile[ip];
}
void plus()
{
    pile[ip - 1] = pile[ip - 1] + pile[ip];
    ip--;
}
void moins()
{
    pile[ip - 1] = pile[ip - 1] - pile[ip];
    ip--;
}
void mult()
{
    pile[ip - 1] = pile[ip - 1] * pile[ip];
    ip--;
}
void division()
{
    pile[ip - 1] = pile[ip - 1] / pile[ip];
    ip--;
}
void mod()
{
    pile[ip - 1] = pile[ip - 1] % pile[ip];
    ip--;
}
void puiss()
{
    int result = 1;
    for (int i = 0; i < pile[ip]; i++)
    {
        result *= pile[ip - 1];
    }
    pile[ip - 1] = result;
    ip--;
}
void egal()
{
    pile[ip - 1] = pile[ip - 1] == pile[ip] ? 1 : 0;
    ip--;
}
void dif()
{
    pile[ip - 1] = pile[ip - 1] != pile[ip] ? 1 : 0;
    ip--;
}
void ou()
{
    pile[ip - 1] = pile[ip - 1] || pile[ip] ? 1 : 0;
    ip--;
}
void et()
{
    pile[ip - 1] = pile[ip - 1] && pile[ip] ? 1 : 0;
    ip--;
}

void pgs()
{
    pile[ip - 1] = pile[ip - 1] > pile[ip] ? 1 : 0;
    ip--;
}
void pps()
{
    pile[ip - 1] = pile[ip - 1] < pile[ip] ? 1 : 0;
    ip--;
}
void pg_egal()
{
    pile[ip - 1] = pile[ip - 1] >= pile[ip] ? 1 : 0;
    ip--;
}
void pp_egal()
{
    pile[ip - 1] = pile[ip - 1] <= pile[ip] ? 1 : 0;
    ip--;
}
void imprimer(char *text)
{
    printf("%s ", text);
}
void imprimerRC(char *text)
{
    printf("%s\n", text);
}
void bra(int etiq)
{
    CO = etiq;
}
void bsv(int etiq)
{
    CO = (pile[ip] == 1) ? etiq : CO + 1;
    ip--;
}
void bsf(int etiq)
{
    CO = (pile[ip] == 0) ? etiq : CO + 1;
    ip--;
}
/* main removed to avoid conflict with generated code */
#if 0
int main() {
    ouverture_bloc();      // 1
    reserver_var(3);       // 2  - reserves a(0), b(1), c(2)
    empiler_adr(0);        // 3  - push address of a
    lire();                // 4  - read a
    empiler_adr(1);        // 5  - push address of b
    lire();                // 6  - read b
    empiler_adr(2);        // 7  - push address of c
    empiler_adr(0);        // 8  - push address of a
    valeur_pile();         // 9  - get value of a
    empiler_adr(1);        // 10 - push address of b
    valeur_pile();         // 11 - get value of b
    plus();                // 12 - a + b
    affect();              // 13 - c := a + b
    empiler_adr(2);        // 15 - push address of c
    valeur_pile();         // 16 - get value of c
    ecrire();              // 17 - print c
    fermeture_bloc();      // 18
    return 0;
}
#endif
