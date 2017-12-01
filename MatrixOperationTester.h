//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXTESTER_H
#define MATRIXOPERATIONS_MATRIXTESTER_H
#include "Matrix.h"

using namespace std;


class MatrixOperationTester {
public:
    MatrixOperationTester();
    void testDoubleMatrix();
    void testTripleMatrix();
    void testGetDeterminant();
    void testGetXYZ();
    void testGetVariable();
    void testGetDotProduct();
    void testScaleBy();
    void testVectorString();
    void testVectorGetCrossProduct();
};


#endif //MATRIXOPERATIONS_MATRIXTESTER_H
