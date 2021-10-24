#include "MatrixLowTriangleReader.h"
#include "MatrixReader.h"
#include "../matrix/MatrixLowTriangle.h"
#include <fstream>

Matrix *MatrixLowTriangleReader::read(std::ifstream &is) {
    int matrixSize;
    is >> matrixSize;
    MatrixLowTriangle *matrix = new MatrixLowTriangle(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j <= i; j++) {
            double value;
            is >> value;
            matrix->put(i, j, value);
        }
    }
    return matrix;
}
