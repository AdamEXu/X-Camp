#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int n, totalcoins = 0;
    nums.push_back(0);
    cin >> n;
    for (int i = 0; i < n; ++i) nums.push_back(1);
    cin >> n;
    for (int i = 0; i < n; ++i) nums.push_back(2);
    cin >> n;
    for (int i = 0; i < n; ++i) nums.push_back(3);
    cin >> n;
    for (int i = 0; i < n; ++i) nums.push_back(5);
    cin >> n;
    for (int i = 0; i < n; ++i) nums.push_back(10);
    cin >> n;
    for (int i = 0; i < n; ++i) nums.push_back(20);
    for (int i = 0; i < nums.size(); ++i) {
        // cout << nums[i] << ' ';
        totalcoins += nums[i];
    }
    // cout << '\n';
    n = nums.size();
    bool dp[n+1][totalcoins+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= totalcoins; ++j) {
            if (j == 0) {
                dp[i][j] = true;
            } else {
                dp[i][j] = false;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= totalcoins; ++j) {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= totalcoins; ++i) {
        if (dp[n][i]) {
            ++ans;
        }
    }
    cout << "Total=" << ans << '\n';
    // for (int i = 1; i <= totalcoins; ++i) {
    //     if (dp[n][i]) {
    //         cout << i << ' ';
    //     }
    // }
    // cout << '\n';
}