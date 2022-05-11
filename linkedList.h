// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "board.h"
#include "structs.h"

//Guarda numa lista ligada a última jogada
pMoves newMove(pMoves move, char **board, int x, int y, int realX, int realY);

//Guarda em x e y os valores introduzidos na última jogada
void getLastMove(pMoves move, int *x, int *y, int *lastMove);

#endif