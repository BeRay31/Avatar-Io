#include "../include1/GameMech.h"
#include "../include1/point.h"
boolean NotEnd(BuildingsArr B)
{
    int i;
    int count1 = 0;
    int count2 = 0;
    for(i=1;i<=B.MaxEl;i++)
    {
        if(B.T[i].owner == 1)
        {
            count1++;
        }
        if(B.T[i].owner == 2)
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
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != atk[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 1;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != lvl[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 2;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != skill[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 3;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != UNDO[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 4;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != END_TURN[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 5;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != SAVE[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 6;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != MOVE[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
    {
        return 7;
    }
    for(i=0;i<Kata.Length;i++)
    {
        if(Kata.TabKata[i] != EXIT[i])
        {
            break;
        }
    }
    if(i == Kata.Length)
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

void PrintPBuildings(int player, BuildingsArr B){
    int j = 1;
    for(int i=1;i<=B.MaxEl;i++){
        if(B.T[i].owner == player){
            if(B.T[i].buildingsType == 'C'){
                printf('%d. Castle (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].armies,B.T[i].level);
                j++;
            }
            else if(B.T[i].buildingsType == 'T'){
                printf('%d. Tower (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].armies,B.T[i].level);
                j++;
            }
            else if(B.T[i].buildingsType == 'F'){
                printf('%d. Fort (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].armies,B.T[i].level);
                j++;
            }
            else if(B.T[i].buildingsType == 'V'){
                printf('%d. Village (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].armies,B.T[i].level);
                j++;
            }
        }
    }
}
/*
{I.S Building Defined}
{F.S Players Building Printed}
*/

void EksekusiCommand(int command, int player, BuildingsArr *B, BuildingsArr *BL, Queue *QP){
    
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
            if(Narmies<=(*B).T[op1].armies){   
                Attacked ((*BL).T[op2],(*B).T[op1],Narmies);
            }
        //jika tidak ada
            printf("Tidak ada bangunan yang dapat diserang");
    }
    else if(command == 2){//LEVEL_UP
        int op;
        printf("Daftar bangunan:  ");
        PrintPBuildings(player, *B);
        printf("Bangunan yang akan di level up: "); scanf("%d", op);
        LevelUp (&((*B).T[op]));
    }
    else if(command == 3){//SKILL
        Skill Act;
        QDelElmt (QP, &Act);
        actvteCrntSkill(Act,BuildingsArr BArr,BuildingsArr BArr2, Buildings *B,);
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