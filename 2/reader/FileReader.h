#ifndef INC_2_FILEREADER_H
#define INC_2_FILEREADER_H

#include <string>
#include <random>
#include <map>
#include "../matrix/Matrix.h"
#include "../generator/MatrixGenerator.h"
#include "MatrixReader.h"

class FileReaderCallback {
public:
    virtual void handle(Matrix *matrix) = 0;
};

class FileReader {
public:
    explicit FileReader(FileReaderCallback *readerCallback);

    virtual ~FileReader();

    FileReader& operator=(const FileReader &fileReader) = delete;

    void read(std::string fileName);

private:
    static inline const std::string RAW_INPUT_TYPE = "raw";
    static inline const std::string RANDOM_INPUT_TYPE = "random";
    static inline const int MAX_RANDOM_MATRIX_SIZE = 10;

    static inline const std::string DIAGONAL_MATRIX_TYPE = "diagonal";
    static inline const std::string LOW_TRIANGLE_MATRIX_TYPE = "low_triangle";
    static inline const std::string TWO_DIMENSIONS_MATRIX_TYPE = "2d";

    std::map<std::string, MatrixReader*> matrixReaders;

    FileReaderCallback *readerCallback;

    void readRandom(std::ifstream &ifstream);

    void readRaw(std::ifstream &ifstream);
};

#endif //INC_2_FILEREADER_H
