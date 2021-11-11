#Large Jupiter System
set terminal jpeg
set output "Radii.jpeg"
set style data linespoint
stats "Radii.txt"
set xlabel offset 0,-1 "t(weeks)" font "Menlo,15"
set ylabel offset -1,0 "R(AU)" font "Menlo,15"
set yrange [0:4]
set xrange[0:2100]
set xtics 300 font "Menlo,15"
set ytics 0.5 font "Menlo,15"
set grid lt 0 lw 1
set key font "Menlo,15"
set key spacing 1.25
set title "Center of Mass Radii" font "Menlo,20"
plot 'Radii.txt' using 1:2 ti "Sun (Ms)" lt 7 lc rgb "black",\
'Radii.txt' using 1:3 ti "Large Jupiter (1000 x Mj)" lt 7 lc rgb "purple",\
'Radii.txt' using 1:4 ti "Earth (Me)" lt 7 lc rgb "red"

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
set xtics 5 font "Menlo,15"
set ytics 5 font "Menlo,15"
set ztics 5 font "Menlo,15" 
set grid lt 0 lw 1
set key font "Menlo,15"
set key spacing 2
set title "Large Jupiter System" font "Menlo,20"
splot 'Orbit.txt' using 7:8:9 ti "Planet (Me)" lt 0 lw 2 lc rgb "red",\
'Orbit.txt' using 1:2:3 ti "Sun (Ms)" lt 7 lc rgb "black",\
'Orbit.txt' using 4:5:6 ti "Large Jupiter (1000 x Mj)" lt 7 lc rgb "purple"

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
stats "Sun.txt"
set key font "Menlo,15"
set key spacing 2
set grid lt 0 lw 1
set title "Large Jupiter System" font "Menlo,20"
do for [i=0:STATS_blocks]{
splot 'Sun.txt' index i ti "Sun (Ms)" lt 7 lw 6 lc rgb "black",\
'Jupiter.txt' index i ti "Large Jupiter (1000 x Mj)\n" lt 7 lw 3 lc rgb "purple",\
'Earth.txt' index i ti "Earth (Me)\n" lt 7 lw 1 lc rgb "red"}