#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_FILES 21
#define MAX_FILENAME_LENGTH 100
#define SIZE 500

typedef struct dataCells { 
    //The struct is for the data from the file
    int numCell;
    char address;
    char ESSID;
    char mode;
    int ch;
    char key;
    char Quality;
    int level;
    float frq;
} dataCells;

dataCells savedCells[NUM_FILES];

void mode1();
void mode2(dataCells cellData[]);
void mode9();
void mode10(dataCells cellData[]);
/// ====================================================================================================
/// ============================================ FUNCTIONS =============================================
/// ====================================================================================================
void inputMode()
{
    int mode;
    bool valid = false;
    char c;
    while (!valid)
    {
        scanf("%d", &mode);
        while (c != '\n')
        {
            c = getchar();
        }
        if ((mode > 10) || (mode < 1))
        {
            printf("Please, introduce a valid mode: ");
        }
        else if ((mode == 3) || (mode == 4) || (mode == 5) || (mode == 6) || (mode == 7) || (mode == 8))
        {
            printf("This mode is not available. Please, introduce a valid mode: ");
        }

        modeChanger(mode);
    }
    
}
 void modeChanger(int mode){
    switch (mode)
    {
    case 1:
        mode1();
        break;
    case 2:
        printf("Mode 2 selected.\n");
        mode2(&savedCells);
        break;
    case 9:
        printf("Mode 9 selected.\n");
        mode9();
        break;
    case 10:
        printf("Mode 10 selected.\n");
        mode10(&savedCells);
        break;
    default:
        printf("Please, introduce a valid mode: ");
        inputMode();
        break;
    }
}
/// ====================================================================================================
/// ============================================ MODES ================================================
/// ====================================================================================================
 void mode1(){
    char input = '\0';

    while (input != 'y' || input != 'n' || input != 'Y' || input != 'N'){
        printf("Are you sure you want to exit? [y/N]:");
        scanf("%c", &input);

        if (input == 'y' || input == 'n' || input == 'Y' || input == 'N') {
            break;
        }
        printf("Please select a valid option\n");
    }
    if (input == 'y'){
            printf("Goodbye!\n");
            exit(0);
    }
    else{
        inputMode();
    }
}
void mode2(dataCells cellData[]) {
    char c;

    do{
        int i = 0, j = 0;
        int array_size[NUM_FILES];
        printf("What cell do you want to collect? (1-21):\n");
        scanf("%d", &i);
        if(i>21 || i<1){
            printf("Please, introduce a valid cell: ");
        }
        else{
            char filename[MAX_FILENAME_LENGTH];

            sprintf(filename, "cells/info_cell_%d.txt", i);
            FILE *file = fopen(filename, "r");

            if (file == NULL) {
                fprintf(stderr, "Could not open the file.\n");
                return;
            }
            dataCells data;  
            data.numCell = i;

            while (fscanf(file, "Cell %d\n Address: %c\nESSID:%s\n Mode:%s\n Channel:%d\n Encryption key:%s\n Quality=%c\n Frequency:%f GHz Signal level=%d dBm\n", &data.numCell, data.address, data.ESSID, data.mode, &data.ch, data.key, &data.Quality, &data.Quality, &data.frq, &data.level) != EOF) {            
                printf("Network read from %s (added to position %d of the array)\n", filename, j);
                /*
                printf("%d %s %s %s %d %s %d/%f %d\n",
                    data.numCell, data.address, data.ESSID, data.mode, data.ch, data.key, data.Quality, data.frq, data.level);*/
                j++;
            }
            cellData[i - 1] = data;
            fclose(file);


        }

        printf("Do you want to add another access point? [y/N]: ");
        scanf(" %c", &c); // Note the space before %c to skip leading whitespace
    }while(c != 'y' || c != 'Y' || c != 'n' || c != 'N');
    
    if(c== 'y' || c== 'Y'){
        modeChanger(2);
    }
    else if(c== 'n' || c== 'N'){
        inputMode();
    }
    else{
        printf("Please, introduce a valid option: ");
    }
}
 void mode9(){
    bool valid = false;
    int i;
    char c;
    while(!valid){
        printf("Indicate the number of the cell for which you want to know its information (1 - 21): ");
        scanf("%d", &i);
        if(i>21 || i<1){
            printf("Please, introduce a valid cell: ");
        }
        else{
            valid = true;
        }
    }   
    if(savedCells[i].numCell != 0){
        printf("%d %c %c %c %d %c %d/%d %d\n",
            savedCells[i].numCell, savedCells[i].address, savedCells[i].ESSID, savedCells[i].mode, savedCells[i].ch, savedCells[i].key, savedCells[i].Quality, savedCells[i].frq, savedCells[i].level);
    }
    else{
        printf("There is no information about this cell.\n");
    }
    valid = false;
    while (!valid)
    {
        printf("Do you want to print the information of another cell? [y/N]: ");
        scanf("%c", &c);
        if(c == 'y' || c == 'Y'){
            modeChanger(9);
        }
        else if(c == 'n' || c == 'N'){
            inputMode();
        }
        else{
            printf("Please, introduce a valid option: ");
        }
    }  
}
 void mode10(dataCells cellData[]){
    for(int i = 0; i< sizeof(cellData); i++){
        printf("%d %c %c %c %d %c %d %d\n",
            cellData[i].numCell, cellData[i].address, cellData[i].ESSID, cellData[i].mode, cellData[i].ch, cellData[i].key, cellData[i].Quality, cellData[i].frq, cellData[i].level);
    }
}
int main(){
    printf("[2023] SUCEM S.L. Wifi Collector by Alberto Villarroel & Yago Martínez\n\n");
    printf("\n[1]wificollector_quit\n");
    printf("[2]wificollector_collect\n");
    printf("[3]wificollector_show_data_one_network\n");
    printf("[4]wificollector_select_best\n");
    printf("[5]wificollector_delete_net\n");
    printf("[6]wificollector_sort\n");
    printf("[7]wificollector_export\n");
    printf("[8]wificollector_import\n");
    printf("[9]wificollector_display\n");
    printf("[10]wificollector_display_all\n");
    printf("\nOption: ");
    inputMode();
    return 0;
}