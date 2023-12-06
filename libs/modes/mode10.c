void mode10(DataCells** savedCells){
    for(int i = 0; i < getLastArrayElement(*savedCells); i++){
        printf("Cell %d: %s %s %s %d %s %d/%d %f GHz %d dBm \n",
               (*savedCells)[i]->numCell, (*savedCells)[i]->address, (*savedCells)[i]->name, (*savedCells)[i]->mode, (*savedCells)[i]->ch, (*savedCells)[i]->key, (*savedCells)[i]->num1, (*savedCells)[i]->num2, (*savedCells)[i]->frq, (*savedCells)[i]->dbm);
    }
}