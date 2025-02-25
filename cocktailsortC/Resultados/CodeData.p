set datafile separator ","
set title "Cocktail sort" font "Arial, 20"
set xlabel "Tamanho dos vetores" font "Arial, 20"
set ylabel "Médias de tempo (ms)" font "Arial, 20"
set xrange [0:500000]
set yrange [0:1000000]
set grid

set term png size 1350,950

set output "ResultadosCocktailsort.png"
plot "cocktailsort.csv" using 1:2 with lp lw 3.0 lc 7 title "Média dos tempos de execução", \
    