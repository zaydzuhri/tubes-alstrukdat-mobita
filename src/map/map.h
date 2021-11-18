/** Filename: map.h **/

#ifndef MAP_H
#define MAP_H

#include "../listdinloc/listdinloc.h"
#include "../todolist/todolist.h"
#include "../pcolor/pcolor.h"
#include "../inprogresslist/inprogresslist.h"
#include "../listdinloc/listdinloc.h"
#include "../bag/bag.h"

void CreateMap(int mapRows, int mapCols, Matrix *M);
    /*  I.S. mapRows, mapCols, locL terdefinisi
        F.S. M membuat matrix kosong dengan batas 42 => (int) '*' dan berisi 32 => (int) ' ' */ 

void displayMap(int mapRows, int mapCols, ListLoc locL, Location curLoc, Matrix adjM, ToDoList todoL, Bag bag);
    /*  I.S. mapRows, mapCols, time, locL, curLoc, adjM, todoL, progL terdefinisi.
        F.S. Menuliskan peta  */

boolean isInTodolist(ToDoList L, char name);
    /*  mencari apakah pesanan name ada di L*/

#endif