#include <iostream>
using namespace std;

int main(void) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int rides = 0;
    int cost = n * a;
    // while (rides < n) {
    //     if (rides+m <= n) {
    //         rides += m;
    //         cost += b;
    //     } else if (n-rides < m && m < a*(n-rides)) {
    //         rides += m;
    //         cost+=b;
    //     } else {
    //         rides += 1;
    //         cost += a;
    //     }
    // }

    int small = n%m;
    rides += small;
    int big = n/m;
    // cost += big*b + small*a;
    cost = min(cost, big*b + small*a);

    cout << min(cost, ((n / m) + 1) * b) << endl;
}