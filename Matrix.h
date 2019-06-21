#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
public:
	Matrix();
	Matrix(int new_row, int new_column);
	Matrix(const Matrix& other);
	~Matrix();
	void operator =(const Matrix& rhs);
	void change_size(int new_row, int new_column);


    int getRow() const;
    int getColumn() const;


    Matrix rref() const;
	Matrix inverse() const;
	Matrix transpose() const;
	double det() const;


	friend Matrix operator +(const Matrix &lhs, const Matrix &rhs);
	friend Matrix operator -(const Matrix &lhs, const Matrix &rhs);
	friend Matrix operator *(const Matrix &lhs, const double &rhs);
	friend Matrix operator *(const double &lhs, const Matrix &rhs);
	friend Matrix operator *(const Matrix &lhs, const Matrix &rhs);
	friend std::istream& operator >>(std::istream &ins, Matrix &rhs);
	friend std::ostream& operator <<(std::ostream &outs, const Matrix &rhs);

private:
	int row;
	int column;
	double** entries;
    void e1(double* row1, double num) const;
    void e2(double*row1, double* row2) const;
    void e3(double*row1, double* row2, double num) const;
};

#endif



