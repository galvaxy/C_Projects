#include <stdio.h>
#include "celestial_mechanics.h"

double x[3][MAXj],y[3][MAXj],z[3][MAXj]; //Arrays to hold positions of three bodies at the j'th time step (ex. x[1][j]=x position of body 1 at time j)
double vx[3][MAXj],vy[3][MAXj],vz[3][MAXj]; //Arrays to hold velocities of the three bodies at the j'th time step (ex. vx[1][j]=x component of velocity of body 1 at time j)
double RR[3]; //Array to hold the dot products between position vectors of the three bodies at j'th time step (RR[1][j]=R1*R2, RR[2][j]=R1*R3, RR[3][j]=R2*R3).
double RMag[3]; //Array to hold the magnitude of the position vectors of each body at j'th time step
double rMag[3]; // Array to hold the magnitude of the relative displacement vector of the three bodies at j'th time step (ex. rMag[1][j]=Distance between body 1 and body 2 at time j)
double m1,m2,m3; //These variables hold the value of the masses of the three bodies

int main()
{
    initialize();
    calculate();
    return 0;
}