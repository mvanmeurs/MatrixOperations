//
// Created by mason on 11/28/17.
//

#include "MatrixCalculator.h"

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Welcome to the Matrix Calculator!" << endl;
    printOptions();

    Matrix<double> m(3, 3);

    unsigned user = 0;
    cin >> user;

    while(true){
        if(user == 1){
            Matrix<double> m1(3, 4);
            scanVariableMatrix(m1);
        }
        else if(user == 2) {
            Matrix<double> m1(3, 3);
            scanTripleMatrix(m1);
        }
        else if(user == 0){break;}
        else{
            cout << "Invalid option" << endl;
        }
        printOptions();
        cin >> user;
    }
}

void MatrixCalculator::printOptions() const {
    cout << "Press 1 to solve for a variable in a 3x4 Matrix" << endl;
    cout << "Press 2 to solve the determinant of a Matrix" << endl;
    cout << "Press 3 to calculate the dot product or cross product of a vector" << endl;
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::scanVariableMatrix(Matrix<double>& matrix) {
    cout << "Please enter the values for your 3x4 matrix:" << endl;
    double scan;
    for (unsigned r = 0; r < 3; r++) {
        for (unsigned c = 0; c < 4; c++) {
            cin >> scan;
            matrix[r][c] = scan;
        }
        cout << endl;
    }
    cout << "Here is the matrix you entered:" << endl;
    matrix.toString();
}


void MatrixCalculator::scanTripleMatrix(Matrix<double>& matrix){
    cout << "Please enter the values for your 3x3 matrix:" << endl;
    double scan;
    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++){
            cin >> scan;
            matrix[r][c] = scan;
        }
        cout << endl;
    }
    cout << "Here is the matrix you entered:" << endl;
    matrix.toString();
}

void MatrixCalculator::scanDoubleMatrix(Matrix<double>& matrix){
    cout << "Please enter the values for your 2x2 matrix:" << endl;
    double scan;
    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            cin >> scan;
            matrix[r][c] = scan;
        }
        cout << endl;
    }
    cout << "Here is the matrix you entered:" << endl;
    matrix.toString();
}

void MatrixCalculator::scanVector(Vec<double>& vec){

}
