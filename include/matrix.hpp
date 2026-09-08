#pragma once
#include <vector>
#include <cstddef>
#include <stdexcept>

template <typename T = float>
class Matrix {
public:
    size_t rows;
    size_t cols;
    std::vector<T> data;

    Matrix(size_t r, size_t c, T init = T(0)) : rows(r), cols(c), data(r * c, init) {}

    inline T& operator()(size_t r, size_t c) {
        return data[r * cols + c];
    }

    inline const T& operator()(size_t r, size_t c) const {
        return data[r * cols + c];
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(j, i) = (*this)(i, j);
            }
        }
        return result;
    }
};
