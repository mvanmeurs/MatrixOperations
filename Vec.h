/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <cassert>

using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	Vec(unsigned);
	Vec(const Vec<Item>&);
	virtual ~Vec();
	Vec<Item>& operator=(const Vec<Item>&);
	unsigned getSize() const;
	void setItem(unsigned, const Item&);
	Item getItem(unsigned) const;
	void setSize(unsigned);
	bool operator==(const Vec<Item>&) const;
	void writeTo(ostream&) const;
	void readFrom(istream&);
	bool operator!=(const Vec<Item>&);
	void readFrom(const string&);
	void writeTo(const string&);
	Vec<Item> operator+(const Vec<Item>&);
	Vec<Item> operator-(const Vec<Item>&);
	double operator*(const Vec<Item>&);
	Item& operator[](unsigned);
	const Item& operator[](unsigned) const;
private:
	unsigned mySize;
	Item* myArray;
	friend class VecTester;
};

/* Vec default constructor
 * @param: none
 * Initializes Vec to size zero and the pointer to Null
 */
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

/* Vec explicit constructor
 * @param: size, an unsigned
 * Initializes Vec to a size of size if size is greater than zero, else sets size to zero and the pointer to Null.
 */
template<class Item>
Vec<Item>::Vec(unsigned size){
	mySize = size;
	if(size>0){
		myArray = new Item[mySize];
		for(int i = 0 ; i<mySize ; i++){
			myArray[i] = 0;
		}
	}
	else{
		Vec();
	}
}

/* Vec copy constructor
 * @param: original, a Vec
 * Creates a copy of original.
 */
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	if(original.mySize > 0){
		myArray = new Item[mySize];
		for(int i = 0 ; i<original.mySize ; i++){
			myArray[i] = original.myArray[i];
		}
	}
	else{
		myArray = NULL;
	}
}

/* Vec destructor
 * @param: none
 * Deletes the array, sets the array pointer to Null, sets the mySize to 0.
 */
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	mySize = 0;
	myArray = NULL;
}

/* operator=
 * @param: original, a Vec
 * iterates through all values in myArray, checking if they are all equal to each value in original.
 * returns: a Vec
 */
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if(myArray == original.myArray){return *this;}
    delete [] myArray;
    mySize = original.mySize;
    myArray = new Item[mySize];
    if(original.mySize == 0){myArray = NULL;}
    else{
    	for(int i = 0 ; i<original.mySize ; i++){
		myArray[i] = original.myArray[i];
    	}
    }
	return *this;
 }

/* getSize
 * @param: none
 * Returns: the size of the vector, mySize.
 */
template<class Item>
unsigned Vec<Item>::getSize() const{
	return mySize;
}

/* setItem
 * @param: index, an unsigned; it, an Item
 * Sets the value at index to it.
 */
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if(mySize == 0){throw range_error("Array has size 0");}
	else if(index > mySize-1){throw range_error("index must be less than the arrays size");}
	else{myArray[index] = it;}
}

/* getItem
 * @param: index, an unsigned
 * Returns: an Item at index.
 */
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if(mySize == 0){throw range_error("Array has size 0");}
	else if(index > mySize-1){throw range_error("index must be less than the arrays size");}
	else{return myArray[index];}
}

/* setSize
 * @param: newSize, an unsigned
 * Creates a new array of size, newSize. Copy's all values from myArray into newArray.
 * If newArray is larger than myArray, all extra values are set to zero.
 * If newArray is smaller than myArray, extra values are discarded.
 * myArray is deleted, the reference to newArray is set into myArray
 */
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {

	if (newSize == 0){
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
	}
	else if(mySize != newSize){
		Item * newArray = new Item[newSize]();
		if (mySize < newSize) {
			for (int i = 0; i < mySize; i++) {
				newArray[i] = myArray[i];
			}
//			for (int i = mySize; i < newSize; i++) {
//				newArray[i] = 0;
//			}
		} else {

			for (int i = 0; i < newSize; i++) {
				newArray[i] = myArray[i];
			}
		}
		mySize = newSize;
		delete[] myArray;
		myArray = newArray;
	}
}

