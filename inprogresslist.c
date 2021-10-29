#include "inprogresslist.h"

void createInProgressList(InProgressList *ipl){
/* I.S. InProgressList ipl sembarang */
/* F.S. InProgressList ipl berupa LinkedList kosong */
    CreateLinkedList(ipl);
}

void AddToInProgressList(InProgressList *ipl, Pesanan p){
/* I.S. InProgressList ipl dan Pesanan p terdefinisi */
/* F.S. Pesanan p ditambahkan di paling belakang InProgressList ipl */
    insertLastLinkedList(ipl, p);
}

void removeFromInProgressList(InProgressList *ipl, Pesanan p){
/* I.S. InProgressList ipl dan Pesanan p terdefinisi, Pesanan p ada di dalam InProgressList */
/* F.S. Pesanan p dihapuskan dari InProgressList ipl */
    /* KAMUS LOKAL */
    int idx;

    /* ALGORITMA */
    idx = indexOfLinkedList(*ipl, p);
    deleteAtLinkedList(ipl, idx, &p);
}

void removeExpiredPerishables(InProgressList *ipl){
/* I.S. InProgressList ipl terdefinisi */
/* F.S. Pesanan yang itemnya berupa perishable dan durasinya sudah mencapai 0 atau -1 dihapus dari ipl */
    /* KAMUS LOKAL */
    Address addr1, addr2;
    Pesanan p;

    /* ALGORITMA */
    addr1 = NULL;
    addr2 = *ipl;

    if (!isLinkedListEmpty(*ipl)) {
        while (addr2 != NULL) {
            // KONFIRMASI LAGI KODE UNTUK JENIS ITEM APA
            if (JENIS_ITEM(INFO(addr2)) == "p" && (WAKTU_HANGUS(INFO(addr2)) == 0 || WAKTU_HANGUS(INFO(addr2)) == -1)) {
                if (addr1 == NULL) {
                    deleteFirstLinkedList(ipl, &p);
                }
                else {
                    NEXT(addr1) = NEXT(addr2);
                    free(addr2);
                    addr2 = NEXT(addr1);        
                }
            }
            addr1 = addr2;
            addr2 = NEXT(addr2);
        }
    }

}

void reduceAllPerishablesTime(InProgressList *ipl){
/* I.S. InProgressList ipl terdefinisi */
/* F.S. Pesanan di ipl yang merupakan perishable durasinya akan dikurangi 1 */
    /* KAMUS LOKAL */
    Address addr;

    /* ALGORITMA */
    if (!isLinkedListEmpty(*ipl)) {
        while (addr != NULL) {
             if (JENIS_ITEM(INFO(addr)) == "p") {
                WAKTU_HANGUS(INFO(addr))--; 
             }
             addr = NEXT(addr);
        }
    }
}

void changePerishableTime(InProgressList *ipl, Pesanan p, int time){
/* I.S. ipl, p, dan time terdefinisi. p merupakan item perishable. item p ada pada ipl */
/* F.S. Pesanan p di ipl diganti durasinya dengan time */
    /* KAMUS LOKAL */
    Address addr;

    /* ALGORITMA */
    while (addr != NULL && KODE_PESANAN(INFO(addr)) != KODE_PESANAN(p)) {
        addr = NEXT(addr);
    }
    WAKTU_HANGUS(INFO(addr)) = time;
}

void displayInProgressList(InProgressList ipl){
/* I.S. InProgressList ipl terdefinisi */
/* F.S. Ditampilkan jenis item dan lokasi dropoff setiap Pesanan dalam InProgressList ipl */
    /* KAMUS LOKAL */

    /* ALGORITMA */

}