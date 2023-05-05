#include "geradores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


unsigned int seed;

void InicializaRand() {
    seed = (unsigned int) time(NULL);
    srand(seed);
}

void GerarString(int n, char string[])
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        string[i] = 65 + rand() % 26;
    }
    string[n - 1] = '\0';
    return;
}

float GerarNumeroFloat(int min, int max) {
    float n = (float) rand() / RAND_MAX;
    return min + n * (max - min);
}

int GerarNumeroInt(int min, int max) {
    int n = rand();
    return min + n % (max - min + 1);
}

void GerarVetorInt(int min, int max, int v[], int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        v[i] = min + rand() % (max - min + 1);
    }
    return;
}

void EscreveV(int V[], int linha)
{
    int i;
    for (i = 0; i < linha; i++)
    {
        printf("%d ", V[i]);
    }
}

void GerarMatrizChar(char caps[], int linha, int coluna, char nomearq[])
{
    int i, j;
    char Mm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char M[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char m[] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    FILE *matriz;
    matriz = fopen(nomearq, "w");
    if (strcmp(caps, "Mm") == 0)
    {
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                fprintf(matriz, "%c ", Mm[rand() % strlen(Mm)]);
            }
            fprintf(matriz, "\n");
        }
    }
    else if (strcmp(caps, "M") == 0)
    {
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                fprintf(matriz, "%c ", M[rand() % strlen(M)]);
            }
            fprintf(matriz, "\n");
        }
    }
    else if (strcmp(caps, "m") == 0)
    {
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                fprintf(matriz, "%c ", m[rand() % strlen(m)]);
            }
            fprintf(matriz, "\n");
        }
    }
    fclose(matriz);
}

void GerarMatrizInt(int min, int max, int linha, int coluna, char nomearq[])
{
    int i, j;
    srand(time(NULL));
    FILE *matriz;
    matriz = fopen(nomearq, "w");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            fprintf(matriz, "%d ", min + rand() % (max - min + 1));
        }
        fprintf(matriz, "\n");
    }
    fclose(matriz);
}

void GerarMatrizEsparsa(int min, int max, int linha, int coluna, char nomearq[])
{
    int i, j;
    srand(time(NULL));
    FILE *matriz;
    matriz = fopen(nomearq, "w");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            if (1 + rand() % 101 >= 70) // Chance de ser 0  = 70%
            {
                fprintf(matriz, "%d ", min + rand() % (max - min + 1));
            }
            else
            {
                fprintf(matriz, "%d ", 0);
            }
        }
        fprintf(matriz, "\n");
    }
    fclose(matriz);
}

void LerMatrizChar(char nomearq[], int linha, int coluna)
{
    int i, j;
    FILE *matriz;

    // Matriz Dinâmica
    char **mat;
    mat = malloc(linha * sizeof(char *)); // Vetor de ponteiros "Linhas"
    for (i = 0; i < linha; i++)
    {
        mat[i] = malloc(coluna * sizeof(char)); // Colunas ou Vetor da linha
    }

    // Leitura do arquivo
    matriz = fopen(nomearq, "r");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            fscanf(matriz, "%c ", &mat[i][j]);
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    fclose(matriz);
}

void LerMatrizInt(char nomearq[], int linha, int coluna)
{
    int i, j;
    FILE *matriz;

    // Matriz Dinâmica
    int **mat;
    mat = malloc(linha * sizeof(int *)); // Vetor de ponteiros "Linhas"
    for (i = 0; i < linha; i++)
    {
        mat[i] = malloc(coluna * sizeof(int)); // Colunas ou Vetor da linha
    }

    // Leitura do arquivo
    matriz = fopen(nomearq, "r");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            fscanf(matriz, "%d ", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    fclose(matriz);
}

void LiberarMatriz(void **mat, int linha)
{
    int i;
    for (i = 0; i < linha; i++)
    {
        free(mat[i]); // libera o vetor da linha
    }
    free(mat); // libera o vetor de ponteiros "linhas"
}

FILE *CriaLog(char nome[])
{
    // Aloca memória para o nome do arquivo
    char nomearq[strlen(nome) + 10];
    int n = 1;
    sprintf(nomearq, "%s.txt", nome);

    // Verifica se o arquivo já existe
    FILE *vrfy = fopen(nomearq, "r");
    while (vrfy != NULL)
    {
        fclose(vrfy);
        n++;
        sprintf(nomearq, "%s-%d.txt", nome, n);
        vrfy = fopen(nomearq, "r");
    }

    // Cria o arquivo com o nome gerado
    FILE *arq = fopen(nomearq, "w");
    if (arq == NULL)
    {
        printf("Erro ao criar arquivo de log!\n");
    }

    return arq;
}
