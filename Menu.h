//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MATRIXCALCULATOR_H
#define MATRIXOPERATIONS_MATRIXCALCULATOR_H


#include "Matrix.h"
#include "Point.h"
#include "Plane.h"

class Menu {
public:
    Menu();
private:
    void printMainMenuOptions() const;
    void printVectorOptions() const;
    void printMatrixOptions() const;
    void printPlaneOptions() const;
    void printPointOptions() const;
};


#endif //MATRIXOPERATIONS_MATRIXCALCULATOR_H
