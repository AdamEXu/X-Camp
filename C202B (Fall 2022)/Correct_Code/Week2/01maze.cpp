#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > maze;
vector<vector<int> > zone;
int cur_zone = 0, dirx[4] = {0, 0, -1, 1}, diry[4] = {1, -1, 0, 0};
vector<int> zones;

bool isvalid(int x, int y, int old) {
    if (maze[x][y] == old) {
        return false;
    }
}

void dfs(int x, int y) {
    zone[x][y] = cur_zone;
    zones[cur_zone]++;
    for (int i = 0; i < 4; i++) {
        int nx = x+dirx[i], ny = y+diry[i];
        if (isvalid(nx, ny, maze[x][y])) {
            dfs(nx, ny);
        }
    }
}


int main(void) {
    
}