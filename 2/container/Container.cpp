#include <algorithm>
#include "Container.h"

void Container::add(Matrix *matrix) {
    data[size++] = matrix;
}

Matrix *Container::get(int ind) {
    return data[ind];
}

void Container::set(int ind, Matrix *matrix) {
    data[ind] = matrix;
}

int Container::getSize() {
    return size;
}

void Container::sort() {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (getAverage(data[i]) > getAverage(data[j])) {
                std::swap(data[i], data[j]);
            }
        }
    }
}

double Container::getAverage(Matrix *matrix) {
    double sum = 0;
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            sum += matrix->get(i, j);
        }
    }
    double sizeDouble = (double) matrix->size;
    return sum / (sizeDouble * sizeDouble);
}
