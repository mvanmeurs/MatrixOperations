/* Plane.h defines Plane class methods.
 * Made by Mason VanMeurs
 * Student at Calvin College in Grand Rapids Michigan
 * Date:12/2/17
 */

#ifndef MATRIXOPERATIONS_PLANE_H
#define MATRIXOPERATIONS_PLANE_H

#include "Vec.h"
#include <cstdlib>
#include "math.h"

using namespace std;

template<class Item>

class Plane {
public:
    Plane(Item, Item, Item);
    Plane(Item, Item, Item, Item);
    ~Plane();
    Vec<Item> getX() const;
    Vec<Item> getY() const;
    Vec<Item> getZ() const;
    Vec<Item> getMyEqualsTo() const;
    void setX(const Item&);
    void setY(const Item&);
    void setZ(const Item&);
    void setEqualsTo(const Item&);
    void WriteToOperator(ostream &out) const;
private:
    Vec<Item> myVec;
};

template<class Item>
Plane<Item>::Plane(Item myx, Item myy, Item myz) {
    myVec[0] = myx;
    myVec[1] = myy;
    myVec[2] = myz;
    myVec[3] = 0;
}

template<class Item>
Plane<Item>::Plane(Item myx, Item myy, Item myz, Item myequals) {
    myVec[0] = myx;
    myVec[1] = myy;
    myVec[2] = myz;
    myVec[3] = myequals;
}

template<class Item>
Plane<Item>::~Plane() {
    myVec.~Vec();
}

template<class Item>
Vec<Item> Plane<Item>::getX() const{
    Vec<Item> result(4);
    result[0] = myVec[0];
    result[1] = result[2] = result[3] = 0;
    return result;
}

template<class Item>
Vec<Item> Plane<Item>::getY() const{
    Vec<Item> result(4);
    result[1] = myVec[1];
    result[0] = result[2] = result[3] = 0;
    return result;
}

template<class Item>
Vec<Item> Plane<Item>::getZ() const{
    Vec<Item> result(4);
    result[2] = myVec[2];
    result[0] = result[1] = result[3] = 0;
    return result;
}

template<class Item>
Vec<Item> Plane<Item>::getMyEqualsTo() const{
    Vec<Item> result(4);
    result[3] = myVec[3];
    result[0] = result[1] = result[2] = 0;
    return result;
}

template<class Item>
void Plane<Item>::setX(const Item& setX){
    myVec[0] = setX;
}

template<class Item>
void Plane<Item>::setY(const Item& setY){
    myVec[1] = setY;
}

template<class Item>
void Plane<Item>::setZ(const Item& setZ){
    myVec[2] = setZ;
}

template<class Item>
void Plane<Item>::setEqualsTo(const Item& setequals){
    myVec[3] = setequals;
}

template<class Item>
void Plane<Item>::WriteToOperator(ostream &out) const{
    //is x coefficient negative
    if(myVec[0] < 0){out << " - " << flush;}
    else{out << " + " << flush;}
    out << abs(myVec[0]) << flush;
    //is x not zero
    if(myVec[0] != 0){out << "X " << flush;}

    //is y coefficient negative
    if(myVec[1] < 0){out << " - " << flush;}
    else{out << " + " << flush;}
    out << abs(myVec[1]) << flush;
    //is y not zero
    if(myVec[1] != 0){out << "Y " << flush;}

    //is z coefficient negative
    if(myVec[2] < 0){out << " - " << flush;}
    else{out << " + " << flush;}
    out << abs(myVec[2]) << flush;
    //is z not zero
    if(myVec[2] != 0){out << "Z " << flush;}
    out << " = " << flush;
    out << myVec[3] << flush;
}

template<class Item>
ostream& operator<<(ostream& out, const Plane<Item>& plane){
    plane.WriteToOperator(out);
    return out;
}


#endif //MATRIXOPERATIONS_PLANE_H
