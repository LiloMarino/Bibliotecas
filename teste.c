#include <stdio.h>
#include "efficiency.h"
#include "geradores.h"

#define MAX_LENGHT 300

int main()
{
    FILE *log = CriaLog("logs/log");
    InicializaRand();

    iniciarTempo();
    GerarMatrizChar("M",20,20,"testeM1.txt");
    fprintf(log, "Gerar M:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    iniciarTempo();
    GerarMatrizChar("M",20,20,"testeM2.txt");
    fprintf(log, "Gerar M:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    iniciarTempo();
    GerarMatrizChar("Mm",20,20,"testeMm1.txt");
    fprintf(log, "Gerar Mm:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    iniciarTempo();
    GerarMatrizChar("Mm",20,20,"testeMm2.txt");
    fprintf(log, "Gerar Mm:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    iniciarTempo();
    GerarMatrizChar("m",20,20,"testem1.txt");
    fprintf(log, "Gerar m:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    iniciarTempo();
    GerarMatrizChar("m",20,20,"testem2.txt");
    fprintf(log, "Gerar m:\nTempo total de execução: %lf segundos.\n", finalizarTempo());

    fclose(log);
}