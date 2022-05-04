// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdio.h>
#define SIZE 3

//Liberta a matriz alocada com memória dinâmica com "size" linhas e colunas
void freeBoard(char** p, int size);

//Cria uma matriz dinâmica de caracteres com "size" linhas e colunas, e devolve o endereço inicial da matriz
char** newBoard(int size);

//Imprime a matriz dinâmica de caracteres
void showBoard(char **p, int size);

//coloca o carácter "c" na posição (x, y) na matriz dinâmica
void setPos(char **p, int x, int y, char c);

//obtém o carácter armazenado na posição (x, y) da matriz dinâmica
char getPos(char **p, int x, int y);

#endif