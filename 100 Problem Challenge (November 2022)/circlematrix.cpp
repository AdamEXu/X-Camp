#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<vector<int> > circle(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            circle[i][j] = min(min(i, j), min(n-i-1, n-j-1)) + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << circle[i][j] << " ";
        }
        cout << '\n';
    }
}