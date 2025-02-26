#include <iostream>
#include <string>
using namespace std;

void arrout(int *input) {
    for (int i = 0; i < INT_MAX; i++) {
        cout << input[i];
        if (input[i+1] == '\0') {
            cout << input[i] << endl;
            return;
        } else if (i != 0) {
            cout << ", ";
        }
    }
}

int input(istream& in=cin) {
    int x;
    in >> x;
    return x;
}