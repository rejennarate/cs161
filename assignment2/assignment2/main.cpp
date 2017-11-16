// This is assignment 2 - Conversion (assignment2.cpp)
// Written by: Jenna Hildebrand
// Date: June 29 2016
// Sources: None


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double EURO_CONVERSION_FACTOR  = 0.6938;
const double KILO_CONVERSION_FACTOR  = 0.4536;
const double OUNCE_CONVERSION_FACTOR = 16;

int main()
{
	char    reply;
	int     pounds;
	int     ounces;
	double  price;
    double  weightInPounds;
    double  pricePerPound;
    double  priceInEuros;
    double  weightInKilos;
    double  pricePerKilo;

    cout << fixed;          // displays floats in fixed point notation
    cout << setprecision(2); // sets decimal precision to 2

    // Get user input
	cout << "Welcome to Jenna's Conversion program." << endl;
	cout << "What is the weight of your item in pounds and ounces? " << endl;
	cout << "Pounds: ";
	cin >> pounds;
	cout << "Ounces: ";
	cin >> ounces;
	cout << "What is the price in dollars and cents? $";
	cin >> price;

	// Calculate the conversion
    weightInPounds = pounds + (ounces / OUNCE_CONVERSION_FACTOR);
    pricePerPound  = price / weightInPounds;
	priceInEuros   = price * EURO_CONVERSION_FACTOR;
    weightInKilos  = weightInPounds * KILO_CONVERSION_FACTOR;
    pricePerKilo   = priceInEuros / weightInKilos;

	// Output the results
	cout << "The price of this item is $" << pricePerPound << " per pound" << endl;
	cout << "That is equivalent to " << pricePerKilo << " Euros per kilo" << endl;
	cout << "Thank you for using Jenna's Conversion program." << endl;

	// This section stops the program 'flashing' off the screen.
	cout << "Press q (or any other key) followed by 'Enter' to quit: ";
	cin >> reply;
	return 0;
}


