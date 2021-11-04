#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "harmonic_oscillator.h"

/* ********************************************************** */
/* ****************** RUNGE-KUTTA METHOD ******************** */
/* ********************************************************** */
void rungeKuttaCalc()
{
    int i;
    double kx1,kx2,kx3,kx4,kv1,kv2,kv3,kv4;
    xrk[0]=xo;
    vrk[0]=vo;
    for(i = 0; i < MAX-1; i++)
        {
            kx1 = vrk[i];
            kv1 = -omega*omega*xrk[i];
            kx2 = vrk[i]+0.5*kv1*dt;
            kv2 = -omega*omega*(xrk[i]+0.5*kx1*dt);
            kx3 = vrk[i]+0.5*kv2*dt;
            kv3 = -omega*omega*(xrk[i]+0.5*kx2*dt);
            kx4 = vrk[i]+kv3*dt;
            kv4 = -omega*omega*(xrk[i]+kx3*dt);
            xrk[i+1] = xrk[i]+(1./6.)*(kx1+2*kx2+2*kx3+kx4)*dt;
            vrk[i+1] = vrk[i]+(1./6.)*(kv1+2*kv2+2*kv3+kv4)*dt;
            EnRK[i] = 0.5*k*( (vrk[i]*vrk[i])/(omega*omega) + xrk[i]*xrk[i] );
        }
    EnRK[i] = 0.5*k*( (vrk[i]*vrk[i])/(omega*omega) + xrk[i]*xrk[i] );
}