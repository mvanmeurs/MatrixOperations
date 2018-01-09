// Vector Calculator defines calculations that return a Vector or return values after performing operations on a Vector
// Created by mason on 12/5/17.
//

#include "VectorCalculator.h"
#include "Vec.h"
#include "Plane.h"
#include "Point.h"

using namespace std;

VectorCalculator::VectorCalculator() {
    cout << "Press 1 to find the Area from two Vectors" << endl;
    cout << "Press 2 to find the Magnitude of a Vector" << endl;
    cout << "Press 3 to find the Normal Vector to a Plane" << endl;
    cout << "Press 4 to find the Normal Vector to a plane created by three Points" << endl;
    cout << "Press 5 to find the parameterized line through a Point and orthogonal to a Plane" << endl;
    cout << "Press 6 to find the parameterized line through a Point and parallel to Plane" << endl;
    cout << "Press 0 to quit" << endl;

    unsigned user = 0;
    cin >> user;

    switch(user){
        case 1:
            getArea();
            break;
        case 2:
            getMagnitude();
            break;
        case 3:
            getNormalToPlane();
            break;
        case 4:
            getNormalToThreePoints();
            break;
        case 0:
            break;
        default:
            cerr << "Invalid option" << endl;
            cin >> user;
    }
    cout << endl;
}

void VectorCalculator::getArea() {
    Vec<double> v1(3);
    Vec<double> v2(3);
    v1.scan();
    v2.scan();
    cout << "The Area created by " << v1 << " and " << v2 << " = " << v1.getCrossProduct(v2).getMagnitude() << endl;
}

void VectorCalculator::getMagnitude() {
    cout << "Please enter the number of dimensions your Vector has:" << endl;
    unsigned size;
    cin >> size;
    Vec<double> v(size);
    v.scan();
    cout << "The Magnitude of " << v << " is " << v.getMagnitude() << endl;
}

void VectorCalculator::getNormalToPlane() {
    Plane<double> p;
    p.scan();
    cout << "The Vector normal to the Plane is " << p.getCoefficients() << endl;
}

void VectorCalculator::getNormalToThreePoints() {
    Point<double> p1(0, 0, 0);
    Point<double> p2(0, 0, 0);
    Point<double> p3(0, 0, 0);

    p1.scan();
    p2.scan();
    p3.scan();

    cout << "The Normal Vector to the Plane created by your three points is "
         << p1.getVectorFromPoints(p2).getCrossProduct(p1.getVectorFromPoints(p3))
         << endl;
}