int getLastArrayElement(struct dataCells **cellData){
    int i = 0;
    while (cellData[i]->numCell != 0)
    {
        i++;
    }
    isArrayBigEnough(cellData, i);
    return i;
}
void isArrayBigEnough(struct dataCells **cellData, int i){
    if(sizeof(cellData)-i < 2 && i != 0){
       struct dataCells *TempArray = (struct dataCells *)realloc(cellData, sizeof(struct dataCells) * (sizeof(*cellData) + 5));

        if (TempArray == NULL) {
            // Handle realloc failure
            free(cellData);  // Release the original array
            printf("Memory allocation failed.\n");
            return;
        }
        cellData = TempArray;  // Update the array with the newly allocated memory
    }
}