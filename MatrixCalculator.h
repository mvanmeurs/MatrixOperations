//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXCALCULATOR_H
#define MATRIXOPERATIONS_MATRIXCALCULATOR_H


#include "Matrix.h"

class MatrixCalculator {
    MatrixCalculator();
    void scanVariableMatrix(Matrix<double>&);
    void scanTripleMatrix(Matrix<double>&);
    void scanDoubleMatrix(Matrix<double>&);
    void scanVector(Vec<double>&);

    void printOptions() const;
};


#endif //MATRIXOPERATIONS_MATRIXCALCULATOR_H
