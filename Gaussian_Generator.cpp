
#include <cstdlib>
#include <cmath>
#include <random>

#include "Gaussian_Generator.h"

using namespace std;

// Get Value Using C++ Random Generator
double get_sample_using_random_generator()
{
    // Use a high-quality random seed
    random_device rd;
    mt19937_64 gen(rd());
    // Note: The _64 in std::mt19937_64 signifies a 64-bit version of the Mersenne Twister engine.

    // Use a distribution to generate random numbers (e.g., uniform distribution)
    uniform_real_distribution<double> dis(0.0, 1.0);

    // Generate a random number
    double random_value = dis(gen);

    return random_value;
}

//------------------------------------------------------------------------------------------------|
// Get Value by Summation
double get_sample_by_summation()
{
    double random_value = 0;
    for (unsigned long j = 0; j < 12; j++)
        random_value += rand() / static_cast<double>(RAND_MAX);
    random_value -= 6.0;
    return random_value;
}

//------------------------------------------------------------------------------------------------|
// Get Value by Box Muller
double get_sample_by_box_muller()
{
    double random_value;
    double x, y;

    double size_squared;

    do {
        //Note: static_cast = type cast operation that converts the integer value RAND_MAX to a double.
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        size_squared = x * x + y * y;
    } 
    while (size_squared >= 1.0); {
        random_value = x * sqrt(-2 * log(size_squared) / size_squared);;
    }
    return random_value;
  
}

//------------------------------------------------------------------------------------------------|
// Get Value by Von Neumann Rejection
double get_sample_by_von_neumann_rejection()
{
    double square, middle_digits;

    // Generate a random number
    double random_num = rand() / static_cast<double>(RAND_MAX);

    // Square the random number
    square = random_num * random_num;

    // Extract middle digits
    middle_digits = (square / 100);

    return middle_digits;
}

