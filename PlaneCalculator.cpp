// Plane Calculator defines calculations that return a Plane or return values after performing operations on a Plane
// Created by mason on 12/5/17.
//

#include <iostream>
#include "PlaneCalculator.h"
#include "Vec.h"
#include "Point.h"
#include "Plane.h"

using namespace std;

PlaneCalculator::PlaneCalculator() {
    cout << "Press 1 to find the Plane with normal Vector through a Point" << endl;
    cout << "Press 2 to find the Plane through three Points" << endl;
    cout << "Press 3 to find the Plane that's parallel to a Plane and passes through a Point" << endl;
    cout << "Press 4 to find the Plane that's normal to a Vector and passes through a Point" << endl;
    cout << "Press 5 to find the Angle between two Planes" << endl;
    cout << "Press 6 to find the Plane formed by two parametrized Vectors" << endl;
    cout << "Press 7 to find the Plane through a Point with a normal Vector" << endl;
    cout << "Press 8 to find if two Planes are parallel" << endl;
    cout << "Press 9 to find if two Planes are orthogonal" << endl;
    cout << "Press 10 to find the Angle between two Planes" << endl;
    cout << "Press 0 to quit" << endl;

    unsigned user = 0;
    cin >> user;

    switch(user){
        case 1:
            getPlaneNormalVecPoint();
            break;
        case 2:
            getPlaneThroughPoints();
            break;
        case 3:
            getPlaneParallelThroughPoint();
            break;
        case 4:

            break;
        case 0:
            break;
        default:
            cerr << "Invalid option" << endl;
            cin >> user;
    }
    cout << endl;
}

void PlaneCalculator::getPlaneNormalVecPoint(){
    Vec<double> v(3);
    Point<double> pt(0, 0, 0);
    Plane<double> Pl(0, 0, 0, 0);
    v.scan();
    pt.scan();
    Pl.setPlane(v, pt);
    cout << "The Plane normal to " << v << " that passes through " << pt << " is " << Pl << endl;
}

void PlaneCalculator::getPlaneThroughPoints() {
    Point<double> p1(0, 0, 0);
    Point<double> p2(0, 0, 0);
    Point<double> p3(0, 0, 0);
    Plane<double> p(0, 0, 0, 0);
    p1.scan();
    p2.scan();
    p3.scan();
    p.setPlane(p1.getVectorFromPoints(p2).getCrossProduct(p1.getVectorFromPoints(p3)), p1);
    cout << "The Plane made from Points " << p1 << ", " << p2 << ", " << p3 << " is " << p << endl;
}

void PlaneCalculator::getPlaneParallelThroughPoint(){
    Plane<double> plane(0, 0, 0, 0);
    plane.scan();
    Point<double> point(0, 0, 0);
    point.scan();
    Plane<double> result(0, 0, 0, 0);
    result.setPlane(plane.getCoefficients(), point);
    cout << "The plane parallel to " << plane << " and " << point << " is " << result << endl;
}