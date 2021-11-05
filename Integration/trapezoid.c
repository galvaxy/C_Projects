#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "integration.h"

/* ********************************************************** */
/* ******************** Trapezoid Rule ********************** */
/* ********************************************************** */
void trapezoid()
{
    int i, j;
    double dA[MAX], x1, x2;
    for(j = 0; j < N; j++)
    {
        AreaT[j]=0; /* Initialize calculated Area to zero */
        for(i = 0; i < (N-j); i++)
        {
            x1 = i * dx[j];
            x2 = (i + 1) * dx[j];
            dA[i] = 0.5 * ( sqrt(1 - x1*x1) + sqrt(1 - x2*x2) ) * dx[j];
            AreaT[j] = AreaT[j] + dA[i];
        }
        ErrT[j] = fabs( ( (AreaT[j] - (M_PI/4.) ) / (M_PI/4.) ) * 100 );
    }
}