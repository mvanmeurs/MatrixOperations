// Plane Calculator defines calculations that return a Plane or return values after performing operations on a Plane
// Created by mason on 12/5/17.
//

#ifndef MATRIXOPERATIONS_PLANECALCULATOR_H
#define MATRIXOPERATIONS_PLANECALCULATOR_H


class PlaneCalculator {
public:
    PlaneCalculator();
private:
    void getPlaneNormalVecPoint();
    void getPlaneThroughPoints();
    void getPlaneParallelThroughPoint();
    void getPlaneNormalToVecThroughPoint();
    void getAngleBetweenPlanes();
    void getIfParallelOrthogonal();
};


#endif //MATRIXOPERATIONS_PLANECALCULATOR_H
