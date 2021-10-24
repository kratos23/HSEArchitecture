#ifndef INC_2_MATRIXLOWTRIANGLE_H
#define INC_2_MATRIXLOWTRIANGLE_H

#include "Matrix.h"

class MatrixLowTriangle : public Matrix {
public:
    explicit MatrixLowTriangle(int _size);

    MatrixLowTriangle(const MatrixLowTriangle &other);

    MatrixLowTriangle &operator=(const MatrixLowTriangle &other);

    ~MatrixLowTriangle() override;

    double get(int i, int j) override;

    void put(int i, int j, double value) override;

private:
    double *data;

    int getArraySize() const;

    int getCellIndex(int i, int j);

};


#endif //INC_2_MATRIXLOWTRIANGLE_H
