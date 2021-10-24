#include "Matrix2DGenerator.h"
#include "MatrixGenerator.h"
#include "../matrix/Matrix2D.h"
#include <random>

Matrix *Matrix2DGenerator::generate(int size) {
    Matrix2D *matrix = new Matrix2D(size);
    std::uniform_real_distribution<double> distrib(-MAX_ABSOLUTE_MATRIX_VALUE, MAX_ABSOLUTE_MATRIX_VALUE);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix->put(i, j, distrib(randomGenerator));
        }
    }
    return matrix;
}

Matrix2DGenerator::Matrix2DGenerator(std::mt19937 &_randomGenerator) : randomGenerator(_randomGenerator) {}