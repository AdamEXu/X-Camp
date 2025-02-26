#include <iostream>
using namespace std;

int main(void) {
    cout << "Welcome to SasquatchHAX by Adam The Great." << endl;
    cout << "This program was made just for fun and isn't intended to be used for hacking leaderboard scores." << endl;
    cout << "Please make sure that Sneaky Sasquatch is installed on your Mac and is not open." << endl;
    cout << "I am not responsible to any damage done to your save due to this program." << endl;
    cout << "Are you sure you want to continue? (y/n)" << endl;
    char c;
    cin >> c;
    if (c == 'N' || c == 'n') {
        cout << "Goodbye." << endl;
        return 0;
    } else if (c == 'Y' || c == 'y') {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    } else {
        cout << "Goodbye." << endl;
        return 0;
    }
}