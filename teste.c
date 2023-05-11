#include <stdio.h>
#include "efficiency.h"
#include "utilities.h"
#include <unistd.h>

#define FIM 100

int main()
{
    time_t inicio = time(NULL);
    iniciarTempo();
    for (int i = 0; i <= FIM; i++)
    {
        sleep(1);
        BarraDeProgressoETA(i,FIM,inicio);
    }
    printf("\n");
    printf("Tempo total de execução: %lf segundos.\n", finalizarTempo());
}