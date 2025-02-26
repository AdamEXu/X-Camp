#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    int x, y, d;
    Point (int a, int b, int c) {
        x=a;y=b;d=c;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > turns;
    vector<int> temp;
    for (int i = 0; i < m; i++) {
        temp.push_back(100000);
    }
    for (int i = 0; i < n; i++) {
        turns.push_back(temp);
    }
    vector<vector<int> > maze;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        maze.push_back(row);
    }
    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;
    start_x--; start_y--; end_x--; end_y--;
    queue<Point> notebook;
    notebook.push(Point(start_x, start_y, -1));
    turns[start_x][start_y] = 0; 
    int dirx[4] = {-1, 0, 1, 0}, diry[4] = {0, 1, 0, -1};
    if (start_x == end_x && start_y == end_y) {
        cout << 0 << endl;
        return 0;
    }
    while (!notebook.empty()) {
        Point current = notebook.front();
        notebook.pop();
        for (int i = 0; i < 4; i++) {
            int newx=current.x+dirx[i],newy=current.y+diry[i];
            // cout << newx << " " << newy << endl;
            if (newx >= 0 && newy >= 0 && newx < n && newy < m) {
                int turns_so_far = turns[current.x][current.y];
                if (i != current.d) {
                    turns_so_far++;
                } 
                if (turns_so_far < turns[newx][newy] && maze[newx][newy] != 1) {
                    notebook.push(Point(newx, newy, i));
                    turns[newx][newy] = turns_so_far;
                }
            }
        }
    }
    cout << turns[end_x][end_y]-1 << endl;
}