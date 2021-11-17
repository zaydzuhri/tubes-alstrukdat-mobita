// Driver ADT Queue

#include "queue.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    PendingPesanan pp1, pp2, pp3, ppTemp;
    Location lokasiA, lokasiB, lokasiC;
    Queue q;

    /* ALGORITMA */

    // Pembentukan Location
    createLocation(&lokasiA, 'A', 1, 3);
    createLocation(&lokasiB, 'B', 2, 4);
    createLocation(&lokasiC, 'C', 5, 6);

    // Buat elemen PendingPesanan
    createPendingPesanan(&pp1, 5, 1, lokasiA, lokasiB, 'N', -99);
    createPendingPesanan(&pp2, 2, 2, lokasiB, lokasiC, 'H', -99);
    createPendingPesanan(&pp3, 3, 3, lokasiC, lokasiA, 'P', 5);

    // Buat Queue
    createQueue(&q);
    printf("Queue setelah dibentuk:\n");
    displayQueue(q);
    printf("\n");

    // Cek apakah Queue kosong
    printf("Apakah Queue kosong? : ");
    if (isQueueEmpty(q)) {
        printf("Queue kosong\n");
    }
    else {
        printf("Queue tidak kosong\n");
    }

    printf("\n");

    // Simulasi enqueue berdasarkan prioritas waktu masuk
    printf("Enqueue 1: \n");
    enqueue(&q, pp1);
    displayQueue(q);
    printf("\n");

    // pp2 seharusnya masuk ke urutan depan karena waktu masuknya lebih kecil dari pp1
    printf("Enqueue 2: \n");
    enqueue(&q, pp2);
    displayQueue(q);
    printf("\n");

    printf("Enqueue 3: \n");
    enqueue(&q, pp3);
    displayQueue(q);
    printf("\n");

    // Cek apakah Queue kosong
    printf("Apakah Queue kosong? : ");
    if (isQueueEmpty(q)) {
        printf("Queue kosong\n");
    }
    else {
        printf("Queue tidak kosong\n");
    }

    // Simulasi dequeue
    printf("Dequeue 1: \n");
    dequeue(&q, &ppTemp);
    displayQueue(q);
    printf("\n");
    
    printf("Dequeue 2: \n");
    dequeue(&q, &ppTemp);
    displayQueue(q);
}