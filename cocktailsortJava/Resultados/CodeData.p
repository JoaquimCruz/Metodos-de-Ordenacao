set datafile separator ","
set title "Cocktail sort"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo (ms)"
set xrange [0:500000]
set yrange [0:500000]
set grid

set term png size 1350, 950

set output "MediasCocktailsort.png"
plot "ResultadoCocktailsort.csv" using 1:2 with lp lw 3.0 lc 7 title "Tempo de execução", \