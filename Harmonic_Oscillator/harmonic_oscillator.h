#ifndef HARMONIC_OSCILLATOR_H
#define HARMONIC_OSCILLATOR_H

/* ********************************************************** */
/* ********************* EULER METHOD *********************** */
/* ********************************************************** */
void eulerCalc();

/* ********************************************************** */
/* ****************** RUNGE-KUTTA METHOD ******************** */
/* ********************************************************** */
void rungeKuttaCalc();

/* ********************************************************** */
/* ****************** ANALYTICAL SOLUTION ******************* */
/* ********************************************************** */
void analyticalCalc();

/* ********************************************************** */
/* ********************* ERROR ANALYSIS ********************* */
/* ********************************************************** */
void errorAnalysis();

/* ********************************************************** */
/* ******************** WRITE TO FILE *********************** */
/* ********************************************************** */
void write();

#endif