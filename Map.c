#include "Map.h"


void MakeBMap(BuildMap *Map)
{
    //GRABBING INFO FROM FILE
    int n,m,Nbuildings;
    BuildingsArr Arrb;
    MATRIKS Mgraf;
    Buildings BTemp;
    GetInfoDariFile(&n,&m,&Nbuildings,&Arrb,&Mgraf);
    (*Map).NBrsEff = n;
    (*Map).NKolEff = m;

    //EDIT BUILDING ON MAP
    for (int i = 1 ; i<= (*Map).NBrsEff;i++)  //initiating Empty Building
    {
        for (int j = 1;j <= (*Map).NKolEff;j++)
        {
            CreateBuildings(&BTemp,' ');
            BTemp.position.X = i;
            BTemp.position.Y = j;
            (*Map).M[i][j] = BTemp;
        }
    }

    for (int i = 1 ; i<= Nbuildings ; i++) //add Building From File
    {
        Buildings Temp;
        char type = Arrb.T[i].buildingsType;
        int x = Arrb.T[i].position.X;
        int y = Arrb.T[i].position.Y;
        CreateBuildings(&Temp,type);
        Temp.position.X = x;
        Temp.position.Y = y;
        if (i == 1)
        {
            Temp.owner = 1;
        }
        else if (i == 2)
        {
            Temp.owner = 2;
        }
        (*Map).M[x][y] = Temp;
    }
	
    //EDIT GRAPH
    CreateEmptyGraph((*Map).G,Nbuildings);
    for (int i = 1; i <= Nbuildings;i++)
    {
        for (int j = 1;j<= Nbuildings ;j++)
        {
            if (Mgraf.Mem[i][j]==1)
            {
                addGraph(Map->G,i,j);
            }
        }
    }

}
/*
{I.S Anything}
{F.S Matrix of Building Initiated by empty Building}
*/

void PrintMap(BuildMap Map)
{
    for (int j = 1; j <= Map.NKolEff+2 ; j++){
		printf("*");
	}
	printf("\n");
	
	for (int i = 1; i <= Map.NBrsEff; i++){
		printf("*");
		for (int j = 1; j <= Map.NKolEff; j++){
			if (Map.M[i][j].owner == 1)
				print_blue(Map.M[i][j].buildingsType);
			else if (Map.M[i][j].owner == 2)
				print_red(Map.M[i][j].buildingsType);
			else
				printf("%c",Map.M[i][j].buildingsType);
		}
		printf("*\n");
	}
	
	for (int j = 1; j <= Map.NKolEff+2 ; j++){
		printf("*");
	}
	printf("\n");
}
/*
{I.S Map defined}
{F.S Map Printed}
*/
