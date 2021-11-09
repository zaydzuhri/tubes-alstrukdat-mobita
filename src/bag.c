#include "boolean.h"
#include "bag.h"

/* *** Konstruktor/Kreator *** */
void CreateBag(Bag *b){
/* I.S. sembarang; */
/* F.S. Membuat sebuah Bag b kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah b kosong */
    IDX_TOP(*b) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isBagEmpty(Bag b){
/* Mengirim true jika b kosong: lihat definisi di atas */
    return (IDX_TOP(b) == IDX_UNDEF);
}
boolean isBagFull(Bag b){
/* Mengirim true jika tabel penampung nilai b penuh */
    return (IDX_TOP(b) == CAPACITY-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushBag(Bag *b, ElType val){
/* Menambahkan val sebagai elemen Bag b */
/* I.S. b mungkin kosong, tabel penampung elemen bag TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
    IDX_TOP(*b)++;
    TOP(*b) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void popBag(Bag *b, ElType *val){
/* Menghapus val dari  Bag b */
/* I.S. b tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
    *val = TOP(*b);
    IDX_TOP(*b)--;
}