#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include1/Buildings.h"
#include "../include1/matriks.h"
#include "../include1/Map.h"
#include "../include1/Graph.h"
#include "../include1/loadinfoawal.h"
#include "../include1/GameMech.h"
int main()
{
    int n, m, nbangunan;
    int Turn = 1;
	TabBuildings ArrOfBuildings;
	MATRIKS mgraf;
    Kata command;
    BuildMap Map;
    List P1Buildings,P2Buildings;
    GetInfoDariFile (&n, &m, &nbangunan, &ArrOfBuildings, &mgraf);
    UpdateLoadBuilding(&ArrOfBuildings);
    MakeBMap(&Map);
    InsertLast(&P1Buildings,AllocateL(1));//Initiate and allocate Building index 1 == owner P1
    InsertLast(&P2Buildings,AllocateL(2));//Initiate and allocate Building index 2 == owner P2
    while(NotEnd(ArrOfBuildings)){
        PrintMap(Map);
        if(Turn == 1){    
           do
            {
                 InputString(&command);
                 EksekusiCommand(OlahString(command),Map.G,Turn,&P1Buildings,&P2Buildings,&ArrOfBuildings);
                
            } while (NotEndTurn(OlahString(command)));     
        }
        else{
             do
            {
                 InputString(&command);
                 EksekusiCommand(OlahString(command),Map.G,Turn,&P1Buildings,&P2Buildings,&ArrOfBuildings);
                
            } while (NotEndTurn(OlahString(command)));
        }
        ChangeTurn(&Turn);
        resetAttacknMove(&ArrOfBuildings);
        UpdateMap(&Map,ArrOfBuildings);
    }
}//main app Command Line Interface