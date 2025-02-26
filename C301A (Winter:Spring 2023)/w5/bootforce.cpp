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

vector<long long> nums;
long long n, k;

int bettermod(long long a, long long b) {
    int r = a % b;
    if (r < 0) {
        r += b;
    }
    return r;
}

vector<long long> bootedforce() {
    vector<long long> results;
    for (long long i = 0; i < (1 << n); ++i) {
        long long sum = 0;
        for (long long j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += nums[j];
            } else {
                sum -= nums[j];
            }
        }
        results.push_back(sum);
    }
    return results;
}

int main(void) {
    // long long n, k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    nums.resize(n);
    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<long long> results = bootedforce();
    for (long long i = 0; i < results.size(); ++i) {
        if (bettermod(results[i], k) == 0) {
            cout << "Divisible" << '\n';
            return 0;
        }
    }
    cout << "Not divisible" << '\n';
    // for (long long i = 0; i < results.size(); ++i) {
    //     cout << results[i] << ' ';
    // }
    // cout << '\n';
}