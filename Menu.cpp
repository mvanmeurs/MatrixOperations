//
// Created by mason on 11/28/17.
//

#include <iostream>

#include "Menu.h"
#include "MatrixCalculator.h"

using namespace std;

Menu::Menu(){
    cout << "Welcome to the Vector Calculus class!" << endl;
    cout << endl;

    unsigned main = 1;
    printMenuOptions();
    cin >> main;
    //main
    while(main != 0){
        if(main == 1){
            VectorCalculator vc;
        }
        else if(main == 2){
            MatrixCalculator mc;
        }
        else if(main == 3){
            PlaneCalculator pc;
        }
        printMenuOptions();
        cin >> main;
    }
    //main loop

    cout << "Thanks for using the Vector Calculus Class!" << flush;
}

void Menu::printMenuOptions() const {
    cout << "Press 1 to perform an operation that returns a Vector" << endl;
    cout << "Press 2 to perform an operation that returns a Matrix" << endl;
    cout << "Press 3 to perform an operation that returns a Plane" << endl;
    cout << "Press 4 to perform an operation that returns a Point" << endl;
    cout << "Press 0 to quit" << endl;
}

void Menu::printPointOptions() const {
    cout << "Press 1 to find the Area created by three Points" << endl;
    cout << "Press 2 to find the intersection Point of a Plane and a parametrized Vector" << endl;
    cout << "Press 0 to quit" << endl;
}