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

bool sorterhelper(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int> > ints(n);
    for (int i = 0; i < n; i++) {
        cin >> ints[i].first;
        ints[i].second = i;
    }
    sort(ints.begin(), ints.end(), sorterhelper);
    double average = 0.0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum+=ints[i].first*(n-i-1);
    }
    average = (double)sum/n;
    for (int i = 0; i < n; i++) {
        cout << ints[i].second+1 << " ";
    }
    cout << '\n';
    cout << fixed << setprecision(2) << average << '\n';
}