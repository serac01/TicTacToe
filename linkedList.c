// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#include "linkedList.h"

pMoves newMove(pMoves move, char **board, int x, int y, int realX, int realY){
    pMoves new, aux=move;

    //Alocar memoria para conseguir guardar mais uma jogada
    new = malloc(sizeof(moves));
    if(new == NULL){
        printf("\n\t[ERROR]: Couldn't allocate memory (Malloc Failed)");
        return move;
    }

    //Percorre uma lista auxiliar igual a que recebe e põe-na na última posição para receber o numero da última jogada e mais tarde põe o novo elemento nela
    if(move!=NULL){
        while (aux->next != NULL)
            aux = aux->next;
        new->moveNumber = (aux->moveNumber) + 1;
    }

    new->x=x;
    new->y=y;
    new->next=NULL;

    //Coloca na matriz a jogada que o utilizador pediu
    if(move!=NULL && new->moveNumber % 2 == 0)
        setPos(board, realX, realY, 'X');
    else
        setPos(board, realX, realY, '0');

    //Se ainda não foi feita nenhuma jogada
    if(move == NULL) {
        new->moveNumber=1;
        move = new;
    }else
        aux->next = new;

    return move;
}

void getLastMove(pMoves move, int *x, int *y){
    if(move!=NULL){
        while (move->next != NULL)
            move = move->next;
        *x = move->x;
        *y = move->y;
    }else
        *x=*y=0;

}