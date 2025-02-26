#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string intformat(int n) {
    string s = to_string(n);
    while (s.length() < 4) s = " " + s;
    return s;
}

int main(void) {
    int n;
    cin >> n;
    int current = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << intformat(++current);
        }
        cout << '\n';
    }
}