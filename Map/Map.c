#include "Map.h"

void MakeBMap(BuildMap *Map)
{
    //GRABBING INFO FROM FILE
    int n,m,Nbuildings;
    TabBuildings Arrb;
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
        char type = Arrb.TI[i].buildingsType;
        int x = Arrb.TI[i].position.X;
        int y = Arrb.TI[i].position.Y;
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


    MakeEmptyGraf(&(*Map).G);
    for(int i =1 ;i<=Nbuildings;i++)
    {
        AddMotherLast(&(*Map).G);
        for(int j =1;j<=Nbuildings;j++)
        {
            if(Mgraf.Mem[i][j]==1)
            {
                AddNewChild(&(*Map).G,i,j);
            }
        }
    }
}
/*
{I.S Anything}
{F.S Matrix of Building Initiated by empty Building}
*/

void UpdateMap (BuildMap *Map,TabBuildings b)
{
    for (int i = 1 ; i<= b.MaxEl ; i++) //add Building From File
    {
        Buildings Temp;
        char type = b.TI[i].buildingsType;
        int x = b.TI[i].position.X;
        int y = b.TI[i].position.Y;
        CreateBuildings(&Temp,type);
        Temp.owner = b.TI[i].owner;
        Temp.armies = b.TI[i].armies;
        Temp.level = b.TI[i].level;
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
}
/*
{I.S Defined}
{F.S Update Map with new Building Information}
*/

void PrintMap(BuildMap Map)
{
    printf("   ");
    print_cyan('\\');
    for (int j = 1; j <= Map.NKolEff+2 ; j++){
		print_cyan('=');
	}
    print_cyan('/');
	printf("\n");
	
	for (int i = 1; i <= Map.NBrsEff; i++){
        printf("   ");
		print_cyan('|');
        printf(" ");
		for (int j = 1; j <= Map.NKolEff; j++){
			if (Map.M[i][j].owner == 1)
				print_blue(Map.M[i][j].buildingsType);
			else if (Map.M[i][j].owner == 2)
				print_red(Map.M[i][j].buildingsType);
			else
				printf("%c",Map.M[i][j].buildingsType);
		}
        printf(" ");
        print_cyan('|');
		printf("\n");
	}
    printf("   ");
	print_cyan('/');
	for (int j = 1; j <= Map.NKolEff+2 ; j++){
		print_cyan('=');
	}
    print_cyan('\\');
	printf("\n");
	printf("\n");
}
/*
{I.S Map defined}
{F.S Map Printed}
*/
