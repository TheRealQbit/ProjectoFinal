#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_FILES 21
#define MAX_FILENAME_LENGTH 100
#define SIZE 500

void modeChanger(int mode);

typedef struct dataCells
{
    int numCell;
    char address[20];
    char name[10];
    char mode[10];
    int ch;
    char key[4];
    int num1;
    int num2;
    float num3;
    int frq;
} dataCells;

dataCells savedCells[NUM_FILES];

void mode1();
void mode2(dataCells cellData[]);
int getLastArrayElement(dataCells cellData[]);
void mode9();
void mode10(dataCells cellData[]);
/// ====================================================================================================
/// ============================================ FUNCTIONS =============================================
/// ====================================================================================================
void inputMode()
{
    int mode = 0;
    bool valid = false;
    char c;
    while (!valid)
    {
        printf("\nOption: ");
        scanf("%d", &mode);
        while (c != '\n')
        {
            c = getchar();
        }
        if ((mode > 10) || (mode < 1))
        {
            printf("Please, introduce a valid mode: ");
        }
        else if ((mode == 3) || (mode == 4) || (mode == 6) || (mode == 7) || (mode == 8))
        {
            printf("This mode is not available. Please, introduce a valid mode: ");
        }

        modeChanger(mode);
    }
}
void modeChanger(int mode)
{
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
        mode2(&savedCells);
    default:
        printf("Please, introduce a valid mode: ");
        inputMode();
        break;
    }


}
int getLastArrayElement(dataCells cellData[])
{
    int i = 0;
    while (cellData[i].numCell != 0)
    {
        i++;
    }
    return i;
}
/// ====================================================================================================
/// ============================================ MODES ================================================
/// ====================================================================================================
void mode1()
{
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
void mode2(dataCells cellData[])
{
    char c;

    do
    {
        int i = 0, j = 0;
        int array_size[NUM_FILES];
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
            printf("Please, introduce a valid option: ");
        }
    } while (c != 'y' || c != 'Y' || c != 'n' || c != 'N');
}



void mode9(dataCells cellData[])
{
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
    for (int j = 0; j < sizeof(cellData); j++)
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
void mode10(dataCells cellData[])
{
    for (int i = 0; i < sizeof(dataCells *); i++)
    {
        if (cellData[i].numCell != 0)
        {
            printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm\n",
                   cellData[i].numCell, cellData[i].address, cellData[i].name, cellData[i].mode, cellData[i].ch, cellData[i].key, cellData[i].num1, cellData[i].num2, cellData[i].num3, cellData[i].frq);
        }
    }
}
int main()
{
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
    inputMode();
    return 0;
}