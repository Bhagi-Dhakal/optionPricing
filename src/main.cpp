/*
    Author: Bhagi Dhakal
    File Name: main.cpp
    compile: Makefile
    Description: Implementing Option pricing models.
        Binomial Model, Black-Scholes Model...

*/


/*** Includes ***/
#include<iostream>

// #include "matrix2D.cpp"
#include "binomialModel.hpp"



// 10.5 (page 309)
float S = 41.00; // Stock price in dollars
float K = 40.00; // Strike Price
float sigma = 0.30; // Basically historical volitality
float r = 0.08; // Risk free intrest rate..? 
float T = 1.00; // time in years 
float deltaDividends = 0.00;  // amout of dividends stock pays in the contracts life time.. 
float h = 3.00; // time period, number of steps 


/*** Main Function ***/

int main() {

    // Matrix2D<int> myMatrix(5, 5);
    // Matrix2D<int> myMatrix2(5, 5);

    // myMatrix[2][3] = 5;
    // myMatrix[2][2] = 5;

    // myMatrix2[2][3] = 5;
    // myMatrix2[2][2] = 5;

    // Matrix2D<int> C = myMatrix - myMatrix2;
    // C.print();

    float x = calculateOptionPrice(S, K, sigma, r, T, deltaDividends, h, true);

    return 0;
}