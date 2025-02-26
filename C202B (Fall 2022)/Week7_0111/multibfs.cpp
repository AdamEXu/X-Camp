#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

bool notempty(vector<queue<Point> > notebook) {
    for (int i = 0; i < notebook.size(); i++) {
        if (!notebook[i].empty()) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<Point> leaders, infected;
    vector<queue<Point> > notebooks;
    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        leaders.push_back(Point(x, y));
    }
    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        infected.push_back(Point(x-1, y-1));
        notebooks.push_back(queue<Point>());
        notebooks[i].push(Point(x-1, y-1));
    }
    int dist[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = 500000;
        }
    }
    cout << "Here!" << endl;
    int dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1};
    // print out the distance from each leader to the closest infected
    while (notempty(notebooks)) {
        cout << "There!" << endl;
        for (int i = 0; i < b; i++) {
            Point current = notebooks[i].front();
            cout << "Here & There!" << current.x << current.y << endl;
            notebooks[i].pop();
            for (int j = 0; j < 4; j++) {
                cout << "Hello World!" << i << j << endl;
                int newx = current.x + dirx[j];
                int newy = current.y + diry[j];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && dist[current.x][current.y] + 1 < dist[newx][newy]) {
                    dist[newx][newy] = dist[current.x][current.y] + 1;
                    notebooks[i].push(Point(newx, newy));
                }
            }
        }
    }
    for (int i = 0; i < a; i++) {
        cout << dist[leaders[i].x][leaders[i].y] << endl;
    }
}