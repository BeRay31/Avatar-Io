#include "../include1/Skills.h"
#include "../include1/loadinfoawal.h"

/*
	1. Instant Upgrade
	2. Shield
	3. Extra Turn
	4. Attack Up
	5. Critical Hit
	6. Instant Reinforcement
	7. Barragemdwhuwe
	*/

actvteCrntSkill(Skill Act,TabBuildings BArr,TabBuildings BArr2, Buildings *B,)
/*
{I.S }
{F.S }
*/
{
	//TabBuildings BArr;//pemain
	//TabBuildings BArr2; //lawan

	switch(Act.SkillCode){   
		case 1 : 
			for(int i=IdxMin; i<=(BArr).MaxEl){
				LevelUp (&(BArr.TI[i]));}
			break;
		case 2 :

			break;
		case 3 :

			break;
		case 4 :
			break;
		case 5 :
			for(i=IdxMin; i<=(BArr2).MaxEl){

			}
			break;
		case 6 :
			for(i=IdxMin; i<=(BArr).MaxEl){
				(BArr.TI[i]).armies += 5;
			}
			break;
		case 7 :
			for(i=IdxMin; i<=(BArr2).MaxEl){
				(BArr2.TI[i]).armies -= 10;
			}
			break;
	}
}
addSkill(Queue *SP, Queue *SL, TabBuildings BArr, TabBuildings BArr2)
{
	if(NbQElmt (*SP)!=10 || NbQElmt(*SL)!= 10){ 
		//EksekusiCommand(int command, int player, TabBuildings *B)
		//Attacked (Buildings *B, Buildings *BP, int Narmies)
		//actvteCrntSkill(Queue *S,Skill Act)
		if(command==1 && *B.owner==*BP.owner && NbElmt(BArr2)==2){
			QAddElmt (SL,2);	
		}else if(command==1 && *B.owner==*BP.owner && *B.buildingsType=='F'){
			QAddElmt (SL,3);
		}else if(command==1 && *B.buildingsType=='T' && *B.owner==*BP.owner && NbBuild(BArr,'T')==3){
			QAddElmt (SP,4);
		}else if(Act.SkillCode==3 && command==3){
			QAddElmt (SL,5);
		}else if(command==5){
			boolean allmaxlev = true;
			int i = IdxMin;
			while(i<=MaxEl && allmaxlev){
				if((BArr.TI[i]).level != 4){
					allmaxlev = false;
				}
				i++;
			}
			if(allmaxlev){
				QAddElmt(SP,6);
			}
		}else if(command==1 && *B.owner==*BP.owner && NbElmt(BArr)==10){
			QAddElmt(SL,7);
		}
	}
}