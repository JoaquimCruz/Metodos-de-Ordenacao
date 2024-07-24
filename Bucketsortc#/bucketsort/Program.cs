using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;
using System;
using System.Collections.Generic;
using System.Linq;

[SimpleJob(warmupCount: 3, iterationCount: 25)]
[MemoryDiagnoser]
public class BenchmarkBucketSort
{
    private int[] array1k;
    private int[] array10k;
    private int[] array100k;
    private int[] array500k;

    [GlobalSetup]
    public void Setup()
    {
        array1k = CreateRandomArray(1000);
        array10k = CreateRandomArray(10000);
        array100k = CreateRandomArray(100000);
        array500k = CreateRandomArray(500000);
    }

    private int[] CreateRandomArray(int size)
    {
        Random r = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = r.Next(0, 100001);
        }
        return array;
    }

    // Insertion sort function to sort individual buckets
    public void InsertionSort(List<int> bucket)
    {
        for (int i = 1; i < bucket.Count; ++i)
        {
            int key = bucket[i];
            int j = i - 1;
            while (j >= 0 && bucket[j] > key)
            {
                bucket[j + 1] = bucket[j];
                j--;
            }
            bucket[j + 1] = key;
        }
    }

    // Function to sort arr[] of size n using bucket sort
    public void BucketSort(int[] arr)
    {
        int n = arr.Length;

        // 1) Create n empty buckets
        List<int>[] buckets = new List<int>[n];
        for (int i = 0; i < n; i++)
        {
            buckets[i] = new List<int>();
        }

        // 2) Put array elements in different buckets
        for (int i = 0; i < n; i++)
        {
            int bi = (int)((float)n * ((float)arr[i] / 100001.0f));
            buckets[bi].Add(arr[i]);
        }

        // 3) Sort individual buckets using insertion sort
        for (int i = 0; i < n; i++)
        {
            InsertionSort(buckets[i]);
        }

        // 4) Concatenate all buckets into arr[]
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < buckets[i].Count; j++)
            {
                arr[index++] = buckets[i][j];
            }
        }
    }

    [Benchmark]
    public void BucketSort1k()
    {
        BucketSort((int[])array1k.Clone());
    }

    [Benchmark]
    public void BucketSort10k()
    {
        BucketSort((int[])array10k.Clone());
    }

    [Benchmark]
    public void BucketSort100k()
    {
        BucketSort((int[])array100k.Clone());
    }

    [Benchmark]
    public void BucketSort500k()
    {
        BucketSort((int[])array500k.Clone());
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        var summary = BenchmarkRunner.Run<BenchmarkBucketSort>();
    }
}
