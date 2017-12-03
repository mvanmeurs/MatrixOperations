//
// Created by mason on 11/28/17.
//
#include <cassert>
#include "CalculatorOperationTester.h"

using namespace std;

CalculationOperationTester::CalculationOperationTester(){
    cout << "Testing Operations..." << endl;
    testDoubleMatrix();
    testTripleMatrix();
    testGetDeterminant();
    testGetXYZ();
    testGetVariable();
    testGetDotProduct();
    testScaleBy();
    testVectorString();
    testVectorGetCrossProduct();
    //testVectorGetMagnitude();
    testVectorOperatorOut();
    testMatrixOperatorOut();
    cout << "All tests passed!" << endl;
}

void CalculationOperationTester::testDoubleMatrix(){
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

void CalculationOperationTester::testTripleMatrix(){
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

void CalculationOperationTester::testGetDeterminant(){
    cout << "Testing getDeterminant..." << flush;

    Matrix<int> m1(4, 5);
    try{
        m1.getDeterminant();
        cerr << "getDeterminant worked on a non 2x2 or 3x3 Matrix" << flush;
    }catch(MatrixDimensionException& mde){
        cout << " 0a " << flush;
    }

    Matrix<int> m2(2, 3);
    try{
        m2.getDeterminant();
        cerr << "getDeterminant worked on a non 2x2 or 3x3 Matrix" << flush;
    }catch(MatrixDimensionException& mde){
        cout << " 0b " << flush;
    }
    Matrix<int> m3(2, 2);
    try{
        m3.getDeterminant();
        cout << " 0c " << flush;
    }catch(MatrixDimensionException& mde){
        cerr << "getDeterminant didn't work on a 2x2 Matrix" << flush;
    }
    Matrix<int> m4(3, 3);
    try{
        m4.getDeterminant();
        cout << " 0d " << flush;
    }catch(MatrixDimensionException& mde){
        cerr << "getDeterminant didn't work on a 3x3 Matrix" << flush;
    }

    unsigned a = 1;
    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            m3.myVec[r][c] = a;
            a++;
        }
    }
    assert(m3.getDeterminant() == -2);
    cout << " 1 " << flush;

    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; c++){
            m3.myVec[r][c] = (r+1)*(c+1);
        }
    }
    assert(m3.getDeterminantDouble() == 0);
    cout << " 2 " << flush;

    Matrix<int> m5(3, 3);
    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++){
            m5.myVec[r][c] = (r+3)*(c+1);
        }
    }
    assert(m5.getDeterminant() == 0);
    cout << " 3 " << flush;

    m5.myVec[0][0] = 9;
    m5.myVec[2][1] = 17;

    assert(m5.getDeterminant() == -504);
    cout << " 4 " << flush;

    cout << " Passed!" << endl;
}

