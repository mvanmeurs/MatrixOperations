#include <iostream>
#include "VecTester.h"
#include "MatrixTester.h"
#include "CalculatorOperationTester.h"
#include "PointTester.h"
#include "Calculator.h"

using namespace std;

int main() {
    VecTester vc;
    vc.runTests();
    MatrixTester mt;
    mt.runTests();
    CalculationOperationTester mot;
    PointTester pt;
    //MatrixCalculator mc;
    return 0;
}