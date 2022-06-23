// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "interface.h"

pPlayers start(pPlayers player){
    char option;

    player = malloc(2*sizeof(Players));
    if(player==NULL)
        return NULL;

    printf("\n\n\t\tWelcome! Do you want to play?\n\tTell me your name: ");
    fflush(stdin);
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strlen(player->name)-1] = '\0';
    player->isComputer=0;

    do{
        printf("\n\tWill you want to play with\n\t\t[1] - Computer\n\t\t[2] - Friend\n\t> ");
        fflush(stdin);
        scanf("%c", &option);
    }while(option!='1' && option!='2');

    switch(option){
        case '1':
            strcpy((player+1)->name,"Computer");
            (player+1)->isComputer=1;
            break;
        case '2':
            printf("\n\tTell me your friend's name: ");
            fflush(stdin);
            fgets((player+1)->name, sizeof((player+1)->name), stdin);
            (player+1)->name[strlen((player+1)->name)-1] = '\0';
            (player+1)->isComputer=0;
            break;
        default:
            strcpy((player+1)->name,"Computer");
            (player+1)->isComputer=1;
            break;
    }

    //Escolhe qual dos utilizadores vai começar
    if(intUniformRnd(0, 1)) {
        printf("\n\n\tThe player %s starts\n\n\n", player->name);
        player->number=1;
        (player+1)->number=2;
    }else{
        printf("\n\n\tThe player %s starts\n\n", (player+1)->name);
        (player+1)->number=1;
        player->number=2;
    }
    return player;
}

void askForCoordinates(int *x, int *y, pPlayers players, char **board, int bigX, int bigY, int lastMove){
    char op1[]=" ";
    int result, isComputer;
    lastMove++;

    do{
        //Determinar qual é o nome do jogador atual baseado no número da jogada
        if(lastMove%2==0) {
            if (players->number == 2) {
                printf("\n\tYour turn %s [row=%d column=%d] > ", players->name, bigX + 1, bigY + 1);
                isComputer=players->isComputer;
            }else {
                printf("\n\tYour turn %s [row=%d column=%d] > ", (players + 1)->name, bigX + 1, bigY + 1);
                isComputer=(players+1)->isComputer;
            }
        }else {
            if (players->number == 1) {
                printf("\n\tYour turn %s [row=%d column=%d] > ", players->name, bigX + 1, bigY + 1);
                isComputer=players->isComputer;
            }else {
                printf("\n\tYour turn %s [row=%d column=%d] > ", (players + 1)->name, bigX + 1, bigY + 1);
                isComputer=(players+1)->isComputer;
            }
        }
        if(isComputer==1){
            *x=intUniformRnd(1,3);
            *y=intUniformRnd(1,3);
            printf("%d %d",*x,*y);
        }else
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

int menu(pPlayers players, int lastMove){
    int opt;

    do{
        printf("\n\n\t\tMENU");
        if(lastMove%2==0) {
            if (players->number == 2) {
                if(players->isComputer==1)
                    return 1;
                printf("\n\tYour turn %s", players->name);
            }else {
                if((players+1)->isComputer==1)
                    return 1;
                printf("\n\tYour turn %s", (players + 1)->name);
            }
        }else {
            if (players->number == 1) {
                if(players->isComputer==1)
                    return 1;
                printf("\n\tYour turn %s", players->name);
            }else {
                if((players+1)->isComputer==1)
                    return 1;
                printf("\n\tYour turn %s", (players + 1)->name);
            }
        }

        printf("\n\t 1 - Make a new move\n\t 2 - See N previous plays\n\t 3 - Quit\n\t\tOption > ");
        scanf("%d",&opt);
    }while(opt<1 || opt>3);
    return opt;
}

void showNPreviousPlays(pMoves list, pPlayers players){
    pMoves moves=list;
    int n, lastMove=0;

    //Pedir um numero de vistas validas
    do{
        printf("\n\tHow many plays do you want to see? [1 to 10] > ");
        scanf("%d",&n);
    }while(n<1 || n>10);

    //Se a lista tiver conteúdo, guarda em lastMove o número da jogada antes das (N) jogadas atuais
    if(moves!=NULL) {
        while (moves->next != NULL)
            moves = moves->next;
        lastMove = moves->moveNumber - (n - 1);
    }

    //Se o valor exceder o número de jogadas feitas, começa a mostrar desde o início
    if(lastMove<1)
        lastMove=1;

    //Ir para a posição certa da lista
    while(list!=NULL && list->moveNumber!=lastMove)
        list = list->next;
    
        while(list!=NULL){
            if(list->moveNumber%2==0) {
                if (players->number == 2)
                    printf("\n\tThe player %s made the move %d %d on the board %d %d", players->name, list->x+1, list->y+1, list->bigX+1, list->bigY+1);
                else
                    printf("\n\tThe player %s made the move %d %d on the board %d %d", (players+1)->name, list->x+1, list->y+1, list->bigX+1, list->bigY+1);
            }else{
                if (players->number == 1)
                    printf("\n\tThe player %s made the move %d %d on the board %d %d", players->name, list->x+1, list->y+1, list->bigX+1, list->bigY+1);
                else
                    printf("\n\tThe player %s made the move %d %d on the board %d %d", (players+1)->name, list->x+1, list->y+1, list->bigX+1, list->bigY+1);
            }
            list=list->next;
        }
}

int wantToRecoverGame(){
    char answer;
    FILE *file;

    //Verificar se o ficheiro existe, se nao devolve 0 e faz o processo normal
    if ((file = fopen("jogo.bin", "r")))
        fclose(file);
    else
        return 0;

    do{
        printf("\n\n\t\tWelcome! Do you want to play?\n\tDo you want to recover the last game that was interrupted? [Y/N]");
        scanf(" %c", &answer);
        fflush(stdin);
    } while (answer!='y' && answer!='Y' && answer!='N' && answer!='n');

    return answer=='y' || answer=='Y';
}

void showTheWinnerAndAskFile(pPlayers players, int lastMove, char *filename, int itsATie){
    if(itsATie==5)
        printf("\n\tThe game ended in a tie");
    else if(lastMove%2==0) {
        if (players->number == 2)
            printf("\n\tCongratulations %s you won the game", players->name);
        else
            printf("\n\tCongratulations %s you won the game", (players + 1)->name);
    }else {
        if (players->number == 1)
            printf("\n\tCongratulations %s you won the game", players->name);
        else
            printf("\n\tCongratulations %s you won the game", (players + 1)->name);
    }
    printf("\n\n\t\tLet's save this magnificent game!\n\tTell me the name of the file: ");
    fflush(stdin);
    scanf("%s",filename);
    filename[strlen(filename)] = '\0';
    if(!(filename[strlen(filename)-4] == '.' && filename[strlen(filename)-3] =='t' && filename[strlen(filename)-2] =='x' && filename[strlen(filename)-1] =='t'))
        strcat(filename,".txt");
}