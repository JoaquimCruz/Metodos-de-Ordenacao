import random
import time
import csv

def cocktailSort(a):
    n = len(a)
    swapped = True
    start = 0
    end = n-1
    while swapped:
        swapped = False
        for i in range(start, end):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                swapped = True
        if not swapped:
            break
        swapped = False
        end = end-1
        for i in range(end-1, start-1, -1):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                swapped = True
        start = start+1

def generate_random_array(size):
    return [random.randint(0, 1000) for _ in range(size)]

sizes = [1000, 10000, 100000]

# Abrir o arquivo CSV para escrita
with open('Resultados\ResultadosCocktailsort.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    # Escrever o cabeçalho do CSV
    writer.writerow(["# Tamanho do Vetor", "Tempo Medio de Execucao (ms)"])
    
    for size in sizes:
        total_time = 0
        for _ in range(50):
            arr = generate_random_array(size)
            start_time = time.time() 
            cocktailSort(arr)
            end_time = time.time()
            total_time += (end_time - start_time)*1000
        
        average_time = total_time/50
        # Escrever o resultado no CSV
        writer.writerow([size, average_time])
        
        print(f"Tamanho do Vetor: {size}, Tempo Medio: {average_time:.10f} ms")

print("Benchmark concluido. Resultados salvos em 'cocktailsort_results.csv'.")
