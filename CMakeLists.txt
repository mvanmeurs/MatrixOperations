cmake_minimum_required(VERSION 3.8)
project(MatrixOperations)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES main.cpp Matrix.h Vec.h Calculator.cpp Calculator.h CalculatorOperationTester.cpp CalculatorOperationTester.h MatrixDimensionException.h TypeDefException.h VariableException.h MatrixTester.cpp Matrix.h VecTester.cpp VecTester.h testfiles/MatrixTest1.txt testfiles/MatrixTest1Copy.txt testfiles/MatrixTest1Copy2.txt testfiles/vecStreamOut.txt testfiles/vecTest1.txt testfiles/vecTest2Copy.txt testfiles/vecTest1Copy.txt testfiles/vecTest2.txt testfiles/vecTest2Copy.txt testfiles Plane.h Point.h PointTester.cpp PointTester.h PointException.h)
add_executable(MatrixOperations ${SOURCE_FILES})