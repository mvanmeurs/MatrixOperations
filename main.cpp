#include <iostream>
#include "VecTester.h"
#include "MatrixTester.h"
#include "CalculatorOperationTester.h"
#include "PointTester.h"
#include "PlaneTester.h"
#include "Calculator.h"

using namespace std;

int main() {
    VecTester vc;
    vc.runTests();
    MatrixTester mt;
    mt.runTests();
    CalculationOperationTester mot;
    PointTester pt;
    PlaneTester Pt;
    //MatrixCalculator mc;
    return 0;
}