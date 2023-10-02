#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mode;

void inputMode() {
    bool valid = false;
    char c;

    while (!valid) {
        scanf("%d", &mode);
        while ((c = getchar()) != '\n');  // Limpiar el buffer de entrada

        if ((mode > 10) || (mode < 1)) {
            printf("Please, introduce a valid mode: ");
        } else if ((mode == 3) || (mode == 4) || (mode == 5) || (mode == 6) || (mode == 7) || (mode == 8)) {
            printf("This mode is not available. Please, introduce a valid mode: ");
        } else {
            valid = true;
        }
    }
    
    modeChanger();
}

void modeChanger() {
    switch (mode) {
        case 1:
            char input = '\0';

            while (1) {
                printf("Are you sure you want to exit? ");
                scanf(" %c", &input);  // Leer un carácter y descartar el espacio en blanco

                if (input == 'y' || input == 'n') {
                    break;
                }

                printf("Please select a valid option\n");
            }

            if (input == 'y') {
                printf("Goodbye!\n");
                exit(0);
            }
            break;
        case 2:
            int input2 = 0;  // Inicializar la variable

            printf("What cell do you want to collect? (1 - 21): ");
            scanf("%d", &input2);

            // Verificar que el número esté dentro del rango válido
            if (input2 < 1 || input2 > 21) {
                printf("Número fuera del rango válido.\n");
                break;
            }

            // Construir el nombre del archivo en función del número ingresado
            char cells[50];  // Aumentar el tamaño del búfer para acomodar el nombre del archivo
            snprintf(cells, sizeof(cells), "mi_carpeta/archivo%d.txt", input2);

            // Intentar abrir el archivo
            FILE *file = fopen(cells, "r");
            if (file == NULL) {
                perror("Error when opening the file");
                break;
            } else {
                printf("The file '%s' was correctly opened.\n", cells);
                // Realiza operaciones de lectura/escritura en el archivo si es necesario
                fclose(file);
            }
            break;
        case 9:
            printf("You've chosen mode display\n");
            break;
        case 10:
            printf("You've chosen mode display all\n");
            break;
        default:
            printf("Invalid mode selected.\n");
            break;
    }
}

int main() {
    printf("Select a mode (1-10): ");
    inputMode();
    return 0;
}
