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

vector<int> nums;
vector<int> dp(0, 1);

int longestincrease(int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i] && dp[j]+1 > dp[i]) { 
                dp[i] = dp[j]+1;
            }
        }
        if (dp[i] > max) max = dp[i];
    }
    return max;
}

int main(void) {
    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums.push_back(t);
    }
    dp.resize(n);
    cout << longestincrease(n) << endl;
}