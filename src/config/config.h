#include "../daftarpesanan/daftarpesanan.h"
#include "../listdinloc/listdinloc.h"
#include "../matrix/matrix.h"
#include "../queue/queue.h"
#include "../wordmachine/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

#define input currentWord.contents

void readConfig(char fileName[20], ListLoc *listLoc, int *mapRows, int *mapCols, Matrix *adjMat, DaftarPesanan *daftarPesanan);