//
// Created by mason on 11/28/17.
//

#include "MatrixCalculator.h"

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Welcome to the Matrix Calculator!" << endl;
    cout << endl;
    printOptions();

    unsigned user = 0;
    cin >> user;

    //main loop
    while(true){
        //3x4 matrix
        if(user == 1){
            Matrix<double> m1(3, 4);
            scanMatrix(m1);

        }
        //determinant
        else if(user == 2) {
            cout << "Press 1 to enter your matrix dimensions" << flush;
            cout << "Press 0 to quit" << endl;

            unsigned user;
            cin >> user;
            //determinant
            while(true){
                //enter dimensions
                if(user == 1){
                    cout << "Please enter your square matrix dimension:" << endl;
                    unsigned size;
                    cin >> size;

                    //determinant
                    while(true){
                        //2x2 matrix
                        if(size == 2){
                            Matrix<double> m1(size, size);
                            scanMatrix(m1);
                            cout << "The determinant is: " << m1.getDeterminant() << flush;
                        }
                        //3x3 matrix
                        else if(size == 3){
                            Matrix<double> m1(size, size);
                            scanMatrix(m1);
                            cout << "The determinant is: " << m1.getDeterminant() << flush;
                        }
                        //quit
                        else if(user == 3){break;}
                        //invalid option
                        else{cerr << "Invalid matrix size. Please enter your square matrix dimension:" << endl;}
                        cin >> size;
                    }
                }
                //quit
                else if(user == 0){break;}
                //invalid option
                else{ cerr << "Invalid option. Please re-enter your option" << flush;}
                cin >> user;
            }

        }
        //dot or cross
        else if(user == 3){
            cout << "Press 1 to calculate the dot product" << endl;
            cout << "Press 2 to calculate the cross product" << endl;
            cout << "Press 0 to quit" << endl;

            unsigned user;
            cin >> user;

            //dot or cross
            while(true){
                Vec<double> v1(3);
                Vec<double> v2(3);
                Vec<double> result(3);
                scanVector(v1);
                scanVector(v2);
                //dot product
                if(user == 1){
                    cout << "The dot product is: " << flush;
                    result = v1.getDotProduct(v2);
                    result.toString();
                }
                //cross product
                else if(user == 2){

                }
                //quit
                else if(user == 0){break;}
                else{cerr << "Invalid option. Please re-enter your option" << flush;}
                cin >> user;
            }
        }
        //quit
        else if(user == 0){break;}
            //invalid option
        else{cerr << "Invalid option" << endl;}
        printOptions();
        cin >> user;
    }
}

void MatrixCalculator::printOptions() const {
    cout << "Press 1 to solve for a variable in a 3x4 Matrix" << endl;
    cout << "Press 2 to solve the determinant of a Matrix" << endl;
    cout << "Press 3 to calculate the dot product or cross product of two vectors" << endl;
    cout << "Press 4 to calculate the Volume created by three Vectors" << endl;
    cout << "Press 0 to quit" << endl;
}

void MatrixCalculator::scanMatrix(Matrix<double>& matrix) {
   cout << "Please enter the values for your " << matrix.getRows() << "x" << matrix.getColumns() << " matrix:" << endl;
    double scan;
    for(unsigned r = 0; r < matrix.getRows(); r++) {
        for (unsigned c = 0; c < matrix.getColumns(); c++) {
            cin >> scan;
            matrix[r][c] = scan;
        }
        cout << endl;
    }
    cout << "Here is the matrix you entered:" << endl;
    matrix.toString();
}

void MatrixCalculator::scanVector(Vec<double>& vec){
    cout << "Please enter the values for your Vector:" << endl;
    double scan;
    for(unsigned i = 0; i < vec.getSize() ; i++){
        cin >> scan;
        vec[i] = scan;
    }
    cout << "Here is the vector you entered:" << endl;
    vec.toString();
}
