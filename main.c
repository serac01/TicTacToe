// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"
#include "linkedList.h"
#include "file.h"

int main() {
    pPlayers players=NULL;
    pMoves moves=NULL;
    char **board, filename[50];
    int x,y,bigX,bigY,quit=0,lastMove=-1;

    //Chamado apenas uma vez para usar o relógio interno do computador para controlar a escolha de números aleatórios e não repeti-los com uma nova execução.
    initRandom();

    //Cria um tabuleiro com o tamanho fixo, se for impossível da (erro)
    board = newBoard(SIZE);

    //Se for detetado um ficheiro
    if(wantToRecoverGame()) {
        players = recoverPlayers(players);
        if(board==NULL || players==NULL) {
            printf("\n\t[ERROR]: Couldn't allocate memory (Malloc Failed)");
            return 0;
        }
        moves = readInterruptedGame(moves, board);
        if(moves==NULL) {
            printf("\n\t[ERROR]: Couldn't read the file");
            return 0;
        }
        //Para o menu receber o lastMove atualizado
        getLastMove(moves,&bigX,&bigY,&lastMove);
        //É preciso voltar uma casa atras, onde foi a última jogada do próximo jogador
        lastMove--;
        showBoard(board,SIZE);
    }
    else{
        //Cria os dois jogadores (Humano e Humano/Computador)
        players=start(players);
        if(board==NULL || players==NULL) {
            printf("\n\t[ERROR]: Couldn't allocate memory (Malloc Failed)");
            return 0;
        }
    }

    //Executa as funções em ciclo ate se verificar uma vitória, empate ou desistência
    do{
        switch(menu(players, lastMove)){
            case 1:
                //Recebe o ultimo movimento
                getLastMove(moves,&bigX,&bigY,&lastMove);
                //Verifica se o mini tabuleiro anterior está ganho ou empatado e se tiver muda as coordenadas para um mini tabuleiro que esteja disponível
                generateNewMove(board,&bigX,&bigY);
                //Pede e verifica as coordenadas
                askForCoordinates(&x,&y,players,board,bigX,bigY,lastMove);
                //Atualiza a lista e o tabuleiro com a nova jogada
                moves = newMove(moves,board,x,y,bigX,bigY);
                //Mostra o tabuleiro
                showBoard(board,SIZE);
                //Se for detetado o fim, termina o jogo
                quit=confirmIfWon(board);
                break;
            case 2:
                //Mostra os últimos movimentos
                showNPreviousPlays(moves,players);
                break;
            case 3: quit=6; break;
        }
    }while(quit==0);

    if(quit==6)
        saveInterruptedGame(moves,players);
    else {
        showTheWinnerAndAskFile(players,++lastMove, filename, quit);
        saveFinishedGame(moves, players, filename);
    }

    //Libertar a memória alocada durante a execução do programa
    freeBoard(board,SIZE);
    freeList(moves);
    free((players+1));
    free(players);

    return 0;
}