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
        printf("\n\tWill you want to play with\n\t\t[1] - Me\n\t\t[2] - Friend\n\t> ");
        fflush(stdin);
        scanf("%c", &option);
    } while (option!='1' && option!='2');

    switch(option){
        case '1':
            strcpy(player[1].name,"Me");
            break;
        case '2':
            printf("\n\tTell me your friend's name: ");
            fflush(stdin);
            fgets(player[1].name, sizeof(player[1].name), stdin);
            player[1].name[strlen(player[1].name)-1] = '\0';
            break;
        default:
            strcpy(player[1].name,"Me");
            break;
    }

    //Some error
    probEvento((float) 0.5);

    if(probEvento((float) 0.5)) {
        printf("\n\n\tThe player %s starts\n\n\n", player[0].name);
        player[0].number=1;
        player[1].number=2;
    } else{
        printf("\n\n\tThe player %s starts\n\n", player[1].name);
        player[1].number=1;
        player[0].number=2;
    }
}

void askForCoordinates(int *x, int *y, Players players[]){
    do{
        printf("\n\tYour turn %s > ",players[0].name);
        scanf("%d %d",x,y);
    }while(*x<1 || *x>SIZE || *y<1 || *y>SIZE);
    (*x)--;
    (*y)--;
}