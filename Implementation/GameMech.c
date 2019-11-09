#include "../include1/GameMech.h"
#include "../include1/point.h"
#include "../include1/Stack.h"
boolean NotEnd(TabBuildings B)
{
    int i;
    int count1 = 0;
    int count2 = 0;
    for(i=1;i<=B.MaxEl;i++)
    {
        if(B.TI[i].owner == 1)
        {
            count1++;
        }
        if(B.TI[i].owner == 2)
        {
            count2++;
        }
    }
    if(count1 == 0 || count2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/*
{I.S Game Launched}
{F.S Check the game if end return false if !end return true}
*/

void ChangeTurn(int *Turn)
{
    if(*Turn == 1)
    {
        *Turn = 2;
    }
    else
    {
        *Turn = 1;
    }
}
/*
{I.S Game Launched}
{F.S Turn Changed}
*/

int OlahString(Kata Kata)
{
    char atk[] = "ATTACK"; // 1
    char lvl[] = "LEVEL_UP"; // 2
    char skill[] = "SKILL"; // 3
    char UNDO[] = "UNDO"; // 4
    char END_TURN[] = "END_TURN"; // 5
    char SAVE[] = "SAVE"; // 6
    char MOVE[] = "MOVE"; // 7
    char EXIT[] = "EXIT"; // 8
    int i;
    for(i=0;i<6;i++)
    {
        if(Kata.TabKata[i] != atk[i])
        {
            break;
        }
    }
    if(i == 5)
    {
        return 1;
    }
    for(i=0;i<8;i++)
    {
        if(Kata.TabKata[i] != lvl[i])
        {
            break;
        }
    }
    if(i == 7)
    {
        return 2;
    }
    for(i=0;i<5;i++)
    {
        if(Kata.TabKata[i] != skill[i])
        {
            break;
        }
    }
    if(i == 4)
    {
        return 3;
    }
    for(i=0;i<4;i++)
    {
        if(Kata.TabKata[i] != UNDO[i])
        {
            break;
        }
    }
    if(i == 3)
    {
        return 4;
    }
    for(i=0;i<8;i++)
    {
        if(Kata.TabKata[i] != END_TURN[i])
        {
            break;
        }
    }
    if(i == 7)
    {
        return 5;
    }
    for(i=0;i<4;i++)
    {
        if(Kata.TabKata[i] != SAVE[i])
        {
            break;
        }
    }
    if(i == 3)
    {
        return 6;
    }
    for(i=0;i<4;i++)
    {
        if(Kata.TabKata[i] != MOVE[i])
        {
            break;
        }
    }
    if(i == 3)
    {
        return 7;
    }
    for(i=0;i<4;i++)
    {
        if(Kata.TabKata[i] != EXIT[i])
        {
            break;
        }
    }
    if(i == 3)
    {
        return 8;
    }
}
/*
{I.S Kata Defined}
{F.S Return Int representation of Kata based on command list}
*/

boolean NotEndTurn(int i){
    if(i==5){
        return false;
    }
    else{
        return true;
    }
}
/*
{I.S Game Launched}
{F.S Check the Turn if End return False, if !end return true}
*/
void EksekusiCommand(int command,GraphArr G, int player,List *PList, TabBuildings *B, Queue *QP,StackElmt *S)
{
    
    if(command == 1)
    {//ATTACK
        int current = 1;
        int NbOfB;
        int selected;
        int tempBIndex;
        Buildings Attck;//Building that attack
        Buildings Target;//Target Building
        address x;
        printf("Daftar Bangunan : \n");
        PrintOwnedBuildings(*B,*PList,&NbOfB);
        printf ("Bangunan yang digunakan untuk menyerang: ");
        scanf("%d",&selected);
        //Select Building That attack
        while(selected>NbOfB)
        {
            printf("Bangunan yang anda pilih tidaklah ada\n");
            printf("Masukkan kembali bangunan yang digunakan untuk menyerang :");
            scanf("%d",&selected);
        }
        x = (*PList).First;
        while(current!=selected)//search selected building index
        {
            x = x->next;
            current++;
        }
        tempBIndex = x->info;
        Attck = (*B).TI[tempBIndex];//building that attack
        printf("Daftar bangunan yang dapat diserang : \n");
        PrintLinkedBuildingsA(player,G,*B,Attck.buildingsIndex,&NbOfB);
        //Select Target Building
        while(selected>NbOfB)
        {
            printf("Bangunan yang anda pilih tidaklah ada\n");
            printf("Masukkan kembali bangunan untuk diserang :");
            scanf("%d",&selected);
        }
        while(current!=selected)//search selected building index
        {
            x = x->next;
            current++;
        }
        tempBIndex = x->info;
        Target = (*B).TI[tempBIndex];
        //NbOfArmies used and validate
        
    }
    else if(command == 2)
    {//LEVEL_UP
        int op;
    }
    else if(command == 3)
    {//SKILL
    
    }
    else if(command == 4)
    {//UNDO
        
    }
    else if(command == 5)
    {//END_TURN
        
    }
    else if(command == 6)
    {//SAVE
        
    }
    else if(command == 7)
    {//MOVE

    }
    else if(command == 8)
    {//EXIT
        
    }
}
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/
void UpdateListBuilding(int index , List *PlayerB)
{
    InsertLast(PlayerB,AllocateL(index));
}
/*
{I.S List Index of Building defined}
{F.S List Index of Building updated}
*/

void PrintOwnedBuildings(TabBuildings PBuildings, List PBIndex,int *NbofBuilding)
{
    int i = 1;
    int indexB;
    address current = PBIndex.First;
    if (current != NULL)
    {
        while(current!=NULL)
        {
            indexB = current->info;
            printf("%d. ",i);
            if (PBuildings.TI[indexB].buildingsType == 'C')
            {
                printf("Castle (%d,%d) %d lv. %d\n",PBuildings.TI[indexB].position.X,PBuildings.TI[indexB].position.Y,PBuildings.TI[indexB].armies,PBuildings.TI[indexB].level);
            }
            else if (PBuildings.TI[indexB].buildingsType == 'T')
            {
                printf("Tower (%d,%d) %d lv. %d\n",PBuildings.TI[indexB].position.X,PBuildings.TI[indexB].position.Y,PBuildings.TI[indexB].armies,PBuildings.TI[indexB].level);
            }
            else if (PBuildings.TI[indexB].buildingsType == 'F')
            {
                printf("Fort (%d,%d) %d lv. %d\n",PBuildings.TI[indexB].position.X,PBuildings.TI[indexB].position.Y,PBuildings.TI[indexB].armies,PBuildings.TI[indexB].level);
            }
            else if (PBuildings.TI[indexB].buildingsType == 'V')
            {
                printf("Village (%d,%d) %d lv. %d\n",PBuildings.TI[indexB].position.X,PBuildings.TI[indexB].position.Y,PBuildings.TI[indexB].armies,PBuildings.TI[indexB].level);
            }
            i++;
            current = current->next;
        }
    }
    NbofBuilding = i;
    printf("\n");
}
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/

void PrintLinkedBuildingsA (int turn,GraphArr G,TabBuildings Buildings,int index,int *NbofBuilding)//for attack mech
{
    int i = 1;
    address currentIndex = G.Arr[index].First;
    int EnemyIndex;
    int indexB ;
    if (turn == 1)
    {
        EnemyIndex = 2;
    }
    else 
    {
        EnemyIndex = 1;
    }
    while(currentIndex != NULL)
    {
        index = currentIndex->info;
        if (Buildings.TI[indexB].owner == EnemyIndex)
        {
            printf("%d. ",i);
            if (Buildings.TI[indexB].buildingsType == 'C')
            {
                printf("Castle (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'T')
            {
                printf("Tower (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'F')
            {
                printf("Fort (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'V')
            {
                printf("Village (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }            
        }
        else if(Buildings.TI[indexB].owner == 0)
        {
            printf("%d. ",i);
            if (Buildings.TI[indexB].buildingsType == 'C')
            {
                printf("Castle (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].minArmiesToOccupy,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'T')
            {
                printf("Tower (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].minArmiesToOccupy,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'F')
            {
                printf("Fort (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].minArmiesToOccupy,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'V')
            {
                printf("Village (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].minArmiesToOccupy,Buildings.TI[indexB].level);
            }            
        }
        currentIndex=currentIndex->next;
        i++;
    }
    NbofBuilding = i;
    printf("\n");
}
/*
{I.S Graph Defined and Building Defined}
{F.S Printed Linked Building}
*/
void PrintLinkedBuildingsM (int turn,GraphArr G,TabBuildings Buildings,int index,int *NbofBuilding)
{
    int i = 1;
    int tempturn = turn;
    address currentIndex = G.Arr[index].First;
    int indexB ;
    while(currentIndex != NULL)
    {
        index = currentIndex->info;
        if (Buildings.TI[indexB].owner == turn)
        {
            printf("%d. ",i);
            if (Buildings.TI[indexB].buildingsType == 'C')
            {
                printf("Castle (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'T')
            {
                printf("Tower (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'F')
            {
                printf("Fort (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }
            else if (Buildings.TI[indexB].buildingsType == 'V')
            {
                printf("Village (%d,%d) %d lv. %d\n",Buildings.TI[indexB].position.X,Buildings.TI[indexB].position.Y,Buildings.TI[indexB].armies,Buildings.TI[indexB].level);
            }            
        }
        currentIndex = currentIndex->next;
        i++;
    }
    NbofBuilding = i;
    printf("\n");
}
