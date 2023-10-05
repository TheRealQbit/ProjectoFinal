#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_FILES 21
#define MAX_FILENAME_LENGTH 100
#define SIZE 500
int mode;
    typedef struct { //The struct is for the data from the file
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


void savedCells[size];
void inputMode()
{
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

        modeChanger();
    }
    
}
void mode2(dataCells dataCells[]) { //The void that makes the action for mode2
    char str[2];
    do {
        int i;
        int array_size[NUM_FILES];
        printf("What cell do you want to collect? (1-21):\n");
        scanf("%d", &i);

        if (i >= 1 && i <= NUM_FILES) {
            char filename[MAX_FILENAME_LENGTH];
            
            sprintf(filename, "info_cell_%d.txt", i);
            FILE *file = fopen(filename, "r");
    

            if (file == NULL) {
                fprintf(stderr, "Could not open the file.\n");
                return;
            }

            dataCells data;
            data.numCell = i;

            // Here we're reading the data of the file with the fscanf
            while(fscanf(file, "Cell %d Address: %s ESSID:%s Mode:%s Channel:%d Encryption key:%s Quality=%d/%d Frequency:%f GHz Signal level=%d dBm\n",
                   &data.numCell, data.address, data.name, data.mode, &data.ch, data.key, &data.num1, &data.num2, &data.num3, &data.frq) != EOF) {
                
                printf("%d %s %s %s %d %s %d/%d %f %d\n",
                       data.numCell, data.address, data.name, data.mode, data.ch, data.key, data.num1, data.num2, data.num3, data.frq);
            }

            // From this point we'll store the data
            dataCells[i - 1] = data;
            fclose(file);
        } else {
            printf("Invalid cell number. Please enter a number between 1 and %d.\n", NUM_FILES);
            continue;  // If the number is wrong
        }

        // Just in case to repeat the action
        printf("Do you want to repeat the action? (y/n): ");
        scanf("%s", str);

    } while (str[0] == 'y' || str[0] == 'Y');    
}


void mode10(){
    for(int i = 0; i<= size; i++){
        if(savedCells[i].ncell != NULL){
            printFile(savedCells[i]);
        }        
    }
    modeChanger();
}

void mode9(){
    bool valid = false;
    int index;
    int input2 = '\0';
    while (!valid)
    {
        printf("What cell do you want to collect? (1 - 21):");
        scanf("%d",&input2);

        // Is the number in range?
        if (input2 < 1 || input2 > 21) {
            printf("Number out of range.\n");            
        }
        else {
            index = input2;
            valid = true;
        }
    }
    
    for(int i = 0; i<= size; i++){
        if(savedCells[i].Adress != NULL && savedCells[i].ncell == index){
            printFile(savedCells[i]);
        }        
    }

    while (!valid){
        printf("Do you want to print the information of another cell? [y/N]: \n");
        scanf("%d",&input2);
        if(input2 != "n" && "y"){
            printf("Invalid input, please try again \n");
        }
        else if (input2 == "y")
        {
            valid = true;
            modeChanger();
        }else if(input2 == "n"){
            valid = true;
            mode9();
        }
    }
}

void printFile(infocells Cells){
    printf("%d %s %s %s %d %s %d %d \n", Cells.ncell, Cells.Adress, Cells.ESSID, Cells.Mode, Cells.Channel, Cells.Encryption_Key, Cells.n1, Cells.n2);
}
void saveCell(infocells Cell){
    bool valid = false;
    int i = 0;
    while(!valid){
        if(savedCells[i].ncell == NULL){
            savedCells[i] = Cell;
            valid = true;
        }
    }
}

void modeChanger()

    switch (mode)
    {
    case 1:
    
        char input = '\0';

        while (1)
        {
            printf("Are you sure you want to exit? [y/N]:");
            scanf("%c", &input);

            if (input == 'y' || input == 'n') {
                break;
            }

            printf("Please select a valid option\n");
            if (input != '\n') {

            }
        }

        if (input == 'y')
        {
            printf("Goodbye!\n");
            exit(0);
        }
           
        break;
    case 2:
        mode2(dataCells);
        break;

    case 9:
        mode9();
        break;
    case 10:
        mode10();
        break;
    default:
        printf("Not available\n")
        break;

}

void case2(CellData cellData[]);
void case9(CellData cellData[]);
void case10(CellData cellData[]);

int main(){
    printf("[2023] SUCEM S.L. Wifi Collector by Alberto Villarroel & Yago Martínez\n");
        printf("\n%*s[1]wificollector_quit\n", width, "");
        printf("%*s[2]wificollector_collect\n", width, "");
        printf("%*s[3]wificollector_show_data_one_network\n", width, "");
        printf("%*s[4]wificollector_select_best\n", width, "");
        printf("%*s[5]wificollector_delete_net\n", width, "");
        printf("%*s[6]wificollector_sort\n", width, "");
        printf("%*s[7]wificollector_export\n", width, "");
        printf("%*s[8]wificollector_import\n", width, "");
        printf("%*s[9]wificollector_display\n", width, "");
        printf("%*s[10]wificollector_display_all\n", width, "");
        printf("\n%*sOption: ", width, "");
        scanf("%d", &opcion);
    inputMode();

       

}

