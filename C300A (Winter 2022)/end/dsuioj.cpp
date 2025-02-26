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

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent = vector<int>(n, -1);
    }
    int find(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    DSU dsu(n);
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        dsu.unite(x-1, y-1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // int j = 1;
        // while (a[j-1] != i) {
        //     ++j;
        // }
        if (dsu.find(i-1) == dsu.find(a[i-1])) {
            ++ans;
        } else if (a[i] == i) {
            ++ans;
        }
    }
    cout << ans << endl;
}