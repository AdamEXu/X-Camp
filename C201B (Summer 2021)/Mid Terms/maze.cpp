#include <iostream>
#include <vector>
using namespace std;

int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

int dx, dy;

int labyrinth(vector<vector<int> > maze, int x, int y, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return 0;
    } else if (maze[x][y] == 1) {
        return 0;
    } else if (maze[x][y] == 2) {
        return 0;
    } else if (x == dx-1 && y == dy-1) {
        return 1;
    }
    maze[x][y] = 2;
    long long ct = 0;
    ct+=labyrinth(maze, x+1, y, n, m);
    ct+=labyrinth(maze, x-1, y, n, m);
    ct+=labyrinth(maze, x, y+1, n, m);
    ct+=labyrinth(maze, x, y-1, n, m);
    return ct;
}

int main(void) {
    int n, m, x, y, t;
    cin >> n >> m >> t;
    cin >> x >> y >> dx >> dy;
    // dx--;dy--;
    vector<vector<int> > maze;
    vector<int> temp;
    for (int i = 0; i < m; i++) {
        temp.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        maze.push_back(temp);
    }
    for (int i = 0; i < t; i++) {
        int tx, ty;
        cin >> tx >> ty;
        maze[tx-1][ty-1] = 1;
    }
    cout << labyrinth(maze, x-1, y-1, n, m) << endl;
}