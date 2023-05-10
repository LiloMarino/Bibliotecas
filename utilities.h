#ifndef UTILITIES_H
#define UTILITIES_H

#ifndef PI
#define PI 3.14159265358979323846
#endif

/**
 * @brief Recebe um valor em Graus e o retorna em Radianos
 * @param Graus Ângulo em Graus
 * @return Ângulo em Radianos
 */
double GrausParaRadianos(double Graus);

/**
 * @brief Recebe um valor em Radianos e o retorna em Graus
 * @param Radianos Ângulo em Radianos
 * @return Ângulo em Graus
 */
double RadianosParaGraus(double Radianos);

/**
 * @brief Verifica se um ponto está num determinado intervalo delimitado por 2 valores
 * @param Inicio Valor inicial
 * @param P Valor a ser verificado a pertencente do intervalo
 * @param Fim Valor final
 * @return Retorna verdadeiro se pertencer e falso caso não pertença
 */
bool VerificaIntervalo(float Inicio, float P, float Fim);

/**
 * @brief Verifica se um ponto pertence ou não a uma Área Retangular definida por Asup e Ainf
 * @param Axsup Coordenada x da Aresta Superior Esquerda
 * @param Px Coordenada x do ponto P
 * @param Axinf Coordenada x da Aresta Inferior Direita
 * @param Aysup Coordenada y da Aresta Superior Esquerda
 * @param Py Coordenada y do ponto P
 * @param Ayinf Coordenada y da Aresta Inferior Direita
 * @return Retorna verdadeiro se o ponto pertence a área e falso caso não pertença
 */
bool VerificaPonto(float Axsup, float Px, float Axinf, float Aysup, float Py, float Ayinf);

/**
 * @brief Mostra uma barra de progresso baseada na % obtida pela divisão i/total
 * @param i Quantidade já feita
 * @param total Quantidade total a ser feita
 */
void BarraDeProgresso(int i, int total);

#endif