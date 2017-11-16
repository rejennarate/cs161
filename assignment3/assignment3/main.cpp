// Assignment 3 - Fare Calculator (assignment3.cpp)
// Written by: Jenna Hildebrand
// Date: July 8 2016
// Sources: None

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double ADULT_FARE                      = 13.00;
const double CHILD_FARE                      = 6.50;
const double PEOPLE_FUEL_SURCHARGE           = 1.25;
const double VEHICLE_FARE                    = 43.00;
const double VEHICLE_FUEL_SURCHARGE          = 4.15;
const double VEHICLE_PER_FOOT_RATE           = 2.15;
const double OVERSIZE_VEHICLE_FARE           = 69.00;
const double OVERSIZE_VEHICLE_FUEL_SURCHARGE = 10.40;
const double OVERSIZE_PER_FOOT_RATE          = 3.45;

int main()
{
    char   reply;
    int    numAdults;            
    int    numChildren;          
    char   vehiclePresent;       
    char   oversizeVehiclePresent;
    int    vehicleLength;
    double vehiclePerFootRate;
    int    numVehicles;          
    int    numOversizeVehicles;  
    double oversizePerFootRate;
    double fare;
    double fuelSurcharge;
    double totalFare;

    cout << fixed;            // displays floats in fixed point notation
    cout << setprecision(2);  // sets decimal precision to 2

    // Get user input
    cout << "Welcome to Jenna's Fare Calculator." << endl;
    cout << "How many adults (age 12 and over) are in your party? ";
    cin >> numAdults;
    cout << "How many children (age 5 to 11) are in your party? ";
    cin >> numChildren;
    cout << "Are you driving a vehicle onto the ferry? (y/n): ";
    cin >> vehiclePresent;
    if (vehiclePresent == 'y' || vehiclePresent == 'Y') {
        numVehicles = 1;
        cout << "What is the length of the vehicle in feet? ";
        cin >> vehicleLength;
        cout << "Is the vehicle over 7 feet high? (y/n): ";
        cin >> oversizeVehiclePresent;
        if (oversizeVehiclePresent == 'y' || oversizeVehiclePresent == 'Y') {
            numVehicles = 0;
            numOversizeVehicles = 1;
        }
        else if (oversizeVehiclePresent == 'n' || oversizeVehiclePresent == 'N') {
            numOversizeVehicles = 0;
        }
        else {
            cout << "Please enter y/n" << endl;
        }
    }
    else if (vehiclePresent == 'n' || vehiclePresent == 'N') {
        numVehicles = 0;
        vehicleLength = 0;
        numOversizeVehicles = 0;
    }
    else {
        cout << "Please enter y/n" << endl;
    }

    // do the calculations
    if (vehicleLength > 20 && numVehicles == 1) {
        vehiclePerFootRate = (vehicleLength - 20) * VEHICLE_PER_FOOT_RATE;
    }
    else if (vehicleLength > 20 && numOversizeVehicles == 1) {
        vehiclePerFootRate = (vehicleLength - 20) * OVERSIZE_PER_FOOT_RATE;
    }
    else {
        vehiclePerFootRate = 0;
    }

    fare = (numAdults * ADULT_FARE) + 
        (numChildren * CHILD_FARE) + 
        (numVehicles * VEHICLE_FARE) +
        (numOversizeVehicles * OVERSIZE_VEHICLE_FARE) +
        vehiclePerFootRate;

    fuelSurcharge = (numAdults * PEOPLE_FUEL_SURCHARGE) + 
        (numChildren * PEOPLE_FUEL_SURCHARGE) + 
        (numVehicles * VEHICLE_FUEL_SURCHARGE) +
        (numOversizeVehicles * OVERSIZE_VEHICLE_FUEL_SURCHARGE);

    totalFare = fare + fuelSurcharge;
    
    // output the results
    cout << "Your fare is $" << fare << " plus a fuel surcharge of $" << fuelSurcharge << endl;
    cout << "The total amount payable is $" << totalFare << endl;
    cout << "Thank you for using Jenna's Fare Calculator." << endl;


    // This section stops the program 'flashing' off the screen.
    cout << "Press q (or any other key) followed by 'Enter' to quit: ";
    cin >> reply;
    return 0;
}