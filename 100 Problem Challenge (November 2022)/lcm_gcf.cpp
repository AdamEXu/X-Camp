#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    int gcf = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && m % i == 0) {
            gcf = i;
        }
    }
    cout << gcf << '\n';
    int lcm = n * m;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && m % i == 0) {
            lcm = n * m / i;
            break;
        }
    }
    cout << lcm << '\n';
}