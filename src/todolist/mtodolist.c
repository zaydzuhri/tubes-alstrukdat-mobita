// Driver ADT ToDoList

#include "todolist.h"

int main() {
    /* KAMUS */
    DaftarPesanan dp1, dp2;
    // dp1 digunakan untuk menampung pesanan yang belum masuk to do list
    // dp2 digunakan untuk menampung pesanan yang sudah masuk to do list

    ToDoList tdl;
    PendingPesanan pp1, pp2, pp3, pp4, ppTemp;
    Pesanan p;
    Location lokasiA, lokasiB, lokasiC;
    boolean pickUpSuccess;
    int waktu;

    /* ALGORITMA */

    // Pembentukan Location
    createLocation(&lokasiA, 'A', 1, 3);
    createLocation(&lokasiB, 'B', 2, 4);
    createLocation(&lokasiC, 'C', 5, 6);

    // SET UP DAFTAR PESANAN 
    // Buat daftar pesanan
    createDaftarPesanan(&dp1);
    createDaftarPesanan(&dp2);

    // Buat elemen PendingPesanan
    createPendingPesanan(&pp1, 5, 1, lokasiA, lokasiB, 'N', -99);
    createPendingPesanan(&pp2, 2, 2, lokasiB, lokasiC, 'H', -99);
    createPendingPesanan(&pp3, 3, 3, lokasiC, lokasiA, 'P', 5);
    createPendingPesanan(&pp4, 2, 4, lokasiA, lokasiB, 'N', -99);

    // Simulasi set up daftar pesanan di awal permainan
    enqueueDaftarPesanan(&dp1, pp1);
    enqueueDaftarPesanan(&dp1, pp2);
    enqueueDaftarPesanan(&dp1, pp3);
    enqueueDaftarPesanan(&dp1, pp4);

    // Buat To Do List
    createToDoList(&tdl);

    // Simulasi proses pada ToDoList seiring berjalannya permainan
    // Misalnya permainan berjalan dari waktu = 1 sampai waktu = 9
    for (int waktu = 1; waktu < 10; waktu++) {
        printf("Waktu: %d\n", waktu);
        timeUpdateToDoList(&tdl, &dp1, &dp2, waktu);
        displayToDoList(tdl);
    }

    printf("\n");

    // Misalkan pemain sedang ada di lokasiB dan melakukan pick up
    // Expected outcome : pesanan 2 di pick up
    printf("Pemain melakukan pick up di lokasi B\n");
    pickUpUpdateToDoList(&tdl, lokasiB, &p, &pickUpSuccess);
    if (pickUpSuccess) {
        printf("Pesanan yang di pick-up: \n");
        displayPesanan(p);
    }
    else {
        printf("Tidak ada pesanan yang bisa di pick-up\n");
    }
    printf("\n");
    displayToDoList(tdl);

    printf("\n");

    // Misalkan pemain sedang ada di lokasiB dan melakukan pick up
    // Expected outcome : Tidak ada pesanan yang di pick-up
    printf("Pemain melakukan pick up di lokasi B\n");
    pickUpUpdateToDoList(&tdl, lokasiB, &p, &pickUpSuccess);
    if (pickUpSuccess) {
        printf("Pesanan yang di pick-up: \n");
        displayPesanan(p);
    }
    else {
        printf("Tidak ada pesanan yang bisa di pick-up\n");
    }
    printf("\n");
    displayToDoList(tdl);
}