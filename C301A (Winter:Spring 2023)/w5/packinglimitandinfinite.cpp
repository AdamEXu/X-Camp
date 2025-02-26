#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int main(void) {
    int maxW, n;
    cin >> maxW >> n;
    int w[n+1], v[n+1], q[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i] >> q[i];
        if (q[i] == 0) q[i] = INT_MAX;
    }
    // w = weight of item
    // v = value of item
    // q = quantity of item

    int dp[n + 1][maxW + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= maxW; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= maxW; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
        }
    }
    cout << dp[n][maxW] << '\n';
}