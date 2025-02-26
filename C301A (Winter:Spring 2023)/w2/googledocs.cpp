#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int input_series[n];
    int dp[n];
    for (int i = 0; i < n; i++) {
        cin >> input_series[i];
        dp[i] = 1;
    }

    // largest increasing subsequence
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (input_series[i] > input_series[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp, dp + n) << endl;
}