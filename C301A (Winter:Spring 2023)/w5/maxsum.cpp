#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int prefix[n+1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    int maxsum = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            maxsum = max(maxsum, prefix[j] - prefix[i-1]);
        }
    }
    cout << maxsum << '\n';
}