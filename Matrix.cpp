#include "Matrix.h"
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

double dot_product(const double * const arr_one, const double * const arr_two, int size)
{
    double product = 0;
    for (int i = 0; i < size; i++)
        product += arr_one[i] * arr_two[i];
    return product;
}

Matrix::Matrix() : row(0), column(0), entries(nullptr) {}
Matrix::Matrix(int new_row, int new_column) : row(new_row), column(new_column)
{
    if (row != 0 && column != 0)
    {
        entries = new double*[row];
        for (int i = 0; i < row; i++)
        {
            entries[i] = new double[column];
            for (int j = 0;j < column;j++)
                entries[i][j] = 0;
        }
    }
    else
        entries = nullptr;
}
Matrix::Matrix(const Matrix& other)
{
    row = other.row; column = other.column;
    if (row != 0 && column != 0)
    {
        entries = new double*[row];
        for (int i = 0; i < row; i++)
        {
            entries[i] = new double[column];
            for (int j = 0; j < column; j++)
                entries[i][j] = other.entries[i][j];
        }
    }
    else
        entries = nullptr;
}

Matrix::~Matrix()
{
    if (entries != nullptr)
    {
        for (int i = 0; i < row; i++)
            delete[] entries[i];
        delete[] entries;
    }
}

void Matrix::operator =(const Matrix& rhs)
{
    change_size(rhs.row, rhs.column);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            entries[i][j] = rhs.entries[i][j];
}

void Matrix::change_size(int new_row, int new_column)
{
    if (new_row != row || new_column != column)
    {
        if (entries != nullptr)
        {
            for (int i = 0; i < row; i++)
                delete[] entries[i];
            delete[] entries;
        }
        row = new_row;
        column = new_column;
        if (row != 0 && column != 0)
        {
            entries = new double*[row];
            for (int i = 0; i < row; i++)
            {
                entries[i] = new double[column];
                for (int j = 0;j < column;j++)
                    entries[i][j] = 0;
            }

        }
        else
            entries = nullptr;
    }
}

int Matrix::getRow() const
{
    return row;
}
int Matrix::getColumn() const
{
    return column;
}

Matrix Matrix::rref() const
{
    Matrix temp(*this);
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < row; j++)
            for (int k = 0;k < column;k++)
                if (temp.entries[j][k] != 0)
                {
                    e1(temp.entries[j], 1.0 / temp.entries[j][k]);
                    break;
                }
        if (temp.entries[i][i] == 0)
            for (int j = i + 1; j < row; j++)
                if (temp.entries[j][i] != 0)
                    e2(temp.entries[i], temp.entries[j]);
        for (int j = i + 1; j < row; j++)
            if (temp.entries[j][i] != 0)
                e3(temp.entries[j], temp.entries[i], -1.0);
    }

    for (int i = row - 1; i >= 0; i--)
        for (int j = 0;j < column;j++)
            if (temp.entries[i][j] != 0)
            {
                for (int k = i - 1; k >= 0; k--)
                    if (temp.entries[k][j] != 0)
                        e3(temp.entries[k], temp.entries[i], -temp.entries[k][j]);
                break;
            }
    return temp;
}

Matrix Matrix::inverse() const
{
    if (row == column)
    {
        Matrix temp(*this);
        Matrix inverse(row, row);
        for (int i = 0;i < row;i++)
            inverse.entries[i][i] = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = i; j < row; j++)
                for (int k = 0;k < row;k++)
                    if (temp.entries[j][k] != 0)
                    {
						double divisor = 1.0 / temp.entries[j][k];
                        e1(temp.entries[j], divisor);
                        e1(inverse.entries[j], divisor);
                        break;
                    }
            if (temp.entries[i][i] == 0)
                for (int j = i + 1; j < row; j++)
                    if (temp.entries[j][i] != 0)
                    {
                        e2(temp.entries[i], temp.entries[j]);
                        e2(inverse.entries[i], inverse.entries[j]);
                    }
            for (int j = i + 1; j < row; j++)
                if (temp.entries[j][i] != 0)
                {
                    e3(temp.entries[j], temp.entries[i], -1.0);
                    e3(inverse.entries[j], inverse.entries[i], -1.0);
                }
        }

        for (int i = row - 1; i >= 0; i--)
            for (int j = 0;j < row;j++)
                if (temp.entries[i][j] != 0)
                {
                    for (int k = i - 1; k >= 0; k--)
                        if (temp.entries[k][j] != 0)
                        {
							double divisor = -temp.entries[k][j];
                            e3(temp.entries[k], temp.entries[i], divisor);
                            e3(inverse.entries[k], inverse.entries[i], divisor);
                        }
                    break;
                }
        return inverse;
    }
    else
    {
        exit(1);
    }
}

