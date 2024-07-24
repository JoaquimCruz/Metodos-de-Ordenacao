// bucketsort.hpp
#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP
#include <bits/stdc++.h>

using namespace std;


class bucketsort{

public:

    // Função para encontrar o valor máximo no array
    float getMax(int arr[], int size) {
        float m = arr[0];
        for(int i = 1; i < size; i++) {
            if(arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }

    // Função para ordenar um balde
    void sortBucket(vector<int>& bucket) {
        sort(bucket.begin(), bucket.end());
    }

    // Função de ordenação por bucket
    void BucketSort(int arr[], int size) {
        int bucket = 10;
        vector<int> B[bucket];

        float max = getMax(arr, size);
        float divider = ceil(float(max + 1) / bucket);

        for(int i = 0; i < size; i++) {
            int j = floor(arr[i] / divider);
            B[j].push_back(arr[i]);
        }

        // Criar um vetor de threads
        vector<thread> threads;

        // Ordenar os baldes em paralelo
        for(int i = 0; i < bucket; i++) {
            threads.push_back(thread(sortBucket, ref(B[i])));
        }

        // Esperar todas as threads terminarem
        for(auto& th : threads) {
            th.join();
        }

        int k = 0;
        for(int i = 0; i < bucket; i++) {
            for(int j = 0; j < B[i].size(); j++) {
                arr[k++] = B[i][j];
            }
        }
    }
};

#endif