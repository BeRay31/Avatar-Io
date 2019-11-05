#include "../include1/Skills.h"
#include "../include1/infofileeksternal.h"

/*
	1. Instant Upgrade
	2. Shield
	3. Extra Turn
	4. Attack Up
	5. Critical Hit
	6. Instant Reinforcement
	7. Barrage
	*/

actvteCrntSkill(Queue *S,Skill Act)
/*
{I.S }
{F.S }
*/
{
	BuildingsArr BArr;//pemain
	BuildingsArr BArr2; //lawan

	switch(Act.SkillCode){   
		case 1 : 
			for(int i=IdxMin; i<=(BArr).MaxEl){
				LevelUp (&(BArr.T[i]));}
			break;
		case 2 :

			break;
		case 3 :

			break;
		case 4 :
			break;
		case 5 :
			break;
		case 6 :
			for(int i=IdxMin; i<=(BArr).MaxEl){
				(BArr.T[i]).armies += 5;
			}
			break;
		case 7 :
			for(int i=IdxMin; i<=(BArr2).MaxEl){
				(BArr2.T[i]).armies -= 10;
			}
			break;
	}
}
addSkill(Queue *S,Skill New)
{
	QAddElmt (S,New);
	if()
}