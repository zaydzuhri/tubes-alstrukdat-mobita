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
    while (!isMarkFound && len < LISTPOS_CAPACITY){
        if(ELMTListPos(l,i) == VAL_UNDEF){
            isMarkFound = true;
        }else{
            len++;
            i++;
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
    return i >= 0 && i < lengthListPos(l);
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

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListPos(ListPos *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= LISTPOS_CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= LISTPOS_CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    /* KAMUS */
    int num_of_elmt, i, input_number;
    /* ALGORITMA */
    do{
        scanf("%d",&num_of_elmt);
    } while (num_of_elmt <0 || num_of_elmt>LISTPOS_CAPACITY);

    CreateListPos(l);

    for(i = 0; i < num_of_elmt; i++){
        scanf("%d", &input_number);
        ELMTListPos(*l,i) = input_number;
    }
}
void displayListPos(ListPos l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("[");
    for(i = 0; i<lengthListPos(l); i++){
        printf("%d",ELMTListPos(l,i));
        if(i != lengthListPos(l)-1) printf(",");
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTabListPos(ListPos l1, ListPos l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    /* KAMUS */
    int i;
    ListPos l3;
    /* ALGORITMA */
    CreateListPos(&l3);
    for(i=0; i<lengthListPos(l1); i++){
        if(plus) ELMTListPos(l3,i) = ELMTListPos(l1,i) + ELMTListPos(l2,i);
        else ELMTListPos(l3,i) = ELMTListPos(l1,i) - ELMTListPos(l2,i);
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListPosEqual(ListPos l1, ListPos l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    /* KAMUS */
    int i,len;
    boolean isEqual = true;
    /* ALGORITMA */
    if (lengthListPos(l1)==lengthListPos(l2)){
        i = 0;
        len = lengthListPos(l1);
        while(isEqual && i<len){
            isEqual = ELMTListPos(l1,i) == ELMTListPos(l2,i);
            i++;
        }
        return isEqual;
    }else{
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListPos(ListPos l, ElType val){
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
    while (ELMTListPos(l,i) != VAL_UNDEF && !isFound){
        isFound = ELMTListPos(l,i) == val;
        i++;
    }
    if (isFound) return i-1;
    else return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremesListPos(ListPos l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    *max = ELMTListPos(l,0);
    *min = ELMTListPos(l,0);
    for(i=1; i<lengthListPos(l); i++){
        if(ELMTListPos(l,i)>*max) *max = ELMTListPos(l,i);
        if(ELMTListPos(l,i)<*min) *min = ELMTListPos(l,i);
    }
}

/* ********** OPERASI LAIN ********** */
boolean isAllEvenListPos(ListPos l){
/* Menghailkan true jika semua elemen l genap */
    /* KAMUS */
    boolean isOddFound = false;
    int i;
    /* ALGORITMA */
    i=0;
    while (!isOddFound && i<lengthListPos(l)){
        isOddFound = ELMTListPos(l,i)%2 == 1;
        i++;
    }
    return !isOddFound;
}

/* ********** SORTING ********** */
void sortListPos(ListPos *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    /* KAMUS */
    int i,j, len;
    ElType tmp;
    /* ALGORITMA */
    len = lengthListPos(*l);
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if ((asc && ELMTListPos(*l,i)>ELMTListPos(*l,j)) || (!asc && ELMTListPos(*l,i)<ELMTListPos(*l,j))){
                tmp = ELMTListPos(*l,i);
                ELMTListPos(*l,i) = ELMTListPos(*l,j);
                ELMTListPos(*l,j) = tmp;
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListPos(ListPos *l, ElType val){
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
void deleteLastListPos(ListPos *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = 0;
    while(ELMTListPos(*l,i) != VAL_UNDEF){
        i++;
    }
    *val = ELMTListPos(*l,i-1);
    ELMTListPos(*l,i-1) = VAL_UNDEF;
}

void deleteAtListPos(ListPos *l, ElType *val, int idx){
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
    while(isIdxEffListPos(*l,i+1)){
        ELMTListPos(*l,i) = ELMTListPos(*l,i+1);
        i++;
    }
    ELMTListPos(*l,i) = VAL_UNDEF;
}