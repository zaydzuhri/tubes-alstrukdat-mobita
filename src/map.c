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

void displayMap(int mapRows, int mapCols, int time, ListLoc locL, Location curLoc, Matrix adjM, ToDoList todoL, InProgressList progL) {
    /*  I.S. mapRows, mapCols, time, locL, curLoc, adjM, todoL, progL terdefinisi.
    F.S. Menuliskan peta  */
    /* KAMUS */
    Matrix M;
    int i, j, k,l, ctr; 
    ListLoc dest;
    Address p;
    /* Algoritma */
    CreateMap(mapRows, mapCols, &M);
    CreateListLoc(&dest, NEFF(locL));

    ctr = 0;
    while (LOC_NAME(LOC(locL,ctr)) != LOC_NAME(curLoc)) {
        ctr++;
    }

    for (i = 0; i < NEFF(locL); i++) {
        ELMT(M, 1+LOC_ROW(LOC(locL,i)),1+LOC_COL(LOC(locL,i))) = (int) LOC_NAME(LOC(locL,i));
        if (ELMT(adjM, ctr, i) == 1) {
            insertLastListLoc(&dest, LOC(locL,i));
        }
    } 

    for (i = 1; i < ROWS(M) - 1; i++) {
        for (j = 1; j < COLS(M) - 1; j++) {
            for (k = 0; k < NEFF(dest); k++) {
                p = FIRST(todoL);
                while (p != NULL) {
                    if (ELMT(M,i,j) == (int) LOC_NAME(curLoc)) {
                        print_yellow((char) ELMT(M,i,j));
                    }
                    else if (KODE_PESANAN(INFO(p)) >= time && (int) LOC_NAME(PICK_UP_LOCATION(INFO(p))) == ELMT(M,i,j)) {
                        print_red((char) ELMT(M,i,j));
                    }
                    else if ((int) LOC_NAME(DROP_OFF_LOCATION(INFO(FIRST(progL)))) == ELMT(M,i,j)) {
                        print_blue((char) ELMT(M,i,j));
                    }
                    else if (ELMT(M,i,j) == (int) LOC_NAME(LOC(dest,k))) {
                        print_green((char) ELMT(M,i,j));
                    }
                    else {
                        printf("%c", (char) ELMT(M,i,j));
                    }
                }
            }
        }
        printf("\n");
    }
    printf("\n");

};