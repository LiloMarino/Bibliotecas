#include "efficiency.h"
#include <stdio.h>
#include <sys/time.h>
#include <stdarg.h>

static struct rusage inicio, fim;
struct timeval tempo_inicio, tempo_fim;

void iniciarTempo()
{
    gettimeofday(&tempo_inicio, NULL);
}

long double finalizarTempo()
{
    gettimeofday(&tempo_fim, NULL);

    long double segundos = (long double)(tempo_fim.tv_sec - tempo_inicio.tv_sec) +
                          (long double)(tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0L;
    #if ALLOW_PRINT == 1
        printf("\nTempo total de execução: %Lf segundos.\n", segundos);
    #endif
    return segundos;
}

long double calcularMemoriaUtilizada()
{
    getrusage(RUSAGE_SELF, &fim);
    #if ALLOW_PRINT == 1
        printf("\nMemória utilizada: %ld bytes.\n", fim.ru_maxrss);
    #endif
    return fim.ru_maxrss;
}

long double calcularTempoCPU()
{
    getrusage(RUSAGE_SELF, &fim);

    long double tempo_cpu = (long double)(fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) +
                            (long double)(fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1000000.0L;
    #if ALLOW_PRINT == 1
        printf("\nTempo de CPU utilizado: %Lf segundos.\n", tempo_cpu);
    #endif
    return tempo_cpu;
}