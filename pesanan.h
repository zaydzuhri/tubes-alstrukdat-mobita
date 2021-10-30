/* File : pesanan.h */
/* Definisi ADT Pesanan */

#ifndef PESANAN_H
#define PESANAN_H

#include "boolean.h"
#include "location.h"

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

void createPesanan(Pesanan *p, int kp, Location pul, Location dol, char ji, int wh);
/* I.S. Pesanan p sembarang. pul, dol, ji, dan wh terdefinisi. */
/* F.S. Pesanan p terdefinisi berdasarkan parameter prosedur */
/* Jika jenis barang bukan perishable item, wh diset ke -99 */

boolean isPesananIdentical(Pesanan p1, Pesanan p2);
/* Mengembalikan true jika kodePesanan p1 = kode Pesanan p2, false jika sebaliknya */

#endif