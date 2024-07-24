import random
import time
import csv

def bucketSort(arr):
    if len(arr) == 0:
        return arr

    # Encontrar o valor máximo e mínimo para saber o intervalo
    min_val, max_val = min(arr), max(arr)

    # Criar buckets
    bucket_count = len(arr)
    buckets = [[] for _ in range(bucket_count)]

    # Distribuir os elementos nos buckets
    for num in arr:
        index = int((num - min_val) / (max_val - min_val + 1) * bucket_count)
        buckets[index].append(num)

    # Ordenar elementos de cada bucket e concatenar
    sorted_array = []
    for bucket in buckets:
        sorted_array.extend(sorted(bucket))

    return sorted_array

def generate_random_array(size):
    return [random.randint(0, 1000) for _ in range(size)]

sizes = [1000, 10000, 100000, 500000]

# Abrir o arquivo CSV para escrita
with open('Resultados\ResultadosBucketsort.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    # Escrever o cabeçalho do CSV
    writer.writerow(["# Tamanho do Vetor", "Tempo Medio de Execucao (s)"])
    
    for size in sizes:
        total_time = 0
        for _ in range(50):
            arr = generate_random_array(size)
            start_time = time.time() 
            sorted_arr = bucketSort(arr)
            end_time = time.time()
            total_time += (end_time - start_time)*1000
        
        average_time = total_time / 50
        # Escrever o resultado no CSV
        writer.writerow([size, average_time])
        
        print(f"Tamanho do Vetor: {size}, Tempo Medio: {average_time:.10f} ms")

print("Benchmark concluido. Resultados salvos em 'ResultadosBucketsort.csv'.")
