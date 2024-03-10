#pragma once

#include <vector>
#include <chrono>

using namespace std;

class Test {
	public:
		double generated_random_variable;

		// ----------------------------------------------------------------------------------------------- |
		//  FUNCTIOND TESTING RANDOM NUMBER GENERATOR													   |
		// ----------------------------------------------------------------------------------------------- |
		void test_get_sample_using_random_generator();
		void test_get_sample_by_summation();
		void test_get_sample_by_box_muller();
		void test_get_sample_by_von_neumann_rejection();

		// ----------------------------------------------------------------------------------------------- |
		//  FUNCTIOND TESTING MONTE CARLO PRICER    													   |
		// ----------------------------------------------------------------------------------------------- |

		void test_monte_carlo_pricer();

};