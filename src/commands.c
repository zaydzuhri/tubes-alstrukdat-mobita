#include "commands.h"
#include <stdlib.h>

void move(ListLoc locList, Matrix adjMat, Location *currentLoc, int *time, int heavyItems, boolean isSpeedBoost, int speedBoostCount) {
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
        if (isSpeedBoost) {
            if (speedBoostCount % 2 != 0) {
                *time++;
            }
            speedBoostCount++;
        } else {
            *time += 1 + heavyItems;
        }
    }
}

void pick_up(Bag bag, ToDoList tdlist, Location l, int *heavyItemsAmount){
    if(isBagFull(bag)){
        printf("Tas Sudah Penuh ! Antarkan pesanan dahulu !");
        printf("\n");
    }

    else{
        boolean pick = true;
        Address pos = tdlist;
        while(pos != NULL && pick){
            if(LOC_NAME(PICK_UP_LOCATION(INFO(pos))) == LOC_NAME(l)){
                pushBag(&bag,INFO(pos));
                char jenisItem = JENIS_ITEM(INFO(pos));
                pick = false;
                switch (JENIS_ITEM(INFO(pos)))
                {
                case 'n':
                    printf("Pesanan berupa Normal Item berhasil di pick up!");
                    break;
                case 'h':
                    *heavyItemsAmount++;
                    printf("Pesanan berupa Heavy Item berhasil di pick up!");
                    break;
                case 'p':
                    printf("Pesanan berupa Perishable item berhasil di pick up!");
                    break;
                case 'v':
                    printf("Pesanan berupa VIP Item berhasil di pick up!");
                    break;
                default:
                    printf("Pesanan berhasil di pick up!");
                    break;
                }
                printf("\n");
            }else{
                pos = NEXT(pos);
            }
        }
    }
}

void drop_off(Bag bag, Location l, int *heavyItemsAmount, int *uang){
    if(isBagEmpty(bag)){
        printf("Tidak ada pesanan yang dapat diantarkan!");
    }else{
        Pesanan p;
        char jenis[15] = "item";
        popBag(&bag, &p);
        if(!(isSameLoc(l, DROP_OFF_LOCATION(p)))){
            pushBag(&bag, p);
            printf("Lokasi salah!");
        }else{
            switch (JENIS_ITEM(p))
            {
            case 'n':
                strcpy(jenis, "Normal Item");
                *uang += 200;
                break;
            case 'h':
                strcpy(jenis, "Heavy Item");
                *heavyItemsAmount--;
                *uang += 400;
                break;
            case 'p':
                strcpy(jenis, "Perishable Item");
                *uang += 400;
                increaseMaxCapacity(&bag);
                break;
            case 'v':
                strcpy(jenis, "VIP Item");
                *uang += 600;
                break;
            default:
                break;
            }
            printf("Pesanan %c berhasil diantarkan", jenis);
        }
    }

}