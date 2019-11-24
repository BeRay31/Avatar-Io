#include <stdio.h>
#include "../Booelan/boolean.h"
#include "loadinfoawal.h"


int main()
{
    int n, m, nbangunan;
    TabBuildings b;
    MATRIKS mgraf;
    int turn;
    GetInfoDariFile(&n, &m, &nbangunan, &b, &mgraf);
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
    TulisMATRIKS(mgraf);
}