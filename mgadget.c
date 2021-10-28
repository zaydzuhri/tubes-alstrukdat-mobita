#include<stdio.h>
#include "gadget.h"

int main(){
    GadgetList Inventory;
    int money = 5000;
    CreateInventory(&Inventory);

    displayShop(&Inventory, &money);
    displayInventory(&Inventory);
}