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

int dp[1000001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, W;
    cin >> W >> n;
    int weights[n], values[n];
    for (int i = 0; i < n; i++) cin >> weights[i] >> values[n];

    int dp[W + 1];

    for (int capacity = 0; capacity <= W; capacity++) dp[capacity] = 0;

    for (int max_index = 0; max_index < n; max_index++) {
        for (int capacity = W; capacity >= weights [max_index]; capacity--) {
            dp[capacity] = max(dp [capacity],
            dp[capacity - weights [max_index]] + values [max_index]);
        }
    }
    cout << dp[W];
}