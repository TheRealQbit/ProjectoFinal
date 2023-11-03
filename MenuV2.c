#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/structs.h"
#include "tools/definitions.h"
//#include "tools/arrayTools.c"
//#include "tools/input.c"
#include <ctype.h>


//void modeChanger(int mode, int *contador, struct dataCells **savedCells);

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
//dataCells *savedCells; 
//int *contador;
/// ====================================================================================================
/// ============================================ FUNCTIONS =============================================
/// ====================================================================================================


/// ====================================================================================================
/// ============================================ MODES =================================================
/// ====================================================================================================
void mode1(bool *exit){
    printf("You chose the modo 1\n");
    char modo;

    do
    {
        printf("Are you sure you want to exit? [y/n]: ");
        scanf(" %c", &modo);    // we scan the modo chosen by the user
        modo = tolower(modo); // So the value can be introduced both in uppercase and lower case

        if (modo == 'y')
        {
            printf("Goodbye!\n"); // we quit the program
            *exit= true;   // Update the value using a pointer
            break;
        }
        else if (modo == 'n')
        {
            printf("Returning to the main interface.\n"); // we return to the interface
            return;
        }
        else
        {
            printf("Invalid modo. Please try again: \n"); // if the user introduced an invalid modo
        }
    } while (1);
}
void mode2(struct dataCells** savedCells, int *contador){//this is mode 2 that will print the data of all the cells
    //initializes the variables
    char c;
    int arrSize = 5;
    do{
        int i;
        printf("What cell do you want to collect? (1-21):\n");//we ask the user for the number of the cell
        scanf("%d", &i);
        if (i > 21 || i < 1)//check if it is in bounds
        {
            printf("Please, introduce a valid cell: ");//response for not in bounds
        }
        else
        {
            char archivo[MAX_FILENAME_LENGTH];

            sprintf(archivo, "cells/info_cell_%d.txt", i);
            FILE *file = fopen(archivo, "r");//we open the file

            if (file == NULL)//just in case the file does not exist
            {
                fprintf(stderr, "Could not open the file.\n");
                return;
            }
            struct dataCells info;
            info.numCell = i;

            //here we read the data of the cell (scan)
            while (fscanf(file, "Cell %d Address: %s ESSID:\"%[^\"]\" Mode:%s Channel:%d Encryption key:%s Quality=%d/%d Frequency:%f GHz Signal level=%d dBm\n",
            &info.numCell, info.address, info.name, info.mode, &info.ch, info.key, &info.num1, &info.num2, &info.num3, &info.frq) != EOF)
            {
                if (arrSize<=*contador){
                    printf("(Allocating another 5 positions in the dynamic array)\n");
                    arrSize += 5;
                    *savedCells = (struct dataCells *)realloc(*savedCells, arrSize * sizeof(struct dataCells));//reallocating the memory
                    if (*savedCells == NULL)
                    {
                        fprintf(stderr, "Error: Memory reallocation failed.\n");//to check if it is possible to allocate more memory
                        return;
                    }


                }
                //here we save the data of the cell (print)
                (*savedCells)[*contador] = info;
                (*contador)++;                
                printf("The data that was selected from info_cell_%d.txt (is going to be added at position %d of the array)\n",
                       i, *contador - 1);
                printf("%d %s \"%s\" %s %d %s %d/%d %f %d\n",
                       info.numCell, info.address, info.name, info.mode, info.ch, info.key, info.num1, info.num2, info.num3, info.frq);
            }

            fclose(file); //we close the file
        }

        printf("Do you want to add another access point? [Y/n]: ");//we ask the user if he wants to add another access point
        scanf(" %c", &c); 
        
    } while (c == 'y' || c == 'Y');// check the answer of the user
}

