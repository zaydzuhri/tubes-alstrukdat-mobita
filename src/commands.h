#include "bag.h"
#include "daftarpesanan.h"
#include "inprogresslist.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "time.h"
#include "todolist.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int heavyItems, int *speedBoostDur, int *time, InProgressList *inProgress);

void pick_up(Bag *bag, ToDoList *tdlist, InProgressList *inplist, Location l, int *heavyItemsAmout);

void drop_off(Bag *bag, Location l, InProgressList *inProgress, int *heavyItemsAmount, int *uang, int *speedBoostDur);