#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/structs.h"
#include "tools/arrayTools.c"
#include "tools/input.c"
#include "MenuV2.c"

void mode10(dataCells** savedCells){
    for(int i = 0; i < getLastArrayElement(*savedCells); i++){
                    printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm \n",
                   (*savedCells)[i].numCell, (*savedCells)[i].address, (*savedCells)[i].name, (*savedCells)[i].mode, (*savedCells)[i].ch, (*savedCells)[i].key, (*savedCells)[i].num1, (*savedCells)[i].num2, (*savedCells)[i].num3, (*savedCells)[i].frq);
    }
}