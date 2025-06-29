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
float h = 0.333; // time period, number of steps 


/*** Main Function ***/
int main() {


    calculateOptionPrice(S, K, sigma, r, T, deltaDividends, 1, true);
    calculateOptionPrice(S, K, sigma, r, T, deltaDividends, .25, true);
    calculateOptionPrice(S, K, sigma, r, T, deltaDividends, .1, true);
    calculateOptionPrice(S, K, sigma, r, T, deltaDividends, .05, true);
    calculateOptionPrice(S, K, sigma, r, T, deltaDividends, .01, true);
    calculateOptionPrice(S, K, sigma, r, T, deltaDividends, .002, true);




    return 0;
}