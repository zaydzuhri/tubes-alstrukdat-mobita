#include "inprogresslist.h"

void createInProgressList(InProgressList *ipl) {
    /* I.S. InProgressList ipl sembarang */
    /* F.S. InProgressList ipl berupa LinkedList kosong */
    createLinkedList(ipl);
}

void AddToInProgressList(InProgressList *ipl, Pesanan p) {
    /* I.S. InProgressList ipl dan Pesanan p terdefinisi */
    /* F.S. Pesanan p ditambahkan di paling belakang InProgressList ipl */
    insertFirstLinkedList(ipl, p);
}

void removeFromInProgressList(InProgressList *ipl, Pesanan p) {
    /* I.S. InProgressList ipl dan Pesanan p terdefinisi, Pesanan p ada di dalam InProgressList */
    /* F.S. Pesanan p dihapuskan dari InProgressList ipl */
    /* KAMUS LOKAL */
    int idx;

    /* ALGORITMA */
    idx = indexOfLinkedList(*ipl, p);
    deleteAtLinkedList(ipl, idx, &p);
}

void removeExpiredPerishables(InProgressList *ipl) {
    /* I.S. InProgressList ipl terdefinisi */
    /* F.S. Pesanan yang itemnya berupa perishable dan durasinya sudah mencapai 0 dihapus dari ipl */
    /* KAMUS LOKAL */
    Address addr1, addr2;
    Pesanan p;

    /* ALGORITMA */
    addr1 = NULL;
    addr2 = FIRST(*ipl);

    if (!isLinkedListEmpty(*ipl)) {
        do {
            if (JENIS_ITEM(INFO(addr2)) == 'P' && (WAKTU_HANGUS(INFO(addr2)) <= 0)) {
                if (addr1 == NULL) {
                    // Elemen pertama InProgressList adalah perishable item yang waktu hangusnya 0
                    deleteFirstLinkedList(ipl, &p);
                    addr2 = FIRST(*ipl);
                } else {
                    // elemen pada addr2 adalah perishable item yang waktu hangusnya 0, addr2 bukan elemen pertama InProgressList
                    NEXT(addr1) = NEXT(addr2);
                    free(addr2);
                    addr2 = NEXT(addr1);
                }
            } else {
                // elemen pada addr2 bukan perishable item atau perishable item yang waktu hangusnya bukan 0
                addr1 = addr2;
                addr2 = NEXT(addr2);
            }
        } while (addr2 != NULL);
    }
}

void reduceAllPerishablesTime(InProgressList *ipl, int reduction) {
    /* I.S. InProgressList ipl terdefinisi */
    /* F.S. Pesanan di ipl yang merupakan perishable durasinya akan dikurangi 1 */
    /* KAMUS LOKAL */
    Address addr;

    /* ALGORITMA */
    addr = FIRST(*ipl);
    if (!isLinkedListEmpty(*ipl)) {
        while (addr != NULL) {
            if (JENIS_ITEM(INFO(addr)) == 'P') {
                WAKTU_HANGUS(INFO(addr)) -= reduction;
            }
            addr = NEXT(addr);
        }
    }
}

void changePerishableTime(InProgressList *ipl, Pesanan p, int time) {
    /* I.S. ipl, p, dan time terdefinisi. p merupakan item perishable. item p ada pada ipl */
    /* F.S. Pesanan p di ipl diganti durasinya dengan time */
    /* KAMUS LOKAL */
    Address addr;

    /* ALGORITMA */
    addr = *ipl;
    while (addr != NULL && KODE_PESANAN(INFO(addr)) != KODE_PESANAN(p)) {
        addr = NEXT(addr);
    }
    WAKTU_HANGUS(INFO(addr)) = time;
}

void displayInProgressList(InProgressList ipl) {
    /* I.S. InProgressList ipl terdefinisi */
    /* F.S. Ditampilkan jenis item dan lokasi dropoff setiap Pesanan dalam InProgressList ipl */
    /* KAMUS LOKAL */
    Address p;
    int counter;

    /* ALGORITMA */
    p = ipl;
    printf("Pesanan yang sedang diantarkan: \n");

    if (p == NULL) {
        printf("Tidak ada pesanan yang sedang diantarkan.\n");
    } else {
        counter = 1;
        do {
            printf("%d. ", counter);
            switch (JENIS_ITEM(INFO(p))) {
            case 'N':
                printf("Normal Item (Tujuan: %c)\n", LOC_NAME(DROP_OFF_LOCATION(INFO(p))));
                break;
            case 'H':
                printf("Heavy Item (Tujuan: %c)\n", LOC_NAME(DROP_OFF_LOCATION(INFO(p))));
                break;
            case 'P':
                printf("Perishable Item (Tujuan: %c, Sisa Waktu %d)\n", LOC_NAME(DROP_OFF_LOCATION(INFO(p))), WAKTU_HANGUS(INFO(p)));
                break;
            case 'V':
                printf("VIP Item (Tujuan: %c)\n", LOC_NAME(DROP_OFF_LOCATION(INFO(p))));
                break;
            default:
                printf("Invalid\n");
            }
            counter++;
            p = NEXT(p);
        } while (p != NULL);
    }
}