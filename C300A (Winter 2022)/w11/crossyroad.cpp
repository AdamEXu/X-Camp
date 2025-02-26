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
    int ch, n;
    cin >> ch >> n;
    multiset<int> chickens;
    int a, b;
    for (int i = 0; i < ch; i++) {
        cin >> a;
        chickens.insert(a);
    }
    vector<pair<int, int> > cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i].second >> cows[i].first;
    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto c = chickens.lower_bound(cows[i].second);
        if (c != chickens.end() && *c <= cows[i].first) {
            ++ans;
            chickens.erase(c);
        }
    }
    cout << ans << '\n';
}