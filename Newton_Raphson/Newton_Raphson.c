#include <stdio.h>
#include <math.h>
#include "Newton_Raphson.h"

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
}

/* *************************************************** */
/* * Calculate iterations and store them in an array * */
/* *************************************************** */
void calculate()
{
    /*
    The Newton-Raphson method of finding roots uses iterations of the equation,
    x(i+1) = x(i) - f(x(i))/f'(x(i)), where 0<i<MAX-1 , MAX=total number of iterations
    and x(0) is an initial guess at the root of the function.
    */
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

/* ************************************************* */
/* ************   write data to file   ************* */
/* ************************************************* */
void write()
{
    char answer;
    char file[15];
    FILE *stream;
    printf("\n\nEnter 's' to write data to a file or any other key to exit-> ");
    scanf("%s", &answer);
    if(answer == 's' || answer == 'S')
    {
        printf("\n\nEnter the name of the file-> ");
        scanf("%s", file);
        stream = fopen(file, "w");
        /* If function is redefined it must also be redefined in the premise (string below) */
        fprintf(stream, "The equation is f(x)= x^3 - 2*x^2 + x - 3.");
        fprintf(stream, "\n\nWith an initial guess of %.2f the Newton-Raphson sequence is:\n\n", x[0]);
        fprintf(stream, "Iteration     x (Root)           f(x)\n");
        fprintf(stream, "----------------------------------------\n");
        int i;
        int last;
        if(cap<MAX-1)
        {
            last = cap;
        }
        else last = MAX-1;
        for(i = 0; i <= last; i++)
        {
            fprintf(stream, "    %d         %3.5f          %3.5f\n", i, x[i], func[i]);
        }
        if(i==MAX)
        {
            fprintf(stream, "\nMaximum iterations reached, MAX = %d\n", MAX);
        }
        else
        {
            if(fabs(func[i]) > fabs(func[i-1]))
            {
                fprintf(stream, "    %d         %3.5f          %3.5f\n", i, x[i], func[i]);
                fprintf(stream, "\n\nSequence diverges.\n\n");
            }
            else if( fabs( fabs(func[i]) - fabs(func[i-1]) ) < threshold)
            {
                fprintf(stream, "    %d         %3.5f          %3.5f\n", i, x[i], func[i]);
                fprintf(stream, "\n\nSequence converged.\n\n");
            }
            else
            {
                fprintf(stream, "\n\nInitial guess leads to an undefined value.\n");
                fprintf(stream, "Derivative of the polynomial is singular at x[%d]\n", i-1);
            }
        }
        fclose(stream);
    }
}