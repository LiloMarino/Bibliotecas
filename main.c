#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
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

void ImprimeVetorInt(int vetor_int[], int ni)
{
    // Imprime o vetor int
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");
}

int main()
{
    char vetor_char[MAX_LENGHT] = "\0";
    char Copy[MAX_LENGHT];
    FILE *log = CriaLog("logs/log");

    // GerarVetorInt(0,100,vetor_int,ni);
    GerarString(MAX_LENGHT, vetor_char);

    // Imprime o vetor char desordenado
    printf("Vetor char desordenado: ");
    ImprimeVetorChar(vetor_char, MAX_LENGHT);

    // Imprime o vetor int desordenado
    /*printf("Vetor int desordenado: ");
    ImprimeVetorInt(vetor_int, ni);*/

    // Ordena o vetor char
    strcpy(Copy, vetor_char);
    iniciarTempo();
    SelectionSortChar(Copy, MAX_LENGHT);
    fprintf(log, "SelectionSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    TiredBubbleSortChar(Copy, MAX_LENGHT);
    fprintf(log, "TiredBubbleSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    BubbleSortChar(Copy, MAX_LENGHT);
    fprintf(log, "BubbleSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    InsertionSortChar(Copy, MAX_LENGHT);
    fprintf(log, "InsertionSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    ShellSortChar(Copy, MAX_LENGHT);
    fprintf(log, "ShellSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    QuickSortChar(Copy, 0, MAX_LENGHT);
    fprintf(log, "QuickSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    HeapSortChar(Copy, MAX_LENGHT);
    fprintf(log, "HeapSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, MAX_LENGHT);

    fclose(log);
    return 0;
}