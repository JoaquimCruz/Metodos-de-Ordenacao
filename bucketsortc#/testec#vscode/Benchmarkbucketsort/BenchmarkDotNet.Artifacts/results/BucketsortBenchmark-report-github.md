```

BenchmarkDotNet v0.13.12, Windows 11 (10.0.22631.3880/23H2/2023Update/SunValley3)
11th Gen Intel Core i7-11390H 3.40GHz, 1 CPU, 8 logical and 4 physical cores
.NET SDK 8.0.303
  [Host]     : .NET 8.0.7 (8.0.724.31311), X64 RyuJIT AVX-512F+CD+BW+DQ+VL+VBMI
  Job-TJQWES : .NET 8.0.7 (8.0.724.31311), X64 RyuJIT AVX-512F+CD+BW+DQ+VL+VBMI

IterationCount=100  WarmupCount=3  

```
| Method         | Mean         | Error        | StdDev       | Gen0      | Gen1      | Gen2     | Allocated   |
|--------------- |-------------:|-------------:|-------------:|----------:|----------:|---------:|------------:|
| BucketSort1k   |     17.52 μs |     0.361 μs |     1.024 μs |   10.9253 |    2.1667 |        - |    66.99 KB |
| BucketSort10k  |    416.17 μs |    10.695 μs |    29.814 μs |  110.3516 |   92.2852 |        - |   678.91 KB |
| BucketSort100k | 19,089.70 μs |   287.307 μs |   805.640 μs | 1187.5000 |  781.2500 | 281.2500 |  6789.83 KB |
| BucketSort500k | 95,738.30 μs | 1,031.374 μs | 2,942.567 μs | 4500.0000 | 2666.6667 | 833.3333 | 29010.42 KB |
