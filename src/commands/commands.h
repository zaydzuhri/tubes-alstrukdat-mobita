#include "../bag/bag.h"
#include "../daftarpesanan/daftarpesanan.h"
#include "../inprogresslist/inprogresslist.h"
#include "../listdinloc/listdinloc.h"
#include "../matrix/matrix.h"
#include "../queue/queue.h"
#include "../time/time.h"
#include "../todolist/todolist.h"
#include "../wordmachine/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int heavyItems, int *speedBoostDur, int *time, InProgressList *inProgress, Bag *bag);

void pick_up(Bag *bag, ToDoList *tdlist, InProgressList *inplist, Location l, int *heavyItemsAmout);

void drop_off(Bag *bag, Location l, InProgressList *inProgress, int *heavyItemsAmount, int *uang, int *speedBoostDur, int *amountDropped);

void help();