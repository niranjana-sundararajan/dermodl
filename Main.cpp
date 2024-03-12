#include <iostream>
#include <cstdlib>

#include "Gaussian_Generator.h"
#include "MCP.h"
#include "Payoff.h"
using namespace std;


void display_random_number_generator_menu() {
    cout << " ---------------------------------------------------------------------------------" << endl;
    cout << " SELECT GAUSSIAN GENERATOR  " << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    cout << "1. By Random Generator \n";
    cout << "2. By Summation \n";
    cout << "3. By Box Mueller \n";
    cout << "4. By Von Neumann Rejection\n";
    cout << "5. EXIT\n";
}

void display_types_of_options() {
    cout << "1. Vanilla Call/Put Option \n";
    cout << "2. Digital Call/Put Option \n";
    cout << "3. Asian Call/Put Option\n";
    cout << "4. Digital Call Option\n";
    cout << "5. Asian Put Option\n";
    cout << "6. Asian Call Option\n";
}

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));
    int choice;
    // Variable to store random number
    double ran_generated_result;

    // Display the menu
    display_random_number_generator_menu();

    // Get user input
        
    std::cin >> choice;

  
    // Process user choice
    switch (choice) {
    case 1:
        std::cout << "You selected Option 1.\n";
        ran_generated_result = get_sample_using_random_generator();
        break;
    case 2:
        std::cout << "You selected Option 2.\n";
        ran_generated_result = get_sample_by_summation();
        break;
    case 3:
        std::cout << "You selected Option 3.\n";
        ran_generated_result = get_sample_by_box_muller();
        break;
    case 4:
        std::cout << "You selected Option 4.\n";
        ran_generated_result = get_sample_by_von_neumann_rejection();
        break;
    case 5:
        std::cout << "Exiting the program.\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }

   
    double time_to_expiry;
    double strike_price;
    double spot_price;
    double volatility;
    double rate;
    unsigned long number_of_paths;
    cout << " ---------------------------------------------------------------------------------" << endl;
    cout << " MONTE CARLO PRICER INITIATED  " << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    //cout << " Select Type of Option  " << endl;

    //display_types_of_options();
    cout << " ---------------------------------------------------------------------------------" << endl;

    cout << "\nEnter Time to Expiry\n";
    cin >> time_to_expiry;

    cout << "\nEnter Strike Price\n";
    cin >> strike_price;

    cout << "\nEnter Spot Price\n";
    cin >> spot_price;

    cout << "\nEnter Volatility \n";
    do{
        cout << "Note: 0 <= vol =<1\n";
        cin >> volatility;
    } while (volatility > 1 && volatility < 0);
    
    cout << "\n Enter Risk Free Rate\n";
    do {
        cout << "Note: 0 <= rate =<1\n";
        cin >> rate;
    } while (rate > 1 && rate < 0);

    cout << "\nNumber of Paths\n";
    cin >> number_of_paths;



    // Initialise Payoffs for both Call and Put
    PayOff call_pay_off(strike_price, PayOff::call);
    PayOff put_pay_off(strike_price, PayOff::put);


    // calcualte results for both call and put
    double result_call = monte_carlo_pricer_using_payoffs(call_pay_off,
        time_to_expiry,
        strike_price,
        spot_price,
        volatility,
        rate,
        number_of_paths, ran_generated_result);

    double result_put = monte_carlo_pricer_using_payoffs(put_pay_off,
        time_to_expiry,
        strike_price,
        spot_price,
        volatility,
        rate,
        number_of_paths, ran_generated_result);


    cout << "the prices are " << result_call
        << " for the call and "
        << result_put
        << " for the put\n";

    //double result = procedural_monte_carlo_pricer(time_to_expiry,
    //    strike_price,
    //    spot_price,
    //    volatility,
    //    rate,
    //    number_of_paths, ran_generated_result);

    //cout << "the price is " << result << "\n";
    return 0;


}