#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > board;

int dirx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int diry[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int n, m;

void horses(int x, int y, int d) {
    // cout << x << ", " << y << endl;
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return;
    }

    if (d > 200) {
        return;
    }

    if (d < board[x][y] || board[x][y] == -1) {
        board[x][y] = d;
        for (int i = 0; i < 8; i++) {
            horses(x+dirx[i], y+diry[i], d+1);
        }
    }
    return;
}

int main(void) {
    int x, y;
    cin >> n >> m >> x >> y;
    vector<int> temp;
    for (int i = 0; i < m; i++) {
        temp.push_back(-1);
    }
    for (int i = 0; i < n; i++) {
        board.push_back(temp);
    }
    horses(x-1, y-1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}