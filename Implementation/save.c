#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/Queue.h"
#include "../include1/loadinfoawal.h"
#include "../include1/save.h"

// gcc driverFile.c mesinkar.c mesinkata.c loadinfoawal.c Buildings.c point.c matriks.c save.c -o run

void Save (TabBuildings CurrentBuilding, int N, int M, int NBuilding, Queue q1, Queue q2, int Turn)
// p.s. dalam main program dipake
// include header dari loadinfoawal
// untuk dapet position
{
	/* open file for writing */
	fp = fopen("driver-save.dat","w");
	/* write into file */
	/* write ukuran peta */
	fprintf(fp, "%d ", N);
	fprintf(fp, "%d\n",M);
	/* write banyak building */
	fprintf(fp, "%d\n", NBuilding);
	/* write building info */
	for (int i=1; i<=CurrentBuilding.MaxEl; i++){
		fprintf(fp, "%d ", CurrentBuilding.TI[i].owner);
		fprintf(fp, "%d ", CurrentBuilding.TI[i].armies);
		fprintf(fp, "%d ", CurrentBuilding.TI[i].level);
		fprintf(fp, "%d ", CurrentBuilding.TI[i].incArmy);
		fprintf(fp, "%d ", CurrentBuilding.TI[i].maxArmyOnBuildings);
		// p.s. defense dikonverse dari bool jadi integer
		fprintf(fp, "%d ", BoolToInt(CurrentBuilding.TI[i].defenses));
		fprintf(fp, "%d ", CurrentBuilding.TI[i].minArmiesToOccupy);
		fprintf(fp, "%c ", CurrentBuilding.TI[i].buildingsType);
		fprintf(fp, "%d ", CurrentBuilding.TI[i].buildingsIndex);
		fprintf(fp, "%d ", CurrentBuilding.TI[i].position.X);
		fprintf(fp, "%d\n", CurrentBuilding.TI[i].position.Y);
	}
	/* write graf keterhubungan 
	for (int i=1; i<=Graf.NBrsEff; i++){
		for (int j=1; j<=Graf.NKolEff; j++){
			if (j==Graf.NKolEff) {
				fprintf(fp, "%d\n",Graf.Mem[i][j]);
			} else {
				fprintf(fp, "%d ",Graf.Mem[i][j]);
			}
		}
	} */
	/* menyimpan queue */
	// q1
	fprintf(fp, "%d\n", NBElmtQ(q1));
	for (int i=1; i<=NBElmtQ(q1); i++) {
		if (i == NBElmtQ(q1)) {
			fprintf(fp, "%d\n", q1.T[i]);
		} else {
			fprintf(fp, "%d ", q1.T[i]);
		}
	}
	// q2
	fprintf(fp, "%d\n", NBElmtQ(q2));
	for (int i=1; i<=NBElmtQ(q2); i++) {
		if (i == NBElmtQ(q2)) {
			fprintf(fp, "%d\n", q2.T[i]);
		} else {
			fprintf(fp, "%d ", q2.T[i]);
		}
	}
	fprintf(fp, "%d\n", Turn);
	/* close file */
	fclose(fp);
}