// By: Sérgio Apolinário da Costa (a2020129026),
// On: 09/04/2022

#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "utils.h"
#include "board.h"

void start(Players players[]);

void askForCoordinates(int *x, int *y, Players players[]);

#endif /*INTERFACE_H*/