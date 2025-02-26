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
    int k, n, m;
    cin >> k >> n >> m;
    vector<pair<int, int> > crabrave(n), veggers(m);
    for (int i = 0; i < n; ++i) {
        cin >> crabrave[i].first >> crabrave[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> veggers[i].first >> veggers[i].second;
    }
    sort(veggers.begin(), veggers.end());
    int dp[k+1], maxhappiness = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[j] = 0;
        }
        for (int j = 0; j < m; ++j) {
            for (int l = k; l >= veggers[j].first; --l) {
                dp[l] = max(dp[l], dp[l-veggers[j].first] + veggers[j].second);
            }
        }
        for (int j = 0; j <= k; ++j) {
            if (j + crabrave[i].first <= k) {
                maxhappiness = max(maxhappiness, dp[j] + crabrave[i].second);
            }
        }
    }
    // try it without crabrave
    for (int j = 0; j <= k; ++j) {
        dp[j] = 0;
    }
    for (int j = 0; j < m; ++j) {
        for (int l = k; l >= veggers[j].first; --l) {
            dp[l] = max(dp[l], dp[l-veggers[j].first] + veggers[j].second);
        }
    }
    maxhappiness = max(maxhappiness, dp[k]);
    cout << maxhappiness << '\n';
}