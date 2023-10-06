#include <stdio.h>
#include <stdbool.h>

#define NUM_FILES 21
#define MAX_FILENAME_LENGTH 100
#define SIZE 500


typedef struct {
    int nCell;
    char address[20];
    char name[10];
    char mode[10];
    int ch;
    char key[4];
    int num1;
    int num2;
    float num3;
    int frq;
} CellData;

void case2(CellData cellData[]);
void case10(CellData cellData[]);
void case1();

int main() {
    CellData cellData[NUM_FILES];  // Array to store cell data
    int width = 10;
    int opcion;
    bool exit_program = false;  // Declare and define exit_program here

    do {
        printf("[2023] SUCEM S.L. Wifi Collector\n");
        printf("\n%*s[1]wificollector_quit\n", width, "");
        printf("%*s[2]wificollector_collect\n", width, "");
        printf("%*s[9]wificollector_display\n", width, "");
        printf("%*s[10]wificollector_display_all\n", width, "");
        printf("\n%*sOption: ", width, "");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                case1(&exit_program);  // Pass exit_program as a pointer
                break;
            case 2:
                case2(cellData);
                break;
            case 9:
                printf("You chose the option 9\n");
                break;
            case 10:
                case10(cellData);
                break;
            default:
                printf("This option is not valid\n");
                break;
        }

    } while (!exit_program);

    return 0;
}

void case1(bool *exit_program) {
    printf("You chose the option 1\n");
    char option;

    do {
        printf("Are you sure you want to exit? [y/n]: ");
        scanf(" %c", &option);

        if (option == 'y') {
            printf("Goodbye :)\n");
            *exit_program = true;  // Update the value using a pointer
            break;
        } else if (option == 'n') {
            printf("Returning to the main interface.\n");
            return;
        } else {
            printf("Invalid option. Please try again: \n");
        }
    } while (1);
}

   void case2(CellData cellData[]) {
    char str[2];
    

    do {
        int i;
        int array_size[NUM_FILES];
        printf("What cell do you want to collect? (1-21):\n");
        scanf("%d", &i);

        if (i >= 1 && i <= NUM_FILES) {
            char filename[MAX_FILENAME_LENGTH];
            
            sprintf(filename, "cells/info_cell_%d.txt", i);
            FILE *file = fopen(filename, "r");
    

            if (file == NULL) {
                fprintf(stderr, "Could not open the file.\n");
                return;
            }

            CellData data;  // Temporary struct to store data for the current cell
            data.nCell = i;

            // Read data from the file
            while(fscanf(file, "Cell %d Address: %s ESSID:%s Mode:%s Channel:%d Encryption key:%s Quality=%d/%d Frequency:%f GHz Signal level=%d dBm\n", &data.nCell, data.address, data.name, data.mode, &data.ch, data.key, &data.num1, &data.num2, &data.num3, &data.frq) != EOF) {
                
                printf("%d %s %s %s %d %s %d/%d %f %d\n",
                       data.nCell, data.address, data.name, data.mode, data.ch, data.key, data.num1, data.num2, data.num3, data.frq);
            }

            // Store the data in the array
            cellData[i - 1] = data;
            fclose(file);
        } else {
            printf("Invalid cell number. Please enter a number between 1 and %d.\n", NUM_FILES);
            continue;  // Repeat the loop if the cell number is invalid
        }

        // Ask if the user wants to repeat the action
        printf("Do you want to repeat the action? (y/n): ");
        scanf("%s", str);

    } while (str[0] == 'y' || str[0] == 'Y');

    
}


   void case10(CellData cellData[]) {
    // Loop through the stored data and print it
    for (int i = 0; i < sizeof(cellData); i++) {
        printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm\n",
               cellData[i].nCell, cellData[i].address, cellData[i].name, cellData[i].mode,
               cellData[i].ch, cellData[i].key, cellData[i].num1, cellData[i].num2,
               cellData[i].num3, cellData[i].frq);
    }
   }