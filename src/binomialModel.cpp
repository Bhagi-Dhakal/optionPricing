/*
    Author: Bhagi Dhakal
    File Name: binomialModel.cpp (For Now I will just have many functions )
    Description: I will implement Binomial Model for option Pricing
*/

#include "binomialModel.hpp" 
#include "optionNode.hpp"

#include <iostream>
#include <cmath>
#include <vector> 


float calculateBMOptionPrice(float S, float K, float sigma, float r, float T, float deltaDivs, float h, bool call) {

    // Using equation 10.6 on page 300
    int N = static_cast<int>(T / h); // 
    float u = std::exp((r - deltaDivs) * h + sigma * std::sqrt(h)); // equations 10.9 on Page 300
    float d = std::exp((r - deltaDivs) * h - sigma * std::sqrt(h));
    float p = (std::exp((r - deltaDivs) * h) - d) / (u - d);  // equation 10.5 on page 299
    float discount = std::exp(-r * h);


    // forward price propagation: 
    int treeSize = (N + 1) * (N + 2) / 2;
    std::vector<optionNode> binomialTree(treeSize); // this is our tree, but its represented as a vector
    for (int t = 0; t <= N; ++t) { // points to the col (kind of)
        for (int i = 0; i <= t; ++i) { // points to the row (kind of)
            int index = t * (t + 1) / 2 + i;
            binomialTree[index].stockPrice = S * std::pow(u, t - i) * std::pow(d, i);
        }
    }

    // Price at maturatiy, when it expires 
    for (int i = 0; i <= N; ++i) {
        int indexMaturatiy = N * (N + 1) / 2 + i;
        binomialTree[indexMaturatiy].optionPrice = call ?
            std::max(0.0f, binomialTree[indexMaturatiy].stockPrice - K) : // if option is a call 
            std::max(0.0f, K - binomialTree[indexMaturatiy].stockPrice); // if option is a put
    }


    // now we need to go backword in time to "Now" using future prices 
    for (int t = N - 1; t >= 0; --t) {
        for (int i = 0; i <= t; ++i) {
            int currentIndex = t * (t + 1) / 2 + i; // getting the index of up and down from our tree
            int upIndex = (t + 1) * (t + 2) / 2 + i;
            int downIndex = upIndex + 1;

            float Cu = binomialTree[upIndex].optionPrice;
            float Cd = binomialTree[downIndex].optionPrice;
            float Su = binomialTree[upIndex].stockPrice;
            float Sd = binomialTree[downIndex].stockPrice;

            binomialTree[currentIndex].delta = (Cu - Cd) / (Su - Sd);
            binomialTree[currentIndex].B = (u * Cd - d * Cu) / (u - d) * discount;
            binomialTree[currentIndex].optionPrice = discount * (p * Cu + (1 - p) * Cd); // 10.6 on page 300
        }
    }


    // for (int t = 0; t <= N; ++t) {
    //     for (int i = 0; i <= t; ++i) {
    //         int index = t * (t + 1) / 2 + i;
    //         std::cout
    //             << "Stock Price = " << binomialTree[index].stockPrice
    //             << " Option Price = " << binomialTree[index].optionPrice
    //             << " Delta = " << binomialTree[index].delta
    //             << " Beta = " << binomialTree[index].B << "\n";
    //     }
    // }

    std::cout << "Steps: " << N << "  Option Price: " << binomialTree[0].optionPrice << std::endl;

    return binomialTree[0].optionPrice;
}

