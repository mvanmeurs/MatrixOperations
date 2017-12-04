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
    Plane(Item, Item, Item, Item);
    ~Plane();
    Item getx() const;
    Item gety() const;
    Item getz() const;
    Vec<Item> getX() const;
    Vec<Item> getY() const;
    Vec<Item> getZ() const;
    Item getMyEqualsTo() const;
    Vec<Item> getCoefficients() const;
    void setX(const Item&);
    void setY(const Item&);
    void setZ(const Item&);
    void setEqualsTo(const Item&);
    bool operator==(const Plane<Item>&) const;
    bool operator!=(const Plane<Item>&) const;
    Plane<Item>& operator=(const Plane<Item>&);
    void WriteToOperator(ostream &out) const;
private:
    Vec<Item> myVec;
    friend class PlaneTester;
};

template<class Item>
Plane<Item>::Plane(Item myx, Item myy, Item myz, Item myequals) {
    myVec.setSize(4);
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
Item Plane<Item>::getx() const{return myVec[0];}

template<class Item>
Item Plane<Item>::gety() const{return myVec[1];}

template<class Item>
Item Plane<Item>::getz() const{return myVec[2];}

template<class Item>
Vec<Item> Plane<Item>::getX() const{
    Vec<Item> result(3);
    result[0] = myVec[0];
    result[1] = result[2] = 0;
    return result;
}

template<class Item>
Vec<Item> Plane<Item>::getY() const{
    Vec<Item> result(3);
    result[1] = myVec[1];
    result[0] = result[2] = 0;
    return result;
}

template<class Item>
Vec<Item> Plane<Item>::getZ() const{
    Vec<Item> result(3);
    result[2] = myVec[2];
    result[0] = result[1] = 0;
    return result;
}

template<class Item>
Item Plane<Item>::getMyEqualsTo() const{return myVec[3];}

template<class Item>
Vec<Item> Plane<Item>::getCoefficients() const{
    Vec<Item> result(3);
    result[0] = myVec[0];
    result[1] = myVec[1];
    result[2] = myVec[2];
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
bool Plane<Item>::operator==(const Plane<Item>& rhs) const{
    if(myVec == rhs.myVec){return true;}
    else{return false;}
}

template<class Item>
bool Plane<Item>::operator!=(const Plane<Item>& rhs) const{
    if(myVec == rhs.myVec){return false;}
    else{return true;}
}

template<class Item>
Plane<Item>& Plane<Item>::operator=(const Plane<Item>& rhs){
    if(myVec == rhs.myVec){return *this;}
    for(int i = 0 ; i<4 ; i++){
        myVec[i] = rhs.myVec[i];
    }
    return *this;
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
