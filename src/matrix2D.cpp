/*
    Author: Bhagi Dhakal
    File Name: matrix.cpp (Class File)
    Description: Implementing matrix class

*/


/*** Includes ***/

#include<iostream>
#include <vector> 


// Class 
template<typename T>
class Matrix2D {
private:

    int rows = 0;
    int cols = 0;

    std::vector<std::vector<T>> matrix;

public:

    Matrix2D(int row, int col) : rows(row), cols(col) {
        matrix = std::vector<std::vector<T>>(row, std::vector<T>(cols, T{}));

    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << "   ";
            }
            std::cout << std::endl;
        }
    }



    std::pair<int, int> getSize() const {
        return { rows, cols };
    }

    /*** Operations ***/

    std::vector<T>& operator[](int row) {
        return matrix[row];
    }
    const std::vector<T>& operator[](int row) const {
        return matrix[row];
    }

    Matrix2D operator+(const Matrix2D& other) {
        Matrix2D operationResult(this->rows, this->cols);

        if (this->getSize() != other.getSize()) {
            throw std::runtime_error("Division by zero is not allowed.");

        }
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                operationResult[i][j] = matrix[i][j] + other[i][j];
            }
        }
        return operationResult;
    }

    Matrix2D operator-(const Matrix2D& other) {
        Matrix2D operationResult(this->rows, this->cols);

        if (this->getSize() != other.getSize()) {
            throw std::runtime_error("Division by zero is not allowed.");

        }
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                operationResult[i][j] = matrix[i][j] - other[i][j];
            }
        }
        return operationResult;
    }

};
