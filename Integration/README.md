 INEGRATION -> NEWTON-COTES, SIMPSON AND TRAPEZOID ALGORITHMS:
 
 f(x) = sqrt(1 - x^2)
 
 This program Integrates the above function from 0 to 1 using the Newton Cotes method, the trapezoid rule and Simpson's rule. It then calculates the error relative to the analytic solution. This is done for various integration step sizes to study the error as a function of step size. The plots.gp file is a GnuPlot script which can be run using GnuPlot from terminal to view plots. It can be seen that for sufficiently small step sizes all algorithms do equally well. However, for larger step sizes the Simpsons algorithm has the smallest error and the Trapezoid algorithm has the largest error. Surprisingly, the Newton-Cotes algorithm does better than the Trapezoid algorithm and it not too far off from the Simpsons algorithm. Both the Simpsons rule and the Trapezoid rule begin to under-estimate the area for large step sizes while Netwon-Cotes over-estimates the area.
 
 The Newton-Cotes algorithm in newton_cote.c uses the midpoint rule to calculate the area (per step).
 f(xi + 0.5 dx) * dx 
 
 The Trapezoid algorithm in trapezoid.c averages the area (per step) calculated using the left and right points of the step size dx.
 0.5 * ( f(xi) + f(xi + dx) ) * dx
 
 The Simpson's algorithm in simpson.c averages over three points (per step), the left point, right point and midpoint.
 (1/6) * ( f(xi) + 4 f(xi + 0.5 dx) + f(xi + dx) ) * dx

 All algorithms use a Reimann sum over step schemes to calculate the total area. The results are written to a file names integration.txt in save.c.