#pragma once
#ifndef PAYOFF
#define PAYOFF

class PayOff 
{
public:
	// enum that defines the number of options
	enum option_type {call, put};

	// Construtor of payoff class with - strike and option_type enum as input
	PayOff(double strike_price, option_type type_of_option);
	
	// Overload the bracket() with a function so that we can use PayOff(strike_price)
	double operator()(double spot_price) const;

	// Getter for Strike Price
	double get_strike();

private:
	// Keeping the inputs to the class private and hence immutable
	double strike_price;
	option_type type_of_option;

};
#endif