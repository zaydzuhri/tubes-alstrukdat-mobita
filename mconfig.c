#include "config.h"

int main() {
    ListLoc l;
    Matrix adj;
    DaftarPesanan dp;
    int rows = -1;
    int cols = -1;
    CreateListLoc(&l, 30);
    createQueue(&dp);
    readConfig("config.txt", &l, &rows, &cols, &adj, &dp);
    printf("%d %d\n", rows, cols);
    displayListLoc(l);
    printf("\n");
    displayMatrix(adj);
    printf("\n");
    int dpLen = queueLength(dp);
    for (int i = 0; i < dpLen; i++) {
        PendingPesanan pPesanan;
        dequeueDaftarPesanan(&dp, &pPesanan);
        printf("[%d,%d,%c,%c,%c,%d]\n", KODE_PESANAN(PESANAN(pPesanan)), WAKTU_MASUK(pPesanan), PICK_UP_LOCATION(PESANAN(pPesanan)).locName, DROP_OFF_LOCATION(PESANAN(pPesanan)).locName, JENIS_ITEM(PESANAN(pPesanan)), WAKTU_HANGUS(PESANAN(pPesanan)));
    }

    return 0;
}