/*
    Author: Bhagi Dhakal
    File Name: blackScholesFormula.cpp
    Description: Creating function to calculate option price using Black Scholes Formula
*/

#include "blackScholesFormula.hpp" 


#include <iostream>
#include <cmath>
#include <vector> 

float e = std::exp(1.0);


float N(float x) {
    return .5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

std::pair<float, float> calculateD1D2(float S, float K, float sigma, float r, float T, float deltaDivs) {

    float numerator = std::log(S / K) + (r - deltaDivs + 0.5 * sigma * sigma) * T;

    float denominator = sigma * std::sqrt(T);

    float d1 = numerator / denominator;
    float d2 = d1 - sigma * std::sqrt(T);

    return { d1, d2 };
}



float calculateBSFOptionPrice(float S, float K, float sigma, float r, float T, float deltaDivs, bool call) {

    std::pair<float, float> d1d2 = calculateD1D2(S, K, sigma, r, T, deltaDivs);

    // calculating the call 

    // Stock Price discount with deltaDivs
    float StockPD = S * pow(e, -deltaDivs * T);

    // float Strike price discount with the risk free rate
    float StrikePD = K * pow(e, -r * T);


    // return price based on the call or put
    if (call) {
        float callOptionPrice = StockPD * N(d1d2.first) - StrikePD * N(d1d2.second);
        std::cout << "Call Option Price: " << callOptionPrice << std::endl;
        return callOptionPrice;
    }
    else {
        float putOptionPrice = StrikePD * N(-d1d2.second) - StockPD * N(-d1d2.first);
        std::cout << "Put Option Price: " << putOptionPrice << std::endl;
        return putOptionPrice;
    }
}
