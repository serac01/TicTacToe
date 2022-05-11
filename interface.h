// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef INTERFACE_H
#define INTERFACE_H

#include <string.h>
#include <string.h>
#include "structs.h"
#include "utils.h"
#include "board.h"

//Pergunta o nome do utilizador e se vai jogar contra um amigo ou contra o computador, caso seja o amigo pede o nome. No final sorteia um dos dois para começar
void start(Players players[]);

//Pede as coordenadas ao utilizador e faz a validação, nos final da função os ponteiros irão ter as coordenadas já corrigidas
void askForCoordinates(int *x, int *y, Players players[], char **board, int bigX, int bigY, int lastMove);

//Mostra a matriz de memoria dinâmica de caracteres
void showBoard(char **p, int size);

//Gera aleatoriamente duas coordenadas para o início de um mini tabuleiro, caso o que foi enviado já esteja ganho ou empatado
void generateNewMove(char **p, int *x, int *y);

#endif /*INTERFACE_H*/