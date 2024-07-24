set datafile separator ","
set title "Bucket sort"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo (ms)"
set xrange [0:500000]
set yrange [0:3]
set grid

set term png size 1350, 950

set output "/home/joaquim/Documents/bucketsortbenchmarkC++/Resultados/Graficos/MediasBucketsort.png"
plot "Resultados.csv" using 1:2 with lp lw 3.0 lc 7 title "Tempo", \
     "Resultados.csv" using 3:4 with lines lw 3.0 title "Tempo CPU", \
