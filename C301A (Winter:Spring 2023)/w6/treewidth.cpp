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

struct Tree {
    vector<int> child;
    int depth;
} T[100000];

void dfs(int u) {
    for (auto v : T[u].child) {
        T[v].depth = T[u].depth + 1;
        dfs(v);
    }
}

int main(void) {
    int n;
    char tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            if (tmp == '1') {
                T[i].child.push_back(j);
            }
        }
    }
    dfs(0);
    int maxdepth = 0;
    for (int i = 0; i < n; ++i) {
        maxdepth = max(maxdepth, T[i].depth);
    }
    cout << maxdepth << '\n';
}