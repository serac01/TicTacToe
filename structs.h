// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>
#include <stdio.h>

//Estrutura do jogador
typedef struct player Players, *pPlayers;
struct player{
    char name[30];
    int number;
    int isComputer;
};

//Estrutura da jogada, usado nas listas ligadas
typedef struct allMoves moves, *pMoves;
struct allMoves {
    int x,y,bigX,bigY,moveNumber;
    pMoves next;
};

#endif /* STRUCTS_H */