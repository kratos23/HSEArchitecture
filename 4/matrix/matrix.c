#include "stdlib.h"
#include "matrix.h"

Matrix createMatrix2d(int size) {
    Matrix2D *matrix2d = (Matrix2D *) malloc(sizeof(Matrix2D));
    matrix2d->data = malloc(sizeof(double *) * size);
    for (int i = 0; i < size; i++) {
        matrix2d->data[i] = malloc(sizeof(double) * size);
    }

    Matrix resultMatrix;
    resultMatrix.tag = MATRIX_TAG_2D;
    resultMatrix.matrix2dPtr = matrix2d;
    resultMatrix.size = size;
    return resultMatrix;
}

Matrix createMatrixDiagonal(int size) {
    MatrixDiagonal *matrixDiagonal = (MatrixDiagonal *) malloc(sizeof(MatrixDiagonal));
    matrixDiagonal->data = malloc(sizeof(double) * size);

    Matrix resultMatrix;
    resultMatrix.tag = MATRIX_TAG_DIAGONAL;
    resultMatrix.matrixDiagonalPtr = matrixDiagonal;
    resultMatrix.size = size;
    return resultMatrix;
}

Matrix createMatrixLowTriangle(int size) {
    MatrixLowTriangle *matrixLowTriangle = (MatrixLowTriangle *) malloc(sizeof(MatrixLowTriangle));
    matrixLowTriangle->data = malloc(sizeof(double) * (size * (size + 1) / 2));

    Matrix resultMatrix;
    resultMatrix.tag = MATRIX_TAG_LOW_TRIANGLE;
    resultMatrix.matrixLowTrianglePtr = matrixLowTriangle;
    resultMatrix.size = size;
    return resultMatrix;
}


void freeMatrix(Matrix matrix) {
    switch (matrix.tag) {
        case MATRIX_TAG_2D: {
            Matrix2D *matrix2d = matrix.matrix2dPtr;
            for (int i = 0; i < matrix.size; i++) {
                free(matrix2d->data[i]);
            }
            free(matrix2d);
            break;
        }
        case MATRIX_TAG_DIAGONAL: {
            MatrixDiagonal *matrixDiagonal = matrix.matrixDiagonalPtr;
            free(matrixDiagonal->data);
            break;
        }
        case MATRIX_TAG_LOW_TRIANGLE: {
            MatrixLowTriangle *matrixLowTriangle = matrix.matrixLowTrianglePtr;
            free(matrixLowTriangle->data);
            break;
        }
    }
}

double getMatrixValue(Matrix matrix, int i, int j) {
    switch (matrix.tag) {
        case MATRIX_TAG_2D: {
            Matrix2D *matrix2d = matrix.matrix2dPtr;
            return matrix2d->data[i][j];
        }
        case MATRIX_TAG_DIAGONAL: {
            MatrixDiagonal *matrixDiagonal = matrix.matrixDiagonalPtr;
            if (i == j) {
                return matrixDiagonal->data[i];
            } else {
                return 0.0;
            }
        }
        case MATRIX_TAG_LOW_TRIANGLE: {
            MatrixLowTriangle *matrixLowTriangle = matrix.matrixLowTrianglePtr;
            if (j <= i) {
                int passed = (i * (i + 1)) / 2;
                return matrixLowTriangle->data[passed + j];
            } else {
                return 0.0;
            }
        }
    }
}

void setMatrixValue(Matrix matrix, int i, int j, double value) {
    switch (matrix.tag) {
        case MATRIX_TAG_2D: {
            Matrix2D *matrix2d = matrix.matrix2dPtr;
            matrix2d->data[i][j] = value;
            break;
        }
        case MATRIX_TAG_DIAGONAL: {
            MatrixDiagonal *matrixDiagonal = matrix.matrixDiagonalPtr;
            if (i == j) {
                matrixDiagonal->data[i] = value;
            }
            break;
        }
        case MATRIX_TAG_LOW_TRIANGLE: {
            MatrixLowTriangle *matrixLowTriangle = matrix.matrixLowTrianglePtr;
            if (j <= i) {
                int passed = (i * (i + 1)) / 2;
                matrixLowTriangle->data[passed + j] = value;
            }
            break;
        }
    }
}
