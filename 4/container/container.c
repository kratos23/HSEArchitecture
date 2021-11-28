#include "container.h"

void add(Container *containerPtr, Matrix matrix) {
    containerPtr->data[containerPtr->size++] = matrix;
}

double getAverage(Matrix matrix) {
    double sum = 0;
    switch (matrix.tag) {
        case MATRIX_TAG_2D:
            for (int i = 0; i < matrix.size; i++) {
                for (int j = 0; j < matrix.size; j++) {
                    sum += getMatrixValue(matrix, i, j);
                }
            }
            break;
        case MATRIX_TAG_DIAGONAL:
            for (int i = 0; i < matrix.size; i++) {
                sum += getMatrixValue(matrix, i, i);
            }
            break;
        case MATRIX_TAG_LOW_TRIANGLE:
            for (int i = 0; i < matrix.size; i++) {
                for (int j = 0; j <= i; j++) {
                    sum += getMatrixValue(matrix, i, j);
                }
            }
            break;
    }
    int elementsCount = matrix.size * matrix.size;
    return sum / ((double) elementsCount);
}

void sort(Container *containerPtr) {
    for (int i = 0; i < containerPtr->size; i++) {
        for (int j = i + 1; j < containerPtr->size; j++) {
            if (getAverage(containerPtr->data[i]) > getAverage(containerPtr->data[j])) {
                Matrix tmp = containerPtr->data[i];
                containerPtr->data[i] = containerPtr->data[j];
                containerPtr->data[j] = tmp;
            }
        }
    }
}