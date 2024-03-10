#pragma once


double simple_monte_carlo_pricer(double time_to_expiry,
	double strike_price,
	double spot_price,
	double volatility,
	double rate,
	unsigned long number_of_paths, double gaussian_input);