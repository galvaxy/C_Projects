#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "celestial_mechanics.h"

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize()
{
    m1 = 5*Ms; //Mass of star1: 5 x Mass of Sun
    m2 = Ms; //Mass of star2: 1 x Mass of Sun
    m3 = 2*Me; //Mass of planet: 2 x Mass of earth

    //Body 2
    x[1][0] = 1.5;
    y[1][0] = 0;
    z[1][0] = 0;

    //Body 3
    x[2][0] = 8.5;
    y[2][0] = 0;
    z[2][0] = 0;

    //Calculate initial position of Body 1
    x[0][0] = -((double)m2 / m1) * x[1][0] - ((double)m3 / m1) * x[2][0];
    y[0][0] = -((double)m2 / m1) * y[1][0] - ((double)m3 / m1) * y[2][0];
    z[0][0] = -((double)m2 / m1) * z[1][0] - ((double)m3 / m1) * z[2][0];

    //Body 3
    vx[2][0] = 0;
    vy[2][0] = 0.0097;
    vz[2][0] = 0.0077;

    //Body 1
    vx[0][0] = 0;
    vy[0][0] = -0.005;
    vz[0][0] = 0;

    //Calculate initial velocity of body 2
    vx[1][0] = -((double)m1 / m2) * vx[0][0] - ((double)m3 / m2) * vx[2][0];
    vy[1][0] = -((double)m1 / m2) * vy[0][0] - ((double)m3 / m2) * vy[2][0];
    vz[1][0] = -((double)m1 / m2) * vz[0][0] - ((double)m3 / m2) * vz[2][0];
}