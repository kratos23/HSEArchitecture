#include <stdexcept>
#include "MatrixLowTriangle.h"

MatrixLowTriangle::MatrixLowTriangle(int _size) : Matrix(_size) {
    data = new double[getArraySize()];
}

MatrixLowTriangle::MatrixLowTriangle(const MatrixLowTriangle &other) : Matrix(other.size) {
    data = new double[getArraySize()];
}

MatrixLowTriangle &MatrixLowTriangle::operator=(const MatrixLowTriangle &other) {
    if (size != other.size) {
        delete data;
        data = new double[other.getArraySize()];
    }
    size = other.size;
    for (int i = 0; i < getArraySize(); i++) {
        data[i] = other.data[i];
    }
    return *this;
}

MatrixLowTriangle::~MatrixLowTriangle() {
    delete data;
    data = nullptr;
}

double MatrixLowTriangle::get(int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw std::out_of_range("Matrix out of range");
    } else if (j <= i) {
        return data[getCellIndex(i, j)];
    } else {
        return 0;
    }
}

void MatrixLowTriangle::put(int i, int j, double value) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw std::out_of_range("Matrix out of range");
    } else if (j <= i) {
        data[getCellIndex(i, j)] = value;
    } else {
        throw std::invalid_argument("Can't set value above main diagonal");
    }
}


int MatrixLowTriangle::getArraySize() const{
    return (size * (size + 1)) / 2;
}

int MatrixLowTriangle::getCellIndex(int i, int j) {
    int passed = (i * (i + 1)) / 2;
    return passed + j;
}