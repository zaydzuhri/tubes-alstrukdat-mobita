/* File : time.h */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"
#include "inprogresslist.h"

void addTime(int *time, int *speedBoostCount, int heavy, InProgressList *inProgress);
/*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
*/

#endif
