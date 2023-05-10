#include "utilities.h"
#include <stdio.h>

double GrausParaRadianos(double Graus)
{
    double Radianos = Graus * (PI / 180.0);
    return Radianos;
}

double RadianosParaGraus(double Radianos)
{
    double Graus = Radianos * (180.0 / PI);
    return Graus;
}

bool VerificaIntervalo(float Inicio, float P, float Fim)
{
    return (Inicio <= P) && (P <= Fim);
}

bool VerificaPonto(float Axsup, float Px, float Axinf, float Aysup, float Py, float Ayinf)
{
    return (Axsup <= Px && Px <= Axinf && Ayinf <= Py && Py <= Aysup);
}

void BarraDeProgresso(int i, int total)
{
    // Calcula a porcentagem de conclusão
    float porcentagem = (float)i / total * 100;

    // Calcula a largura da barra
    int largura = 100;

    // Calcula o número de caracteres '=' na barra
    int num_igual = (int)(porcentagem / 100 * largura);

    // Imprime a barra
    printf("[");
    for (int j = 0; j < largura; j++)
    {
        if (j < num_igual)
        {
            printf("=");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %3.0f%%\r", porcentagem);

    // Limpa o buffer de saída para atualizar a barra
    fflush(stdout);
}