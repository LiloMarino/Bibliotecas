#include "efficiency.h"
#include <stdio.h>
#include <sys/time.h>

static struct rusage inicio, fim;
struct timeval tempo_inicio, tempo_fim;

void iniciarTempo() {
    gettimeofday(&tempo_inicio, NULL);
}

void finalizarTempo() {
    gettimeofday(&tempo_fim, NULL);

    double segundos = (double)(tempo_fim.tv_sec - tempo_inicio.tv_sec) + 
                      (double)(tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000;

    printf("\nTempo total de execução: %lf segundos.\n", segundos);
}

void calcularMemoriaUtilizada() {
    getrusage(RUSAGE_SELF, &fim);

    printf("\nMemória utilizada: %lld bytes.\n", fim.ru_maxrss);
}

void calcularTempoCPU() {
    getrusage(RUSAGE_SELF, &fim);

    double tempo_cpu = (double) (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + 
                      (double) (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1000000;
    
    printf("\nTempo de CPU utilizado: %lf segundos.\n", tempo_cpu);
}

void contarOperacoesBasicas(void (*f)())
{
    iniciarTempo();

    // Executa a função passada como argumento.
    (*f)();

    finalizarTempo();

    // Calcula o número de operações básicas a partir do tempo de CPU utilizado pela função.
    double tempo_cpu = (double) (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + 
                      (double) (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1000000;
    long long operacoes = (long long) (tempo_cpu * 1e9);
    
    printf("\nNúmero de operações básicas: %lld.\n", operacoes);
}