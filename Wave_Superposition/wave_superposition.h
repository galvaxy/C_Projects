#ifndef WAVE_SUPERPOSITION_H
#define WAVE_SUPERPOSITION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXj 200 // 100 time steps (j) is enough time (given the speed of the waves and the length of the string) for the waves to propagate, reflect and propagate back.
#define MAXi 100 // Given the size of the string and delta(x), 100 spatial samples (i) is enough to measure the entire string.

double y[MAXi][3];
double dx, c, r, dt; // r = c * (dt/dx)

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize();

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate();

#endif