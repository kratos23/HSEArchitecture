#include <fstream>
#include <string>
#include <random>
#include <vector>
#include "FileReader.h"
#include "../generator/Matrix2DGenerator.h"
#include "../generator/MatrixDiagonalGenerator.h"
#include "../generator/MatrixLowTriangleGenerator.h"
#include "MatrixDiagonalReader.h"
#include "MatrixLowTriangleReader.h"
#include "Matrix2DReader.h"

FileReader::FileReader(FileReaderCallback *_readerCallback) : readerCallback(_readerCallback) {
    matrixReaders[DIAGONAL_MATRIX_TYPE] = new MatrixDiagonalReader();
    matrixReaders[LOW_TRIANGLE_MATRIX_TYPE] = new MatrixLowTriangleReader();
    matrixReaders[TWO_DIMENSIONS_MATRIX_TYPE] = new Matrix2DReader();
}

void FileReader::read(std::string fileName) {
    std::ifstream is(fileName);
    std::string inputType;
    is >> inputType;
    if (inputType == FileReader::RAW_INPUT_TYPE) {
        readRaw(is);
    } else if (inputType == FileReader::RANDOM_INPUT_TYPE) {
        readRandom(is);
    }
}

void FileReader::readRandom(std::ifstream &ifstream) {
    int randomKey;
    ifstream >> randomKey;
    std::mt19937 randomGenerator(randomKey);

    std::string unused;
    ifstream >> unused;

    int count;
    ifstream >> count;

    auto generator1 = Matrix2DGenerator(randomGenerator);
    auto generator2 = MatrixDiagonalGenerator(randomGenerator);
    auto generator3 = MatrixLowTriangleGenerator(randomGenerator);
    std::vector<MatrixGenerator *> matrixGenerators = {&generator1, &generator2, &generator3};
    std::uniform_int_distribution<int> distribution(0, (int) matrixGenerators.size() - 1);
    std::uniform_int_distribution<int> matrixSizeDistribution(1, MAX_RANDOM_MATRIX_SIZE);
    for (int i = 0; i < count; i++) {
        MatrixGenerator *matrixGenerator = matrixGenerators[distribution(randomGenerator)];
        readerCallback->handle(matrixGenerator->generate(matrixSizeDistribution(randomGenerator)));
    }
}

void FileReader::readRaw(std::ifstream &ifstream) {
    std::string matrixType;
    while (ifstream >> matrixType) {
        Matrix* matrix = matrixReaders[matrixType]->read(ifstream);
        readerCallback->handle(matrix);
    }
}

FileReader::~FileReader() {
    for (auto &[k, v]: matrixReaders) {
        delete v;
    }
}
