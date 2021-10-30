#include "config.h"
#include <stdio.h>
#include <stdlib.h>

void readConfig(char fileName[20], ListLoc *listLoc, int *mapRows, int *mapCols, Matrix *adjMat) {
    FILE *file;
    file = fopen(fileName, "r");
    startWordFile(file);
    *mapRows = atoi(input);
    advWordFile();
    *mapCols = atoi(input);

    advWordFile();
    int HQRow = atoi(input);
    advWordFile();
    int HQCol = atoi(input);
    Location HQLoc;
    createLocation(&HQLoc, '@', HQRow, HQCol);
    insertLastListLoc(listLoc, HQLoc);

    advWordFile();
    int lNum = atoi(input);

    for (int lCount = 0; lCount < lNum; lCount++) {
        advWordFile();
        char locName = input[0];
        advWordFile();
        int locRow = atoi(input);
        advWordFile();
        int locCol = atoi(input);
        Location loc;
        createLocation(&loc, locName, locRow, locCol);
        insertLastListLoc(listLoc, loc);
    }

    CreateMatrix(lNum + 1, lNum + 1, adjMat);
    for (int i = 0; i < lNum + 1; i++) {
        for (int j = 0; j < lNum + 1; j++) {
            advWordFile();
            ELMT(*adjMat, i, j) = atoi(input);
        }
    }
    ROWS(*adjMat) = lNum + 1;
    COLS(*adjMat) = lNum + 1;

    advWordFile();
    int pNum = atoi(input);
}