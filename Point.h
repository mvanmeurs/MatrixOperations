/* Point.h defines Point class methods.
 * Made by Mason VanMeurs
 * Student at Calvin College in Grand Rapids Michigan
 * Date:12/2/17
 */

#ifndef MATRIXOPERATIONS_POINT_H
#define MATRIXOPERATIONS_POINT_H

#include <cstdlib>
#include "Vec.h"

using namespace std;

template<class Item>

class Point {
public:
    Point(Item, Item);
    Point(Item, Item, Item);
    ~Point();
    Vec<Item> getX() const;
    Vec<Item> getY() const;
    Vec<Item> getZ() const;
    void WriteToOperator(ostream &out) const;
private:
    //enum { SIZE = 3 };
    Vec<Item> myVec;
    friend class PointTester;
};

template<class Item>
Point<Item>::Point(Item myx, Item myy) {
    myVec.setSize(3);
    myVec[0] = myx;
    myVec[1] = myy;
    myVec[2] = 0;
}

template<class Item>
Point<Item>::Point(Item myx, Item myy, Item myz) {
    myVec.setSize(3);
    myVec[0] = myx;
    myVec[1] = myy;
    myVec[2] = myz;
}

template<class Item>
Point<Item>::~Point() {
    myVec.~Vec();
}

template<class Item>
Vec<Item> Point<Item>::getX() const{return myVec[0];}

template<class Item>
Vec<Item> Point<Item>::getY() const{return myVec[1];}

template<class Item>
Vec<Item> Point<Item>::getZ() const{return myVec[2];}

template<class Item>
void Point<Item>::WriteToOperator(ostream &out) const{
    out << "(" << flush;
    for (int i = 0; i < myVec.getSize(); ++i){
        out << myVec[i];
        if(i<myVec.getSize()-1){out << ", " << flush;}
    }
    out << ")" << flush;
}

template<class Item>
ostream& operator<<(ostream& out, const Point<Item>& plane){
    plane.WriteToOperator(out);
    return out;
}

#endif //MATRIXOPERATIONS_POINT_H
