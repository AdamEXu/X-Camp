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
vector<vector<int> > memeorization;

int dfs(int height, int x, int y) {
    if (memeorization[x][y] != -1) return memeorization[x][y];
    int count = 0;
    if (x+1 == height) return triangle[x][y];
    count+=triangle[x][y];
    int a = dfs(height, x+1, y);
    int b = dfs(height, x+1, y+1);
    if (a > b) count+=a; else count+=b;
    memeorization[x][y] = count;
    return count;
}

int main(void) {
    int n, t;
    cin >> n;
    vector<int> temp;
    for (int j = 0; j < n; ++j) {
        temp.push_back(-1);
    }
    for (int i = 0; i < n; ++i) {
        memeorization.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j <= i; ++j) {
            cin >> t;
            temp.push_back(t);
        }
        triangle.push_back(temp);
    }
    cout << dfs(n, 0, 0) << endl;
}