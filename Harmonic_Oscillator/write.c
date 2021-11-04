#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "harmonic_oscillator.h"

/* ********************************************************** */
/* ********************* WRITE TO FILE ********************** */
/* ********************************************************** */

void write()
{
    FILE *stream, *output;
    stream = fopen("EulerMethod.txt","w");
    output = fopen("RungeKuttaMethod.txt","w");
    int i;
    fprintf(stream, "\n\n                           Euler's Method\n          Time         x(t)          Percent Error        Energy\n");
    for(i=0;i<=MAX;i++)
        {
           double t=i*dt;
           fprintf(stream, "\n         %0.3f        %3.3f             %3.3f             %3.3f    ",t,xe[i],ErrEu[i],EnEu[i]);
        }
    fprintf(output, "\n\n                           Runge-Kutta Method\n          Time         x(t)          Percent Error        Energy\n");
    for(i=0;i<=MAX;i++)
        {
           double t=i*dt;
           fprintf(output, "\n         %0.3f        %3.3f             %3.3f             %3.3f    ",t,xrk[i],ErrRK[i],EnRK[i]);
        }
}