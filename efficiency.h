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
 */
void calcularMemoriaUtilizada();

/**
 * @brief Retorna a quantidade de CPU utilizada pelo programa em segundos.
 *
 */
void calcularTempoCPU();

#endif
