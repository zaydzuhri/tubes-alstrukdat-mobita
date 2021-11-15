#include<stdio.h>
#include "../gadget.h"

int main(){
    GadgetList Inventory;
    int money = 5000;
    DaftarPesanan dp;
    Bag b;
    int mapRows, mapCols;
    int time;
    ListLoc locL;
    Location curLoc;
    Matrix adjM;
    ToDoList todoL;
    InProgressList progL;
    CreateInventory(&Inventory);

    displayShop(&Inventory, &money);
    displayInventory(&Inventory);
    useGadget(&Inventory, dp, &b, mapRows, mapCols, &time, locL, &curLoc, adjM, todoL, progL);
}