#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<double> ropes (n);
    double t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ropes[i] = t*100;
    }
    int lbound = 0, ubound = *max_element(ropes.begin(), ropes.end()), mid, ans=0;
    while (lbound < ubound) {
        mid = (lbound+ubound)/2;
        int pieces = 0;
        for (int i = 0; i < n; ++i) {
            pieces += ropes[i]/mid;
        }
        if (pieces < k) {
            ubound = mid-1;
        } else {
            lbound = mid+1;
            ans = mid;
        }
    }
    cout << fixed << setprecision(2) << ans/100.0 << '\n';
}