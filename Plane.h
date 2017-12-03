/* Plane.h defines Plane class methods.
 * Made by Mason VanMeurs
 * Student at Calvin College in Grand Rapids Michigan
 * Date:12/2/17
 */

#ifndef MATRIXOPERATIONS_PLANE_H
#define MATRIXOPERATIONS_PLANE_H

#include <cstdlib>

using namespace std;

template<class Item>

class Plane {
public:
    Plane();
    Plane(double&, double&, double&, Item&);
    ~Plane();
    double getX() const;
    double getY() const;
    double getZ() const;
    Item getMyEqualsTo() const;
private:
    double myX;
    double myY;
    double myZ;
    Item myEqualsTo;
};

template<class Item>
Plane<Item>::Plane() {
    myX = myY = myZ = myEqualsTo = 0;
}

template<class Item>
Plane<Item>::Plane(double& myx, double& myy, double& myz, Item& myequals) {
    myX = myx;
    myY = myy;
    myZ = myz;
    myEqualsTo = myequals;
}

template<class Item>
Plane<Item>::~Plane() {
    myX = myY = myZ = myEqualsTo = 0;
}

template<class Item>
double Plane<Item>::getX() const{return myX;}

template<class Item>
double Plane<Item>::getY() const{return myY;}

template<class Item>
double Plane<Item>::getZ() const{return myZ;}

template<class Item>
double Plane<Item>::getMyEqualsTo() const{return myEqualsTo;}


#endif //MATRIXOPERATIONS_PLANE_H
