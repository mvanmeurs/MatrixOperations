//
// Created by mason on 11/28/17.
//

#include "MatrixCalculator.h"
#include <iostream>

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Welcome to the Matrix Calculator!" << endl;
    cout << "Press 1 to enter a 3x3 Matrix or 2 to enter a 2x2 Matrix" << endl;

    unsigned user = 0;
    cin >> user;

    switch(user){
        case 1:
            scanTripleMatrix();
    }
}

void MatrixCalculator::scanTripleMatrix(){

}
