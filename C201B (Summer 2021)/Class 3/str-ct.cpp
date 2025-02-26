#include <iostream>
using namespace std;

int main(void) {
    char c = '/';
    long long letters = 0, numbers=0, other =0;
    while (c != '?') {
        cin >> c;
        if (int(c) >= 65 && int(c) <= 90) {
            letters++;
        } else if (int(c) >= 97 && int(c) <= 122) {
            letters++;
        } else if (int(c) >= 48 && int(c) <= 57) {
            numbers++;
        } else {
            other++;
        }
    }
    cout << numbers << endl << letters << endl << other-1 << endl;
}