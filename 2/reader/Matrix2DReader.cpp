#include "Matrix2DReader.h"
#include "../matrix/Matrix2D.h"
#include <fstream>

Matrix *Matrix2DReader::read(std::ifstream &is) {
    int matrixSize;
    is >> matrixSize;
    Matrix2D *matrix = new Matrix2D(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            double value;
            is >> value;
            matrix->put(i, j, value);
        }
    }
    return matrix;
}
