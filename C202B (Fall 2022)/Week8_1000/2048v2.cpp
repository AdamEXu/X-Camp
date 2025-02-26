#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

int dfs(int x, int y, int board[3][3]) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3) {
        return 0;
    }
    int newboard[3][3];
    int shortest = 100000;
    for (int i = 0; i < 4; i++) {
        int newx = x + dirx[i];
        int newy = y + diry[i];
        if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3 && board[newx][newy] == 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    newboard[i][j] = board[i][j];
                }
            }
            newboard[x][y] = board[newx][newy];
            newboard[newx][newy] = 0;
            dfs(newx, newy, newboard);
        }
    }
}

int main(void) {
    int board[3][3], ox, oy;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                ox = i;
                oy = j;
            }
        }
    }
}