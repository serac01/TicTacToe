// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

//Recupera a lista baseado num ficheiro onde está guardado um jogo interrompido
pMoves readInterruptedGame(pMoves moves, char **board);

//Recupera os jogadores baseado num ficheiro onde está guardado um jogo interrompido
pPlayers recoverPlayers(pPlayers player);

//Guarda num ficheiro as informações necessarias para poder retomar o jogo
void saveInterruptedGame(pMoves moves, pPlayers players);

void saveFinishedGame(pMoves moves, pPlayers players, char *filename);

#endif /*FILE_H*/