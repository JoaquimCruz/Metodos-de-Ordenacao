const Benchmark = require('benchmark');
const fs = require('fs');
const path = require('path');

// Função de ordenação Cocktail Sort
function cocktailSort(a) {
    let swapped = true;
    let start = 0;
    let end = a.length;

    while (swapped) {
        swapped = false;

        // Loop de baixo para cima
        for (let i = start; i < end - 1; ++i) {
            if (a[i] > a[i + 1]) {
                let temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped = true;
            }
        }

        // Se nada foi trocado, o array está ordenado
        if (!swapped) break;

        // Caso contrário, resetamos o flag para ser usado na próxima etapa
        swapped = false;

        // Move o ponto final para trás
        end--;

        // Loop de cima para baixo
        for (let i = end - 1; i >= start; i--) {
            if (a[i] > a[i + 1]) {
                let temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped = true;
            }
        }

        // Aumenta o ponto de partida
        start++;
    }
}

// Função para gerar um array de valores aleatórios entre 0 e 1
function generateRandomArray(size) {
    return Array.from({ length: size }, () => Math.random());
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

// Verifica e cria o diretório, se necessário
const outputDir = path.join(__dirname, '../cocktailsortJS/Resultados');
if (!fs.existsSync(outputDir)) {
    fs.mkdirSync(outputDir, { recursive: true });
}

// Cria o arquivo CSV e escreve o cabeçalho
const csvFile = path.join(outputDir, 'Resultadoscocktailsort.csv');
fs.writeFileSync(csvFile, '#Tamanho do Vetor,Tempo de Execução (ms)\n');

sizes.forEach(size => {
    const arr = generateRandomArray(size);
    const times = [];

    for (let i = 0; i < repetitions; i++) {
        const suite = new Benchmark.Suite();

        suite.add(`Cocktail Sort com vetor de ${size} elementos`, function() {
            cocktailSort([...arr]);
        });

        suite.on('complete', function() {
            times.push(this[0].times.cycle * 1000); // Converte para milissegundos
        });

        suite.run({ async: false });
    }

    const averageTime = calculateAverage(times);
    fs.appendFileSync(csvFile, `${size},${averageTime.toFixed(6)}\n`);
    console.log(`Média do tempo de execução para vetor de ${size} elementos: ${averageTime.toFixed(6)} ms`);
});
