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
    testGetXYZ();
    testSetXYZ();
    testOperatorDoubleEquals();
    testOperatorNotEquals();
    testOperatorEquals();
    testOperatorOut();
    cout << "All Tests Passed!" << endl;
}
void PointTester::test2DConstructor(){
    cout << "Testing 2D constructor..." << flush;

    //empty
    Point<int> p1(0, 0);
    assert(p1.myVec[0] == 0);
    assert(p1.myVec[1] == 0);
    cout << " 0 " << flush;

    Point<int> p2(2, 3);
    assert(p2.myVec[0] == 2);
    assert(p2.myVec[1] == 3);
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

    Point<int> p4(1, 2);
    assert(p4.getX() == 1);
    cout << " 1d " << flush;
    assert(p4.getY() == 2);
    cout << " 1e " << flush;
    try{
        p4.getZ();
        cerr << "Get Z worked on a point of two dimensions" << flush;
    }catch(PointException& pe){
        cout << " 1f " << flush;
    }

    cout << " Passed!" << endl;
}

void PointTester::testSetXYZ(){
    cout << "Testing setXYZ... " << flush;
    //empty
    Point<int> p1(0, 0, 0);
    p1.setX(1);
    p1.setY(2);
    p1.setZ(3);
    assert(p1.getX() == 1);
    cout << " 0a " << flush;
    assert(p1.getY() == 2);
    cout << " 0b " << flush;
    assert(p1.getZ() == 3);
    cout << " 0c " << flush;

    Point<int> p3(0, 0);
    p3.setX(1);
    p3.setY(2);
    assert(p3.getX() == 1);
    cout << " 0d " << flush;
    assert(p3.getY() == 2);
    cout << " 0e " << flush;
    try{
        p3.setZ(3);
        cerr << "Set Z worked on a point of two dimensions" << flush;
    }catch(PointException& pe){
        cout << " 0f " << flush;
    }

    Point<int> p2(1, 2, 3);
    p2.setX(0);
    p2.setY(0);
    p2.setZ(0);
    assert(p2.getX() == 0);
    cout << " 1a " << flush;
    assert(p2.getY() == 0);
    cout << " 1b " << flush;
    assert(p2.getZ() == 0);
    cout << " 1c " << flush;

    Point<int> p4(1, 2);
    p4.setX(0);
    p4.setY(0);
    assert(p4.getX() == 0);
    cout << " 1d " << flush;
    assert(p4.getY() == 0);
    cout << " 1e " << flush;
    try{
        p4.setZ(0);
        cerr << "Set Z worked on a point of two dimensions" << flush;
    }catch(PointException& pe){
        cout << " 1f " << flush;
    }

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

    Point<int> p5(0, 0);
    Point<int> p6(0, 0);
    assert(p5 == p6);
    assert(p6 == p5);
    cout << " 2 " << flush;

    Point<int> p7(1, 2);
    Point<int> p8(1, 2);
    assert(p7 == p8);
    assert(p8 == p7);
    cout << " 3 " << flush;

    cout << " Passed!" << endl;
}

void PointTester::testOperatorNotEquals(){
    cout << "Testing operator!=..." << flush;
    Point<int> p1(1, 2);
    Point<int> p2(1, 3);
    Point<int> p3(2, 3);
    Point<int> p4(1, 2);
    assert(p1 != p2);
    cout << " 0 " << flush;
    assert(p2 != p3);
    cout << " 1 " << flush;
    assert(p1 != p3);
    cout << " 2 " << flush;
    assert(!(p1 != p4));
    cout << " 3 " << flush;
    cout << " Passed!" << endl;
}

void PointTester::testOperatorEquals(){
    cout << "Testing operator=..." << flush;

    Point<int> p1(0, 0);
    Point<int> p2(1, 2);
    Point<int> p3(1, 2);
    p1 = p2;
    assert(p1 == p3);
    cout << " 0 " << flush;

    Point<int> p4(0, 0, 0);
    Point<int> p5(1, 2, 3);
    Point<int> p6(1, 2, 3);
    p4 = p5;
    assert(p4 == p6);
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}

void PointTester::testOperatorOut(){
    cout << "Testing operator<<..." << flush;

    Point<int> p1(0, 0);
    cout << " Should be (0, 0) | " << p1 << flush;

    Point<int> p2(1, 2);
    cout << " Should be (1, 2) | " << p2 << flush;

    Point<int> p3(0, 0, 0);
    cout << " Should be (0, 0, 0) | " << p3 << flush;

    Point<int> p4(1, 2, 3);
    cout << " Should be (1, 2, 3) | " << p4 << flush;

    cout << " Passed!" << endl;
}