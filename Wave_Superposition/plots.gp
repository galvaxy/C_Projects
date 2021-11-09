set terminal gif animate delay 5
set output "waveSuperposition.gif"
set xrange [0:1]
set yrange [-1:1]
set xlabel "x" font "Menlo,15"
set ylabel "y" font "Menlo,15"
set xtics 0.2 font "Menlo,15"
set ytics 0.2 font "Menlo,15"
set key font "Menlo,15"
set style data linespoint
set grid lt 0 lw 1
stats 'waveSuperposition.txt'
do for [i=0: STATS_blocks]{plot 'waveSuperposition.txt' index i using 1:2 ti "Superposition of Waves" lt 0 lw 2 lc rgb "black"}