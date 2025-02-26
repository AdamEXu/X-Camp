#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > maze;
int n, m;

void labyrinth(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return;
    } else if (maze[x][y] == 1) {
        maze[x][y] = 0;
        long long ct = 0;
        labyrinth(x+1, y);
        labyrinth(x-1, y);
        labyrinth(x, y+1);
        labyrinth(x, y-1);
        labyrinth(x+1, y+1);
        labyrinth(x-1, y-1);
        labyrinth(x+1, y-1);
        labyrinth(x-1, y+1);
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> a;
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            a.push_back(int(temp[j])-'0');
        }
        maze.push_back(a);
    }
    int puddles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 1) {
                labyrinth(i, j);
                puddles++;
            }
        }
    }
    cout << puddles << endl;
}