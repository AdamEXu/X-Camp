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
    long long n, t;
    cin >> n >> t;
    map<long long, long long> arr;
    long long a, b;
    for (long long i = 0; i < n; ++i) {
        cin >> a >> b;
        arr[a-1] = b;
    }
    long long eaten = 0, lastspace = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (max(it->first, lastspace) + it->second > t) {
            eaten += t - max(lastspace, it->first);
            break;
        } else if (it->first >= lastspace) {
            eaten += it->second;
            lastspace = it->first + it->second;
        } else {
            eaten += it->second;
            lastspace+=it->second;
        }
    }
    cout << eaten << '\n';
}