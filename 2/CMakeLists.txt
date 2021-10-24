cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 17)

add_executable(2 main.cpp matrix/Matrix.h matrix/Matrix2D.cpp matrix/Matrix2D.h matrix/MatrixDiagonal.cpp matrix/MatrixDiagonal.h matrix/MatrixLowTriangle.h matrix/MatrixLowTriangle.cpp)
