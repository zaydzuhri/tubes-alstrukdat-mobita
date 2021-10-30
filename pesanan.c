#include "pesanan.h"

void createPesanan (Pesanan *p, int kp, Location pul, Location dol, char ji, int wh){
/* I.S. Pesanan p sembarang. kp, pul, dol, ji, dan wh terdefinisi. */
/* F.S. Pesanan p terdefinisi berdasarkan parameter prosedur */
/* Jika jenis barang bukan perishable item, wh diset ke -99 */
    KODE_PESANAN(*p) = kp;
    PICK_UP_LOCATION(*p) = pul;
    DROP_OFF_LOCATION(*p) = dol;
    JENIS_ITEM(*p) = ji;
    WAKTU_HANGUS(*p) = wh;
}

boolean isPesananIdentical(Pesanan p1, Pesanan p2){
/* Mengembalikan true jika kodePesanan p1 = kode Pesanan p2, false jika sebaliknya */
    return KODE_PESANAN(p1) == KODE_PESANAN(p2);
}