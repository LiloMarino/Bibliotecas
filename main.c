#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "efficiency.h"
#include "geradores.h"

#define MAX_LENGHT 1000

int main()
{
    char vetor_char[MAX_LENGHT]; 
    int vetor_int[MAX_LENGHT]; 
    int nc = MAX_LENGHT;
    int ni = MAX_LENGHT;

    GerarVetorInt(0,100,vetor_int,ni);
    GerarString(nc,vetor_char);

    // Imprime o vetor char desordenado
    printf("Vetor char desordenado: ");
    for (int i = 0; i < nc; i++)
    {
        printf("%c ", vetor_char[i]);
    }
    printf("\n");

    // Imprime o vetor int desordenado
    printf("Vetor int desordenado: ");
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");

    // Ordena o vetor char
    iniciarTempo();
    SelectionSortChar(vetor_char,nc);
    finalizarTempo();
    
    // Ordena o vetor int
    iniciarTempo();
    SelectionSortInt(vetor_int,ni);
    finalizarTempo();

    // Imprime o vetor char ordenado
    printf("Vetor char ordenado: ");
    for (int i = 0; i < nc; i++)
    {
        printf("%c ", vetor_char[i]);
    }
    printf("\n");

    // Imprime o vetor int ordenado
    printf("Vetor int ordenado: ");
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");

    return 0;
}