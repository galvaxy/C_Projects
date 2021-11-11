#Binary Star System 1
set terminal jpeg
set output "Radii.jpeg"
set style data linespoint
stats "Radii.txt"
set xlabel offset 0,-1 "t(days)" font "Menlo,15"
set ylabel offset -1,0 "R(AU)" font "Menlo,15"
set yrange [0:15]
set xrange[0:4400]
set xtics 1000 font "Menlo,15"
set ytics 2 font "Menlo,15"
set grid lt 0 lw 1
set key font "Menlo,15"
set key spacing 1.25
set title "Center of Mass Radii" font "Menlo,20"
plot 'Radii.txt' using 1:2 ti "Star1 (5x Ms)" lt 7 lc rgb "black",\
'Radii.txt' using 1:3 ti "Star2 (1x Ms)" lt 7 lc rgb "purple",\
'Radii.txt' using 1:4 ti "Planet (2x Me)" lt 7 lc rgb "red"

set terminal jpeg
set output "Orbits.jpeg"
set style data linespoint
set size square
set xlabel offset 0,-1,0 "x(AU)" font "Menlo,15"
set ylabel offset 4,0,0"y(AU)" font "Menlo,15"
set zlabel offset -2,-2,0 "z(AU)" font "Menlo,15"
set xrange [-11:11]
set yrange [-11:11]
set zrange [-10:10]
set xtics font "Menlo,15"
set ytics font "Menlo,15"
set ztics font "Menlo,15" 
set grid lt 0 lw 1
set key font "Menlo,15"
set key spacing 2
set title "System 1 Orbits" font "Menlo,20"
splot 'Orbit.txt' using 7:8:9 ti "Planet (2x Me)" lt 0 lw 2 lc rgb "red",\
'Orbit.txt' using 1:2:3 ti "Star1 (5x Ms)" lt 7 lc rgb "black",\
'Orbit.txt' using 4:5:6 ti "Star2 (1x Ms)" lt 7 lc rgb "purple"

set terminal gif animate delay 1
set output "Orbits.gif"
set size square
set xrange [-11:11]
set yrange [-11:11]
set zrange [-10:10]
set xlabel offset 0,-1,0 "x(AU)" font "Menlo,15"
set ylabel offset 4,0,0 "y(AU)" font "Menlo,15"
set zlabel offset -2,-2,0 "z(AU)" font "Menlo,15"
set xtics 5 font "Menlo,15"
set ytics 5 font "Menlo,15"
set ztics 5 font "Menlo,15"
stats "Star1.txt"
set key font "Menlo,15"
set key spacing 2
set grid lt 0 lw 1
set title "Binary Star Planetary System 1" font "Menlo,20"
do for [i=0:STATS_blocks]{
splot 'Star1.txt' index i ti "Star1 (5 x Ms)" lt 7 lw 6 lc rgb "black",\
'Star2.txt' index i ti "Star2 (1 x Ms)\n" lt 7 lw 3 lc rgb "purple",\
'Planet.txt' index i ti "Planet (2 x Me)\n" lt 7 lw 1 lc rgb "red"}