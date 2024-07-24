# Adiciona os arquivos de código-fonte
add_executable(benchmark_example main.cpp)

# Encontra e adiciona a biblioteca Google Benchmark
find_package(benchmark REQUIRED)

# Linka a biblioteca Google Benchmark com o executável
target_link_libraries(benchmark_example benchmark::benchmark)
