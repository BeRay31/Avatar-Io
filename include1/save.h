#ifndef SAVE_H
#define SAVE_H

#include "boolean.h"
#include "loadinfoawal.h"
#include "Queue.h"

static FILE * fp; // dalam main program dipake

void Save (TabBuildings CurrentBuilding, int N, int M, int NBuilding, Queue q1, Queue q2, int Turn);

#endif