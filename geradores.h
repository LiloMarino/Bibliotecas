#ifndef GERADORES_H
#define GERADORES_H

/**
 * @file geradores.h
 * @brief Biblioteca de funções geradoras de dados aleatórios
 */

#include <stdio.h>

/**
 * @brief Gera uma string de caracteres aleatórios.
 * @param n Tamanho da string gerada.
 * @param string Vetor onde a string será armazenada.
 *
 */
void GerarString(int n, char string[]);

/**
 * @brief Gera um número aleatório do tipo float ou int.
 * @param min Valor mínimo que pode ser gerado.
 * @param max Valor máximo que pode ser gerado.
 * @param tipo Tipo do número gerado, pode ser "float" ou "int".
 * @return float Retorna o número gerado.
 */
float GerarNumero(int min, int max, char tipo[]);

/**
 * @brief Gera um vetor de inteiros aleatórios.
 * @param min Valor mínimo que pode ser gerado.
 * @param max Valor máximo que pode ser gerado.
 * @param v Vetor onde os valores serão armazenados.
 * @param n Tamanho do vetor gerado.
 *
 */
void GerarVetorInt(int min, int max, int v[], int n);

/**
 * @brief Escreve um vetor de inteiros na saída padrão.
 * @param V Vetor a ser impresso.
 * @param linha Tamanho do vetor.
 *
 */
void EscreveV(int V[], int linha);

/**
 * @brief Gera uma matriz de caracteres aleatórios e salva em um arquivo.
 * @param caps Tipo de caracteres a ser gerado, pode ser "Mm", "M" ou "m".
 * @param linha Número de linhas da matriz gerada.
 * @param coluna Número de colunas da matriz gerada.
 * @param nomearq Nome do arquivo onde a matriz será salva.
 *
 */
void GerarMatrizChar(char caps[], int linha, int coluna, char nomearq[]);

/**
 * @brief Gera uma matriz de inteiros aleatórios e salva em um arquivo.
 * @param min Valor mínimo que pode ser gerado.
 * @param max Valor máximo que pode ser gerado.
 * @param linha Número de linhas da matriz gerada.
 * @param coluna Número de colunas da matriz gerada.
 * @param nomearq Nome do arquivo onde a matriz será salva.
 *
 */
void GerarMatrizInt(int min, int max, int linha, int coluna, char nomearq[]);

/**
 * @brief Gera uma matriz esparsa de inteiros aleatórios e salva em um arquivo.
 * @param min Valor mínimo que pode ser gerado.
 * @param max Valor máximo que pode ser gerado.
 * @param linha Número de linhas da matriz gerada.
 * @param coluna Número de colunas da matriz gerada.
 * @param nomearq Nome do arquivo onde a matriz será salva.
 *
 */
void GerarMatrizEsparsa(int min, int max, int linha, int coluna, char nomearq[]);

/**
 * @brief Função que lê uma matriz de caracteres de um arquivo e imprime a matriz na tela.
 *
 * @param nomearq Nome do arquivo a ser lido.
 * @param linha Número de linhas da matriz.
 * @param coluna Número de colunas da matriz.
 *
 * @note A matriz é alocada dinamicamente.
 *
 */
void LerMatrizChar(char nomearq[], int linha, int coluna);

/**
 * @brief Função que lê uma matriz de inteiros de um arquivo e imprime a matriz na tela.
 *
 * @param nomearq Nome do arquivo a ser lido.
 * @param linha Número de linhas da matriz.
 * @param coluna Número de colunas da matriz.
 *
 * @note A matriz é alocada dinamicamente.
 *
 */
void LerMatrizInt(char nomearq[], int linha, int coluna);

/**
 * @brief Função que libera a memória alocada para uma matriz dinâmica.
 *
 * @param mat Matriz dinâmica a ser liberada.
 * @param linha Número de linhas da matriz.
 *
 * @note A matriz deve ter sido alocada dinamicamente usando malloc() ou calloc().
 *
 */
void LiberarMatriz(void **mat, int linha);

/**
 * @brief Cria um arquivo de log com o nome especificado.
 *
 * @param nome Nome base para o arquivo de log.
 * @return Ponteiro para o arquivo de log criado.
 *
 * @note A função adiciona a extensão ".txt" ao nome do arquivo e verifica se já existe
 * um arquivo com o mesmo nome. Se já existir, adiciona um número ao nome para evitar
 * sobrescrever o arquivo existente.
 *
 * @warning Se ocorrer um erro ao criar o arquivo, a função imprime uma mensagem de erro
 * na tela e retorna um ponteiro nulo.
 *
 */
FILE *CriaLog(char nome[]);

#endif