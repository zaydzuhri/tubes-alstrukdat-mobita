/* File : time.h */

#ifndef TIME_H
#define TIME_H

#include "../boolean/boolean.h"
#include "../inprogresslist/inprogresslist.h"
#include "../bag/bag.h"

void addTime(int *time, int *speedBoostCount, int heavy, InProgressList *inProgress, Bag *b);
/*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
*/

#endif