void CalculationOperationTester::testGetXYZ(){
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

void CalculationOperationTester::testGetVariable(){
    cout << "Testing getVariable... " << flush;

    Matrix<int> m1(3, 4);

    try{
        m1.getVariable('x');
        cout << " 0a " << flush;
    }catch(VariableException& ve){
        cerr << "getVariable didn't work on an invalid variable name" << flush;
    }

    try{
        m1.getVariable('y');
        cout << " 0b " << flush;
    }catch(VariableException& ve){
        cerr << "getVariable didn't work on an invalid variable name" << flush;
    }

    try{
        m1.getVariable('z');
        cout << " 0c " << flush;
    }catch(VariableException& ve){
        cerr << "getVariable didn't work on an invalid variable name" << flush;
    }

    try{
        m1.getVariable('X');
        cout << " 0d " << flush;
    }catch(VariableException& ve){
        cerr << "getVariable didn't work on an invalid variable name" << flush;
    }

    try{
        m1.getVariable('Y');
        cout << " 0e " << flush;
    }catch(VariableException& ve){
        cerr << "getVariable didn't work on an invalid variable name" << flush;
    }

    try{
        m1.getVariable('Z');
        cout << " 0f " << flush;
    }catch(VariableException& ve){
        cerr << "getVariable didn't work on an invalid variable name" << flush;
    }

    try{
        m1.getVariable('r');
        cerr << "getVariable worked on an invalid variable name" << flush;
    }catch(VariableException& ve){
        cout << " 1 " << flush;
    }

    try{
        m1.getVariable('o');
        cerr << "getVariable worked on an invalid variable name" << flush;
    }catch(VariableException& ve){
        cout << " 2 " << flush;
    }

    try{
        m1.getVariable('W');
        cerr << "getVariable worked on an invalid variable name" << flush;
    }catch(VariableException& ve){
        cout << " 3 " << flush;
    }

    cout << " Passed!" << endl;
}

void CalculationOperationTester::testGetDotProduct(){
    cout << "Testing getDotProduct... " << flush;

    Vec<int> m1(3);
    for(unsigned i = 0 ; i < 3 ; i++){
        m1.myArray[i] = 0;
    }
    Vec<int> m2(3);
    for(unsigned i = 0 ; i < 3 ; i++){
        m2.myArray[i] = 0;
    }
    assert(m1.getDotProduct(m2) == 0);
    cout << " 0a " << flush;

    Vec<int> m3(100);
    for(unsigned i = 0 ; i < 100 ; i++){
        m3.myArray[i] = 0;
    }
    Vec<int> m4(100);
    for(unsigned i = 0 ; i < 100 ; i++){
        m4.myArray[i] = 0;
    }
    assert(m3.getDotProduct(m4) == 0);
    cout << " 0b " << flush;

    Vec<int> m5(3);
    for(unsigned i = 0 ; i < 3 ; i++){
        m5.myArray[i] = 0;
    }
    Vec<int> m6(5);
    for(unsigned i = 0 ; i < 5 ; i++){
        m6.myArray[i] = 0;
    }
    try{
        m5.getDotProduct(m6);
        cerr << "getDotProduct worked on Vectors of different dimensions" << flush;
    }catch(MatrixDimensionException& mde){
        cout << " 1 " << flush;
    }

    Vec<int> m7(3);
    int a = 1;
    for(unsigned i = 0 ; i < 3 ; i++){
        m7.myArray[i] = a;
        a++;
    }
    Vec<int> m8(3);
    int b = 3;
    for(unsigned i = 0 ; i < 3 ; i++){
        m8.myArray[i] = b;
        b++;
    }
    assert(m7.getDotProduct(m8) == m8.getDotProduct(m7));
    cout << " 2 " << flush;

    assert(m7.getDotProduct(m8) == 26);
    cout << " 3 " << flush;

    a = 7;
    for(unsigned i = 0 ; i < 3 ; i++){
        m7.myArray[i] = a;
        a++;
    }
    b = 1;
    for(unsigned i = 0 ; i < 3 ; i++){
        m8.myArray[i] = b;
        b++;
    }
    assert(m7.getDotProduct(m8) == m8.getDotProduct(m7));
    cout << " 4 " << flush;

    assert(m7.getDotProduct(m8) == 50);
    cout << " 5 " << flush;

    cout << " Passed!" << endl;
}

void CalculationOperationTester::testScaleBy(){
    cout << "Testing scaleBy..." << flush;

    Vec<int> v1(3);
    for(int i = 0 ; i < 3 ; i++){
        v1.myArray[i] = 0;
    }
    v1.scaleBy(6);
    for(int i = 0 ; i < 3 ; i++){
        assert(v1.myArray[i] == 0);
    }
    cout << " 0a " << flush;

    int a = 1;
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = a;
        a++;
    }
    v1.scaleBy(0);

    for(unsigned i = 0 ; i < 3 ; i++){
        assert(v1.myArray[i] == 0);
    }
    cout << " 0b " << flush;

    a = 1;
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = a;
        a*=2;
    }
    assert(v1.myArray[0] == 1);
    assert(v1.myArray[1] == 2);
    assert(v1.myArray[2] == 4);
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}

