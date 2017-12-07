//
// Created by mason on 11/28/17.
//

#include <iostream>

#include "Menu.h"

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

void Menu::printPlaneOptions() const {
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
}

void Menu::printPointOptions() const {
    cout << "Press 1 to find the Area created by three Points" << endl;
    cout << "Press 2 to find the intersection Point of a Plane and a parametrized Vector" << endl;
    cout << "Press 0 to quit" << endl;
}