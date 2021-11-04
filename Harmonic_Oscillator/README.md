HARMONIC OSCILLATOR -> EULER VS RUNGE-KUTTA 4TH ORDER METHOD:

This program calculates, numerically, the solution to the harmonic oscillator using both Euler's method and Runge-Kutta 4th order method. Equation of harmonic oscillator is given by d^2x/dt^2 + w^2 x = 0 with w -> angular velocity. 

Euler method simply descretizes the differential equation in euler_calc.c. Runge-Kutta 4th order method descretizes the differential equation in four ways and averages over different descretization schemes in runge_kutta_calc.c.

Initial conditions are set in main.c along with values for the angular velocity and the spring constant. The results of both methods are compared to the analytical calculation in analytical_calc.c. The error calculated from the comparison is found in error_analysis.c All results of calculation are written to .txt files in write.c. Results can be found in eulerMethod.txt and rungeKuttaMethod.txt.

The plots.gp is a GnuPlot script which can be run using GnuPlot from terminal to vizualize results. It can be seen that Runge-Kutta method is a much more reliabel method than Euler method. In Euler method, large errors cause a violation in energy conservation. These errors are not present in Runge-Kutta method.

