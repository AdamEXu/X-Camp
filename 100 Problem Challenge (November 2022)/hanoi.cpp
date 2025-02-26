#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int moves = 1;
    for (int i = 0; i < n-1; i++) {
        moves = 2*moves + 1;
    }
    cout << moves << '\n';
}