/* File : daftarpesanan.h */
/* Definisi ADT DaftarPesanan dengan memanfaatkan ADT Queue */

#ifndef DAFTARPESANAN_H
#define DAFTARPESANAN_H

#include "queue.h"

typedef Queue DaftarPesanan;


void createDaftarPesanan(DaftarPesanan *dp);
/* I.S. dp sembarang */
/* F.S. dp berupa queue kosong */

void enqueueDaftarPesanan(DaftarPesanan *dp, PendingPesanan p);
/* I.S. DaftarPesanan dp terdefinisi */
/* F.S. PendingPesanan p ditambahkan ke dp sesuai dengan urutan waktu masuknya */
/* Elemen pada dp terurut dari yang waktu masuknya paling kecil ke yang paling besar */ 
    
void dequeueDaftarPesanan(DaftarPesanan *dp, PendingPesanan *p);
/* I.S. DaftarPesanan dp terdefinisi dan tidak kosong */
/* F.S. Elemen paling depan pada dp dihapus, p menjadi nilai elemen yang dihapus */

int getOriginalWaktuHangus(DaftarPesanan dp, Pesanan p);
/* Mengembalikan waktuHangus awal Pesanan p yang datanya tersimpan pada DaftarPesanan dp */
/* Prekondisi: data Pesanan p selalu ada di dp */

#endif