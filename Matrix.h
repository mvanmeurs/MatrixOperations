/* Matrix.h defines Matrix class methods.
 * Student 2 Name: Mason VanMeurs
 * Student 2 methods:operator[], operator==, writeTo(ostream), readFrom(filename), operator-, getTranspose(), toString()
 * Student 1 Name: Joel Adams
 * Student 1 methods:operator!=, readFrom(istream), writeTo(filename), operator+
 * Date:10/3/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

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
    double getDeterminantTriple(const Matrix<Item>&) const;
private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

/* Default Constructor
 * @param: none
 * Sets myRows and myColumns to zero.
 */
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/* Explicit Constructor
 * @param: rows, an unsigned; columns, an unsigned
 * Sets myRows to rows, sets myColumns to columns, sets the row array to
 * size of rows,and sets each array in the row array to a size of columns.
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
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
		for (unsigned c = 0; c < myColumns; ++c) {
			cout << (*this)[r][c];
			if(c<myColumns-1){cout << ", " << flush;}
		}
		if(r!=myRows-1){cout << '\n' << flush;}
	}
	cout << "}" << '\n' << flush;
}

template<class Item>
double Matrix<Item>::getDeterminantTriple(const Matrix<Item>& matrix) const{
    Matrix<Item> m1(2, 2);
    Matrix<Item> m2(2, 2);
    Matrix<Item> m3(2, 2);

    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; ){
            m1[r][c] = matrix[r+1][c+1];
        }
    }

    m2[0][0] = matrix[1][0];
    m2[0][1] = matrix[1][2];
    m2[1][0] = matrix[2][0];
    m2[1][1] = matrix[2][2];

    for(unsigned r = 0 ; r < 2 ; r++){
        for(unsigned c = 0 ; c < 2 ; ){
            m3[r][c] = matrix[r][c];
        }
    }

    //return matrix[0][0]*m1.getDeterminantDouble(m1) -
}

#endif
