#include <stdexcept>
#include "Matrix2D.h"

Matrix2D::Matrix2D(int _size) : Matrix(_size) {
    data = new double *[size];
    for (int i = 0; i < _size; i++) {
        data[i] = new double[size];
    }
}

Matrix2D::Matrix2D(const Matrix2D &other) : Matrix(other.size) {
    data = new double *[other.size];
    for (int i = 0; i < size; i++) {
        data[i] = new double[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix2D::~Matrix2D() {
    if (data != nullptr) {
        for (int i = 0; i < size; i++) {
            delete data[i];
            data[i] = nullptr;
        }
        delete data;
    }
}

void Matrix2D::put(int i, int j, double value) {
    data[i][j] = value;
}

double Matrix2D::get(int i, int j) {
    if (i >= 0 && j >= 0 && i < size; j < size) {
        return data[i][j];
    } else {
        throw std::out_of_range("Matrix out of range");
    }
}

Matrix2D &Matrix2D::operator=(const Matrix2D &other) {
    if (other.size != size) {
        if (data != nullptr) {
            for (int i = 0; i < size; i++) {
                delete data[i];
                data[i] = nullptr;
            }
            delete data;
            data = nullptr;
        }

        size = other.size;
        data = new double *[size];
        for (int i = 0; i < size; i++) {
            data[i] = new double[i];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

