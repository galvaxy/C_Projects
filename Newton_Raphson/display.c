#include <stdio.h>
#include <math.h>
#include "newton_raphson.h" 
#include "global_variables.h"

/* *********************************************** */
/* *********   Display data on terminal   ******** */
/* *********************************************** */
void display()
{
    printf("\n\nWith an initial guess of %.2f the Newton-Raphson sequence is:\n\n", x0);
    printf("Iteration     x (Root)           f(x)\n");
    printf("----------------------------------------\n");
    int i;
    int last;
    if(cap<MAX-1)
    {
        last = cap;
    }
    else last = MAX-1;
    for(i = 0; i <= last; i++)
    {
        printf("   %d         %.5f          %.5f\n", i, x[i], func[i]);
    }
    if(i==MAX)
    {
        printf("\nMaximum iterations reached, MAX = %d\n", MAX);
    }
    else
    {
        if(fabs(func[i]) > fabs(func[i-1]))
        {
            printf("   %d         %.5f          %.5f\n", i, x[i], func[i]);
            printf("\n\nSequence diverges.\n\n");
        }
        else if( fabs( fabs(func[i]) - fabs(func[i-1]) ) < threshold)
        {
            printf("   %d         %.5f          %.5f\n", i, x[i], func[i]);
            printf("\n\nSequence converged.\n\n");
        }
        else
        {
            printf("\n\nInitial guess leads to an undefined value.\n");
            printf("Derivative of the polynomial is singular at x[%d]\n", i-1);
        }
    }
}