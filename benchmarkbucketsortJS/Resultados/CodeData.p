set datafile separator ","
set title "Bucketsort"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo (ms)"
set xrange [0:500000]
set yrange [0:500]
set grid

set term png size 1350,950

set output "ResultadosBucketsort.png"
plot "ResultadosBucketsort.csv" using 1:2 with lp lw 3.0 lc 7 title "Média dos tempos de execução", \
    