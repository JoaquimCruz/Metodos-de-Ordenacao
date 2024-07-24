set datafile separator ","
set title "Cocktail sort" font "Arial, 20"
set xlabel "Tamanho dos vetores" font "Arial, 20"
set ylabel "Médias de tempo (ms)" font "Arial, 20"
set xrange [0:500000]
set yrange [0:500000]
set grid

set term png size 1350, 950

set output "MediasCocktailsort.png"
plot "cocktailsort6.csv" using 1:2 with lp lw 3.0 lc 1 title "Tempo de execução Python", \
     "cocktailsort6.csv" using 1:3 with lp lw 3.0 lc 2 title "Tempo de execução Java", \
     "cocktailsort6.csv" using 1:4 with lp lw 3.0 lc 3 title "Tempo de execução JS", \
     "cocktailsort6.csv" using 1:5 with lp lw 3.0 lc 4 title "Tempo de execução C", \
     "cocktailsort6.csv" using 1:6 with lp lw 3.0 lc 5 title "Tempo de execução C++", \
     "cocktailsort6.csv" using 1:7 with lp lw 3.0 lc 6 title "Tempo de execução C#", \

set output "MediasBucketsort.png"
set title "Bucket sort" font "Arial, 20"
set xrange [0:500000]
set yrange [0:1500]
set grid
plot "bucketsort6.csv" using 1:2 with lp lw 3.0 lc 1 title "Tempo de execução Python", \
     "bucketsort6.csv" using 1:3 with lp lw 3.0 lc 2 title "Tempo de execução Java", \
     "bucketsort6.csv" using 1:4 with lp lw 3.0 lc 3 title "Tempo de execução JS", \
     "bucketsort6.csv" using 1:5 with lp lw 3.0 lc 4 title "Tempo de execução C", \
     "bucketsort6.csv" using 1:6 with lp lw 3.0 lc 5 title "Tempo de execução C++", \
     "bucketsort6.csv" using 1:7 with lp lw 3.0 lc 6 title "Tempo de execução C#", \

     