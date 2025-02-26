#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, t;
    cin >> n >> t;
    vector<long long> machines;
    for (long long i = 0; i < n; ++i) {
        long long temp;
        cin >> temp;
        machines.push_back(temp);
    }
    long long lbound = 0, ubound = t * *min_element(machines.begin(), machines.end()), mid;
    long long ans = ubound;
    while (lbound <= ubound) {
        mid = (lbound+ubound)/2;
        long long time = 0;
        for (long long i = 0; i < n; ++i) {
            time += mid/machines[i];
        }
        if (time < t) {
            lbound = mid+1;
        } else {
            ans = mid;
            ubound = mid-1;
        }
    }
    cout << ans << endl;
}