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
    int dirx[4] = {0, 0, -1, 1}, diry[4] = {1, -1, 0, 0};
    vector<vector<int> > maze;
    // vector<vector<int> > dist;
    vector<vector<int> > visited;
    int n, m;
    cin >> n >> m;
    Point friendloc = Point(0, 0), youloc = Point(0, 0);
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                temp.push_back(0);
            } else if (c == '#') {
                temp.push_back(1);
            } else if (c == 'F') {
                temp.push_back(2);
                // kfc.push_back(Point(i, j));
                // cout << "ITS A KFC!!!" << endl;
            } else if (c == '@') {
                temp.push_back(0);
                youloc = Point(i, j);
            } else if (c == '&') {
                temp.push_back(0);
                friendloc = Point(i, j);
            } else {
                temp.push_back(c-'0');
            }
        }
        maze.push_back(temp);
    }

    vector<vector<int> > youdist;
    vector<vector<int> > frienddist;

    vector<int> temp;
    for (int i = 0; i < m; i++) {
        temp.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        youdist.push_back(temp);
        frienddist.push_back(temp);
        visited.push_back(temp);
    }

    queue<Point> youbook;
    youbook.push(youloc);
    visited[youloc.x][youloc.y] = 1; 

    while(!youbook.empty()) {
        Point current = youbook.front();
        youbook.pop();
        int nx, ny;
        for(int i = 0; i < 4; i++) {
            nx = current.x + dirx[i];
            ny = current.y + diry[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && maze[nx][ny] != 1) {
                visited[nx][ny] = 1; 
                youdist[nx][ny] = youdist[current.x][current.y] + 1;
                youbook.push(Point(nx, ny)); 
            } 
        }  
    }

    if (youdist[friendloc.x][friendloc.y] == 0) {
        cout << "Meeting cancelled" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0; 
        }
    }

    queue<Point> friendbook;
    friendbook.push(youloc);
    visited[youloc.x][youloc.y] = 1; 

    while (!friendbook.empty()) {
        Point current = friendbook.front();
        friendbook.pop();
        int nx, ny;
        for(int i = 0; i < 4; i++) {
            nx = current.x + dirx[i];
            ny = current.y + diry[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && maze[nx][ny] != 1) {
                visited[nx][ny] = 1; 
                frienddist[nx][ny] = frienddist[current.x][current.y] + 1;
                friendbook.push(Point(nx, ny)); 
            } 
        }  
    }

    int least = 2147483647;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 2) {
                if (youdist[i][j] && frienddist[i][j]) {
                    int dist = youdist[i][j] + frienddist[i][j];
                    least = min(dist, least);
                }
            }
        }
    }
    cout << least << endl;
}