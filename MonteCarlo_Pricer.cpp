#include <random>
#include <iostream>
#include <cmath>

#include "MCP.h"
#include "Payoff.h"

using namespace std;

// Procedural Monte Carlo Pricer

double procedural_monte_carlo_pricer(double time_to_expiry,
	double strike_price,
	double spot_price,
	double volatility,
	double rate,
	unsigned long number_of_paths, double gaussian_input)
{

	double variance = volatility * volatility * time_to_expiry;
	double root_variance = sqrt(variance);
	double ito_correction = -0.5 * variance;
	double moved_spot = spot_price * exp(rate * time_to_expiry + ito_correction);
	double current_spot;
	double running_sum = 0;
	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double thisGaussian = gaussian_input;
		current_spot = moved_spot * exp(root_variance * thisGaussian);
		double current_payoff = current_spot - strike_price;
		current_payoff = current_payoff > 0 ? current_payoff : 0;
		running_sum += current_payoff;
	}

	double avg_payoff = running_sum / number_of_paths;
	avg_payoff *= exp(-rate * time_to_expiry);
	return avg_payoff;
}



// Monte Carlo Pricer Using PayOff Function

double monte_carlo_pricer_using_payoffs(const PayOff& pay_off, double time_to_expiry, double strike_price, double spot_price, double volatility, double rate, unsigned long number_of_paths, double gaussian_input)
{

	double variance = volatility * volatility * time_to_expiry;
	double root_variance = sqrt(variance);
	double ito_correction = -0.5 * variance;
	double moved_spot = spot_price * exp(rate * time_to_expiry + ito_correction);
	double current_spot;
	double running_sum = 0;
	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double thisGaussian = gaussian_input;
		current_spot = moved_spot * exp(root_variance * thisGaussian);
		double current_payoff = pay_off(spot_price);
		running_sum += current_payoff;
	}

	double avg_payoff = running_sum / number_of_paths;
	avg_payoff *= exp(-rate * time_to_expiry);
	return avg_payoff;
}
