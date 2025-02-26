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

set<int> s;

void getsum(int x, vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        int temp = x+a[i];
        a.erase(a.begin()+i);
        s.insert(temp);
        getsum(temp, a);
        a.insert(a.begin()+i, temp-x);
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    // getsum(0, a);
    // queue of int arrays
    queue<vector<int> > q;
    q.push(a);
    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        for (int i = 0; i < temp.size(); ++i) {
            int temp2 = temp[i];
            temp.erase(temp.begin()+i);
            s.insert(temp2);
            q.push(temp);
            temp.insert(temp.begin()+i, temp2);
        }
    }
    cout << s.size() << '\n';
    for (auto i : s) cout << i << ' ';
    cout << '\n';
}