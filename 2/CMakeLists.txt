cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 17)

add_executable(2 main.cpp matrix/Matrix.h matrix/Matrix2D.cpp matrix/Matrix2D.h matrix/MatrixDiagonal.cpp matrix/MatrixDiagonal.h matrix/MatrixLowTriangle.h matrix/MatrixLowTriangle.cpp printer/Printer.cpp printer/Printer.h reader/FileReader.cpp reader/FileReader.h generator/MatrixGenerator.h generator/Matrix2DGenerator.cpp generator/Matrix2DGenerator.h generator/MatrixDiagonalGenerator.cpp generator/MatrixDiagonalGenerator.h generator/MatrixLowTriangleGenerator.cpp generator/MatrixLowTriangleGenerator.h reader/MatrixReader.h reader/Matrix2DReader.cpp reader/Matrix2DReader.h reader/MatrixDiagonalReader.cpp reader/MatrixDiagonalReader.h reader/MatrixLowTriangleReader.cpp reader/MatrixLowTriangleReader.h)
