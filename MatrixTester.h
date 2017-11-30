//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXTESTER_H
#define MATRIXOPERATIONS_MATRIXTESTER_H
#include "Matrix.h"

using namespace std;


class MatrixTester {
public:
    MatrixTester();
    void testDoubleMatrix();
    void testTripleMatrix();
    void testGetDeterminant();
    void testGetXYZ();
    void testGetVariable();
    void testGetDotProduct();
    void testScaleBy();
};


#endif //MATRIXOPERATIONS_MATRIXTESTER_H
