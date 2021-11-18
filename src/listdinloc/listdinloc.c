/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdinloc.h"
#include "../boolean/boolean.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListLoc(ListLoc *l, int capacity) {
    BUFFER(*l) = (ElTypeLoc *)malloc(capacity * sizeof(ElTypeLoc));
    NEFF(*l) = 0;
    LISTLOCCAP(*l) = capacity;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListLoc *l) {
    free(BUFFER(*l));
    NEFF(*l) = 0;
    LISTLOCCAP(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, LISTLOCCAP(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListLoc(ListLoc l) {
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

void getLocationFromList(ListLoc l, Location *loc, char locName) {
    LOC_NAME(*loc) = LOC(l, indexOfListLoc(l, locName)).locName;
    LOC_POS(*loc) = LOC(l, indexOfListLoc(l, locName)).locPosition;
}

void getAdjacentLocations(Matrix adjMat, ListLoc list, ListLoc *adjList, Location currentLoc) {
    for (int i = 0; i < lengthListLoc(list); i++) {
        if (isAdjacent(adjMat, list, LOC(list, i), currentLoc)) {
            insertLastListLoc(adjList, LOC(list, i));
        }
    }
}

/* *** Selektor INDEKS *** */
IdxType getLastIdxListLoc(ListLoc l) {
    return NEFF(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListLoc(ListLoc l, int i) {
    return i >= 0 && i < LISTLOCCAP(l);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListLoc(ListLoc l, IdxType i) {
    return i >= 0 && i < NEFF(l);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListLoc(ListLoc l) {
    return NEFF(l) == 0;
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListLoc(ListLoc l) {
    return NEFF(l) == LISTLOCCAP(l);
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isInListLoc(ListLoc l, char name) {
    boolean found = false;
    for (int i = 0; i < lengthListLoc(l) && !found; i++) {
        if (LOC(l, i).locName == name) {
            found = true;
        }
    }
    return found;
}

boolean isAdjacent(Matrix adjMat, ListLoc list, Location loc1, Location loc2) {
    int loc1idx = indexOfListLoc(list, loc1.locName);
    int loc2idx = indexOfListLoc(list, loc2.locName);
    return ELMT(adjMat, loc1idx, loc2idx);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListLoc(ListLoc *l) {
    int n;
    do {
        scanf("%d", &n);
    } while (!(n >= 0 && n <= LISTLOCCAP(*l)));

    ElTypeLoc element;
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        LOC(*l, i) = element;
        NEFF(*l) += 1;
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= LISTLOCCAP(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= LISTLOCCAP(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayListLoc(ListLoc l, Location currentLoc) {
    if (!isEmptyListLoc(l)) {
        int i = 0;
        int count = 1;
        while (i < lengthListLoc(l)) {
            if (LOC(l, i).locName != currentLoc.locName) {
                printf("%d. %c (%d,%d)\n", count, LOC(l, i).locName, LOC(l, i).locPosition.Row, LOC(l, i).locPosition.Col);
                count++;
            }
            i++;
        }
    } else {
        printf("Peta kosong.\n");
    }
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfListLoc(ListLoc l, char locName) {
    int i = 0;
    boolean found = false;
    if (!isEmptyListLoc(l)) {
        found = (LOC(l, 0).locName == locName);
        while (!found && (i < lengthListLoc(l))) {
            i += 1;
            found = (LOC(l, i).locName == locName);
        }
    }
    return (found ? i : IDX_UNDEF);
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void copyListLoc(ListLoc lIn, ListLoc *lOut) {
    CreateListLoc(lOut, LISTLOCCAP(lIn));
    for (int i = 0; i < lengthListLoc(lIn); i++) {
        LOC(*lOut, i) = LOC(lIn, i);
        NEFF(*lOut) += 1;
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListLoc(ListLoc *l, ElTypeLoc val) {
    if (lengthListLoc(*l) != LISTLOCCAP(*l)) {
        LOC(*l, NEFF(*l)) = val;
        NEFF(*l) += 1;
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListLoc(ListLoc *l, ElTypeLoc *val) {
    if (lengthListLoc(*l) != 0) {
        *val = LOC(*l, lengthListLoc(*l) - 1);
        NEFF(*l) -= 1;
    }
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growListLoc(ListLoc *l, int num) {
    ListLoc new;
    copyListLoc(*l, &new);
    dealocate(l);
    CreateListLoc(l, LISTLOCCAP(new) + num);
    for (int i = 0; i < lengthListLoc(new); i++) {
        LOC(*l, i) = LOC(new, i);
        NEFF(*l) += 1;
    }
    dealocate(&new);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListLoc(ListLoc *l, int num) {
    ListLoc new;
    copyListLoc(*l, &new);
    dealocate(l);
    CreateListLoc(l, LISTLOCCAP(new) - num);
    for (int i = 0; i < lengthListLoc(new); i++) {
        LOC(*l, i) = LOC(new, i);
    }
    if (num <= (LISTLOCCAP(new) - lengthListLoc(new))) {
        NEFF(*l) = lengthListLoc(new);
    } else {
        NEFF(*l) = LISTLOCCAP(*l);
    };
    dealocate(&new);
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactListLoc(ListLoc *l) {
    ListLoc new;
    copyListLoc(*l, &new);
    dealocate(l);
    CreateListLoc(l, NEFF(new));
    for (int i = 0; i < lengthListLoc(new); i++) {
        LOC(*l, i) = LOC(new, i);
        NEFF(*l) += 1;
    }
    dealocate(&new);
}
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */