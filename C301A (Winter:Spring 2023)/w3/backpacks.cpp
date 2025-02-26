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

int memeorization[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, W;
    cin >> n >> W;
    int weights[n], values[n];
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = W; j >= 1; --j) {
            if (j - weights[i] >= 0) {
                memeorization[j] = max(memeorization[j], memeorization[j - weights[i]] + values[i]);
            }
        }
    }
    cout << memeorization[W] << endl;
}