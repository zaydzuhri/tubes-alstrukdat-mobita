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