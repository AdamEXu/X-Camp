#include <iostream>
#include <vector>
using namespace std;

unsigned long long factorial(unsigned long long n) {
    n = n % 998244353;
    if (n <= 1) {
        return 1;
    }
    n = n % 998244353;
    n *= factorial((n-1) % 998244353);
    n = n % 998244353;
    // cout << n << endl;
    return n;
}

int main(void) {
    unsigned long long n;
    cin >> n;
    n = n % 998244353;
    cout << factorial(n) << endl;
}