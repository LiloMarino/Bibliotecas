#include "sort.h"
#include <stdlib.h>
#include <stdbool.h>
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
        Swap(&V[minimo], &V[i], sizeof(int));
    }
}

void TiredBubbleSortInt(int V[], int n)
{
    for (int j = n - 2; j >= 1; j--)
    {
        for (int i = 0; i <= j; i++)
        {
            if (V[i] > V[i + 1])
            {
                Swap(&V[i], &V[i + 1], sizeof(int));
            }
        }
    }
}

void BubbleSortInt(int V[], int n)
{
    bool trocado;
    do
    {
        trocado = false;
        for (int i = 0; i <= n - 2; i++)
        {
            if (V[i] > V[i + 1])
            {
                Swap(&V[i], &V[i + 1], sizeof(int));
                trocado = true;
            }
        }
        n = n - 1;
    } while (!trocado);
}

void InsertionSortInt(int V[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i <= n - 1; i++)
    {
        temp = V[i];
        j = i - 1;
        while (temp < V[j] && j >= 0)
        {
            V[j+1] = V[j];
            j = j - 1;
        }
        V[j+1] = temp;
    }
}

void ShellSortInt(int V[], int n)
{
    int i, j, k, temp;

    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            temp = V[i];
            for (j = i; j >= k; j -= k)
            {
                if (temp < V[j - k])
                {
                    V[j] = V[j - k];
                }
                else
                {
                    break;
                }
            }
            V[j] = temp;
        }
    }
}


void QuickSortInt(int V[], int i, int f)
{
    int pivo, j;
    if (i == f)
    {
        return;
    }

    /* Adquire o Pivo */
    pivo = (i+f)/2;

    /* Particiona */
    int e,d;
    e = i;
    d = f;
    while (e < d)
    {
        while ((d > i) && (V[d] > pivo))
        {
            d--;
        }
        while ((e < f) && (V[e] < pivo))
        {
            e++;
        }
        if (e < d)
        {
            Swap(&V[d],&V[e],sizeof(int));
            e++;
            d--;
        }
        
    }
    j = d;

    /*Quick Sort*/
    QuickSortInt(V,i,j);
    QuickSortInt(V,j+1,f);
}

void HeapifyInt(int V[], int n, int i)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && V[esq] > V[maior])
        maior = esq;

    if (dir < n && V[dir] > V[maior])
        maior = dir;

    if (maior != i)
    {
        Swap(&V[i], &V[maior], sizeof(int));
        HeapifyInt(V, n, maior);
    }
}

void HeapSortInt(int V[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyInt(V, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        Swap(&V[0], &V[i], sizeof(int));
        HeapifyInt(V, i, 0);
    }
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
        Swap(&V[minimo], &V[i], sizeof(char));
    }
}

void TiredBubbleSortChar(char V[], int n)
{
    for (int j = n - 2; j >= 1; j--)
    {
        for (int i = 0; i <= j; i++)
        {
            if (V[i] > V[i + 1])
            {
                Swap(&V[i], &V[i + 1], sizeof(char));
            }
        }
    }
}

void BubbleSortChar(char V[], int n)
{
    bool trocado;
    do
    {
        trocado = false;
        for (int i = 0; i <= n - 2; i++)
        {
            if (V[i] > V[i + 1])
            {
                Swap(&V[i], &V[i + 1], sizeof(char));
                trocado = true;
            }
        }
        n = n - 1;
    } while (!trocado);
}

void InsertionSortChar(char V[], int n)
{
    int i, j;
    char temp;
    for (i = 1; i <= n - 1; i++)
    {
        temp = V[i];
        j = i - 1;
        while (temp < V[j] && j >= 0)
        {
            V[j+1] = V[j];
            j = j - 1;
        }
        V[j+1] = temp;
    }
}

void ShellSortChar(char V[], int n)
{
    int i, j, k;
    char temp;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            temp = V[i];
            for (j = i; j >= k; j -= k)
            {
                if (temp < V[j - k])
                {
                    V[j] = V[j - k];
                }
                else
                {
                    break;
                }
            }
            V[j] = temp;
        }
    }
}


void QuickSortChar(char V[], int i, int f)
{
    int pivo, j;
    if (i == f)
    {
        return;
    }
    
    /* Adquire o Pivo */
    pivo = (i+f)/2;

    /* Particiona */
    int e,d;
    e = i;
    d = f;
    while (e < d)
    {
        while ((d > i) && (V[d] > pivo))
        {
            d--;
        }
        while ((e < f) && (V[e] < pivo))
        {
            e++;
        }
        if (e < d)
        {
            Swap(&V[d],&V[e],sizeof(char));
            e++;
            d--;
        }
        
    }
    j = d;

    /*Quick Sort*/
    QuickSortChar(V,i,j);
    QuickSortChar(V,j+1,f);
}

void HeapifyChar(char V[], int n, int i)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && V[esq] > V[maior])
        maior = esq;

    if (dir < n && V[dir] > V[maior])
        maior = dir;

    if (maior != i)
    {
        Swap(&V[i], &V[maior], sizeof(char));
        HeapifyChar(V, n, maior);
    }
}

void HeapSortChar(char V[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyChar(V, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        Swap(&V[0], &V[i], sizeof(char));
        HeapifyChar(V, i, 0);
    }
}

void Swap(Sort A, Sort B, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, A, size);
    memcpy(A, B, size);
    memcpy(B, temp, size);
    free(temp);
}
