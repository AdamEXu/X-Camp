#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int countx(int n, int x) {
    // count number of times x appears in the digits of n
    int count = 0;
    while (n > 0) {
        if (n % 10 == x) count++;
        n /= 10;
    }
    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += countx(i, x);
    }
    cout << count << '\n';
}