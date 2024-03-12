#include <minmax.h>
#include "Payoff.h"


// Constructor : Initialised via Initialisation list: No executable so body is empty
PayOff::PayOff(double strike_price, option_type type_of_option)
    :
    strike_price(strike_price), type_of_option(type_of_option)
{
}

double PayOff::operator()(double spot_price) const
{
    switch (type_of_option)
    {
    case call:
        return max(spot_price - strike_price, 0.0);
    case put:
        return max(strike_price - spot_price, 0.0);
    default:
        throw("unknown option type found.");
    }
}

double PayOff::get_strike()
{
   return strike_price;
}
