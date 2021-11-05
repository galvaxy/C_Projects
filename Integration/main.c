#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "integration.h"

int main()
{
    int i;
    for(i = 0; i < N; i++)  /* Save all values of step sizes */
    {
        dx[i] = 1. / (double)(N - i);
    }

    newtonCotes();
    trapezoid();
    simpson();
    save();
    
    return 0;
}