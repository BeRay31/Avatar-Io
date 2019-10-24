
#include "ArrayImp.h"
#include <stdio.h>
void MakeEmpty (TabInt * T)
{
	int i;

	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		Elmt(*T, i) = ValUndef;
	}
}

int NbElmt (TabInt T)

{
	IdxType i = IdxMin;

	while (i <= IdxMax + IdxMin - 1 && Elmt(T, i) != ValUndef) {
		i++;
	}

	return i - IdxMin;

}

int MaxNbEl (TabInt T)

{
	return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx (TabInt T)

{
	return IdxMin;
}

IdxType GetLastIdx (TabInt T)

{
	return NbElmt(T) + IdxMin - 1;
}

boolean IsIdxValid (TabInt T, IdxType i)

{
	return ((i >= IdxMin) && (i<= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)

{
	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T) );
}


boolean IsEmpty (TabInt T)

{
	return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T)

{
	return (NbElmt(T) == MaxNbEl(T));
}

void TulisIsiTab (TabInt T)
{
    int i;

    printf("[");
	for (i = GetFirstIdx(T); IsIdxEff(T, i); i++) {
		if (i != GetFirstIdx(T)) {
			printf(",");
		}
		printf("%d",Elmt(T,i));
	}
	printf("]");
}


boolean IsEQ (TabInt T1, TabInt T2)
{
    int i;

    if (NbElmt(T1) != NbElmt(T2)){
        return false;
    }
    else{
        for ( i = IdxMin;(i<= NbElmt(T1));i++){
			if ((Elmt(T1,i) != ValUndef) && (Elmt(T2,i) != ValUndef)){
				if (Elmt(T1,i) != Elmt(T2,i)) {
					return false;
				}
			}
        }
    }

    return true;
}

IdxType Search1 (TabInt T, ElType X)
{
    int i;
    for ( i = IdxMin;(i<= NbElmt(T));i++){
            if (Elmt(T,i) == X){
      
                return i;
            }
        } 
    return IdxUndef;
}

boolean SearchB (TabInt T, ElType X)

{
    int i;

    for ( i = IdxMin;(i<= NbElmt(T));i++){
            if (Elmt(T,i) == X){
                return true;
            }
        }
    return false;
}

void MaxMin (TabInt T, ElType * Max, ElType * Min)

{
    *Max = Elmt(T, GetFirstIdx(T));
    *Min = Elmt(T, GetFirstIdx(T));
    int i;
    for ( i = IdxMin; (i <= NbElmt(T)); i++){
		if (Elmt(T,i) != ValUndef){

			if (Elmt(T,i) > *Max) {
				*Max = Elmt(T,i);
			}
			if (Elmt(T,i) < *Min) {
				*Min = Elmt(T,i);
			}
		}
    }
}

ElType SumTab (TabInt T)
{
	int sum = 0;
	int i;

	for (i = IdxMin; i <= IdxMax ; i++){
		if (Elmt(T,i) != ValUndef){
			sum += Elmt(T,i);
		}

	}
	return sum;
}



int CountX (TabInt T, ElType X)

{
	int count = 0;
	int i;

	for (i = IdxMin; i <= IdxMax ; i++){
		if (Elmt(T,i) == X){
			count += 1;
		}

	}
	return count;
}


void Sort (TabInt * T, boolean asc)

{
	int i, j, flag, temp;
    flag = GetFirstIdx(*T);
    if (NbElmt(*T) > 1){
        for (j = IdxMin; j <= GetLastIdx(*T)-1; j++){
            flag = j;
            for (i = j+1 ; i <= GetLastIdx(*T); i++){

				if (asc){
					if (Elmt(*T,i) < Elmt (*T,flag)){
						flag = i;
					}
                }
                else{
					if (Elmt(*T,i) > Elmt (*T,flag)){
						flag = i;
					}
				}
            }
            temp = Elmt(*T,flag);
            Elmt(*T, flag) = Elmt(*T, j);
            Elmt(*T,j) = temp;
        }
    }
}

void AddAsLastEl (TabInt * T, ElType X)
{
    Elmt(*T,GetLastIdx(*T)+1) = X;
}


void DelLastEl (TabInt * T, ElType * X)

{
	*X = Elmt(*T,GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}