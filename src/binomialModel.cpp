/*
    Author: Bhagi Dhakal
    File Name: binomialModel.cpp (For Now I will just have many functions )
    Description: I will implement Binomial Model for option Pricing
*/

#include "binomialModel.hpp" 
#include <iostream>
#include <cmath>
#include <vector> 


float calculateOptionPrice(float S, float K, float sigma, float r, float T, float deltaDivs, float h, bool call) {

    float x = 0.00f;
    float dt = T / h; // steps we are taking 
    float u = std::exp(r * dt + sigma * std::sqrt(dt));
    float d = std::exp(r * dt - sigma * std::sqrt(dt));


    float p = (std::exp(r * dt) - d) / (u - d);
    float discount = std::exp(-r * dt);

    // float u = 

    // Forword price Propagation
    std::vector<float> assetPrice(h + 1);
    for (int i = 0; i <= h; ++i) {
        assetPrice[i] = S * std::pow(u, h - i) * std::pow(d, i);
    }

    std::vector<float> optionPrice(h + 1);
    for (int i = 0; i <= h; ++i) {
        if (call) {
            optionPrice[i] = std::max(0.0f, assetPrice[i] - K);
        }
        else {
            optionPrice[i] = std::max(0.0f, K - assetPrice[i]);
        }

    }

    for (int i = h; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            optionPrice[j] = discount * (optionPrice[j + 1] * p + optionPrice[j] * (p - 1));
        }
    }

    for (int i = 0; i <= h; ++i) {
        std::cout << "Asset price: " << assetPrice[i] << " Option price: " << optionPrice[i] << std::endl;
    }


    return x;
}

