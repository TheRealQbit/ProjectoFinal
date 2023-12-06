#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libs/tools/structs.h"

#include "./libs/modes/mode1.c"
#include "./libs/modes/mode2.c"
/*
#include "./libs/modes/mode5.c"
#include "./libs/modes/mode9.c"
#include "./libs/modes/mode10.c"
*/
int input(){
    int* mode = (int*) malloc(sizeof(int));
    *mode = 0;
    bool valid = false;
    while(!valid){
        printf("Select an option: ");
        scanf("%d", mode);     
        if(*mode > 0 && *mode < 11){
            valid = true;
        }else{
            printf("Invalid option\n");
        }
    }
    return *mode;
}
int main(){
    int mode;
    Cell *head = NULL;
    head = (Cell*) malloc(sizeof(Cell));
    head->next = NULL;
    head->data = *(DataCells*) malloc(sizeof(DataCells));

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
    do{
        printf("\n");
        mode = input();        
        switch (mode){
        case 1:
            mode1();
            break;
        case 2:
            mode2(head);
            break;
        case 5:
            //mode5(savedCells);
            break;
        case 9:
            //mode9(savedCells);
            break;
        case 10:
            //mode10(savedCells);
            break;
        default:
            break;
        }        
    }while(mode != 1);
    return 0;
}