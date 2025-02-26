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
    int l, w;
    // length and width of the "paper"
    cin >> l >> w;
    int maxh = min(l, w) / 2;
    int maxvol = 0;
    // find the max volume possible to 5 decimal places
    for (int h = 1; h <= maxh; ++h) {
        maxvol = max(maxvol, vol);
    }
    cout << maxvol / 100000.0 << '\n';
}