```

BenchmarkDotNet v0.13.12, Windows 11 (10.0.22631.3880/23H2/2023Update/SunValley3)
11th Gen Intel Core i7-11390H 3.40GHz, 1 CPU, 8 logical and 4 physical cores
.NET SDK 8.0.303
  [Host]     : .NET 8.0.7 (8.0.724.31311), X64 RyuJIT AVX-512F+CD+BW+DQ+VL+VBMI
  Job-KMYNLB : .NET 8.0.7 (8.0.724.31311), X64 RyuJIT AVX-512F+CD+BW+DQ+VL+VBMI

IterationCount=100  WarmupCount=3  

```
| Method           | Mean             | Error           | StdDev           | Median           | Gen0   | Allocated  |
|----------------- |-----------------:|----------------:|-----------------:|-----------------:|-------:|-----------:|
| cocktailSort1k   |         468.3 μs |         9.06 μs |         25.86 μs |         467.4 μs | 0.4883 |    3.93 KB |
| cocktailSort10k  |      43,542.8 μs |       156.67 μs |        407.21 μs |      43,541.3 μs |      - |   39.13 KB |
| cocktailSort100k |   8,393,485.2 μs |   144,112.70 μs |    424,919.54 μs |   8,681,928.5 μs |      - |  391.04 KB |
| cocktailSort500k | 219,662,701.2 μs | 4,752,453.39 μs | 13,169,025.96 μs | 223,329,091.3 μs |      - | 1953.54 KB |
