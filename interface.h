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
pPlayers start(pPlayers players);

//Pede as coordenadas ao utilizador e faz a validação, nos final da função os ponteiros irão ter as coordenadas já corrigidas
void askForCoordinates(int *x, int *y, pPlayers players, char **board, int bigX, int bigY, int lastMove);

//Mostra a matriz de memoria dinâmica de caracteres
void showBoard(char **p, int size);

//Gera aleatoriamente duas coordenadas para o início de um mini tabuleiro, caso o que foi enviado já esteja ganho ou empatado
void generateNewMove(char **p, int *x, int *y);

//Apresentar o menu de jogadas possíveis
int menu(pPlayers players, int lastMove);

//Apresentar a quantidade de jogadas que o utilizador quer (max: 10)
void showNPreviousPlays(pMoves moves, pPlayers players);

int wantToRecoverGame();

void showTheWinnerAndAskFile(pPlayers players, int lastMove, char *filename, int itsATie);

#endif /*INTERFACE_H*/