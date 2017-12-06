#include <iostream>
#include "VecTester.h"
#include "MatrixTester.h"
#include "CalculatorOperationTester.h"
#include "PointTester.h"
#include "PlaneTester.h"
#include "Menu.h"

using namespace std;

int main() {
    VecTester vc;
    vc.runTests();
    cout << endl;
    MatrixTester mt;
    mt.runTests();
    cout << endl;
    CalculationOperationTester mot;
    cout << endl;
    PointTester pt;
    cout << endl;
    PlaneTester Pt;
    MatrixCalculator mc;
    return 0;
}