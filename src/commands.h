#include "daftarpesanan.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int *time, int heavyItems, boolean isSpeedBoost, int speedBoostCount);