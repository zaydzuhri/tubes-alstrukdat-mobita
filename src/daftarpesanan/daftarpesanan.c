#include "daftarpesanan.h"

void createDaftarPesanan(DaftarPesanan *dp) {
/* I.S. dp sembarang */
/* F.S. dp berupa queue kosong */
    createQueue(dp);
}

boolean isDaftarPesananEmpty(DaftarPesanan dp) {
/* Mengembalikan nilai true jika DaftarPesanan dp kosong, mengembalikan false jika tidak kosong */
    return isQueueEmpty(dp);
}

void enqueueDaftarPesanan(DaftarPesanan *dp, PendingPesanan p) {
/* I.S. DaftarPesanan dp terdefinisi */
/* F.S. PendingPesanan p ditambahkan ke dp sesuai dengan urutan waktu masuknya */
/* Elemen pada dp terurut dari yang waktu masuknya paling kecil ke yang paling besar */
    enqueue(dp, p);
}

void dequeueDaftarPesanan(DaftarPesanan *dp, PendingPesanan *p) {
/* I.S. DaftarPesanan dp terdefinisi dan tidak kosong */
/* F.S. Elemen paling depan pada dp dihapus, p menjadi nilai elemen yang dihapus */
    dequeue(dp, p);
}

int getOriginalWaktuHangus(DaftarPesanan dp, Pesanan p) {
/* Mengembalikan waktuHangus awal Pesanan p yang datanya tersimpan pada DaftarPesanan dp */
/* Prekondisi: data Pesanan p selalu ada di dp. p merupakan item perishable. */
    /* KAMUS LOKAL */
    PendingPesanan pp;

    /* ALGORITMA */
    do {
        dequeueDaftarPesanan(&dp, &pp);
    } while (KODE_PESANAN(PESANAN(pp)) != KODE_PESANAN(p));

    return WAKTU_HANGUS(PESANAN(pp));
}

void displayDaftarPesanan(DaftarPesanan dp) {
/* I.S. DaftarPesanan dp terdefinisi */
/* F.S. Isi dari DaftarPesanan dp ditampilkan ke layar */
    displayQueue(dp);
}