#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include <stdio.h>
#include <math.h>

#define MAX 10 // Max number of iterations 

double func[MAX], funcprime[MAX], x[MAX]; 
/*
func[]  holds values of function evaluated at ith iteration,
funcprime[]  holds values of first derivative of function evaluated at ith iteration,
x[] holds converging x values,
*/

double x0;  // x0 = initial guess

double threshold = 0.00001; // accuracy tolerance (must converge to 5 decimal places)

int cap = MAX; // store number of iterations before convergence (if converges before MAX iterations)

/* ********************************************** */
/* **********   Initialize variables   ********** */
/* ********************************************** */
void initialize();

/* *************************************************** */
/* * Calculate iterations and store them in an array * */
/* *************************************************** */
void calculate();


/* *********************************************** */
/* *********   Display data on terminal   ******** */
/* *********************************************** */
void display();

/* ************************************************* */
/* ************   write data to file   ************* */
/* ************************************************* */
void write();

#endif