/* operator==
 * @param: v2, a Vec
 * Returns: a boolean if myArray is equal to v2. If mySize isn't equal to v2's size, the arrays can't be the same.
 * If they are of the same size, we iterate through each array, testing if each value is equivalent.
 */
template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const{
	if(mySize != v2.getSize()){
		return false;
	}
	else{
		for(int i = 0 ; i<mySize ; i++){
				if(myArray[i] != v2.getItem(i)){
					return false;
				}
			}
	}
	return true;
}

/* writeTo
 * @param: out, an ostream
 * Writes each value in the array into a single text file.
 */
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for(int i = 0 ; i<mySize ; i++){
		out << myArray[i] << endl;
	}
}

/* readFrom
 * @param: in, an istream
 * Reads each value from a text file.
 */
template<class Item>
void Vec<Item>::readFrom(istream& in){
	for(int i = 0 ; i<mySize ; i++){
		in >> myArray[i];
	}
}

/* operator[] retrieve
 * @param: index, an unsigned
 * Returns: An item at index: index, in myArray.
 */
template<class Item>
Item& Vec<Item>::operator[](unsigned index){
	if(index >= mySize){throw range_error("index must be less than the arrays size");}
	return myArray[index];
}

/* operator[] set
 * @param: index, an unsigned
 * Returns: An item at index: index, in myArray.
 */
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if(index >= mySize){throw range_error("index must be less than the arrays size");}
	return myArray[index];
}

/* operator!=
 * @param: v2, a Vec
 * Returns: True if v2 and myArray aren't equal.
 */
template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2){
	if(mySize != v2.getSize()){
		return true;
	} else {
		for (int i = 0; i < mySize; i++) {
			if (myArray[i] != v2.getItem(i)) {
				return true;
			}
		}
	return false;
	}
}

/* readFrom
 * @param: filename, a string
 * Reads Items from filename, making an array of Items of size from the first line.
 */
template<class Item>
void Vec<Item>::readFrom(const string& filename){
	ifstream fin(filename.c_str());
	assert( fin.is_open() );

	unsigned newSize = 0;
	fin >> newSize;

	Item * newArray = new Item[newSize]();

	for(unsigned i = 0 ; i<newSize ; i++){
		fin >> newArray[i];
	}


	mySize = newSize;
	myArray = newArray;

	fin.close();
}

/* writeTo
 * @param: filename, a string
 * Writes Items from filename, making an array of Items of size from
 * the first line with the amount of items in the file on the first line.
 */
template<class Item>
void Vec<Item>::writeTo(const string& filename){
	ofstream fout(filename.c_str());
	assert( fout.is_open() );

	fout << mySize << endl;

	for(unsigned i = 0 ; i<mySize ; i++){
		fout << myArray[i] << endl;
	}

	fout.close();
}

/* operator+
 * @param: v2, a Vec
 * Returns: a Vec, the addition of myArray and v2.
 */
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2){
	if(v2.mySize != mySize){
		throw invalid_argument("Vectors aren't the same size.");
	}else{
		Vec newvec(mySize);
		for(unsigned i = 0 ; i<mySize ; i++){
			newvec.myArray[i] = (myArray[i] + v2.myArray[i]);
		}
		return newvec;
	}
}

/* operator-
 * @param: v2, a Vec
 * Returns: a Vec, the subraction of myArray and v2.
 */
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2){
	if(v2.mySize != mySize){
		throw invalid_argument("Vectors aren't the same size.");
	}else{
		Vec newvec(mySize);
		for(unsigned i = 0 ; i<mySize ; i++){
			newvec.myArray[i] = (myArray[i] - v2.myArray[i]);
		}
		return newvec;
	}
}

/* operator*
 * @param: v2, a Vec
 * Returns: a double, dot product of myArray and v2.
 */
template<class Item>
double Vec<Item>::operator*(const Vec<Item>& v2){
	if(v2.mySize != mySize){
		throw invalid_argument("Vectors aren't the same size.");
	} else {
		Vec newvec(mySize);
		double product = 0;
		for (unsigned i = 0; i < mySize; i++) {
			product += (myArray[i] * v2.myArray[i]);
		}
		return product;
	}
}

#endif /*VEC_H_*/