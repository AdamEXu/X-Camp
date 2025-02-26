#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> timings (n);
    for (int i = 0; i < n; ++i) cin >> timings[i];
    int lbound = 0, ubound = n, mid;
    int ans = 0;
    while (lbound <= ubound) {
        mid = (lbound+ubound)/2;
        int time = 0;
        for (int i = 0; i < n; ++i) {
            time += (timings[i]+mid-1)/mid;
        }
        if (time <= k) {
            ans = mid;
            ubound = mid-1;
        } else {
            lbound = mid+1;
        }
    }
}