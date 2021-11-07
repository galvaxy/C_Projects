set terminal qt 0
set terminal jpeg
set output "error.jpeg"
set size square
set style data linespoints 
set ytics 5 font "Menlo,15"
set xtics 0.1 font "Menlo,15"
set xlabel "Step Size" offset 0,-1 font "Menlo,20"
set ylabel "% Error" offset -1,0 font "Menlo,20"
set xrange [0:1]
set yrange[0:40]
set key font "Menlo,15"
set grid lt 0 lw 1
plot "integration.txt" index 0 using 1:3 ti "Newton-Cotes" lt 3 lw 2,\
'integration.txt' index 1 using 1:3 ti "Trapazoid Rule" lt 7 lw 2, 'integration.txt' index 2 using 1:3 ti "Simpsons Rule" lt 8 lw 2

set terminal qt 1
set terminal jpeg
set output "area.jpeg"
set size square
set style data linespoints 
set ytics 0.1 font "Menlo,15"
set xtics 0.1 font "Menlo,15"
set xlabel "Step Size" offset 0,-1 font "Menlo,20"
set ylabel "Area" offset -1,0 font "Menlo,20"
set xrange [0:1]
set yrange[0.4:1]
set key font "Menlo,15"
set grid lt 0 lw 1
plot "integration.txt" index 0 using 1:2 ti "Newton-Cotes" lt 3 lw 2,\
'integration.txt' index 1 using 1:2 ti "Trapazoid Rule" lt 7 lw 2, 'integration.txt' index 2 using 1:2 ti "Simpsons Rule" lt 8 lw 2