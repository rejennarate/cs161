// Assignment 7a: Library Part I
// Written by: Jenna Hildebrand
// Date: August 11, 2016
// Sources: Marisol Curtis (coworker), Marcus Chalona

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 1000;
int loadData(string pathName);
int showBooksByAuthor(int count, string name);
int showBooksByTitle(int count, string title);
void showAll(int count);
bool stringIsFound(string a, string b);
void abortProgram();

string bookTitle[ARRAY_SIZE];
string bookAuthor[ARRAY_SIZE];
string pathName;
string authorName;
string bookName;

int main() {
    string reply;
    char response;

    // Prompt user to put in full path to file
    cout << "Welcome to Jenna's Library Database." << endl;
    cout << "Please enter the name of the backup file: ";
    getline(cin, pathName);
    cout << endl;
    cout << loadData(pathName) << " records loaded successfully" << endl;

    bool done = false;
    while (done != true) {
        // Prompt user to make a selection
        cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: " << endl;
        cin >> response;

        switch (toupper(response)) {
        case 'A': {
            cout << "Author's Name: ";
            cin >> authorName;
            showBooksByAuthor(loadData(pathName), authorName);
            break;
        }
        case 'T': {
            cout << "Title: ";
            cin >> bookName;
            showBooksByTitle(loadData(pathName), bookName);
            break;
        }
        case 'S':
            showAll(loadData(pathName));
            break;
        case 'Q':
            done = true;
            break;
            break;
        default:
            cout << "Please select a valid option." << endl;
        }
    }
    return 0;
}

// function for loading file information into arrays
int loadData(string pathName) {
    string line;
    ifstream inputFile;
    string reply;
    int i = 0;

    // Open the input file.
    inputFile.open(pathName.c_str());   // inputFile.open("F:\Dropbox\cs161\library.txt");
 
    // Check the file opened successfully.
    if (!inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        cout << "Press enter to continue...";
        getline(cin, reply);
        exit(-1);
    }

    // fill parallel array
    while (inputFile.peek() != EOF) {
        getline(inputFile, line);
        bookTitle[i] = line;
        getline(inputFile, line);
        bookAuthor[i] = line;
        i++;
    }

    // Close the input file stream
    inputFile.close();
    inputFile.clear(std::ios_base::goodbit);
    return i;
}

// displays all records which contain the designated text
int showBooksByAuthor(int count, string name) {
    int idx = 0;
    int recordsFound = 0;

    while ((idx < count) && (recordsFound != count)) {

        if (stringIsFound(bookAuthor[idx], name) == true) {
            recordsFound++;
            cout << bookTitle[idx] << " (" << bookAuthor[idx] << ")" << endl;
            idx++;
        }
        else
            idx++;
    }
    cout << recordsFound << " records found." << endl;
    return recordsFound;
}

int showBooksByTitle(int count, string title) {
    int idx = 0;
    int recordsFound = 0;

    while ((idx < count) && (recordsFound != count)) {
        if (stringIsFound(bookTitle[idx], title) == true) {
            recordsFound++;
            cout << bookTitle[idx] << " (" << bookAuthor[idx] << ")" << endl;
            idx++;
        }
        else
            idx++;
    }
    cout << recordsFound << " records found." << endl;
    return recordsFound;
}

// function for printing information inside of arrays
void showAll(int count) {
    for (int i = 0; i < count; i++) {
        cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;
    }
}

// find string b in string a in a case insensitive manner return true of found 
bool stringIsFound(string a, string b) {
    for (int x = 0; x < a.size(); x++) {
        a[x] = toupper(a[x]);
    }
    for (int x = 0; x < b.size(); x++) {
        b[x] = toupper(b[x]);
    }
    if (string::npos != a.find(b)) {
        return true;
    }
    return false;
}

// This function stops the program 'flashing' off the screen.
void abortProgram() {
    string line;

    cout << "Press enter to quit:";
    getline(cin, line);
    exit(1);
}