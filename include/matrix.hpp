#pragma once
#include <vector>
#include <cstddef>

class Matrix {
public:
    size_t rows, cols;
    std::vector<float> data;
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r * c, 0.0f) {}
    float& operator()(size_t i, size_t j) { return data[i * cols + j]; }
    const float& operator()(size_t i, size_t j) const { return data[i * cols + j]; }
};
