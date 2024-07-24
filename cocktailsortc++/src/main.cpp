#include <benchmark/benchmark.h>
#include "cocktailsort.hpp"
#include <vector>
#include <algorithm>

// Função que configura o benchmark para o Cocktail Sort
static void BM_CocktailSort(benchmark::State& state) {
    cocktailsort aux;
    int n = state.range(0); 
    std::vector<int> v(n);
    std::generate(v.begin(), v.end(), std::rand);

    std::vector<std::vector<int>> backup_vectors(10, v);

    for (auto _ : state) {
        for (int i = 0; i < 1; ++i) {

            std::vector<int> v_copy = backup_vectors[i];

            aux.CocktailSort(v_copy.data(), v_copy.size());
            benchmark::ClobberMemory(); // Evita otimizações do compilador
        }
    }
}

// Registra o benchmark com os tamanhos específicos
BENCHMARK(BM_CocktailSort)->Arg(1000)->Arg(10000)->Arg(100000)->Arg(500000)->Iterations(10);

BENCHMARK_MAIN();
