#pragma once

#include <iostream>


//float e = std::exp(1.0);

// we also need the  N(x) which is the cumulative Normal Distribution Function
// I will be using the error function to calculate the CDF.. 
float N(float x);

// Equation 12.2a
std::pair<float, float> calculateD1D2(float S, float K, float sigma, float r, float T, float deltaDivs);


// Equation 12.1
float calculateBSFOptionPrice(float S, float K, float sigma, float r, float T, float deltaDivs, bool call);
