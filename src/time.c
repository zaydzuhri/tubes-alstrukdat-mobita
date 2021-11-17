#include "time.h"

void addTime(int *time, int *speedBoostDur, int heavy, InProgressList *inProgress, Bag *b) {
    /*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
    */
    /* KAMUS */
    Address P;

    /* ALGORITMA */
    /* Mengembalikan Tambahan Waktu */
    if (heavy > 0) {
        *speedBoostDur = 0;
        *time += 1 + heavy;
        reduceAllPerishablesTime(inProgress, 1 + heavy);
        reducePersihablesTimeBag(b, 1+heavy);
        deletePershablesFromBag(b);
    } else {
        if (*speedBoostDur > 0) {
            *time += ((*speedBoostDur % 2 == 1) ? 1 : 0);
            reduceAllPerishablesTime(inProgress, ((*speedBoostDur % 2 == 1) ? 1 : 0));
            reducePersihablesTimeBag(b, ((*speedBoostDur % 2 == 1) ? 1 : 0));
            deletePershablesFromBag(b);
            *speedBoostDur -= 1;
        } else {
            *time += 1;
            reduceAllPerishablesTime(inProgress, 1);
            reducePersihablesTimeBag(b, 1);
            deletePershablesFromBag(b);
        }
    }
};
