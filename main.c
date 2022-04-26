// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"
#include "utils.h"
#include "matdin.h"

pMoves newMove(pMoves move, int size, char **board, int x, int y){
    pMoves new, aux;
    char letter='X';

    new = malloc(sizeof(moves));
    if(new == NULL){
        printf("\n\tMalloc failed");
        return move;
    }

    setPos(board, x, y, 'X');

    new->letter=letter;
    new->x=x;
    new->y=y;
    new->next=NULL;

    if(move == NULL)
        move = new;
    else{
        aux = move;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
    return move;
}

int main() {
    Players players;
    pMoves moves=NULL;
    char **board;
    int x,y;

    //Cria os dois jogadores (Humano e Humano/Computador)
    start(&players);

    //Sortear a probabilidade de quem começa primeiro (50% para cada)
    initRandom();
    if(probEvento((float)0.5))
        printf("\n\n\tThe player %s starts\n\n\n", players.player1);
    else
        printf("\n\n\tThe player %s starts\n\n", players.player2);

    /*************************/
    board = newBoard(SIZE);
    showBoard(board,SIZE);
    do{
        scanf("%d %d",&x,&y);
        newMove(moves,SIZE,board,x,y);
        showBoard(board,SIZE);
    } while (1);

    freeBoard(board,SIZE);

    return 0;
}