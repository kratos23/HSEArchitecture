#ifndef INC_2_MATRIXGENERATOR_H
#define INC_2_MATRIXGENERATOR_H

#include "../matrix/Matrix.h"

const double MAX_ABSOLUTE_MATRIX_VALUE = 1e9;

class MatrixGenerator {
public:
    virtual Matrix *generate(int size) = 0;
};

#endif //INC_2_MATRIXGENERATOR_H
