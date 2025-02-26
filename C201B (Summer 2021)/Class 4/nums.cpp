#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    long long n, num = 0, current = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<long long> factors;
        long long total = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                factors.push_back(j);
                total+=j;
            }
        }
        if (total == i) {
            cout << i << endl;
        }
    }
}