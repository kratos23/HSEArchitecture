#include <random>
#include "MatrixDiagonalGenerator.h"
#include "../matrix/MatrixDiagonal.h"

MatrixDiagonalGenerator::MatrixDiagonalGenerator(std::mt19937 &_randomGenerator) : randomGenerator(_randomGenerator) {}

Matrix *MatrixDiagonalGenerator::generate(int size) {
    MatrixDiagonal *matrixDiagonal = new MatrixDiagonal(size);
    std::uniform_real_distribution<double> distrib(-MAX_ABSOLUTE_MATRIX_VALUE, MAX_ABSOLUTE_MATRIX_VALUE);
    for (int i = 0; i < size; i++) {
        matrixDiagonal->put(i, i, distrib(randomGenerator));
    }
    return matrixDiagonal;
}
