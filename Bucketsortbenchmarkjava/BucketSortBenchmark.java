import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Random;

public class BucketSortBenchmark {

    public static void main(String[] args) throws IOException {
        // Tamanhos dos vetores
        int[] sizes = {1000, 10000, 100000, 500000};

        // Fixar a semente do gerador de números aleatórios
        Random random = new Random(123); // Número arbitrário para a semente

        // Abrir arquivo para escrita com Locale que usa ponto como separador decimal
        FileWriter csvWriter = new FileWriter("Resultados/ResultadoBucketSort.csv");
        csvWriter.append("# Tamanho do Vetor,Tempo de Execução Médio (ms)\n");

        // Loop para cada tamanho de vetor
        for (int size : sizes) {
            double totalTime = 0;

            // Executar 10 vezes para o mesmo tamanho de vetor
            for (int run = 1; run <= 10; run++) {
                float[] array = generateRandomArray(random, size);

                // Medir o tempo de execução do Bucket Sort
                long startTime = System.nanoTime();
                bucketSort(array);
                long endTime = System.nanoTime();

                // Converter para milissegundos e calcular tempo total
                double durationMs = (endTime - startTime) / 1e6;
                totalTime += durationMs;
            }

            // Calcular média do tempo de execução
            double averageTime = totalTime / 25;

            // Imprimir no console (opcional)
            System.out.println("Tamanho " + size + ": Média de tempo de execução = " + averageTime + " ms");

            // Escrever no arquivo CSV com formatação de ponto flutuante usando ponto como separador decimal
            csvWriter.append(size + "," + String.format(Locale.US, "%.2f", averageTime) + "\n");
        }

        // Fechar arquivo CSV
        csvWriter.flush();
        csvWriter.close();

        System.out.println("Médias das 25 execuções salvas em ResultadoBucketSort.csv");
    }

    // Função para gerar um array de floats aleatórios de tamanho especificado com a semente fixada
    private static float[] generateRandomArray(Random random, int size) {
        float[] array = new float[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextFloat() * 100000; // Números aleatórios de 0 a 100000
        }
        return array;
    }

    // Implementação corrigida do Bucket Sort
    public static void bucketSort(float[] arr) {
        int n = arr.length;

        // 1) Create n empty buckets
        List<List<Float>> buckets = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            buckets.add(new ArrayList<>());
        }

        // 2) Put array elements in different buckets
        for (int i = 0; i < n; i++) {
            int bi = (int) (n * arr[i] / 100000); // Calcula o índice do balde corretamente
            buckets.get(bi).add(arr[i]);
        }

        // 3) Sort individual buckets using insertion sort
        for (int i = 0; i < n; i++) {
            insertionSort(buckets.get(i));
        }

        // 4) Concatenate all buckets into arr[]
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets.get(i).size(); j++) {
                arr[index++] = buckets.get(i).get(j);
            }
        }
    }

    // Insertion sort function to sort individual buckets
    public static void insertionSort(List<Float> bucket) {
        for (int i = 1; i < bucket.size(); ++i) {
            float key = bucket.get(i);
            int j = i - 1;
            while (j >= 0 && bucket.get(j) > key) {
                bucket.set(j + 1, bucket.get(j));
                j--;
            }
            bucket.set(j + 1, key);
        }
    }
}
