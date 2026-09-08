# simd-matrix-core

High-throughput matrix linear algebra and cache-tiled GEMM kernel library in modern C++20.

## Features
- **Cache-Blocked GEMM**: Tiled 3-level loop structure maximizing L1/L2 cache locality.
- **SIMD Auto-Vectorization**: Pragmas for AVX2/NEON vector instructions.
- **Zero Heap Fragmentations**: Flat contiguous vector allocations.
