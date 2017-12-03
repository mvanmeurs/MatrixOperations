//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXCALCULATOR_H
#define MATRIXOPERATIONS_MATRIXCALCULATOR_H


#include "Matrix.h"

class MatrixCalculator {
public:
    MatrixCalculator();
private:
    void printMainMenuOptions() const;
    void printVectorOptions() const;
    void printMatrixOptions() const;
    void printPlaneOptions() const;
    void printPointOptions() const;
    void printAngleOptions() const;
};


#endif //MATRIXOPERATIONS_MATRIXCALCULATOR_H
