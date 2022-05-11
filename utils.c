// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#include "utils.h"

void initRandom(){ srand(time(NULL)); }

int intUniformRnd(int a, int b){ return a + rand()%(b-a+1); }

int probEvento(float prob){ return prob > ((float)rand()/RAND_MAX); }