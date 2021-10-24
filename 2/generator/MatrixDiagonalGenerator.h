#ifndef INC_2_MATRIXDIAGONALGENERATOR_H
#define INC_2_MATRIXDIAGONALGENERATOR_H

#include <random>
#include "MatrixGenerator.h"

class MatrixDiagonalGenerator : public MatrixGenerator {
public:
    Matrix *generate(int size) override;

    explicit MatrixDiagonalGenerator(std::mt19937 &_randomGenerator);

private:
    std::mt19937 &randomGenerator;
};


#endif //INC_2_MATRIXDIAGONALGENERATOR_H
