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

vector<vector<int> > triangle;

int dfs(int height, int x, int y) {
    int count = 0;
    if (x+1 == height) {
        return triangle[x][y];
    }
    count+=triangle[x][y];
    int a = dfs(triangle, height, x+1, y);
    int b = dfs(triangle, height, x+1, y+1);
    if (a > b) {
        count+=a;
    } else {
        count+=b;
    }
    return count;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // cout << i << endl;
        vector<int> temp;
        for (int j = 0; j <= i; j++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        triangle.push_back(temp);
    }
    cout << dfs(n, 0, 0) << endl;
}