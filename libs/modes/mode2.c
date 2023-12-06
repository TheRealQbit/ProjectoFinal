#include <stdio.h>
#include <stdlib.h>
#include "../tools/definitions.h"
#include "../tools/structs.h"
#include "../tools/LinkedListTools.c"

void mode2(Cell **head){
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
            DataCells data;
            data.numCell = i;

            j = count(head);
            
            while (fscanf(file, "Cell %d Address: %s ESSID:%s Mode:%s Channel:%d Encryption key:%s Quality=%d/%d Frequency:%f GHz Signal level=%d dBm\n", &data.numCell, data.address, data.name, data.mode, &data.ch, data.key, &data.num1, &data.num2, &data.num3, &data.frq) != EOF)
            {
                Cell *temp = createCell(data);
                append(head, &temp);
                printf("Network read from info_cell_1.txt (added to position %d of the array)\n", j);
                printf("%d %s %s %s %d %s %d/%d %f %d\n",
                       data.numCell, data.address, data.name, data.mode, data.ch, data.key, data.num1, data.num2, data.num3, data.frq);
                free(temp); 
                
            }

            fclose(file);
        }

        printf("Do you want to add another access point? [y/N]: ");
        scanf(" %c", &c); // Note the space before %c to skip leading whitespace
        if (c == 'y' || c == 'Y')
        {
            mode2(head);
        }
        else if (c == 'n' || c == 'N')
        {
            break;
        }
        else
        {
            printf("Please, introduce a valid option (y/n): ");
        }
    } while (c != 'y' || c != 'Y' || c != 'n' || c != 'N');
}