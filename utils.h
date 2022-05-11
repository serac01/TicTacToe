// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <time.h>

//Inicializa o gerador de números aleatórios. Esta função apenas deve ser chamada uma vez no início da execução do programa
void initRandom();

//Devolve um valor inteiro aleatório distribuído uniformemente entre [a,b]
int intUniformRnd(int a, int b);

// Devolve o valor 1 com probabilidade prob. Caso contrario, devolve 0
int probEvento(float prob);

#endif /* UTILS_H */
