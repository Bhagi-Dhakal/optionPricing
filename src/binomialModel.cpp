/*
    Author: Bhagi Dhakal
    File Name: binomialModel.cpp (For Now I will just have many functions )
    Description: I will implement Binomial Model for option Pricing
*/

#include "binomialModel.hpp" 
#include <iostream>
#include <cmath>
#include <vector> 


void calculateOptionPrice(float S, float K, float sigma, float r, float T, float deltaDivs, float h, bool call) {

    float x = 0.00f;
    int N = static_cast<int>(T / h);

    //float dt = T / h; // steps we are taking 
    float u = std::exp(sigma * std::sqrt(h));
    //float d = std::exp((r - deltaDivs) * h - sigma * std::sqrt(h));
    float d = 1.0f / u;

    float p = (std::exp((r - deltaDivs) * h) - d) / (u - d);
    float discount = std::exp(-r * h);



    // Forword price Propagation 
    std::vector<float> assetPrice(N + 1);
    for (int i = 0; i <= N; ++i) {
        assetPrice[i] = S * std::pow(u, N - i) * std::pow(d, i);
    }

    // Price at maturatiy
    std::vector<float> optionPrice(N + 1);
    for (int i = 0; i <= N; ++i) {
        if (call) {
            optionPrice[i] = std::max(0.0f, assetPrice[i] - K);
        }
        else {
            optionPrice[i] = std::max(0.0f, K - assetPrice[i]);
        }

    }

    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            optionPrice[j] = discount * (p * optionPrice[j + 1] + (1 - p) * optionPrice[j]);
        }
    }

    std::cout << "Option price at t=0: " << optionPrice[0] << "\n";
}

