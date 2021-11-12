/* File : time.h */

#ifndef TIME_H
#define TIME_H

#include "inprogresslist.h"
#include "boolean.h"

int addTime(InProgressList L, int speedBoostCount,boolean *isSpeedBoost);
/*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
*/

#endif
    