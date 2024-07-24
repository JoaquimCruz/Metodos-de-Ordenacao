#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos em um array
void swap(int *x, int *y) {
    if (x == y)
        return;
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

// Função CocktailSort para ordenar um array
void cocktailsort(int *a, size_t n) {
    while (1) {
        char flag;
        int it, i;
        int start[2] = {1, n - 1},
               end[2] = {n, 0},
               inc[2] = {1, -1};

        for (it = 0; it < 2; ++it) {
            flag = 1;
            for (i = start[it]; i != end[it]; i += inc[it])
                if (a[i - 1] > a[i]) {
                    swap(a + i - 1, a + i);
                    flag = 0;
                }
            if (flag)
                return;
        }
    }
}

void generateRandomArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % 1000000; // Gera números aleatórios até 1.000.000
  }
}

void copyArray(int source[], int dest[], int size) {
  for (int i = 0; i < size; ++i) {
    dest[i] = source[i];
  }
}

int main() {
  int sizes[] = {1000, 10000, 100000, 500000};
  int numSizes = sizeof(sizes) / sizeof(sizes[0]);
  FILE *file = fopen("Resultados/cocktailsort.csv", "w");
  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Escreve o cabeçalho do arquivo CSV
  fprintf(file, "# Tamanho do Vetor,Tempo de Execução (ms)\n");

  srand(time(0));

  for (int i = 0; i < numSizes; ++i) {
    int size = sizes[i];
    int *originalArray = (int *)malloc(size * sizeof(int));
    int *array = (int *)malloc(size * sizeof(int));
    generateRandomArray(originalArray, size);

    double total_time = 0.0;

    for (int j = 0; j < 50; ++j) {
      copyArray(originalArray, array, size);
      clock_t start = clock();
      cocktailsort(array, size);
      clock_t end = clock();
      total_time += ((double)(end - start)*1000) / CLOCKS_PER_SEC;
    }

    double average_time = total_time / 50;
    fprintf(file, "%d,%f\n", size, average_time);

    free(originalArray);
    free(array);
  }

  fclose(file);
  printf("Benchmark concluído. Resultados salvos em 'cocktailsort.csv'.\n");

  return 0;
}
