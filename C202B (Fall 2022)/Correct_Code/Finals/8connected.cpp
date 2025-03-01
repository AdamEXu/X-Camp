#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > maze;

void flood(int x, int y) {
    if (x < 0 || x >= maze.size() || y < 0 || y >= maze[x].size()) {
        return;
    } else if (maze[x][y] == 1) {
        return;
    }
    maze[x][y] = 1;
    flood(x-1, y);
    flood(x+1, y);
    flood(x, y-1);
    flood(x, y+1);
    flood(x-1, y-1);
    flood(x+1, y-1);
    flood(x-1, y+1);
    flood(x+1, y+1);
    return;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    maze = vector<vector<int> >(n, vector<int>(m, 0));
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == 'W') {
                maze[i][j] = 0;
            } else if (tmp == '.') {
                maze[i][j] = 1;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << maze[i][j];
    //     }
    //     cout << endl;
    // }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 0) {
                count++;
                flood(i, j);
            }
        }
    }
    cout << count << endl;
    return 0;
}