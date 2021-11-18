/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean/boolean.h"
#include "../location/location.h"
#include "../pesanan/pesanan.h"

#ifndef IDX_UNDEF
#define IDX_UNDEF -1
#endif

#define QUEUE_CAPACITY 30

/* Definisi elemen dan address */
typedef struct {
    int waktuMasuk;
    Pesanan pesanan;
} PendingPesanan;

typedef struct {
    PendingPesanan buffer[QUEUE_CAPACITY];
    int idxHead;
    int idxTail;
} Queue;

/* ********* AKSES PendingPesanan (Selektor) ********* */
/* Jika p adalah PendingPesanan, maka akses elemen : */
#define WAKTU_MASUK(p) (p).waktuMasuk
#define PESANAN(p) (p).pesanan

/* ********* AKSES Queue (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* Kreator Elemen */
void createPendingPesanan(PendingPesanan *pp, int waktuMasuk, int kodePesanan, Location pickUpLocation, Location dropOffLocation, char jenisItem, int waktuHangus);
/* I.S. PendingPesanan pp sembarang. waktuMasuk, kodePesanan, pickUpLocation, dropOffLocation, jenisItem, dan waktuHangus terdefinisi. */
/* F.S. PendingPesanan pp terdefinisi berdasarkan parameter prosedur */
/* Jika jenis barang bukan perishable item, waktuHangus diset ke -99 */

/* *** Kreator *** */
void createQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, PendingPesanan val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, PendingPesanan *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong tampilkan isi queue ke layar */
/* Jika Queue kosong : tampilkan pesan "Kosong" */

#endif