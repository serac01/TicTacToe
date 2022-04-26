#include "matdin.h"

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

    for(int i=0, aux=1; i<sizeAux; i++){
        if(i == (size*aux+(aux-1))) { //Faz a linha completa
            aux++;
            for (int j = 0; j < sizeAux; j++)
                p[i][j] = (char)219;
        }
        else
            for(int j=0, auxJ=1; j<sizeAux; j++)
                if(j == (size*auxJ+(auxJ-1))) { //Faz a coluna
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

void showBoard(char **p, int size){
    for(int i=0; i<size*size+(size-1); i++){
        printf("\n\t");
        for(int j=0; j<size*size+(size-1); j++)
            printf("%c ", p[i][j]);
    }
}