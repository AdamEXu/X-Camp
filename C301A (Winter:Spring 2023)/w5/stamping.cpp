#include <iostream>
#include <string>
#include <vector>
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

int N, K;
vector<vector<bool> > canvas;
vector<vector<vector<bool> > > stamps;

static bool canstamp(int x, int y) {
    if (x + K > N || y + K > N || x < 0 || y < 0) {
        return false;
    }
    return true;
}

static vector<vector<bool> > rotate(int r) {
    if (r == 0) {
        return stamps[0];
    } else if (r == 1) {
        vector<vector<bool> > rotated(K, vector<bool>(K, false));
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                rotated[i][j] = stamps[0][K-j-1][i];
            }
        }
        return rotated;
    } else if (r == 2) {
        vector<vector<bool> > rotated(K, vector<bool>(K, false));
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                rotated[i][j] = stamps[0][K-i-1][K-j-1];
            }
        }
        return rotated;
    } else if (r == 3) {
        vector<vector<bool> > rotated(K, vector<bool>(K, false));
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                rotated[i][j] = stamps[0][j][K-i-1];
            }
        }
        return rotated;
    }
    return stamps[0];
}

void printcanvas(vector<vector<bool> > canvas) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (canvas[i][j]) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

bool bruteforceallposiblestamps(void) {
    // cout << N << ' ' << K << '\n';
    // blank canvas
    vector<vector<bool> > blank(N, vector<bool>(N, false));
    queue<vector<vector<bool> > > q;
    map<vector<vector<bool> >, int> depth;
    depth[blank] = 0;
    q.push(blank);
    while (!q.empty()) {
        vector<vector<bool> > tmp = q.front();
        q.pop();
        // printcanvas(tmp);
        // check if it is equal to canvas
        bool equal = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (tmp[i][j] != canvas[i][j]) {
                    equal = false;
                    break;
                }
            }
        }
        if (equal) {
            return true;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (canstamp(i, j)) {
                    // cout << "i: " << i << " j: " << j << '\n';
                    for (int r = 0; r < 4; ++r) {
                        vector<vector<bool> > merged = tmp;
                        for (int k = 0; k < K; ++k) {
                            for (int l = 0; l < K; ++l) {
                                if (stamps[r][k][l]) {
                                    merged[i+k][j+l] = true;
                                }
                            }
                        }
                        if (depth.find(merged) == depth.end()) {
                            depth[merged] = depth[tmp] + 1;
                            q.push(merged);
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        canvas.clear();
        stamps.clear();
        cin >> N;
        char tmp;
        vector<bool> blank(N, false);
        for (int i = 0; i < N; ++i) {
            canvas.push_back(blank);
            for (int j = 0; j < N; ++j) {
                cin >> tmp;
                if (tmp == '*') {
                    canvas[i][j] = true;
                }
            }
        }
        cin >> K;
        vector<vector<bool> > stamp(K, vector<bool>(K, false));
        for (int i = 0; i < K; ++i) {
            stamp.push_back(blank);
            for (int j = 0; j < K; ++j) {
                cin >> tmp;
                if (tmp == '*') {
                    stamp[i][j] = true;
                }
            }
        }
        stamps.push_back(stamp);
        stamps.push_back(rotate(1));
        stamps.push_back(rotate(2));
        stamps.push_back(rotate(3));
        if (bruteforceallposiblestamps()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}