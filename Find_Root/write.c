#include <stdio.h>
#include <math.h>
#include "find_root.h" 
#include "global_variables.h"


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