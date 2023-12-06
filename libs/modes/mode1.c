#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void mode1() {
    char input;

    while (true) {
        printf("Are you sure you want to exit? [y/N]: ");
        scanf(" %c", &input);

        if (input == 'y' || input == 'n' || input == 'Y' || input == 'N') {
            break;
        }

        printf("Please select a valid option\n");
    }

    if (input == 'y' || input == 'Y') {
        printf("Goodbye!\n");
        exit(0);
    }
}