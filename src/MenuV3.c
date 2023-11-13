#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libs/tools/structs.h"

int input(){
    int mode = malloc(sizeof(int));
    mode = 0;
    bool valid = malloc(sizeof(bool));
    valid = false;
    while(!valid){
        printf("Select an option: ");
        scanf("%d", &mode);
        if(mode > 0 && mode < 11){
            valid = true;
        }else{
            printf("Invalid option\n");
        }
    }
    free(valid);
    return mode;
    free(mode);
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
    printf("\n");
    return 0;
}