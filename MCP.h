#pragma once
#include "PayOff.h"
// PROCEDURAL MONTE CARLO SIMULATION
double procedural_monte_carlo_pricer(double time_to_expiry,
	double strike_price,
	double spot_price,
	double volatility,
	double rate,
	unsigned long number_of_paths, double gaussian_input);

// MONTE CARLO USING PAYOFF CLASS
//Pass Payoff Object, with other variables
double monte_carlo_pricer_using_payoffs(const PayOff& pay_off_, 
	double time_to_expiry,
	double strike_price,
	double spot_price,
	double volatility,
	double rate,
	unsigned long number_of_paths, 
	double gaussian_input);