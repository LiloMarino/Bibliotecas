#ifndef EFFICIENCY_H
#define EFFICIENCY_H

#include <sys/resource.h>

/**
 * @brief Inicia o contador de tempo.
 * 
 */
void iniciarTempo();

/**
 * @brief Finaliza o contador de tempo, calcula e exibe na tela o tempo total em segundos.
 * 
 */
void finalizarTempo();

/**
 * @brief Retorna a quantidade de memória utilizada pelo programa em bytes.
 * 
 * @return long long A quantidade de memória utilizada pelo programa em bytes.
 */
long long calcularMemoriaUtilizada();

/**
 * @brief Retorna a quantidade de CPU utilizada pelo programa em segundos.
 * 
 * @return double A quantidade de CPU utilizada pelo programa em segundos.
 */
double calcularTempoCPU();

/**
 * @brief Conta o número de operações básicas executadas por um trecho de código.
 * 
 * Esta função conta o número de operações básicas (adições, subtrações, multiplicações, divisões, 
 * comparações e atribuições) que são executadas por um trecho de código. O número de operações é 
 * retornado como um long long.
 * 
 * @param f A função a ser avaliada.
 * @return long long O número de operações básicas executadas pela função.
 */
long long contarOperacoesBasicas(void (*f)());

#endif