double Matrix::det() const
{
	double determinant = 1;
	if (row == column)
	{
		Matrix temp(*this);
		for (int i = 0; i < row; i++)
		{
			for (int j = i; j < row; j++)
				for (int k = 0; k < row; k++)
					if (temp.entries[j][k] != 0)
					{
						determinant *= temp.entries[j][k];
						e1(temp.entries[j], 1.0 / temp.entries[j][k]);
						break;
					}
			if (temp.entries[i][i] == 0)
				for (int j = i + 1; j < row; j++)
					if (temp.entries[j][i] != 0)
					{
						determinant *= -1;
						e2(temp.entries[i], temp.entries[j]);
					}
			for (int j = i + 1; j < row; j++)
				if (temp.entries[j][i] != 0)
					e3(temp.entries[j], temp.entries[i], -1.0);
		}
		for (int i = 0; i < row; i++)
			determinant *= temp.entries[i][i];
		return determinant;
	}
	else
		return 0;
}




Matrix Matrix::transpose() const
{
    Matrix temp(column, row);
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            temp.entries[i][j] = entries[j][i];
    return temp;
}


Matrix operator +(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.row == rhs.row && lhs.column == rhs.column)
    {
        Matrix temp(lhs.row, lhs.column);
        for (int i = 0; i < lhs.row; i++)
            for (int j = 0; j < lhs.column; j++)
                temp.entries[i][j] = lhs.entries[i][j] + rhs.entries[i][j];
        return temp;
    }
    else
        std::cout << "Addition Fail;\n"; //should implement a exception and catch while different size occurs
}
Matrix operator -(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.row == rhs.row && lhs.column == rhs.column)
    {
        Matrix temp(lhs.row, lhs.column);
        for (int i = 0; i < lhs.row; i++)
            for (int j = 0; j < lhs.column; j++)
                temp.entries[i][j] = lhs.entries[i][j] - rhs.entries[i][j];
        return temp;
    }
    else
        std::cout << "Subtraction Fail;\n"; //should implement a exception and catch while different size occurs
}

Matrix operator *(const Matrix & lhs, const double & rhs)
{
    Matrix temp(lhs.row, lhs.column);
    for (int i = 0; i < lhs.row; i++)
        for (int j = 0; j < lhs.column; j++)
            temp.entries[i][j] = lhs.entries[i][j] * rhs;
    return temp;
}

Matrix operator *(const double & lhs, const Matrix & rhs)
{
    return rhs * lhs;
}

Matrix operator *(const Matrix & lhs, const Matrix & rhs)
{
    if (lhs.column == rhs.row)
    {
        Matrix temp(lhs.row, rhs.column);
        for (int i = 0; i < lhs.row; i++)
            for (int j = 0; j < rhs.column; j++)
                temp.entries[i][j] = dot_product(lhs.entries[i], rhs.transpose().entries[j], lhs.column);
        return temp;
    }
    else
    {
        std::cout << "not multiplicable\n";
        return Matrix();
    }
}

std::istream& operator >>(std::istream &ins, Matrix &rhs)
{
    std::stringstream ss;
    std::string s, temp;
    ss << ins.rdbuf();
    s = ss.str();
    if (!s.empty())
    {
        std::vector<std::string> nums;
        std::vector<int> temp_rows;
        s += '\n';
        temp.erase();
        int row = 0, column = 0, max_column = 0;
        bool isDot = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                if(i > 0 && s[i-1] == '-')
                    temp += s[i-1];
                temp += s[i];
            }
            else if (s[i] == '.' && !isDot)
            {
                temp += s[i];
                isDot = true;
            }
            else if (isspace(s[i]) && isdigit(s[i - 1]))
            {
                bool is_newline = false;
                isDot = false;
                while (isspace(s[i]))
                {
                    if (s[i] == '\n')
                        is_newline = true;
                    i++;
                }
                i--;
                if (is_newline)
                {
                    row++;
                    column++;
                    if (column >= max_column)
                        max_column = column;
                    temp_rows.push_back(column);
                    column = 0;
                }
                else
                    column++;
                nums.push_back(temp);
                temp.erase();
            }
        }

        rhs.change_size(row, max_column);
        int index = 0;
        for (int i = 0; i < rhs.row; i++)
            for (int j = 0; j < rhs.column; j++)
                if (j < temp_rows[i])
                {
                    rhs.entries[i][j] = atof(nums[index].c_str());
                    index++;
                }
    }
    return ins;
}

std::ostream& operator <<(std::ostream &outs, const Matrix &rhs){
    for (int i = 0; i < rhs.row; i++)
    {
        for (int j = 0; j < rhs.column; j++)
            outs << rhs.entries[i][j] << " ";
        outs << std::endl;
    }
    return outs;
}

void Matrix::e1(double*row, double num) const
{
    for (int i = 0; i < column; i++)
        if (row[i] != 0)
            row[i] = row[i] * num;
}
void Matrix::e2(double*row1, double* row2) const
{
    for (int i = 0; i < column; i++)
    {
        double temp;
        temp = row1[i];
        row1[i] = row2[i];
        row2[i] = temp;
    }
}
void Matrix::e3(double*row1, double* row2, double num) const
{
    for (int i = 0; i < column; i++)
        row1[i] = row1[i] + row2[i] * num;
}

