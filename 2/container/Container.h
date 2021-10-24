#ifndef INC_2_CONTAINER_H
#define INC_2_CONTAINER_H


#include "../matrix/Matrix.h"

class Container {
public:
    void add(Matrix *matrix);

    Matrix *get(int ind);

    void set(int ind, Matrix *matrix);

    int getSize();

    void sort();

private:
    static const int MAX_SIZE = 10005;

    Matrix* data[MAX_SIZE];
    int size = 0;

    double getAverage(Matrix *matrix);
};

#endif //INC_2_CONTAINER_H
