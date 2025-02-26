#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int nqueen(int n, int row, vector<int> &col, vector<int> &diag1, vector<int> &diag2) {
    if (row == n) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0 && diag1[row+i] == 0 && diag2[row-i+n-1] == 0) {
            col[i] = 1;
            diag1[row+i] = 1;
            diag2[row-i+n-1] = 1;
            count += nqueen(n, row+1, col, diag1, diag2);
            col[i] = 0;
            diag1[row+i] = 0;
            diag2[row-i+n-1] = 0;
        }
    }
    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
}