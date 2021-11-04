#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "harmonic_oscillator.h"

/* ********************************************************** */
/* ********************* EULER METHOD *********************** */
/* ********************************************************** */

void eulerCalc()
{
    int i;
    xe[0]=xo;
    ve[0]=vo;
    for(i=0;i<=MAX;i++)
        {
           ve[i+1] = ve[i] - omega*omega*xe[i]*dt;
           xe[i+1] = xe[i] + ve[i]*dt;
           EnEu[i] = 0.5*ve[i]*ve[i]+0.5*xe[i]*xe[i];        }
}