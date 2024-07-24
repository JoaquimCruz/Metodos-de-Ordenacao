using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;

[SimpleJob(warmupCount: 3, iterationCount:100)]
[MemoryDiagnoser]
public class benchmarkcocktailsort
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

    static void cocktailSort(int[] a)
    {
        bool swapped = true;
        int start = 0;
        int end = a.Length;
 
        while (swapped == true) {
 
            
            swapped = false;
 
            for (int i = start; i < end - 1; ++i) {
                if (a[i] > a[i + 1]) {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    swapped = true;
                }
            }
 
            // if nothing moved, then array is sorted.
            if (swapped == false)
                break;
 
            // otherwise, reset the swapped flag so that it
            // can be used in the next stage
            swapped = false;
 
            end = end - 1;
 
            for (int i = end - 1; i >= start; i--) {
                if (a[i] > a[i + 1]) {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    swapped = true;
                }
            }
 
            
            start = start + 1;
        }
    }
 
    [Benchmark]
    public void cocktailSort1k()
    {
        cocktailSort((int[])array1k.Clone());
    }

    [Benchmark]
    public void cocktailSort10k()
    {
        cocktailSort((int[])array10k.Clone());
    }

    [Benchmark]
    public void cocktailSort100k()
    {
        cocktailSort((int[])array100k.Clone());
    }

    [Benchmark]
    public void cocktailSort500k()
    {
        cocktailSort((int[])array500k.Clone());
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        var summary = BenchmarkRunner.Run<benchmarkcocktailsort>();
    }
}
