/* File : pesanan.h */
/* Definisi ADT Pesanan */

#ifndef PESANAN_H
#define PESANAN_H

#include "../boolean/boolean.h"
#include "../location/location.h"

typedef struct {
    Location pickUpLocation;
    Location dropOffLocation;
    int kodePesanan;
    int waktuHangus;
    char jenisItem;
} Pesanan;

/* ********* AKSES (Selektor) ********* */
/* Jika p adalah Pesanan, maka akses elemen : */
#define KODE_PESANAN(p) (p).kodePesanan
#define PICK_UP_LOCATION(p) (p).pickUpLocation
#define DROP_OFF_LOCATION(p) (p).dropOffLocation
#define JENIS_ITEM(p) (p).jenisItem
#define WAKTU_HANGUS(p) (p).waktuHangus

void createPesanan (Pesanan *p, int kodePesanan, Location pickUpLocation, Location dropOffLocation, char jenisItem, int waktuHangus);
/* I.S. Pesanan p sembarang. kodePesanan, pickUpLocation, dropOffLocation, jenisItem, dan waktuHangus terdefinisi. */
/* F.S. Pesanan p terdefinisi berdasarkan parameter prosedur */
/* Jika jenis barang bukan perishable item, waktuHangus diset ke -99 */

boolean isPesananIdentical(Pesanan p1, Pesanan p2);
/* Mengembalikan true jika kodePesanan p1 = kode Pesanan p2, false jika sebaliknya */

void displayPesanan(Pesanan p);
/* I.S. Pesanan p terdefinisi */
/* F.S. Atribut-atribut dari Pesanan p ditampilkan ke layar */

#endif