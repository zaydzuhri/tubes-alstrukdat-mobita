#include "todolist.h"

void createToDoList(ToDoList *tdl){
/* I.S. ToDoList tdl sembarang */
/* F.S. ToDoList tdl berupa LinkedList kosong */
    CreateLinkedList(tdl);
}

void timeUpdateToDoList(ToDoList *tdl, DaftarPesanan *dp, DaftarPesanan *dp2, int waktuSekarang){
/* I.S. ToDoList tdl, DaftarPesanan dp, dan waktuSekarang terdefinisi, dp terurut berdasarkan waktu masuk */
/* F.S. Seluruh PendingPesanan dalam dp yang waktu masuknya >= waktuSekarang dimasukkan */
/* ke elemen terakhir pada tdl sebagai Pesanan */
    PendingPesanan pp;
    while ( WAKTU_MASUK(HEAD(*dp)) == waktuSekarang ) {
        dequeueDaftarPesanan(dp, &pp);
        insertLast(tdl, PESANAN(pp));
        enqueueDaftarPesanan(dp2, pp);  
    } 
}

void pickUpUpdateToDoList(ToDoList *tdl, Location l, Pesanan *p, boolean *pickUpSuccess){
/* I.S. ToDoList tdl, Pesanan p terdefinisi. pickUpSuccess sembarang */
/* F.S. Pesanan paling awal yang dapat di pick up di lokasi l dihapuskan dari tdl dan dimasukkan ke p */
/* Jika terjadi penghapusan, pickUpSuccess true. Jika tidak, pickUpSuccess false */

}

void displayToDoList(ToDoList tdl){
/* I.S. ToDoList tdl terdefinisi */
/* F.S. Ditampilkan lokasi pickup, lokasi dropoff, dan jenis item dari setiap Pesanan pada ToDoList */

}