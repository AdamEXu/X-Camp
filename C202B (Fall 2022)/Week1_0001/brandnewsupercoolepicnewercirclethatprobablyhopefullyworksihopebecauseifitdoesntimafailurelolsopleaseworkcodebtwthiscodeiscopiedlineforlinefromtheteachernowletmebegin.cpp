#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > maze;

void dfs(int i) {
    if (maze[i][i] != 1) {
        return;
    }
    maze[i][i] = 2;
    for (int j = 0; j < n; j++) {
        if (maze[i][j] == 1) {
            dfs(j);
        }
    }
}

int main(void) {
    cin >> n;
    maze = vector<vector<int> >(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (maze[i][i] == 1) {
            count++;
            dfs(i);
        }
    }
    cout << count << endl;
}