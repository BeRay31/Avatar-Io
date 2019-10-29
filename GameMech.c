#include "GameMech.h"
#include "point.h"
boolean NotEnd(BuildingsArr B)
{
    int i;
    int count1 = 0;
    int count2 = 0;
    for(i=1;i<=B.MaxEl;i++){
        if(B.T[i].owner == 1){
            count1++;
        }
        if(B.T[i].owner == 2){
            count2++;
        }
    }
    if(count1 == 0 || count2 == 0){
        return false;
    }
    else{
        return true;
    }
}
void ChangeTurn(int *Turn){
    if(*Turn == 1){
        *Turn = 2;
    }
    else{
        *Turn = 1;
    }
}
int OlahString(Kata Kata){
    char atk[] = "ATTACK"; // 1
    char lvl[] = "LEVEL_UP"; // 2
    char skill[] = "SKILL"; // 3
    char UNDO[] = "UNDO"; // 4
    char END_TURN[] = "END_TURN"; // 5
    char SAVE[] = "SAVE"; // 6
    char MOVE[] = "MOVE"; // 7
    char EXIT[] = "EXIT"; // 8
    int i;
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != atk[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 1;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != lvl[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 2;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != skill[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 3;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != UNDO[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 4;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != END_TURN[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 5;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != SAVE[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 6;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != MOVE[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 7;
    }
    for(i=0;i<Kata.Length;i++){
        if(Kata.TabKata[i] != EXIT[i]){
            break;
        }
    }
    if(i == Kata.Length){
        return 8;
    }
}
boolean NotEndTurn(int i){
    if(i==5){
        return false;
    }
    else{
        return true;
    }
}
void PrintPBuildings(int player, BuildingsArr B){
    int j = 1;
    for(int i=1;i<=B.MaxEl;i++){
        if(B.T[i].owner == player){
            if(B.T[i].buildingsType == 'C'){
                printf('%d. Castle (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].level);
                j++;
            }
            else if(B.T[i].buildingsType == 'T'){
                printf('%d. Tower (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].level);
                j++;
            }
            else if(B.T[i].buildingsType == 'F'){
                printf('%d. Fort (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].level);
                j++;
            }
            else if(B.T[i].buildingsType == 'V'){
                printf('%d. Village (%d,%d) %d lv. %d',j,B.T[i].position.X,B.T[i].position.Y,B.T[i].level);
                j++;
            }
        }
    }
}
void EksekusiCommand(int command, int player, BuildingsArr *B){
    if(command == 1){
        
    }
    else if(command == 2){

    }
    else if(command == 3){

    }
    else if(command == 4){
        
    }
    else if(command == 6){
    
    }
    else if(command == 7){
        
    }
    else if(command == 8){
        
    }
 
}