// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef STRUCTS_H
#define STRUCTS_H

#define BOARD_SIZE 11

typedef struct player{
    char player1[30], player2[30];
}Players;

typedef struct allMoves moves, *pMoves;
struct allMoves {
    char letter;
    int x,y;
    pMoves next;
};

#endif /* STRUCTS_H */