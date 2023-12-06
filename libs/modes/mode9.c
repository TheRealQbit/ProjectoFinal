void mode9(DataCells** savedCells){
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
            valid = true;
        }
    }
    for (int j = 0; j < sizeof(*savedCells); j++)
    {
        if ((*savedCells)[j].numCell != 0 && (*savedCells)[j].numCell == i)
        {
            printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm\n",
                   (*savedCells)[j].numCell, (*savedCells)[j].address, (*savedCells)[j].name, (*savedCells)[j].mode, (*savedCells)[j].ch, (*savedCells)[j].key, (*savedCells)[j].num1, (*savedCells)[j].num2, (*savedCells)[j].num3, (*savedCells)[j].frq);
        }
    }
    valid = false;
    while (!valid)
    {
        printf("Do you want to print the information of another cell? [y/N]: ");
        scanf("%c", &c);
        if (c == 'y' || c == 'Y')
        {
            modeChanger(9);
        }
        else if (c == 'n' || c == 'N')
        {
            inputMode();
        }
        else
        {
            printf("Please, introduce a valid option: ");
        }
    }
}