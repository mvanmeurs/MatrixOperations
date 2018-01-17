//
// Created by mason on 1/17/18.
//

#ifndef MATRIXOPERATIONS_PARAVEC_H
#define MATRIXOPERATIONS_PARAVEC_H

#include <iostream>
#include "Vec.h"
#include "Point.h"

using namespace std;

template<class Item>

class ParaVec {
public:
    ParaVec();
    void scan();
private:
    Point<Item> myPoint;
    Vec<Item> myCoefficients;
    void WriteToOperator(ostream &out) const;
    //friend class ParaVecTester;
};

template<class Item>
ParaVec<Item>::ParaVec() {
    myCoefficients.setSize(3);
}

template<class Item>
void ParaVec<Item>::scan() {
    cout << "Please enter a Point on your Vector:" << endl;
    myPoint.scan();
    myCoefficients.scan();
}

template<class Item>
void ParaVec<Item>::WriteToOperator(ostream &out) const{
    out << myPoint << " + t" << myCoefficients << flush;
}

template<class Item>
ostream& operator<<(ostream& out, const ParaVec<Item>& paravec){
    paravec.WriteToOperator(out);
    return out;
}

#endif //MATRIXOPERATIONS_PARAVEC_H
