#include "pesanan.h"
#include <stdio.h>

void createPesanan (Pesanan *p, int kodePesanan, Location pickUpLocation, Location dropOffLocation, char jenisItem, int waktuHangus){
/* I.S. Pesanan p sembarang. kodePesanan, pickUpLocation, dropOffLocation, jenisItem, dan waktuHangus terdefinisi. */
/* F.S. Pesanan p terdefinisi berdasarkan parameter prosedur */
/* Jika jenis barang bukan perishable item, waktuHangus diset ke -99 */
    KODE_PESANAN(*p) = kodePesanan;
    PICK_UP_LOCATION(*p) = pickUpLocation;
    DROP_OFF_LOCATION(*p) = dropOffLocation;
    JENIS_ITEM(*p) = jenisItem;

    if (jenisItem == 'P') {
        WAKTU_HANGUS(*p) = waktuHangus;
    }
    else {
        WAKTU_HANGUS(*p) = -99;
    }
}

boolean isPesananIdentical(Pesanan p1, Pesanan p2){
/* Mengembalikan true jika kodePesanan p1 = kode Pesanan p2, false jika sebaliknya */
    return KODE_PESANAN(p1) == KODE_PESANAN(p2);
}

void displayPesanan(Pesanan p) {
/* I.S. Pesanan p terdefinisi */
/* F.S. Atribut-atribut dari Pesanan p ditampilkan ke layar */
    printf("Kode pesanan: %d\n", KODE_PESANAN(p));
    printf("Lokasi pick up: %c\n", LOC_NAME(PICK_UP_LOCATION(p)));
    printf("Lokasi drop off: %c\n", LOC_NAME(DROP_OFF_LOCATION(p)));

    printf("Jenis item: ");
    switch (JENIS_ITEM(p)) {
    case 'N':
        printf("Normal item\n");
        break;
    case 'H':
        printf("Heavy item\n");
        break;
    case 'P':
        printf("Perishable item\n");
        printf("Waktu Hangus: %d\n", WAKTU_HANGUS(p));
        break;
    case 'V':
        printf("VIP item\n");
        break;
    default:
        printf("Kode item invalid\n");
        break;
    }
}