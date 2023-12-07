#include <stdio.h>
#include "structs.h"

/*
 * Create new Cell (using data as input)
 */
Cell* createCell(struct DataCells data){

    Cell* cell = (Cell*)malloc(sizeof(Cell));
    cell->data = data;
    cell->next = NULL;

    return cell;
};
/*
 * Insert Cell at the beginning
 */

void push(Cell **head, Cell *new_Cell){
    new_Cell->next = *head;
    *head = new_Cell;
}
/*
 * Insert Cell at the end
 */
void append(Cell **head_ref, Cell *new_Cell) {
    // If list is empty, the Cell is inserted at the beginning
    if (*head_ref == NULL) {
        *head_ref = new_Cell;
        return;
    }

    // If list is not empty, we look for the last Cell
    Cell *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_Cell;
}
/*
* Count the amount of cells in the list
*/    
int count(Cell *head){
    int count = 0;
    Cell *current = head;
    if(current->next == NULL){
        return 1;
    }
    while(current->next != NULL){
        count++;
        current = current->next;
    }
    return count;
}
/*
 * Insert Cell after a giving position
 */
void insert_after(Cell *prev_Cell, Cell *new_Cell) {
    if (prev_Cell == NULL) {
        printf("The previous Cell cannot be NULL\n");
        return;
    }

    new_Cell->next = prev_Cell->next;
    prev_Cell->next = new_Cell;
}

/*
 * Delete Cell by value
 */
void delete_Cell(Cell **head_ref,  char address[20]) {
    Cell *tmp = *head_ref, *prev;

    // The Cell to be deleted is the first position
    if (tmp != NULL && tmp->data.numCell == address) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    // If not, we find the matching Cell (if any)
    while (tmp != NULL && tmp->data.numCell != address) {
        prev = tmp;
        tmp = tmp->next;
    }

    // If not found, nothing is done
    if (tmp == NULL) {
        return;
    }

    // If found, the previous Cell is connected to the next
    // and then, the memory of the matching Cell is released
    prev->next = tmp->next;
    free(tmp);
}
Cell* FindCell(Cell *head, char address[20]){
    Cell *current = head;
    while(current->data.address != address){
        current = current->next;
    }
    return current;
}
void printList(Cell **head){
    Cell *current = *head;
    while(current != NULL){
        printf("%d %s %s %s %d %s %d/%d %f %d\n",
               current->data.numCell, current->data.address, current->data.name, current->data.mode, current->data.ch, current->data.key, current->data.num1, current->data.num2, current->data.num3, current->data.frq);
        current = current->next;
    }

}
void printCellsByNumCell(Cell **head, int key){
    Cell *current = *head;
    while(current != NULL){
        if(current->data.numCell == key){
            printf("%d %s %s %s %d %s %d/%d %f %d\n",
               current->data.numCell, current->data.address, current->data.name, current->data.mode, current->data.ch, current->data.key, current->data.num1, current->data.num2, current->data.num3, current->data.frq);
        }
        current = current->next;
    }
}