set datafile separator ","
set title "Bucket sort"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo (ms)"
set xrange [0:500000]
set yrange [0:100]
set grid

set term png size 1350, 950

set output "MediasBucketsort.png"
plot "ResultadoBucketSort.csv" using 1:2 with lp lw 3.0 lc 7 title "Tempo de execução", \