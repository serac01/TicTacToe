// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"

void start(Players *player){
    char option;

    printf("\n\n\t\tWelcome! Do you want to play?\n\tTell me your name: ");
    fflush(stdin);
    fgets(player->player1, sizeof(player->player1), stdin);

    do{
        printf("\n\tWill you want to play with\n\t\t[1] - Me\n\t\t[2] - Friend\n\t> ");
        fflush(stdin);
        scanf("%c", &option);
    } while (option!='1' && option!='2');

    switch(option){
        case '1':
            strcpy(player->player2,"Me");
            break;
        case '2':
            printf("\n\tTell me your friend's name: ");
            fflush(stdin);
            fgets(player->player2, sizeof(player->player2), stdin);
            break;
        default:
            strcpy(player->player2,"Me");
            break;
    }
}