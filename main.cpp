#include <iostream>
#include "VecTester.h"
#include "MatrixTester.h"
#include "MatrixOperationTester.h"
#include "Calculator.h"

using namespace std;

int main() {
    VecTester vc;
    vc.runTests();
    MatrixTester mt;
    mt.runTests();
    MatrixOperationTester mot;
    MatrixCalculator mc;
    return 0;
}