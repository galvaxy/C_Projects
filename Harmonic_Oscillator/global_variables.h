#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#define MAX 50 // Max = maximum number of steps 

double dt, omega, k, xo, vo; // dt = time step, xo and vo are boundry conditions, omega = angular velocity, k = spring constant
double xe[MAX], ve[MAX], xrk[MAX], vrk[MAX], xa[MAX], va[MAX]; // Positions and velocities for Euler, Runge-Kutta and analytical calc
double ErrEu[MAX], ErrRK[MAX], EnEu[MAX], EnRK[MAX]; // Error and Energy values in Euler and in Runge-Kutta method

#endif 