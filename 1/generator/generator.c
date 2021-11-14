#include "generator.h"
#include <stdlib.h>
#include <assert.h>

const double MAX_ABSOLUTE_MATRIX_VALUE = 1e9;
const int MAX_RANDOM_MATRIX_SIZE = 10;

int generateRandomMatrixSize() {
    return rand() % MAX_RANDOM_MATRIX_SIZE;
}

double generateRandomMatrixValue() {
    double value = ((double) rand() / (double) RAND_MAX) * MAX_ABSOLUTE_MATRIX_VALUE;
    return value;
}

Matrix generateRandomMatrix2d() {
    Matrix matrix = createMatrix2d(generateRandomMatrixSize());
    for (int i = 0; i < matrix.size; i++) {
        for (int j = 0; j < matrix.size; j++) {
            setMatrixValue(matrix, i, j, generateRandomMatrixValue());
        }
    }
    return matrix;
}

Matrix generateRandomMatrixDiagonal() {
    Matrix matrix = createMatrixDiagonal(generateRandomMatrixSize());
    for (int i = 0; i < matrix.size; i++) {
        setMatrixValue(matrix, i, i, generateRandomMatrixValue());
    }
    return matrix;
}

Matrix generateRandomMatrixLowTriangle() {
    Matrix matrix = createMatrixLowTriangle(generateRandomMatrixSize());
    for (int i = 0; i < matrix.size; i++) {
        for (int j = 0; j <= matrix.size; j++) {
            setMatrixValue(matrix, i, j, generateRandomMatrixValue());
        }
    }
    return matrix;
}

void generateMatricesTo(int matrixCount, Container *container) {
    static const int MATRIX_TYPES_COUNT = 3;
    for (int i = 0; i < matrixCount; i++) {
        switch (rand() % MATRIX_TYPES_COUNT) {
            case 0:
                add(container, generateRandomMatrix2d());
                break;
            case 1:
                add(container, generateRandomMatrixDiagonal());
                break;
            case 2:
                add(container, generateRandomMatrixLowTriangle());
                break;
            default:
                assert(0);
        }
    }
}

