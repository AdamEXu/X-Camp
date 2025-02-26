#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;

    point (int a, int b) {
        x = a;
        y = b;
    }
};

int dirx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int diry[8] = {2, -2, 1, -1, 2, -2, 1, -1};
vector<vector<int> > board;

void bfs(int x, int y, int d) {
    queue<point> notebook;
    while (!notebook.empty()) {
        point current = notebook.pop();
        if (board[current.x][current.y] == -1) {
            for (int i = 0; i < 8; i++) {
                notebook.push(point(x+dirx[i], y+diry[i]));
            }
        }
    }
}