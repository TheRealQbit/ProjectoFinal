#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int mode;

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
void modeChanger()
{
    switch (mode)
    {
    case 1:
    
        char input = '\0';

        while (1)
        {
            printf("Are you sure you want to exit? ");
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
        int input2 = '\0';

        printf("What cell do you want to collect? (1 - 21):");
        scanf("%d",&input2);

    // Verificar que el número esté dentro del rango válido
    if (input2 < 1 || input2 > 21) {
        printf("Número fuera del rango válido.\n");
        return 1;
    }

    // Construir el nombre del archivo en función del número ingresado
    char cells[21];  // Asumimos que el nombre del archivo no excederá los 50 caracteres
    snprintf(cells, sizeof(cells), "mi_carpeta/archivo%d.txt", input2);

    // Intentar abrir el archivo
    FILE *file = fopen(cells  , "r");
    if (file == NULL) {
        perror("Error when opening the file");
        return 1;
    } else {
        printf("The file '%s' was correctely opened.\n", cells  );
        // Realiza operaciones de lectura/escritura en el archivo si es necesario
        fclose(file);
    }


        break;
    case 9:
        printf("Youve choosen mode display");
        break;
    case 10:
        printf("Youve choosen mode display all");
        break;
    default:
        break;
    }
}

int main()
{
    printf("1. Quit \n2. Collect \n3. Show Data\n4. Select Best \n5. Delete Net \n6. Sort \n7. Export \n8. Import \n9. Display \n10. Display all \n\rSelect a mode: ");
    inputMode();
}
