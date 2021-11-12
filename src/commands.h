#include "daftarpesanan.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "wordmachine.h"
#include "bag.h"
#include "todolist.h"
#include <stdio.h>
#include <stdlib.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int *time, int heavyItems, boolean isSpeedBoost, int speedBoostCount);

void pick_up(Bag bag, ToDoList tdlist, Location l, int *heavyItemsAmout);

void drop_off();