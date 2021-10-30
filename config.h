#include "daftarpesanan.h"
#include "listdinloc.h"
#include "matrix.h"
#include "queue.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

#define input currentWord.contents

void readConfig(char fileName[20], ListLoc *listLoc, int *mapRows, int *mapCols, Matrix *adjMat, DaftarPesanan *daftarPesanan);