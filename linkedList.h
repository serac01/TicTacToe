// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "board.h"
#include "structs.h"

//Guarda numa lista ligada a última jogada
pMoves newMove(pMoves move, char **board, int x, int y, int realX, int realY);

void getLastMove(pMoves move, int *x, int *y);

#endif