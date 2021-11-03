#include <stdio.h>
#include <math.h>
#include "Newton_Raphson.h"

/* ********************************************** */
/* **********   Initialize variables   ********** */
/* ********************************************** */
void initialize()
{
    /* If function is redefined it must also be redefined in the premise (string below) */
    printf("The equation is f(x)= x^3 - 2*x^2 + x - 3.\n\nInitial guess for the root-> ");
    scanf("%lf", &x0);
    x[0] = x0;
}

/* *************************************************** */
/* * Calculate iterations and store them in an array * */
/* *************************************************** */
void calculate()
{
    /*
    The function is f(x) = x^3 - 2*x^2 + x - 3, therefore f(x) prime is,
    f'(x) = 3*x^2 - 4*x + 1 (Unless function is redefined). 
    The Newton-Raphson method of finding roots uses iterations of the equation,
    x(i+1) = x(i) - f(x(i))/f'(x(i)), where 0<i<MAX , MAX=total number of iterations
    and x(0) is an initial guess at the root of the function.
    */

    for(int i = 0; i < MAX-1 ; i++)
    {
        printf("%.2f %.2f\n", x0, x[0]);
        /* To change polynomial redefine func and funcprime (the function and its first derivative must be analytical)*/
        func[i] = (x[i]*x[i]*x[i]) - (2*x[i]*x[i]) + x[i] - 3; /* Function to find root */
        funcprime[i] = (3*x[i]*x[i]) - (4*x[i]) + 1;  /* First derivative of function */
        x[i + 1] = x[i] - ((func[i])/(funcprime[i]));
    }
    func[MAX-1] = (x[MAX-1]*x[MAX-1]*x[MAX-1]) - (2*x[MAX-1]*x[MAX-1]) + x[MAX-1] - 3; /* Function to find root */
    funcprime[MAX-1] = (3*x[MAX-1]*x[MAX-1]) - (4*x[MAX-1]) + 1;  /* First derivative of function */
}


/* *********************************************** */
/* *********   Display data on terminal   ******** */
/* *********************************************** */
void display()
{
    printf("\n\nWith an initial guess of %.2f and %d iterations,\n", x0, MAX);
    printf("the Newton-Raphson sequence is\n\n");
    printf("Iteration     x (Root)           f(x)\n");
    printf("----------------------------------------");
    int i;
    for(i = 0; i < MAX && fabs(func[i + 1]) < fabs(func[i]); i++)
    {
        printf("\n    %d         %3.5f          %3.5f\n ", i, x[i], func[i]);
    }
    if(i < MAX-1 && fabs(func[i + 1]) > fabs(func[i]))
    {
        printf("\n    %d         %3.5f          %3.5f\n ", i + 1, x[i + 1], func[i + 1]);
        printf("\n\nSequence diverges.\n\n");
    }
    else if(i < MAX-1 && fabs(func[i + 1]) == fabs(func[i]))
    {
        printf("\n\nSequence converged.\n\n");
    }
    for(i = 0; i < MAX; i++)
    {
        if(funcprime[i] == 0)
        {
            printf("\n\nInitial guess leads to an undefined value.\n\n");
        }
    }
}

/* ************************************************* */
/* ************   write data to file   ************* */
/* ************************************************* */
void write()
{
    int i;
    char answer, file;
    FILE *stream;
    printf("\n\nEnter 's' to write data to a file or any other key to exit-> ");
    scanf("%s", &answer);
    if(answer == 's' || answer == 'S')
    {
        printf("\n\nEnter the name of the file-> ");
        scanf("%s", &file);
        stream = fopen(&file, "w");
        /* If function is redefined it must also be redefined in the premise (string below) */
        fprintf(stream, "The equation is f(x)= x^3 - 2*x^2 + x - 3.");
        fprintf(stream, "\n\nWith an initial guess of %.2f and %d iterations,",x[0], MAX);
        fprintf(stream, "\nthe Newton-Raphson sequence is\n\n");
        fprintf(stream, "Iteration     x (Root)           f(x)\n");
        fprintf(stream, "----------------------------------------\n");
        for(i = 0; i < MAX-1 && fabs(func[i + 1]) < fabs(func[i]); i++)
        {
            fprintf(stream, "    %d         %3.5f          %3.5f\n", i, x[i], func[i]);
        }
        if(i < MAX-1 && fabs(func[i + 1]) > fabs(func[i]))
        {
            fprintf(stream, "\n    %d         %3.5f          %3.5f\n", i + 1, x[i + 1], func[i + 1]);
            fprintf(stream, "\n\nSequence diverges.\n\n");
        }
        else if(i < MAX-1 && fabs(func[i + 1]) <= fabs(func[i]))
        {
            fprintf(stream, "\n\nSequence converged.\n\n");
        }
        for(i = 0; i < MAX; i++)
        {
            if(funcprime[i] == 0)
            {
                fprintf(stream, "\n\nThis guess leads to an undefined value.\n\n");
            }
        }
        fclose(stream);
    }
}