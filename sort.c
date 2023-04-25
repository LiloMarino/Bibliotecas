#include "sort.h"
#include <stdlib.h>
#include <string.h>

void SelectionSortInt(int V[], int n)
{
    int i, j, minimo;
    for (i = 0; i <= n - 2; i++)
    {
        minimo = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (V[j] < V[minimo])
            {
                minimo = j;
            }
        }
        /*Troca*/
        Swap(&V[minimo], &V[i], sizeof(int));
    }
}

void BubbleSortInt(int V[], int n)
{
}

void SelectionSortChar(char V[], int n)
{
    int i, j, minimo;
    for (i = 0; i <= n - 2; i++)
    {
        minimo = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (V[j] < V[minimo])
            {
                minimo = j;
            }
        }
        /*Troca*/
        Swap(&V[minimo], &V[i], sizeof(char));
    }
}

void BubbleSortChar(char V[], int n)
{
}

void Swap(Sort A, Sort B, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, A, size);
    memcpy(A, B, size);
    memcpy(B, temp, size);
    free(temp);
}
