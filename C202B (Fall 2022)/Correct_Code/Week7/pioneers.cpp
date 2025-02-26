#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

struct PNT {
    int x;
    int y;
    PNT(int tx, int ty) : x(tx), y(ty) {}
};
int maze[500][500];
queue<PNT> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
    int n, m, a, b, nx, ny;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int total = n*m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maze[i][j] = -1;
        }
    }

    int i, j, k;
    for (k = 0; k < a; k++) { // add all sources
        scanf("%d %d", &i, &j);
        maze[i-1][j-1] = 0;
        q.push(PNT(i-1, j-1));
    }
    while (!q.empty()) {
        PNT pt = q.front();
        q.pop(); // remove front
        for (i = 0; i < 4; i++) {
            nx = pt.x + dx[i];
            ny = pt.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == -1) {
                maze[nx][ny] = maze[pt.x][pt.y] + 1;
                q.push(PNT(nx, ny));
            }
        }
    }

    for (k = 0; k < b; k++) {
        scanf("%d %d", &i, &j);
        printf("%d\n", maze[i-1][j-1]);
    }
}