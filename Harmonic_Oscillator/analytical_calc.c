#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "harmonic_oscillator.h"

/* ********************************************************** */
/* ****************** ANALYTICAL SOLUTION ******************* */
/* ********************************************************** */
void analyticalCalc()
{
    int i;
    for(i = 0; i < MAX; i++)
        {
            xa[i] = xo*cos(omega*i*dt)+(vo/omega)*sin(omega*i*dt);
            va[i] = vo*cos(omega*i*dt)-xo*omega*sin(omega*i*dt);
        }
}