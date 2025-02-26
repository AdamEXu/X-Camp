#include <iostream>
#define LL long long
using namespace std;

LL factorial(LL n) {
    if (n == 1) {
        return 1;
    }
    return n*factorial(n-1);
}

int main(void) {
    int n;
    cin >> n;
    cout << factorial(n)%998244353 << endl;
}