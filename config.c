#include "config.h"
#include <stdio.h>
#include <stdlib.h>

void readConfig(char fileName[20], ListLoc *listLoc, int *mapRows, int *mapCols, Matrix *adjMat, DaftarPesanan *daftarPesanan) {
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
    createLocation(&HQLoc, '8', HQRow, HQCol);
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

    for (int pCount = 0; pCount < pNum; pCount++) {
        advWordFile();
        int waktuMasuk = atoi(input);
        advWordFile();
        char puLocName = input[0];
        Location puLoc;
        getLocationFromList(*listLoc, &puLoc, puLocName);
        advWordFile();
        char doLocName = input[0];
        Location doLoc;
        getLocationFromList(*listLoc, &doLoc, doLocName);
        advWordFile();
        char jenisItem = input[0];
        PendingPesanan pPesanan;
        if (jenisItem == 'P') {
            advWordFile();
            int waktuHangus = atoi(input);
            createPendingPesanan(&pPesanan, waktuMasuk, pCount, puLoc, doLoc, jenisItem, waktuHangus);
        } else {
            createPendingPesanan(&pPesanan, waktuMasuk, pCount, puLoc, doLoc, jenisItem, -99);
        }
        enqueueDaftarPesanan(daftarPesanan, pPesanan);
    }

    fclose(file);
}