#include <iostream>
#include <string>
#include <vector>
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
    string cows;
    cin >> cows;
    int minG, maxG, minH, maxH;
    for (int i = 0; i < n; ++i) {
        if (cows[i] == 'G') {
            minG = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (cows[i] == 'G') {
            maxG = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (cows[i] == 'H') {
            minH = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (cows[i] == 'H') {
            maxH = i;
            break;
        }
    }
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
        --e[i];
    }
    int counter = 0;
    // CASE #1?
    if (e[minG] >= maxG) {
        for (int i = minH; i < minG; ++i) {
            if (cows[i] == 'H' && e[i] >= minG && e[i] < maxH) {
                ++counter;
            }
        }
    }
    // CASE #2
    if (e[minH] >= maxH) {
        for (int i = minG; i < minH; ++i) {
            if (cows[i] == 'G' && e[i] >= minH && e[i] < maxG) {
                ++counter;
            }
        }
    }
    // CASE #3
    if (e[minG] >= maxG && e[minH] >= maxH) {
        ++counter;
    }
    cout << counter << '\n';
}