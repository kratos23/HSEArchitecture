#ifndef INC_1_MATRIX_H
#define INC_1_MATRIX_H

struct Matrix2DTag;
struct MatrixDiagonalTag;
struct MatrixLowTriangleTag;
struct MatrixTag;

typedef struct Matrix2DTag {
    double **data;
} Matrix2D;

typedef struct MatrixDiagonalTag {
    double *data;
} MatrixDiagonal;

typedef struct MatrixLowTriangleTag {
    double *data;
} MatrixLowTriangle;

typedef struct MatrixTag {
    enum {
        MATRIX_TAG_2D,
        MATRIX_TAG_DIAGONAL,
        MATRIX_TAG_LOW_TRIANGLE
    } tag;

    int size;
    union {
        Matrix2D *matrix2dPtr;
        MatrixDiagonal *matrixDiagonalPtr;
        MatrixLowTriangle *matrixLowTrianglePtr;
    };
} Matrix;

Matrix createMatrix2d(int size);

Matrix createMatrixDiagonal(int size);

Matrix createMatrixLowTriangle(int size);

void freeMatrix(Matrix matrix);

double getMatrixValue(Matrix matrix, int i, int j);

void setMatrixValue(Matrix matrix, int i, int j, double value);

#endif //INC_1_MATRIX_H
