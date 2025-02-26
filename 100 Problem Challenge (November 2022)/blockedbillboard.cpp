#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    int tx1, ty1, tx2, ty2;
    cin >> tx1 >> ty1 >> tx2 >> ty2;
    vector<vector<int> > board(2001, vector<int>(2001));
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            board[i+1000][j+1000] = 1;
        }
    }
    for (int i = x3; i < x4; i++) {
        for (int j = y3; j < y4; j++) {
            board[i+1000][j+1000] = 1;
        }
    }
    for (int i = tx1; i < tx2; i++) {
        for (int j = ty1; j < ty2; j++) {
            board[i+1000][j+1000] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            ans += board[i][j];
        }
    }
    cout << ans << '\n';
}