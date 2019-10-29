#include <stdio.h>
#include "boolean.h"
#include "infofileeksternal.h"
#include "save.h"

int BoolToInt (boolean True)
{
	if (True){
		return 1;
	} else {
		return 0;
	}
}

void Save (BuildingsArr CurrentBuilding, MATRIKS Graf)
// p.s. dalam main program dipake
// include header dari infofileeksternal
// untuk dapet position
{
	/* open file for writing */
	fp = fopen("save_file.dat","w");
	/* write into file */
	/* write building info */
	for (int i=1; i<=CurrentBuilding.MaxEl; i++){
		fprintf(fp, "%d ", CurrentBuilding.T[i].owner);
		fprintf(fp, "%d ", CurrentBuilding.T[i].armies);
		fprintf(fp, "%d ", CurrentBuilding.T[i].level);
		fprintf(fp, "%d ", CurrentBuilding.T[i].incArmy);
		fprintf(fp, "%d ", CurrentBuilding.T[i].maxArmyOnBuildings);
		// p.s. defense dikonverse dari bool jadi integer
		fprintf(fp, "%d ", BoolToInt(CurrentBuilding.T[i].defenses));
		fprintf(fp, "%d ", CurrentBuilding.T[i].minArmiesToOccupy);
		fprintf(fp, "%c ", CurrentBuilding.T[i].buildingsType);
		fprintf(fp, "%d ", CurrentBuilding.T[i].buildingsIndex);
		fprintf(fp, "%d ", CurrentBuilding.T[i].position.X);
		fprintf(fp, "%d\n", CurrentBuilding.T[i].position.Y);
	}
	/* write graf keterhubungan */
	for (int i=1; i<=Graf.NBrsEff; i++){
		for (int j=1; j<=Graf.NKolEff; j++){
			if (j==Graf.NKolEff) {
				fprintf(fp, "%d\n",Graf.Mem[i][j]);
			} else {
				fprintf(fp, "%d ",Graf.Mem[i][j]);
			}
		}
	}
	/* close file */
	fclose(fp);
}