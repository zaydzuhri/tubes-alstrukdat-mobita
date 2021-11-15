#include "todolist.h"

void createToDoList(ToDoList *tdl) {
    /* I.S. ToDoList tdl sembarang */
    /* F.S. ToDoList tdl berupa LinkedList kosong */
    createLinkedList(tdl);
}

void timeUpdateToDoList(ToDoList *tdl, DaftarPesanan *dp1, DaftarPesanan *dp2, int waktuSekarang) {
    /* I.S. ToDoList tdl, DaftarPesanan dp1, dan waktuSekarang terdefinisi, dp1 terurut berdasarkan waktu masuk */
    /* F.S. Seluruh PendingPesanan dalam dp1 yang waktu masuknya >= waktuSekarang dimasukkan */
    /* ke elemen terakhir pada tdl sebagai Pesanan */
    /* KAMUS LOKAL */
    PendingPesanan pp;
    boolean allPpAtCurrentTimeInserted;

    /* ALGORITMA */
    allPpAtCurrentTimeInserted = false;
    while (!isDaftarPesananEmpty(*dp1) && !allPpAtCurrentTimeInserted) {
        if (WAKTU_MASUK(HEAD(*dp1)) == waktuSekarang) {
            dequeueDaftarPesanan(dp1, &pp);
            insertLastLinkedList(tdl, PESANAN(pp));
            enqueueDaftarPesanan(dp2, pp);
        } else {
            allPpAtCurrentTimeInserted = true;
        }
    }
}

void pickUpUpdateToDoList(ToDoList *tdl, Location l, Pesanan *p, boolean *pickUpSuccess) {
    /* I.S. ToDoList tdl, Pesanan p terdefinisi. pickUpSuccess sembarang */
    /* F.S. Pesanan paling awal yang dapat di pick up di lokasi l dihapuskan dari tdl dan dimasukkan ke p */
    /* Jika terjadi penghapusan, pickUpSuccess true. Jika tidak, pickUpSuccess false */
    /* KAMUS LOKAL */
    Address iterator;
    int idxCounter;

    /* ALGORITMA */
    *pickUpSuccess = false;
    iterator = *tdl;
    idxCounter = 0;

    while (iterator != NULL && !*pickUpSuccess) {
        if (isSameLoc(l, PICK_UP_LOCATION(INFO(iterator)))) {
            deleteAtLinkedList(tdl, idxCounter, p);
            *pickUpSuccess = true;
        } else {
            iterator = NEXT(iterator);
            idxCounter++;
        }
    }
}

void displayToDoList(ToDoList tdl) {
    /* I.S. ToDoList tdl terdefinisi */
    /* F.S. Ditampilkan lokasi pickup, lokasi dropoff, dan jenis item dari setiap Pesanan pada ToDoList */
    /* KAMUS LOKAL */
    Address p;
    int counter;

    /* ALGORITMA */
    p = tdl;
    printf("Pesanan pada To Do List:\n");

    if (p == NULL) {
        printf("Tidak ada pesanan di dalam To Do List.\n");
    } else {
        counter = 1;
        do {
            printf("%d. ", counter);
            switch (JENIS_ITEM(INFO(p))) {
            case 'N':
                printf("%c -> %c (Normal Item)\n", LOC_NAME(PICK_UP_LOCATION(INFO(p))), LOC_NAME(DROP_OFF_LOCATION(INFO(p))));
                break;
            case 'H':
                printf("%c -> %c (Heavy Item)\n", LOC_NAME(PICK_UP_LOCATION(INFO(p))), LOC_NAME(DROP_OFF_LOCATION(INFO(p))));
                break;
            case 'P':
                printf("%c -> %c (Perishable Item, Waktu hangus = %d)\n", LOC_NAME(PICK_UP_LOCATION(INFO(p))), LOC_NAME(DROP_OFF_LOCATION(INFO(p))), WAKTU_HANGUS(INFO(p)));
                break;
            case 'V':
                printf("%c -> %c (VIP Item)\n", LOC_NAME(PICK_UP_LOCATION(INFO(p))), LOC_NAME(DROP_OFF_LOCATION(INFO(p))));
                break;
            default:
                printf("Invalid\n");
            }
            counter++;
            p = NEXT(p);
        } while (p != NULL);
    }
}

boolean isToDoListEmpty(ToDoList tdl){
/* Mengembalikan true jika tdl kosong, false jika tidak kosong */
    return isLinkedListEmpty(tdl);
}