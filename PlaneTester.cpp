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

    cout << " Passed!" << endl;
}