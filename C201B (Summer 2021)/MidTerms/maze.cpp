#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

int num_way_maze(vector<vector <bool> > board, int n, int m, int x, int y) {
    if(x>=n || y>=m || x<0 || y<0) {
        
    }

    num_way_maze(board, n, m, x, y-1);
    num_way_maze(board, n, m, x, y+1);
    num_way_maze(board, n, m, x-1, y);
    num_way_maze(board, n, m, x+1, y);
}

int main(void) {
    int n, m, t;
    cin >> n >> m >> t;
    Point start(0,0), end(0,0);
    cin >> start.x >> start.y >> end.x >> end.y;
    vector<vector<bool> > maze;
    
}