#ifndef INC_2_MATRIX2DGENERATOR_H
#define INC_2_MATRIX2DGENERATOR_H

#include <random>
#include "MatrixGenerator.h"

class Matrix2DGenerator : public MatrixGenerator {
public:
    Matrix *generate(int size) override;

    explicit Matrix2DGenerator(std::mt19937 &randomGenerator);

private:
    std::mt19937 &randomGenerator;
};

#endif //INC_2_MATRIX2DGENERATOR_H
