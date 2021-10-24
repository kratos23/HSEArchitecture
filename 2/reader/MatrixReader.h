#ifndef INC_2_MATRIXREADER_H
#define INC_2_MATRIXREADER_H

#include "../matrix/Matrix.h"
#include <fstream>

class MatrixReader {
public:
    virtual Matrix* read(std::ifstream &is) = 0;
};

#endif //INC_2_MATRIXREADER_H
