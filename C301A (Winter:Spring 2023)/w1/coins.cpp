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

int n, x;
int coins[1000001];

long min_num_coins(int x) {
    long dp[x+1];
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) { 
            if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    if (dp[x] == INT_MAX) return -1;
    return dp[x];
}

int main(void) {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << min_num_coins(x) << endl;
}