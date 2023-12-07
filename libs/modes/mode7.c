void mode7(Cell **head){
    char filename[MAX_FILENAME_LENGTH];
    char userFilename[MAX_FILENAME_LENGTH];
    printf("Introduce the name of the file that you want to export: ");
    scanf("%99s", userFilename);
    snprintf(filename, sizeof(filename), "export/%s.cll", userFilename);
    printf("%s", filename);
    FILE* file = fopen(filename, "w");
    if (file == NULL)
            {
                fprintf(stderr, "Could not open the file.\n");
                return;
    }
    Cell* temp = *head;
    while(temp != NULL){
            fprintf(file, "%d %s %s %s %d %s %d/%d %f %d\n",
                temp->data.numCell, temp->data.address, temp->data.name, temp->data.mode, temp->data.ch, temp->data.key, temp->data.num1, temp->data.num2, temp->data.num3, temp->data.frq);
                temp = temp->next;
    }
    fclose(file);
    printf("Exported successfully\n");
}