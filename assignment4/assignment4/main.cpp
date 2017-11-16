// Assignment 4 - Advertising Survey (assignment4.cpp)
// Written by: Jenna Hildebrand
// Date: July 15 2016
// Sources: Trevor Babcock (boyfriend), Marisol Curtis (coworker)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    char     reply;
    ifstream filePath;
    string   fileName;
    string   line;
    string   name;
    char     seenAd;
    int      age;
    int      score;

    double   numUnder18NotSeenAd = 0;
    double   numUnder18SeenAd = 0;
    double   num18OverNotSeenAd = 0;
    double   num18OverSeenAd = 0;
    double   numAllSubjects = 0;

    double   sumUnder18NotSeenAd = 0;
    double   sumUnder18SeenAd = 0;
    double   sum18OverNotSeenAd = 0;
    double   sum18OverSeenAd = 0;
    double   sumAllSubjects = 0;

    double   avgUnder18NotSeenAd;
    double   avgUnder18SeenAd;
    double   avg18OverNotSeenAd;
    double   avg18OverSeenAd;
    double   avgAllSubjects;

    cout << fixed << setprecision(2);    // displays floats in fixed point notation with decimal precision set to 2
    
    // get file input
    cout << "Please enter the full pathname of the data file on disk: ";
    getline(cin, fileName);
    // open the file
    filePath.open(fileName.c_str());
    if (!filePath.is_open()) {
        cout << "Unable to open file. Please provide a valid path to a file on disk." << endl;
        cout << "Press enter to continue...";
        getline(cin, line);
        exit(1);
    }

    // read the file
    while (filePath) {        
        filePath >> name >> seenAd >> age >> score;
        // break here so we don't read the last line of the file twice
        if (!filePath) break;
        // print the read lines to the console
        cout << name << ' ' << seenAd << ' ' << age << ' ' << score << endl;

        numAllSubjects = numAllSubjects + 1;
        sumAllSubjects = sumAllSubjects + score;
        avgAllSubjects = sumAllSubjects / numAllSubjects;

        if (seenAd == 'N' && age < 18) {
            numUnder18NotSeenAd = numUnder18NotSeenAd + 1;
            sumUnder18NotSeenAd = sumUnder18NotSeenAd + score;
            avgUnder18NotSeenAd = sumUnder18NotSeenAd / numUnder18NotSeenAd;
        }
        if (seenAd == 'Y' && age < 18) {
            numUnder18SeenAd = numUnder18SeenAd + 1;
            sumUnder18SeenAd = sumUnder18SeenAd + score;
            avgUnder18SeenAd = sumUnder18SeenAd / numUnder18SeenAd;
        }
        if (seenAd == 'N' && age >= 18){
            num18OverNotSeenAd = num18OverNotSeenAd + 1;
            sum18OverNotSeenAd = sum18OverNotSeenAd + score;
            avg18OverNotSeenAd = sum18OverNotSeenAd / num18OverNotSeenAd;
        }
        if (seenAd == 'Y' && age >= 18){
            num18OverSeenAd = num18OverSeenAd + 1;
            sum18OverSeenAd = sum18OverSeenAd + score;
            avg18OverSeenAd = sum18OverSeenAd / num18OverSeenAd;
        }
    }


    // output the results
    cout << "Average score for subjects under 18 who have not seen the ad: " << avgUnder18NotSeenAd << endl;
    cout << "Average score for subjects under 18 who have seen the ad: " << avgUnder18SeenAd << endl;
    cout << "Average score for subjects 18 and over who have not seen the ad: " << avg18OverNotSeenAd << endl;
    cout << "Average score for subjects 18 and over who have seen the ad: " << avg18OverSeenAd << endl;
    cout << "Average score for all subjects: " << avgAllSubjects << endl;

    // This section stops the program 'flashing' off the screen.
    cout << "Press q (or any other key) followed by 'Enter' to quit: ";
    cin >> reply;
    return 0;
}