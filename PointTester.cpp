//
// Created by mason on 12/3/17.
//

#include <cstdlib>
#include <iostream>
#include <cassert>
#include "PointTester.h"
#include "Point.h"
#include "PointException.h"

using namespace std;

PointTester::PointTester(){
    cout << "Testing Class Point" << endl;
    test2DConstructor();
    test3DConstructor();
    testGetXYZ();
    testOperatorDoubleEquals();
    cout << "All Tests Passed!" << endl;
}
void PointTester::test2DConstructor(){
    cout << "Testing 2D constructor..." << flush;

    //empty
    Point<int> p1(0, 0);
    assert(p1.myVec[0] == 0);
    assert(p1.myVec[1] == 0);
    assert(p1.myVec[2] == 0);
    cout << " 0 " << flush;

    Point<int> p2(2, 3);
    assert(p2.myVec[0] == 2);
    assert(p2.myVec[1] == 3);
    assert(p2.myVec[2] == 0);
    cout << " 1 " << flush;
    cout << " Passed!" << endl;
}

void PointTester::test3DConstructor(){
    cout << "Testing 3D constructor..." << flush;

    //empty
    Point<int> p1(0, 0, 0);
    assert(p1.myVec[0] == 0);
    assert(p1.myVec[1] == 0);
    assert(p1.myVec[2] == 0);
    cout << " 0 " << flush;

    Point<int> p2(2, 3, 1);
    assert(p2.myVec[0] == 2);
    assert(p2.myVec[1] == 3);
    assert(p2.myVec[2] == 1);
    cout << " 1 " << flush;
    cout << " Passed!" << endl;
}

void PointTester::testGetXYZ() {
    cout << "Testing getXYZ... " << flush;
    //empty
    Point<int> p1(0, 0, 0);
    assert(p1.getX() == 0);
    cout << " 0a " << flush;
    assert(p1.getY() == 0);
    cout << " 0b " << flush;
    assert(p1.getZ() == 0);
    cout << " 0c " << flush;

    Point<int> p3(0, 0);
    assert(p3.getX() == 0);
    cout << " 0d " << flush;
    assert(p3.getY() == 0);
    cout << " 0e " << flush;
    try{
        p3.getZ();
        cerr << "Get Z worked on a point of two dimensions" << flush;
    }catch(PointException& pe){
        cout << " 0f " << flush;
    }

    Point<int> p2(1, 2, 3);
    assert(p2.getX() == 1);
    cout << " 1a " << flush;
    assert(p2.getY() == 2);
    cout << " 1b " << flush;
    assert(p2.getZ() == 3);
    cout << " 1c " << flush;

    cout << " Passed!" << endl;
}

void PointTester::testOperatorDoubleEquals() {
    cout << "Testing operator==..." << flush;
    //empty
    Point<int> p1(0, 0, 0);
    Point<int> p2(0, 0, 0);
    assert(p1 == p2);
    assert(p2 == p1);
    cout << " 0 " << flush;
    Point<int> p3(1, 2, 3);
    Point<int> p4(1, 2, 3);
    assert(p3 == p4);
    assert(p4 == p3);
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}