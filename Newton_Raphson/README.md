NEWTON-RAPHSON ALGORITHM:

f(x)= x^3 - 2*x^2 + x - 3

This program calculates the root of the above polynomial within a specified error margin (5 decimal places) in the calculate.c file.
The error threshold can be defined in the implimentation file initialize.c. 
The calculation is based off of an initial guess for the root which is taken as user input in initialize.c.
Polynomial can be redefined in calculate.c and the premise may be adjusted in initialize.c and write.c.

x(i+1) = x(i) - f(x(i))/f'(x(i))

The Newton-Raphson method of finding roots uses iterations of the above equation where 0 < i < MAX-1.
MAX = total number of iterations and x(0) is an initial guess at the root of the function.
MAX can befined in the header file global_variables.h. 

The display.c file prints results of the calculation to terminal.
The output of the calculation is written to file in write.c. 
The output files are of type .txt and the name of the file is taken as user input.