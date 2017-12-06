//
// Created by mason on 11/28/17.
//

#include "Calculator.h"

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Welcome to the Calculator class!" << endl;
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

    cout << "Thanks for using the Calculator Class!" << flush;
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
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printMatrixOptions() const {
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printPlaneOptions() const {
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printPointOptions() const {
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::printAngleOptions() const {
    cout << "Press 0 to quit" << endl;
}