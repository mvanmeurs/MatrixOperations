//
// Created by mason on 11/28/17.
//

#include "Menu.h"

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Welcome to the Vector Calculus class!" << endl;
    cout << endl;
    printMainMenuOptions();

    unsigned main;
    cin >> main;
    //main
    switch(main){
        //Vector
        case 1:
            printVectorOptions();
            unsigned vector;
            cin >> vector;
            //vector
            switch(vector){

            }

        //Matrix
        case 2:

            break;
        //Plane
        case 3:

            break;
        //Point
        case 4:

            break;
        //Angle
        case 5:

            break;
        //quit
        case 0:
            break;
        default:
            cerr << "Invalid Option" << flush;
            cin >> main;
    }
    //main loop

    cout << "Thanks for using the Vector Calculus Class!" << flush;
}

void MatrixCalculator::printMainMenuOptions() const {
    cout << "Press 1 to perform an operation that returns a Vector" << endl;
    cout << "Press 2 to perform an operation that returns a Matrix" << endl;
    cout << "Press 3 to perform an operation that returns a Plane" << endl;
    cout << "Press 4 to perform an operation that returns a Point" << endl;
    cout << "Press 5 to perform an operation that returns an Angle" << endl;
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printVectorOptions() const {
    cout << "Press 1 to find the Area from two Vectors" << endl;
    cout << "Press 2 to find the Magnitude of a Vector" << endl;
    cout << "Press 3 to find the Normal Vector to a Plane" << endl;
    cout << "Press 4 to find the Normal Vector to a plane created by three Points" << endl;
    cout << "Press 5 to find the parameterized line through a Point and orthogonal to a Plane" << endl;
    cout << "Press 6 to find the parameterized line through a Point and parallel to Plane" << endl;
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printMatrixOptions() const {
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printPlaneOptions() const {
    cout << "Press 1 to find the Plane with normal Vector through a Point" << endl;
    cout << "Press 2 to find the Plane through three Points" << endl;
    cout << "Press 3 to find the Plane that's parallel to a Plane and passes through a Point" << endl;
    cout << "Press 4 to find the Plane that's normal to a Vector and passes through a Point" << endl;
    cout << "Press 5 to find the Angle between two Planes" << endl;
    cout << "Press 6 to find the Plane formed by two parametrized Vectors" << endl;
    cout << "Press 7 to find the Plane through a Point with a normal Vector" << endl;
    cout << "Press 8 to find if two Planes are parallel" << endl;
    cout << "Press 9 to find if two Planes are orthogonal" << endl;
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printPointOptions() const {
    cout << "Press 1 to find the Area created by three Points" << endl;
    cout << "Press 2 to find the intersection Point of a Plane and a parametrized Vector" << endl;
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printAngleOptions() const {
    cout << "Press 0 to quit" << endl;
}