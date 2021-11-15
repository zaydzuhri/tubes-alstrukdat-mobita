// Driver ADT DaftarPesanan
// Compile command : gcc -o mdaftarpesanan.exe mdaftarpesanan.c daftarpesanan.c pesanan.c queue.c location.c point.c


#include "daftarpesanan.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    DaftarPesanan dp1, dp2;
    // dp1 digunakan untuk menampung pesanan yang belum masuk to do list
    // dp2 digunakan untuk menampung pesanan yang sudah masuk to do list

    PendingPesanan pp1, pp2, pp3, pp4, ppTemp;
    Pesanan p3;
    Location lokasiA, lokasiB, lokasiC;
    int waktu;
    boolean allPpAtCurrentTimeInserted;

    /* ALGORITMA */

    // Buat daftar pesanan
    createDaftarPesanan(&dp1);
    createDaftarPesanan(&dp2);

    // Pembentukan Location
    createLocation(&lokasiA, 'A', 1, 3);
    createLocation(&lokasiB, 'B', 2, 4);
    createLocation(&lokasiC, 'C', 5, 6);

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

    // Simulasi proses pada daftar pesanan seiring berjalannya permainan
    // Misalnya permainan berjalan dari waktu = 1 sampai waktu = 9
    for (int waktu = 1; waktu < 10; waktu++) {
        printf("Waktu: %d\n", waktu);
        // Proses di bawah seharusnya dilaksanakan dengan fungsi timeUpdateToDoList yanga ada di ADT ToDoList
        allPpAtCurrentTimeInserted = false;
        while (!isDaftarPesananEmpty(dp1) && !allPpAtCurrentTimeInserted) {
            if (WAKTU_MASUK(HEAD(dp1)) == waktu) {
                dequeueDaftarPesanan(&dp1, &ppTemp);
                // PESANAN(ppTemp) dimasukan ke dalam to do list (tidak diimplementasikan di driver ini)
                enqueueDaftarPesanan(&dp2, ppTemp);
            }
            else {
                allPpAtCurrentTimeInserted = true;
            }
        }

        // Menunjukkan isi dp1
        printf("Isi dp1:\n");
        displayDaftarPesanan(dp1);
        printf("\n");

        // Menunjukkan isi dp2
        printf("Isi dp2:\n");
        displayDaftarPesanan(dp2);
        printf("\n");
    }

    // Misalkan pp3 telah masuk ke dalam to do list dan in progress list dalam rupa Pesanan p3
    p3 = PESANAN(pp3);
    // Mengambil waktu hangus awal dari p3 dan menampilkannya
    printf("Waktu hangus awal pesanan 3: %d", getOriginalWaktuHangus(dp2, p3));

}