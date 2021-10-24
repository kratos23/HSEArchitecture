#include <string>
#include <iostream>
#include "reader/FileReader.h"
#include "printer/Printer.h"
#include "container/Container.h"

class ReaderCallback : public FileReaderCallback {
private:
    Container *container;

public:
    ReaderCallback(Container *container) : container(container) {}

public:

    void handle(Matrix *matrix) override {
        container->add(matrix);
    }
};

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    Container container;
    ReaderCallback readerCallback(&container);

    FileReader fileReader(&readerCallback);
    fileReader.read(inputFile);

    std::ofstream outputStream(outputFile);
    Printer printer = Printer(std::vector<std::ostream*>({&std::cout, &outputStream}));

    for (int i = 0; i < container.getSize(); i++) {
        printer.print(container.get(i));
    }
    printer.printCount(container.getSize());
    container.sort();
    for (int i = 0; i < container.getSize(); i++) {
        printer.print(container.get(i));
    }
    for (int i = 0; i < container.getSize(); i++) {
        delete container.get(i);
        container.set(i, nullptr);
    }
    outputStream.close();
}
