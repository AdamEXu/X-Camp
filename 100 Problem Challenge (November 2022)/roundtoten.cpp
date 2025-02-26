#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s = to_string(n);
    if (s[s.length()-1] >= '5') {
        cout << (n/10 + 1) * 10 << '\n';
    } else {
        cout << n/10 * 10 << '\n';
    }
}