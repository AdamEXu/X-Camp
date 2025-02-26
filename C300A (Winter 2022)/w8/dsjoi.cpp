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

struct Point {
    vector<int> edges;
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<Point> points(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        points[u-1].edges.push_back(v-1);
        points[v-1].edges.push_back(u-1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (a[j-1] != i) {
            j++;
        }
        bool found = false;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(j-1);
        visited[j-1] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == i-1) {
                found = true;
                break;
            }
            for (int k = 0; k < points[curr].edges.size(); ++k) {
                if (!visited[points[curr].edges[k]]) {
                    q.push(points[curr].edges[k]);
                    visited[points[curr].edges[k]] = true;
                }
            }
        }
        if (found) {
            ans++;
        }
    }
    cout << ans << '\n';
}