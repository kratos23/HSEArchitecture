#ifndef INC_2_MATRIXLOWTRIANGLEREADER_H
#define INC_2_MATRIXLOWTRIANGLEREADER_H

#include "MatrixReader.h"
#include <fstream>

class MatrixLowTriangleReader: public MatrixReader {
    Matrix *read(std::ifstream &is) override;
};


#endif //INC_2_MATRIXLOWTRIANGLEREADER_H
