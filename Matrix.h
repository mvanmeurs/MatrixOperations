/* Matrix.h defines Matrix class methods.
 * Student 2 Name: Mason VanMeurs
 * Student 2 methods: Everything Professor Adams didn't do
 * Student 1 Name: Joel Adams
 * Student 1 methods:operator!=, readFrom(istream), writeTo(filename), operator+
 * Date:10/3/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Added to by: Mason VanMeurs
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstdlib>

#include "Vec.h"
#include "MatrixDimensionException.h"
#include "TypeDefException.h"
#include "VariableException.h"

using namespace std;

template<class Item>

class Matrix {
public:
	Matrix();
	Matrix(unsigned, unsigned);
	unsigned getRows() const;
	unsigned getColumns() const;
	const Vec<Item>& operator[](unsigned) const;
	Vec<Item>& operator[](unsigned);
	bool operator==(const Matrix<Item>&) const;
	bool operator!=(const Matrix<Item>&) const;
	void readFrom(istream&);
	void writeTo(ostream&);
	void writeTo(const string&) const;
	void readFrom(const string&);
	Matrix<Item> operator+(const Matrix<Item>&) const;
	Matrix<Item> operator-(const Matrix<Item>&) const;
	Matrix<Item> operator*(const Matrix<Item>&) const;
	Matrix<Item> getTranspose() const;
	void toString() const;
    Item getDeterminant() const;
    Item getVariable(const char&) const;
    void scan();
	void WriteToOperator(ostream &out) const;
private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
    Item getDeterminantTriple() const;
    Item getDeterminantDouble() const;
    Item getX() const;
    Item getY() const;
    Item getZ() const;
	friend class MatrixTester;
    friend class CalculationOperationTester;
};

/* Default Constructor
 * @param: none
 * Sets myRows and myColumns to zero.
 */
template<class Item>
Matrix<Item>::Matrix() {
	//if(mytype is unsigned){throw TypeDefException("Matrix: ", "Type can't be unsigned");}
	myRows = myColumns = 0;
}

/* Explicit Constructor
 * @param: rows, an unsigned; columns, an unsigned
 * Sets myRows to rows, sets myColumns to columns, sets the row array to
 * size of rows,and sets each array in the row array to a size of columns.
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
    //if(rows == 0 || columns == 0){throw MatrixDimensionException("Matrix()", "matrix dimensions must both be larger than 0");}
	//if(mytype is unsigned){throw TypeDefException("Matrix: ", "Type can't be unsigned");}
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/* getRows
 * @param: none
 * Returns: myRows, an unsigned.
 */
template<class Item>
unsigned Matrix<Item>::getRows() const{
	return myRows;
}

/* getColumns
 * @param: none
 * Returns: myColumns, an unsigned.
 */
template<class Item>
unsigned Matrix<Item>::getColumns() const{
	return myColumns;
}

/* operator[]
 * @param: index, an unsigned
 * Returns: A Vec if index is greater than or equal to zero.
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const{
	if(index < 0){
		throw range_error("operator[] Index must be greater than or equal to zero.");
	}
	else{
		return myVec[index];
	}
}

/* operator[]
 * @param: index, an unsigned
 * Returns: A Vec if index is greater than or equal to zero.
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index){
	if(index < 0){
		throw range_error("operator[] Index must be greater than or equal to zero.");
	} else {
		return myVec[index];
	}
}

/* operator==
 * @param: m2, a Matrix
 * Returns: True if v2 and myMatrix are equal.
 */
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const{
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

/* boolean inequality
 * @parameter: mat2, a Matrix.
 * Return: true, if myRows != mat2.myRows || myColumns != mat2.myColumns
 *               || for all rows r and columns c: if any me[r][c] != mat2[r][c].
 *         false, otherwise.
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& mat2) const {
	return !( (*this) == mat2);
}

/* stream input
 * @parameter: in, an istream.
 * Precondition: in contains myRows x myColumns values.
 * Postcondition: myVec contains the values from in.
 *
 */
template<class Item>
void Matrix<Item>::readFrom(istream& in) {
	for (unsigned r = 0; r < myRows; ++r) {
			for (unsigned c = 0; c < myColumns; ++c) {
				in >> myVec[r][c];
			}
	}
}

/* stream input
 * @parameter: out, an ostream
 * Precondition: out contains myRows x myColumns values.
 * Postcondition: ostream contains values from myVec
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& out) {
	for (unsigned r = 0; r < myRows; ++r) {
		for (unsigned c = 0; c < myColumns; ++c) {
			out << myVec[r][c] << '\t' << flush;
		}
	out << '\n' << flush;
	}
}

/* file output
 * @parameter: fileName, a string.
 * Precondition: fileName contains the name of the desired output file.
 * Postcondition: the first line of fileName contains myRows, a space,
 *                 and myColumns; each subsequent line contains the values
 *                 from one of my rows, in order from row 0..row myRows-1.
 */
template<class Item>
void Matrix<Item>::writeTo(const string& fileName) const {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );
	fout << myRows << ' ' << myColumns;
	for (unsigned r = 0; r < myRows; ++r) {
		for (unsigned c = 0; c < myColumns; ++c) {
			fout << ' ' << myVec[r][c];
		}
		fout << '\n';
	}
	fout.close();
}

