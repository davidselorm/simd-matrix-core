#pragma once
#include "matrix.hpp"
#include <algorithm>

inline Matrix multiply_tiled(const Matrix& A, const Matrix& B, size_t block_size = 64) {
    Matrix C(A.rows, B.cols);
    for (size_t i0 = 0; i0 < A.rows; i0 += block_size) {
        for (size_t j0 = 0; j0 < B.cols; j0 += block_size) {
            for (size_t k0 = 0; k0 < A.cols; k0 += block_size) {
                for (size_t i = i0; i < std::min(i0 + block_size, A.rows); ++i) {
                    for (size_t k = k0; k < std::min(k0 + block_size, A.cols); ++k) {
                        for (size_t j = j0; j < std::min(j0 + block_size, B.cols); ++j) {
                            C(i, j) += A(i, k) * B(k, j);
                        }
                    }
                }
            }
        }
    }
    return C;
}
