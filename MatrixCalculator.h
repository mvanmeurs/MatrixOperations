//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXCALCULATOR_H
#define MATRIXOPERATIONS_MATRIXCALCULATOR_H


#include "Matrix.h"

class MatrixCalculator {
    MatrixCalculator();
    void scanMatrix(Matrix<double>& matrix);
    void scanVector(Vec<double>&);
    void printOptions() const;
};


#endif //MATRIXOPERATIONS_MATRIXCALCULATOR_H