/* file input
 * @parameter: fileName, a string.
 * Precondition: fileName contains the name of the desired output file.
 * Postcondition: the first line of fileName contains myRows, a space,
 *                 and myColumns; each subsequent line contains the values
 *                 from one of my rows, in order from row 0..row myRows-1.
 */
template<class Item>
void Matrix<Item>::readFrom(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );
	fin >> myRows;
	fin >> myColumns;
	myVec.setSize(myRows);
	for( unsigned i = 0 ; i<myRows ;i++){
		myVec[i].setSize(myColumns);
		for (unsigned j = 0 ; j<myColumns ; j++){
			fin >> myVec[i][j];
		}
	}
	fin.close();
}

/* Matrix addition
 * @parameter: mat2, a Matrix
 * Precondition: myRows == mat2.getRows() && myColumns == mat2.getColumns().
 * Return: Matrix result, such that for all rows r and columns c,
 *          result[r][c] == me[r][c] + mat2[r][c].
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& mat2) const {
	if (myRows != mat2.getRows() || myColumns != mat2.getColumns() ) {
		throw invalid_argument("Matrix::operator+: Matrix dimensions do not match");
	}
	Matrix result(myRows, myColumns);
	for (unsigned r = 0; r < myRows; ++r) {
		for (unsigned c = 0; c < myColumns; ++c) {
			result[r][c] = (*this)[r][c] + mat2[r][c];
		}
	}
	return result;
}

/* Matrix subtraction
 * @parameter: mat2, a Matrix
 * Precondition: myRows == mat2.getRows() && myColumns == mat2.getColumns().
 * Return: Matrix result, such that for all rows r and columns c,
 *          result[r][c] == me[r][c] - mat2[r][c].
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& mat2) const {
	if (myRows != mat2.getRows() || myColumns != mat2.getColumns() ) {
		throw invalid_argument("Matrix::operator-: Matrix dimensions do not match");
	}
	Matrix result(myRows, myColumns);
	for (unsigned r = 0; r < myRows; ++r) {
		for (unsigned c = 0; c < myColumns; ++c) {
			result[r][c] = (*this)[r][c] - mat2[r][c];
		}
	}
	return result;
}

/* Matrix transpose
 * @parameter: mat2, a Matrix
 * Return: Matrix result, such that for all rows r and columns c,
 *          result[c][r] = this[r][c].
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() const {
	Matrix result(myColumns, myRows);
	for (unsigned c = 0; c < myColumns; ++c){
		for (unsigned r = 0; r < myRows; ++r) {
			result[c][r] = (*this)[r][c];
		}
	}
	return result;
}

/* Matrix toString
 * @parameter: m2, a Matrix
 * Prints the matrix passed in for the application class
 * Return: nothing
 */
template<class Item>
void Matrix<Item>::toString() const{
	cout << "{" << flush;
	for (unsigned r = 0; r < myRows; ++r){
		if(r>0){cout << " " << flush;}
		for (unsigned c = 0; c < myColumns; ++c) {
			cout << (*this)[r][c];
			if(c<myColumns-1){cout << ", " << flush;}
		}
		if(r!=myRows-1){cout << '\n' << flush;}
	}
	cout << "}" << '\n' << flush;
}

template<class Item>
Item Matrix<Item>::getDeterminant() const{
    if(myRows == 2 && myColumns == 2){
        return getDeterminantDouble();
    }
    else if(myRows == 3 && myColumns == 3){
        return getDeterminantTriple();
    }
    else{
        throw MatrixDimensionException("getDeterminant: ", "Dimensions must be 2x2 or 3x3");
    }
}

template<class Item>
Item Matrix<Item>::getDeterminantTriple() const{
    Matrix<Item> m1(2, 2);
    Matrix<Item> m2(2, 2);
    Matrix<Item> m3(2, 2);

    for(Item r = 0 ; r < 2 ; r++){
        for(Item c = 0 ; c < 2 ; c++){
            m1.myVec[r][c] = myVec[r+1][c+1];
        }
    }

    m2.myVec[0][0] = myVec[1][0];
    m2.myVec[0][1] = myVec[1][2];
    m2.myVec[1][0] = myVec[2][0];
    m2.myVec[1][1] = myVec[2][2];

    for(Item r = 0 ; r < 2 ; r++){
        for(Item c = 0 ; c < 2 ; c++){
            m3.myVec[r][c] = myVec[r+1][c];
        }
    }

    return (myVec[0][0]*m1.getDeterminantDouble()) - (myVec[0][1]*m2.getDeterminantDouble()) + (myVec[0][2]*m3.getDeterminantDouble());
}

