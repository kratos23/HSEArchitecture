cmake_minimum_required(VERSION 3.20)
project(4 C ASM_NASM)

set(CMAKE_C_STANDARD 11)
set(
        PROJECT_HEADERS
        matrix/matrix.h generator/generator.h container/container.h
        reader/reader.h)
set(
        PROJECT_SOURCES
        main.c generator/generator.c matrix/matrix.c container/container.asm
        reader/reader.c)

set(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp ")
SET(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -no-pie")

add_executable(4 ${PROJECT_SOURCES} ${PROJECT_HEADERS})