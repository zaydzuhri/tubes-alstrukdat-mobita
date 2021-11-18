/*Driver ADT Bag*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bag.h"
#include "../pesanan/pesanan.h"

int main(){
    Pesanan pesanan1, pesanan2, pesanan3, curPesanan;
    Location lokasiA, lokasiB, lokasiC;
    Bag b;

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

    CreateBag(&b);
    printf("Apakah Bag kosong? \n");
    if(isBagEmpty(b)){
        printf("yes\n");
    }else{printf("no\n");}
    printf("\nMemasukkan pesanan 1, 2, 3 ke dalam tas...\n");
    pushBag(&b, pesanan1);
    pushBag(&b, pesanan2);
    pushBag(&b, pesanan3);
    sleep(2);
    printf("Apakah bag penuh? \n");
    if(isBagFull(b)){
        printf("yes\n");
    }else{printf("no\n");}
    printf("\nMeningkatkan kapasitas tas...\n");
    increaseMaxCapacity(&b);
    printf("Kapasitas tas saat ini : %d", bagCapacity(b));
    sleep(1);
    printf("Apakah bag penuh?\n");
    if(isBagFull(b)){
        printf("yes\n");
    }else{printf("no\n");}
    printf("\nMengeluarkan pesanan teratas...\n");
    popBag(&b, &curPesanan);
    displayPesanan(curPesanan);
    sleep(1);
    printf("Mengurangi waktu sebanyak 5\n");
    reducePerishablesTimeBag(&b, 5);
    printf("\nMenghapus item perishable yang sudah hangus");
    deletePerishablesFromBag(&b);
    printf("Mengeluarkan pesanan yang ada\n");
    while(!isBagEmpty(b)){
        popBag(&b, &curPesanan);
        displayPesanan(curPesanan);
        printf("\n");
    }

}