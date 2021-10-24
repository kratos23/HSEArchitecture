#ifndef INC_2_MATRIX2DREADER_H
#define INC_2_MATRIX2DREADER_H

#include "MatrixReader.h"
#include <fstream>

class Matrix2DReader: public MatrixReader {
    Matrix *read(std::ifstream &is) override;
};

#endif //INC_2_MATRIX2DREADER_H
