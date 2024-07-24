set datafile separator ","
set title "Bucketsort c#"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo"
set xrange [0:50000]
set yrange [0:50000]
set grid

set term png 

set term png size 1350, 950

set output "/home/joaquim/Documents/bucketsortc#/testec#vscode/Benchmarkbucketsort/BenchmarkDotNet.Artifacts/results/GraficosMediasBucketsort.png"
plot "BucketsortBenchmark-report.csv" using 1:45 with lp lw 3.0 lc 7 title "Tempo de execução"

     
     
     
     
     
