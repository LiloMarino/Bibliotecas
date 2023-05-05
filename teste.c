#include <stdio.h>
#include "efficiency.h"
#include "geradores.h"

#define MAX_LENGHT 300

int main()
{
    int vetor_int[MAX_LENGHT];
    int ni = MAX_LENGHT;
    FILE *log = CriaLog("logs/log");
    InicializaRand();

    iniciarTempo();
    GerarVetorInt(1,100,vetor_int,ni);
    fprintf(log, "Gerar VetInt:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    ImprimeVetorInt(vetor_int, ni);

    iniciarTempo();
    GerarVetorInt(1,100,vetor_int,ni);
    fprintf(log, "Gerar VetInt:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    ImprimeVetorInt(vetor_int, ni);
    
    fclose(log);
}