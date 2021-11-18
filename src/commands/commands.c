#include "commands.h"
#include <stdlib.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int heavyItems, int *speedBoostDur, int *time, InProgressList *inProgress, Bag *bag) {
    printf("Posisi yang dapat dicapai:\n");

    ListLoc adjLocList;
    CreateListLoc(&adjLocList, 30);
    getAdjacentLocations(adjMat, locList, &adjLocList, *currentLoc);
    displayListLoc(adjLocList, *currentLoc);

    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
    boolean loop = true;
    boolean exit = false;
    while (loop) {
        printf("ENTER COMMAND: ");
        startWord();

        if (isInListLoc(adjLocList, currentWord.contents[0])) {
            getLocationFromList(adjLocList, currentLoc, currentWord.contents[0]);
            printf("\nMobita sekarang berada di titik ");
            displayLocation(*currentLoc);
            printf("\n");
            loop = false;
        } else if (isSameString(currentWord, "0")) {
            exit = true;
            loop = false;
        } else {
            printf("Posisi yang dipilih tidak valid. Silahkan ulangi.\n\n");
        }
    }

    if (!exit) {
        addTime(time, speedBoostDur, heavyItems, inProgress, bag);
    }
}

void pick_up(Bag *bag, ToDoList *tdlist, InProgressList *inplist, Location l, int *heavyItemsAmount) {
    if (isBagFull(*bag)) {
        printf("Tas Sudah Penuh ! Antarkan pesanan dahulu !");
        printf("\n");
    }

    else {
        boolean pick = true;
        boolean pickUpSuccess;
        Pesanan pesanan;
        Address pos = *tdlist;

        pickUpUpdateToDoList(tdlist, l, &pesanan, &pickUpSuccess);
        if (pickUpSuccess) {
            pushBag(bag, pesanan);
            char jenisItem = JENIS_ITEM(pesanan);
            pick = false;
            switch (jenisItem) {
            case 'N':
                printf("Pesanan berupa Normal Item berhasil di pick up!");
                break;
            case 'H':
                *heavyItemsAmount += 1;
                printf("Pesanan berupa Heavy Item berhasil di pick up!");
                break;
            case 'P':
                printf("Pesanan berupa Perishable item berhasil di pick up!");
                break;
            case 'V':
                printf("Pesanan berupa VIP Item berhasil di pick up!");
                break;
            default:
                printf("Pesanan berhasil di pick up!");
                break;
            }
            printf("\n");
            AddToInProgressList(inplist, pesanan);
        } else {
            printf("Tidak ada pesanan di lokasi ini.\n");
        }
    }
}

void drop_off(Bag *bag, Location l, InProgressList *inProgress, int *heavyItemsAmount, int *uang, int *speedBoostDur, int *amountDropped) {
    if (isBagEmpty(*bag)) {
        printf("Tidak ada pesanan yang dapat diantarkan!");
    } else {
        Pesanan p;
        char jenis[15] = "item";
        popBag(bag, &p);
        if (!(isSameLoc(l, DROP_OFF_LOCATION(p)))) {
            pushBag(bag, p);
            printf("Lokasi salah!");
        } else {
            switch (JENIS_ITEM(p)) {
            case 'N':
                printf("Pesanan Normal Item berhasil diantarkan");
                *uang += 200;
                *amountDropped++;
                break;
            case 'H':
                printf("Pesanan Heavy Item berhasil diantarkan");
                *heavyItemsAmount -= 1;
                *uang += 400;
                *speedBoostDur += 10;
                *amountDropped++;
                break;
            case 'P':
                printf("Pesanan Perishable Item berhasil diantarkan");
                *uang += 400;
                increaseMaxCapacity(bag);
                *amountDropped++;
                break;
            case 'V':
                printf("Pesanan VIP Item berhasil diantarkan");
                *uang += 600;
                *amountDropped++;
                break;
            default:
                break;
            }
            removeFromInProgressList(inProgress, p);
        }
    }
}

void help() {
    printf("COMMMANDS:\n");
    printf("1. MOVE         : Untuk berpindah ke lokasi lain pada map\n");
    printf("2. MAP          : Untuk melihat map dan lokasi player\n");
    printf("3. PICK_UP      : Untuk mengambil pesanan di lokasi sekarang\n");
    printf("4. DROP_OFF     : Untuk mengantarkan pesanan di lokasi sekarang\n");
    printf("5. TO_DO        : Untuk melihat pesanan dalam to-do list\n");
    printf("6. IN_PROGRESS  : Untuk melihat pesanan yang sedang diantar\n");
    printf("7. BUY          : Untuk membeli gadget, hanya dapat dibuka di headquarters\n");
    printf("8. INVENTORY    : Untuk melihat gadget yang dimiliki\n");
    printf("9. HELP         : Untuk melihat semua command yang tersedia\n");
    printf("10. EXIT        : Untuk keluar dari game loop\n");
}