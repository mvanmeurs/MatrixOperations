// Matrix Calculator defines class methods that can be applied to a Matrix
// Created by mason on 1/9/18.
//

#include <iostream>
#include "MatrixCalculator.h"
#include "Matrix.h"

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Press 1 to get the Determinant of a Matrix" << endl;
    cout << "Press 2 to get the Coefficient of a variable in a Matrix" << endl;
    cout << "Press 0 to quit" << endl;

    unsigned user = 0;
    cin >> user;

    switch(user){
        case 1:
            getDeterminant();
            break;
        case 2:
            getCoefficient();
            break;
        case 0:
            break;
        default:
            cerr << "Invalid option" << endl;
            cin >> user;
    }
}

void MatrixCalculator::getDeterminant() {
    cout << "Please enter the dimension of your Matrix:" << endl;
    unsigned size;
    cin >> size;
    Matrix<double> m(size, size);
    m.scan();
    cout << m << flush;
    cout << "The Determinant of your Matrix is " << m.getDeterminant() << endl;
}

void MatrixCalculator::getCoefficient() {
    Matrix<double> m(3, 4);
    m.scan();
    cout << m << flush;

    char user;
    cout << "Please enter the letter of the coefficient that you want to get:" << endl;
    cin >> user;

    while(true){
        try{
            m.getVariable(user);
            cout << "The " << toupper(user) << " coefficient is " << m.getVariable(user) << endl;
            break;
        }catch(VariableException& ve){
            cout << "Please enter x, y, or z:" << endl;
            cin >> user;
        }
    }
}