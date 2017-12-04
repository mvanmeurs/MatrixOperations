//
// Created by mason on 12/3/17.
//

#include <cstdlib>
#include <iostream>
#include <cassert>
#include "PlaneTester.h"
#include "Plane.h"

using namespace std;

PlaneTester::PlaneTester(){
    cout << "Testing Class Plane" << endl;
    testConstructor();
    testGetxyzEqualsTo();
    testGetXYZ();
    testGetCoefficients();
    testSetXYZ();
    testOperatorDoubleEquals();
    testOperatorNotEquals();
    testOperatorEquals();
    testOperatorOut();
    cout << "All Tests Passed!" << endl;
}

void PlaneTester::testConstructor() {
    cout << "Testing Constructor..." << flush;
    Plane<int> p1(0, 0, 0, 0);
    assert(p1.myVec[0] == 0);
    assert(p1.myVec[1] == 0);
    assert(p1.myVec[2] == 0);
    assert(p1.myVec[3] == 0);
    cout << " 0 " << flush;

    Plane<int> p2(1, 2, 3, 4);
    assert(p2.myVec[0] == 1);
    assert(p2.myVec[1] == 2);
    assert(p2.myVec[2] == 3);
    assert(p2.myVec[3] == 4);
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testGetxyzEqualsTo(){
    cout << "Testing getxyzEqualsTo... " << flush;

    Plane<int> p1(0, 0, 0, 0);
    assert(p1.getx() == 0);
    assert(p1.gety() == 0);
    assert(p1.getz() == 0);
    assert(p1.getMyEqualsTo() == 0);
    cout << " 0 " << flush;

    Plane<int> p2(1, -2, 3, 4);
    assert(p2.getx() == 1);
    assert(p2.gety() == -2);
    assert(p2.getz() == 3);
    assert(p2.getMyEqualsTo() == 4);
    cout << " 1 " << flush;


    cout << " Passed!" << endl;
}

void PlaneTester::testGetXYZ() {
    cout << "Testing getXYZ... " << flush;

    Plane<int> p1(0, 0, 0, 0);
    Vec<int> v1(3);
    assert(p1.getX() == v1);
    assert(p1.getY() == v1);
    assert(p1.getZ() == v1);
    cout << " 0 " << flush;

    Plane<int> p2(1, 2, 3, 4);
    v1[0] = 1;
    assert(p2.getX() == v1);
    cout << " 1 " << flush;
    v1[0] = 0;
    v1[1] = 2;
    assert(p2.getY() == v1);
    cout << " 2 " << flush;
    v1[1] = 0;
    v1[2] = 3;
    assert(p2.getZ() == v1);
    cout << " 3 " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testGetCoefficients(){
    cout << "Testing getCoefficients... " << flush;

    Plane<int> p1(0, 0, 0, 0);
    Vec<int> v1(3);
    assert(p1.getCoefficients() == v1);
    cout << " 0 " << flush;
    Plane<int> p2(1, 2, -3, 4);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = -3;
    assert(p2.getCoefficients() == v1);
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testSetXYZ(){
    cout << "Testing setXYZ... " << flush;

    Plane<int> p1(0, 0, 0, 0);
    Plane<int> p2(1, 2, 3, 0);
    p1.setX(1);
    p1.setY(2);
    p1.setZ(3);
    assert(p1 == p2);
    cout << " 0 " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testOperatorDoubleEquals() {
    cout << "Testing operator==..." << flush;

    Plane<int> p1(0, 0, 0, 0);
    Plane<int> p2(0, 0, 0, 0);
    assert(p1 == p2);
    cout << " 0a " << flush;
    assert(p2 == p1);
    cout << " 0b " << flush;

    Plane<int> p3(1, 2, 3, 4);
    Plane<int> p4(1, 2, 3, 4);
    assert(p3 == p4);
    cout << " 1a " << flush;
    assert(p4 == p3);
    cout << " 1b " << flush;

    Plane<int> p5(1, 2, 3, 4);
    Plane<int> p6(0, 0, 0, 0);
    assert(!(p5 == p6));
    cout << " 2a " << flush;
    assert(!(p6 == p5));
    cout << " 2b " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testOperatorNotEquals() {
    cout << "Testing operator!=..." << flush;

    Plane<int> p1(0, 0, 0, 0);
    Plane<int> p2(0, 0, 0, 0);
    assert(!(p1 != p2));
    cout << " 0a " << flush;
    assert(!(p2 != p1));
    cout << " 0b " << flush;

    Plane<int> p3(1, 2, 3, 4);
    Plane<int> p4(1, 2, 3, 4);
    assert(!(p3 != p4));
    cout << " 1a " << flush;
    assert(!(p4 != p3));
    cout << " 1b " << flush;

    Plane<int> p5(1, 2, 3, 4);
    Plane<int> p6(0, 0, 0, 0);
    assert(p5 != p6);
    cout << " 2a " << flush;
    assert(p6 != p5);
    cout << " 2b " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testOperatorEquals() {
    cout << "Testing operator=..." << flush;

    Plane<int> p1(0, 0, 0, 0);
    Plane<int> p2(1, 2, 3, 4);
    Plane<int> p3(1, 2, 3, 4);
    p1 = p2;
    assert(p1 == p3);
    cout << " 0 " << flush;

    cout << " Passed!" << endl;
}

void PlaneTester::testOperatorOut(){
    cout << "Testing operator<<... " << flush;

    Plane<int> p1(0, 0, 0, 0);
    cout << "Should be 'All real numbers are solutions' | " << p1 << flush;

    Plane<int> p2(1, -1, 1, -1);
    cout << " Should be X - Y + Z = -1 | " << p2 << flush;

    Plane<int> p3(-1, 0, -4, 5);
    cout << " Should be -X - 4Z = 5 | " << p3 << flush;

    Plane<int> p4(0, -3, 1, 0);
    cout << " Should be - 3Y + Z = 0 | " << p4 << flush;

    Plane<int> p5(5, -1, -1, 9);
    cout << " Should be 5X - Y - Z = 9 | " << p5 << flush;

    Plane<int> p6(-2, 3, 0, 1);
    cout << " Should be -2X + 3Y = 1 | " << p6 << flush;

    cout << " Passed!" << endl;
}