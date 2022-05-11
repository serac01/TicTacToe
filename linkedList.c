// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "linkedList.h"

pMoves newMove(pMoves move, char **board, int x, int y, int realX, int realY){
    pMoves new, aux=move;

    //Alocar memoria para conseguir guardar mais uma jogada
    new = malloc(sizeof(moves));
    if(new == NULL){
        printf("\n\t[ERROR]: Couldn't allocate memory (Malloc Failed)");
        return move;
    }

    //Percorre uma lista auxiliar igual a que recebe e põe-na na última posição para receber o número da última jogada e mais tarde põe o novo elemento nela
    if(move!=NULL){
        while (aux->next != NULL)
            aux = aux->next;
        new->moveNumber = (aux->moveNumber) + 1;
    }

    new->x=x;
    new->y=y;
    new->next=NULL;

    //Coloca na matriz a jogada que o utilizador pediu, consoante a ordem de jogada
    if(move!=NULL && new->moveNumber % 2 == 0)
        setPos(board, realX, realY, 'X');
    else
        setPos(board, realX, realY, '0');

    //Se ainda não foi feita nenhuma jogada adiciona a nova informação na 1ª posição, caso contrario guarda-a na ultima posição da lista
    if(move == NULL) {
        new->moveNumber=1;
        move = new;
    }else
        aux->next = new;

    return move;
}

void getLastMove(pMoves move, int *x, int *y, int *lastMove){
    //Se existir algum conteúdo na lista, percorre-a ate a última posição e guarda os últimos valores de x e y inseridos, se não escreve a primeira posição
    if(move!=NULL){
        //Vai ate a ulti
        while (move->next != NULL)
            move = move->next;
        *x = move->x;
        *y = move->y;
        *lastMove = move->moveNumber;
    }else
        *x=*y=*lastMove=0;
}

/*void showMeTheList(pMoves list){
    printf("\n\n\n");
    while(list->next!=NULL){
        printf("\tX:%d Y:%d Number:%d\n",list->x,list->y,list->moveNumber);
        list=list->next;
    }
    printf("\tX:%d Y:%d Number:%d\n",list->x,list->y,list->moveNumber);
}*/