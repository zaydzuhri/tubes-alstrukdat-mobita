#include "bag/bag.h"
#include "commands/commands.h"
#include "config/config.h"
#include "daftarpesanan/daftarpesanan.h"
#include "gadget/gadget.h"
#include "inprogresslist/inprogresslist.h"
#include "listdinloc/listdinloc.h"
#include "map/map.h"
#include "matrix/matrix.h"
#include "queue/queue.h"
#include "time/time.h"
#include "todolist/todolist.h"
#include "wordmachine/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define input currentWord.contents

int main() {
    /*KAMUS*/
    ListLoc locList;
    Matrix adjMatrix;
    DaftarPesanan dafPesananBefore;
    DaftarPesanan dafPesananAfter;
    ToDoList toDo;
    InProgressList inProgress;
    Bag bag;
    GadgetList inventory;

    int mapRows = 0;
    int mapCols = 0;
    int capTas = 3;
    int heavyItemsAmount = 0;

    int amountDropped = 0;
    int money = 0;
    int time = 0;

    int speedBoostDur = 0;

    boolean gameLoop = false;

    Location currentLoc;

    /*ALGORITMA*/
    system("color F0");
    printf("           Selamat datang di permainan\n");
    printf("_______________       _____________________________ \n");
    printf("__  ____/_  __ \\      ___  __ )___  _/__  __/__    |\n");
    printf("_  / __ _  / / /________  __  |__  / __  /  __  /| |\n");
    printf("/ /_/ / / /_/ /_/_____/  /_/ /__/ /  _  /   _  ___ |\n");
    printf("\\____/  \\____/        /_____/ /___/  /_/    /_/  |_|\n\n");
    printf("           Bantu Mobita mengantarkan\n        pesanan-pesanan usaha orang tuanya!\n");
    printf("===================================================\n");
    printf("||                                               ||\n");
    printf("||                 MENU UTAMA                    ||\n");
    printf("||                                               ||\n");
    printf("||                1. NEW_GAME                    ||\n");
    printf("||                  2. EXIT                      ||\n");
    printf("||                                               ||\n");
    printf("===================================================\n");
    printf("ENTER COMMAND: ");
    startWord();
    while (!isSameString(currentWord, "NEW_GAME") && !isSameString(currentWord, "EXIT")) {
        printf("Command not recognized!\nENTER NEW COMMAND: ");
        startWord();
    }
    if (isSameString(currentWord, "NEW_GAME")) {
        printf("Masukkan nama file konfigurasi level (jangan lupa \".txt\") : ");
        startWord();
        while (!(access(currentWord.contents, F_OK) != -1)) {
            printf("Nama file tidak valid!\n");
            printf("Masukkan kembali nama file konfigurasi level (jangan lupa \".txt\") : ");
            startWord();
        }
        CreateListLoc(&locList, 30);
        createDaftarPesanan(&dafPesananBefore);
        createDaftarPesanan(&dafPesananAfter);
        CreateBag(&bag);
        createToDoList(&toDo);
        createInProgressList(&inProgress);
        CreateInventory(&inventory);

        readConfig(currentWord.contents, &locList, &mapRows, &mapCols, &adjMatrix, &dafPesananBefore);

        getLocationFromList(locList, &currentLoc, '8');
        gameLoop = true;
        printf("Loading");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".\n");
        printf("Loading success!\n");
        sleep(1);
        printf("Selamat membantu Mobita mengantarkan pesanan!\n");
        sleep(1);
        printf("              ___\n");
        printf("             /  _\\\n");
        printf("             | /\\_|\n");
        printf("          __-'' _'\n");
        printf("         ----'-.\n");
        printf("            |#\\#)_,_\n");
        printf("            )##\\__ _\\__.-. \n");
        printf("    -  .-  (###)   '---.  `.\n");
        printf(" -   __\\____`.#\\(      )  L(|\n");
        printf("   .'__//\\    \\#)`-._.' / \\\\==.\n");
        printf("  /_/_//\\_\\_  /#/  ### / //\\\\ \\\n");
        printf("   |(________(##)___/-' '| (_) |\n");
        printf("____\\___/_________________\\___/________________________________________\n");
    }
    while (gameLoop) {
        printf("\nWaktu: %d\n", time);
        printf("ENTER COMMAND: ");
        startWord();

        if (isSameString(currentWord, "MOVE")) {
            move(locList, adjMatrix, &currentLoc, heavyItemsAmount, &speedBoostDur, &time, &inProgress, &bag);

        } else if (isSameString(currentWord, "MAP")) {
            displayMap(mapRows, mapCols, locList, currentLoc, adjMatrix, toDo, bag);

        } else if (isSameString(currentWord, "PICK_UP")) {
            pick_up(&bag, &toDo, &inProgress, currentLoc, &heavyItemsAmount);

        } else if (isSameString(currentWord, "DROP_OFF")) {
            drop_off(&bag, currentLoc, &inProgress, &heavyItemsAmount, &money, &speedBoostDur, &amountDropped);

        } else if (isSameString(currentWord, "TO_DO")) {
            displayToDoList(toDo);

        } else if (isSameString(currentWord, "IN_PROGRESS")) {
            displayInProgressList(inProgress);

        } else if (isSameString(currentWord, "BUY")) {
            if (currentLoc.locName == '8') {
                displayShop(&inventory, &money);
            } else {
                printf("Command ini hanya dapat dipanggil di Headquarters.\n");
            }

        } else if (isSameString(currentWord, "INVENTORY")) {
            displayInventory(&inventory);
            useGadget(&inventory, dafPesananAfter, &bag, mapRows, mapCols, &time, locList, &currentLoc, adjMatrix, toDo, &inProgress);

        } else if (isSameString(currentWord, "HELP")) {
            help();

        } else if (isSameString(currentWord, "EXIT")) {
            printf("Apakah Anda yakin ingin meninggalkan game? Sesi ini tidak akan tersimpan. (y/n): ");
            startWord();
            while (!isSameString(currentWord, "y") && !isSameString(currentWord, "n")) {
                printf("Command salah, silahkan ulangi.\n");
                startWord();
            }
            if (isSameString(currentWord, "y")) {
                gameLoop = false;
            }

        } else {
            printf("Command salah, silahkan ulangi.\n");
        }

        timeUpdateToDoList(&toDo, &dafPesananBefore, &dafPesananAfter, time);

        if (isDaftarPesananEmpty(dafPesananBefore) && isToDoListEmpty(toDo) && isInProgressListEmpty(inProgress)) {
            printf("░█████╗░░█████╗░███╗░░██╗░██████╗░██████╗░░█████╗░████████╗██╗░░░██╗██╗░░░░░░█████╗░████████╗██╗░█████╗░███╗░░██╗░██████╗\n");
            printf("██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔══██╗╚══██╔══╝██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║██╔════╝\n");
            printf("██║░░╚═╝██║░░██║██╔██╗██║██║░░██╗░██████╔╝███████║░░░██║░░░██║░░░██║██║░░░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║╚█████╗░\n");
            printf("██║░░██╗██║░░██║██║╚████║██║░░╚██╗██╔══██╗██╔══██║░░░██║░░░██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║░╚═══██╗\n");
            printf("╚█████╔╝╚█████╔╝██║░╚███║╚██████╔╝██║░░██║██║░░██║░░░██║░░░╚██████╔╝███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║██████╔╝\n");
            printf("░╚════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═════╝░\n");
            printf("Kamu sudah berhasil membantu Mobita mengantarkan seluruh pesanan usaha orang tuanya! \n");
            sleep(1);
            while (LOC_NAME(currentLoc) != '8') {
                printf("Kembali ke Headquarters untuk menyelesaikan game ini !\n");
                move(locList, adjMatrix, &currentLoc, heavyItemsAmount, &speedBoostDur, &time, &inProgress, &bag);
            }
            printf("Terimakasih sudah membantu Mobita mengantarkan ");
            printf("%d item", &amountDropped);
            printf(" selama %d satuan waktu !\n", &time);
            sleep(1);
            printf("░██████╗███████╗███████╗  ██╗░░░██╗  ██╗░░░░░░█████╗░████████╗███████╗██████╗░\n");
            printf("██╔════╝██╔════╝██╔════╝  ██║░░░██║  ██║░░░░░██╔══██╗╚══██╔══╝██╔════╝██╔══██╗\n");
            printf("╚█████╗░█████╗░░█████╗░░  ██║░░░██║  ██║░░░░░███████║░░░██║░░░█████╗░░██████╔╝\n");
            printf("░╚═══██╗██╔══╝░░██╔══╝░░  ██║░░░██║  ██║░░░░░██╔══██║░░░██║░░░██╔══╝░░██╔══██╗\n");
            printf("██████╔╝███████╗███████╗  ╚██████╔╝  ███████╗██║░░██║░░░██║░░░███████╗██║░░██║\n");
            printf("╚═════╝░╚══════╝╚══════╝  ░╚═════╝░  ╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n");
            fflush(stdout);
            sleep(3);
            gameLoop = false;
        }
    }
    return 0;
}