const Benchmark = require('benchmark');
const fs = require('fs');

// Função de ordenação por inserção
function insertionSort(bucket) {
    for (let i = 1; i < bucket.length; ++i) {
        let key = bucket[i];
        let j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Função de ordenação por balde (bucket sort)
function bucketSort(arr) {
    let n = arr.length;
    let buckets = Array.from({length: n}, () => []);

    // Distribui os elementos do array nos baldes
    for (let i = 0; i < n; i++) {
        let bi = Math.floor(n * arr[i]);
        buckets[bi].push(arr[i]);
    }

    // Ordena os baldes individualmente usando ordenação por inserção
    for (let i = 0; i < n; i++) {
        insertionSort(buckets[i]);
    }

    // Concatena todos os baldes de volta no array original
    let index = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < buckets[i].length; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Função para gerar um array de valores aleatórios entre 0 e 1
function generateRandomArray(size) {
    return Array.from({length: size}, () => Math.random());
}

// Função para calcular a média de um array de números
function calculateAverage(times) {
    const total = times.reduce((acc, curr) => acc + curr, 0);
    return total / times.length;
}

// Tamanhos dos vetores
const sizes = [1000, 10000, 100000, 500000];

// Número de repetições para o benchmark
const repetitions = 50;

const csvFile = '../benchmarkbucketsortJS/Resultados/Resultadosbucketsort.csv'
fs.writeFileSync(csvFile, '#Tamanho do Vetor,Tempo de Execução (ms)\n');


sizes.forEach(size => {
    const arr = generateRandomArray(size);
    const times = [];

    for (let i = 0; i < repetitions; i++) {
        const suite = new Benchmark.Suite();

        suite.add(`Bucket Sort com vetor de ${size} elementos`, function() {
            bucketSort([...arr]);
        });

        suite.on('cycle', function(event) {
            times.push(event.target.times.cycle * 1000);
        });

        suite.run();
    }

    const averageTime = calculateAverage(times);
    fs.appendFileSync(csvFile, `${size},${averageTime.toFixed(6)}\n`);
    console.log(`Média do tempo de execução para vetor de ${size} elementos: ${averageTime.toFixed(6)} ms`);
});
