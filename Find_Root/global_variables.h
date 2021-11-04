#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#define MAX 10 // Max number of iterations 

double func[MAX], funcprime[MAX], x[MAX]; 
/*
func[] holds values of function evaluated at ith iteration
funcprime[] holds values of first derivative of function evaluated at ith iteration,
x[] holds converging x values,
*/

double x0; //x0 = initial guess

double threshold;// threshold = accuracy tolerance (must converge to 5 decimal places)

int cap; // store number of iterations before convergence (if converges before MAX iterations)

#endif