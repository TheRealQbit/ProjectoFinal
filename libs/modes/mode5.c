#include "../tools/structs.h"
#include "../tools/definitions.h"


void mode5(Cell **head)
{
    Cell *current = *head;
    int count = 0;
    char searchName[MAX_FILENAME_LENGTH];
    bool validInput = false;
    int foundCount = 0;
  
    while (!validInput){
        printf("Enter the ESSID to delete (use double quotes): ");
        scanf(" %s", searchName);
        printf("You entered: \"%s\"\n", searchName);
        validInput = true;
    }   

    if(*head == NULL){
        printf("The list is empty\n");
        return;
    }
    do{
        if(current->data.address == NULL){
            break;
        }else if (current->data.address != searchName){
            current = current->next;
            count++;
        }else {
            foundCount++;
            printf("Network \"%s\" deleted from the array.\n", searchName);
            delete_Cell(head, searchName);
            current = current->next;
        }    
    }while (current != NULL);   

    if (foundCount == 0)//if it is not found we print this
    {
        printf("ESSID \"%s\" not found in the array.\n", searchName);
    }
}