#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > maze;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            int convertedint = 0;
            if (temp == '#') {
                convertedint = 1;
            }
            row.push_back(convertedint);
        }
        maze.push_back(row);
    }
    vector<vector<int> > visited (n, vector<int>(m, 0));
    queue<Point> notebook;
    notebook.push(Point(0, 0));
    visited[0][0] = 1;
    int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
    while (!notebook.empty()) {
        Point current = notebook.front();
        notebook.pop();
        cout << visited[current.x][current.y] << endl;
        for (int i = 0; i < 4; i++) {
            int newx = current.x + dirx[i];
            int newy = current.y + diry[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && maze[newx][newy] == 0) {
                notebook.push(Point(newx, newy));
                visited[newx][newy] = max(visited[current.x][current.y], visited[newx][newy] + 1);
            }
        }
    }
    cout << visited[n-1][m-1] << endl;
}