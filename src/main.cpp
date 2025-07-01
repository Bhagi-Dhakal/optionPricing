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
#include "blackScholesFormula.hpp"




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

    // Option Price uisng the Binomial Model
    // does not matter what we assign the results.... (it will just be printed out)
    // int a = calculateBMOptionPrice(S, K, sigma, r, T, deltaDividends, 1, true);
    // int b = calculateBMOptionPrice(S, K, sigma, r, T, deltaDividends, .25, true);
    // int c = calculateBMOptionPrice(S, K, sigma, r, T, deltaDividends, .1, true);
    // int d = calculateBMOptionPrice(S, K, sigma, r, T, deltaDividends, .05, true);
    // int e = calculateBMOptionPrice(S, K, sigma, r, T, deltaDividends, .01, true);
    // int f = calculateBMOptionPrice(S, K, sigma, r, T, deltaDividends, .002, true);

    /* Results:
        a: Steps: 1  Option Price: 7.83858
        b: Steps: 4  Option Price: 7.16015
        c: Steps: 10  Option Price: 7.0647
        d: Steps: 20  Option Price: 6.98072
        e: Steps: 100  Option Price: 6.96648
        f: Steps: 499  Option Price: 6.95466
    */


    // Option Price using the Black Scholes Formula
    int x = calculateBSFOptionPrice(41, 40, 0.3, 0.08, 0.25, 0, true); // Example 12.1 Page 351
    int y = calculateBSFOptionPrice(41, 40, 0.3, 0.08, 0.25, 0, false); // Example 12.2 Page 352
    /*  Results:
        Call Option Price: 3.39908 (Book: $3.399)
        Put Option Price: 1.60702  (Book: $1.607)
    */

    return 0;
}