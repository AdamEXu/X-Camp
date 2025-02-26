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
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string cows;
        cin >> cows;
        string results = ""; for (int i = 0; i < n; ++i) results += '.';
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (cows[i] == '.') continue;
            int current = i;
            char cow = cows[i];
            if (current+k < n && results[current+k] == '.') {
                results[current+k] = cows[current];
                ++count;
                for (int j = current; j <= current+k+k && j < n; ++j) {
                    if (cows[j] == cow) {
                        cows[j] = '.';
                    }
                }
            } else {
                while (current+k >= n || results[current+k] == '.') {
                    --current;
                }
                results[current] = cows[i];
                ++count;
                for (int j = current; j <= current+k+k && j < n; ++j) {
                    if (cows[j] == cow) {
                        cows[j] = '.';
                    }
                }
            }
        }
        cout << count << '\n';
        cout << results << '\n';
    }
}