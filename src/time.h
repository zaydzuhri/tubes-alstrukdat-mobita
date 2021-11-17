/* File : time.h */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"
#include "inprogresslist.h"
#include "bag.h"

void addTime(int *time, int *speedBoostCount, int heavy, InProgressList *inProgress, Bag *b);
/*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
*/

#endif
