#include "commands.h"

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

void pick_up(Bag bag, ToDoList tdlist, Location l){
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
                pick = false;
                printf("Pesanan berhasil di pick up!");
                printf("\n");
            }else{
                pos = NEXT(pos);
            }
        }
    }
}

void drop_off();