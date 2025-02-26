#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
// #include <bits/stdc++.h>
using namespace std;

struct Point {
    int n;
    vector<int> neighbors;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Point> points(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        points[a-1].neighbors.push_back(b-1);
        points[b-1].neighbors.push_back(a-1);
    }
    vector<int> closures;
    for (int i = 0; i < n; i++) {
        cin >> a;
        closures.push_back(a-1);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < points[curr].neighbors.size(); i++) {
            int neighbor = points[curr].neighbors[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    bool allconnected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            allconnected = false;
            break;
        }
    }
    if (allconnected) cout << "YES" << '\n'; else cout << "NO" << '\n';
    for (int i = 0; i < n-1; i++) {
        vector<int> current = points[closures[i]].neighbors;
        for (int j = 0; j < current.size(); j++) {
            // remove closures[i] from current[j]'s neighbors
            vector<int>::iterator it = find(points[current[j]].neighbors.begin(), points[current[j]].neighbors.end(), closures[i]);
            if (it != points[current[j]].neighbors.end()) {
                points[current[j]].neighbors.erase(it);
            }
        }
        points[closures[i]].neighbors.clear();
        // use bfs to check if all connected
        vector<bool> visited(n, false);
        int count = 1;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int j = 0; j < points[curr].neighbors.size(); j++) {
                int neighbor = points[curr].neighbors[j];
                if (!visited[neighbor]) {
                    count++;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        if (count == n-i-1) cout << "YES" << '\n'; else cout << "NO" << '\n';
    }
}