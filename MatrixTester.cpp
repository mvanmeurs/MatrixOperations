//
// Created by mason on 11/28/17.
//
#include <cassert>
#include "MatrixTester.h"

using namespace std;

MatrixTester::MatrixTester(){
    cout << "Testing Class Matrix..." << endl;
    testDoubleMatrix();
    testTripleMatrix();
    cout << "All tests passed!" << endl;
}

void MatrixTester::testDoubleMatrix(){
    cout << "Testing 2x2 Matrix... " << flush;
    Matrix<unsigned> m1;
    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; ){
            m1[r][c] = 0;
        }
    }
    assert(m1.getDeterminantDouble() == 0);
}

void MatrixTester::testTripleMatrix(){

}