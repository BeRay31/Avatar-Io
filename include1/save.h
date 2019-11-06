#ifndef SAVE_H
#define SAVE_H

#include "boolean.h"
#include "loadinfoawal.h"

static FILE * fp; // dalam main program dipake

void Save (BuildingsArr CurrentBuilding, MATRIKS Graf, int N, int M, int NBuilding);

#endif