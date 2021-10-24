#ifndef INC_2_PRINTER_H
#define INC_2_PRINTER_H

#include <iostream>
#include <vector>
#include "../matrix/Matrix.h"

class Printer {
public:
    void print(Matrix *matrix);
    Printer(std::vector<std::ostream*> _outputStreams);

private:
    std::vector<std::ostream*> outputStreams;
    void printTo(Matrix *matrix, std::ostream *ostream);
};

#endif //INC_2_PRINTER_H
