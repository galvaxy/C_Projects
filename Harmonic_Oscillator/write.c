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
    stream = fopen("eulerMethod.txt", "w");
    output = fopen("rungeKuttaMethod.txt", "w");
    int i;
    for(i = 0; i < MAX; i++)
        {
            double t = i*dt;
            fprintf(stream, "%0.3f\t%3.3f\t%3.3f\t%3.3f\n", t, xe[i], ErrEu[i], EnEu[i]);
        }
    for(i = 0; i < MAX; i++)
        {
            double t=i*dt;
            fprintf(output, "%0.3f\t%3.3f\t%3.3f\t%3.3f\n",t,xrk[i],ErrRK[i],EnRK[i]);
        }
}