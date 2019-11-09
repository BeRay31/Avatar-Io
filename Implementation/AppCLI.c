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
        }
        else{
             do
            {
                 InputString(&command);
                 EksekusiCommand(OlahString(command),Turn,&ArrOfBuildings);
                
            } while (NotEndTurn(OlahString(command)));
        }
        ChangeTurn(&Turn);
        UpdateMap(&Map,ArrOfBuildings);
    }
}//main app Command Line Interface