// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"
#include "utils.h"
#include "board.h"
#include "linkedList.h"

void showMeTheList(pMoves list){
    printf("\n\n\n");
    while(list->next!=NULL){
        printf("\tX:%d Y:%d Number:%d\n",list->x,list->y,list->moveNumber);
        list=list->next;
    }
    printf("\tX:%d Y:%d Number:%d\n",list->x,list->y,list->moveNumber);
}

int main() {
    Players players[2];
    pMoves moves=NULL;
    char **board;
    int x,y;

    //
    initRandom();

    //Cria os dois jogadores (Humano e Humano/Computador)
    start(players);

    //Cria um tabuleiro com o tamanho redimensionar
    board = newBoard(SIZE);

    do{
        getLastMove(moves,&x,&y);
        printf("\n\tCordenadas anterior: %d %d",x,y);
        askForCoordinates(&x,&y,players);
        moves=newMove(moves,board,x,y);
        //showBoard(board,SIZE);
        showMeTheList(moves);
    }while(1);

    freeBoard(board,SIZE);

    return 0;
}