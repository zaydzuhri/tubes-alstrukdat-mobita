// Driver ADT LinkedList
// Compile command : gcc -o mlinkedlist.exe mlinkedlist.c linkedlist.c pesanan.c location.c point.c node.c

#include "linkedlist.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    Location lokasiA, lokasiB, lokasiC;
    Pesanan p1, p2, p3, p4, pTemp;
    LinkedList l;

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

    // Buat LinkedList
    createLinkedList(&l);

    // Cek apakah LinkedList kosong
    printf("Apakah LinkedList kosong? : ");
    if (isLinkedListEmpty(l)) {
        printf("LinkedList kosong\n");
    }
    else {
        printf("LinkedList tidak kosong\n");
    }

    printf("\n");

    // Simulasi insert
    // Urutan akhir seharusnya p3, p1, p2, p4
    insertFirstLinkedList(&l, p1);
    insertLastLinkedList(&l, p2);
    insertFirstLinkedList(&l, p3);
    insertLastLinkedList(&l, p4);

    printf("Hasil insert: \n");
    displayLinkedList(l);

    // Cek apakah LinkedList kosong
    printf("Apakah LinkedList kosong? : ");
    if (isLinkedListEmpty(l)) {
        printf("LinkedList kosong\n");
    }
    else {
        printf("LinkedList tidak kosong\n");
    }

    printf("\n");

    // index of
    printf("Index pp1: %d\n", indexOfLinkedList(l, p1));
    printf("\n");

    // Simulasi delete
    printf("Hasil delete elemen pertama: \n");
    deleteFirstLinkedList(&l, &pTemp);
    displayLinkedList(l);
    printf("\n");

    printf("Hasil delete elemen dengan index 1: \n");
    deleteAtLinkedList(&l, 1, &pTemp);
    displayLinkedList(l);
    printf("\n");
}