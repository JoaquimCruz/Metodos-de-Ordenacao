```

BenchmarkDotNet v0.13.12, Windows 11 (10.0.22631.3880/23H2/2023Update/SunValley3)
11th Gen Intel Core i7-11390H 3.40GHz, 1 CPU, 8 logical and 4 physical cores
.NET SDK 8.0.303
  [Host]     : .NET 8.0.7 (8.0.724.31311), X64 RyuJIT AVX-512F+CD+BW+DQ+VL+VBMI
  Job-STNOZO : .NET 8.0.7 (8.0.724.31311), X64 RyuJIT AVX-512F+CD+BW+DQ+VL+VBMI

IterationCount=25  WarmupCount=3  

```
| Method         | Mean         | Error        | StdDev       | Gen0      | Gen1      | Gen2     | Allocated   |
|--------------- |-------------:|-------------:|-------------:|----------:|----------:|---------:|------------:|
| BucketSort1k   |     18.75 μs |     0.943 μs |     1.226 μs |   11.0474 |    2.4414 |        - |    67.75 KB |
| BucketSort10k  |    481.30 μs |    25.587 μs |    32.360 μs |  110.3516 |   89.8438 |        - |   678.38 KB |
| BucketSort100k | 20,361.38 μs |   691.249 μs |   898.819 μs | 1187.5000 |  781.2500 | 281.2500 |  6784.84 KB |
| BucketSort500k | 99,721.78 μs | 1,963.520 μs | 2,621.243 μs | 4400.0000 | 2600.0000 | 800.0000 | 29002.64 KB |
