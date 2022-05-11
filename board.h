// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdio.h>
#define SIZE 3

//Liberta a matriz alocada com memória dinâmica com "size" linhas e colunas
void freeBoard(char** p, int size);

//Cria uma matriz quadrada dinâmica de caracteres com tamanho size e já inicializada, devolve o endereço inicial da matriz
char** newBoard(int size);

//Coloca o carácter guardado em c na posição (x, y) na matriz dinâmica
void setPos(char **p, int x, int y, char c);

//Obtém o carácter armazenado na posição (x, y) da matriz dinâmica
char getPos(char **p, int x, int y);

//Confirma se o tabuleiro já tem um vencedor ou empate
int confirmIfWon(char **p);

//Confirma se um dos minis tabuleiros já tem um vencedor ou empate, devolve o caracter do vencedor, e se empate devolve '-'
char confirmIfWonMiniBoard(char **p, int x, int y);

#endif