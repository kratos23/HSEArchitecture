#ifndef INC_2_MATRIXLOWTRIANGLEGENERATOR_H
#define INC_2_MATRIXLOWTRIANGLEGENERATOR_H

#include <random>
#include "MatrixGenerator.h"

class MatrixLowTriangleGenerator : public MatrixGenerator {
public:
    MatrixLowTriangleGenerator(std::mt19937 &randomGenerator);

    Matrix *generate(int size) override;
private:
    std::mt19937 &randomGenerator;
};

#endif //INC_2_MATRIXLOWTRIANGLEGENERATOR_H
