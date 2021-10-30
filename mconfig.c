#include "config.h"

int main() {
    ListLoc l;
    Matrix adj;
    int rows = -1;
    int cols = -1;
    CreateListLoc(&l, 20);
    readConfig("config.txt", &l, &rows, &cols, &adj);
    printf("%d %d\n", rows, cols);
    displayListLoc(l);
    printf("\n");
    displayMatrix(adj);

    return 0;
}