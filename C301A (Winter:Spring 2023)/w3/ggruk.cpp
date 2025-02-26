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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    int nums[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= 1; --j) {
            if (j - nums[i] >= 0) {
                memeorization[j] = max(memeorization[j], memeorization[j - nums[i]] + nums[i]);
            }
        }
    }
    cout << x-memeorization[x] << endl;
}