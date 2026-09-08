#pragma once
#include "matrix.hpp"
#include <immintrin.h>

namespace SIMDMatrix {

/// Tiled General Matrix Multiply (GEMM): C = A * B
template <typename T = float>
inline Matrix<T> matmul_tiled(const Matrix<T>& A, const Matrix<T>& B, size_t tile_size = 32) {
    if (A.cols != B.rows) {
        throw std::invalid_argument("Inner matrix dimensions must match");
    }

    Matrix<T> C(A.rows, B.cols, T(0));
    size_t M = A.rows;
    size_t K = A.cols;
    size_t N = B.cols;

    // Cache-blocking 3D loop for L1/L2 data locality
    for (size_t ii = 0; ii < M; ii += tile_size) {
        size_t i_max = std::min(ii + tile_size, M);
        for (size_t kk = 0; kk < K; kk += tile_size) {
            size_t k_max = std::min(kk + tile_size, K);
            for (size_t jj = 0; jj < N; jj += tile_size) {
                size_t j_max = std::min(jj + tile_size, N);

                for (size_t i = ii; i < i_max; ++i) {
                    for (size_t k = kk; k < k_max; ++k) {
                        T r = A(i, k);
                        #pragma omp simd
                        for (size_t j = jj; j < j_max; ++j) {
                            C(i, j) += r * B(k, j);
                        }
                    }
                }
            }
        }
    }
    return C;
}

} // namespace SIMDMatrix
