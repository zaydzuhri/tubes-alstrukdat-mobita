/* Driver ADT Pesanan */

#include "pesanan.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    Pesanan pesanan1, pesanan2, pesanan3;
    Location lokasiA, lokasiB, lokasiC;

    /* ALGORITMA */
    
    // Pembentukan Location
    createLocation(&lokasiA, 'A', 1, 3);
    createLocation(&lokasiB, 'B', 2, 4);
    createLocation(&lokasiC, 'C', 5, 6);
    
    // Pembentukan pesanan1
    // pesanan1 memiliki atribut sebagai berikut :
        // Kode pesanan = 1
        // Lokasi pick up = lokasiA
        // Lokasi drop off = lokasiB
        // Jenis item = 'n'     (Normal item)
        // Jenis item bukan item perishable sehingga waktu hangus diset sembarang
    createPesanan(&pesanan1, 1, lokasiA, lokasiB, 'N', -99);
    printf("Pesanan 1:\n");
    displayPesanan(pesanan1);
    printf("\n");

    // Pembentukan pesanan2
    // pesanan2 memiliki atribut sebagai berikut :
        // Kode pesanan = 2
        // Lokasi pick up = lokasiB
        // Lokasi drop off = lokasiC
        // Jenis item = 'h'     (Heavy item)
        // Jenis item bukan item perishable sehingga waktu hangus diset sembarang
    createPesanan(&pesanan2, 2, lokasiB, lokasiC, 'H', -99);
    printf("Pesanan 2:\n");
    displayPesanan(pesanan2);
    printf("\n");

    // Pembentukan pesanan3
    // pesanan1 memiliki atribut sebagai berikut :
        // Kode pesanan = 3
        // Lokasi pick up = lokasiC
        // Lokasi drop off = lokasiA
        // Jenis item = 'p'     (Perishable item)
        // Waktu hangus = 5
    createPesanan(&pesanan3, 3, lokasiC, lokasiA, 'P', 5);
    printf("Pesanan 3:\n");
    displayPesanan(pesanan3);
    printf("\n");

    // Cek fungsi isPesananIdentical()
    printf("Pesanan 1 dan Pesanan 2 identik? ");
    if (isPesananIdentical(pesanan1, pesanan2)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    printf("Pesanan 3 dan Pesanan 3 identik? ");
    if (isPesananIdentical(pesanan3, pesanan3)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}