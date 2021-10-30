#include "daftarpesanan.h"

void createDaftarPesanan(DaftarPesanan *dp) {
    /* I.S. dp sembarang */
    /* F.S. dp berupa queue kosong */
    createQueue(dp);
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
    PendingPesanan pp;
    while (!isQueueEmpty(dp) && KODE_PESANAN(PESANAN(HEAD(dp))) != KODE_PESANAN(p)) {
        dequeueDaftarPesanan(&dp, &pp);
    }

    return WAKTU_HANGUS(PESANAN(pp));
}