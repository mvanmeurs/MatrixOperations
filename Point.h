/* Point.h defines Plane class methods.
 * Made by Mason VanMeurs
 * Student at Calvin College in Grand Rapids Michigan
 * Date:12/2/17
 */

#ifndef MATRIXOPERATIONS_POINT_H
#define MATRIXOPERATIONS_POINT_H

#include <cstdlib>

using namespace std;

template<class Item>

class Point {
public:
    Point();
    Point(Item&, Item&);
    Point(Item&, Item&, Item&);
    ~Point();
    Item getX() const;
    Item getY() const;
    Item getZ() const;
private:
    Item myX;
    Item myY;
    Item myZ;
};

template<class Item>
Point<Item>::Point() {
    myX = myY = myZ = 0;
}

template<class Item>
Point<Item>::Point(double& myx, double& myy) {
    myX = myx;
    myY = myy;
    myZ = 0;
}

template<class Item>
Point<Item>::Point(double& myx, double& myy, double& myz) {
    myX = myx;
    myY = myy;
    myZ = myz;
}

template<class Item>
Point<Item>::~Point() {
    myX = myY = myZ = 0;
}

template<class Item>
double Point<Item>::getX() const{return myX;}

template<class Item>
double Point<Item>::getY() const{return myY;}

template<class Item>
double Point<Item>::getZ() const{return myZ;}

#endif //MATRIXOPERATIONS_POINT_H