void mode5(struct dataCells **savedCells, int* contador)//this is mode 5 that will erase the access point that is entered.
{
        //initialize variables
    char buscador[MAX_FILENAME_LENGTH];
    bool in = false;
    int encontrados = 0;

    while (!in)
    {
        printf("Enter the ESSID to delete (use double quotes): ");
        int scanned = scanf("\"%[^\"]\"", buscador);//to check if the format is correct.

        if (scanned == 1)
        {
            in = true;//here we'll change the value of the boolean parameter.
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            printf("Error: Please enter the ESSID between double quotes.\n"); //response to the format was not correct.
        }
    }

    for (int i = 0; i < *contador; i++)
    {
        if (strcmp(buscador, (*savedCells)[i].name) == 0)//this will check whereas the ESSID is the same than the entered one.
        {
            encontrados++;//it adds 1 to the number of times that the ESSID was found.

            for (int j = i; j < *contador - 1; j++) //loop of the dinamic array.
            {
                (*savedCells)[j] = (*savedCells)[j + 1];
            }

            (*contador)--;//it decreases the number of elements in the array.

            printf("Found ESSID \"%s\" at position %d\n", buscador, i + 1);//hereprint the position of the ESSID that was found.

            i--;
        }
    }

    if (encontrados == 0)//we're checking if the ESSID was found or not.
    {
        printf("ESSID \"%s\" not found in the array.\n", buscador);//this will be printted if the ESSID was not found.
    }
}

void mode9(struct dataCells** savedCells, int* contador) {//this is mode 9 that will print the data of all the cells
    char c;

    do
    {
        int cellss;

        //
        printf("Indicate the number of the cell for which you want to know its information (1 - 21): ");
        scanf("%d", &cellss);//we ask the user for the number of the cell

        if (1<=cellss && cellss <= NUM_FILES)
        {
            bool cellsEncontradas = false; // Initialize cellsEncontradas

            
            for (int i = 0; i < *contador; i++)
            {
                if ((*savedCells)[i].numCell == cellss)
                {
                    // print the info of the cell that was selected
                    printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm\n",
                   (*savedCells)[i].numCell, (*savedCells)[i].address, (*savedCells)[i].name,
                   (*savedCells)[i].mode, (*savedCells)[i].ch, (*savedCells)[i].key, (*savedCells)[i].num1,
                   (*savedCells)[i].num2, (*savedCells)[i].num3, (*savedCells)[i].frq);
                    cellsEncontradas = true;// Update the value using a pointer
                }
            }

            if (!cellsEncontradas)// Check if the cell was found or not.
            {
                printf("Error: Cell %d has not been collected previously.\n", cellss);
            }
        }
        else
        {
            printf("Error: Invalid cell number. Please enter a number between 1 and 21.\n");// respose to error message
        }

        printf("Do you want to retrieve information for another cell? [Y/n]: ");//we ask the user if he wants to retrieve information for another cell
        scanf(" %c", &c);
        c = tolower(c);

    } while (c == 'y');
}


void mode10(struct dataCells** savedCells, int *contador){//this is mode 10 that will print the data of all the cells
    if (*contador > 0)//check if the array is not empty
    {
        printf("Previously collected cells:\n");//

        for (int i = 0; i < *contador; i++)//check if the cell is in the array
        {
             printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm \n",//print the info of the cell that was selected
                   (*savedCells)[i].numCell, (*savedCells)[i].address, (*savedCells)[i].name, (*savedCells)[i].mode, (*savedCells)[i].ch, (*savedCells)[i].key, (*savedCells)[i].num1, (*savedCells)[i].num2, (*savedCells)[i].num3, (*savedCells)[i].frq);
        }
    }
    else
    {
        printf("The cell has not been stored(Access mode 2 and collect it).\n");//if the array is empty it will print this message
    }
}

/// ====================================================================================================
/// ============================================ MAIN ==================================================
/// ====================================================================================================


    

int main(){
    //initializes the variables
    int mode;  
    bool exit = false;
    struct dataCells* savedCells = (struct dataCells *)malloc(5* sizeof(struct dataCells));//allocating memory for the dynamic array
    int contador = 0;

do {//this is the main loop of the program
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
    printf("\nmodo: ");
        scanf("%d", &mode);


    switch (mode)//this is the switch that will execute the different modes
    {
    case 1:
        mode1(&exit);
        break;
    case 2:
        printf("Mode 2 selected.\n");
        mode2(&savedCells, &contador);
        break;
    case 9:
        printf("Mode 9 selected.\n");
        mode9(&savedCells, &contador);
        break;
    case 10:
        printf("Mode 10 selected.\n");
        mode10(&savedCells, &contador);
        break;        
    case 5:
        printf("Mode 5 was selected .\n");
        mode5(&savedCells, &contador);
    default:
        printf("Please, introduce a valid mode: ");
                break;
    }
    }while(!exit);//this is the end of the program.


    free(savedCells); //freeing the memory
    return 0;
}