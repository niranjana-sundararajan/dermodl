#pragma once

// Inclue Guards to prevent multiple calls
#ifndef GET_SAMPLE
#define GET_SAMPLE

//Note : Include guards are used to prevent multiple inclusions of the same header file, which can lead to compilation errors due to redefinitions.


// Each function represents a mehtod to generate a random number from a gaussian
double get_sample_using_random_generator();
double get_sample_by_summation();
double get_sample_by_box_muller();
double get_sample_by_von_neumann_rejection();


#endif