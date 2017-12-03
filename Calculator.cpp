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
    //main
    while(true){
        cin >> main;
        //Vector
        if(main == 1){
            printVectorOptions();
            unsigned vector;
            //vector
            while(true){
                if(vector == 1){

                }
            }

        }
        //Matrix
        else if(main == 2){

        }
        //Plane
        else if(main == 3){

        }
        //Point
        else if(main == 4){

        }
        //Angle
        else if(main == 5){

        }
        //quit
        else if(main == 0){break; }
        else{
            cerr << "Invalid Option" << flush;
        }
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