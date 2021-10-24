#ifndef INC_2_MATRIXDIAGONALREADER_H
#define INC_2_MATRIXDIAGONALREADER_H
#include "MatrixReader.h"
#include <fstream>

class MatrixDiagonalReader: public MatrixReader {
    Matrix *read(std::ifstream &is) override;
};

#endif //INC_2_MATRIXDIAGONALREADER_H
