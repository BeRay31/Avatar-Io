#ifndef SAVE_H
#define SAVE_H

#include "../Booelan/boolean.h"
#include "../LoadInfoAwal/loadinfoawal.h"
#include "../Queue/Queue.h"

static FILE * fp; // dalam main program dipake

void Save (TabBuildings CurrentBuilding, int N, int M, int NBuilding, Queue q1, Queue q2, int Turn);

#endif