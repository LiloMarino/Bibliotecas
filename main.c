#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "efficiency.h"
#include "geradores.h"

#define MAX_LENGHT 10000

void ImprimeVetorChar(char vetor_char[], int nc)
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
    char vetor_char[MAX_LENGHT];
    char Copy[MAX_LENGHT];
    int vetor_int[MAX_LENGHT];
    int nc = MAX_LENGHT;
    int ni = MAX_LENGHT;
    FILE *log = CriaLog("logs/log");

    // GerarVetorInt(0,100,vetor_int,ni);
    GerarString(nc, vetor_char);

    // Imprime o vetor char desordenado
    printf("Vetor char desordenado: ");
    ImprimeVetorChar(vetor_char, nc);

    // Imprime o vetor int desordenado
    /*printf("Vetor int desordenado: ");
    ImprimeVetorInt(vetor_int, ni);*/

    // Ordena o vetor char
    strcpy(Copy, vetor_char);
    iniciarTempo();
    SelectionSortChar(Copy, nc);
    fprintf(log, "SelectionSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    TiredBubbleSortChar(Copy, nc);
    fprintf(log, "TiredBubbleSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    BubbleSortChar(Copy, nc);
    fprintf(log, "BubbleSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    InsertionSortChar(Copy, nc);
    fprintf(log, "InsertionSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    ShellSortChar(Copy, nc);
    fprintf(log, "ShellSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);

    /*strcpy(Copy, vetor_char);
    iniciarTempo();
    QuickSortChar(Copy,0,nc);
    fprintf(log, "QuickSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);

    strcpy(Copy, vetor_char);
    iniciarTempo();
    HeapSortChar(Copy,nc);
    fprintf(log, "HeapSortChar:\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    printf("Vetor char ordenado: ");
    ImprimeVetorChar(Copy, nc);*/

    // Ordena o vetor int
    /*iniciarTempo();
    SelectionSortInt(vetor_int,ni);
    fprintf(log,"Int:\nTempo total de execução: %lf segundos.\n",finalizarTempo());
    printf("Vetor int ordenado: ");
    ImprimeVetorInt(vetor_int,ni);*/
    
    fclose(log);
    return 0;
}