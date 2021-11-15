#include "time.h"

int addTime(int speedBoostDur, int heavy) {
    /*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
    */
    /* KAMUS */
    Address P;

    /* ALGORITMA */
    /* Mengembalikan Tambahan Waktu */
    if (heavy > 0) {
        speedBoostDur = 0;
        return (1 + heavy);
    } 
    else {
        if (speedBoostDur > 0) {
            speedBoostDur -= 1;
            return(0.5);
        } else {
            return 1;
        }
    }
};
