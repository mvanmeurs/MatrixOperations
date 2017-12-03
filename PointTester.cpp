//
// Created by mason on 12/3/17.
//

#include <cstdlib>
#include <iostream>
#include <cassert>
#include "PointTester.h"
#include "Point.h"

using namespace std;

PointTester::PointTester(){
    cout << "Testing Class Point" << endl;
    test2DConstructor();
    test3DConstructor();
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

    cout << " Passed!" << endl;
}