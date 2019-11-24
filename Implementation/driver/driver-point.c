#include "../../include1/point.h"
#include <stdio.h>
#include<stdlib.h>
int main()
{
    POINT X;
    X.X = 12;
    X.Y = 10;
    printf("(X,Y) = (%d,%d)\n",X.X,X.Y);
    return 0;
}