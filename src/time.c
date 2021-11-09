#include "time.h"

int addTime(InProgressList L, int speedBoostCount ,boolean *isSpeedBoost) {
    /*  Mengembalikan banyaknya tambahan waktu
    Tambahan waktu = 1
    setiap ada heavy item dalam inprogress list => Tambahan waktu += 1 
    */
    /* KAMUS */
    Address P;
    int Heavy;

    /* ALGORITMA */
    
    /* Algoritma Menghitung banyaknya Heavy Item(s)*/
    P = FIRST(L);
    Heavy = 0;

    while (P != NULL) {
        if (JENIS_ITEM(INFO(P)) == 'H') {
            Heavy += 1;
        }
    }

    /* Mengembalikan Tambahan Waktu */
    if (Heavy > 0) {
        *isSpeedBoost = false;
        return (1 + Heavy);
    } else {
        if (isSpeedBoost) {
            if (speedBoostCount % 2 == 1) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }
};
