#ifndef DATA_CELLS_H
#define DATA_CELLS_H
typedef struct DataCells{
    int numCell;
    char address[20];
    char name[10];
    char mode[10];
    int ch;
    char key[4];
    int num1;
    int num2;
    float num3;
    int frq;
    
} DataCells;

typedef struct Cell{
    struct DataCells data;
    struct Cell *next;
} Cell;
#endif // DATA_CELLS_H