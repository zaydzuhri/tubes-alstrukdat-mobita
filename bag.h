/* File : bag.h */
/* Definisi bag dengan ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef BAG_H
#define BAG_H

#include "boolean.h"
#include "pesanan.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef Pesanan ElType;
typedef struct {
  ElType buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
} Bag;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(b) (b).idxTop
#define     TOP(b) (b).buffer[(b).idxTop]

/* *** Konstruktor/Kreator *** */
void CreateBag(Bag *b);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Bag b kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah b kosong */

/* ************ Prototype ************ */
boolean isBagEmpty(Bag b);
/* Mengirim true jika b kosong: lihat definisi di atas */
boolean isBagFull(Bag b);
/* Mengirim true jika tabel penampung nilai b penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushBag(Bag *b, ElType val);
/* Menambahkan val sebagai elemen Bag b */
/* I.S. b mungkin kosong, tabel penampung elemen bag TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popBag(Bag *b, ElType *val);
/* Menghapus val dari  Bag b */
/* I.S. b tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

#endif