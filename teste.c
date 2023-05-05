#include <stdio.h>
#include "efficiency.h"
#include "geradores.h"

#define MAX_LENGHT 300

void ImprimeVetorChar(const char vetor_char[], int nc)
{
    // Imprime o vetor char
    for (int i = 0; i < nc; i++)
    {
        printf("%c ", vetor_char[i]);
    }
    printf("\n");
}

int main()
{
    char vetor_char[MAX_LENGHT];
    int nc = MAX_LENGHT;
    int ni;
    float nf;
    FILE *log = CriaLog("logs/log");
    InicializaRand();

    iniciarTempo();
    GerarString(nc, vetor_char);
    fprintf(log, "Gerar String:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    ImprimeVetorChar(vetor_char, nc);

    iniciarTempo();
    GerarString(nc, vetor_char);
    fprintf(log, "Gerar String:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    ImprimeVetorChar(vetor_char, nc);

    iniciarTempo();
    for (int i = 0; i < MAX_LENGHT; i++)
    {
        ni = GerarNumeroInt(1, 100);
        printf("%d ", ni);
    }
    printf("\n");
    fprintf(log, "Gerar Int:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    iniciarTempo();
    for (int i = 0; i < MAX_LENGHT; i++)
    {
        nf = GerarNumeroFloat(1, 100);
        printf("%lf ", nf);
    }
    printf("\n");
    fprintf(log, "Gerar Float:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    fclose(log);
}