// This is assignment 1 - Horoscope (assignment1.cpp)
// Written by: Jenna Hildebrand
// Date: June 22 2016
// Sources: None


#include <iostream>                 
#include <string>

using namespace std;               

int main()
{
	char reply;
	string name;
	string course;

	cout << "Welcome to Jenna's Crystal Ball!" << endl;
	cout << "What is your name, please? ";
	cin >> name;
	cout << "Hello, " << name << ". My name is Jenna. " << endl;
	cout << "What subject are you studying? ";
	cin >> course;
	cout << "Well, " << name << ", Jenna's crystal ball says you will do very well in " << course << " this term." << endl;
	cout << "Good luck!" << endl;


	// This section stops the program 'flashing' off the screen.
	cout << "Press q (or any other key) followed by 'Enter' to quit: ";
	cin >> reply;
	return 0;
}

