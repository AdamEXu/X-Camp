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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int costsofar = k+1, prev = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] - prev > k) {
            costsofar += k+1;
            prev = arr[i];
        } else {
            costsofar += arr[i] - prev;
            prev = arr[i];
        }
    }
    cout << costsofar << '\n';
}