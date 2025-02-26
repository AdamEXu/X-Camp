#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int> > maze;
vector<vector<bool> > visited;
int paths = 0, n, m, dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (x == n-1 && y == m-1) {
        paths++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newx = x + dirx[i];
        int newy = y + diry[i];
        if (newx >= 0 && newx < n && newy >= 0 && newy < m && maze[newx][newy] == 0 && !visited[newx][newy]) {
            dfs(newx, newy);
        }
    }
    visited[x][y] = false;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            char temp;
            scanf(" %c", &temp);
            int convertedint = 0;
            if (temp == '#') {
                convertedint = 1;
            }
            row.push_back(convertedint);
        }
        maze.push_back(row);
    }
    vector<bool> temp;
    for (int i = 0; i < m; i++) {
        temp.push_back(false);
    }
    for (int i = 0; i < n; i++) {
        visited.push_back(temp);
    }
    dfs(0, 0);
    printf("%d\n", paths);
}