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
    return indexOfListPos(IG,g)!=IDX_UNDEF;
}

void addGadget(GadgetList *IG, Gadget g){
// I.S. g, ig terdefinisi dan tidak penuh
// F.S. g ditambahkan ke inventory 
    /* KAMUS */
    /* ALGORITMA */
    insertLastListPos(IG,g);
    printf("%s berhasil ditambahkan\n", getGadgetName(g));
}

void removeGadget(GadgetList *IG, int idx){
// I.S. g, ig terdefinisi dan g ada di IG
// F.S. g dihapus ke inventory
    /* KAMUS */
    ElTypeListPos val;
    /* ALGORITMA */
    deleteAtListPos(IG, &val,idx);
}

void useGadget(GadgetList *IG, DaftarPesanan dp, Bag *b, int mapRows, int mapCols, int *time, ListLoc locL, Location *curLoc, Matrix adjM, ToDoList todoL, InProgressList *progL){
// I.S. IG, g terdefinisi
/* F.S. jika g ada pada IG, g dihapus dari IG, g menjadi aktif, 
    jika tidak ada, keluarkan pesan gagal*/
    /* KAMUS */
    int idx;
    /* ALGORITMA */
    printf("Gadget mana yang ingin dipakai? (ketik 0 jika ingin kembali)\n\nENTER COMMAND : ");

    startWord();
    if(currentWord.length == 1){
        idx = currentWord.contents[0] - '1';
        if(isIdxEffListPos(*IG,idx)){
            switch(ELMTListPos(*IG, idx)){
                case (1):
                    kainEffect(dp,b,progL);
                    break;
                case (2):
                    pembesarEffect(b);
                    break;
                case (3):
                    pintuEffect(mapRows, mapCols, *time, locL, curLoc, adjM, todoL, *progL);
                    break;
                case (4):
                    mesinWaktuEffect(time);
                    break;
                default:
                    printf("Senter pengecilmu tiba-tiba hilang!\n");
            }
            printf("%s berhasil dipakai\n",getGadgetName(ELMTListPos(*IG,idx)));
            removeGadget(IG,idx);
        }else{
            printf("Gadget tidak ditemukan.\n");
        }
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
        }else if(isFullListPos(*IG)){
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
        if(isIdxEffListPos(*IG,i)){
            printf("%d. %s\n",i+1, getGadgetName(ELMTListPos(*IG,i)));
        }else{
            printf("%d. -\n",i+1);
        }
    }
}

void kainEffect(DaftarPesanan dp,Bag *b, InProgressList *ipl){
// I.S. Kain Pembungkus Waktu dipilih dalam prosedur useGadget
/* F.S. Jika item paling atas dalam tas ialah perishible item, waktu hangusnya kembali ke semula */
    /* KAMUS */
    int time;
    /* ALGORITMA */
    if(JENIS_ITEM(TOP(*b)) == 'P'){
        time = getOriginalWaktuHangus(dp,TOP(*b));
        WAKTU_HANGUS(TOP(*b)) =time;
        changePerishableTime(ipl, TOP(*b), time);
    }
}

void pembesarEffect(Bag *b){
// I.S. Senter Pembesar dipilih dalam prosedur useGadget
/* F.S. Jika dua kali kapasitas tas <= kapasitas maksimum, kapasitas tas dikali 2 */
    /* KAMUS */
    /* ALGORITMA */
    if (max_Cap(*b)*2<=BAG_CAPACITY){
        max_Cap(*b)*=2;
    }else{
        max_Cap(*b) = BAG_CAPACITY;
    }
}

void pintuEffect(int mapRows, int mapCols, int time, ListLoc locL, Location *curLoc, Matrix adjM, ToDoList todoL, InProgressList progL){
// I.S. Pintu Kemana Saja dipilih dalam prosedur useGadget
/* F.S. Berhasil berpindah ke lokasi lain, waktu tidak bertambah */
    /* KAMUS */
    Location targetLoc;
    /* ALGORITMA */
    //displayMap(mapRows, mapCols, time, locL, *curLoc, adjM, todoL, progL);
    printf("\nIngin berpindah ke lokasi mana?\n\nENTER COMMAND : ");

    startWord();

    while(currentWord.length!=1 || !isInListLoc(locL,currentWord.contents[0])){
        printf("Lokasi tidak valid. Masukkan lokasi yang valid!\nENTER COMMAND : ");
        startWord();
    }

    getLocationFromList(locL, curLoc, currentWord.contents[0]);
}

void mesinWaktuEffect(int *time){
// I.S. Mesin Waktu dipilih dalam prosedur useGadget
/* F.S. Jika item paling atas dalam tas ialah perishible item, waktu hangusnya kembali ke semula */
    /* KAMUS */
    /* ALGORITMA */
    if(*time > 50) *time -= 50;
    else *time = 0;
}