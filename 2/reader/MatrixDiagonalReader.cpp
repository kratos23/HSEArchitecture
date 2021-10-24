#include <fstream>
#include "MatrixDiagonalReader.h"
#include "../matrix/MatrixDiagonal.h"

Matrix *MatrixDiagonalReader::read(std::ifstream &is) {
    int matrixSize;
    is >> matrixSize;
    MatrixDiagonal *matrix = new MatrixDiagonal(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        double value;
        is >> value;
        matrix->put(i, i, value);
    }
    return matrix;
}
