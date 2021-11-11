#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "celestial_mechanics.h"

/* ********************************************************** */ 
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate()
{
    int j,i;

    FILE *body1, *body2, *body3, *radii, *orbit;

    body1 = fopen("Solar_System/Sun.txt", "w");
    body2 = fopen("Solar_System/Jupiter.txt", "w");
    body3 = fopen("Solar_System/Earth.txt", "w");
    radii = fopen("Solar_System/Radii.txt", "w");
    orbit = fopen("Solar_System/Orbit.txt", "w");

    //print initial conditions
    //Print Results for body 1
    fprintf(body1, "%.10f\t%.10f\t%.10f\n", x[0][0], y[0][0], z[0][0]);

    //print results for body 2
    fprintf(body2, "%.10f\t%.10f\t%.10f\n", x[1][0], y[1][0], z[1][0]);

    //print results for body 3
    fprintf(body3, "%.10f\t%.10f\t%.10f\n", x[2][0], y[2][0], z[2][0]);

    fprintf(body1, "\n\n");
    fprintf(body2, "\n\n");
    fprintf(body3, "\n\n");

    //Print Initial position in orbit
    fprintf(orbit, "%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\n", x[0][0], y[0][0], z[0][0], x[1][0], y[1][0], z[1][0], x[2][0], y[2][0], z[2][0]);

    for(j = 0; j < MAXj; j++)
    {
        //Calculate the magnitude of the position vectors at current time step
        for(i = 0; i < 3; i++)
        {
            RMag[i] = sqrt( x[i][j] * x[i][j] + y[i][j] * y[i][j] + z[i][j] * z[i][j] );
        }

        //Calculate the vector dot products between the three position vectors
        RR[0] = x[0][j] * x[1][j] + y[0][j] * y[1][j] + z[0][j] * z[1][j]; //R1*R2
        RR[1] = x[0][j] * x[2][j] + y[0][j] * y[2][j] + z[0][j] * z[2][j]; //R1*R3
        RR[2] = x[1][j] * x[2][j] + y[1][j] * y[2][j] + z[1][j] * z[2][j]; //R2*R3

        //Calculate the magnitude of the relative displacement vectors between the bodies
        rMag[0] = sqrt( RMag[1] * RMag[1] - 2 * RR[0] + RMag[0] * RMag[0] ); //Distance between body 1 and 2
        rMag[1] = sqrt( RMag[2] * RMag[2] - 2 * RR[1] + RMag[0] * RMag[0] ); //Distance between body 1 and 3
        rMag[2] = sqrt( RMag[2] * RMag[2] - 2 * RR[2] + RMag[1] * RMag[1] ); //Distance between body 2 and 3

        //Print Results for radii
        fprintf(radii, "%d\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\n", j, RMag[0], RMag[1], RMag[2], rMag[0], rMag[1], rMag[2]);

        //Calculate the position and velocity at next time step of body 1
        vx[0][j + 1] = vx[0][j] + G * ( m2 * (x[1][j] - x[0][j]) / (rMag[0] * rMag[0] * rMag[0]) + m3 * (x[2][j] - x[0][j]) / (rMag[1] * rMag[1] * rMag[1]) ) * dt;
        x[0][j + 1] = x[0][j] + vx[0][j + 1] * dt;

        vy[0][j + 1] = vy[0][j] + G * ( m2 * (y[1][j] - y[0][j]) / (rMag[0] * rMag[0] * rMag[0]) + m3 * (y[2][j] - y[0][j]) / (rMag[1] * rMag[1] * rMag[1]) ) * dt;
        y[0][j + 1] = y[0][j] + vy[0][j + 1] * dt;

        vz[0][j + 1] = vz[0][j] + G * ( m2 * (z[1][j] - z[0][j]) / (rMag[0] * rMag[0] * rMag[0]) + m3 * (z[2][j] - z[0][j]) / (rMag[1] * rMag[1] * rMag[1]) ) * dt;
        z[0][j + 1] = z[0][j] + vz[0][j + 1] * dt;

        //Calculate the position and velocity at next time step of body 2
        vx[1][j + 1] = vx[1][j] + G * ( m3 * (x[2][j] - x[1][j]) / (rMag[2] * rMag[2] * rMag[2]) - m1 * (x[1][j] - x[0][j]) / (rMag[0] * rMag[0] * rMag[0]) ) * dt;
        x[1][j + 1] = x[1][j] + vx[1][j + 1] * dt;

        vy[1][j + 1] = vy[1][j] + G * ( m3 * (y[2][j] - y[1][j]) / (rMag[2] * rMag[2] * rMag[2]) - m1 * (y[1][j] - y[0][j]) / (rMag[0] * rMag[0] * rMag[0]) ) * dt;
        y[1][j + 1] = y[1][j] + vy[1][j + 1] * dt;

        vz[1][j + 1] = vz[1][j] + G * ( m3 * (z[2][j] - z[1][j]) / (rMag[2] * rMag[2] * rMag[2]) - m1 * (z[1][j] - z[0][j]) / (rMag[0] * rMag[0] * rMag[0]) ) * dt;
        z[1][j+1]=z[1][j]+vz[1][j+1]*dt;

        //Calculate the position and velocity at next time step of body 3
        vx[2][j + 1] = vx[2][j] - G * ( m1 * (x[2][j] - x[0][j]) / (rMag[1] * rMag[1] * rMag[1]) + m2 * (x[2][j] - x[1][j]) / (rMag[2] * rMag[2] * rMag[2]) ) * dt;
        x[2][j + 1] = x[2][j] + vx[2][j + 1] * dt;

        vy[2][j + 1] = vy[2][j] - G * ( m1 * (y[2][j] - y[0][j]) / (rMag[1] * rMag[1] * rMag[1]) + m2 * (y[2][j] - y[1][j]) / (rMag[2] * rMag[2] * rMag[2]) ) * dt;
        y[2][j + 1] = y[2][j] + vy[2][j + 1] * dt;

        vz[2][j + 1] = vz[2][j] - G * ( m1 * (z[2][j] - z[0][j]) / (rMag[1] * rMag[1] * rMag[1]) + m2 * (z[2][j] - z[1][j]) / (rMag[2] * rMag[2] * rMag[2]) ) * dt;
        z[2][j + 1] = z[2][j] + vz[2][j + 1] * dt;

        //Print Results for body 1
        fprintf(body1, "%.10f\t%.10f\t%.10f\n", x[0][j + 1], y[0][j + 1], z[0][j + 1]);

        //print results for body 2
        fprintf(body2, "%.10f\t%.10f\t%.10f\n", x[1][j + 1], y[1][j + 1], z[1][j + 1]);

        //print results for body 3
        fprintf(body3, "%.10f\t%.10f\t%.10f\n", x[2][j + 1], y[2][j + 1], z[2][j + 1]);

        fprintf(body1, "\n\n");
        fprintf(body2, "\n\n");
        fprintf(body3, "\n\n");

        //Print position in orbit at current time step
        fprintf(orbit,"%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\t%.5f\n", x[0][j + 1], y[0][j + 1], z[0][j + 1], x[1][j + 1], y[1][j + 1], z[1][j + 1], x[2][j + 1], y[2][j + 1], z[2][j + 1]);
    }
}