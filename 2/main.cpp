#include <string>
#include <iostream>
#include "reader/FileReader.h"
#include "printer/Printer.h"

class ReaderCallback : public FileReaderCallback {
private:
    Printer printer = Printer(std::vector({&std::cout}));

public:

    void handle(Matrix *matrix) override {
        printer.print(matrix);
    }
};

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    ReaderCallback readerCallback;

    FileReader fileReader(&readerCallback);
    fileReader.read(inputFile);
}
