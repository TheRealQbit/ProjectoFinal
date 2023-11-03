#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/structs.h"
#include "tools/definitions.h"
#include "tools/arrayTools.c"
#include "tools/input.c"
#include "mode/mode1.c"
#include "mode/mode2.c"
//#include "mode/mode5.c"
#include "mode/mode9.c"
#include "mode/mode10.c"


void modeChanger(int mode);

/// @brief Struct that contains the data of a cell
/// @param numCell Number of the cell
/// @param address Address of the cell
/// @param name Name of the cell
/// @param mode Mode of the cell
/// @param ch Channel of the cell
/// @param key Key of the cell
/// @param num1 First number of the cell
/// @param num2 Second number of the cell
/// @param num3 Third number of the cell
/// @param frq Frequency of the cell

// Declaration of a pointer to a dataCells struct
dataCells *savedCells; 
int *count;
/// ====================================================================================================
/// ============================================ FUNCTIONS =============================================
/// ====================================================================================================

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
        mode9(&savedCells);
        break;
    case 10:
        printf("Mode 10 selected.\n");
        mode10(&savedCells);
        break;        
    case 5:
        printf("Mode 5 was selected .\n");
        //mode5(&savedCells, count);
    default:
        printf("Please, introduce a valid mode: ");
        inputMode();
        break;
    }
}
/// ====================================================================================================
/// ============================================ MODES =================================================
/// ====================================================================================================
/*void mode1(){
    char input;

    while (true)
    {
        printf("Are you sure you want to exit? [y/N]:");
        scanf("%c", &input);

        if (input == 'y' || input == 'n' || input == 'Y' || input == 'N')
        {
            break;
        }

        printf("Please select a valid option\n");
    }
    if (input == 'y')
    {
        printf("Goodbye!\n");
        exit(0);
    }
}
void mode2(dataCells** savedCells){
    char c;
    do{
        int i = 0, j = 0;
        printf("What cell do you want to collect? (1-21):\n");
        scanf("%d", &i);
        if (i > 21 || i < 1)
        {
            printf("Please, introduce a valid cell: ");
        }
        else
        {
            char filename[MAX_FILENAME_LENGTH];

            sprintf(filename, "cells/info_cell_%d.txt", i);
            FILE *file = fopen(filename, "r");

            if (file == NULL)
            {
                fprintf(stderr, "Could not open the file.\n");
                return;
            }
            dataCells data;
            data.numCell = i;

            j = getLastArrayElement(cellData);

            while (fscanf(file, "Cell %d Address: %s ESSID:%s Mode:%s Channel:%d Encryption key:%s Quality=%d/%d Frequency:%f GHz Signal level=%d dBm\n", &data.numCell, data.address, data.name, data.mode, &data.ch, data.key, &data.num1, &data.num2, &data.num3, &data.frq) != EOF)
            {
                printf("Network read from info_cell_1.txt (added to position %d of the array)\n", j);
                printf("%d %s %s %s %d %s %d/%d %f %d\n",
                       data.numCell, data.address, data.name, data.mode, data.ch, data.key, data.num1, data.num2, data.num3, data.frq);
                cellData[j] = data;
                j++;
            }

            fclose(file);
        }

        printf("Do you want to add another access point? [y/N]: ");
        scanf(" %c", &c); // Note the space before %c to skip leading whitespace
        if (c == 'y' || c == 'Y')
        {
            modeChanger(2);
        }
        else if (c == 'n' || c == 'N')
        {
            inputMode();
        }
        else
        {
            printf("Please, introduce a valid option (y/n): ");
        }
    } while (c != 'y' || c != 'Y' || c != 'n' || c != 'N');
}
void mode5(dataCells** savedCells, int *count);
/*void mode5(dataCells** cellData, int* count) {
    char searchName[MAX_FILENAME_LENGTH];
    int foundIndex = 0;

    printf("Indicate the ESSID (use double quotes): ");
    scanf("%s", searchName);

    for (int i = 0; i < *count; i++) {
        if (strcmp(searchName, cellData[i]->name) == 0) {
            foundIndex = i;
            break; // Exit the loop when the ESSID is found
        }
    }

    if (foundIndex != -1) {
        // Delete the access point file here, if applicable
        char filename[MAX_FILENAME_LENGTH];
        sprintf(filename, "access_points/%s.txt", searchName); // Adjust the path as needed

        if (remove(filename) == 0) {
            // Shift elements to eliminate the cell
            for (int i = foundIndex; i < *count - 1; i++) {
                cellData[i] = cellData[i + 1];
            }
            (*count)--;

            printf("ESSID \"%s\" has been deleted.\n", searchName);
        } else {
            printf("Failed to delete ESSID \"%s\". Please check file permissions or existence.\n", searchName);
        }
    } else {
        printf("ESSID \"%s\" not found in the data.\n", searchName);
    }
}*/

/*void mode9(dataCells** savedCells){
    bool valid = false;
    int i;
    char c;
    while (!valid)
    {
        printf("Indicate the number of the cell for which you want to know its information (1 - 21): ");
        scanf("%d", &i);
        if (i > 21 || i < 1)
        {
            printf("Please, introduce a valid cell: ");
        }
        else
        {
            valid = true;
        }
    }
    for (int j = 0; j < sizeof(*cellData); j++)
    {
        if (cellData[j].numCell != 0 && cellData[j].numCell == i)
        {
            printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm\n",
                   cellData[j].numCell, cellData[j].address, cellData[j].name, cellData[j].mode, cellData[j].ch, cellData[j].key, cellData[j].num1, cellData[j].num2, cellData[j].num3, cellData[j].frq);
        }
    }
    valid = false;
    while (!valid)
    {
        printf("Do you want to print the information of another cell? [y/N]: ");
        scanf("%c", &c);
        if (c == 'y' || c == 'Y')
        {
            modeChanger(9);
        }
        else if (c == 'n' || c == 'N')
        {
            inputMode();
        }
        else
        {
            printf("Please, introduce a valid option: ");
        }
    }
}
void mode10(dataCells**savedCells){
    for(int i = 0; i < getLastArrayElement(cellData); i++){
                    printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm \n",
                   cellData[i].numCell, cellData[i].address, cellData[i].name, cellData[i].mode, cellData[i].ch, cellData[i].key, cellData[i].num1, cellData[i].num2, cellData[i].num3, cellData[i].frq);
    }
}*/
/// ====================================================================================================
/// ============================================ MAIN ==================================================
/// ====================================================================================================
int main(){
    dataCells* savedCells = (dataCells *)malloc(5* sizeof(dataCells));
    dataCells dataCells[MAX_ACCESS_POINTS];
    int* count = 0;
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
    printf("\n");

    inputMode();
    free(savedCells); 
    return 0;
}