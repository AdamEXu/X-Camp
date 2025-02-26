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
    int n, W=0; 
    cin >> n;
    int weights[n];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        W+=weights[i];
    }
    int dp[W + 1];
    dp[0] = true;
    for (int capacity = 0; capacity <= W; capacity++) dp[capacity] = false;
    
    for (int max_index = 0; max_index < n; max_index++) {
        for (int capacity = W; capacity >= weights [max_index]; capacity--) {
            dp[capacity] = dp[capacity] || dp[capacity - weights[max_index]];
        }
    }
    cout << dp[W];
}