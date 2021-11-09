#ifndef LOCATION_H
#define LOCATION_H

#include "boolean.h"
#include "point.h"

typedef struct {
    char locName;
    POINT locPosition;
} Location;

/* ********* AKSES (Selektor) ********* */
/* Jika l adalah Location, maka akses elemen : */
#define LOC_NAME(l) (l).locName
#define LOC_POS(l) (l).locPosition
#define LOC_ROW(l) LOC_POS(l).Row
#define LOC_COL(l) LOC_POS(l).Col

void createLocation(Location *l, char lName, int row, int col);

boolean isSameLoc(Location l1, Location l2);

void displayLocation(Location loc);

#endif