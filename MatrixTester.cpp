//
// Created by mason on 11/28/17.
//
#include <cassert>
#include "MatrixTester.h"

using namespace std;

MatrixTester::MatrixTester(){
    cout << "Testing Class Matrix..." << endl;
    testDoubleMatrix();
    cout << endl;
    testTripleMatrix();
    cout << endl;
    testGetX();
    cout << "All tests passed!" << endl;
}

void MatrixTester::testDoubleMatrix(){
    cout << "Testing 2x2 Matrix... " << flush;
    Matrix<unsigned> m1(2, 2);
    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            m1.myVec[r][c] = 0;
        }
    }
    assert(m1.getDeterminantDouble() == 0);
    cout << " 0 " << flush;

    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            m1.myVec[r][c] = (r+1)*(c+1);
        }
    }
    assert(m1.getDeterminantDouble() == 0);
    cout << " 1 " << flush;

    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            m1.myVec[r][c] = (r+2)*(c+1);
        }
    }
    assert(m1.getDeterminantDouble() == 0);
    cout << " 2 " << flush;

    cout << "Passed!" << flush;
}

void MatrixTester::testTripleMatrix(){
    cout << "Testing 3x3 Matrix... " << flush;
    Matrix<unsigned> m1(3, 3);
    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++){
            m1.myVec[r][c] = 0;
        }
    }
    assert(m1.getDeterminantTriple() == 0);
    cout << " 0 " << flush;

    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++){
            m1.myVec[r][c] = (r+1)*(c+1);
        }
    }
    assert(m1.getDeterminantTriple() == 0);
    cout << " 1 " << flush;

    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++){
            m1.myVec[r][c] = (r+3)*(c+1);
        }
    }
    assert(m1.getDeterminantTriple() == 0);
    cout << " 2 " << flush;

    m1.myVec[0][0] = 9;
    m1.myVec[2][1] = 17;

    assert(m1.getDeterminantTriple() == -504);
    cout << " 3 " << flush;

    cout << "Passed!" << flush;
}

void MatrixTester::testGetX(){
    Matrix<unsigned> m(3, 4);
    unsigned a = 1;
    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 4 ; c++){
            m.myVec[r][c] = a;
            a++;
        }
    }
    m.myVec[2][0] = 0;
    m.myVec[2][1] = 0;
    m.myVec[2][2] = 12;
    m.myVec[2][3] = 12;

    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 4 ; c++){
            cout << m.myVec[r][c] << " " << flush;
        }
    }

    cout << m.getX() << flush;

    assert(m.getX() == -1);
    cout << " 0 " << flush;

    cout << "Passed!" << flush;
}
