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

static int getdivisors(int x) {
    int divisors = 0;
    int i = 1;
    while (i*i <= x) {
        if (x % i == 0) {
            ++divisors;
            if (x / i != i) {
                ++divisors;
            }
        }
        ++i;
    }
    return divisors;
}

// i made my own max function because for some weird reason the std::max function isnt working on my computer :(
static int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i+1;
    vector<int> divisors(n);
    for (int i = 0; i < n; ++i) divisors[i] = getdivisors(a[i]);
    // knapsack algorithm with
    // max weight = n
    // value = # of divisors
    // weight = number
    int dp[n+1][n+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= a[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]]+divisors[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][n] << endl;
}