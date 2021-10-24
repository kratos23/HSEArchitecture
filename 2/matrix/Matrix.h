#ifndef INC_MATRIX_H
#define INC_MATRIX_H

class Matrix {
public:
    int size;
    explicit Matrix(int _size) : size(_size) {};
    virtual ~Matrix() = default;

    virtual double get(int i, int j) = 0;
    virtual void put(int i, int j, double value) = 0;
};

#endif //INC_MATRIX_H
