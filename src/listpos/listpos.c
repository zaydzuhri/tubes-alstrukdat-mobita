#include<stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas LISTPOS_CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for(i=0; i<LISTPOS_CAPACITY; i++){
        ELMTListPos(*l,i) = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPos(ListPos l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS */
    int len, i;
    boolean isMarkFound;
    /* ALGORTIMA */
    len = 0;
    i = 0;
    isMarkFound = false;
    for(i=0; i<LISTPOS_CAPACITY; i++){
        if(ELMTListPos(l,i) != VAL_UNDEF){
            len++;
        }
    }

    return len;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListPos(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */
    /* ALGORITMA */
    return i >= 0 && i < LISTPOS_CAPACITY;
}

boolean isIdxEffListPos(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    /* KAMUS */
    /* ALGORITMA */
    return ELMTListPos(l,i) != VAL_UNDEF;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListPos(ListPos l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* KAMUS */
    /* ALGORITMA */
    return lengthListPos(l) == 0;
}
/* *** Test List penuh *** */
boolean isFullListPos(ListPos l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* KAMUS */
    /* ALGORITMA */
    return lengthListPos(l) == LISTPOS_CAPACITY;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListPos(ListPos l, ElTypeListPos val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int len, i;
    boolean isFound = false;
    /* ALGORITMA */
    len = lengthListPos(l);
    i = 0;
    while (i<len && !isFound){
        isFound = ELMTListPos(l,i) == val;
        i++;
    }
    if (isFound) return i-1;
    else return IDX_UNDEF;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertListPos(ListPos *l, ElTypeListPos val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = 0;
    while(ELMTListPos(*l,i) != VAL_UNDEF){
        i++;
    }
    ELMTListPos(*l,i) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteAtListPos(ListPos *l, ElTypeListPos *val, int idx){
/* Proses : Menghapus elemen dengan indeks idx */
/* I.S. List tidak kosong, idx merupakan indeks yang tedefinisi untuk l */
/* F.S. val adalah nilai elemen yang dihapus */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = idx;
    *val = ELMTListPos(*l, idx);
    ELMTListPos(*l,i) = VAL_UNDEF;
}