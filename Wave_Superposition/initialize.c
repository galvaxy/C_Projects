#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave_superposition.h"

double dx = 0.01, c = 300, r = 1, dt; // r = c * (dt/dx)

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize()
{
    int i;
    double k = 1000; //The value of k is a measure of the width of the Gaussian pluck

    dt = (double)dx / c; // If r is to equal 1 than this relationship must hold

    for(i = 0; i < MAXi; i++) //Initialize the shape of the pluck of the string (two Gaussian's)
    {
        y[i][0] = exp(-k * (i * dx - 0.8) * (i * dx - 0.8)) + exp(-k * (i * dx - 0.1) * (i * dx - 0.1));
        y[i][1] = exp(-k * (i * dx - 0.8) * (i * dx - 0.8)) + exp(-k * (i * dx - 0.1) * (i * dx - 0.1));
    }

    y[0][2] = 0; //initialize the boundary conditions
    y[MAXi - 1][2] = 0; //the ends of the strings are fixed.
}