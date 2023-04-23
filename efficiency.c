#include "efficiency.h"
#include <stdio.h>

static struct rusage inicio, fim;

void iniciarTempo() {
    getrusage(RUSAGE_SELF, &inicio);
}

void finalizarTempo() {
    getrusage(RUSAGE_SELF, &fim);

    double segundos = (double) (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + 
                      (double) (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1000000;

    printf("\nTempo total de execução: %lf segundos.\n", segundos);
}

long long calcularMemoriaUtilizada() {
    getrusage(RUSAGE_SELF, &fim);

    return fim.ru_maxrss;
}

double calcularTempoCPU() {
    getrusage(RUSAGE_SELF, &fim);

    return (double) (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + 
           (double) (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1000000;
}

long long contarOperacoesBasicas(void (*f)()) {
    iniciarTempo();

    // Executa a função passada como argumento.
    (*f)();

    finalizarTempo();

    // Calcula o número de operações básicas a partir do tempo de CPU utilizado pela função.
    double tempo_cpu = calcularTempoCPU();
    long long operacoes = (long long) (tempo_cpu * 1e9);

    return operacoes;
}