set datafile separator ","
set title "CoktailSort"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo (ms)"
set xrange [0:500000]
set yrange [0:1000000]
set grid


set term png size 1350, 950

set output "/home/joaquim/Documents/meuprojetobenchmark/Resultados/ResultadosCocktailSort.png"
plot "resultados.csv" using 1:2 with lp lw 3.0 lc 7 title "Tempo", \
     "resultados.csv" using 3:4 with lines lw 3.0 title "Tempo CPU", \

