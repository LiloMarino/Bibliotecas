#include "geradores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

unsigned int seed;

void InicializaRand()
{
    seed = (unsigned int)time(NULL);
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

float GerarNumeroFloat(int min, int max)
{
    float n = (float)rand() / RAND_MAX;
    return min + n * (max - min);
}

double GerarNumeroDouble(double min, double max)
{
    double scale = (double)rand() / RAND_MAX; // Obter um número aleatório no intervalo [0, 1]
    return min + scale * (max - min);         // Ajustar para o intervalo desejado
}

int GerarNumeroInt(int min, int max)
{
    int n = rand();
    return min + n % (max - min + 1);
}

void GerarVetorInt(int min, int max, int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        v[i] = min + (int)((float)rand() / RAND_MAX * (max - min + 1));
    }
}

void ImprimeVetorChar(const char vetor_char[], const int nc)
{
    // Imprime o vetor char
    for (int i = 0; i < nc; i++)
    {
        printf("%c ", vetor_char[i]);
    }
    printf("\n");
}

void ImprimeVetorInt(const int vetor_int[], const int ni)
{
    // Imprime o vetor int
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");
}

void GerarMatrizChar(char caps[], int linha, int coluna, char nomearq[])
{
    int i, j;
    char Mm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char M[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char m[] = "abcdefghijklmnopqrstuvwxyz";
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
    FILE *matriz;
    matriz = fopen(nomearq, "w");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            int valor = min + rand() % (max - min + 1);
            fprintf(matriz, "%d ", valor);
        }
        fprintf(matriz, "\n");
    }
    fclose(matriz);
}

void GerarMatrizEsparsa(int min, int max, int linha, int coluna, char nomearq[])
{
    int i, j;
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

char **LerMatrizChar(char nomearq[], int linha, int coluna)
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
    return mat;
}

int **LerMatrizInt(char nomearq[], int linha, int coluna)
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
    return mat;
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

FILE *CriaLog(char nome[], char ext[])
{
    // Aloca memória para o nome do arquivo
    char nomearq[strlen(nome) + 10 + strlen(ext)];
    int n = 1;
    sprintf(nomearq, "%s.%s", nome, ext);

    // Verifica se o arquivo já existe
    FILE *vrfy = fopen(nomearq, "r");
    while (vrfy != NULL)
    {
        fclose(vrfy);
        n++;
        sprintf(nomearq, "%s_%d.%s", nome, n, ext);
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

char *CriaLogNome(char nome[], char ext[], FILE **arq)
{
    // Aloca memória para o nome do arquivo
    char nomearq[strlen(nome) + 10 + strlen(ext)];
    int n = 1;
    sprintf(nomearq, "%s.%s", nome, ext);

    // Verifica se o arquivo já existe
    FILE *vrfy = fopen(nomearq, "r");
    while (vrfy != NULL)
    {
        fclose(vrfy);
        n++;
        sprintf(nomearq, "%s_%d.%s", nome, n, ext);
        vrfy = fopen(nomearq, "r");
    }

    // Cria o arquivo com o nome gerado
    *arq = fopen(nomearq, "w");
    if (arq == NULL)
    {
        printf("Erro ao criar arquivo de log!\n");
    }
    n--;
    if (n == 1)
    {
        sprintf(nomearq, "%s", nome);
    }
    else
    {

        sprintf(nomearq, "%s_%d", nome, n);
    }
    return strdup(nomearq);
}

void CriaPasta(const char *diretorio, const char *nomePasta)
{
    char caminhoCompleto[strlen(diretorio) + strlen(nomePasta) + 10];

    // Copia o diretório para o caminho completo
    strncpy(caminhoCompleto, diretorio, sizeof(caminhoCompleto) - 1);
    caminhoCompleto[sizeof(caminhoCompleto) - 1] = '\0';

    // Concatena o nome da pasta ao caminho completo
    strcat(caminhoCompleto, "/");
    strcat(caminhoCompleto, nomePasta);

    // Verifica se a pasta já existe
    DIR *dir = opendir(caminhoCompleto);
    if (dir != NULL)
    {
        printf("A pasta já existe.\n");
        closedir(dir);
        return;
    }

    // Cria a pasta com as permissões 0777
    int resultado = mkdir(caminhoCompleto, 0777);

    if (resultado == 0)
    {
        printf("Pasta criada com sucesso.\n");
    }
    else
    {
        printf("Erro ao criar a pasta.\n");
    }
}

void DeleteDuplicates(char nome[], char ext[])
{
    // Cria o nome base do arquivo
    char nomeBase[strlen(nome) + strlen(ext) + 2];
    sprintf(nomeBase, "%s.%s", nome, ext);

    // Verifica se o arquivo original existe
    FILE *original = fopen(nomeBase, "r");
    if (original == NULL)
    {
        printf("Arquivo original não encontrado.\n");
        return;
    }
    fclose(original);

    // Loop para deletar arquivos duplicados
    int n = 2;
    char nomeArq[strlen(nome) + strlen(ext) + 10];
    sprintf(nomeArq, "%s_%d.%s", nome, n, ext);
    while (remove(nomeArq) == 0)
    {
        n++;
        sprintf(nomeArq, "%s_%d.%s", nome, n, ext);
    }

    printf("Arquivos duplicados deletados com sucesso.\n");
}
