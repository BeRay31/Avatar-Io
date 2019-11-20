#include <stdio.h>
#include "../include1/boolean.h"
#include "../include1/point.h"
#include <math.h>
POINT MakePOINT (float X, float Y)
{
    POINT P;
    P.X = X;
    P.Y = Y;
    return P;
}