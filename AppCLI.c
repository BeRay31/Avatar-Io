#include "Buildings.h"
#include <stdlib.h>
#include <stdbool.h>
#include "matriks.h"
#include "Map.h"
#include "Graph.h"
#include "infofileeksternal.h"
#include "GameMech.h"
#include <stdio.h>
int main()
{
    int n, m, nbangunan;
    int Turn = 1;
	BuildingsArr ArrOfBuildings;
	MATRIKS mgraf;
    Kata command;
    BuildMap Map;
    GetInfoDariFile (&n, &m, &nbangunan, &ArrOfBuildings, &mgraf);
    MakeBMap(&Map);
    while(NotEnd(ArrOfBuildings)){
        
        PrintMap(Map);
        if(Turn == 1){    
           do
            {
                 InputString(&command);
                 EksekusiCommand(OlahString(command),Turn, &ArrOfBuildings);
                
            } while (NotEndTurn(OlahString(command)));
            
            ChangeTurn(&Turn);
            
        }
        else{
             do
            {
                 InputString(&command);
                 EksekusiCommand(OlahString(command),Turn,&ArrOfBuildings);
                
            } while (NotEndTurn(OlahString(command)));
            
            ChangeTurn(&Turn);
        }
        UpdateMap(&Map,ArrOfBuildings);
    }
}//main app Command Line Interface