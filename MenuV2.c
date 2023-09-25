#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int mode;

void inputMode(){
    bool valid = false;
    char c;
    while (!valid) {
        scanf("%d", &mode);
        while (c != '\n')
        {
            c = getchar();
        }
        if ((mode > 10) || (mode < 1)){
            printf("Please, introduce a valid mode: ");
        }
        else if ((mode == 3) || (mode == 4) || (mode == 5) || (mode == 6) || (mode == 7) || (mode == 8))
        {
            printf("This mode is not available. Please, introduce a valid mode: ");
        }
        
        else{
            valid = true;
        }
    }
}
void modeChanger(){
    switch (mode)
    {
    case 1:
        printf("Youve choosen mode quit");
        break;
    case 2:
        printf("Youve choosen mode collect");
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

int main(){
    printf("1. Quit \n2. Collect \n3. Show Data\n4. Select Best \n5. Delete Net \n6. Sort \n7. Export \n8. Import \n9. Display \n10. Display all \n\rSelect a mode: ");
    inputMode();
    modeChanger();
}