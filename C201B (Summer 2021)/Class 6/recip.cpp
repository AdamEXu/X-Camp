#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    double r = 0.0;
    for (int i = 1; i <= n; i++) {
        r+=(1.0/i);
    }
    cout << fixed << setprecision(6) << r << endl;
}