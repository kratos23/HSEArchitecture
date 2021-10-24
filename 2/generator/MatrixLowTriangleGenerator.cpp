#include "../matrix/MatrixDiagonal.h"
#include "MatrixLowTriangleGenerator.h"
#include "../matrix/MatrixLowTriangle.h"
#include <random>

Matrix *MatrixLowTriangleGenerator::generate(int size) {
    MatrixLowTriangle *matrix = new MatrixLowTriangle(size);
    std::uniform_real_distribution<double> distrib(-MAX_ABSOLUTE_MATRIX_VALUE, MAX_ABSOLUTE_MATRIX_VALUE);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            matrix->put(i, j, distrib(randomGenerator));
        }
    }
    return matrix;
}

MatrixLowTriangleGenerator::MatrixLowTriangleGenerator(std::mt19937 &randomGenerator) : randomGenerator(
        randomGenerator) {}
