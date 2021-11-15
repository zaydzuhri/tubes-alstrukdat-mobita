#include "bag.h"
#include "daftarpesanan.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "todolist.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int heavyItems, int speedBoostDur);

void pick_up(Bag bag, ToDoList tdlist, Location l, int *heavyItemsAmout);

void drop_off(Bag bag, Location l, int *heavyItemsAmount, int *uang, int speedBoostDur);