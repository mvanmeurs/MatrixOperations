cmake_minimum_required(VERSION 3.8)
project(MatrixOperations)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES main.cpp Matrix.h Vec.h)
add_executable(MatrixOperations ${SOURCE_FILES})