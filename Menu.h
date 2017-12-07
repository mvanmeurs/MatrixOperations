//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXCALCULATOR_H
#define MATRIXOPERATIONS_MATRIXCALCULATOR_H

#include "VectorCalculator.h"
#include "MatrixCalculator.h"
#include "PlaneCalculator.h"
#include "PointCalculator.h"

class Menu {
public:
    Menu();
private:
    void printMenuOptions() const;
    void printPlaneOptions() const;
    void printPointOptions() const;
};


#endif //MATRIXOPERATIONS_MATRIXCALCULATOR_H
