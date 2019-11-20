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
    Stack S;
    Queue Q1,Q2;
    int t;
    CreateEmptyQ(&Q1,10);
    CreateEmptyQ(&Q2,10);
    BuildMap Map;
    boolean changeTurn;
    List P1Buildings,P2Buildings;
    GetInfoDariFile (&n, &m, &nbangunan, &ArrOfBuildings, &mgraf);
    ArrOfBuildings.TI[1].owner = 1;
    ArrOfBuildings.TI[2].owner = 2;
    UpdateLoadBuilding(&ArrOfBuildings);
    MakeBMap(&Map);
    InitializeQueue(&Q1,&Q2);
    SCreateEmpty(&S);
    InsertLast(&P1Buildings,AllocateL(1));//Initiate and allocate Building index 1 == owner P1
    InsertLast(&P2Buildings,AllocateL(2));//Initiate and allocate Building index 2 == owner P2
    ArrOfBuildings.TI[1].armies = 40;
    ArrOfBuildings.TI[2].armies = 40;
    changeTurn = false;
    if(!NotEnd(ArrOfBuildings)){
        printf("Test\n");
    }
    while(NotEnd(ArrOfBuildings)){
        
        if(Turn == 1){    
           do
            {
                PrintMap(Map);
                printf("Player %d\n",Turn);
                PrintOwnedBuildings(ArrOfBuildings,P1Buildings,&t);
                printf("Skill Available : ");
                PrintSkill(Q1);
                do{
                    InputString(&command);
                }while(OlahString(command) == 0);
                EksekusiCommand(OlahString(command),Map.G,Turn,&changeTurn,&P1Buildings,&P2Buildings,&ArrOfBuildings,&S,&Q1,&Q2);
                UpdateMap(&Map,ArrOfBuildings);
            } while (NotEndTurn(OlahString(command)));     
        }
        else{
             do
            {
                PrintMap(Map);
                printf("Player %d\n",Turn);
                PrintOwnedBuildings(ArrOfBuildings,P2Buildings,&t);
                printf("Skill Available : \n");
                PrintSkill(Q2);
                do{
                    InputString(&command);
                }while(OlahString(command) == 0);
                EksekusiCommand(OlahString(command),Map.G,Turn,&changeTurn,&P1Buildings,&P2Buildings,&ArrOfBuildings,&S,&Q1,&Q2);
                UpdateMap(&Map,ArrOfBuildings);
            } while (NotEndTurn(OlahString(command)));
        }
        
        ChangeTurn(&Turn,changeTurn);
        changeTurn = false;
        resetAttacknMove(&ArrOfBuildings);
    }
}//main app Command Line Interface