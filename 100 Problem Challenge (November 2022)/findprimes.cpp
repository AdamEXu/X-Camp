#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isprime(int n) {
    if (n == 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (isprime(i)) {
            cout << i << " ";
        }
    }
    cout << '\n';
}