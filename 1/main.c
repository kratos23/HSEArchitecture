#include "matrix/matrix.h"
#include "container/container.h"
#include "reader/reader.h"
#include <stdio.h>
#include <time.h>

void printMatrix(Matrix matrix, FILE *file) {
    printf("%d\n", matrix.size);
    fprintf(file, "%d\n", matrix.size);
    for (int i = 0; i < matrix.size; i++) {
        for (int j = 0; j < matrix.size; j++) {
            printf("%.3lf ", getMatrixValue(matrix, i, j));
            fprintf(file, "%.3lf ", getMatrixValue(matrix, i, j));
        }
        printf("\n");
        fprintf(file, "\n");
    }
}

void printContainer(Container *container, FILE *outputFile) {
    for (int i = 0; i < container->size; i++) {
        printMatrix(container->data[i], outputFile);
    }
}

int main(int argc, char *argv[]) {
    clock_t start, stop;
    start = clock();

    Container container;
    container.size = 0;

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    readTo(inputFileName, &container);
    FILE *outputFile = fopen(outputFileName, "w");

    printContainer(&container, outputFile);
    printf("Count in container: %d\n", container.size);
    fprintf(outputFile, "Count in container: %d\n", container.size);

    sort(&container);
    printContainer(&container, outputFile);

    fclose(outputFile);
    for (int i = 0; i < container.size; i++) {
        freeMatrix(container.data[i]);
    }

    stop = clock();
    float elapsedSeconds = ((float) stop - (float) start) / (float) CLOCKS_PER_SEC;
    printf("Time elapsed %f s", elapsedSeconds);

    return 0;
}
