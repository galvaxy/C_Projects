/*
Newton-Raphson algorithm
This program calculates the root of the polynomial
f(x)= x^3 - 2*x^2 + x - 3, within a specified error
margin. The calculation is based off of an initial guess for the root.
Polynomial can be redefined in calculate() function and
the premise may be adjusted in initialize() function and write() function.
*/


#include <stdio.h>
#include <math.h>
#include "Newton_Raphson.h"


int main()
{
    initialize();
    calculate();
    display();
    write();

    return 0;
}