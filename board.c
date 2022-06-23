// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "board.h"

void freeBoard(char** p, int size){
    for(int i=0; i<size*size+(size-1); i++)
        free(p[i]);
    free(p);
}

char** newBoard(int size){
    int sizeAux = size*size+(size-1);
    char **p = NULL;

    p = malloc(sizeof(char*) * sizeAux);
    if(p == NULL)
        return NULL;

    for(int i=0; i<sizeAux; i++){
        p[i] = malloc(sizeof(char) * sizeAux);
        if(p[i] == NULL){
            freeBoard(p, i-1);
            return NULL;
        }
    }

    //inicializar o tabuleiro
    for(int i=0, aux=1; i<sizeAux; i++){
        if(i == (size*aux+(aux-1))) { //Faz a linha da completa (borda horizontal)
            aux++;
            for (int j = 0; j < sizeAux; j++)
                p[i][j] = (char)219;
        }
        else
            for(int j=0, auxJ=1; j<sizeAux; j++)
                if(j == (size*auxJ+(auxJ-1))) { //Faz a coluna (borda vertical)
                    p[i][j] = (char)219;
                    auxJ++;
                }
                else
                    p[i][j] = '-';
    }

    return p;
}

void setPos(char **p, int x, int y, char c){ p[x][y] = c; }

char getPos(char **p, int x, int y){ return p[x][y]; }

int confirmIfWon(char **p){
    int count;
    char bigBoard[SIZE][SIZE]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            bigBoard[i][j]= confirmIfWonMiniBoard(p,i,j);

    //Linha por linha
    for(int i=0; i<SIZE; i++) {
        count=0;
        for (int j=0; j<SIZE; j++)
            if (j+1 != SIZE && bigBoard[i][j] != ' ' && bigBoard[i][j]==bigBoard[i][j+1])
                count++;
        if(count==SIZE-1)
            return 1;
    }

    //Coluna por coluna
    for(int i=0; i<SIZE; i++) {
        count=0;
        for (int j=0; j<SIZE; j++)
            if (j+1 != SIZE && bigBoard[j][i] != ' ' && bigBoard[j][i] == bigBoard[j+1][i])
                count++;
        if(count==SIZE-1)
            return 2;
    }

    //Diagonal principal
    count=0;
    for(int i=0; i<SIZE; i++) {
        if (bigBoard[i][i] != ' ' && bigBoard[i][i] == bigBoard[i+1][i+1])
            count++;
        if(count==SIZE-1)
            return 3;
    }

    //Diagonal secundária
    for(int i=0, j=SIZE-1; i<SIZE; i++, j--) {
        count=0;
        if (bigBoard[i][j] != ' ' && bigBoard[i][j] == bigBoard[i+1][j-1])
            count++;
        if(count==SIZE-1)
            return 4;
    }

    //Empate
    count=0;
    for(int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++)
            if (bigBoard[i][j] != ' ')
                count++;
        if(count==SIZE*SIZE)
            return 5;
    }

    return 0;
}

char confirmIfWonMiniBoard(char **p, int x, int y){
    int initX=SIZE*x+x, initY=SIZE*y+y,auxInitY=initY+(SIZE-1),count;
    char letter=' ';

    //Linha por linha
    for(int i=initX; i<initX+SIZE; i++) {
        count=0;
        for (int j=initY; j < initY+SIZE; j++)
            if (j+1 != initY+SIZE && getPos(p,i,j) != '-' && getPos(p,i,j)==getPos(p,i,j+1)) {
                count++;
                letter=getPos(p,i,j);
            }
        if(count==SIZE-1)
            return letter;
    }

    //Coluna por coluna
    for(int i=initY; i<initY+SIZE; i++) {
        count=0;
        for (int j = initX; j < initX + SIZE; j++)
            if (j + 1 != initX + SIZE && getPos(p, j, i) != '-' && getPos(p, j, i) == getPos(p,j+1,i)) {
                count++;
                letter=getPos(p, j, i);
            }
        if(count==SIZE-1)
            return letter;
    }

    //Diagonal principal
    count=0;
    for(int i=0; i<SIZE; i++) {
        if (getPos(p, initX, initY) != '-' && getPos(p, initX + i, initY + i) == getPos(p, initX + i + 1, initY + i + 1)) {
            count++;
            letter=getPos(p, initX + i, initY + i);
        }
        if(count==SIZE-1)
            return letter;
    }

    //Diagonal secundária
    count=0;
    for(int i=0; i<SIZE; i++) {
        if (getPos(p, initX, auxInitY) != '-' && getPos(p, initX+i, auxInitY-i) == getPos(p, initX+i+1, auxInitY-i-1)) {
            count++;
            letter=getPos(p, initX+i, auxInitY-i);
        }
        if(count==SIZE-1)
            return letter;
    }

    //Empate
    count=0;
    for(int i=initX; i<initX+SIZE; i++) {
        for (int j=initY; j < initY+SIZE; j++)
            if (getPos(p,i,j) != '-')
                count++;
        if(count==SIZE*SIZE)
            return '-';
    }

    return ' ';
}
