// Point Calculator defines calculations that return a Point
// Created by mason on 12/5/17.
//

#include <iostream>
#include "PointCalculator.h"
#include "Point.h"

using namespace std;

PointCalculator::PointCalculator() {
    cout << "Press 1 to find the Area created by three Points" << endl;
    cout << "Press 2 to find the intersection Point of a Plane and a parametrized Vector" << endl;
    cout << "Press 0 to quit" << endl;

    unsigned user = 0;
    cin >> user;

    switch(user){
        case 1:
            getArea();
            break;
        case 0:
            break;
        default:
            cerr << "Invalid option" << endl;
            cin >> user;
    }
    cout << endl;
}

void PointCalculator::getArea() {
    Point<double> p1(0, 0, 0);
    Point<double> p2(0, 0, 0);
    Point<double> p3(0, 0, 0);
    p1.scan();
    p2.scan();
    p3.scan();
    cout << "The area created by points "
         << p1 << ", " << p2 << ", and " << p3 << " is "
         << .5*((p1.getVectorFromPoints(p2).getCrossProduct(p1.getVectorFromPoints(p3)).getMagnitude())) << endl;
}