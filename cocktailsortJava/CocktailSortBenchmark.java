import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class CocktailSortBenchmark {

    public static void main(String[] args) throws IOException {
        // Tamanhos dos vetores
        int[] sizes = {1000, 10000, 100000, 500000};

        // Abrir arquivo para escrita
        FileWriter csvWriter = new FileWriter("Resultados/ResultadoCocktailsort.csv");
        csvWriter.append("Tamanho do Vetor,Tempo de Execução Médio (ms)\n");

        // Loop para cada tamanho de vetor
        for (int size : sizes) {
            long totalTime = 0;

            // Executar 10 vezes para o mesmo tamanho de vetor
            for (int run = 1; run <= 25; run++) {
                int[] array = generateRandomArray(size);

                // Medir o tempo de execução do Cocktail Sort
                long startTime = System.nanoTime();
                new CocktailSort().cocktailSort(array);
                long endTime = System.nanoTime();

                // Converter para milissegundos e calcular tempo total
                long durationMs = (endTime - startTime) / 1000000;
                totalTime += durationMs;
            }

            // Calcular média do tempo de execução
            long averageTime = totalTime / 25;

            // Imprimir no console (opcional)
            System.out.println("Tamanho " + size + ": Média de tempo de execução = " + averageTime + " ms");

            // Escrever no arquivo CSV
            csvWriter.append(size + "," + averageTime + "\n");
        }

        // Fechar arquivo CSV
        csvWriter.flush();
        csvWriter.close();

        System.out.println("Médias das 25 execuções salvas em ResultadoCocktailsort.csv");
    }

    // Função para gerar um array de inteiros aleatórios de tamanho especificado
    private static int[] generateRandomArray(int size) {
        Random random = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(100001); // Números aleatórios de 0 a 100000
        }
        return array;
    }

    // Classe CocktailSort conforme fornecida
    static class CocktailSort {
        void cocktailSort(int a[]) {
            boolean swapped = true;
            int start = 0;
            int end = a.length;

            while (swapped) {
                swapped = false;
                for (int i = start; i < end - 1; ++i) {
                    if (a[i] > a[i + 1]) {
                        int temp = a[i];
                        a[i] = a[i + 1];
                        a[i + 1] = temp;
                        swapped = true;
                    }
                }
                if (!swapped) break;
                swapped = false;
                end--;
                for (int i = end - 1; i >= start; i--) {
                    if (a[i] > a[i + 1]) {
                        int temp = a[i];
                        a[i] = a[i + 1];
                        a[i + 1] = temp;
                        swapped = true;
                    }
                }
                start++;
            }
        }
    }
}
