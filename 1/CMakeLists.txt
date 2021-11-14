cmake_minimum_required(VERSION 3.20)
project(1 C)

set(CMAKE_C_STANDARD 11)
set(
        PROJECT_HEADERS
        matrix/matrix.h generator/generator.h container/container.h
        reader/reader.h)
set(
        PROJECT_SOURCES
        main.c generator/generator.c matrix/matrix.c container/container.c
        reader/reader.c)

add_executable(1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
