#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "efficiency.h"

int main()
{
    char vetor_char[] = {'d', 'a', 'c', 'f', 'e', 'b', 'g', 'h', 'i', 'a', 'd', 'f', 'e', 'b', 'g', 'h', 'c', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'd', 'a', 'c', 'f', 'e', 'b', 'g', 'h', 'i', 'a', 'd', 'f', 'e', 'b', 'g', 'h', 'c', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int vetor_int[] = {5, 1, 7, 3, 9, 2, 8, 4, 6, 1, 5, 3, 2, 4, 6, 7, 8, 9, 10, 11, 13, 12, 15, 14, 16, 18, 17, 19, 20, 22, 21, 23, 24, 25, 26, 28, 27, 29, 30, 32, 31, 34, 33, 35, 36, 38, 37, 39, 40, 42, 41, 43, 44, 46, 45, 47, 49, 48, 50, 52, 51, 53, 54, 56, 55, 58, 57, 59, 60, 62, 61, 63, 64, 66, 65, 68, 67, 69, 70, 72, 71, 73, 74, 76, 75, 77, 78, 80, 79, 81, 83, 82, 84, 85, 87, 86, 88, 89, 91, 90, 92, 93, 95, 94, 96, 97, 99, 98};
    int nc = sizeof(vetor_char) / sizeof(char);
    int ni = sizeof(vetor_int) / sizeof(int);

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
    contarOperacoesBasicas(&SelectionSortChar, vetor_char, nc);
    
    // Ordena o vetor int
    contarOperacoesBasicas(&SelectionSortInt, vetor_int, ni);

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