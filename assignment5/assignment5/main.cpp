// Assignment 5 - Mersenne Primes (assignment5.cpp)
// Written by: Jenna Hildebrand
// Date: July 21 2016
// Sources: Marisol Curtis (coworker), Bean (coworker)

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

bool isPrime(long n);
long power2(long n);
void abortProgram();

int main() {
    int x;

    // format the output
    cout << "Mersenne Primes by Jenna Hildebrand" << endl;
    cout << setw(2) << "n" << setw(33) << "Mersenne Prime" << endl;
    cout << setw(2) << "==" << setw(33) << "==============" << endl << endl;

    // do a loop over numbers 2 thru 1,000,000
    for (x = 2; x < 20; x++) {
        if (isPrime(x) == true) {
            if (isPrime(power2(x) - 1))
                cout << setw(2) << x << setw(33) << power2(x) - 1 << endl;
        }
    }

    abortProgram();

    return 0;
}

bool isPrime(long n) {
    // returns true if n is a prime, else false
    for (int x = 2; x < n; x++) {
        if (n % x == 0)
            return false;
    }
    return true;
}

long power2(long n) {
    // returns 2 raised to the power of n
    int i = 1;

    while (n != 0) {
        i = i * 2;
        --n;
    }
    return i;
}


// This function stops the program 'flashing' off the screen.
void abortProgram() {
    string line;

    cout << "Press enter to quit:";
    getline(cin, line);
    exit(1);
}