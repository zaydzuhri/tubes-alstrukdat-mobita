/** Filename: map.c **/

#include "map.h"
#include <stdio.h>

void CreateMap(int mapRows, int mapCols, Matrix *M) {
    /*  I.S. mapRows, mapCols, locL terdefinisi
        F.S. M membuat matrix kosong dengan batas 42 => (int) '*' */ 
    /* KAMUS */
    int i,j;
    /* Algoritma */
    CreateMatrix(mapRows+2, mapCols+2, M);
    ROWS(*M) = mapRows+2;
    COLS(*M) = mapCols+2;
    
    for (i = 0; i < ROWS(*M); i++) {
        for (j = 0; j < COLS(*M); j++) {
            if (i == 0 || i == ROWS(*M) - 1 || j == 0 || j == COLS(*M) - 1) {
                ELMT(*M, i, j) = (int) '*';
            }
            else {
                ELMT(*M, i, j) = (int) ' ';
            }
        }
    }
};

void displayMap(int mapRows, int mapCols, ListLoc locL, Location curLoc, Matrix adjM, ToDoList todoL, InProgressList progL) {
    /*  I.S. mapRows, mapCols, time, locL, curLoc, adjM, todoL, progL terdefinisi.
    F.S. Menuliskan peta  */
    /* KAMUS */
    Matrix M;
    int i, j, k; 
    ListLoc adjLocList;
    Address p;
    /* Algoritma */

    CreateMap(mapRows, mapCols, &M);
    CreateListLoc(&adjLocList, 30);
    getAdjacentLocations(adjM, locL, &adjLocList, curLoc);

    for (i = 0; i < NEFF(locL); i++) {
        ELMT(M, 1+LOC_ROW(LOC(locL,i)),1+LOC_COL(LOC(locL,i))) = (int) LOC_NAME(LOC(locL,i));
    }
    
    for (i = 0; i < ROWS(M); i++) {
        for (j = 0; j < COLS(M); j++) {
            // print hijau untuk destination dari current location
            for (k = 0; k < NEFF(adjLocList); k++) {
                if (ELMT(M,i,j) == (int) LOC_NAME(LOC(adjLocList,k))) {
                    print_green((char) ELMT(M,i,j));
                }
            }

            // print merah untuk tempat pickup location
            p = FIRST(todoL);
            while (p != NULL) {
                if ((int) LOC_NAME(PICK_UP_LOCATION(INFO(p))) == ELMT(M,i,j)) {
                    print_red((char) ELMT(M,i,j));
                }
            }

            // print orange untuk current location
            if (ELMT(M,i,j) == (int) LOC_NAME(curLoc)) {
                print_yellow((char) ELMT(M,i,j));
            }

            // print biru untuk tempat drop off item teratas
            else if ((int) LOC_NAME(DROP_OFF_LOCATION(INFO(FIRST(progL)))) == ELMT(M,i,j)) {
                print_blue((char) ELMT(M,i,j));
            }

            // print hitam untuk lainya
            else {
                printf("%c", (char) ELMT(M,i,j));
            }
        }
        printf("\n");
    }
    printf("\n");
};
