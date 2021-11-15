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

boolean isInTodolist(ToDoList L, char name) {
    /*  mencari apakah pesanan name ada di L*/
    /* KAMUS */
    Address p;
    boolean found;
    /* ALGORITMA */
    found = false;
    p = FIRST(L);
    while (p != NULL && !found) {
        if (LOC_NAME(PICK_UP_LOCATION(INFO(p))) == name) {
            found = true;
        }
        p = NEXT(p);
    }
    return found;
};


void displayMap(int mapRows, int mapCols, ListLoc locL, Location curLoc, Matrix adjM, ToDoList todoL, Bag bag) {
    /*  I.S. mapRows, mapCols, locL, curLoc, adjM, todoL, progL terdefinisi.
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
        ELMT(M, LOC_ROW(LOC(locL,i)),LOC_COL(LOC(locL,i))) = (int) LOC_NAME(LOC(locL,i));
    }
    
    for (i = 0; i < ROWS(M); i++) {
        for (j = 0; j < COLS(M); j++) {

            if (ELMT(M,i,j) == (int) LOC_NAME(curLoc)) {
                print_yellow((char) ELMT(M,i,j));
            }

            else if (isInTodolist(todoL, (char) ELMT(M,i,j))) {
                print_red((char) ELMT(M,i,j));
            }

            else if (!isBagEmpty(bag) && (int) LOC_NAME(DROP_OFF_LOCATION(TOP(bag))) == ELMT(M,i,j)) {
                print_blue((char) ELMT(M,i,j));
            }

            else if (isInListLoc(adjLocList, (char) ELMT(M,i,j))){
                print_green((char) ELMT(M,i,j));
            }

            else {
                printf("%c", (char) ELMT(M,i,j));
            }
        }
        printf("\n");
    }
    printf("\n");
};
