#include "path.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "learquivo.h"

void splitPath(const char *fullPath, char **path, char **nomeArq, char **extArq)
{
    if (*path != NULL)
    {
        free(*path);
        *path = NULL;
    }
    if (*nomeArq != NULL)
    {
        free(*nomeArq);
        *nomeArq = NULL;
    }
    if (*extArq != NULL)
    {
        free(*extArq);
        *extArq = NULL;
    }
    char *ultimabarra = strrchr(fullPath, '/');
    if (ultimabarra == NULL)
    {
        *path = my_strdup("");
    }
    else
    {
        int tamanhoPath = strlen(fullPath) - strlen(ultimabarra) + 1;
        *path = malloc((tamanhoPath + 1) * sizeof(char));
        strncpy(*path, fullPath, tamanhoPath);
        (*path)[tamanhoPath] = '\0';
    }
    char *ultimoponto = strrchr(fullPath, '.');
    if (ultimoponto == NULL)
    {
        *extArq = my_strdup("");
        if (ultimabarra == NULL)
        {
            *nomeArq = malloc((strlen(fullPath) + 1) * sizeof(char));
            strcpy(*nomeArq, fullPath);
        }
        else
        {
            *nomeArq = malloc((strlen(ultimabarra) + 1) * sizeof(char));
            strncpy(*nomeArq, ultimabarra + 1, strlen(fullPath) - (ultimabarra - fullPath) - 1);
            (*nomeArq)[strlen(ultimabarra) - 1] = '\0';
        }
    }
    else
    {
        if (ultimabarra == NULL)
        {
            *nomeArq = malloc((strlen(fullPath) - strlen(ultimoponto) + 1) * sizeof(char));
            strncpy(*nomeArq, fullPath, strlen(fullPath) - strlen(ultimoponto));
            (*nomeArq)[strlen(fullPath) - strlen(ultimoponto)] = '\0';
            *extArq = malloc((strlen(ultimoponto) + 1) * sizeof(char));
            strcpy(*extArq, ultimoponto);
        }
        else
        {
            *nomeArq = malloc((strlen(ultimabarra) - strlen(ultimoponto) + 1) * sizeof(char));
            strncpy(*nomeArq, ultimabarra + 1, strlen(ultimabarra) - strlen(ultimoponto));
            (*nomeArq)[strlen(ultimoponto) + 1] = '\0';
            *extArq = malloc((strlen(ultimoponto) + 2) * sizeof(char));
            strcpy(*extArq, ultimoponto);
        }
    }
}

void joinFilePath(const char *path, const char *fileName, char **fullPath)
{
    if (path == NULL || fileName == NULL)
    {
        return;
    }

    if (strcmp("", path) != 0)
    {
        if (path[strlen(path) - 1] == '/')
        {
            *fullPath = malloc((strlen(path) + strlen(fileName) + 1) * sizeof(char));
            sprintf(*fullPath, "%s%s", path, fileName);
        }
        else
        {
            *fullPath = malloc((strlen(path) + strlen(fileName) + 2) * sizeof(char));
            sprintf(*fullPath, "%s/%s", path, fileName);
        }
    }
    else
    {
        *fullPath = malloc((strlen(fileName) + 1) * sizeof(char));
        sprintf(*fullPath, "%s", fileName);
    }
}

void joinAll(char *path, char *fileName, char *ext, char **fullPath)
{
    if (path == NULL || ext == NULL || fileName == NULL)
    {
        return;
    }
    if (*fullPath != NULL)
    {
        free(*fullPath);
        *fullPath = NULL;
    }
    if (strcmp("", path) != 0)
    {
        if (path[strlen(path) - 1] == '/')
        {
            *fullPath = malloc((strlen(path) + strlen(fileName) + strlen(ext) + 1) * sizeof(char));
            sprintf(*fullPath, "%s%s%s", path, fileName, ext);
        }
        else
        {
            *fullPath = malloc((strlen(path) + strlen(fileName) + strlen(ext) + 2) * sizeof(char));
            sprintf(*fullPath, "%s/%s%s", path, fileName, ext);
        }
    }
    else
    {
        *fullPath = malloc((strlen(fileName) + strlen(ext) + 1) * sizeof(char));
        sprintf(*fullPath, "%s%s", fileName, ext);
    }
}

void getFileName(char *fullPath, char **fileName)
{
    if (fullPath == NULL)
    {
        return;
    }
    if (*fileName != NULL)
    {
        free(*fileName);
        *fileName = NULL;
    }
    char *ultimabarra = strrchr(fullPath, '/');
    if (ultimabarra == NULL)
    {
        *fileName = my_strdup(fullPath);
    }
    else
    {
        *fileName = my_strdup(ultimabarra + 1);
    }
}

void getPath(char *fullPath, char **path)
{
    if (fullPath == NULL)
    {
        return;
    }
    if (*path != NULL)
    {
        free(*path);
        *path = NULL;
    }
    char *ultimabarra = strrchr(fullPath, '/');
    if (ultimabarra == NULL)
    {
        *path = my_strdup("");
    }
    else
    {
        int pathLength = ultimabarra - fullPath;
        *path = malloc((pathLength + 1) * sizeof(char));
        strncpy(*path, fullPath, pathLength);
        (*path)[pathLength] = '\0';
    }
}

void normalizePath(char *path, char **normPath)
{
    if (path == NULL)
    {
        return;
    }
    if (*normPath != NULL)
    {
        free(*normPath);
        *normPath = NULL;
    }
    int pathLength = strlen(path);
    if (path[pathLength - 1] == '/')
    {
        pathLength--;
    }
    *normPath = malloc((pathLength + 1) * sizeof(char));
    strncpy(*normPath, path, pathLength);
    (*normPath)[pathLength] = '\0';
}

char *RemoveExtensao(const char *fileName)
{
    char *fileName1 = NULL, *path = NULL, *ext = NULL;

    splitPath(fileName, &path, &fileName1, &ext);
    free(path);
    free(ext);
    return fileName1;
}

char *ConcatenaNomes(const char *NomeGeo, const char *NomeQry)
{
    if (NomeQry != NULL)
    {
        char *nome = calloc(strlen(NomeGeo) + strlen(NomeQry) + 1, sizeof(char));
        strcpy(nome, NomeGeo);
        strtok(nome, ".");
        strcat(nome, "-");
        char *Qry = calloc(strlen(NomeQry) + 1, sizeof(char));
        strcpy(Qry, NomeQry);
        strtok(Qry, ".");
        strcat(nome, Qry);
        free(Qry);
        return nome;
    }
    else
    {
        return NULL;
    }
}

void ArgumentosDeComando(char **PathInput, char **PathOutput, char **nomeGeo, char **nomeQry, char **numSetor, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp("-e", argv[i]) == 0 && i + 1 < argc)
        {
            *PathInput = argv[++i];
        }
        else if (strcmp("-f", argv[i]) == 0 && i + 1 < argc)
        {
            *nomeGeo = argv[++i];
        }
        else if (strcmp("-o", argv[i]) == 0 && i + 1 < argc)
        {
            *PathOutput = argv[++i];
        }
        else if (strcmp("-q", argv[i]) == 0 && i + 1 < argc)
        {
            *nomeQry = argv[++i];
        }
        else if (strcmp("-ns", argv[i]) == 0 && i + 1 < argc)
        {
            *numSetor = argv[++i];
        }
    }
}
