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
    int zone = -1;
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
    int zone = 0;
    for (int i = 0; i < n; ++i) {
        if (points[i].zone == -1) {
            queue<int> q;
            q.push(i);
            points[i].zone = zone;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int j = 0; j < points[curr].edges.size(); ++j) {
                    if (points[points[curr].edges[j]].zone == -1) {
                        q.push(points[curr].edges[j]);
                        points[points[curr].edges[j]].zone = zone;
                    }
                }
            }
            zone++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int j = 1;
        while (a[j-1] != i) {
            j++;
        }
        if (points[i-1].zone == points[j-1].zone) {
            ++ans;
        }
    }
    cout << ans << '\n';
}