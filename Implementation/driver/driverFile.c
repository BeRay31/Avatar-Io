#include <stdio.h>
#include "../../include1/boolean.h"
#include "../../include1/load.h"

//load (int *n, int *m, int *nbangunan, TabBuildings *b, MATRIKS *mgraf, Queue *q1, Queue *q2)

int main()
{
    /*
    List P1Buildings,P2Buildings;
    BuildMap Peta;
    int n,m,nbuildings;
    TabBuildings arrBuildings;
    MATRIKS graf;
    Stack S;
    */
    int n, m, nbangunan;
    TabBuildings b;
    MATRIKS mgraf;
    Queue q1, q2;
    load (&n, &m, &nbangunan, &b, &mgraf, &q1, &q2);
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
    for (int i=1; i<=mgraf.NBrsEff; i++){
		for (int j=1; j<=mgraf.NKolEff; j++){
			if (j==mgraf.NKolEff) {
				printf("%d\n",mgraf.Mem[i][j]);
			} else {
				printf("%d ",mgraf.Mem[i][j]);
			}
		}
	}
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

    /*
    SCreateEmpty(&S);
    InsertLast(&P1Buildings,AllocateL(1));//Initiate and allocate Building index 1 == owner P1
    InsertLast(&P2Buildings,AllocateL(2));//Initiate and allocate Building index 2 == owner P2
    InsertLast(&P1Buildings,AllocateL(13));
    InsertLast(&P2Buildings,AllocateL(17));
    GetInfoDariFile(&n,&m,&nbuildings,&arrBuildings,&graf);
    printf("%d %d\n",n,m );
    printf("%d\n",nbuildings);
    TulisTabBuilding(arrBuildings);
    TulisMATRIKS(graf);
    printf("\n");
    */
    /*
    Save(arrBuildings, graf, n, m, nbuildings);
    return 0;
    */
    /*
    UpdateLoadBuilding(&arrBuildings);
    arrBuildings.TI[1].armies = 80;
    arrBuildings.TI[13].armies = 40;
    arrBuildings.TI[13].owner = 1;
    arrBuildings.TI[17].armies =40;
    arrBuildings.TI[17].owner=2;
    MakeBMap(&Peta);
    UpdateMap(&Peta,arrBuildings);
    PrintMap(Peta);
    EksekusiCommand(1,Peta.G,1,&P1Buildings,&P2Buildings,&arrBuildings,&S);
    UpdateMap(&Peta,arrBuildings);
    PrintMap(Peta);
    EksekusiCommand(1,Peta.G,1,&P1Buildings,&P2Buildings,&arrBuildings,&S);
    UpdateMap(&Peta,arrBuildings);
    PrintMap(Peta);
    EksekusiCommand(1,Peta.G,2,&P1Buildings,&P2Buildings,&arrBuildings,&S);
    */
   return 0;
}

// gcc driverFile.c mesinkar.c mesinkata.c loadinfoawal.c Buildings.c point.c matriks.c save.c load.c -o run