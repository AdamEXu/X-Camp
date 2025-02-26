#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void vecout(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size()-1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
}

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

int main(void) {
    // TODO
}