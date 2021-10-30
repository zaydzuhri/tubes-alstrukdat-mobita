#include "queue.h"
#include "boolean.h"
#include <stdio.h>

/* Kreator Elemen */
void createPendingPesanan(PendingPesanan *pp, int wm, int kp, Location pul, Location dol, char ji, int wh) {
    /* I.S. Pesanan p sembarang. wm, kp, pul, dol, ji, dan wh terdefinisi. */
    /* F.S. Pesanan p terdefinisi berdasarkan parameter prosedur */
    /* Jika jenis barang bukan perishable item, wh diset ke -99 */
    createPesanan(&PESANAN(*pp), kp, pul, dol, ji, wh);
    WAKTU_MASUK(*pp) = wm;
}

/* *** Kreator *** */
void createQueue(Queue *q) {
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q) {
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isQueueFull(Queue q) {
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    return IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1;
}

int queueLength(Queue q) {
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isQueueEmpty(q)) {
        return 0;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, PendingPesanan val) {
    /* Proses: Menambahkan val pada q dengan aturan FIFO berdasarkan prioritas waktuMasuk */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    // KAMUS LOKAL
    int currentIdx;
    PendingPesanan tempVal;
    boolean positionFound;

    // ALGORITMA
    if (isQueueEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        // Pergeseran
        if (IDX_TAIL(*q) == CAPACITY - 1) {
            for (int i = 0; i <= IDX_TAIL(*q) - IDX_HEAD(*q); i++) {
                (*q).buffer[i] = (*q).buffer[i + IDX_HEAD(*q)];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }

        // Pencarian posisi untuk val baru
        currentIdx = IDX_TAIL(*q) + 1;
        positionFound = false;

        while (!positionFound && currentIdx != IDX_HEAD(*q)) {
            if (WAKTU_MASUK((*q).buffer[currentIdx - 1]) > WAKTU_MASUK(val)) {
                (*q).buffer[currentIdx] = (*q).buffer[currentIdx - 1];
                currentIdx--;
            } else {
                positionFound = true;
            }
        }

        // Memasukkan val baru
        (*q).buffer[currentIdx] = val;
        IDX_TAIL(*q)
        ++;
    }
}

void dequeue(Queue *q, PendingPesanan *val) {
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    *val = HEAD(*q);

    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)
        ++;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
    /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */

    //....................
    if (isQueueEmpty(q)) {
        printf("[]");
    } else {
        printf("[");
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            if (i != IDX_TAIL(q)) {
                printf("%d,", (q).buffer[i]);
            } else {
                printf("%d", (q).buffer[i]);
            }
        }
        printf("]");
    }
}