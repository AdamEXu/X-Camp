#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int numofone = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') numofone++;
    }
    cout << numofone << '\n';
}