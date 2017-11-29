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
    testGetXYZ();
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

    unsigned a = 1;
    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            m1.myVec[r][c] = a;
            a++;
        }
    }
    assert(m1.getDeterminantDouble() == -2);
    cout << " 3 " << flush;

    cout << "Passed!" << endl;
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

    cout << "Passed!" << endl;
}

void MatrixTester::testGetXYZ(){
    cout << "Testing getXYZ()..." << flush;
    Matrix<int> m(3, 4);

    for(int r = 0 ; r < 3 ; r++){
        for(int c = 0 ; c < 4 ; c++){
            m.myVec[r][c] = 0;
        }
    }

    assert(m.getX() == 0);
    cout << " 0a " << flush;

    assert(m.getY() == 0);
    cout << " 0b " << flush;

    assert(m.getZ() == 0);
    cout << " 0c " << flush;

    for(int r = 0 ; r < 3 ; r++){
        for(int c = 0 ; c < 4 ; c++){
            m.myVec[r][c] = 1;
        }
    }

    assert(m.getX() == 0);
    cout << " 1a " << flush;

    assert(m.getY() == 0);
    cout << " 1b " << flush;

    assert(m.getZ() == 0);
    cout << " 1c " << flush;

    int a = 1;
    for(int r = 0 ; r < 2 ; r++){
        for(int c = 0 ; c < 4 ; c++){
            m.myVec[r][c] = a;
            a++;
        }
    }
    m.myVec[2][0] = 0;
    m.myVec[2][1] = 0;
    m.myVec[2][2] = 12;
    m.myVec[2][3] = 12;

    assert(m.getX() == -1);
    cout << " 2a " << flush;

    assert(m.getY() == 1);
    cout << " 2b " << flush;

    assert(m.getZ() == 1);
    cout << " 2c " << flush;

    cout << "Passed!" << endl;

    for(int r = 0 ; r < 3 ; r++){
        for(int c = 0 ; c < 4 ; c++){
            m.myVec[r][c] = 1;
        }
    }

}
