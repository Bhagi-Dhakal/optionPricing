/*
    Author: Bhagi Dhakal
    File Name: main.cpp
    compile: Makefile
    Description: Implementing Option pricing models.
        Binomial Model, Black-Scholes Model...

*/


/*** Includes ***/
#include<iostream>
#include "matrix2D.cpp"


/*** Main Function ***/

int main() {

    Matrix2D<int> myMatrix(5, 5);
    Matrix2D<int> myMatrix2(5, 5);

    myMatrix[2][3] = 5;
    myMatrix[2][2] = 5;

    myMatrix2[2][3] = 5;
    myMatrix2[2][2] = 5;

    Matrix2D<int> C = myMatrix - myMatrix2;
    C.print();


    return 0;
}