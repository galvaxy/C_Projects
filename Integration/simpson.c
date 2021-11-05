#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "integration.h"

/* ********************************************************** */
/* ******************** Simpson's rule ********************** */
/* ********************************************************** */
void simpson()
{
    int i, j;
    double dA[MAX], x1, x2, x3;
    for(j = 0; j < N; j++)
    {
        AreaS[j] = 0; /* Initialize calculated Area to zero */
        for(i = 0; i < (N-j); i++)
        {
            x1 = i * dx[j];
            x2 = (i + 0.5) * dx[j];
            x3 = (i + 1) * dx[j];
            dA[i] = (1/6.) * ( sqrt(1 - x1*x1) + 4 * sqrt(1 - x2*x2) + sqrt(1 - x3*x3) ) * dx[j];
            AreaS[j] = AreaS[j] + dA[i];
        }
        ErrS[j] = fabs( ( ( AreaS[j] - (M_PI/4.) ) / (M_PI/4.) ) * 100 );
    }
}