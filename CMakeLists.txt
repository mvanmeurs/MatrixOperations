cmake_minimum_required(VERSION 3.8)
project(MatrixOperations)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES main.cpp Matrix.h Vec.h MatrixCalculator.cpp MatrixCalculator.h MatrixOperationTester.cpp MatrixOperationTester.h MatrixDimensionException.h TypeDefException.h VariableException.h MatrixTester.cpp Matrix.h VecTester.cpp VecTester.h MatrixTest1.txt MatrixTest1Copy.txt MatrixTest1Copy2.txt vecStreamOut.txt vecTest1.txt vecTest2Copy.txt vecTest1Copy.txt vecTest2.txt vecTest2Copy.txt)
add_executable(MatrixOperations ${SOURCE_FILES})