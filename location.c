#include "location.h"
#include "boolean.h"
#include "point.h"

void createLocation(Location *l, char lName, int row, int col) {
    LOC_NAME(*l) = lName;
    POINT p = MakePOINT(row, col);
    LOC_POS(*l) = p;
}

boolean isSameLoc(Location l1, Location l2) {
    return LOC_NAME(l1) == LOC_NAME(l2) && EQ(LOC_POS(l1), LOC_POS(l2));
}