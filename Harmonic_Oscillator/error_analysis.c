#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "harmonic_oscillator.h"

/* ********************************************************** */
/* ********************* ERROR ANALYSIS ********************* */
/* ********************************************************** */

void errorAnalysis()
{
    int i;
    for(i=0;i<=MAX;i++)
        {
           ErrEu[i] = ((xe[i]-xa[i])/xa[i])*100.;
           ErrRK[i] = ((xrk[i]-xa[i])/xa[i])*100.;
        }

}