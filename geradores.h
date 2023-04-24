/**
 * @file geradores.h
 * @brief Biblioteca de funções geradoras de dados aleatórios
 */

#ifndef GERADORES_H
#define GERADORES_H

/**
 * @brief Gera uma string de caracteres aleatórios.
 * @param n Tamanho da string gerada.
 * @param string Vetor onde a string será armazenada.
 * @return void
 */
void GerarString(int n,char string[]);

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
 * @return void
 */
void GerarVetorInt(int min, int max,int v[],int n);

/**
 * @brief Escreve um vetor de inteiros na saída padrão.
 * @param V Vetor a ser impresso.
 * @param linha Tamanho do vetor.
 * @return void
 */
void EscreveV(int V[],int linha);

/**
 * @brief Gera uma matriz de caracteres aleatórios e salva em um arquivo.
 * @param caps Tipo de caracteres a ser gerado, pode ser "Mm", "M" ou "m".
 * @param linha Número de linhas da matriz gerada.
 * @param coluna Número de colunas da matriz gerada.
 * @param nomearq Nome do arquivo onde a matriz será salva.
 * @return void
 */
void GerarMatrizChar(char caps[],int linha,int coluna,char nomearq[]);

/**
 * @brief Gera uma matriz de inteiros aleatórios e salva em um arquivo.
 * @param min Valor mínimo que pode ser gerado.
 * @param max Valor máximo que pode ser gerado.
 * @param linha Número de linhas da matriz gerada.
 * @param coluna Número de colunas da matriz gerada.
 * @param nomearq Nome do arquivo onde a matriz será salva.
 * @return void
 */
void GerarMatrizInt(int min,int max,int linha,int coluna,char nomearq[]);

/**
 * @brief Gera uma matriz esparsa de inteiros aleatórios e salva em um arquivo.
 * @param min Valor mínimo que pode ser gerado.
 * @param max Valor máximo que pode ser gerado.
 * @param linha Número de linhas da matriz gerada.
 * @param coluna Número de colunas da matriz gerada.
 * @param nomearq Nome do arquivo onde a matriz será salva.
 * @return void
 */
void GerarMatrizEsparsa(int min,int max,int linha,int coluna,char nomearq[]);

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
void LerMatrizChar(char nomearq[],int linha,int coluna);

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
void LerMatrizInt(char nomearq[],int linha,int coluna);

#endif