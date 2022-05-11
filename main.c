// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"
#include "linkedList.h"

int main() {
    Players players[2];
    pMoves moves=NULL;
    char **board, **auxBoard;
    int x,y,bigX,bigY,quit,lastMove=0;

    //Chamado apenas uma vez para usar o relógio interno do computador para controlar a escolha de números aleatórios e não repeti-los com uma nova execução.
    initRandom();

    //Cria os dois jogadores (Humano e Humano/Computador)
    start(players);

    //Cria um tabuleiro com o tamanho fixo, se for impossível da (erro)
    auxBoard = newBoard(SIZE);
    if(auxBoard==NULL) {
        printf("\n\t[ERROR]: Couldn't allocate memory (Malloc Failed)");
        return 0;
    }
    else
        board=auxBoard;

    do{
        //Recebe o ultimo movimento
        getLastMove(moves,&bigX,&bigY,&lastMove);
        //Verifica se o mini tabuleiro anterior está ganho ou empatado e se tiver muda as coordenadas para um mini tabuleiro que esteja disponível
        generateNewMove(board,&bigX,&bigY);
        //Pede e verifica as coordenadas
        askForCoordinates(&x,&y,players,board,bigX,bigY,lastMove);
        //Atualiza a lista e o tabuleiro com a nova jogada
        moves = newMove(moves,board,x,y,SIZE*bigX+bigX+x,SIZE*bigY+bigY+y);
        //Mostra o tabuleiro
        showBoard(board,SIZE);
        //Se for detetado o fim, termina o jogo
        quit=confirmIfWon(board);
    }while(quit==0);

    freeBoard(board,SIZE);

    return 0;
}