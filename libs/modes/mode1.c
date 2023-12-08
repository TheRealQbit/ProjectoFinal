#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void mode1() {
    char input;

    while (true) {
        printf("Are you sure you want to exit? [y/N]: ");
        scanf(" %c", &input);

        if (input == 'n' || input == 'N' ) {
            main();
            break;      
    }

            else if (input == 'y' || input == 'Y') {
        printf("Goodbye!\n");
        exit(0);
        break;
        }else printf("Please select a valid option\n");
    }
        
}