// Assignment 6 - Data Integrity (assignment6.cpp)
// Written by: Jenna Hildebrand
// Date: August 5, 2016
// Sources: Marisol Curtis (coworker), Bean (coworker)

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main();
void abortProgram();

const int SUM_ARR_SZ = 100;
unsigned int checkSums[SUM_ARR_SZ];
string fileNames[SUM_ARR_SZ];
string file;
int numberOfFiles = 0;

int computeCheckSum(string file);
void storeInArray(string filename, int checksum, int index);
int verifyIntegrity(string file, int checksum);

//F:\Dropbox\cs161\encrypted.txt

int main() {
    char reply;
    string line;

    bool done = false;
    while (done != true) {
        // Prompt user to make a selection
        cout << "Please select:" << endl;
        cout << "A) Compute checksum of specified file" << endl;
        cout << "B) Verify integrity of specified file" << endl;
        cout << "Q) Quit" << endl;
        cin >> reply;

        int index = 0; // needs to increment as you get more files

        switch (toupper(reply)) {
        case 'A': {
            // Prompt user to put in full path to file
            cout << "Specify the file path:" << endl;
            cin >> file;
            cout << endl;
            int c = computeCheckSum(file);
            if (c > -1) {
                cout << "File checksum = " << c << endl;
                storeInArray(file, c, index);
            }
        }
        break;
        case 'B': {
            cout << "Specify the file path:" << endl;
            cin >> file;
            cout << endl;
            int c = computeCheckSum(file);
            if (c > -1) {
                verifyIntegrity(file, c);
            }
        }
        break;
        case 'Q': {
            abortProgram();
        }
        break;
        default:
            cout << "Please select an option." << endl;
        }
    }

    fileNames[numberOfFiles] = file;
    checkSums[numberOfFiles] = file.length();
    numberOfFiles++;

    return 0;
}

int computeCheckSum(string file) {
    ifstream inputFile;
    // open the specified file in binary mode
    inputFile.open(file.c_str(), ios::binary);

    // Check the file opened successfully.
    if (!inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        return(-1);
    }

    // determine the file size using seekg and tellg
    inputFile.seekg(0, ios_base::end);
    int fileLen = inputFile.tellg();
    inputFile.seekg(0, ios_base::beg);

    // read the file contents into the character array in one statement
    char buffer[100000];
    inputFile.read(buffer, fileLen);

    // close the file
    inputFile.close();

    // loop through the array one character and a time and accumulate the sum of each byte
    int checksum = 0;
    for (int i = 0; i < fileLen; i++) {
        checksum = checksum + buffer[i];
    }

    return checksum;
}

void storeInArray(string filename, int checksum, int index) {
    fileNames[index] = filename;
    checkSums[index] = checksum;
}

int verifyIntegrity(string file, int checksum) {
    int index_of_existing_name;
    bool found = false;
    int idx = 0;
    int existingChecksum = 0;

    // search the array for an existing filename
    while ((idx < SUM_ARR_SZ) && !found) {
        if (fileNames[idx] == file) {
            found = true;
            existingChecksum = checkSums[idx];
            if (checksum == existingChecksum) {
                cout << "File checksum = " << checksum << endl;
                cout << "The file integrity check has passed successfully." << endl;
            }
            else
                cout << "The file integrity check has failed (previous checksum = " << existingChecksum << ", new checksum = " << checksum << endl;
        }
        else
            idx++;
    }

    if (!found) {
        cout << file << " checksum has not previously been computed" << endl;
        return 0;
    }
}

// This function stops the program 'flashing' off the screen.
void abortProgram() {
    string line;

    cout << "Press enter to quit:";
    getline(cin, line);
    exit(1);
}