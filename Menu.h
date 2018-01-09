//
// Created by mason on 11/28/17.
//

#ifndef MATRIXOPERATIONS_MENU_H
#define MATRIXOPERATIONS_MENU_H

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


#endif //MATRIXOPERATIONS_MENU_H
