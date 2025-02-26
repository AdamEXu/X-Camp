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
// #include <bits/stdc++.h>
using namespace std;

struct Point {
    char type;
    vector<int> paths;
    int zone;
    Point(char type) {
        this->type = type;
        this->zone = -1;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        points[i] = Point(s[i]);
    }
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        points[i].paths.push_back(a-1);
        points[i].paths.push_back(b-1);
    }
    int zone = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].zone == -1) {
            points[i].zone = zone;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int j = 0; j < points[curr].paths.size(); j++) {
                    int neighbor = points[curr].paths[j];
                    if (points[neighbor].zone == -1 && points[neighbor].type == points[curr].type) {
                        points[neighbor].zone = zone;
                        q.push(neighbor);
                    }
                }
            }
            ++zone;
        }
    }
}