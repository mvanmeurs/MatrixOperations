/* Point.h defines Point class methods.
 * Made by Mason VanMeurs
 * Student at Calvin College in Grand Rapids Michigan
 * Date:12/2/17
 */

#ifndef MATRIXOPERATIONS_POINT_H
#define MATRIXOPERATIONS_POINT_H

#include <cstdlib>
#include "Vec.h"
#include "PointException.h"

using namespace std;

template<class Item>

class Point {
public:
    Point(Item, Item);
    Point(Item, Item, Item);
    ~Point();
    Item getX() const;
    Item getY() const;
    Item getZ() const;
    void setX(const Item& item);
    void setY(const Item& item);
    void setZ(const Item& item);
    bool operator==(const Point<Item>&) const;
    bool operator!=(const Point<Item>&) const;
    Point<Item>& operator=(const Point<Item>&);
    void WriteToOperator(ostream &out) const;
private:
    bool isTwoDimensional = false;
    Vec<Item> myVec;
    friend class PointTester;
};

template<class Item>
Point<Item>::Point(Item myx, Item myy) {
    myVec.setSize(3);
    myVec[0] = myx;
    myVec[1] = myy;
    myVec[2] = 0;
    isTwoDimensional = true;
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
Item Point<Item>::getX() const{return myVec[0];}

template<class Item>
Item Point<Item>::getY() const{return myVec[1];}

template<class Item>
Item Point<Item>::getZ() const{
    if(isTwoDimensional){throw PointException("getZ", "Tried to get Z on a Point of two dimensions");}
    return myVec[2];
}

template<class Item>
void Point<Item>::setX(const Item& item) {myVec[0] = item;}

template<class Item>
void Point<Item>::setY(const Item& item) {myVec[1] = item;}

template<class Item>
void Point<Item>::setZ(const Item& item) {
    if(isTwoDimensional){throw PointException("setZ", "Tried to set Z on a Point of two dimensions");}
    myVec[2] = item;
}

template<class Item>
bool Point<Item>::operator==(const Point<Item>& rhs) const{
    return myVec == rhs.myVec;
}

template<class Item>
bool Point<Item>::operator!=(const Point<Item>& rhs) const{
    if(myVec == rhs.myVec){return false;}
    return true;
}

template<class Item>
Point<Item>& Point<Item>::operator=(const Point<Item>& rhs){
    if(myVec == rhs.myVec){return *this;}
    for(int i = 0 ; i<3 ; i++){
        myVec[i] = rhs.myVec[i];
    }
    return *this;
}

template<class Item>
void Point<Item>::WriteToOperator(ostream &out) const{
    out << "(" << flush;
    for (int i = 0; i < myVec.getSize(); ++i){
        out << myVec[i];
        if( i == 1 && isTwoDimensional){break;}
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
