#include <iostream>
#include "Test.h"
#include "Gaussian_Generator.h"
using namespace std;

void Test::test_get_sample_using_random_generator(){
	cout << "Random number generated by generator " << get_sample_using_random_generator() << endl;
}

void Test::test_get_sample_by_summation() {
	cout << "Random number generated by summmation " << get_sample_by_summation() << endl;
}

void Test::test_get_sample_by_box_muller() {
	cout << "Random number generated by Box Mueller " << get_sample_by_box_muller() << endl;
}

void Test::test_get_sample_by_von_neumann_rejection() {
	cout << "Random number generated by Von Neumann Rejection " << get_sample_by_von_neumann_rejection() << endl;
}

