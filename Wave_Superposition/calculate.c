#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave_superposition.h"

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate()
{
    FILE *stream;
    stream = fopen("waveSuperposition.txt", "w");

    int i, j;

    for(j = 0; j < 2; j++) //print the initial wave profile because that information (stored in an array) will be replaced in the next loop
    {
        for(i = 0; i < MAXi; i++)
        {
            fprintf(stream, "%.2f\t%.3f\n", i * dx, y[i][j]);
        }
        fprintf(stream, "\n\n");
    }
    for(j = 0; j <= MAXj; j++) // calculate the wave profile at the next time step
    {
        for(i = 1; i < MAXi - 1; i++)
        {
            y[i][2] = 2 * (1 - r*r) * y[i][1] + r*r * (y[i + 1][1] + y[i - 1][1]) - y[i][0];
        }
        for(i = 0; i < MAXi; i++) //print newly calculated profile
        {
            fprintf(stream, "%.2f\t%.3f\n", i * dx, y[i][2]);
        }
        fprintf(stream, "\n\n");
        for(i = 0; i < MAXi; i++) //re-initialize arrays so to save memory usage. Only 3 time steps are ever stored at a time.
        {
            y[i][0] = y[i][1];
            y[i][1] = y[i][2];
        }
    }
}