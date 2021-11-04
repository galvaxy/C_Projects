#include <stdio.h>
#include <math.h>
#include "find_root.h" 
#include "global_variables.h"

/* *************************************************** */
/* * Calculate iterations and store them in an array * */
/* *************************************************** */
void calculate()
{
    int i;
    for(i = 0; i < MAX-1 ; i++)
    {   
        // To change polynomial redefine func and funcprime (the function and its first derivative must be analytical) 
        func[i] = (x[i]*x[i]*x[i]) - (2*x[i]*x[i]) + x[i] - 3; 
        funcprime[i] = (3*x[i]*x[i]) - (4*x[i]) + 1; 
        if(funcprime[i] == 0)
        {
            cap = i;
            break;
        }
        x[i + 1] = x[i] - ((func[i])/(funcprime[i]));
        double check = (x[i+1]*x[i+1]*x[i+1]) - (2*x[i+1]*x[i+1]) + x[i+1] - 3;
        if( fabs( fabs(check) - fabs(func[i]) ) < threshold || fabs(check) > fabs(func[i]))
        {
            cap = i;
            func[i+1] = check;
            break;
        }
    }
    if(i == MAX-1)
    {
        func[MAX-1] = (x[MAX-1]*x[MAX-1]*x[MAX-1]) - (2*x[MAX-1]*x[MAX-1]) + x[MAX-1] - 3; 
    }
}