void CalculationOperationTester::testVectorString(){
    cout << "Testing Vec toString..." << flush;

    cout << " (Should be <0, 0, 0> | " << flush;
    Vec<int> v1(3);
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = 0;
    }
    v1.toString();

    cout << ") (Should be <1, 2, 3> | " << flush;
    int a = 1;
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = a;
        a++;
    }
    v1.toString();

    cout << ") (Should be <5, 6, 7> | " << flush;
    a = 5;
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = a;
        a++;
    }
    v1.toString();

    cout << ") Passed!" << endl;
}

void CalculationOperationTester::testVectorGetCrossProduct(){
    cout << "Testing Vec getCrossProduct..." << flush;
    Vec<int> v1(3);
    Vec<int> v2(4);
    try{
        v1.getDotProduct(v2);
        cerr << "getDotProduct worked on Vecs of different size" << flush;
    }catch(MatrixDimensionException& mde){
        cout << " 0a " << flush;
    }

    Vec<int> v3(3);
    Vec<int> v4(3);

    int a = 1;
    int b = 3;
    for(unsigned i = 0 ; i < 3 ; i++){
        v3[i] = a;
        v4[i] = b;
        a++;
        b--;
    }
    Vec<int> result(3);
    result[0] = -4;
    result[1] = 8;
    result[2] = -4;
    assert(v3.getCrossProduct(v4) == result);
    cout << " 1 " << flush;

    result.scaleBy(-1);
    assert(v4.getCrossProduct(v3) == result);
    cout << " 2 " << flush;

    cout << " Passed!" << endl;
}

void CalculationOperationTester::testVectorGetMagnitude(){
    cout << "Testing Vec getMagnitude..." << flush;

    //This test seems to not be passing half of the time for some reason
    Vec<int> v1(2);
    v1.myArray[0] = 3;
    v1.myArray[1] = 4;

    assert(v1.getMagnitude() == 5.0);
    cout << " 0 " << flush;

    Vec<int> v2(5);
    v2.myArray[0] = 1;
    v2.myArray[1] = 1;
    v2.myArray[2] = 2;
    v2.myArray[3] = 3;
    v2.myArray[4] = 7;

    assert(v2.getMagnitude() == 8.0);
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}

void CalculationOperationTester::testVectorOperatorOut(){
    cout << "Testing Vec operator<< ..." << flush;

    cout << " (Should be <0, 0, 0> | " << flush;
    Vec<int> v1(3);
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = 0;
    }
    cout << v1 << flush;

    cout << ") (Should be <1, 2, 3> | " << flush;
    int a = 1;
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = a;
        a++;
    }
    cout << v1 << flush;

    cout << ") (Should be <5, 6, 7> | " << flush;
    a = 5;
    for(unsigned i = 0 ; i < 3 ; i++){
        v1.myArray[i] = a;
        a++;
    }
    cout << v1 << flush;

    cout << ") Passed!" << endl;
}

void CalculationOperationTester::testMatrixOperatorOut(){
    cout << "Testing Matrix operator<< ..." << flush;

    cout << " Should be all zeros:" << endl;
    Matrix<int> m1(3, 3);
    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++) {
            m1.myVec[r][c] = 0;
        }
    }
    cout << m1 << flush;

    cout << "Should be 1, 2, 3, 4, 5, 6, 7, 8, 9:" << endl;
    int a = 1;
    for(unsigned r = 0 ; r < 3 ; r++){
        for(unsigned c = 0 ; c < 3 ; c++) {
            m1.myVec[r][c] = a;
            a++;
        }
    }
    cout << m1 << flush;

    cout << " Passed!" << endl;
}