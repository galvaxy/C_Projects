#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H


#define MAX 100 /* Max number of arguments held in Arrays */
#define N 100  /* starting number of steps in area calculation */

double AreaNC[MAX], AreaT[MAX], AreaS[MAX];   /* Arrays to hold calculated values of the area dependent on step size */
double ErrNC[MAX], ErrT[MAX], ErrS[MAX], dx[MAX];  /* Arrays to hold errors involved with the chosen step size. dx[] holds the step size values. */

#endif