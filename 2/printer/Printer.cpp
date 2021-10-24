//
// Created by user on 24.10.2021.
//

#include "Printer.h"

#include <utility>

Printer::Printer(std::vector<std::ostream *> _outputStreams) : outputStreams(std::move(_outputStreams)) {
}

void Printer::printTo(Matrix *matrix, std::ostream *ostream) {
    *ostream << matrix->size << "\n";
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            *ostream << std::fixed << matrix->get(i, j) << " ";
        }
        *ostream << "\n";
    }
}

void Printer::print(Matrix *matrix) {
    for (auto ostream: outputStreams) {
        printTo(matrix, ostream);
    }
}
