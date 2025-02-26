#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int a, int b) {
        x=a;
        y=b;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int> > maze;
    vector<vector<int> > dist;
    vector<vector<bool> > visited;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        vector<bool> visit;
        dist.push_back(temp);
        visited.push_back(visit);
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            temp.push_back(t);
            dist[i].push_back(0);
            visited[i].push_back(false);
        }
        maze.push_back(temp);
    }
    queue<Point> notebook;
    notebook.push(Point(0, 0));
    int diry[4] = {0, 0, -1, 1}, dirx[4] = {1, -1, 0, 0};
    int counter = 0;
    int min = 2501, mincount = 0;
    dist[0][0] = 0;
    while (!notebook.empty()) {
        counter++;
        Point current=notebook.front();
        notebook.pop();
        // cout << current.x << ", " << current.y << endl;
        if (current.x == n-1 && current.y == n-1) {
            if (!visited[n-1][n-1]) {
                min = dist[n-1][n-1];
            }
            mincount++;
        }
        visited[current.x][current.y] = true;
        for (int i = 0; i < 4; i++) {
            int nx=current.x+dirx[i], ny=current.y+diry[i];
            if (nx >= n || ny >= n || nx < 0 || ny < 0) {
                continue;
            } else if (visited[nx][ny] == true) {
                continue;
            } else if (maze[nx][ny] == 1) {
                continue;
            } else {
                dist[nx][ny] = dist[current.x][current.y]+1;
                notebook.push(Point(nx, ny));
            }
            // visited[n-1][n-1] = false;
        }
    }

    cout << mincount << endl;
    cout << dist[n-1][n-1]+1 << endl;
}
