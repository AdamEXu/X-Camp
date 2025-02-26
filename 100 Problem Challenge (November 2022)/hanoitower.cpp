#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << "->" << to << '\n';
        return;
    }
    hanoi(n-1, from, aux, to);
    cout << from << "->" << to << '\n';
    hanoi(n-1, aux, to, from);
}

int main(void) {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    int moves = 1;
    for (int i = 0; i < n-1; i++) {
        moves = 2*moves + 1;
    }
    cout << "tot=" << moves << '\n';
}