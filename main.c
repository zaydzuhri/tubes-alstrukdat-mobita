#include "commands.h"
#include "config.h"
#include "daftarpesanan.h"
#include "inprogresslist.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "todolist.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

#define input currentWord.contents

int main() {
    ListLoc locList;
    Matrix adjMatrix;
    DaftarPesanan dafPesanan;
    ToDoList toDo;
    InProgressList inProgress;

    int mapRows = 0;
    int mapCols = 0;
    int capTas = 3;
    int heavyItemsAmount = 0;

    int time = 0;

    int speedBoostCount = 0;
    boolean isSpeedBoost = false;

    boolean gameLoop = true;

    Location currentLoc;

    CreateListLoc(&locList, 30);
    createQueue(&dafPesanan);
    readConfig("config.txt", &locList, &mapRows, &mapCols, &adjMatrix, &dafPesanan);

    getLocationFromList(locList, &currentLoc, '8');

    while (gameLoop) {
        printf("\nWaktu: %d\n", time);
        printf("ENTER COMMAND: ");
        startWord();

        if (isSameString(currentWord, "MOVE")) {
            move(locList, adjMatrix, &currentLoc, &time, heavyItemsAmount, isSpeedBoost, speedBoostCount);

        } else if (isSameString(currentWord, "EXIT")) {
            printf("Apakah Anda yakin ingin meninggalkan game? Sesi ini tidak akan tersimpan. (y/n): ");
            startWord();
            if (isSameString(currentWord, "y")) {
                gameLoop = false;
            }

        } else {
            printf("Command salah, silahkan ulangi.\n");
        }
    }
    return 0;
}