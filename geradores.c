#include "geradores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void GerarString(int n,char string[])
{
    int i;
    char *stringa;
    srand(time(NULL));
    stringa = malloc(n*sizeof(char));
    for (i = 0; i < n; i++)
    {
        stringa[i] = 65 + rand() % 26;
    }
    stringa[n-1] = '\0';
    for (i = 0; i < n; i++)
    {
        string[i] = stringa[i];
    }
    return;
}

float GerarNumero(int min, int max, char tipo[])
{
    float n;
    srand(time(NULL));
    n = (min + rand() % (max-min+1))/100.0;
    if (strcmp(tipo,"int")==0)
    {
        n = n*100;
        return (int) n;
    }
    return n;
}

void GerarVetorInt(int min, int max,int v[],int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        v[i] = min + rand() % (max-min+1);
    }
    return;
}

void EscreveV(int V[],int linha)
{
    int i;
    for (i = 0; i < linha; i++)
    {
        printf("%d ",V[i]);
    }
}

void GerarMatrizChar(char caps[],int linha,int coluna,char nomearq[])
{
    int i,j;
    char Mm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char M[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char m[] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    FILE*matriz;
    matriz = fopen(nomearq,"w");
    if(strcmp(caps,"Mm") == 0)
    {
        for(i = 0; i < linha; i++)
        {
            for(j = 0; j < coluna; j++)
            {
                fprintf(matriz,"%c ",Mm[rand() % strlen(Mm)]);
            }
            fprintf(matriz,"\n");
        }
    }
    else if (strcmp(caps,"M") == 0)
    {
        for(i = 0; i < linha; i++)
        {
            for(j = 0; j < coluna; j++)
            {
                fprintf(matriz,"%c ",M[rand() % strlen(M)]);
            }
            fprintf(matriz,"\n");
        }
    }
    else if (strcmp(caps,"m") == 0)
    {
        for(i = 0; i < linha; i++)
        {
            for(j = 0; j < coluna; j++)
            {
                fprintf(matriz,"%c ",m[rand() % strlen(m)]);
            }
            fprintf(matriz,"\n");
        }
    }
    fclose(matriz);
}

void GerarMatrizInt(int min,int max,int linha,int coluna,char nomearq[])
{
    int i,j;
    srand(time(NULL));
    FILE*matriz;
    matriz = fopen(nomearq,"w");
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            fprintf(matriz,"%d ",min + rand() % (max-min+1));
        }
        fprintf(matriz,"\n");
    }
    fclose(matriz);
}

void GerarMatrizEsparsa(int min,int max,int linha,int coluna,char nomearq[])
{
    int i,j;
    srand(time(NULL));
    FILE*matriz;
    matriz = fopen(nomearq,"w");
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            if(1+rand()%101 >= 70) //Chance de ser 0  = 70%
            {
                fprintf(matriz,"%d ",min + rand() % (max-min+1));
            }
            else
            {
                fprintf(matriz,"%d ",0);
            }
        }
        fprintf(matriz,"\n");
    }
    fclose(matriz);
}

void LerMatrizChar(char nomearq[],int linha,int coluna)
{
    int i,j;
    FILE*matriz;

    //Matriz Dinâmica
    char **mat;
    mat = malloc(linha*sizeof(char*)); //Vetor de ponteiros "Linhas"
    for (i = 0; i < linha; i++)
    {
        mat[i] = malloc(coluna*sizeof(char)); //Colunas ou Vetor da linha
    }

    //Leitura do arquivo
    matriz = fopen(nomearq,"r");
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            fscanf(matriz,"%c ",&mat[i][j]);
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
    fclose(matriz);
}

void LerMatrizInt(char nomearq[],int linha,int coluna)
{
    int i,j;
    FILE*matriz;

    //Matriz Dinâmica
    int **mat;
    mat = malloc(linha*sizeof(int*)); //Vetor de ponteiros "Linhas"
    for (i = 0; i < linha; i++)
    {
        mat[i] = malloc(coluna*sizeof(int)); //Colunas ou Vetor da linha
    }

    //Leitura do arquivo
    matriz = fopen(nomearq,"r");
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            fscanf(matriz,"%d ",&mat[i][j]);
            printf("%d ",mat[i][j]);
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
        free(mat[i]); //libera o vetor da linha
    }
    free(mat); //libera o vetor de ponteiros "linhas"
}