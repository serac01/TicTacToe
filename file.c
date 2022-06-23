// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "file.h"

pMoves readInterruptedGame(pMoves moves, char **board){
    int moveNumber,bigX,bigY,x,y, t1,t2;
    char name[50];

    FILE* d = fopen("jogo.bin", "rb");
    if (d == NULL)
        return NULL;

    fscanf(d, "%d %d %[^\n]%*c\n", &t1, &t2, name);
    fscanf(d, "%d %d %[^\n]%*c\n", &t1, &t2, name);
    while (!feof (d)){
        fscanf(d, "%d %d %d %d %d\n", &moveNumber, &bigX, &bigY, &x, &y);
        moves = newMove(moves,board,x,y,bigX,bigY);
    }
    fclose (d);
    return moves;
}

pPlayers recoverPlayers(pPlayers player){
    int whoIsFirst1, whoIsFirst2, isComputer1, isComputer2;
    char name1[50], name2[50];

    player = malloc(2*sizeof(Players));
    if(player==NULL)
        return NULL;

    FILE* d = fopen("jogo.bin", "rb");
    if (d == NULL)
        return NULL;

    fscanf(d, "%d %d %[^\n]%*c\n", &whoIsFirst1, &isComputer1, name1);
    fscanf(d, "%d %d %[^\n]%*c\n", &whoIsFirst2, &isComputer2, name2);
    name1[strlen(name1)-1]='\0';
    name2[strlen(name2)-1]='\0';

    strcpy(player->name,name1);
    strcpy((player+1)->name,name2);
    player->number=whoIsFirst1;
    (player+1)->number=whoIsFirst2;
    player->isComputer=isComputer1;
    (player+1)->isComputer=isComputer2;

    fclose (d);

    return player;
}

void saveInterruptedGame(pMoves moves, pPlayers players){
    FILE *d = fopen("jogo.bin", "wb");
    if (d == NULL)
        return;
    fprintf(d, "%d %d %s\n", players->number, players->isComputer, players->name);
    fprintf(d, "%d %d %s\n", (players+1)->number, (players+1)->isComputer, (players+1)->name);
    while (moves != NULL) {
        fprintf(d, "%d %d %d %d %d\n", moves->moveNumber, moves->bigX, moves->bigY, moves->x, moves->y);
        moves = moves->next;
    }
    fclose(d);
}

void saveFinishedGame(pMoves moves, pPlayers players, char *filename){
    FILE *d = fopen(filename, "wb");
    if (d == NULL)
        return;
    fprintf(d, "Play in %d place, is computer: %d and the name: %s\n", players->number, players->isComputer, players->name);
    fprintf(d, "Play in %d place, is computer: %d and the name: %s\n", (players+1)->number, (players+1)->isComputer, (players+1)->name);
    while (moves != NULL) {
        fprintf(d, "Move number: %d, big board row: %d, big board column: %d, small board row: %d, small board column: %d\n", moves->moveNumber, moves->bigX, moves->bigY, moves->x, moves->y);
        moves = moves->next;
    }
    fclose(d);
}