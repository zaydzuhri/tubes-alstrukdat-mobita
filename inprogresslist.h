/* File : inprogresslist.h */
/* Definisi ADT InProgressList dengan memanfaatkan ADT LinkedList*/

#ifndef INPROGRESSLIST_H
#define INPROGRESSLIST_H

#include "linkedlist.h"
#include "daftarpesanan.h"

typedef LinkedList InProgressList;

void createInProgressList(InProgressList *ipl);
/* I.S. InProgressList ipl sembarang */
/* F.S. InProgressList ipl berupa LinkedList kosong */

void AddToInProgressList(InProgressList *ipl, Pesanan p);
/* I.S. InProgressList ipl dan Pesanan p terdefinisi */
/* F.S. Pesanan p ditambahkan di paling belakang InProgressList ipl */

void removeFromInProgressList(InProgressList *ipl, Pesanan p);
/* I.S. InProgressList ipl dan Pesanan p terdefinisi, Pesanan p ada di dalam InProgressList */
/* F.S. Pesanan p dihapuskan dari InProgressList ipl */

void removeExpiredPerishibles(InProgressList *ipl);
/* I.S. InProgressList ipl terdefinisi */
/* F.S. Pesanan p yang itemnya berupa perishable dan durasinya sudah mencapai 0 atau -1 dihapus dari ipl */

void displayInProgressList(InProgressList ipl);
/* I.S. InProgressList ipl terdefinisi */
/* F.S. Ditampilkan jenis item dan lokasi dropoff setiap Pesanan dalam InProgressList ipl */

#endif