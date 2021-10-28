#include<stdio.h>
#include "gadget.h"
#include "wordmachine.h"

/* SELEKTOR */
char* getGadgetName(Gadget g){
// mengembalikan nama gadget
    /* KAMUS */
    /* ALGORITMA */
    switch(g){
        case (1):
            return "Kain Pembungkus Waktu"; 
        case(2):
            return "Senter Pembesar";
        case(3):
            return "Pintu Kemana Saja";
        case(4):
            return "Mesin Waktu";
        case(5):
            return "Senter Pengecil";
        default:
            return "Bukan Gadget";
    }
}

int getHargaGadget(Gadget g){
// mengembalikan harga gadget
    /* KAMUS */
    /* ALGORITMA */
    switch(g){
        case (1):
            return 800; 
        case(2):
            return 1200;
        case(3):
            return 1500;
        case(4):
            return 3000;
        case(5):
            return 800;
        default:
            return 0;
    }
}

void CreateInventory(GadgetList *IG){
// I.S. IG sembarang
// F.S. IG terdefinisi, isinya kosong
    /* KAMUS */
    /* ALGORITMA */
    CreateListPos(IG);
}

boolean hasGadget(GadgetList IG, Gadget g){
/* menghasilkan true jika player memiliki gadget g
    (gadget g ada di inventory) */
    /* KAMUS */
    /* ALGORITMA */
    return indexOf(IG,g)!=IDX_UNDEF;
}

void addGadget(GadgetList *IG, Gadget g){
// I.S. g, ig terdefinisi dan tidak penuh
// F.S. g ditambahkan ke inventory 
    /* KAMUS */
    /* ALGORITMA */
    insertLast(IG,g);
    printf("%s berhasil ditambahkan\n", getGadgetName(g));
}

void removeGadget(GadgetList *IG, int idx){
// I.S. g, ig terdefinisi dan g ada di IG
// F.S. g dihapus ke inventory
    /* KAMUS */
    ElType val;
    /* ALGORITMA */
    deleteAt(IG, &val,idx);
}

void useGadget(GadgetList *IG){
// I.S. IG, g terdefinisi
/* F.S. jika g ada pada IG, g dihapus dari IG, g menjadi aktif, 
    jika tidak ada, keluarkan pesan gagal*/
    /* KAMUS */
    int idx;
    /* ALGORITMA */
    printf("Gadget mana yang ingin dipakai? (ketik 0 jika ingin kembali)\n\n");

    scanf("%d",idx);
    if(isIdxEff(*IG,idx)){
        printf("%s berhasil dipakai\n",getGadgetName(ELMT(*IG,idx)));
        removeGadget(IG,idx);
    }else{
        printf("Gadget tidak ditemukan.\n");
    }
}

void displayShop(GadgetList *IG, int *money){
// I.S. command BUY dipanggil
/* F.S. Uang dan gadget yang tersedia ditampilkan
    kemudian program meminta input gadget yang ingin dibeli,
    jika berhasil, maka gadget ditambahkan ke inventory, uang setelah pembelian ditampilkan,
    jika gagal, akan muncul pesan gagal*/
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("Uang Anda sekarang: %d Yen\n", *money);
    printf("Gadget yang tersedia:\n");
    for(i=1; i<=5; i++){
        printf("%d. %s (%d Yen)\n",i, getGadgetName(i), getHargaGadget(i));
    }
    buyGadget(IG,money);
}

void buyGadget(GadgetList *IG, int *money){
// I.S. displayShop telah dijalankan
/* F.S. program menerima gadget yang ingin dibeli user
    jika input valid dan inventory tidak penuh, gadget terbeli
    jika tidak, program mengeluarkan pesan gagal dan gadget tidak terbeli */
    /* KAMUS */
    Gadget g;
    /* ALGORITMA */
    printf("Gadget mana yang ingin kamu beli? (ketik 0 jika ingin kembali)\n\n");

    printf("ENTER COMMAND: ");
    startWord();
    if(currentWord.length == 1){
        g = currentWord.contents[0] - '0';
        if(g<=0 || g>5){
            printf("Invalid Input!\n");
        }else if(isFull(*IG)){
            printf("Inventory penuh, pembelian gagal\n");
        }else if(getHargaGadget(g) > *money){
            printf("Uang Anda tidak cukup untuk membeli gadget!\n");
        }else{
            addGadget(IG,g);
            *money -= getHargaGadget(g);
            printf("Uang Anda Sekarang = %d Yen\n", *money);
        }
    }else{
        printf("Invalid Input!\n");
    }
}

void displayInventory(GadgetList *IG){
// I.S. command INVENTORY dipanggil
/* F.S. Menampilkan inventory, lalu program meminta input
    gadget yang ingin dipakai,
    jika berhasil, program akan menampilkan pesan berhasil,
    jika gagal, program akan menampilkan pesan gagal*/
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for(i=0; i<LISTPOS_CAPACITY; i++){
        if(isIdxEff(*IG,i)){
            printf("%d. %s\n",i+1, getGadgetName(ELMT(*IG,i)));
        }else{
            printf("%d. -\n",i+1);
        }
    }
    useGadget(IG);
}