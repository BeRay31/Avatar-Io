#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../Buildings/Buildings.h"
#include "../Matriks/matriks.h"
#include "../Map/Map.h"
#include "../Graph/Graph.h"
#include "../LoadInfoAwal/loadinfoawal.h"
#include "../GameMech/GameMech.h"
#include "../Save/save.h"
#include <unistd.h>

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
    UpdateLoadBuilding(&ArrOfBuildings);
    MakeBMap(&Map);
    InitializeQueue(&Q1,&Q2);
    SCreateEmpty(&S);
    InsertLast(&P1Buildings,AllocateL(1));//Initiate and allocate Building index 1 == owner P1
    InsertLast(&P1Buildings,AllocateL(13));//Initiate and allocate Building index 1 == owner P1    
    InsertLast(&P2Buildings,AllocateL(2));//Initiate and allocate Building index 2 == owner P2
    ArrOfBuildings.TI[1].armies = 40;
    ArrOfBuildings.TI[2].armies = 40;
    ArrOfBuildings.TI[1].armies = 20;
    ArrOfBuildings.TI[13].armies = 20;
    ArrOfBuildings.TI[2].armies = 20;
    ArrOfBuildings.TI[1].owner = 1;
    ArrOfBuildings.TI[13].owner = 1;
    ArrOfBuildings.TI[2].owner = 2;
    UpdateMap(&Map,ArrOfBuildings);
    changeTurn = false;
    boolean fromLoad = false;
    boolean loadChange = false;
    while(NotEnd(ArrOfBuildings)){
        if(!fromLoad)
        {
            IncBuildingTroop(&ArrOfBuildings,Turn);
        }
        if(Turn == 1){    
           do
            {   
                printPlayerBanner(Turn);
                printLabelMap(Turn);
                PrintMap(Map);
                PrintOwnedBuildings(ArrOfBuildings,P1Buildings,&t);
                printf("Skill Available : ");
                PrintSkill(Q1);
                do{
                    // INPUT COMMAND
                    //InputString(&command);
                    Command(&command);
                }while(OlahString(command) == 0);
                EksekusiCommand(OlahString(command),Map.G,Turn,&changeTurn,&P1Buildings,&P2Buildings,&ArrOfBuildings,&S,&Q1,&Q2,n,m,nbangunan);
                UpdateMap(&Map,ArrOfBuildings);
                //Save(ArrOfBuildings, n, m, nbangunan, Q1, Q2, Turn);
                sleep(1);
                system("clear");
                fromLoad = false;
                if(OlahString(command)==9 )
                {
                    fromLoad = true;
                    break;
                }
            } while (NotEndTurn(OlahString(command)) && !loadChange);     
        }
        else{
             do
            {
                printPlayerBanner(Turn);
                printLabelMap(Turn);
                PrintMap(Map);
                PrintOwnedBuildings(ArrOfBuildings,P2Buildings,&t);
                printf("Skill Available : ");
                PrintSkill(Q2);
                do{
                    // INPUT COMMAND
                    //InputString(&command);
                    Command(&command);
                }while(OlahString(command) == 0);
                EksekusiCommand(OlahString(command),Map.G,Turn,&changeTurn,&P1Buildings,&P2Buildings,&ArrOfBuildings,&S,&Q1,&Q2,n,m,nbangunan);
                UpdateMap(&Map,ArrOfBuildings);
                sleep(1);
                system("clear");
                fromLoad = false;            
                if(OlahString(command)==9 )
                {
                    fromLoad = true;
                    break;
                }
            } while (NotEndTurn(OlahString(command)) && Turn==2);
        }
        if(IsAllLvl4(ArrOfBuildings,Turn)){
            if (Turn == 1)
            {
                AddQ(&Q1,6);
            }
            else{
                AddQ(&Q2,6);
            }
        }
        ChangeTurn(&Turn,changeTurn);
        changeTurn = false;
        resetAttacknMove(&ArrOfBuildings);
    }
    if(P1Buildings.First == NULL)
    {
        printPlayerBanner(2);
        printf("         _________ _        _______\n"); 
        printf("|\\     /|\\__   __/( (    /|(  ____ \\\n");
        printf("| )   ( |   ) (   |  \\  ( || (    \\/\n");
        printf("| | _ | |   | |   |   \\ | || (_____ \n");
        printf("| |( )| |   | |   | (\\ \\) |(_____  )\n");
        printf("| || || |   | |   | | \\   |      ) |\n");
        printf("| () () |___) (___| )  \\  |/\\____) |\n");
        printf("(_______)\\_______/|/    )_)\\_______)\n");

    }
    else if(P2Buildings.First == NULL)
    {
        printPlayerBanner(1);
        printf("         _________ _        _______\n"); 
        printf("|\\     /|\\__   __/( (    /|(  ____ \\\n");
        printf("| )   ( |   ) (   |  \\  ( || (    \\/\n");
        printf("| | _ | |   | |   |   \\ | || (_____ \n");
        printf("| |( )| |   | |   | (\\ \\) |(_____  )\n");
        printf("| || || |   | |   | | \\   |      ) |\n");
        printf("| () () |___) (___| )  \\  |/\\____) |\n");
        printf("(_______)\\_______/|/    )_)\\_______)\n");
    }
}