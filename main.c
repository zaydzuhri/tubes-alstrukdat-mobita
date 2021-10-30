#include "config.h"
#include "daftarpesanan.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListLoc locList;
    Matrix adjMatrix;
    DaftarPesanan dafPesanan;
    int mapRows = 0;
    int mapCols = 0;

    CreateListLoc(&locList, 30);
    createQueue(&dafPesanan);
    readConfig("config.txt", &locList, &mapRows, &mapCols, &adjMatrix, &dafPesanan);

    return 0;
}