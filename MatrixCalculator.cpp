//
// Created by mason on 11/28/17.
//

#include "MatrixCalculator.h"
#include <locale>

using namespace std;

MatrixCalculator::MatrixCalculator(){
    cout << "Welcome to the Matrix Calculator!" << endl;
    cout << endl;
    printOptions();

    unsigned main;

    //main loop
    while(true){
        cin >> main;
        //3x4 matrix
        if(main == 1){
            Matrix<double> m1(3, 4);
            scanMatrix(m1);

            cout << "Press 0 to quit" << endl;
            cout << "Please enter the variable you wish to solve for:" << endl;
            char variable;

            //variable
            while(true){
                cin >> variable;
                //x
                if(tolower(variable) == 'x'){

                }
                //y
                else if(tolower(variable) == 'y'){

                }
                //z
                else if(tolower(variable) == 'z'){

                }
                //quit
                else if(variable == '0'){break;}
                else{
                    cerr << "Please enter either x, y, or z" << endl;
                }
            }

        }
        //determinant
        else if(main == 2) {
            cout << "Press 1 to enter your matrix dimensions" << flush;
            cout << "Press 0 to quit" << endl;

            unsigned determinant;

            //determinant
            while(true){
                cin >> determinant;
                //enter dimensions
                if(determinant == 1){
                    cout << "Please enter your square matrix dimension:" << endl;

                    unsigned size;

                    //determinant
                    while(true){

                        cin >> size;
                        //matrix
                        if(size == 2 || size == 3){
                            Matrix<double> m1(size, size);
                            scanMatrix(m1);
                            cout << "The determinant of:" << endl;
                            m1.toString();
                            cout << " is equal to:" << m1.getDeterminant() << flush;
                            break;
                        }
                        //invalid option
                        else{cerr << "Invalid matrix size. Please enter your square matrix dimension:" << endl;}
                    }
                }
                //quit
                else if(determinant == 0){break;}
                //invalid option
                else{ cerr << "Invalid option. Please re-enter your option" << flush;}
            }

        }
        //dot or cross
        else if(main == 3){
            cout << "Press 1 to calculate the dot product" << endl;
            cout << "Press 2 to calculate the cross product" << endl;
            cout << "Press 0 to quit" << endl;

            unsigned dotcross;

            //dot or cross
            while(true){
                cin >> dotcross;
                //quit
                if(dotcross == 0){break;}

                Vec<double> v1(3);
                Vec<double> v2(3);
                Vec<double> result(3);
                scanVector(v1);
                scanVector(v2);
                //dot product
                if(dotcross == 1){
                    v1.toString();
                    cout << " * " << flush;
                    v2.toString();
                    cout << " = " << flush;
                    result = v1.getDotProduct(v2);
                    result.toString();
                }
                //cross product
                else if(dotcross == 2){
                    v1.toString();
                    cout << " * " << flush;
                    v2.toString();
                    cout << " = " << flush;
                    result = v1.getCrossProduct(v2);
                    result.toString();
                }
                else{cerr << "Invalid option. Please re-enter your option" << flush;}
            }
        }
        //volume

        //quit
        else if(main == 0){break;}
        //invalid option
        else{cerr << "Invalid option" << endl;}
        printOptions();
    }
    cout << "Thanks for using the Matrix Operations Class!" << flush;
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
