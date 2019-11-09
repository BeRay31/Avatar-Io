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

void PrintPBuildings(int player, TabBuildings B){
    int j = 1;
    for(int i=1;i<=B.MaxEl;i++){
        if(B.TI[i].owner == player){
            if(B.TI[i].buildingsType == 'C'){
                printf('%d. Castle (%d,%d) %d lv. %d',j,B.TI[i].position.X,B.TI[i].position.Y,B.TI[i].armies,B.TI[i].level);
                j++;
            }
            else if(B.TI[i].buildingsType == 'T'){
                printf('%d. Tower (%d,%d) %d lv. %d',j,B.TI[i].position.X,B.TI[i].position.Y,B.TI[i].armies,B.TI[i].level);
                j++;
            }
            else if(B.TI[i].buildingsType == 'F'){
                printf('%d. Fort (%d,%d) %d lv. %d',j,B.TI[i].position.X,B.TI[i].position.Y,B.TI[i].armies,B.TI[i].level);
                j++;
            }
            else if(B.TI[i].buildingsType == 'V'){
                printf('%d. Village (%d,%d) %d lv. %d',j,B.TI[i].position.X,B.TI[i].position.Y,B.TI[i].armies,B.TI[i].level);
                j++;
            }
        }
    }
}
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/

void EksekusiCommand(int command, int player, TabBuildings *B, TabBuildings *BL, Queue *QP,StackElmt *S){
    
    if(command == 1){//ATTACK
        int op1,op2, Narmies;

        printf("Daftar bangunan:\n");
        PrintPBuildings(player, *B);
        printf("Bangunan yang digunakan untuk menyerang: ");
        scanf("%d", op1);
        //jika ada graf keterhubungan bangunan 
            printf("Daftar bangunan yang dapat diserang: ");
            //print hasil graf
            printf("Bangunan yang diserang: "); scanf("%d", op2);
            printf("Jumlah pasukan: "); scanf("%d", Narmies);
            if(Narmies<=(*B).TI[op1].armies){   
                Attacked (&(*BL).TI[op2],&(*B).TI[op1],Narmies);
            }
        //jika tidak ada
            printf("Tidak ada bangunan yang dapat diserang");
    }
    else if(command == 2){//LEVEL_UP
        int op;
        printf("Daftar bangunan:  ");
        PrintPBuildings(player, *B);
        printf("Bangunan yang akan di level up: "); scanf("%d", op);
        LevelUp (&((*B).TI[op]));
    }
    else if(command == 3){//SKILL
        Skill Act;
        QDelElmt (QP, &Act);
        actvteCrntSkill(Act,TabBuildings BArr,TabBuildings BArr2, Buildings *B,);
    }
    else if(command == 4){//UNDO
        
    }
    else if(command == 5){//END_TURN
        
    }
    else if(command == 6){//SAVE
        
    }
    else if(command == 7){//MOVE
        int Narmies, op1,op2;
        printf("Daftar bangunan:  ");
        PrintPBuildings(player, *B);
        printf("Pilih bangunan: "); scanf("%d", op1);
        printf("Daftar bangunan terdekat: "); 
        //menampilkan bangunan terdekat jika ada 
            scanf("%d", op2);
            scanf("%d", &Narmies);
            Move (Buildings *B, Buildings *B2, int Narmies);
    }
    else if(command == 8){//EXIT
        
    }
}
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/