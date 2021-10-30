/**
Filename: gadget.h
Description: Data Type Gadget
Prepared by: Kelompok 1 K03 IF 2110 Evil Mobita
Created at: 17/10/2019
**/

#ifndef GADGET_H
#define GADGET_H

#include "listpos.h"
#include "boolean.h"

typedef int Gadget;
typedef ListPos GadgetList;

/* SELEKTOR */
char* getGadgetName(Gadget g);
// mengembalikan nama gadget

int getHargaGadget(Gadget g);
// mengembalikan harga gadget

/* KONSTRUKTOR */
void CreateInventory(GadgetList *IG);
// I.S. IG sembarang
// F.S. IG terdefinisi, isinya kosong


boolean hasGadget(GadgetList IG, Gadget g);
/* menghasilkan true jika player memiliki gadget g
    (gadget g ada di inventory) */

void addGadget(GadgetList *IG, Gadget g);
// I.S. g, ig terdefinisi
/* F.S. g ditambahkan ke inventory, jika penuh mengirim pesan bahwa inventory penuh
    lalu F.S. = I.S. */

void removeGadget(GadgetList *IG, int idx);
// I.S. g, ig terdefinisi dan g ada di IG
// F.S. g dihapus ke inventory

void useGadget(GadgetList *IG);
// I.S. IG, g terdefinisi
/* F.S. jika g ada pada IG, g dihapus dari IG, g menjadi aktif, 
    jika tidak ada, keluarkan pesan gagal*/
    
void displayShop(GadgetList *IG, int *money);
// I.S. command BUY dipanggil
// F.S. Uang dan gadget yang tersedia ditampilkan

void buyGadget(GadgetList *IG, int *money);
// I.S. displayShop telah dijalankan
/* F.S. program menerima gadget yang ingin dibeli user
    jika input valid dan inventory tidak penuh, gadget terbeli
    jika tidak, program mengeluarkan pesan gagal dan gadget tidak terbeli */


void displayInventory(GadgetList *IG);
// I.S. command INVENTORY dipanggil
/* F.S. Menampilkan inventory, lalu program meminta input
    gadget yang ingin dipakai,
    jika berhasil, program akan menampilkan pesan berhasil,
    jika gagal, program akan menampilkan pesan gagal*/


#endif // !1