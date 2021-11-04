set terminal qt 0
set size square 
set xrange [0:5]
set yrange [-0.2:0.2]
set grid lt 0 lw 1
set xtics 1 font "Menlo,15"
set ytics 0.05 font "Menlo,15"
set xlabel 't(s)' offset 0.5,-0.5 font "Menlo,20"
set ylabel 'Amplitude' offset -4,0 font "Menlo,20"
set key font "Menlo,15"
set style data linespoints 
plot "eulerMethod.txt" using 1:2 lt 7 lw 2 ti "Euler Method", "rungeKuttaMethod.txt" using 1:2 lt 6 lw 2 ti "Runge-Kutta Method"

set terminal qt 1
set size square 
set xrange [0:5]
set yrange [-45:45]
set grid lt 0 lw 1
set xtics 1 font "Menlo,15"
set ytics 5 font "Menlo,15"
set xlabel 't(s)' offset 0.5,-0.5 font "Menlo,20"
set ylabel '% Error' offset -4,0 font "Menlo,20"
set key font "Menlo,15"
set style data linespoints 
plot "eulerMethod.txt" using 1:3 lt 7 lw 2 ti "Euler Method", "rungeKuttaMethod.txt" using 1:3 lt 6 lw 2 ti "Runge-Kutta Method"

set terminal qt 2
set size square 
set xrange [0:5]
set yrange [0:0.01]
set grid lt 0 lw 1
set xtics 1 font "Menlo,15"
set ytics 0.001 font "Menlo,15"
set xlabel 't(s)' offset 0.5,-0.5 font "Menlo,20"
set ylabel 'Energy' offset -4,0 font "Menlo,20"
set key font "Menlo,15"
set style data linespoints 
plot "eulerMethod.txt" using 1:4 lt 7 lw 2 ti "Euler Method", "rungeKuttaMethod.txt" using 1:4 lt 6 lw 2 ti "Runge-Kutta Method"