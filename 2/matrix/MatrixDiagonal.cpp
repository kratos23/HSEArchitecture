#include <stdexcept>
#include "MatrixDiagonal.h"

MatrixDiagonal::MatrixDiagonal(int size) : Matrix(size) {
    data = new double[size];
}

MatrixDiagonal::MatrixDiagonal(const MatrixDiagonal &other) : Matrix(other.size) {
    data = new double[other.size];
    for (int i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
}

MatrixDiagonal::~MatrixDiagonal() {
    delete data;
    data = nullptr;
}

MatrixDiagonal &MatrixDiagonal::operator=(const MatrixDiagonal &other) {
    if (other.size != size) {
        delete data;
        size = other.size;
        data = new double[size];
    }
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

double MatrixDiagonal::get(int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw std::out_of_range("Matrix out of range");
    } else if (i == j) {
        return data[i];
    } else {
        return 0;
    }
}

void MatrixDiagonal::put(int i, int j, double value) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw std::out_of_range("Matrix out of range");
    } else if (i != j) {
        throw std::invalid_argument("Can't put value on non diagonal");
    } else {
        data[i] = value;
    }
}
