#ifndef INC_MATRIXDIAGONAL_H
#define INC_MATRIXDIAGONAL_H

#include "Matrix.h"

class MatrixDiagonal: public Matrix {
private:
    double *data;

public:
    explicit MatrixDiagonal(int size);

    MatrixDiagonal(const MatrixDiagonal &other);

    MatrixDiagonal &operator=(const MatrixDiagonal &other);

    virtual ~MatrixDiagonal();

    double get(int i, int j) override;

    void put(int i, int j, double value) override;

};

#endif //INC_MATRIXDIAGONAL_H
