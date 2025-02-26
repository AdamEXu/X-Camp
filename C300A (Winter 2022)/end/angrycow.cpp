#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> bales;
    int maxbale = 0, a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > maxbale) maxbale = a;
        bales.push_back(a);
    }
    sort(bales.begin(), bales.end());
    int lbound = 0, ubound = maxbale, mid;
    while (lbound < ubound) {
        mid = (lbound+ubound)/2;
        bool exploded[n];
        for (int i = 0; i < n; ++i) exploded[i] = false;
        int cowsneeded = 0;
        for (int i = 0; i < n; ++i) {
            if (!exploded[i]) {
                ++cowsneeded;
                int j = i;
                while (j < n && bales[j] <= bales[i]+mid) {
                    exploded[j] = true;
                    ++j;
                }
            }
        }
        if (cowsneeded <= k) {
            ubound = mid;
        } else {
            lbound = mid+1;
        }
    }
    cout << 1 + ((lbound - 1) / 2) << '\n';
}