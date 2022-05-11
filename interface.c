// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"

void start(Players player[]){
    char option;

    printf("\n\n\t\tWelcome! Do you want to play?\n\tTell me your name: ");
    fflush(stdin);
    fgets(player[0].name, sizeof(player[0].name), stdin);
    player[0].name[strlen(player[0].name)-1] = '\0';

    do{
        printf("\n\tWill you want to play with\n\t\t[1] - Computer\n\t\t[2] - Friend\n\t> ");
        fflush(stdin);
        scanf("%c", &option);
    }while(option!='1' && option!='2');

    switch(option){
        case '1':
            strcpy(player[1].name,"Computer");
            break;
        case '2':
            printf("\n\tTell me your friend's name: ");
            fflush(stdin);
            fgets(player[1].name, sizeof(player[1].name), stdin);
            player[1].name[strlen(player[1].name)-1] = '\0';
            break;
        default:
            strcpy(player[1].name,"Computer");
            break;
    }

    /*for(int i=0; i<10; i++)
        printf("%d ", probEvento((float) 0.5));*/

    //Escolhe qual dos utilizadores vai começar
    if(probEvento((float) 0.5)) {
        printf("\n\n\tThe player %s starts\n\n\n", player[0].name);
        player[0].number=1;
        player[1].number=2;
    }else{
        printf("\n\n\tThe player %s starts\n\n", player[1].name);
        player[1].number=1;
        player[0].number=2;
    }
}

void askForCoordinates(int *x, int *y, Players players[], char **board, int bigX, int bigY, int lastMove){
    char op1[]=" ";
    int result;
    lastMove++;
    do{
        //Determinar qual é o nome do jogador atual baseado no número da jogada
        if(lastMove%2==0) {
            if (players[0].number == 2)
                printf("\n\tYour turn %s [row column] > ", players[0].name);
            else
                printf("\n\tYour turn %s [row column] > ", players[1].name);
        }else {
            if (players[0].number == 1)
                printf("\n\tYour turn %s [row column] > ", players[0].name);
            else
                printf("\n\tYour turn %s [row column] > ", players[1].name);
        }
        scanf("%d %d",x,y);
        //Faz a verificação quanto ao tamanho do tabuleiro, quanto a posição
        if((*x>0 && *x<=SIZE) && (*y>0 && *y<=SIZE)) {
            op1[0] = getPos(board, SIZE*bigX+bigX+((*x)-1),SIZE*bigY+bigY+((*y)-1));
            result = strcmp(op1, "-");
        }else
            result=1;
    }while(result==1);
    (*x)--;
    (*y)--;
}

void showBoard(char **p, int size){
    for(int i=0; i<size*size+(size-1); i++){
        printf("\n\t");
        for(int j=0; j<size*size+(size-1); j++)
            printf("%c ", p[i][j]);
    }
    printf("\n");
}

void generateNewMove(char **p, int *x, int *y){
    if(confirmIfWonMiniBoard(p,*x,*y)!=' ')
        do{
            *x=intUniformRnd(0,SIZE-1);
            *y=intUniformRnd(0,SIZE-1);
            printf("\n\n\tThe previous board is already complete, now you will play on the board with row %d and column %d",(*x)+1,(*y)+1);
        }while(confirmIfWonMiniBoard(p,*x,*y)!=' ');
}
