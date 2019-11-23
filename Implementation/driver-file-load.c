#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/load.h"


int main()
{
    int n, m, nbangunan;
    TabBuildings b;
    Queue q1, q2;
    int turn;
    load (&n, &m, &nbangunan, &b, &q1, &q2, &turn);
    printf("%d ", n); printf("%d\n", m);
    printf("%d\n", nbangunan);
    for (int i=1; i<=nbangunan; i++){
		printf("%d ", b.TI[i].owner);
		printf("%d ", b.TI[i].armies);
		printf("%d ", b.TI[i].level);
		printf("%d ", b.TI[i].incArmy);
		printf("%d ", b.TI[i].maxArmyOnBuildings);
		// p.s. defense dikonverse dari bool jadi integer
		printf("%d ", BoolToInt(b.TI[i].defenses));
		printf("%d ", b.TI[i].minArmiesToOccupy);
		printf("%c ", b.TI[i].buildingsType);
		printf("%d ", b.TI[i].buildingsIndex);
		printf("%d ", b.TI[i].position.X);
		printf("%d\n", b.TI[i].position.Y);
	}
    // q1
    printf("%d\n", NBElmtQ(q1));
	for (int i=1; i<=NBElmtQ(q1); i++) {
		if (i == NBElmtQ(q1)) {
			printf("%d\n", q1.T[i]);
		} else {
			printf("%d ", q1.T[i]);
		}
	}
	// q2
	printf("%d\n", NBElmtQ(q2));
	for (int i=1; i<=NBElmtQ(q2); i++) {
		if (i == NBElmtQ(q2)) {
			printf("%d\n", q2.T[i]);
		} else {
			printf("%d ", q2.T[i]);
		}
	}
}