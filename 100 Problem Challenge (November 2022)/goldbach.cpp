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
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 2; i <= n/2; i++) {
        if (isprime(i) && isprime(n-i)) {
            a = i;
            b = n-i;
            break;
        }
    }
    cout << n << "=" << a << "+" << b << '\n';
}