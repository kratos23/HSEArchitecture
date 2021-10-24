#ifndef INC_MATRIX2D_H
#define INC_MATRIX2D_H

#include "Matrix.h"

class Matrix2D : public Matrix {
public:
    explicit Matrix2D(int _size);

    Matrix2D(const Matrix2D &other);

    ~Matrix2D() override;

    Matrix2D &operator=(const Matrix2D &other);

    double get(int i, int j) override;

    void put(int i, int j, double value) override;

private:
    double **data = nullptr;
};

#endif //INC_MATRIX2D_H
