#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global_variables.h"
#include "harmonic_oscillator.h"

int main()
{
    dt = 0.1;
    omega = 1;
    xo = 0.1;
    vo = 0;
    
    eulerCalc();
    rungeKuttaCalc();
    analyticalCalc();
    errorAnalysis();
    write();
    return 0;
}