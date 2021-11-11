#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "celestial_mechanics.h"

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize()
{
    m1 = Ms; //Mass of Body 1
    m2 = Mj; //Mass of Body 2
    m3 = Me; //Mass of body 3

    //Body 2
    x[1][0] = 2.5;
    y[1][0] = 0;
    z[1][0] = 0;

    //Body 3
    x[2][0] = -7.0;
    y[2][0] = 0;
    z[2][0] = 0;

    //Calculate initial position of Body 1
    x[0][0] = -((double)m2 / m1) * x[1][0] - ((double)m3 / m1) * x[2][0];
    y[0][0] = -((double)m2 / m1) * y[1][0] - ((double)m3 / m1) * y[2][0];
    z[0][0] = -((double)m2 / m1) * z[1][0] - ((double)m3 / m1) * z[2][0];

    //Body 2
    vx[1][0] = 0; 
    vy[1][0] = vj;     
    vz[1][0] = 0;

    //Body 3
    vx[2][0] = 0;
    vy[2][0] = -ve;
    vz[2][0] = 0;

    //Calculate initial velocity of body 1
    vx[0][0] = -((double)m2 / m1) * vx[1][0] - ((double)m3 / m1) * vx[2][0];
    vy[0][0] = -((double)m2 / m1) * vy[1][0] - ((double)m3 / m1) * vy[2][0];
    vz[0][0] = -((double)m2 / m1) * vz[1][0] - ((double)m3 / m1) * vz[2][0];
}