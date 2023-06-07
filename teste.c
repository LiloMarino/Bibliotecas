#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

int main()
{
    // Teste para splitPath
    char *fullPath = "aaa/bbb/ccc.txt";
    char *path = NULL;
    char *nomeArq = NULL;
    char *extArq = NULL;
    splitPath(fullPath, &path, &nomeArq, &extArq);
    printf("fullPath: %s\n", fullPath);
    printf("path: %s\n", path);
    printf("nomeArq: %s\n", nomeArq);
    printf("extArq: %s\n", extArq);
    printf("\n");

    // Teste para joinFilePath
    char *path1 = "aaa/bbb";
    char *fileName1 = "c.txt";
    char *fullPath1 = NULL;
    joinFilePath(path1, fileName1, &fullPath1);
    printf("path: %s\n", path1);
    printf("fileName: %s\n", fileName1);
    printf("fullPath: %s\n", fullPath1);
    printf("\n");

    // Teste para joinAll
    char *path2 = "aaa/bbb";
    char *fileName2 = "ccc";
    char *ext2 = ".txt";
    char *fullPath2 = NULL;
    joinAll(path2, fileName2, ext2, &fullPath2);
    printf("path: %s\n", path2);
    printf("fileName: %s\n", fileName2);
    printf("ext: %s\n", ext2);
    printf("fullPath: %s\n", fullPath2);
    printf("\n");

    // Teste para getFileName
    char *fullPath3 = "aaa/bb/cc.txt";
    char *fileName3 = NULL;
    getFileName(fullPath3, &fileName3);
    printf("fullPath: %s\n", fullPath3);
    printf("fileName: %s\n", fileName3);
    printf("\n");

    // Teste para getPath
    char *fullPath4 = "aaa/bbb/ccc.txt";
    char *path4 = NULL;
    getPath(fullPath4, &path4);
    printf("fullPath: %s\n", fullPath4);
    printf("path: %s\n", path4);
    printf("\n");

    // Teste para normalizePath
    char *path5 = "aa/bb/cc/";
    char *normPath = NULL;
    normalizePath(path5, &normPath);
    printf("path: %s\n", path5);
    printf("normalized path: %s\n", normPath);
    printf("\n");

    // Liberar memória alocada
    free(path);
    free(nomeArq);
    free(extArq);
    free(fullPath1);
    free(fullPath2);
    free(fileName3);
    free(path4);
    free(normPath);

    return 0;
}
