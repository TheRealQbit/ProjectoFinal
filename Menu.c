#include <stdio.h>
#include <stdlib.h>

int main()
{ // we print the functions
    int mode;

    printf("1. Quit \n2. Collect \n3. Show Data\n4. Select Best \n5. Delete Net \n6. Sort \n7. Export \n8. Import \n9. Display \n10. Display all \n\rSelect a mode: ");

    scanf("%d", &mode);
                        while (c != '\n')
                    {
                        c = getchar();
                    };

    char c;

    if ((mode > 10) || (mode < 1))
    {
        do
        {
            printf("Please, introduce a valid mode: ");
            scanf("%d", &mode);
                                while (c != '\n')
                    {
                        c = getchar();
                    };
        } while ((mode > 10) || (mode < 1));
    }

    if ((mode == 3) || (mode == 4) || (mode == 5) || (mode == 6) || (mode == 7) || (mode == 8))
    {
        do
        {
            printf("This mode is not available. Please, introduce a valid mode: ");
            scanf("%d", &mode);
                                while (c != '\n')
                    {
                        c = getchar();
                    };
            if ((mode < 1) || (mode > 10))
            {
                do
                {
                    printf("Please, introduce a valid mode: ");
                    scanf("%d", &mode);
                    while (c != '\n')
                    {
                        c = getchar();
                    };
                } while ((mode < 1) || (mode > 10));
            }
        } while ((mode == 3) || (mode == 4) || (mode == 5) || (mode == 6) || (mode == 7) || (mode == 8));
    }

    if (mode == 1)
    {
        printf("Youve choosen mode quit");
    }
    if (mode == 2)
    {
        printf("Youve choosen mode collect");
    }
    if (mode == 9)
    {
        printf("Youve choosen mode display");
    }
    if (mode == 10)
    {
        printf("Youve choosen mode display all");
    }
    return 0;
}