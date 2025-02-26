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

static bool same(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < a.size(); i++) {
        sum_a+=a[i];
        sum_b+=b[i];
    }
    if (sum_a != sum_b) return false;
    return true;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    // find number of ways to split a into b and c
    // the sum of b and c must be equal
    // example: a = {1, 2, 3, 4}
    // b = {1, 2}, c = {3, 4}
    // b = {1, 3}, c = {2, 4}
    // b = {1, 4}, c = {2, 3}
    // {1, 2} is considered the same as {2, 1}
    // {1, 3} is considered the same as {3, 1}
    // b = {1, 2} and c = {3, 4} is considered the same as b = {3, 4} and c = {1, 2}
    // code below
    int count = 0;
    vector<vector<int> > b;
    vector<vector<int> > c;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            vector<int> temp;
            temp.push_back(a[i]);
            temp.push_back(a[j]);
            b.push_back(temp);
            vector<int> temp2;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    temp2.push_back(a[k]);
                }
            }
            c.push_back(temp2);
        }
    }
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            if (same(b[i], c[j])) {
                count++;
            }
        }
    }
    cout << count << endl;
}