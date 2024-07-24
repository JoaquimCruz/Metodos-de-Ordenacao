#include <benchmark/benchmark.h>
#include "bucketsort.hpp"
#include <vector>
#include <algorithm>

// Função que configura o benchmark para o Cocktail Sort
static void BM_BucketSort(benchmark::State& state) {
    bucketsort aux;
    int n = state.range(0); 
    std::vector<int> v(n);
    std::generate(v.begin(), v.end(), std::rand);

    std::vector<std::vector<int>> backup_vectors(10, v);

    for (auto _ : state) {
        for (int i = 0; i < 10; ++i) {

            std::vector<int> vet = backup_vectors[i];

            aux.BucketSort(vet.data(), vet.size());
            benchmark::ClobberMemory(); // Evita otimizações do compilador
        }
    }
}

BENCHMARK(BM_BucketSort)->Arg(1000)->Arg(10000)->Arg(100000)->Arg(500000)->Iterations(100);

BENCHMARK_MAIN();
