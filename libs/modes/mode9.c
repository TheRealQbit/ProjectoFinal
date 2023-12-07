void mode9(Cell **head){
    bool valid = false;
    int i;
    char c;
    while (!valid)
    {
        printf("Indicate the number of the cell for which you want to know its information (1 - 21): ");
        scanf("%d", &i);
        if (i > 21 || i < 1)
        {
            printf("Please, introduce a valid cell: ");
        }
        else
        {
            printCellsByNumCell(head, i);
            valid = true;
        }
    }
    
    valid = false;
    while (!valid)
    {
        printf("Do you want to print the information of another cell? [y/N]: ");
        scanf("%c", &c);
        if (c == 'y' || c == 'Y')
        {
            mode9(head);
        }
        else if (c == 'n' || c == 'N')
        {
            break;
        }
        else
        {
            printf("Please, introduce a valid option: ");
        }
    }
}