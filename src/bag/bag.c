#include "bag.h"
#include "../boolean/boolean.h"

/* *** Konstruktor/Kreator *** */
void CreateBag(Bag *b) {
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah Bag b kosong dengan kondisi sbb: */
    /* - Index top bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah b kosong */
    IDX_TOP(*b) = IDX_UNDEF;
    max_Cap(*b) = 3;
}

/* ************ Prototype ************ */
boolean isBagEmpty(Bag b) {
    /* Mengirim true jika b kosong: lihat definisi di atas */
    return (IDX_TOP(b) == IDX_UNDEF);
}
boolean isBagFull(Bag b) {
    /* Mengirim true jika tabel penampung nilai b penuh */
    return (IDX_TOP(b) == max_Cap(b) - 1);
}

/* ************ Menambahkan kapasitas tas************ */
void increaseMaxCapacity(Bag *b) {
    max_Cap(*b)++;
}
/* I.S. Kapasitas maksimal dari tas terdefinisi*/
/* F.S. Kapasitas maksimal secara permanen bertambah 1*/

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushBag(Bag *b, ElTypeBag val) {
    /* Menambahkan val sebagai elemen Bag b */
    /* I.S. b mungkin kosong, tabel penampung elemen bag TIDAK penuh */
    /* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
    IDX_TOP(*b)++;
    TOP(*b) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void popBag(Bag *b, ElTypeBag *val) {
    /* Menghapus val dari  Bag b */
    /* I.S. b tidak mungkin kosong */
    /* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
    *val = TOP(*b);
    IDX_TOP(*b)--;
}

int bagCapacity(Bag b){
/* Mengirim kapasitas maksimal bag saat ini*/
    return max_Cap(b);
}

void reducePerishablesTimeBag(Bag *b, int reduction){
/* I.S. Bag b terdefinisi*/
/* F.S. Pesanan di dalam Bag b yang merupakan perishable item akan berkurang waktunya sebanyak reduction*/
    Bag tempBag;
    Pesanan tempPesanan;
    CreateBag(&tempBag);
    while(!isBagEmpty(*b)){
        popBag(b, &tempPesanan);
        if(JENIS_ITEM(tempPesanan)=='P'){
            WAKTU_HANGUS(tempPesanan) -= reduction;
        }
        pushBag(&tempBag, tempPesanan);
    }
    while(!isBagEmpty(tempBag)){
        popBag(&tempBag, &tempPesanan);
        pushBag(b, tempPesanan);
    }
}

void deletePerishablesFromBag(Bag *b){
    /* I.S. Bag b terdefinisi */
    /* F.S. Pesanan di Bag b yang berupa perishable item dan sudah habis waktunya akan hilang */
    Bag tempBag;
    while(!isBagEmpty(*b)){
        Pesanan tempPesanan;
        popBag(b, &tempPesanan);
        if(JENIS_ITEM(tempPesanan)!='P' || (JENIS_ITEM(tempPesanan)=='P' && WAKTU_HANGUS(tempPesanan)>0)){
            pushBag(&tempBag, tempPesanan);
        }  
    }
    while(!isBagEmpty(tempBag)){
        Pesanan tempPesanan;
        popBag(&tempBag, &tempPesanan);
        pushBag(b, tempPesanan);
    }
}