// Driver ADT InProgressList

#include "inprogresslist.h"

int main() {
    /* KAMUS */
    InProgressList ipl;
    Location lokasiA, lokasiB, lokasiC;
    Pesanan p1, p2, p3, p4;

    /* ALGORITMA */

    // Pembentukan Location
    createLocation(&lokasiA, 'A', 1, 3);
    createLocation(&lokasiB, 'B', 2, 4);
    createLocation(&lokasiC, 'C', 5, 6);

    // Buat elemen Pesanan
    createPesanan(&p1, 1, lokasiA, lokasiB, 'N', -99);
    createPesanan(&p2, 2, lokasiB, lokasiC, 'H', -99);
    createPesanan(&p3, 3, lokasiC, lokasiA, 'P', 5);
    createPesanan(&p4, 4, lokasiA, lokasiB, 'N', -99);

    // Buat In Progress List
    createInProgressList(&ipl);

    // Simulasi proses pada ToDoList seiring berjalannya permainan
    // Misalnya permainan berjalan dari waktu = 1 sampai waktu = 9
    // Diasumsikan pada waktu = 1,  p1,p2,p3,p4 masuk ke In Progress List
    // Waktu = 2, p1 di-drop off
    // Waktu = 3, p3 diubah waktu hangusnya menjadi 5
    // Waktu = 4, p2 di-drop off
    for (int waktu = 1; waktu < 10; waktu++) {
        printf("Waktu: %d\n", waktu);

        // Mengurangi waktu hangus setiap perishable item di In Progress List sebanyak 1
        reduceAllPerishablesTime(&ipl, 1);

        // Menghapus seluruh perishable item di In Progress List yang waktu hangusnya mencapai 0
        removeExpiredPerishables(&ipl);

        if (waktu == 1) {
            // Isi In Progress List
            AddToInProgressList(&ipl, p1);
            AddToInProgressList(&ipl, p2);
            AddToInProgressList(&ipl, p3);
            AddToInProgressList(&ipl, p4);
        }
        else if (waktu == 2) {
            // p1 di-drop off
            removeFromInProgressList(&ipl, p1);
        }
        else if (waktu == 3) {
            // p3 diubah waktu hangusnya menjadi 5
            changePerishableTime(&ipl, p3, 5);
        }
        else if (waktu == 4) {
            // p2 di-drop off
            removeFromInProgressList(&ipl, p2);
        }
        
        displayInProgressList(ipl);

        printf("\n");
    }
}