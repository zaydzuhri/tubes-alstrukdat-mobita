#include "linkedlist.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void createLinkedList(LinkedList *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isLinkedListEmpty(LinkedList l){
/* Mengirim true jika list kosong */
    return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
Pesanan getLinkedListElmt(LinkedList l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */ 
    p = FIRST(l);
    for (int i = 0; i < idx; i++) {
        p = NEXT(p);
    }
    return INFO(p);
}

void setLinkedListElmt(LinkedList *l, int idx, Pesanan val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = FIRST(*l);
    for (int i = 0; i < idx; i++) {
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOfLinkedList(LinkedList l, Pesanan val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    /* KAMUS LOKAL */
    Address p;
    int idx;
    boolean elmtFound;

    /* ALGORITMA */

    if (isLinkedListEmpty(l)) {
        return IDX_UNDEF;
    }
    else {
        p = FIRST(l);
        idx = 0;
        elmtFound = false;

        do {
            if (KODE_PESANAN(INFO(p)) == KODE_PESANAN(val)) {
                elmtFound = true;
            }
            else {
                idx++;
                p = NEXT(p);
            }
        } while (p != NULL && !elmtFound);

        if (elmtFound) {
            return idx;
        }
        else {
            return IDX_UNDEF;
        }
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstLinkedList(LinkedList *l, Pesanan val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLastLinkedList(LinkedList *l, Pesanan val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p, last;

    /* ALGORITMA */
    if (isLinkedListEmpty(*l)) {
        insertFirstLinkedList(l, val);
    }
    else {
        p = newNode(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAtLinkedList(LinkedList *l, Pesanan val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p, loc;

    /* ALGORITMA */
    if (idx == 0) {
        insertFirstLinkedList(l, val);
    }
    else {
        p = newNode(val);
        if (p != NULL) {
            loc = FIRST(*l);
            for (int i = 0; i < idx - 1; i++) {
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstLinkedList(LinkedList *l, Pesanan *val){
/* I.S. LinkedList l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLastLinkedList(LinkedList *l, Pesanan *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS LOKAL */
    Address p, last;

    /* ALGORITMA */
    p = FIRST(*l);
    last = NULL;

    while (NEXT(p) != NULL) {
        last = p;
        p = NEXT(p);
    }

    if (last == NULL) {
        deleteFirstLinkedList(l, val);
    }
    else {
        *val = INFO(p);
        NEXT(last) = NULL;
    }
    
    free(p);
}

void deleteAtLinkedList(LinkedList *l, int idx, Pesanan *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS LOKAL */
    int i;
    Address p, loc;

    /* ALGORITMA */
    if (idx == 0) {
        deleteFirstLinkedList(l, val);
    }
    else {
        i = 0;
        loc = FIRST(*l);
        while (i < idx - 1) {
            i++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
    
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayLinkedList(LinkedList l){
// void printInfo(LinkedList l);
/* I.S. LinkedList mungkin kosong */
/* F.S. Jika list tidak kosong, ditampilkan atribut-atribut elemen pesanan */
/* Jika list kosong : menulis "List kosong" */
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = FIRST(l);

    if (p == NULL) {
        printf("List kosong");
    }
    else {
        do {
            displayPesanan(INFO(p));
            printf("\n");
            p = NEXT(p);
        } while (p != NULL);
    }
}

int linkedListLength(LinkedList l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS LOKAL */
    int len;
    Address p;

    /* ALGORITMA */
    len = 0;
    p = FIRST(l);

    while (p != NULL) {
        len++;
        p = NEXT(p);
    }

    return len;
}

/****************** PROSES TERHADAP LIST ******************/
LinkedList concatLinkedList(LinkedList l1, LinkedList l2){
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    /* KAMUS LOKAL */
    Address p;
    LinkedList l3;

    /* ALGORITMA */
    createLinkedList(&l3);
    p = FIRST(l1);
    while (p != NULL) {
        insertLastLinkedList(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLastLinkedList(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}