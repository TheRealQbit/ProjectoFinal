
#include "../tools/definitions.h"

void mode5(DataCells **savedCells)
{
    int count = 0;
    char searchName[MAX_FILENAME_LENGTH];
    bool validInput = false;
    int foundCount = 0;

    while (!validInput)//we check if the input is between double quotes
    {
        printf("Enter the ESSID to delete (use double quotes): ");
        int scanned = scanf("\"%[^\"]\"", searchName);

        if (scanned == 1)
        {
            validInput = true;
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            printf("Error: Please enter the ESSID between double quotes.\n");
        }
    }

    for (int i = 0; i < &count; i++)
    {
        if (strcmp(searchName, (*savedCells)[i].name) == 0)//then we check if the input of the ESSID is in the array
        {
            foundCount++;

            for (int j = i; j < &count - 1; j++)
            {
                (*savedCells)[j] = (*savedCells)[j + 1];
            }

            (&count)--;

            printf("Found ESSID \"%s\" at position %d\n", searchName, i + 1);

            i--;
        }
    }

    if (foundCount == 0)//if it is not found we print this
    {
        printf("ESSID \"%s\" not found in the array.\n", searchName);
    }
}