#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NBUCKET 10  // Número de baldes
#define INTERVAL 10  // Capacidade de cada balde
#define NUM_RUNS 50  // Número de execuções para cada tamanho de vetor

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[], int size);
struct Node *InsertionSort(struct Node *list);
void print(int arr[], int size);
void printBuckets(struct Node *list);
int getBucketIndex(int value);
void generateRandomArray(int arr[], int size);
void copyArray(int source[], int dest[], int size);

void BucketSort(int arr[], int size) {
  int i, j;
  struct Node **buckets;

  // Cria os baldes e aloca memória
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // Inicializa baldes vazios
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  // Preenche os baldes com os respectivos elementos
  for (i = 0; i < size; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Ordena os elementos de cada balde
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  // Coloca os elementos ordenados no array
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  // Libera memória alocada para os baldes
  for (i = 0; i < NBUCKET; ++i) {
    struct Node *node = buckets[i];
    while (node) {
      struct Node *temp = node;
      node = node->next;
      free(temp);
    }
  }
  free(buckets);
}

struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value) {
  return value / INTERVAL;
}

void generateRandomArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % (NBUCKET * INTERVAL);
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
  FILE *file = fopen("../bucketsortC/Resultados/ResultadosBucketSort.csv", "w");
  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return 1;
  }

  srand(time(0));

  for (int i = 0; i < numSizes; ++i) {
    int size = sizes[i];
    int *originalArray = (int *)malloc(size * sizeof(int));
    int *array = (int *)malloc(size * sizeof(int));
    generateRandomArray(originalArray, size);

    double total_time = 0.0;

    for (int j = 0; j < NUM_RUNS; ++j) {
      copyArray(originalArray, array, size);
      clock_t start = clock();
      BucketSort(array, size);
      clock_t end = clock();
      total_time += ((double)(end - start)*1000) / CLOCKS_PER_SEC;
    }

    double average_time = total_time / NUM_RUNS;
    fprintf(file, "%d,%f\n", size, average_time);

    free(originalArray);
    free(array);
  }

  fclose(file);
  printf("Benchmark concluído. Resultados salvos em 'benchmark_results.txt'.\n");

  return 0;
}
