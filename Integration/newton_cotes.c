#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "integration.h"

/* ********************************************************** */
/* ***************** Newton-Cotes Method ******************** */
/* ********************************************************** */
void newtonCotes()
{
    int i, j;
    double dA[MAX], x;
    for(j = 0; j < N; j++)
    {
        AreaNC[j]=0; /* Initialize calculated Area to zero */
        for(i = 0; i < (N-j); i++)
        {
            x = (i + 0.5) * dx[j];
            dA[i] = sqrt(1 - x*x) * dx[j];
            AreaNC[j] = AreaNC[j] + dA[i];
        }
        ErrNC[j] = fabs( ( ( AreaNC[j] - (M_PI/4.) ) / (M_PI/4.) ) * 100 );
    }
}