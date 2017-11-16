#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    char reply;
    int sum = 0;
    int num;
    int j;

    for (j = 1; j <= 5; j++)
    {
        cin >> num;
        if (num < 0)
            break;
        sum = sum + num;
    }
    cout << sum << endl;

    // This section stops the program 'flashing' off the screen.
    cout << "Press q (or any other key) followed by 'Enter' to quit: ";
    cin >> reply;
    return 0;
}