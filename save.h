#ifndef SAVE_H
#define SAVE_H

#include "boolean.h"
#include "infofileeksternal.h"

static FILE * fp; // dalam main program dipake

int BoolToInt (boolean True);

void Save (BuildingsArr CurrentBuilding, MATRIKS Graf);

#endif