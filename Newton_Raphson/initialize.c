#include <stdio.h>
#include "newton_raphson.h" 
#include "global_variables.h"

/* ********************************************** */
/* **********   Initialize variables   ********** */
/* ********************************************** */
void initialize()
{
    /* If function is redefined it must also be redefined in the premise (string below) */
    printf("\n\nThe equation is f(x)= x^3 - 2*x^2 + x - 3.\n");
    printf("Initial guess for the root-> ");
    scanf("%lf", &x0);
    x[0] = x0;
    threshold = 0.00001;
    cap = MAX;
}