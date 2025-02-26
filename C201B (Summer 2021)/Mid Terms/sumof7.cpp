#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    long long n, sum = 0;
    cin >> n;
    for (int i = 0; i < (n/7)+1; i++) {
        sum+=i*7;
    }
    cout << sum << endl;
}