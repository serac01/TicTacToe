// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"
#include "linkedList.h"

/*void showMeTheList(pMoves list){
    printf("\n\n\n");
    while(list->next!=NULL){
        printf("\tX:%d Y:%d Number:%d\n",list->x,list->y,list->moveNumber);
        list=list->next;
    }
    printf("\tX:%d Y:%d Number:%d\n",list->x,list->y,list->moveNumber);
}*/

int main() {
    Players players[2];
    pMoves moves=NULL;
    char **board;
    int x,y,bigX,bigY,i=0;

    //Chamado apenas uma vez para usar o relógio interno do computador para controlar a escolha de números aleatórios e não repetidos com uma nova execução.
    initRandom();

    //Cria os dois jogadores (Humano e Humano/Computador)
    start(players);

    //Cria um tabuleiro com o tamanho redimensionar
    board = newBoard(SIZE);

    do{
        getLastMove(moves,&bigX,&bigY);
        askForCoordinates(&x,&y,players);
        moves=newMove(moves,board,x,y,SIZE*bigX+bigX+x,SIZE*bigY+bigY+y);
        showBoard(board,SIZE);
    }while(i<10);

    freeBoard(board,SIZE);

    return 0;
}