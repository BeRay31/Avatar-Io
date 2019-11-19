#include "../include1/GameMech.h"
#include "../include1/point.h"
#include "../include1/mesinkata.h"

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

int OlahString(Kata command)
{
    // kamus command
	Kata ATTACK, LEVEL_UP, SKILL, UNDO, END_TURN, SAVE, MOVE, EXIT;
	// ATTTACK
	ATTACK.TabKata[1] = 'A';
	ATTACK.TabKata[2] = 'T';
	ATTACK.TabKata[3] = 'T';
	ATTACK.TabKata[4] = 'A';
	ATTACK.TabKata[5] = 'C';
	ATTACK.TabKata[6] = 'K';
	ATTACK.Length = 6;
	// LEVEL_UP
	LEVEL_UP.TabKata[1] = 'L';
	LEVEL_UP.TabKata[2] = 'E';
	LEVEL_UP.TabKata[3] = 'V';
	LEVEL_UP.TabKata[4] = 'E';
	LEVEL_UP.TabKata[5] = 'L';
	LEVEL_UP.TabKata[6] = '_';
	LEVEL_UP.TabKata[7] = 'U';
	LEVEL_UP.TabKata[8] = 'P';
	LEVEL_UP.Length = 8;
	// SKILL
	SKILL.TabKata[1] = 'S';
	SKILL.TabKata[2] = 'K';
	SKILL.TabKata[3] = 'I';
	SKILL.TabKata[4] = 'L';
	SKILL.TabKata[5] = 'L';
	SKILL.Length = 5;
	// UNDO
	UNDO.TabKata[1] = 'U';
	UNDO.TabKata[2] = 'N';
	UNDO.TabKata[3] = 'D';
	UNDO.TabKata[4] = 'O';
	UNDO.Length = 4;
	// END_TURN
	END_TURN.TabKata[1] = 'E';
	END_TURN.TabKata[2] = 'N';
	END_TURN.TabKata[3] = 'D';
	END_TURN.TabKata[4] = '_';
	END_TURN.TabKata[5] = 'T';
	END_TURN.TabKata[6] = 'U';
	END_TURN.TabKata[7] = 'R';
	END_TURN.TabKata[8] = 'N';
	END_TURN.Length = 8;
	// SAVE
	SAVE.TabKata[1] = 'S';
	SAVE.TabKata[2] = 'A';
	SAVE.TabKata[3] = 'V';
	SAVE.TabKata[4] = 'E';
	SAVE.Length = 4; 
    // MOVE
    MOVE.TabKata[1] = 'M';
	MOVE.TabKata[2] = 'O';
	MOVE.TabKata[3] = 'V';
	MOVE.TabKata[4] = 'E';
	MOVE.Length = 4;
    // EXIT
    EXIT.TabKata[1] = 'E';
	EXIT.TabKata[2] = 'X';
	EXIT.TabKata[3] = 'I';
	EXIT.TabKata[4] = 'T';
	EXIT.Length = 4;

    if (IsKataSama (command, ATTACK)) {
        return 1;
    } else if (IsKataSama (command, LEVEL_UP)) {
        return 2;
    } else if (IsKataSama (command, SKILL)) {
        return 3;
    } else if (IsKataSama (command, UNDO)) {
        return 4;
    } else if (IsKataSama (command, END_TURN)) {
        return 5;
    } else if (IsKataSama (command, SAVE)) {
        return 6;
    } else if (IsKataSama (command, MOVE)) {
        return 7;
    } else if (IsKataSama (command, EXIT)) {
        return 8;
    } else {
        return 0;
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
void EksekusiCommand(int command,GraphArr G, int player,int *changeTurn,List *P1List,List *P2List, TabBuildings *B,Stack *S, Queue *Q1, Queue *Q2)
{   
    *changeTurn = player;
    if(command == 1)
    {//ATTACK
        //{DICT}
        int current = 1;
        int NbOfB;
        int selected;
        int tempBIndex,tempBLIndex;
        int armiesUsed;
        State St;
        Buildings Attck;//Building that attack
        Buildings Target;//Target Building
        address x;

        //IMPLMN
        printf("Daftar Bangunan : \n");
        if(player == 1)
        {
            PrintOwnedBuildings(*B,*P1List,&NbOfB);
            x = (*P1List).First;
        }
        else
        {
            PrintOwnedBuildings(*B,*P2List,&NbOfB);
            x = (*P2List).First;
        }
        printf ("Bangunan yang digunakan untuk menyerang: ");
        scanf("%d",&selected);
        //Select Building That attack
        while(selected>NbOfB || selected<= 0)
        {
            printf("Bangunan yang anda pilih tidaklah ada\n");
            printf("Masukkan kembali bangunan yang digunakan untuk menyerang :");
            scanf("%d",&selected);
        }
        while(current!=selected)//search selected building index
        {
            x = x->next;
            current++;
        }
        tempBIndex = x->info;
        Attck = (*B).TI[tempBIndex];//building that attack

        if (Attck.attck)
        {
            printf("Daftar bangunan yang dapat diserang : \n");
            PrintLinkedBuildingsA(player,G,*B,tempBIndex,&NbOfB);
            //Select Target Building
            printf ("Target Bangunan untuk diserang: ");
            scanf("%d",&selected);
            while(selected>NbOfB || selected<= 0)
            {
                printf("Bangunan yang anda pilih tidaklah ada\n");
                printf("Masukkan kembali bangunan untuk diserang :");
                scanf("%d",&selected);
            }
            x = G.Arr[Attck.buildingsIndex].First;
            current = 1;
            while((*B).TI[x->info].owner==player)
            {
                x = x->next;
            }
            while(current!=selected)//search selected building index
            {
                while((*B).TI[x->info].owner==player)
                {
                    x = x->next;
                }
                x = x->next;
                current++;
            }
            tempBLIndex = x->info;
            Target = (*B).TI[tempBLIndex];
            //NbOfArmies used and validate
            printf("Jumlah Pasukan yang digunakan : ");
            scanf("%d",&armiesUsed);
            while(armiesUsed>Attck.armies)
            {
                printf("Jumlah pasukan pada Building anda tidak mencukupi\n");
                printf("Masukkan kembali jumlah pasukan yang akan digunakan :");
                scanf("%d",&armiesUsed);
            }
            //Stack
            St.B = *B;
            St.P1 = *P1List;
            St.P2 = *P2List;
            
            Push(S,St);
            //AttackMech
            if(Target.owner == 0)
            {
                Occupy(&Attck,&Target,armiesUsed);
                if (Attck.owner == Target.owner)
                {
                    address del;
                    if(player==1)
                    {
                        printf("Bangunan Jadi Milikmu!!!!\n");
                        InsertLast(P1List,AllocateL(Target.buildingsIndex));
                        if(NbOfBuildings(*B,player) == 10){
                            AddQ(&(*Q1),7);
                        }
                    }
                    else
                    {
                        printf("Bangunan Jadi Milikmu!!!!\n");
                        InsertLast(P2List,AllocateL(Target.buildingsIndex));
                        if(NbOfBuildings(*B,player) == 10){
                            AddQ(&(*Q2),7);
                        }
                    }
                }
            }
            else
            {
                Attack(&Attck,&Target,armiesUsed);
                if (Attck.owner == Target.owner)
                {
                    if(player==1)
                    {
                        address del;
                        printf("Bangunan Jadi Milikmu!!!!\n");
                        if(Target.buildingsType == 'F'){
                            AddQ(&(*Q2),3);
                        }
                        InsertLast(P1List,AllocateL(Target.buildingsIndex));
                        DelP(P2List,&del,Search(*P2List,Target.buildingsIndex));
                        if(NbOfBuildings(*B,player) == 10){
                            AddQ(&(*Q1),7);
                        }
                    }
                    else
                    {
                        address del;
                        printf("Bangunan Jadi Milikmu!!!!\n");
                        if (Target.buildingsType == 'F')
                        {
                            AddQ(&(*Q1),3);
                        }
                        InsertLast(P2List,AllocateL(Target.buildingsIndex));
                        DelP(P1List,&del,Search(*P1List,Target.buildingsIndex));
                        if(NbOfBuildings(*B,player) == 10){
                            AddQ(&(*Q2),7);
                        }
                    }
                }
            }
            Attck.attck = false;
            (*B).TI[tempBIndex] = Attck;
            (*B).TI[tempBLIndex] = Target;
        }
        else
        {
            printf("Bangunan yang anda pilih sudah digunakan untuk menyerang.\n");
        }
                
    }
    else if(command == 2)
    {//LEVEL_UP
        //{DICT}
        int NbOfB;
        address x;
        
        int current = 1;
        int selected;
        int TempIndex;
        State St;
        Buildings LvlUp;
        //{IMPLMNT}
        printf ("Daftar Bangunan : \n");
        if (player ==1)
        {
            PrintOwnedBuildings((*B),*P1List,&NbOfB);
            x = (*P1List).First;
        }
        else
        {
            PrintOwnedBuildings((*B),*P2List,&NbOfB);
            x = (*P2List).First;
        }
        printf("Bangunan yang akan di level-up : ");
        scanf("%d",&selected);
        while(selected>NbOfB || selected<=0)
        {
            printf("Bangunan yang anda pilih tidaklah ada.\n");
            printf("Masukan kembali bangunan yang akan di level-up : ");
            scanf("%d",&selected);
        }
        current = 1;
        while(current != selected)
        {
            x = x->next;
            current ++;
        }
        TempIndex = x->info;
        LvlUp = (*B).TI[TempIndex];
        //Stack
        St.B = (*B);
        St.P1=(*P1List);
        St.P2=(*P2List);
        Push(S,St);
        //Level-Up Mech
        LevelUp(&LvlUp);
        (*B).TI[TempIndex] = LvlUp;
    }
    else if(command == 3)
    {   
        int skill;
        if(player == 1){
            if(IsEmptyQ(*Q1)){
                printf("Anda tidak memiliki skill sekarang");
                
            }
            else
            {
                DelQ(&(*Q1),&skill);
            }

        }
        else
        {
            if(IsEmptyQ(*Q2)){
                printf("Anda tidak memiliki skill sekarang");
            }
            else
            {
                DelQ(&(*Q2),&skill);
            }
            
        }
        if(skill == 1 ){
            // Instant Upgrade SKill
            printf("Anda menggunakan skill Instant Upgrade");
            for(int i=0; i < (*B).Neff ; i++){
                if((*B).TI[i].owner == player){
                    if((*B).TI[i].level <= 3){  // Hanya Level kurang dari sama dengan 3 yang dapat naik level
                        (*B).TI[i].level++;
                    }
                }
            }
            SCreateEmpty(&(*S));
        }
        else if(skill == 2){
           // Shield
           // Menyimpan ke Stack
        }
        else if(skill == 3){
            // Extra Turn
            printf("Anda menggunakan skill extra turn");
             if(*changeTurn == 1){
                *changeTurn == 2;
            }
            else{
                *changeTurn == 1;
            }
             SCreateEmpty(&(*S));
            // Menyimpan ke Stack
        }
        else if (skill == 4){
            // Attack Up
            // Menyimpan ke Stack
        }
        else if (skill == 5){
            // Critical Hit
            // Menyimpan ke Stack

        }
        else if (skill == 6){
            // Instant Reinforcement
            for(int i=0; i< (*B).Neff ; i++){
                if((*B).TI[i].owner == player){
                    if((*B).TI[i].armies + 5 >= (*B).TI[i].maxArmyOnBuildings){
                        (*B).TI[i].armies = (*B).TI[i].maxArmyOnBuildings;
                    }
                    else
                    {
                        (*B).TI[i].armies += 5;
                    }
                    
                }
            }
             SCreateEmpty(&(*S));
            // Menyimpan ke Stack
        }
        else if (skill == 7){
            // Barrage
            int lawan;
            if(player == 1){
                lawan = 2;
            }
            else
            {
                lawan = 1;
            }
            for(int i = 0; i <(*B).Neff;i++){
                if((*B).TI[i].owner == lawan){
                    if((*B).TI[i].armies - 10 <= 0 ){
                        (*B).TI[i].armies = 0;
                    }
                    else
                    {
                        (*B).TI[i].armies -=10;
                    }
                    
                }
            }
             SCreateEmpty(&(*S));
            // Menyimpan ke Stack
        }
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
        //{DICT}
        int current = 1;
        int selected;
        address x;
        int NbOfB;
        int TempIndex,TempIndexB;
        Buildings Src,Dest;
        State St;
        int Narmies;
        //{IMPLEMENT}
        if(player == 1)
        {
            PrintOwnedBuildings((*B),*P1List,&NbOfB);
            x = (*P1List).First;
        }
        else
        {
            PrintOwnedBuildings((*B),*P2List,&NbOfB);
            x = (*P2List).First;            
        }
        printf("Pilih Bangunan :");
        scanf("%d",&selected);
        while(selected>NbOfB || selected<= 0)
        {
            printf("Bangunan yang anda pilih tidaklah ada.\n");
            printf("Masukkan kembali bangunan yang akan dipindah pasukannya : ");
            scanf("%d",&selected);
        }
        current = 1;
        while(current != selected)
        {
            x = x->next;
            current++;
        }
        TempIndex = x->info;
        Src = (*B).TI[TempIndex];
        if (Src.move)
        {
            printf("Daftar bangunan yang terdekat : \n");
            x = G.Arr[TempIndex].First;
            PrintLinkedBuildingsM(player,G,(*B),TempIndex,&NbOfB);
            printf("Bangunan yang akan menerima : ");
            scanf("%d",&selected);
            while(selected>NbOfB || selected<0)
            {
                printf("Bangunan yang anda pilih tidaklah ada.\n");
                printf("Masukkan kembali bangunan yang akan menerima : ");
                scanf("%d",&selected);
            }
            current = 1;
            while(current != selected)
            {
                while((*B).TI[x->info].owner!=player)
                {
                    x = x->next;
                }
                x = x->next;
                while((*B).TI[x->info].owner!=player)
                {
                    x = x->next;
                }
                current ++;
            }
            TempIndexB = x->info;
            Dest = (*B).TI[TempIndexB];
            //Stack
            St.B = (*B);
            St.P1 = (*P1List);
            St.P2 = (*P2List);
            Push(S,St);
            //Move MEch
            printf("Jumlah Pasukan : ");
            scanf("%d",&Narmies);
            while(Narmies>Src.armies || Narmies<0)
            {
                printf("Jumlah pasukkan tidaklah valid.\n");
                printf("Masukkan kembali jumlah pasukan : ");
                scanf("%d",&Narmies);
            }
            Move(&Src,&Dest,Narmies);
            Src.move = false;
            (*B).TI[TempIndex] = Src;
            (*B).TI[TempIndexB]= Dest;
        }
        else
        {
            printf("Bangunan sudah pernah dipindah pasukannya.\n");
        }
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
    *NbofBuilding = i;
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
        indexB = currentIndex->info;
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
            i++;      
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
            i++;      
        }
        
        currentIndex=currentIndex->next;
    }
    *NbofBuilding = i;
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
            i++;
        }
        currentIndex = currentIndex->next;
    }
    *NbofBuilding = i;
    printf("\n");
}

void resetAttacknMove(TabBuildings *B)
{
    for (int i =1 ; i<=(*B).Neff;i++)
    {
        (*B).TI[i].attck = true;
        (*B).TI[i].move = true;
    }
}
/*
{I.S attck true or false}
{F.S attack false}
*/
void UpdateLoadBuilding(TabBuildings *Arrb)
{
    for (int i = 1 ; i<= (*Arrb).Neff ; i++) //add Building From File
    {
        Buildings Temp;
        char type = (*Arrb).TI[i].buildingsType;
        int x = (*Arrb).TI[i].position.X;
        int y = (*Arrb).TI[i].position.Y;
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
        Temp.buildingsIndex = i;
        (*Arrb).TI[i] = Temp;
    }
}