template<class Item>
Item Matrix<Item>::getDeterminantDouble() const{
    return (myVec[0][0]*myVec[1][1]) - (myVec[1][0]*myVec[0][1]);
}
template<class Item>
Item Matrix<Item>::getVariable(const char& var) const{
    if(tolower(var) == 'x'){return getX();}
    else if(tolower(var) == 'y'){return getY();}
    else if(tolower(var) == 'z'){return getZ();}
    else{throw VariableException("getVariable: ", "variable must be x, y, or z");};
}

template<class Item>
Item Matrix<Item>::getX() const{
	if(myRows != 3 || myColumns != 4){throw MatrixDimensionException("Solve for a variable: ", "must be a 3x4 matrix");}
    Matrix<Item> bottom(3, 3);
    for(Item r = 0 ; r < 3 ; r++){
        for(Item c = 0 ; c < 3 ; c++){
            bottom.myVec[r][c] = myVec[r][c];
        }
    }
    Matrix<Item> top(3, 3);
    for(Item r = 0 ; r < 3 ; r++){
        for(Item c = 1 ; c < 3 ; c++){
            top.myVec[r][c] = myVec[r][c];
        }
    }
    for(Item r = 0 ; r < 3 ; r++){
        top.myVec[r][0] = myVec[r][3];
    }

    if(bottom.getDeterminantTriple() == 0){return 0;}

    return top.getDeterminantTriple()/bottom.getDeterminantTriple();
}

template<class Item>
Item Matrix<Item>::getY() const{
	if(myRows != 3 || myColumns != 4){throw MatrixDimensionException("Solve for a variable: ", "must be a 3x4 matrix");}
    Matrix<Item> bottom(3, 3);
    for(Item r = 0 ; r < 3 ; r++){
        for(Item c = 0 ; c < 3 ; c++){
            bottom.myVec[r][c] = myVec[r][c];
        }
    }
    Matrix<Item> top(3, 3);
    for(Item r = 0 ; r < 3 ; r++){
            top.myVec[r][0] = myVec[r][0];
    }
    for(Item r = 0 ; r < 3 ; r++){
        top.myVec[r][1] = myVec[r][3];
    }
    for(Item r = 0 ; r < 3 ; r++){
        top.myVec[r][2] = myVec[r][2];
    }

    if(bottom.getDeterminantTriple() == 0){return 0;}

    return top.getDeterminantTriple()/bottom.getDeterminantTriple();
}

template<class Item>
Item Matrix<Item>::getZ() const{
	if(myRows != 3 || myColumns != 4){throw MatrixDimensionException("Solve for a variable: ", "must be a 3x4 matrix");}
    Matrix<Item> bottom(3, 3);
    for(Item r = 0 ; r < 3 ; r++){
        for(Item c = 0 ; c < 3 ; c++){
            bottom.myVec[r][c] = myVec[r][c];
        }
    }
    Matrix<Item> top(3, 3);
    for(Item r = 0 ; r < 3 ; r++){
        for(Item c = 0 ; c < 2 ; c++){
            top.myVec[r][c] = myVec[r][c];
        }
    }
    for(Item r = 0 ; r < 3 ; r++){
        top.myVec[r][2] = myVec[r][3];
    }

    if(bottom.getDeterminantTriple() == 0){return 0;}

    return top.getDeterminantTriple()/bottom.getDeterminantTriple();
}

template<class Item>
void Matrix<Item>::scan() {
    cout << "Please enter the values for your " << myRows << "x" << myColumns << " matrix:" << endl;
    double scan;
    for(unsigned r = 0; r < myRows; r++) {
        for (unsigned c = 0; c < myColumns; c++) {
            cin >> scan;
            myVec[r][c] = scan;
        }
        cout << endl;
    }
    cout << "Here is the matrix you entered:" << endl;
}

template<class Item>
void Matrix<Item>::WriteToOperator(ostream &out) const{
	out << "{" << flush;
	for (unsigned r = 0; r < myRows; ++r){
		if(r>0){out << " " << flush;}
		for (unsigned c = 0; c < myColumns; ++c) {
			out << (*this)[r][c];
			if(c<myColumns-1){out << ", " << flush;}
		}
		if(r!=myRows-1){out << '\n' << flush;}
	}
	out << "}" << '\n' << flush;
}

template<class Item>
ostream& operator<<(ostream& out, const Matrix<Item>& mat){
    mat.WriteToOperator(out);
	return out;
}

#endif
